#ifndef PRODUK_H_INCLUDED
#define PRODUK_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

// Child: Katalog Produk (jenis/model produk, bukan barang fisik)
struct Produk
{
    string idProduk;
    string namaProduk;
    string kategori;
    string merek;
};

typedef Produk infotypeProduk;                  // variabel alias untuk infor
typedef  struct ElmProduk *adrProduk;           // variabel alias untuk pointer

// kerangka dari elemen list
struct ElmProduk
{
    infotypeProduk info;
    adrProduk next;
};

// kerangka dari list
struct ListProduk
{
    adrProduk first;
};

// pengecekan apakah list kosong
bool isEmptyProduk(ListProduk LMK);
/* I.S. list LMK terdefinisi
   F.S. true jika list kosong dan false jika tidak kosong */

// pembuatan list kosong
void createListProduk(ListProduk &LMK);
/* I.S. ~
   F.S. terbentuk list kosong */

// manajemen memori
adrProduk alokasiProduk(infotypeProduk x);
/* I.S. info produk x terdefinisi
   F.S. mengembalikan alamat elemen berisi x dengan next NULL */

void dealokasiProduk(adrProduk &P);
/* I.S. pointer P terdefinisi
   F.S. memori yang digunakan P dikembalikan ke sistem */

// pencarian sebuah elemen list
adrProduk findProduk(ListProduk LMK, string idProduk);
/* I.S. list LMK dan id produk terdefinisi
   F.S. mengembalikan alamat elemen produk yang cocok atau NULL jika tidak ditemukan
*/

// penambahan elemen *
void insertFirstProduk(ListProduk &LMK, adrProduk P);
/* I.S. terdefinisi list LMK yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada awal list */

void insertAfterProduk(ListProduk &LMK, adrProduk Prec, adrProduk P);
/* I.S. terdefinisi list LMK yang mungkin kosong, elemen list P dan elemn list prec
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */

void insertLastProduk(ListProduk &LMK, adrProduk P);
/* I.S. terdefinisi list LMK yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada akhir list */

// penghapusan sebuah elemen
void deleteFirstProduk(ListProduk &LMK, adrProduk &P);
/* I.S. terdefinisi list LMK yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen pertama list
        yang akan dihapus dan elemen list selanjutnya akan menjadi
        elemenlist pertama atau tidak ada elemen list pertama*/

void deleteLastProduk(ListProduk &LMK, adrProduk &P);
/* I.S. terdefinisi list LMK yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen terakhir list
        yang akan dihapus dan elemen list sebelumnya akan menjadi
        elemenlist terakhir atau tidak ada elemen list terakhir */

void deleteAfterProduk(ListProduk &LMK, adrProduk Prec, adrProduk &P);
/* I.S. terdefinisi list LMK yang mungkin kosong, elemen list P dan elemn list prec
   F.S. P adalah alamat dari alamat elemen list setelah prec
        yang akan dihapus dan elemen list setelah p akan terhubung
        langsung dengan prec atau tidak ada elemen list setelahnya */

void printProduk(ListProduk LMK);
/* I.S. terdefinisi list LMK yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list */

infotypeProduk inputProduk();
/* I.S. ~
   F.S. meminta data produk dari user */

#endif // PRODUK_H_INCLUDED
