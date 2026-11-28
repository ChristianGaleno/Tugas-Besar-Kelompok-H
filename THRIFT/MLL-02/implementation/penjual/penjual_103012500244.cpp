#include "../../header/penjual.h"

bool isEmpty(ListPenjual LP){
    return LP.first == NULL && LP.last == NULL;
}

void CreateList(ListPenjual &LP){
    LP.first = NULL;
    LP.last = NULL;
}

addressPenjual createElemen(infotypePenjual x){
    addressPenjual P = new elmPenjual;
    P->info = x;
    P->prev = NULL;
    P->next = NULL;
    return P;
}

void dealokasi(addressPenjual &P){
    delete P;
    P = NULL;
}

addressPenjual findElm(ListPenjual LP, string idPenjual){
    addressPenjual P = LP.first;
    addressPenjual hasil = NULL;
    while (P != NULL && hasil == NULL) {
        if (P->info.idPenjual == idPenjual) {
            hasil = P;
        }
        P = P->next;
    }
    return hasil;
}

void insertFirst(ListPenjual &LP, addressPenjual P){
    if (isEmpty(LP)) {
        LP.first = P;
        LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertAfter(ListPenjual &LP, addressPenjual Prec, addressPenjual P){
    if (Prec != NULL) {
        if (Prec == LP.last) {
            insertLast(LP, P);
        } else {
            P->next = Prec->next;
            P->prev = Prec;
            Prec->next->prev = P;
            Prec->next = P;
        }
    }
}

void insertLast(ListPenjual &LP, addressPenjual P){
    if (isEmpty(LP)) {
        LP.first = P;
        LP.last = P;
    } else {
        P->prev = LP.last;
        LP.last->next = P;
        LP.last = P;
    }
}
