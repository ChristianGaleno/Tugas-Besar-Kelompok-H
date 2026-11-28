#include "../../header/penawaran.h"


bool isEmpty(ListPenawaran LPW){
    return LPW.first == NULL && LPW.last == NULL;
}

void CreateList(ListPenawaran &LPW){
    LPW.first = NULL;
    LPW.last = NULL;
}

addressPenawaran createElemen(infotypePenawaran x, addressPenjual pPenjual, adrProduk pProduk){
    addressPenawaran P = new elmPenawaran;
    P->info = x;
    P->pPenjual = pPenjual;
    P->pProduk = pProduk;
    P->prev = NULL;
    P->next = NULL;
    return P;
}

void dealokasi(addressPenawaran &P){
    delete P;
    P = NULL;
}

addressPenawaran findElm(ListPenawaran LPW, string idPenjual, string idProduk){
    addressPenawaran P = LPW.first;
    addressPenawaran hasil = NULL;
    while (P != NULL && hasil == NULL) {
        if (P->pPenjual->info.idPenjual == idPenjual && P->pProduk->info.idProduk == idProduk) {
            hasil = P;
        }
        P = P->next;
    }
    return hasil;
}

void insertFirst(ListPenawaran &LPW, addressPenawaran P){
    if (isEmpty(LPW)) {
        LPW.first = P;
        LPW.last = P;
    } else {
        P->next = LPW.first;
        LPW.first->prev = P;
        LPW.first = P;
    }
}

void insertAfter(ListPenawaran &LPW, addressPenawaran Prec, addressPenawaran P){
    if (Prec != NULL) {
        if (Prec == LPW.last) {
            insertLast(LPW, P);
        } else {
            P->next = Prec->next;
            P->prev = Prec;
            Prec->next->prev = P;
            Prec->next = P;
        }
    }
}

void insertLast(ListPenawaran &LPW, addressPenawaran P){
    if (isEmpty(LPW)) {
        LPW.first = P;
        LPW.last = P;
    } else {
        P->prev = LPW.last;
        LPW.last->next = P;
        LPW.last = P;
    }
}

bool isProdukReferenced(ListPenawaran LPW, adrProduk pProduk){
    bool ada = false;
    addressPenawaran P = LPW.first;
    while (P != NULL && !ada) {
        ada = (P->pProduk == pProduk);
        P = P->next;
    }
    return ada;
}

bool isPenjualReferenced(ListPenawaran LPW, addressPenjual pPenjual){
    bool ada = false;
    addressPenawaran P = LPW.first;
    while (P != NULL && !ada) {
        ada = (P->pPenjual == pPenjual);
        P = P->next;
    }
    return ada;
}
