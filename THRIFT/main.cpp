#include <iostream>
#include <cstdlib>
#include <ctime>
#include "interface.h"
#include "dummy.h"

using namespace std;

int main() {
    ListPenjual LP;
    ListProduk LK;
    ListPenawaran LPW;
    BST T;

    srand(time(NULL));     

    CreateList(LP);
    createListProduk(LK);
    CreateList(LPW);
    createBST(T);

    dummyPenjual(LP);
    dummyProduk(LK);
    dummyPenawaran(LP, LK, LPW);
    dummyTransaksi(T);

    menu(LP, LK, LPW, T);
    return 0;
}
