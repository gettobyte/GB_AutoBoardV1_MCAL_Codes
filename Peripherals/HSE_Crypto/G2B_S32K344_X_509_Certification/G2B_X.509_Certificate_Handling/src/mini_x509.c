/*
 * mini_x509.c
 *
 *  Created on: 26-Oct-2025
 *      Author: RohanS002 Gettobyte
 */


#include "mini_x509.h"
#include <string.h>
#include <stdio.h>

/* =========================
 * Small internal ASN.1 util
 * ========================= */
typedef struct { const uint8_t* p; const uint8_t* end; } asn1;

#define TAG_SEQ   0x30
#define TAG_SET   0x31
#define TAG_INT   0x02
#define TAG_OID   0x06
#define TAG_NULL  0x05
#define TAG_BIT   0x03
#define TAG_OCT   0x04
#define TAG_UTF8  0x0C
#define TAG_PRINT 0x13
#define TAG_IA5   0x16
#define TAG_UTCT  0x17
#define TAG_GENT  0x18
#define CTX_EXPL(n) (0xA0 + (n))
#define CTX_IMPL(n) (0x80 + (n))

static int get_len(asn1* a, size_t* L){
    if (a->p >= a->end) return SX_INVALID_FORMAT;
    uint8_t b = *a->p++;
    if (!(b & 0x80)) { *L = b; return 0; }
    size_t n = (b & 0x7F);
    if (n == 0 || n > 4 || (size_t)(a->end - a->p) < n) return SX_INVALID_FORMAT;
    size_t v = 0; while (n--) { v = (v << 8) | *a->p++; }
    if ((size_t)(a->end - a->p) < v) return SX_INVALID_FORMAT;
    *L = v; return 0;
}
static int get_tag(asn1* a, uint8_t expect, size_t* L){
    if (a->p >= a->end || *a->p != expect) return SX_INVALID_FORMAT;
    a->p++; return get_len(a, L);
}
static int adv(asn1* a, size_t n){ if ((size_t)(a->end - a->p) < n) return SX_INVALID_FORMAT; a->p += n; return 0; }
static int enter_seq(asn1* a, asn1* inner){ size_t L=0; if (get_tag(a, TAG_SEQ, &L)) return SX_INVALID_FORMAT; inner->p=a->p; inner->end=a->p+L; return adv(a,L); }
static int get_int(asn1* a, const uint8_t** p, size_t* L){ if (get_tag(a, TAG_INT, L)) return SX_INVALID_FORMAT; *p=a->p; return adv(a,*L); }
static int get_oid(asn1* a, const uint8_t** p, size_t* L){ if (get_tag(a, TAG_OID, L)) return SX_INVALID_FORMAT; *p=a->p; return adv(a,*L); }
static int get_null(asn1* a){ if (a->p < a->end && *a->p == TAG_NULL){ size_t L=0; a->p++; if (get_len(a,&L) || L!=0) return SX_INVALID_FORMAT; } return 0; }
static int get_bit_contents(asn1* a, const uint8_t** p, size_t* L){
    size_t len=0; if (get_tag(a, TAG_BIT, &len)) return SX_INVALID_FORMAT;
    if (len == 0 || (size_t)(a->end - a->p) < len) return SX_INVALID_FORMAT;
    uint8_t unused = *a->p++; (void)unused;
    *p = a->p; *L = len - 1; return adv(a, len - 1);
}
static int get_oct(asn1* a, const uint8_t** p, size_t* L){ if (get_tag(a, TAG_OCT, L)) return SX_INVALID_FORMAT; *p=a->p; return adv(a,*L); }

static void hexify(char* dst, size_t dstlen, const uint8_t* p, size_t n){
    static const char h[]="0123456789ABCDEF";
    size_t out=0;
    for (size_t i=0;i<n && out+2<dstlen;i++){ dst[out++]=h[p[i]>>4]; dst[out++]=h[p[i]&0xF]; }
    if (out<dstlen) dst[out]=0;
}
static void hexify_fixed(char* dst, size_t dstlen, const uint8_t* p, size_t n){
    /* hexify but ensure NUL even if truncated */
    hexify(dst, dstlen, p, n);
    if (dstlen) dst[dstlen-1] = 0;
}

/* ================
 * OID dictionaries
 * ================ */
static int oid_eq(const uint8_t* p, size_t L, const uint8_t* v, size_t n){ return (L==n && memcmp(p,v,n)==0); }

/* algs */
static const uint8_t OID_RSA_ENC[]       ={0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x01};
static const uint8_t OID_EC_PUBKEY[]     ={0x2A,0x86,0x48,0xCE,0x3D,0x02,0x01};
static const uint8_t OID_RSA_SHA1[]      ={0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x05};
static const uint8_t OID_RSA_SHA256[]    ={0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B};
static const uint8_t OID_RSA_SHA384[]    ={0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0C};
static const uint8_t OID_RSA_SHA512[]    ={0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0D};
static const uint8_t OID_ECDSA_SHA1[]    ={0x2A,0x86,0x48,0xCE,0x3D,0x04,0x01};
static const uint8_t OID_ECDSA_SHA256[]  ={0x2A,0x86,0x48,0xCE,0x3D,0x04,0x03,0x02};
static const uint8_t OID_ECDSA_SHA384[]  ={0x2A,0x86,0x48,0xCE,0x3D,0x04,0x03,0x03};
static const uint8_t OID_ECDSA_SHA512[]  ={0x2A,0x86,0x48,0xCE,0x3D,0x04,0x03,0x04};

/* curves */
static const uint8_t OID_SECP256R1[]     ={0x2A,0x86,0x48,0xCE,0x3D,0x03,0x01,0x07};
static const uint8_t OID_SECP384R1[]     ={0x2B,0x81,0x04,0x00,0x22};
static const uint8_t OID_SECP521R1[]     ={0x2B,0x81,0x04,0x00,0x23};

/* extensions */
static const uint8_t OID_KU[]            ={0x55,0x1D,0x0F};
static const uint8_t OID_BC[]            ={0x55,0x1D,0x13};
static const uint8_t OID_SKID[]          ={0x55,0x1D,0x0E};
static const uint8_t OID_AKID[]          ={0x55,0x1D,0x23};
static const uint8_t OID_SAN[]           ={0x55,0x1D,0x11};
static const uint8_t OID_EKU[]           ={0x55,0x1D,0x25};
static const uint8_t OID_AIA[]           ={0x55,0x1D,0x1F - 0x0E}; /* actually 1.3.6.1.5.5.7.1.1: see below */
static const uint8_t OID_CERT_POL[]      ={0x55,0x1D,0x20};
static const uint8_t OID_CRL_DP[]        ={0x55,0x1D,0x1F};

/* DN attribute OIDs we’ll name */
static const uint8_t OID_CN[] = {0x55,0x04,0x03};
static const uint8_t OID_O[]  = {0x55,0x04,0x0A};
static const uint8_t OID_C[]  = {0x55,0x04,0x06};
static const uint8_t OID_OU[] = {0x55,0x04,0x0B};
static const uint8_t OID_L[]  = {0x55,0x04,0x07};
static const uint8_t OID_ST[] = {0x55,0x04,0x08};

/* EKU OIDs to friendly names */
static const struct { const uint8_t* oid; size_t len; const char* name; } EKU_MAP[] = {
    /* id-kp = 1.3.6.1.5.5.7.3.x */
    {(const uint8_t*)"\x2b\x06\x01\x05\x05\x07\x03\x01", 8, "ServerAuth"},
    {(const uint8_t*)"\x2b\x06\x01\x05\x05\x07\x03\x02", 8, "ClientAuth"},
    {(const uint8_t*)"\x2b\x06\x01\x05\x05\x07\x03\x03", 8, "CodeSigning"},
    {(const uint8_t*)"\x2b\x06\x01\x05\x05\x07\x03\x04", 8, "EmailProtection"},
    {(const uint8_t*)"\x2b\x06\x01\x05\x05\x07\x03\x08", 8, "TimeStamping"},
    {(const uint8_t*)"\x2b\x06\x01\x05\x05\x07\x03\x09", 8, "OCSPSigning"},
};

/* AIA (AuthorityInfoAccess) real OID: 1.3.6.1.5.5.7.1.1 -> bytes: 2B 06 01 05 05 07 01 01 */
static const uint8_t OID_AUTH_INFO_ACCESS[] = {0x2B,0x06,0x01,0x05,0x05,0x07,0x01,0x01};
/* AccessMethod OIDs */
static const uint8_t OID_AD_OCSP[]       = {0x2B,0x06,0x01,0x05,0x05,0x07,0x30,0x01};
static const uint8_t OID_AD_CAISSUERS[]  = {0x2B,0x06,0x01,0x05,0x05,0x07,0x30,0x02};

static const char* sig_name(const uint8_t* p, size_t L, char* hash, size_t hashlen){
    if (oid_eq(p,L,OID_RSA_SHA1,sizeof(OID_RSA_SHA1)))   { snprintf(hash,hashlen,"sha1");   return "sha1WithRSA"; }
    if (oid_eq(p,L,OID_RSA_SHA256,sizeof(OID_RSA_SHA256))){ snprintf(hash,hashlen,"sha256"); return "sha256WithRSA"; }
    if (oid_eq(p,L,OID_RSA_SHA384,sizeof(OID_RSA_SHA384))){ snprintf(hash,hashlen,"sha384"); return "sha384WithRSA"; }
    if (oid_eq(p,L,OID_RSA_SHA512,sizeof(OID_RSA_SHA512))){ snprintf(hash,hashlen,"sha512"); return "sha512WithRSA"; }
    if (oid_eq(p,L,OID_ECDSA_SHA1,sizeof(OID_ECDSA_SHA1))){ snprintf(hash,hashlen,"sha1");   return "ecdsa-with-SHA1"; }
    if (oid_eq(p,L,OID_ECDSA_SHA256,sizeof(OID_ECDSA_SHA256))){ snprintf(hash,hashlen,"sha256"); return "ecdsa-with-SHA256"; }
    if (oid_eq(p,L,OID_ECDSA_SHA384,sizeof(OID_ECDSA_SHA384))){ snprintf(hash,hashlen,"sha384"); return "ecdsa-with-SHA384"; }
    if (oid_eq(p,L,OID_ECDSA_SHA512,sizeof(OID_ECDSA_SHA512))){ snprintf(hash,hashlen,"sha512"); return "ecdsa-with-SHA512"; }
    snprintf(hash,hashlen,""); return "sig(oid)";
}
static const char* curve_name(const uint8_t* p, size_t L){
    if (oid_eq(p,L,OID_SECP256R1,sizeof(OID_SECP256R1))) return "secp256r1";
    if (oid_eq(p,L,OID_SECP384R1,sizeof(OID_SECP384R1))) return "secp384r1";
    if (oid_eq(p,L,OID_SECP521R1,sizeof(OID_SECP521R1))) return "secp521r1";
    return "curve(oid)";
}

static void append_csv(char dst[][SX_MAX_URI], int *count, const char* s){
    if (*count >= SX_MAX_LIST_ITEMS) return;
    snprintf(dst[*count], SX_MAX_URI, "%s", s);
    (*count)++;
}
static void append_name(char* dst, size_t dstlen, const char* key, const uint8_t* v, size_t vl){
    char tmp[200]={0}; size_t n = (vl < sizeof(tmp)-1) ? vl : sizeof(tmp)-1;
    memcpy(tmp, v, n); tmp[n]=0;
    if (dst[0]) strncat(dst, ",", dstlen - strlen(dst) - 1);
    char piece[260]; snprintf(piece, sizeof(piece), "%s=%s", key, tmp);
    strncat(dst, piece, dstlen - strlen(dst) - 1);
}

/* DN → "C=..,ST=..,L=..,O=..,OU=..,CN=.." best-effort */
static int parse_name(asn1* a, char* out, size_t outlen){
    asn1 seq; if (enter_seq(a,&seq)) return SX_INVALID_FORMAT;
    out[0]=0;
    while (seq.p < seq.end){
        size_t Ls=0; if (get_tag(&seq, TAG_SET, &Ls)) return SX_INVALID_FORMAT;
        if ((size_t)(seq.end - seq.p) < Ls) return SX_INVALID_FORMAT;
        asn1 set={seq.p, seq.p+Ls}; seq.p+=Ls;
        while (set.p < set.end){
            asn1 atv; if (enter_seq(&set,&atv)) return SX_INVALID_FORMAT;
            const uint8_t *oid=NULL,*val=NULL; size_t lo=0,lv=0;
            if (get_oid(&atv,&oid,&lo)) return SX_INVALID_FORMAT;
            if (atv.p >= atv.end) return SX_INVALID_FORMAT;
            uint8_t t = *atv.p++; if (get_len(&atv,&lv)) return SX_INVALID_FORMAT;
            if ((size_t)(atv.end - atv.p) < lv) return SX_INVALID_FORMAT;
            val = atv.p; atv.p += lv;

            if (oid_eq(oid,lo,OID_C,sizeof(OID_C)))   append_name(out,outlen,"C",val,lv);
            else if (oid_eq(oid,lo,OID_ST,sizeof(OID_ST))) append_name(out,outlen,"ST",val,lv);
            else if (oid_eq(oid,lo,OID_L,sizeof(OID_L)))   append_name(out,outlen,"L",val,lv);
            else if (oid_eq(oid,lo,OID_O,sizeof(OID_O)))   append_name(out,outlen,"O",val,lv);
            else if (oid_eq(oid,lo,OID_OU,sizeof(OID_OU))) append_name(out,outlen,"OU",val,lv);
            else if (oid_eq(oid,lo,OID_CN,sizeof(OID_CN))) append_name(out,outlen,"CN",val,lv);
            else append_name(out,outlen,"OID",val,lv);
        }
    }
    return 0;
}

/* Fixed: robust UTCTime / GeneralizedTime to "YYYY-MM-DD HH:MM:SS UTC" */
static int parse_time_utcstr(asn1* a, char* out, size_t outlen){
    if (a->p >= a->end) return SX_INVALID_FORMAT;
    uint8_t tag = *a->p++;
    size_t L=0; if (get_len(a,&L)) return SX_INVALID_FORMAT;
    if ((size_t)(a->end - a->p) < L) return SX_INVALID_FORMAT;
    const uint8_t* s = a->p; a->p += L;

    int Y=0,M=0,D=0,h=0,m=0,S=0;
    if (tag == TAG_UTCT) {
        /* YYMMDDHHMMSSZ (13 bytes) is typical; allow seconds present */
        if (L < 13 || s[L-1] != 'Z') return SX_INVALID_FORMAT;
        if (L != 13 && L != 15) return SX_INVALID_FORMAT; /* be strict */
        int yy = (s[0]-'0')*10 + (s[1]-'0');
        Y = (yy >= 50) ? (1900+yy) : (2000+yy);
        M = (s[2]-'0')*10 + (s[3]-'0');
        D = (s[4]-'0')*10 + (s[5]-'0');
        h = (s[6]-'0')*10 + (s[7]-'0');
        m = (s[8]-'0')*10 + (s[9]-'0');
        S = (s[10]-'0')*10 + (s[11]-'0');
    } else if (tag == TAG_GENT) {
        /* YYYYMMDDHHMMSSZ (15 bytes) */
        if (L < 15 || s[L-1] != 'Z') return SX_INVALID_FORMAT;
        Y = (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
        M = (s[4]-'0')*10 + (s[5]-'0');
        D = (s[6]-'0')*10 + (s[7]-'0');
        h = (s[8]-'0')*10 + (s[9]-'0');
        m = (s[10]-'0')*10 + (s[11]-'0');
        S = (s[12]-'0')*10 + (s[13]-'0');
    } else return SX_UNSUPPORTED;

    snprintf(out, outlen, "%04d-%02d-%02d %02d:%02d:%02d UTC", Y,M,D,h,m,S);
    return 0;
}

/* --------------------
 * Parsing entry point
 * -------------------- */
int simple_x509_parse_der(const uint8_t* der, size_t der_len, SimpleCert* out){
    if (!der || !out) return SX_BAD_INPUT;
    memset(out, 0, sizeof(*out));
    out->path_len = -1;

    asn1 a={der, der+der_len}, cert, tbs;
    if (enter_seq(&a,&cert)) return SX_INVALID_FORMAT;
    if (enter_seq(&cert,&tbs)) return SX_INVALID_FORMAT;

    /* version [0] EXPLICIT DEFAULT v1 */
    if (tbs.p < tbs.end && *tbs.p == CTX_EXPL(0)){
        size_t Lv=0; tbs.p++; if (get_len(&tbs,&Lv)) return SX_INVALID_FORMAT;
        if ((size_t)(tbs.end - tbs.p) < Lv) return SX_INVALID_FORMAT;
        asn1 vi={tbs.p, tbs.p+Lv}; tbs.p+=Lv;
        const uint8_t *vp=NULL; size_t vl=0; if (get_int(&vi,&vp,&vl)) return SX_INVALID_FORMAT;
        int vv=0; for (size_t i=0;i<vl;i++) vv=(vv<<8)|vp[i];
        out->version = vv+1;
    } else out->version = 1;

    /* serialNumber */
    { const uint8_t *sp=NULL; size_t sl=0; if (get_int(&tbs,&sp,&sl)) return SX_INVALID_FORMAT;
      hexify_fixed(out->serial_hex, sizeof(out->serial_hex), sp, sl);
    }

    /* signature AlgorithmIdentifier (TBSCertificate) */
    const uint8_t *sig_oid=NULL; size_t sig_lo=0;
    {
        asn1 alg; if (enter_seq(&tbs,&alg)) return SX_INVALID_FORMAT;
        if (get_oid(&alg,&sig_oid,&sig_lo)) return SX_INVALID_FORMAT;
        if (alg.p < alg.end){
            if (*alg.p == TAG_NULL){ if (get_null(&alg)) return SX_INVALID_FORMAT; }
            else { /* ignore params TLV */ size_t L=0; uint8_t t=*alg.p++; if (get_len(&alg,&L)) return SX_INVALID_FORMAT; if ((size_t)(alg.end-alg.p)<L) return SX_INVALID_FORMAT; alg.p+=L; (void)t; }
        }
        if (alg.p != alg.end) return SX_INVALID_FORMAT;
        char hash[16]={0};
        const char* sn = sig_name(sig_oid, sig_lo, hash, sizeof(hash));
        snprintf(out->sig_alg, sizeof(out->sig_alg), "%s", sn);
        snprintf(out->sig_hash, sizeof(out->sig_hash), "%s", hash);
    }

    /* issuer */
    if (parse_name(&tbs, out->issuer, sizeof(out->issuer))) return SX_INVALID_FORMAT;

    /* validity */
    { asn1 vs; if (enter_seq(&tbs,&vs)) return SX_INVALID_FORMAT;
      if (parse_time_utcstr(&vs, out->not_before, sizeof(out->not_before))) return SX_INVALID_FORMAT;
      if (parse_time_utcstr(&vs, out->not_after , sizeof(out->not_after )))  return SX_INVALID_FORMAT;
      if (vs.p != vs.end) return SX_INVALID_FORMAT;
    }

    /* subject */
    if (parse_name(&tbs, out->subject, sizeof(out->subject))) return SX_INVALID_FORMAT;

    /* subjectPublicKeyInfo */
    {
        asn1 spki; if (enter_seq(&tbs,&spki)) return SX_INVALID_FORMAT;
        /* AlgId */
        const uint8_t *ka=NULL,*kp=NULL; size_t kla=0,klp=0;
        { asn1 a2; if (enter_seq(&spki,&a2)) return SX_INVALID_FORMAT;
          if (get_oid(&a2,&ka,&kla)) return SX_INVALID_FORMAT;
          if (a2.p < a2.end){
            if (*a2.p == TAG_NULL){ if (get_null(&a2)) return SX_INVALID_FORMAT; }
            else { size_t L=0; uint8_t t=*a2.p++; if (get_len(&a2,&L)) return SX_INVALID_FORMAT; if ((size_t)(a2.end-a2.p)<L) return SX_INVALID_FORMAT; kp=a2.p; klp=L; a2.p+=L; (void)t; }
          }
          if (a2.p != a2.end) return SX_INVALID_FORMAT;
        }
        /* pubkey BIT STRING */
        const uint8_t *bits=NULL; size_t bl=0; if (get_bit_contents(&spki,&bits,&bl)) return SX_INVALID_FORMAT;
        if (spki.p != spki.end) return SX_INVALID_FORMAT;

        if (oid_eq(ka,kla,OID_RSA_ENC,sizeof(OID_RSA_ENC))){
            snprintf(out->pubkey_type, sizeof(out->pubkey_type), "RSA");
            asn1 rp={bits,bits+bl}, s; if (enter_seq(&rp,&s)) return SX_INVALID_FORMAT;
            const uint8_t *n=NULL,*e=NULL; size_t nl=0,el=0;
            if (get_int(&s,&n,&nl) || get_int(&s,&e,&el)) return SX_INVALID_FORMAT;
            if (nl>0){
                int lead = n[0]; int leading_bits = 8; while (leading_bits>0 && !(lead & (1<<(leading_bits-1)))) leading_bits--;
                out->rsa_mod_bits = (int)((nl-1)*8 + leading_bits);
            }
            int ev=0; if (el<=4){ for (size_t i=0;i<el;i++) ev=(ev<<8)|e[i]; out->rsa_exp=ev; }
        } else if (oid_eq(ka,kla,OID_EC_PUBKEY,sizeof(OID_EC_PUBKEY))){
            snprintf(out->pubkey_type, sizeof(out->pubkey_type), "EC");
            snprintf(out->curve, sizeof(out->curve), "%s", curve_name(kp, klp));
            if (bl >= 1 && bits[0] == 0x04 && bl % 2 == 1){
                size_t coord = (bl-1)/2;
                const uint8_t* X = bits+1;
                const uint8_t* Y = bits+1+coord;
                hexify_fixed(out->ec_x_hex, sizeof(out->ec_x_hex), X, coord);
                hexify_fixed(out->ec_y_hex, sizeof(out->ec_y_hex), Y, coord);
            }
        } else return SX_UNSUPPORTED;
    }

    /* issuerUniqueID [1] (skip) */
    if (tbs.p < tbs.end && *tbs.p == CTX_IMPL(1)){ size_t L=0; tbs.p++; if (get_len(&tbs,&L)) return SX_INVALID_FORMAT; if ((size_t)(tbs.end-tbs.p)<L) return SX_INVALID_FORMAT; tbs.p+=L; }
    /* subjectUniqueID [2] (skip) */
    if (tbs.p < tbs.end && *tbs.p == CTX_IMPL(2)){ size_t L=0; tbs.p++; if (get_len(&tbs,&L)) return SX_INVALID_FORMAT; if ((size_t)(tbs.end-tbs.p)<L) return SX_INVALID_FORMAT; tbs.p+=L; }

    /* extensions [3] (optional) */
    if (out->version == 3 && tbs.p < tbs.end && *tbs.p == CTX_EXPL(3)){
        size_t L3=0; tbs.p++; if (get_len(&tbs,&L3)) return SX_INVALID_FORMAT;
        if ((size_t)(tbs.end - tbs.p) < L3) return SX_INVALID_FORMAT;
        asn1 ex={tbs.p, tbs.p+L3}; tbs.p+=L3;

        asn1 list; if (enter_seq(&ex,&list)) return SX_INVALID_FORMAT;
        while (list.p < list.end){
            asn1 ext; if (enter_seq(&list,&ext)) return SX_INVALID_FORMAT;
            const uint8_t *id=NULL,*val=NULL; size_t lid=0, lval=0;
            if (get_oid(&ext,&id,&lid)) return SX_INVALID_FORMAT;
            if (ext.p < ext.end && *ext.p == 0x01){ size_t Lb=0; ext.p++; if (get_len(&ext,&Lb)) return SX_INVALID_FORMAT; if ((size_t)(ext.end-ext.p)<Lb) return SX_INVALID_FORMAT; ext.p+=Lb; }
            if (get_oct(&ext,&val,&lval)) return SX_INVALID_FORMAT;
            if (ext.p != ext.end) return SX_INVALID_FORMAT;

            asn1 inner={val, val+lval};

            if (oid_eq(id,lid,OID_BC,sizeof(OID_BC))){
                asn1 bc; if (enter_seq(&inner,&bc)) return SX_INVALID_FORMAT;
                out->is_ca = 0; out->path_len = -1;
                if (bc.p < bc.end && *bc.p == 0x01){ size_t Lb=0; bc.p++; if (get_len(&bc,&Lb)) return SX_INVALID_FORMAT; if (Lb==1) out->is_ca = (bc.p[0]!=0); bc.p+=Lb; }
                if (bc.p < bc.end && *bc.p == TAG_INT){ const uint8_t* ip=NULL; size_t il=0; if (get_int(&bc,&ip,&il)) return SX_INVALID_FORMAT; int v=0; for (size_t i=0;i<il;i++) v=(v<<8)|ip[i]; out->path_len=v; }
                if (bc.p != bc.end) return SX_INVALID_FORMAT;
            } else if (oid_eq(id,lid,OID_KU,sizeof(OID_KU))){
                const uint8_t* bp=NULL; size_t bl=0; if (get_bit_contents(&inner,&bp,&bl)) return SX_INVALID_FORMAT;
                unsigned ku=0; if (bl){ if (bl==1) ku = bp[0]; else ku = ((unsigned)bp[0]<<8) | bp[1]; }
                out->key_usage = ku;
            } else if (oid_eq(id,lid,OID_SKID,sizeof(OID_SKID))){
                const uint8_t* p=NULL; size_t l=0; if (get_oct(&inner,&p,&l)) return SX_INVALID_FORMAT;
                hexify_fixed(out->skid_hex, sizeof(out->skid_hex), p, l);
            } else if (oid_eq(id,lid,OID_AKID,sizeof(OID_AKID))){
                asn1 ak; if (enter_seq(&inner,&ak)) return SX_INVALID_FORMAT;
                if (ak.p < ak.end && *ak.p == 0x80){ size_t Lk=0; ak.p++; if (get_len(&ak,&Lk)) return SX_INVALID_FORMAT; if ((size_t)(ak.end-ak.p)<Lk) return SX_INVALID_FORMAT; hexify_fixed(out->akid_keyid_hex, sizeof(out->akid_keyid_hex), ak.p, Lk); ak.p+=Lk; }
            } else if (oid_eq(id,lid,OID_SAN,sizeof(OID_SAN))){
                asn1 san; if (enter_seq(&inner,&san)) return SX_INVALID_FORMAT;
                while (san.p < san.end && out->san_count < SX_MAX_LIST_ITEMS){
                    uint8_t tag = *san.p++;
                    size_t Lg=0; if (get_len(&san,&Lg)) return SX_INVALID_FORMAT;
                    if ((size_t)(san.end - san.p) < Lg) return SX_INVALID_FORMAT;
                    if (tag == 0x82 /* dNSName */){
                        size_t n = (Lg < SX_MAX_URI-5) ? Lg : SX_MAX_URI-5;
                        snprintf(out->san[out->san_count], SX_MAX_URI, "DNS:%.*s", (int)n, san.p);
                        out->san_count++;
                    } else if (tag == 0x87 /* iPAddress */){
                        char* dst = out->san[out->san_count];
                        if (Lg == 4){
                            snprintf(dst, SX_MAX_URI, "IP:%u.%u.%u.%u", san.p[0],san.p[1],san.p[2],san.p[3]);
                            out->san_count++;
                        } else if (Lg == 16){
                            int off=0;
                            for (int i=0;i<16;i+=2){
                                off += snprintf(dst+off, SX_MAX_URI-off, "%02X%02X%s", san.p[i],san.p[i+1], (i<14)?":":"");
                            }
                            out->san_count++;
                        }
                    }
                    san.p += Lg;
                }
            } else if (oid_eq(id,lid,OID_EKU,sizeof(OID_EKU))){
                asn1 ekuseq; if (enter_seq(&inner,&ekuseq)) return SX_INVALID_FORMAT;
                while (ekuseq.p < ekuseq.end && out->eku_count < SX_MAX_LIST_ITEMS){
                    const uint8_t* op=NULL; size_t ol=0; if (get_oid(&ekuseq,&op,&ol)) return SX_INVALID_FORMAT;
                    const char* name = "EKU(oid)";
                    for (size_t i=0;i<sizeof(EKU_MAP)/sizeof(EKU_MAP[0]); ++i){
                        if (oid_eq(op,ol,EKU_MAP[i].oid, EKU_MAP[i].len)) { name = EKU_MAP[i].name; break; }
                    }
                    snprintf(out->eku[out->eku_count++], SX_MAX_ALG, "%s", name);
                }
            } else if (oid_eq(id,lid,OID_CRL_DP,sizeof(OID_CRL_DP))){
                /* CRLDistributionPoints ::= SEQUENCE OF DistributionPoint
                   DistributionPointName ::= CHOICE { fullName [0] GeneralNames } */
                asn1 dpseq; if (enter_seq(&inner,&dpseq)) return SX_INVALID_FORMAT;
                while (dpseq.p < dpseq.end && out->crl_dp_count < SX_MAX_LIST_ITEMS){
                    asn1 dp; if (enter_seq(&dpseq,&dp)) return SX_INVALID_FORMAT;
                    if (dp.p < dp.end && *dp.p == 0xA0){ /* [0] fullName */
                        size_t Ln=0; dp.p++; if (get_len(&dp,&Ln)) return SX_INVALID_FORMAT;
                        if ((size_t)(dp.end - dp.p) < Ln) return SX_INVALID_FORMAT;
                        asn1 gns={dp.p, dp.p+Ln}; dp.p+=Ln;
                        while (gns.p < gns.end && out->crl_dp_count < SX_MAX_LIST_ITEMS){
                            uint8_t tag = *gns.p++; size_t Lg=0; if (get_len(&gns,&Lg)) return SX_INVALID_FORMAT;
                            if ((size_t)(gns.end - gns.p) < Lg) return SX_INVALID_FORMAT;
                            if (tag == 0x86 /* uniformResourceIdentifier */){
                                size_t n = (Lg < SX_MAX_URI-1) ? Lg : SX_MAX_URI-1;
                                snprintf(out->crl_dp[out->crl_dp_count++], SX_MAX_URI, "%.*s", (int)n, gns.p);
                            }
                            gns.p += Lg;
                        }
                    }
                }
            } else if (oid_eq(id,lid,OID_AUTH_INFO_ACCESS,sizeof(OID_AUTH_INFO_ACCESS))){
                /* AuthorityInfoAccess ::= SEQUENCE OF AccessDescription
                   AccessDescription ::= SEQUENCE { accessMethod OID, accessLocation GeneralName }
                   We extract OCSP / caIssuers URIs. */
                asn1 aias; if (enter_seq(&inner,&aias)) return SX_INVALID_FORMAT;
                while (aias.p < aias.end){
                    asn1 ad; if (enter_seq(&aias,&ad)) return SX_INVALID_FORMAT;
                    const uint8_t* method=NULL; size_t ml=0; if (get_oid(&ad,&method,&ml)) return SX_INVALID_FORMAT;
                    if (ad.p >= ad.end) return SX_INVALID_FORMAT;
                    uint8_t t = *ad.p++; size_t L=0; if (get_len(&ad,&L)) return SX_INVALID_FORMAT;
                    if ((size_t)(ad.end - ad.p) < L) return SX_INVALID_FORMAT;

                    if (t == 0x86 /* uniformResourceIdentifier */){
                        char uri[SX_MAX_URI]; size_t n = (L < SX_MAX_URI-1) ? L : SX_MAX_URI-1;
                        snprintf(uri, sizeof(uri), "%.*s", (int)n, ad.p);
                        if (oid_eq(method,ml,OID_AD_OCSP,sizeof(OID_AD_OCSP))) {
                            append_csv(out->aia_ocsp, &out->aia_ocsp_count, uri);
                        } else if (oid_eq(method,ml,OID_AD_CAISSUERS,sizeof(OID_AD_CAISSUERS))) {
                            append_csv(out->aia_caissuers, &out->aia_caissuers_count, uri);
                        }
                    }
                    ad.p += L;
                }
            } else if (oid_eq(id,lid,OID_CERT_POL,sizeof(OID_CERT_POL))){
                /* CertificatePolicies ::= SEQUENCE OF PolicyInformation { policyIdentifier OID, ... } */
                asn1 pols; if (enter_seq(&inner,&pols)) return SX_INVALID_FORMAT;
                while (pols.p < pols.end && out->policy_count < SX_MAX_LIST_ITEMS){
                    asn1 pi; if (enter_seq(&pols,&pi)) return SX_INVALID_FORMAT;
                    const uint8_t* po=NULL; size_t pl=0; if (get_oid(&pi,&po,&pl)) return SX_INVALID_FORMAT;
                    /* We’ll store dotted string as "OID" placeholder (or raw len) for simplicity */
                    snprintf(out->policy_oid[out->policy_count++], SX_MAX_ALG, "OID(len=%zu)", pl);
                    /* Ignore policyQualifiers for now */
                }
            } else {
                /* ignored extension */
            }
        }
    }

    /* ignore outer signature fields in this simple view */
    return SX_OK;
}

/* ------------------------------
 * Thumbprints (optional helper)
 * ------------------------------ */
void simple_x509_set_thumbprints(SimpleCert* out,
                                 const uint8_t* sha1,   size_t sha1_len,
                                 const uint8_t* sha256, size_t sha256_len)
{
    if (!out) return;
    if (sha1 && sha1_len == 20)  hexify_fixed(out->sha1_thumb,   sizeof(out->sha1_thumb),   sha1,   sha1_len);
    if (sha256 && sha256_len==32)hexify_fixed(out->sha256_thumb, sizeof(out->sha256_thumb), sha256, sha256_len);
}

/* Lightweight re-walk for verification materials:
   Certificate ::= SEQUENCE { tbsCertificate SEQUENCE, signatureAlgorithm AlgId, signatureValue BIT STRING } */
int simple_x509_locate_core(const uint8_t* der, size_t der_len,
                            const uint8_t** tbs_ptr, size_t* tbs_len,
                            const uint8_t** sig_alg_oid, size_t* sig_alg_oid_len,
                            const uint8_t** sig_value, size_t* sig_value_len)
{
    if (!der || der_len < 4 || !tbs_ptr || !tbs_len || !sig_alg_oid || !sig_alg_oid_len || !sig_value || !sig_value_len)
        return SX_BAD_INPUT;

    asn1 a={der,der+der_len}, cert, tbs;
    if (enter_seq(&a,&cert)) return SX_INVALID_FORMAT;          /* Certificate */
    /* Remember TBS *TLV* range: start at SEQUENCE tag, include header + content */
    const uint8_t *tbs_seq_start = cert.p;
    if (enter_seq(&cert,&tbs)) return SX_INVALID_FORMAT;         /* tbsCertificate (content) */
    /* Now: tbs.p..tbs.end = content(V).  cert.p advanced past SEQ header already.
       We want TLV, so start at tbs_seq_start (the tag), and end at tbs.end. */
    *tbs_ptr = tbs_seq_start;
    *tbs_len = (size_t)(tbs.end - tbs_seq_start);
    cert.p = tbs.end;

    /* signatureAlgorithm (outer) */
    asn1 sigalg;
    if (enter_seq(&cert, &sigalg)) return SX_INVALID_FORMAT;
    if (get_oid(&sigalg, sig_alg_oid, sig_alg_oid_len)) return SX_INVALID_FORMAT;
    /* tolerate/skip params if present */
    if (sigalg.p < sigalg.end){
        if (*sigalg.p == TAG_NULL){ if (get_null(&sigalg)) return SX_INVALID_FORMAT; }
        else { size_t L=0; uint8_t t=*sigalg.p++; if (get_len(&sigalg,&L)) return SX_INVALID_FORMAT;
               if ((size_t)(sigalg.end - sigalg.p) < L) return SX_INVALID_FORMAT; sigalg.p += L; (void)t; }
    }
    if (sigalg.p != sigalg.end) return SX_INVALID_FORMAT;

    /* signatureValue (outer) */
    if (get_bit_contents(&cert, sig_value, sig_value_len)) return SX_INVALID_FORMAT;
    if (cert.p != cert.end) return SX_INVALID_FORMAT;

    return SX_OK;
}

/* issuer/subject raw DER (their Name sequences inside TBS) */
int simple_x509_locate_names(const uint8_t* der, size_t der_len,
                             const uint8_t** issuer_ptr, size_t* issuer_len,
                             const uint8_t** subject_ptr, size_t* subject_len)
{
    if (!der || !issuer_ptr || !issuer_len || !subject_ptr || !subject_len) return SX_BAD_INPUT;
    asn1 a={der,der+der_len}, cert, tbs;
    if (enter_seq(&a,&cert) || enter_seq(&cert,&tbs)) return SX_INVALID_FORMAT;

    /* version [0] EXPLICIT DEFAULT v1 ? skip if present */
    if (tbs.p < tbs.end && *tbs.p == CTX_EXPL(0)){ size_t L=0; tbs.p++; if (get_len(&tbs,&L)) return SX_INVALID_FORMAT; if ((size_t)(tbs.end-tbs.p)<L) return SX_INVALID_FORMAT; tbs.p+=L; }

    /* serialNumber */ { const uint8_t *sp=NULL; size_t sl=0; if (get_int(&tbs,&sp,&sl)) return SX_INVALID_FORMAT; }
    /* signature (TBSCertificate) */ { asn1 tmp; if (enter_seq(&tbs,&tmp)) return SX_INVALID_FORMAT; tbs.p = tmp.end; }

    /* issuer Name: capture TLV range of the SEQUENCE value (we return just content) */
    { asn1 name; if (enter_seq(&tbs,&name)) return SX_INVALID_FORMAT;
      *issuer_ptr = name.p; *issuer_len = (size_t)(name.end - name.p);
      tbs.p = name.end;
    }
    /* validity */ { asn1 val; if (enter_seq(&tbs,&val)) return SX_INVALID_FORMAT; tbs.p = val.end; }
    /* subject Name */
    { asn1 name; if (enter_seq(&tbs,&name)) return SX_INVALID_FORMAT;
      *subject_ptr = name.p; *subject_len = (size_t)(name.end - name.p);
      tbs.p = name.end;
    }
    return SX_OK;
}

/* SPKI raw public key bits (exact bytes after removing 1-byte 'unused bits' header) */
int simple_x509_locate_spki_bits(const uint8_t* der, size_t der_len,
                                 const uint8_t** spki_bits, size_t* spki_bits_len)
{
    if (!der || !spki_bits || !spki_bits_len) return SX_BAD_INPUT;
    asn1 a={der,der+der_len}, cert, tbs;
    if (enter_seq(&a,&cert) || enter_seq(&cert,&tbs)) return SX_INVALID_FORMAT;

    /* Skip to subjectPublicKeyInfo */
    if (tbs.p < tbs.end && *tbs.p == CTX_EXPL(0)){ size_t L=0; tbs.p++; if (get_len(&tbs,&L)) return SX_INVALID_FORMAT; if ((size_t)(tbs.end-tbs.p)<L) return SX_INVALID_FORMAT; tbs.p+=L; }
    { const uint8_t *sp=NULL; size_t sl=0; if (get_int(&tbs,&sp,&sl)) return SX_INVALID_FORMAT; }       /* serialNumber */
    { asn1 tmp; if (enter_seq(&tbs,&tmp)) return SX_INVALID_FORMAT; tbs.p = tmp.end; }                  /* TBSCert.sig */
    { asn1 name; if (enter_seq(&tbs,&name)) return SX_INVALID_FORMAT; tbs.p = name.end; }               /* issuer */
    { asn1 val;  if (enter_seq(&tbs,&val )) return SX_INVALID_FORMAT; tbs.p = val.end; }                /* validity */
    { asn1 name; if (enter_seq(&tbs,&name)) return SX_INVALID_FORMAT; tbs.p = name.end; }               /* subject */

    /* subjectPublicKeyInfo */
    asn1 spki; if (enter_seq(&tbs,&spki)) return SX_INVALID_FORMAT;
    { asn1 alg; if (enter_seq(&spki,&alg)) return SX_INVALID_FORMAT; spki.p = alg.end; }                /* skip AlgId */
    if (get_bit_contents(&spki, spki_bits, spki_bits_len)) return SX_INVALID_FORMAT;
    return SX_OK;
}
