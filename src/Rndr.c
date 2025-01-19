#include <Rdvtr/Rndr.h>
#include <string.h>
#include <memory.h>
#include <ae2f/Ds/Arr.h>

static ae2f_CmpFunRet_t Rdvtr_fRndrGenComp(const Rdvtr_RndrQueryEl *l, const Rdvtr_RndrQueryEl *r) {
    return l->Pad - r->Pad;
}

ae2f_extern ae2f_SHAREDEXPORT
size_t Rdvtr_RndrGen(
    char* out,
    const char* in,
    Rdvtr_RndrQuery* queries
) {
    size_t ret = 0;
    size_t Count, Pad = 0, Len = 0;
    Rdvtr_RndrQueryEl EL;

    if(!out) 
    goto Measure_Just_Size;
    if(!in) return 0;

    if(!queries) goto Pure_Copy;

    ae2f_cDsArrQSort(
        queries,
        Rdvtr_fRndrGenComp,
        sizeof(Rdvtr_RndrQueryEl)
    );
    
    ae2f_cDsAllocRefGetSize(
        queries, &Count, 0
    );

    char* out_origin = out;
    for(size_t i = 0; i < Count; i+= sizeof(Rdvtr_RndrQueryEl)) {
        ae2f_cDsAllocRefGets(
            queries, i, 
            &EL, sizeof(Rdvtr_RndrQueryEl)
        );

        InCpy:
        if(EL.Pad - Pad <= 0)
            goto ElCpy;
        
        strncpy(out, in, EL.Pad - Pad);
        in += EL.Pad - Pad;
        out += EL.Pad - Pad;
        ret += EL.Pad - Pad;
        Pad = EL.Pad;

        ElCpy:
        if(!EL.Str) continue;
        Len = strlen(EL.Str);
        strncpy(out, EL.Str, Len);
        out += Len;
        ret += Len;
    }
    size_t rest = strlen(in) + 1;
    strncpy(out, in, rest);
    return ret + rest;

    Measure_Just_Size: {
        ret += strlen(in);
        if(!queries) return ret + 1;
        ae2f_cDsAllocRefGetSize(
            queries, &Count, 0
        );
        for(size_t i = 0; i < Count; i+=sizeof(Rdvtr_RndrQueryEl)) {
            ae2f_cDsAllocRefGets(
                queries, i, 
                &EL, sizeof(Rdvtr_RndrQueryEl)
            );

            ret += strlen(EL.Str);
        }
        return ret + 1;
    }

    Pure_Copy: {
        if(!in) return 0;
        ret = strlen(in) + 1;
        memcpy(out, in, ret);
        return ret;
    }
}