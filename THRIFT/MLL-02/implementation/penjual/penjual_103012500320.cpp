#include "../../header/penjual.h"

void deleteFirst(ListPenjual &LP, addressPenjual &P){
/* I.S. list LP tidak kosong
   F.S. elemen pertama LP dilepas dari list dan alamatnya disimpan pada P */
    P = LP.first;
    if (P != NULL) {
        if (LP.first == LP.last) {
            LP.first = NULL;
            LP.last = NULL;
        } else {
            LP.first = P->next;
            LP.first->prev = NULL;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteLast(ListPenjual &LP, addressPenjual &P){
/* I.S. list LP tidak kosong
   F.S. elemen terakhir LP dilepas dari list dan alamatnya disimpan pada P */
    P = LP.last;
    if (P != NULL) {
        if (LP.first == LP.last) {
            LP.first = NULL;
            LP.last = NULL;
        } else {
            LP.last = P->prev;
            LP.last->next = NULL;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfter(ListPenjual &LP, addressPenjual Prec, addressPenjual &P){
/* I.S. list LP tidak kosong, Prec bukan elemen terakhir
   F.S. elemen setelah Prec dilepas dari list dan alamatnya disimpan pada P */
    P = NULL;
    if (Prec != NULL && Prec->next != NULL) {
        if (Prec->next == LP.last) {
            deleteLast(LP, P);
        } else {
            P = Prec->next;
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = NULL;
            P->prev = NULL;
        }
    }
}

void printInfo(ListPenjual LP){
/* I.S. list LP terdefinisi
   F.S. menampilkan seluruh data penjual pada LP ke layar, atau pesan kosong jika LP kosong */
    if (isEmpty(LP)) {
        cout << "List penjual kosong." << endl;
    } else {
        cout << "ID\tNama\t\tKota\t\tKontak" << endl;
        cout << "----------------------------------------------------------" << endl;
        addressPenjual P = LP.first;
        while (P != NULL) {
            cout << P->info.idPenjual << "\t"
                 << P->info.nama << "\t"
                 << P->info.kota << "\t"
                 << P->info.kontak << endl;
            P = P->next;
        }
    }
}

infotypePenjual inputPenjual(){
/* I.S. sembarang
   F.S. mengembalikan struct Penjual hasil input dari pengguna */
    infotypePenjual x;
    cout << "ID Penjual : ";
    cin >> x.idPenjual;
    cout << "Nama       : ";
    cin >> x.nama;
    cout << "Kota       : ";
    cin >> x.kota;
    cout << "Kontak     : ";
    cin >> x.kontak;
    return x;
}
