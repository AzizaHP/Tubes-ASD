#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
//#include "list_parent.h"
#include <string>
#include <iostream>

using namespace std;


struct makanan {
    int ID_Child;
    string mknan;
    char porsi;
    int harga;
    int totalHarga;
    int diskon;
};

typedef makanan infotype_child;
typedef struct ElmList_Child *address_child;

struct ElmList_Child {
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_Child {
    address_child first;
    address_child last;
};

void createList_Child (List_Child &L);
address_child alokasi_Child (infotype_child x);
void dealokasi_Child (address_child &P);

void insertFirst_Child (List_Child &L, address_child P);
void insertAfter_Child (List_Child &L, address_child &P, address_child &Q);
void insertLast_Child  (List_Child &L, address_child P);
void ASC_Child(List_Child &L, address_child &P);

void deleteFirst_Child (List_Child &L, address_child P);
void deleteAfter_Child (List_Child &L, address_child &P, address_child &Q);
void deleteLast_Child  (List_Child &L, address_child &P);
void deletebyID_Child (List_Child &L, address_child &P);

void insertionSort_Child(List_Child &L);
address_child sentinelSearch(List_Child L, infotype_child y);
address_child findElm_Child (List_Child L, infotype_child x);
void printInfo_Child (List_Child L);

#endif // LIST_CHILD_H_INCLUDED
