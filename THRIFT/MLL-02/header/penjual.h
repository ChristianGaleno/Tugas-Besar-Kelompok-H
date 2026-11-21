#ifndef PENJUAL_H_INCLUDED
#define PENJUAL_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct Penjual {
    string idPenjual;
    string nama;
    string kota;
    string kontak;
};

typedef Penjual infotypePenjual;
typedef struct elmPenjual *addressPenjual;

struct elmPenjual {
    infotypePenjual info;
    addressPenjual prev;
    addressPenjual next;
};

struct ListPenjual {
    addressPenjual first;
    addressPenjual last;
};

// ==================== PRIMITIF DASAR ADT (MINGGU KE-10) ====================
bool isEmpty(ListPenjual LP);
/* I.S. list LP terdefinisi
   F.S. mengembalikan true jika list LP kosong (first == NULL && last == NULL), false jika tidak */

void CreateList(ListPenjual &LP);
/* I.S. sembarang
   F.S. terbentuk list LP kosong dengan first = NULL dan last = NULL */

addressPenjual createElemen(infotypePenjual x);
/* I.S. data penjual x terdefinisi
   F.S. mengembalikan alamat elemen baru berisi info x dengan prev = NULL dan next = NULL */

void dealokasi(addressPenjual &P);
/* I.S. pointer P terdefinisi
   F.S. memori elemen yang ditunjuk P dibebaskan dan P bernilai NULL */

// ==================== PRIMITIF OPERASI LIST (MINGGU KE-11) ====================
addressPenjual findElm(ListPenjual LP, string idPenjual);
/* I.S. list LP dan idPenjual terdefinisi
   F.S. mengembalikan alamat elemen penjual dengan idPenjual yang sesuai, atau NULL jika tidak ditemukan */

void insertFirst(ListPenjual &LP, addressPenjual P);
/* I.S. list LP terdefinisi (mungkin kosong), elemen P teralokasi
   F.S. elemen P ditempatkan sebagai elemen pertama pada list LP */

void insertAfter(ListPenjual &LP, addressPenjual Prec, addressPenjual P);
/* I.S. list LP tidak kosong, Prec adalah elemen valid di LP, elemen P teralokasi
   F.S. elemen P disisipkan tepat setelah elemen Prec */

void insertLast(ListPenjual &LP, addressPenjual P);
/* I.S. list LP terdefinisi (mungkin kosong), elemen P teralokasi
   F.S. elemen P ditempatkan sebagai elemen terakhir pada list LP */

void deleteFirst(ListPenjual &LP, addressPenjual &P);
/* I.S. list LP tidak kosong
   F.S. elemen pertama LP dilepas dari list dan alamatnya disimpan pada P */

void deleteLast(ListPenjual &LP, addressPenjual &P);
/* I.S. list LP tidak kosong
   F.S. elemen terakhir LP dilepas dari list dan alamatnya disimpan pada P */

void deleteAfter(ListPenjual &LP, addressPenjual Prec, addressPenjual &P);
/* I.S. list LP tidak kosong, Prec bukan elemen terakhir
   F.S. elemen setelah Prec dilepas dari list dan alamatnya disimpan pada P */

void printInfo(ListPenjual LP);
/* I.S. list LP terdefinisi
   F.S. menampilkan seluruh data penjual pada LP ke layar, atau pesan kosong jika LP kosong */

infotypePenjual inputPenjual();
/* I.S. sembarang
   F.S. mengembalikan struct Penjual hasil input dari pengguna */

#endif // PENJUAL_H_INCLUDED