#include <stdlib.h>
#include "list_parent.h"
#include "list_child.h"

void createList_Parent (List_Parent &L)
{
    /**
    * NIM : 1301150440
    * FS : first(L) di set NULL
    */
    L.first = NULL;
}

address_parent alokasi_Parent (infotype_parent x)
{
    /**
    * NIM : 1301150440
    * FS : mengembalikan elemen list baru dengan infotype = x, next elemen = NULL, dan create list untuk child
    */
    address_parent P;
    P = new ElmList_Parent;
    info(P) = x;
    next(P) = NULL;
    createList_Child(child(P));
    return P;
}

void dealokasi_Parent (address_parent &P)
{
    /**
    * NIM : 1301150440
    * FS : menghapus elemen yang ditunjuk oleh P
    */
    delete P;
}

void insertFirst_Parent  (List_Parent &L, address_parent P)
{
    /**
    * NIM :1301150440
    * IS : List Parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_Parent L
    */
    if (L.first == NULL)
    {
        L.first = P;
        P->next = NULL;
    }
    else
    {
        P->next = L.first;
        L.first = P;
    }
}

void insertAfter_Parent (List_Parent &L, address_parent P, address_parent Q)
{
    /**
    * NIM : 1301150440
    * IS : List Parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen yang ditambahkan diantara elemen Q pada List_Parent L
    */
    if (L.first != NULL)
    {
        if (next(Q) == NULL)
        {
            insertLast_Parent(L,P);
        }
        else
        {
            next(P) = next(Q);
            next(Q) = P;
        }
    }
    else
    {
        insertFirst_Parent(L,P);
    }
}

void insertLast_Parent  (List_Parent &L, address_parent P)
{
    /**
    * NIM : 1301150440
    * IS : List Parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List_Parent L
    */
    address_parent Q;
    if (L.first == NULL)
    {
        L.first = P;
    }
    else
    {
        Q = L.first;
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void ASC_Parent(List_Parent &L, address_parent &P){
    /**
    * NIM : 1301150440
    * IS : Data tidak terurut secara Ascending
    * FS : Mengurutkan List Parent berdasarkan ID secara Ascending
    */
    address_parent Q;
    if (L.first == NULL){
        insertAfter_Parent(L,P,Q);
    } else {
        Q = L.first;
        bool finded = false;
        if (Q->info.ID_Parent > P->info.ID_Parent){
            insertFirst_Parent(L,P);
        } else {
            while (next(Q) != NULL && !finded){
                Q = next(Q);
                if (info(P).ID_Parent < info(Q).ID_Parent){
                    Q = next(Q);
                    insertAfter_Parent(L,P, Q);
                    finded = true;
                } else if (info(P).ID_Parent == info(Q).ID_Parent){
                    cout << "dah ada" << endl;
                    finded = true;
                }
            }
            if (!finded && next(Q) == NULL){
                insertLast_Parent(L,P);
            }
        }
    }
}

address_parent findElm_Parent(List_Parent L, infotype_parent x)
{
    /**
    * NIM : 1301150440
    * IS : List Parent L mungkin kosong
    * FS : mengembalikan elemen parent dengan info = x,
           mengembalikan NULL jika tidak ditemukan
    */
    address_parent P = L.first;
    while (P!= NULL)
    {
        if (info(P).ID_Parent == x.ID_Parent)
        {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteFirst_Parent  (List_Parent &L, address_parent &P)
{
    /**
    * NIM : 1301154468
    * IS : List Parent L mungkin kosong
    * FS : elemen pertama di dalam List Parent L dilepas dan disimpan/ditunjuk oleh P
    */
    P = L.first;
    if (L.first != NULL)
    {
        if (L.first->next == NULL)
        {
            L.first = NULL;
            dealokasi_Parent(P);
        }
        else
        {
            L.first = P->next;
            P->next = NULL;
            dealokasi_Parent(P);
        }
    }
}

void deleteAfter_Parent (List_Parent &L, address_parent &Prec, address_parent &P)
{
    /**
    * NIM : 1301154468
    * IS : List Parent L tidak kosong
    * FS : P adalah alamat dari next(Prec), menghapus next(Prec) dari List Parent L
    */
    P = next(Prec);
    next(Prec) = next(P);
    dealokasi_Parent(P);
}

void deleteLast_Parent  (List_Parent &L, address_parent P)
{
    /**
    * NIM : 1301154468
    * IS : List Parent L mungkin kosong
    * FS : elemen terakhir didalam List Parent L dilepas dan disimpan/ditunjuk oleh P
    */
    P = L.first;
    address_parent prec;
    if (L.first != NULL)
    {
        if (L.first->next == NULL)
        {
            L.first = NULL;
        }
        else
        {
            while ((P->next)->next != NULL)
            {
                P = P->next;
            }
            prec = P;
            P = P->next;
            prec->next=NULL;
        }
    }
}

void deletebyID_Parent (List_Parent &L, address_parent &P)
{
    /**
    * NIM : 1301154468
    * IS : List Parent L mungkin kosong
    * FS : 1 elemen dengan id info = x.id dihapus dari list (dealokasi)
    */
    address_parent Q = L.first;
    if( P == L.first ) deleteFirst_Parent(L, P);
    while (next(Q) != NULL){
        Q= next(Q);
        if (P == L.first){
            deleteFirst_Parent(L, P);
        } else if (P == Q){
            deleteLast_Parent(L, P);
        } else {
            Q = L.first;
            while (next(Q) != NULL){
                Q = next(Q);
                deleteAfter_Parent(L, Q, P);
            }
        }
    }
}

void insertionSort_Parent(List_Parent &L)
{
    /**
    * NIM : 1301150440
    * IS : List Parent mungkin kosong
    * PR : mengurutkan elemen di dalam List Parent L menggunakan algoritma insertion sort
    * FS : elemen di dalam List Parent L terurut descending
    */

    address_parent batas, P, Q, R;
    List_Child c;
    batas = (L.first->next);
    while (batas != NULL)
    {
        P = L.first;
        while ((P->info.hargaAwal > batas->info.hargaAwal) && (P->next != batas))
        {
            Q = P;
            P = P->next;
        }
        if (batas->info.hargaAwal > P->info.hargaAwal)
        {
            R = batas;
            infotype_parent tmp = batas->info;
            info(batas) = info(P);
            info(P) = tmp;

            c = batas->child;
            batas->child = P->child;
            P->child = c;

//            address_child b, cc, zz;
//            b = c.first->next;
//
//            while (b != c.last ){
//                cc = c.first;
//                while ((cc->info.totalHarga > b->info.totalHarga) && (cc->next != b)){
//                    zz = cc;
//                    cc = cc->next;
//                }
//                if (b->info.totalHarga > cc->info.totalHarga){
//                    infotype_child tempc = b->info;
//                    b->info = zz->info;
//                    zz->info = tempc;
//                }
//            }
//            b = next(b);
        }
        batas = (batas->next);
    }
    printInfo_Parent(L);
}

address_parent sentinelSearch(List_Parent L, infotype_parent x)
{
    /**
    * NIM : 1301150440
    * IS : List mungkin kosong
    * PR : mencari elemen dengan ID = infotype x menggunakan bantuan sentinel
    * FS : mengembalikan address elemen dengan ID infotype x jika ditemukan,
    *      mengembalikan NULL jika tidak ditemukan
    */
    address_parent P, w;
    infotype_parent tp;
    tp.ID_Parent = x.ID_Parent;
    w = L.first;
    P = alokasi_Parent(tp);
    insertLast_Parent(L, P);
    while (w != P)
    {
        if(info(w).ID_Parent == info(P).ID_Parent)
        {
            deleteLast_Parent(L, P);
            return w;
        }
        else
        {
            w = w->next;
        }
    }
    deleteLast_Parent(L,P);
    dealokasi_Parent(P);
    return NULL;
}

void printInfo_Parent(List_Parent L)
{
    /**
    * NIM : 1301150440
    * FS : menampilkan info seluruh elemen List Parent L beserta elemen List Child nya
    */
    List_Child Q;
    address_parent P = L.first;
    while (P != NULL)
    {
        cout << "------------------------------------" << endl;
        cout << "ID Parent      : " << info(P).ID_Parent << endl;
        cout << "Menu Makanan   : " << info(P).menu_makanan << endl;
        cout << "Minuman        : " << P->info.minuman << endl;
        cout << "Bonus Makanan  : " << P->info.dessert << endl;
        cout << "Harga Awal     : Rp" << info(P).hargaAwal << endl;
        cout << "PPN            : 10%" << endl;
        cout << "------------------------------------" << endl;
        cout << endl;
        printInfo_Child(child(P));
        P = P->next;
    }
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
