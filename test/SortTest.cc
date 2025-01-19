#include <ae2f/Ds/Arr.hpp>
#include <stdio.h>
static ae2f_CmpFunRet_t Rdvtr_fRndrGenComp(const int *l, const int *r) {
    return *l - *r;
}

int main() {
    ae2f::Ds::Arr::cOwner::Linear_t<int> V;
    V.Resize(5);

    V.Write(0, 7);
    V.Write(1, 6);
    V.Write(2, 5);
    V.Write(3, 9);
    V.Write(4, 15);

    ae2f_cDsArrQSort(&V, Rdvtr_fRndrGenComp, sizeof(int));

    printf("%d\n", V.Read(0, 0));
    printf("%d\n", V.Read(1, 0));
    printf("%d\n", V.Read(2, 0));
    printf("%d\n", V.Read(3, 0));
    printf("%d\n", V.Read(4, 0));
    
    if(V.Read(0, 0) != 5) return 10;
    if(V.Read(1, 0) != 6) return 11;
    if(V.Read(2, 0) != 7) return 12;
    if(V.Read(3, 0) != 9) return 13;
    if(V.Read(4, 0) != 15) return 14;

    return 0;
}