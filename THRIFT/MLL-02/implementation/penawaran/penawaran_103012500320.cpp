#include "../../header/penawaran.h"

void deleteFirst(ListPenawaran &LPW, addressPenawaran &P){
/* I.S. list LPW tidak kosong
   F.S. elemen pertama LPW dilepas dari list dan alamatnya disimpan pada P */
    P = LPW.first;
    if (P != NULL) {
        if (LPW.first == LPW.last) {
            LPW.first = NULL;
            LPW.last = NULL;
        } else {
            LPW.first = P->next;
            LPW.first->prev = NULL;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteLast(ListPenawaran &LPW, addressPenawaran &P){
/* I.S. list LPW tidak kosong
   F.S. elemen terakhir LPW dilepas dari list dan alamatnya disimpan pada P */
    P = LPW.last;
    if (P != NULL) {
        if (LPW.first == LPW.last) {
            LPW.first = NULL;
            LPW.last = NULL;
        } else {
            LPW.last = P->prev;
            LPW.last->next = NULL;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfter(ListPenawaran &LPW, addressPenawaran Prec, addressPenawaran &P){
/* I.S. list LPW tidak kosong, Prec bukan elemen terakhir
   F.S. elemen setelah Prec dilepas dari list dan alamatnya disimpan pada P */
    P = NULL;
    if (Prec != NULL && Prec->next != NULL) {
        if (Prec->next == LPW.last) {
            deleteLast(LPW, P);
        } else {
            P = Prec->next;
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = NULL;
            P->prev = NULL;
        }
    }
}

void printInfo(ListPenawaran LPW){
/* I.S. list LPW terdefinisi
   F.S. menampilkan seluruh data penawaran beserta informasi penjual dan produknya */
    if (isEmpty(LPW)) {
        cout << "List penawaran kosong." << endl;
    } else {
        printHeaderPenawaran();
        addressPenawaran P = LPW.first;
        while (P != NULL) {
            printElmPenawaran(P);
            P = P->next;
        }
    }
}

infotypePenawaran inputPenawaran(){
/* I.S. sembarang
   F.S. mengembalikan struct Penawaran hasil input dari pengguna */
    infotypePenawaran x;
    cout << "Harga          : ";
    cin >> x.harga;
    cout << "Kondisi barang : ";
    cin >> x.kondisiBarang;
    cout << "Stok           : ";
    cin >> x.stok;
    x.status = tentukanStatus(x.stok);
    return x;
}

string tentukanStatus(int stok){
/* I.S. stok terdefinisi
   F.S. mengembalikan "tersedia" jika stok > 0, "habis" jika stok = 0 */
    string status = "habis";
    if (stok > 0) {
        status = "tersedia";
    }
    return status;
}

void printHeaderPenawaran(){
/* I.S. sembarang
   F.S. judul kolom tabel penawaran ditampilkan */
    cout << "ID\tPenjual\t\tID\tProduk\t\t\tHarga\tKondisi\t\tStok\tStatus" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
}

void printElmPenawaran(addressPenawaran P){
/* I.S. P menunjuk elemen penawaran yang valid (bukan NULL)
   F.S. satu baris data penawaran beserta penjual dan produknya ditampilkan */
    cout << P->pPenjual->info.idPenjual << "\t"
         << P->pPenjual->info.nama << "\t"
         << P->pProduk->info.idProduk << "\t"
         << P->pProduk->info.namaProduk << "\t"
         << P->info.harga << "\t"
         << P->info.kondisiBarang << "\t"
         << P->info.stok << "\t"
         << P->info.status << endl;
}

void printPenawaranByPenjual(ListPenawaran LPW, addressPenjual pPenjual){
/* I.S. list LPW dan pPenjual terdefinisi
   F.S. seluruh penawaran milik pPenjual ditampilkan, atau pesan jika tidak ada */
    bool ada = false;
    addressPenawaran P = LPW.first;
    while (P != NULL) {
        if (P->pPenjual == pPenjual) {
            if (!ada) {
                printHeaderPenawaran();
                ada = true;
            }
            printElmPenawaran(P);
        }
        P = P->next;
    }
    if (!ada) {
        cout << "Penjual ini belum memiliki penawaran." << endl;
    }
}

void printPenawaranByProduk(ListPenawaran LPW, adrProduk pProduk){
/* I.S. list LPW dan pProduk terdefinisi
   F.S. seluruh penawaran untuk produk pProduk ditampilkan, atau pesan jika tidak ada */
    bool ada = false;
    addressPenawaran P = LPW.first;
    while (P != NULL) {
        if (P->pProduk == pProduk) {
            if (!ada) {
                printHeaderPenawaran();
                ada = true;
            }
            printElmPenawaran(P);
        }
        P = P->next;
    }
    if (!ada) {
        cout << "Produk ini belum ditawarkan oleh penjual mana pun." << endl;
    }
}

void deletePenawaranByPenjual(ListPenawaran &LPW, addressPenjual pPenjual, int &jumlahTerhapus){
/* I.S. list LPW dan pPenjual terdefinisi
   F.S. seluruh penawaran yang menunjuk pPenjual dihapus dan didealokasi;
        jumlahTerhapus berisi banyaknya penawaran yang dihapus.
        Dipanggil SEBELUM penjual dihapus agar tidak ada pointer pPenjual yang menggantung */
    jumlahTerhapus = 0;
    addressPenawaran P = LPW.first;
    addressPenawaran Q;
    while (P != NULL) {
        addressPenawaran berikut = P->next;
        if (P->pPenjual == pPenjual) {
            if (P == LPW.first) {
                deleteFirst(LPW, Q);
            } else if (P == LPW.last) {
                deleteLast(LPW, Q);
            } else {
                deleteAfter(LPW, P->prev, Q);
            }
            dealokasi(Q);
            jumlahTerhapus++;
        }
        P = berikut;
    }
}

void deletePenawaranByProduk(ListPenawaran &LPW, adrProduk pProduk, int &jumlahTerhapus){
/* I.S. list LPW dan pProduk terdefinisi
   F.S. seluruh penawaran yang menunjuk pProduk dihapus dan didealokasi;
        jumlahTerhapus berisi banyaknya penawaran yang dihapus.
        Dipanggil SEBELUM produk dihapus agar tidak ada pointer pProduk yang menggantung */
    jumlahTerhapus = 0;
    addressPenawaran P = LPW.first;
    addressPenawaran Q;
    while (P != NULL) {
        addressPenawaran berikut = P->next;
        if (P->pProduk == pProduk) {
            if (P == LPW.first) {
                deleteFirst(LPW, Q);
            } else if (P == LPW.last) {
                deleteLast(LPW, Q);
            } else {
                deleteAfter(LPW, P->prev, Q);
            }
            dealokasi(Q);
            jumlahTerhapus++;
        }
        P = berikut;
    }
}

void perbaruiStok(addressPenawaran P, int jumlahTerjual){
/* I.S. P valid dan 0 < jumlahTerjual <= stok P
   F.S. stok P berkurang sebanyak jumlahTerjual dan status diperbarui
        ("habis" jika stok menjadi 0) */
    P->info.stok = P->info.stok - jumlahTerjual;
    P->info.status = tentukanStatus(P->info.stok);
}
