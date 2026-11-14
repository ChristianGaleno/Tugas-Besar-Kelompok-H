# Marketplace Preloved (Thrift.in)

## Deskripsi
Aplikasi marketplace preloved (Thrift.in) mempertemukan penjual dengan berbagai katalog produk preloved. Satu penjual dapat menawarkan banyak jenis produk dan satu jenis produk dapat ditawarkan oleh beberapa penjual dengan kondisi serta harga yang berbeda. Pelanggan dapat membeli produk dari penjual tertentu. Informasi penawaran dikelola melalui Multi Linked List, sedangkan transaksi penjualan dicatat dalam Binary Search Tree.

---

## Struktur Data

| List | Deskripsi |
|----------|--------|
| Penjual (Parent - DLL) | Penjual (id penjual, nama, kota, kontak) |
| Katalog Produk (Child - DLL) | Katalog Produk (id produk, nama produk, kategori, merek) — Catatan: merupakan katalog jenis/model produk, bukan barang fisik |
| Penawaran (Relasi - DLL) | Penawaran (harga, kondisi barang, stok, status: tersedia, habis) |
| Binary Search Tree | Transaksi penjualan dengan key nomor transaksi (nama pembeli, id penjual, id produk, jumlah barang, total harga, status pembayaran) |

---

## Arsitektur
Arsitektur pada topik tugas besar ini menggunakan multi linked list tipe-02 (Parent: DLL, Relasi: DLL, Child: DLL) dan binary search tree

1. Multi Linked List Tipe-02

   ![Multi Linked List Tipe-02](https://lh3.googleusercontent.com/d/1kqhZSokWiYq0H1S-KqoaU8BN9zahAC8E)

2. Binary Search Tree

   ![Binary Search Tree](https://lh3.googleusercontent.com/d/1arzmXS-nRgc0jmlnZTMYmHEOB5MVnoyp)
---

## Fitur / Fungsional Program
### Fungsional Umum
Fungsionalitas yang harus terpenuhi untuk **Multi-Linked list** adalah 
1. Menyisipkan elemen Penjual, Katalog Produk, dan Penawaran (first, last, after)
2. Menghapus elemen Penjual, Katalog Produk, dan Penawaran (first, last, after)
3. Mencari elemen Penjual, Katalog Produk, dan Penawaran
4. Menampilkan seluruh data pada list (Penjual, Katalog Produk, Penawaran)
5. Membuat data dummy untuk masing-masing list minimal 5 data (Penjual, Katalog Produk) dan 10 data (Penawaran)
6. Melengkapi Main Program (interface)

Fungsionalitas yang harus terpenuhi untuk **Binary Search tree** adalah 
1. Menyisipkan node berisikan transaksi penjualan berdasarkan nomor transaksi.
2. Menghapus node berisikan transaksi penjualan berdasarkan nomor transaksi. 
3. Mencari node berisikan transaksi penjualan berdasarkan nomor transaksi.
4. Menampilkan seluruh data secara traversal (in-order, pre-order, dan post-order).
5. Menampilkan nilai minimum, maksimum, tinggi pohon, dan jumlah node.
6. Membuat data dummy untuk BST minimal 10 node berisikan transaksi penjualan.
7. Melengkapi Main Program (interface)

### Fungsional khusus
Fungsionalitas / studi kasus yang dipilih dari topik ini adalah
1. Melakukan transaksi pembelian dengan memilih produk dan penjual serta memperbarui stok penawaran setelah transaksi berhasil.
2. Menyimpan transaksi pembelian ke BST berdasarkan jumlah barang.
3. Menampilkan penjual dengan pendapatan penjualan terbanyak.
4. Menampilkan total transaksi aplikasi.

### Fungsional tambahan (Bonus)
Fungsionalitas / studi kasus bonus yang dipilih dari topik ini adalah
1. Menampilkan informasi produk dengan penjualan terbanyak.
2. Menampilkan penjual dengan harga penawaran termurah untuk produk tertentu.
3. Menampilkan riwayat transaksi berdasarkan nama pembeli.

---

## Struktur Folder
```bash
├── Tugas-Besar-Kelompok-H
│   ├── Thrift.in
│   │   ├── interface.cpp
│   │   ├── interface.h
│   │   ├── main.cpp
│   │   ├── Thrift.in.cbp
│   │   ├── Thrift.in.layout
│   │   │
│   │   ├── Bonus
│   │   │   ├── header
│   │   │   │   └── bonus.h
│   │   │   └── implementation
│   │   │       └── bonus.cpp
│   │   │
│   │   ├── BST
│   │   │   ├── header 
│   │   │   │   └── transaksiBST.h
│   │   │   └── implementation
│   │   │       ├── transaksiBST_[nim_anggota_1].cpp
│   │   │       └── transaksiBST_[nim_anggota_2].cpp
│   │   │
│   │   ├── Khusus
│   │   │   ├── header
│   │   │   │   └── khusus.h
│   │   │   └── implementation
│   │   │       └── khusus.cpp
│   │   │
│   │   └── MLL-02
│   │       ├── header
│   │       │   ├── produk.h
│   │       │   ├── penawaran.h
│   │       │   └── penjual.h
│   │       └── implementation
│   │           ├── produk
│   │           │   ├── produk_[nim_anggota_1].cpp
│   │           │   └── produk_[nim_anggota_2].cpp
│   │           ├── penawaran
│   │           │   ├── penawaran_[nim_anggota_1].cpp
│   │           │   └── penawaran_[nim_anggota_2].cpp
│   │           └── penjual
│   │               ├── penjual_[nim_anggota_1].cpp
│   │               └── penjual_[nim_anggota_2].cpp
├── README.md
└── .gitignore
