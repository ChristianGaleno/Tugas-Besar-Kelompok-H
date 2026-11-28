#include "dummy.h"

void dummyPenjual(ListPenjual &LP){
    infotypePenjual data[5] = {
        {"P01", "Rina Thrift",     "Bandung",    "0812-1111-2201"},
        {"P02", "Vintage Corner",  "Jakarta",    "0813-2222-3302"},
        {"P03", "Kloset Kedua",    "Yogyakarta", "0815-3333-4403"},
        {"P04", "Second Chance",   "Surabaya",   "0817-4444-5504"},
        {"P05", "Preloved Hub",    "Malang",     "0819-5555-6605"}
    };

    for (int i = 0; i < 5; i++) {
        insertLast(LP, createElemen(data[i]));
    }
}

void dummyProduk(ListProduk &LK){
    infotypeProduk data[6] = {
        {"K01", "Jaket Denim Trucker", "Jaket",  "Levi's"},
        {"K02", "Sneakers Air Force 1", "Sepatu", "Nike"},
        {"K03", "Kemeja Flanel",       "Kemeja", "Uniqlo"},
        {"K04", "Tas Ransel Classic",  "Tas",    "Eastpak"},
        {"K05", "Hoodie Basic",        "Hoodie", "H&M"},
        {"K06", "Celana Chino Slim",   "Celana", "Zara"}
    };

    for (int i = 0; i < 6; i++) {
        insertLastProduk(LK, alokasiProduk(data[i]));
    }
}

void tambahPenawaranDummy(ListPenjual &LP, ListProduk &LK, ListPenawaran &LPW, string idPenjual, string idProduk, int harga, string kondisi, int stok){
    addressPenjual pP = findElm(LP, idPenjual);
    adrProduk pK = findProduk(LK, idProduk);
    if (pP != NULL && pK != NULL) {
        infotypePenawaran x;
        x.harga = harga;
        x.kondisiBarang = kondisi;
        x.stok = stok;
        x.status = tentukanStatus(stok);
        insertLast(LPW, createElemen(x, pP, pK));
    }
}

void dummyPenawaran(ListPenjual &LP, ListProduk &LK, ListPenawaran &LPW){
    tambahPenawaranDummy(LP, LK, LPW, "P01", "K01", 250000, "Like New",   3);
    tambahPenawaranDummy(LP, LK, LPW, "P01", "K03", 120000, "Baik",       5);
    tambahPenawaranDummy(LP, LK, LPW, "P01", "K05", 150000, "Baik",       0);   
    tambahPenawaranDummy(LP, LK, LPW, "P02", "K02", 650000, "Like New",   2);
    tambahPenawaranDummy(LP, LK, LPW, "P02", "K01", 230000, "Baik",       4);
    tambahPenawaranDummy(LP, LK, LPW, "P02", "K06", 140000, "Cukup Baik", 6);
    tambahPenawaranDummy(LP, LK, LPW, "P03", "K03",  95000, "Cukup Baik", 7);
    tambahPenawaranDummy(LP, LK, LPW, "P03", "K04", 310000, "Like New",   2);
    tambahPenawaranDummy(LP, LK, LPW, "P04", "K02", 590000, "Baik",       3);
    tambahPenawaranDummy(LP, LK, LPW, "P04", "K05", 165000, "Like New",   4);
    tambahPenawaranDummy(LP, LK, LPW, "P05", "K06", 125000, "Baik",       5);
    tambahPenawaranDummy(LP, LK, LPW, "P05", "K04", 280000, "Baik",       1);
}

void dummyTransaksi(BST &T){
    infotypeTransaksi data[12] = {
        {"TRX5274", "Dewi",  "P04", "K05", 2,  330000, "lunas"},
        {"TRX7012", "Sinta", "P05", "K06", 1,  125000, "lunas"},
        {"TRX9156", "Andi",  "P02", "K01", 3,  690000, "lunas"},
        {"TRX2317", "Sinta", "P02", "K02", 1,  650000, "lunas"},
        {"TRX1042", "Andi",  "P01", "K01", 2,  500000, "lunas"},
        {"TRX4108", "Andi",  "P01", "K03", 3,  360000, "belum bayar"},
        {"TRX3561", "Budi",  "P03", "K03", 4,  380000, "lunas"},
        {"TRX1583", "Rudi",  "P01", "K05", 1,  150000, "lunas"},
        {"TRX7895", "Dewi",  "P03", "K04", 1,  310000, "lunas"},
        {"TRX2740", "Maya",  "P05", "K04", 2,  560000, "belum bayar"},
        {"TRX8421", "Budi",  "P04", "K02", 2, 1180000, "lunas"},
        {"TRX6630", "Rudi",  "P02", "K06", 5,  700000, "lunas"}
    };

    for (int i = 0; i < 12; i++) {
        insertTransaksi(T, alokasiTransaksi(data[i]));
    }
}
