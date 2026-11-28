#include "../../header/produk.h"

void deleteFirstProduk(ListProduk &LMK, adrProduk &P){
/* I.S. terdefinisi list LMK yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen pertama list
        yang akan dihapus dan elemen list selanjutnya akan menjadi
        elemenlist pertama atau tidak ada elemen list pertama*/
    P = LMK.first;
    if (P != NULL) {
        if (LMK.first == LMK.last) {
            LMK.first = NULL;
            LMK.last = NULL;
        } else {
            LMK.first = P->next;
            LMK.first->prev = NULL;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteLastProduk(ListProduk &LMK, adrProduk &P){
/* I.S. terdefinisi list LMK yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen terakhir list
        yang akan dihapus dan elemen list sebelumnya akan menjadi
        elemenlist terakhir atau tidak ada elemen list terakhir */
    P = LMK.last;
    if (P != NULL) {
        if (LMK.first == LMK.last) {
            LMK.first = NULL;
            LMK.last = NULL;
        } else {
            LMK.last = P->prev;
            LMK.last->next = NULL;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfterProduk(ListProduk &LMK, adrProduk Prec, adrProduk &P){
/* I.S. terdefinisi list LMK yang mungkin kosong, elemen list P dan elemn list prec
   F.S. P adalah alamat dari alamat elemen list setelah prec
        yang akan dihapus dan elemen list setelah p akan terhubung
        langsung dengan prec atau tidak ada elemen list setelahnya */
    P = NULL;
    if (Prec != NULL && Prec->next != NULL) {
        if (Prec->next == LMK.last) {
            deleteLastProduk(LMK, P);
        } else {
            P = Prec->next;
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = NULL;
            P->prev = NULL;
        }
    }
}

void printProduk(ListProduk LMK){
/* I.S. terdefinisi list LMK yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmptyProduk(LMK)) {
        cout << "List produk kosong." << endl;
    } else {
        cout << "ID\tNama Produk\t\tKategori\tMerek" << endl;
        cout << "----------------------------------------------------------" << endl;
        adrProduk P = LMK.first;
        while (P != NULL) {
            cout << P->info.idProduk << "\t"
                 << P->info.namaProduk << "\t"
                 << P->info.kategori << "\t"
                 << P->info.merek << endl;
            P = P->next;
        }
    }
}

infotypeProduk inputProduk(){
/* I.S. ~
   F.S. meminta data produk dari user */
    infotypeProduk x;
    cout << "ID Produk   : ";
    cin >> x.idProduk;
    cout << "Nama Produk : ";
    cin >> x.namaProduk;
    cout << "Kategori    : ";
    cin >> x.kategori;
    cout << "Merek       : ";
    cin >> x.merek;
    return x;
}
