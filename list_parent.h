#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#define info(P) P->info
#define next(P) P->next
#define child(P) P->child

#include <iostream>
#include <windows.h>
#include "list_child.h"

using namespace std;

struct menu {
    int ID_Parent;
    string menu_makanan;
    int hargaAwal;
    string minuman;
    string dessert;
    int ppn;
};

typedef menu infotype_parent;
typedef struct ElmList_Parent *address_parent;

struct ElmList_Parent {
    infotype_parent info;
    address_parent next;
    List_Child child;
};

struct List_Parent {
    address_parent first;
};

void createList_Parent (List_Parent &L);
address_parent alokasi_Parent(infotype_parent x);
void dealokasi_Parent (address_parent &P);

void insertFirst_Parent  (List_Parent &L, address_parent P);
void insertAfter_Parent  (List_Parent &L, address_parent P, address_parent Q);
void insertLast_Parent  (List_Parent &L, address_parent P);
void ASC_Parent(List_Parent &L, address_parent &P);

void deleteFirst_Parent (List_Parent &L, address_parent &P);
void deleteAfter_Parent (List_Parent &L, address_parent &Prec, address_parent &P);
void deleteLast_Parent  (List_Parent &L, address_parent P);
void deletebyID_Parent (List_Parent &L, address_parent &P);

void insertionSort_Parent (List_Parent &L);
//void SortingParent(List_Parent &L);
address_parent sentinelSearch(List_Parent L, infotype_parent x);
void gotoxy(int x, int y);

address_parent findElm_Parent(List_Parent L, infotype_parent P);
void printInfo_Parent (List_Parent L);
#endif // LIST_PARENT_H_INCLUDED
