#ifndef PENAWARAN_H_INCLUDED
#define PENAWARAN_H_INCLUDED

#include <iostream>
#include <string>
#include "penjual.h"
#include "produk.h"

using namespace std;

struct Penawaran {
    int harga;
    string kondisiBarang;
    int stok;
    string status; // "tersedia" atau "habis"
};

typedef Penawaran infotypePenawaran;
typedef struct elmPenawaran *addressPenawaran;

// Model MLL-02: ListRelasi berdiri sejajar (DLL) dengan pointer ke Parent dan Child
struct elmPenawaran {
    infotypePenawaran info;
    addressPenjual pPenjual;
    adrProduk pProduk;
    addressPenawaran prev;
    addressPenawaran next;
};

struct ListPenawaran {
    addressPenawaran first;
    addressPenawaran last;
};

// ==================== PRIMITIF DASAR ADT (MINGGU KE-10) ====================
bool isEmpty(ListPenawaran LPW);
/* I.S. list LPW terdefinisi
   F.S. mengembalikan true jika list LPW kosong (first == NULL && last == NULL), false jika tidak */

void CreateList(ListPenawaran &LPW);
/* I.S. sembarang
   F.S. terbentuk list LPW kosong dengan first = NULL dan last = NULL */

addressPenawaran createElemen(infotypePenawaran x, addressPenjual pPenjual, adrProduk pProduk);
/* I.S. info penawaran x, pointer pPenjual, dan pointer pProduk terdefinisi
   F.S. mengembalikan alamat elemen penawaran baru dengan prev = NULL, next = NULL,
        pPenjual menunjuk penjual terkait, dan pProduk menunjuk katalog produk terkait */

void dealokasi(addressPenawaran &P);
/* I.S. pointer P terdefinisi
   F.S. memori elemen penawaran P dibebaskan dan P bernilai NULL (elemen penjual & produk tidak dihapus) */

// ==================== PRIMITIF OPERASI LIST (MINGGU KE-11) ====================
addressPenawaran findElm(ListPenawaran LPW, string idPenjual, string idProduk);
/* I.S. list LPW, idPenjual, dan idProduk terdefinisi
   F.S. mengembalikan alamat elemen penawaran yang menghubungkan idPenjual dan idProduk, atau NULL jika tidak ada */

void insertFirst(ListPenawaran &LPW, addressPenawaran P);
/* I.S. list LPW terdefinisi (mungkin kosong), elemen P teralokasi
   F.S. elemen P ditempatkan sebagai elemen pertama pada list LPW */

void insertAfter(ListPenawaran &LPW, addressPenawaran Prec, addressPenawaran P);
/* I.S. list LPW tidak kosong, Prec adalah elemen valid di LPW, elemen P teralokasi
   F.S. elemen P disisipkan tepat setelah elemen Prec */

void insertLast(ListPenawaran &LPW, addressPenawaran P);
/* I.S. list LPW terdefinisi (mungkin kosong), elemen P teralokasi
   F.S. elemen P ditempatkan sebagai elemen terakhir pada list LPW */

void deleteFirst(ListPenawaran &LPW, addressPenawaran &P);
/* I.S. list LPW tidak kosong
   F.S. elemen pertama LPW dilepas dari list dan alamatnya disimpan pada P */

void deleteLast(ListPenawaran &LPW, addressPenawaran &P);
/* I.S. list LPW tidak kosong
   F.S. elemen terakhir LPW dilepas dari list dan alamatnya disimpan pada P */

void deleteAfter(ListPenawaran &LPW, addressPenawaran Prec, addressPenawaran &P);
/* I.S. list LPW tidak kosong, Prec bukan elemen terakhir
   F.S. elemen setelah Prec dilepas dari list dan alamatnya disimpan pada P */

void printInfo(ListPenawaran LPW);
/* I.S. list LPW terdefinisi
   F.S. menampilkan seluruh data penawaran beserta informasi penjual dan produknya */

bool isProdukReferenced(ListPenawaran LPW, adrProduk pProduk);
/* I.S. list LPW dan pointer pProduk terdefinisi
   F.S. mengembalikan true jika pProduk masih direferensikan oleh minimal satu penawaran */

bool isPenjualReferenced(ListPenawaran LPW, addressPenjual pPenjual);
/* I.S. list LPW dan pointer pPenjual terdefinisi
   F.S. mengembalikan true jika pPenjual masih memiliki minimal satu penawaran */

infotypePenawaran inputPenawaran();
/* I.S. sembarang
   F.S. mengembalikan struct Penawaran hasil input dari pengguna */

#endif // PENAWARAN_H_INCLUDED