#include "list_child.h"
#include "list_parent.h"

void createList_Child (List_Child &L){
    /**
    * NIM : 1301154468
    * FS : first(L) dan last(L) diset NULL;
    */
    L.first = NULL;
    L.last = NULL;
}

address_child alokasi_Child (infotype_child x){
    /**
    * NIM : 1301154468
    * FS : mengembalikan elemen list parent baru dengan info = x,
           next dan prev elemen diset NULL;
    */
    address_child P = new ElmList_Child;
    info(P) = x;
    next(P) = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi_Child (address_child &P){
    /**
    * NIM : 1301154468
    * FS : menghapus elemen yang ditunjuk oleh P
    */
    delete P;
}

void insertFirst_Child (List_Child &L, address_child P){
    /**
    * NIM :1301154468
    * IS : List Child L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List Child L
    */
    if(L.first == NULL) {
        L.last = P;
        L.first = P;
    } else {
        next(P) = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfter_Child (List_Child &L, address_child &Q, address_child &P){
    /**
    * NIM : 1301154468
    * IS : List Parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen yang ditambahkan diantara elemen Q pada List Child L
    */
    next(P) = next(Q);
    P->prev = Q;
    if (next(Q)!= NULL){
        prev(next(Q)) = P;
    }
    next(Q) = P;
    //cout << "insert after c";
}

void insertLast_Child  (List_Child &L, address_child P){
    /**
    * NIM : 1301154468
    * IS : List Parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List Child L
    */
    if (L.first==NULL){
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        next(L.last) = P;
        L.last = P;
    }
}

void deleteFirst_Child (List_Child &L, address_child P){
    /**
    * NIM : 1301150440
    * IS : List Child L mungkin kosong
    * FS : elemen pertama di dalam List Child L dilepas dan disimpan/ditunjuk oleh P
    */
    if (L.first != NULL){
        P = L.first;
        if (next(P) == NULL){
            L.first = NULL;
        } else {
            L.first = next(P);
            prev(next(P)) == NULL;
            next(P) = NULL;
        }
        dealokasi_Child(P);
    }
}

void deleteAfter_Child (List_Child &L, address_child &P, address_child &Q){
    /**
    * NIM : 1301150440
    * IS : List Child L tidak kosong
    * FS : P adalah alamat dari next(Q), menghapus next(Q) dari List Child L
    */
    if (L.first != NULL) {
        if (next(L.first)==L.first) {
            P = L.first;
            L.first = NULL;
        } else {
            P = next(Q);
            if (next(Q) == L.first) {
                L.first = next(L.first);
            }
            next(Q) = next(P);
        }
        dealokasi_Child(P);
    }
}

void deleteLast_Child (List_Child &L, address_child &P){
    /**
    * NIM : 1301150440
    * IS : List Child L mungkin kosong
    * FS : elemen terakhir didalam List Child L dilepas dan disimpan/ditunjuk oleh P
    */
    if(next(L.first) == NULL)
    {
        deleteFirst_Child(L,P);
    }
    else
    {
        address_child tmp = L.first;
        while(next(next(tmp)) != NULL)
        {
            tmp = next(tmp);
        }
        P = next(tmp);
        next(tmp) = NULL;

    }
    dealokasi_Child(P);
}

void deletebyID_Child (List_Child &L, address_child &P)
{
    /**
    * NIM : 1301150440
    * IS : List L mungkin kosong
    * FS : 1 elemen dengan id info = x.id dihapus dari list (dealokasi)
    */
    address_child Q = L.first;
    if (P == L.first) deleteFirst_Child(L, P);
    while (next(Q) != NULL){
        Q= next(Q);
        if (P == L.first){
            deleteFirst_Child(L, P);
        } else if (P == Q){
            deleteLast_Child(L, P);
        } else {
            Q = L.first;
            while (next(Q) != NULL){
                Q = next(Q);
                deleteAfter_Child(L, P, Q);
            }
        }
    }
}

void ASC_Child(List_Child &L, address_child &P){
    /**
    * NIM : 1301154468
    * IS : Data tidak terurut secara Ascending
    * FS : Mengurutkan List Parent berdasarkan ID secara Ascending
    */
    if (L.first == NULL){
        insertFirst_Child(L,P);
    } else {
        address_child Q = L.first;
        bool finded = false;
        if (Q->info.ID_Child > P->info.ID_Child){
            insertFirst_Child(L,P);
        } else {
            while (next(Q) != NULL && !finded){
                Q = next(Q);
                if (info(P).ID_Child < info(Q).ID_Child){
                    insertAfter_Child(L,P, prev(Q));
                    finded = true;
                } else if (info(P).ID_Child == info(Q).ID_Child){
                    cout << "dah ada" << endl;
                    finded = true;
                }
            }
            if (!finded && next(Q) == NULL){
                insertLast_Child(L,P);
            }
        }
    }
}

address_child findElm_Child(List_Child L, infotype_child x){
    /**
    * NIM : 1301154468
    * IS : List Child L mungkin kosong
    * FS : mengembalikan elemen parent dengan info = x,
           mengembalikan NULL jika tidak ditemukan
    */
    address_child P = L.first;
    while (P != NULL){
        if (info(P).ID_Child == x.ID_Child){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

address_child sentinelSearch(List_Child L, infotype_child y){
    /**
    * NIM : 1301154468
    * IS : List mungkin kosong
    * PR : mencari elemen dengan ID = infotype x menggunakan bantuan sentinel
    * FS : mengembalikan address elemen dengan ID infotype x jika ditemukan,
    *      mengembalikan NULL jika tidak ditemukan
    */
    address_child P, w;
    infotype_child tp;
    tp.ID_Child = y.ID_Child;
    w = L.first;
    P = alokasi_Child(tp);
    insertLast_Child(L, P);
    while (w != P) {
        if(info(w).ID_Child == info(P).ID_Child) {
            deleteLast_Child(L, P);
            return w;
        } else {
            w = w->next;
        }
    }
    deleteLast_Child(L,P);
    dealokasi_Child(P);
    return NULL;
}

void printInfo_Child (List_Child L){
    /**
    * NIM : 1301154468
    * FS : menampilkan info seluruh elemen List Child L
    */
    address_child C = L.first;
    while (C != NULL) {
        cout << "              ------------------------------------" << endl;
        cout << "              ID Child   : " << info(C).ID_Child << endl;
        cout << "              Makanan    : " << info(C).mknan << endl;
        cout << "              Porsi      : " << info(C).porsi << endl;
        cout << "              Diskon     : 0%" << endl;
        cout << "              Harga      : " << info(C).harga << endl;
        info(C).totalHarga = info(C).harga + (info(C).harga*10/100);
        cout << "              Total Harga: " << info(C).totalHarga<< endl;
        cout << "              ------------------------------------" << endl;
        cout << endl;
        C = C->next;
    }
}
