#ifndef TRANSAKSIBST_H_INCLUDED
#define TRANSAKSIBST_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

// Transaksi penjualan; identitas unik: noTransaksi
struct Transaksi
{
    string noTransaksi;
    string namaPembeli;
    string idPenjual;
    string idProduk;
    int jumlahBarang;
    int totalHarga;
    string statusPembayaran;    // "lunas" atau "belum bayar"
};

typedef Transaksi infotypeTransaksi;           // variabel alias untuk infor
typedef  struct nodeTransaksi *adrTransaksi;   // variabel alias untuk pointer

// kerangka dari elemen node
struct nodeTransaksi
{
    infotypeTransaksi info;
    adrTransaksi left;
    adrTransaksi right;
};

// kerangka dari BST
struct BST
{
    adrTransaksi root;
};

bool isSebelum(infotypeTransaksi left, infotypeTransaksi right);
/* I.S. record left dan right terdefinisi
   F.S. true jika record left berada sebelum record right sesuai urutan BST:
        jumlah barang lebih kecil lebih dulu, jika sama maka nomor transaksi
        yang lebih kecil (urutan string) lebih dulu */

int hitungTotalHarga(int hargaSatuan, int jumlahBarang);
/* I.S. harga penawaran per barang dan jumlah barang terdefinisi
   F.S. mengembalikan hargaSatuan * jumlahBarang */

// pengecekan apakah BST kosong
bool isEmptyBST(BST T);
/* I.S. BST T terdefinisi
   F.S. true jika BST kosong dan false jika tidak kosong */

// pembuatan BST kosong
void createBST(BST &T);
/* I.S. ~
   F.S. terbentuk BST kosong */

// manajemen memori
adrTransaksi alokasiTransaksi(infotypeTransaksi x);
/* I.S. info x terdefinisi
   F.S. mengembalikan alamat node berisi x dengan anak kiri dan kanan NULL */

void dealokasiTransaksi(adrTransaksi &P);
/* I.S. pointer P terdefinisi
   F.S. memori yang digunakan P dikembalikan ke sistem */

// pencarian sebuah elemen node
adrTransaksi findTransaksi(BST T, string noTransaksi);
/* I.S. BST T dan nomor transaksi terdefinisi
   F.S. mengembalikan alamat node yang cocok atau NULL jika tidak ditemukan
*/

// penambahan elemen *
void insertTransaksi(BST &T, adrTransaksi P);
/* I.S. terdefinisi BST T yang mungkin kosong dan elemen node P
   F.S. menempatkan elemen beralamat P berdasarkan jumlah barang,
        lalu nomor transaksi sebagai tie-breaker (lihat isSebelum) */

// penghapusan node yang sudah diketahui alamatnya
void deleteNode(BST &T, adrTransaksi &P);
/* I.S. terdefinisi BST T yang mungkin kosong dan elemen node P
   F.S. P adalah alamat dari alamat elemen yang akan dihapus.
        elemen lain menggantikan posisi elemen P yang dihapus
        sesuai aturan BST*/

void deleteTransaksi(BST &T, string noTransaksi);
/* I.S. terdefinisi BST T dan nomor transaksi
   F.S. record yang cocok dihapus jika ditemukan */

void printInOrder(BST T);
/* I.S. terdefinisi BST T
   F.S. seluruh transaksi ditampilkan dengan traversal in-order */

void printPreOrder(BST T);
/* I.S. terdefinisi BST T
   F.S. seluruh transaksi ditampilkan dengan traversal pre-order */

void printPostOrder(BST T);
/* I.S. terdefinisi BST T
   F.S. seluruh transaksi ditampilkan dengan traversal post-order */

adrTransaksi findMin(BST T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan node dengan jumlah barang minimum atau NULL jika BST kosong */

adrTransaksi findMax(BST T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan node dengan jumlah barang maksimum atau NULL jika BST kosong */

int tinggiBST(BST T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan tinggi BST; tinggi pohon kosong adalah 0 */

int jumlahNode(BST T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan jumlah node dalam BST (total transaksi aplikasi) */

infotypeTransaksi inputTransaksi();
/* I.S. ~
   F.S. meminta data transaksi penjualan dari user */


#endif // TRANSAKSIBST_H_INCLUDED

# Christian Galeno