#include "../../header/produk.h"

bool isEmptyProduk(ListProduk LMK){
    return LMK.first == NULL && LMK.last == NULL;
}

void createListProduk(ListProduk &LMK){
    LMK.first = NULL;
    LMK.last = NULL;
}

adrProduk alokasiProduk(infotypeProduk x){
    adrProduk P = new ElmProduk;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasiProduk(adrProduk &P){
    delete P;
    P = NULL;
}

adrProduk findProduk(ListProduk LMK, string idProduk){
    adrProduk P = LMK.first;
    adrProduk hasil = NULL;
    while (P != NULL && hasil == NULL) {
        if (P->info.idProduk == idProduk) {
            hasil = P;
        }
        P = P->next;
    }
    return hasil;
}

void insertFirstProduk(ListProduk &LMK, adrProduk P){
    if (isEmptyProduk(LMK)) {
        LMK.first = P;
        LMK.last = P;
    } else {
        P->next = LMK.first;
        LMK.first->prev = P;
        LMK.first = P;
    }
}

void insertAfterProduk(ListProduk &LMK, adrProduk Prec, adrProduk P){
    if (Prec != NULL) {
        if (Prec == LMK.last) {
            insertLastProduk(LMK, P);
        } else {
            P->next = Prec->next;
            P->prev = Prec;
            Prec->next->prev = P;
            Prec->next = P;
        }
    }
}

void insertLastProduk(ListProduk &LMK, adrProduk P){
    if (isEmptyProduk(LMK)) {
        LMK.first = P;
        LMK.last = P;
    } else {
        P->prev = LMK.last;
        LMK.last->next = P;
        LMK.last = P;
    }
}
