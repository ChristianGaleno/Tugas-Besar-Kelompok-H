#ifndef DUMMY_H_INCLUDED
#define DUMMY_H_INCLUDED
#include "MLL-02/header/penjual.h"
#include "MLL-02/header/produk.h"
#include "MLL-02/header/penawaran.h"
#include "BST/header/transaksiBST.h"

void dummyPenjual(ListPenjual &LP);
/* I.S. LP terdefinisi dan kosong
   F.S. LP berisi 5 data penjual */

void dummyProduk(ListProduk &LK);
/* I.S. LK terdefinisi dan kosong
   F.S. LK berisi 6 data katalog produk */

void tambahPenawaranDummy(ListPenjual &LP, ListProduk &LK, ListPenawaran &LPW,
                          string idPenjual, string idProduk, int harga, string kondisi, int stok);
/* I.S. penjual idPenjual dan produk idProduk ada di LP dan LK
   F.S. satu penawaran baru yang menghubungkan keduanya ditambahkan di akhir LPW */

void dummyPenawaran(ListPenjual &LP, ListProduk &LK, ListPenawaran &LPW);
/* I.S. LP dan LK sudah berisi data dummy, LPW kosong
   F.S. LPW berisi 12 penawaran yang menghubungkan penjual dan produk */

void dummyTransaksi(BST &T);
/* I.S. T terdefinisi dan kosong
   F.S. T berisi 12 transaksi penjualan (konsisten dengan harga di dummyPenawaran) */

#endif // DUMMY_H_INCLUDED
