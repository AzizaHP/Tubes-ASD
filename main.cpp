#include <iostream>
#include <stdlib.h>
#include "list_parent.h"
#include "list_child.h"

using namespace std;

int main()
{
    infotype_parent x;
    infotype_child y;
    address_child C1 = NULL;
    address_child C2 = NULL;
    address_parent P1 = NULL;
    address_parent P2 = NULL;

    int menus = 0;

    List_Parent LP1, LP2;
    List_Child LC1, LC2;

    createList_Parent(LP1);
    createList_Child(LC1);
    createList_Parent(LP2);
    createList_Child(LC2);

    menu mn1, mn2, mn3;
    makanan m1, m2, m3;

    /*Insert Parent*/
    mn1.ID_Parent = 1;
    mn1.menu_makanan = "Mie Ayam";
    mn1.minuman = "Teh Botol Sosro";
    mn1.dessert = "Es Buah";
    mn1.hargaAwal = 15000;
    mn1.ppn = 10;
    P1 = alokasi_Parent(mn1);
    ASC_Parent(LP1, P1);
    //insertLast_Parent (LP1,P1);

    mn2.ID_Parent = 2;
    mn2.menu_makanan = "Nasi Goreng";
    mn2.minuman = "Teh Botol Sosro";
    mn2.dessert = "Pudding";
    mn2.hargaAwal = 13000;
    mn2.ppn = 10;
    P1 = alokasi_Parent(mn2);
    ASC_Parent(LP1, P1);
    //insertFirst_Parent (LP1,P1);

    mn3.ID_Parent = 3;
    mn3.menu_makanan = "Soto";
    mn3.minuman = "Es Jeruk";
    mn3.dessert = "Es Krim";
    mn3.hargaAwal = 16000;
    mn3.ppn = 10;
    P1 = alokasi_Parent(mn3);
    P2 = findElm_Parent(LP1, mn2);
    ASC_Parent(LP1, P1);
    //insertAfter_Parent (LP1, P1, P2);

    /*Insert Child*/

    m1.ID_Child = 1;
    m1.mknan = "Mie Ayam Bakso";
    m1.porsi = 'R';
    m1.harga = 18000;
    P1 = findElm_Parent(LP1, mn1);
    m1.totalHarga = (m1.harga*mn1.ppn/100)+m1.harga;
    C1 = alokasi_Child(m1);
    ASC_Child(P1->child, C1);
    //insertFirst_Child(child(P1),C1);

    m2.ID_Child = 1;
    m2.mknan = "Nasi Goreng Kambing";
    m2.porsi = 'L';
    m2.harga = 25000;
    m2.totalHarga = m2.harga + (m2.harga*mn2.ppn/100);
    P1 = findElm_Parent(LP1, mn2);
    C1 = alokasi_Child(m2);
    //insertLast_Child(child(P1), C1);
    ASC_Child(P1->child, C1);

    m2.ID_Child = 2;
    m2.mknan = "Nasi Goreng Spesial";
    m2.porsi = 'L';
    m2.harga = 40000;
    m2.totalHarga = m2.harga + (m2.harga*mn2.ppn/100);
    P1 = findElm_Parent(LP1, mn2);
    C1 = alokasi_Child(m2);
    //insertFirst_Child(child(P1), C1);
    ASC_Child(P1->child, C1);

    m2.ID_Child = 0;
    m2.mknan = "Nasi Goreng Seafood";
    m2.porsi = 'R';
    m2.harga = 35000;
    m2.totalHarga = m2.harga + (m2.harga*mn2.ppn/100);
    P1 = findElm_Parent(LP1, mn2);
    C1 = findElm_Child(child(P1), m2);
    address_child R = alokasi_Child(m2);
    //insertAfter(C1, R);
    ASC_Child(P1->child, R);

    do {
        //system("cls");
        cout << "===================================" << endl;
        cout << "|            TUBES ASD            |" << endl;
        cout << "|                                 |" << endl;
        cout << "|    1. Insert Data               |" << endl;
        cout << "|    2. Search and Delete         |" << endl;
        cout << "|    3. Search and View           |" << endl;
        cout << "|    4. View All                  |" << endl;
        cout << "|    5. Sorting                   |" << endl;
        cout << "|    6. Reporting                 |" << endl;
        cout << "===================================" << endl;
        cout << endl;
        cout << "Pilihan: "; cin >> menus;
//        gotoxy(23,1); cout << "===================================" << endl;
//        gotoxy(23,2); cout << "|            TUBES ASD            |" << endl;
//        gotoxy(23,3); cout << "|                                 |" << endl;
//        gotoxy(23,4); cout << "|    1. Insert Parent             |" << endl;
//        gotoxy(23,5); cout << "|    2. Insert Child              |" << endl;
//        gotoxy(23,6); cout << "|    3. Delete Parent             |" << endl;
//        gotoxy(23,7); cout << "|    4. Delete Child              |" << endl;
//        gotoxy(23,8); cout << "|    5. Search Parent             |" << endl;
//        gotoxy(23,9); cout << "|    6. Search Child              |" << endl;
//        gotoxy(23,10); cout << "|    7. View All                  |" << endl;
//        gotoxy(23,11); cout << "|    8. Sorting                   |" << endl;
//        gotoxy(23,12); cout << "|    9. Reporting                 |" << endl;
//        gotoxy(23,13); cout << "===================================" << endl;
//        gotoxy(23,14); cout << "Pilihan: "; cin >> menus;
        switch (menus) {
            case 1:
            {
                system("cls");
                cout << "     INSERT DATA " << endl;
                cout << "1. Insert Parent" << endl;
                cout << "2. Insert Child" << endl;
                int insertc = 0;
                cin >> insertc;
                if (insertc == 1){
                    system("cls");
                    cout << "ID Menu: ";
                    cin >> x.ID_Parent;
                    if (findElm_Parent(LP1, x)){
                        cout << "ID Parent sudah ada" << endl;
                    } else {
                        cout << "Menu Makanan   : ";
                        cin >> x.menu_makanan;
                        cout << "Minuman        : ";
                        cin >> x.minuman;
                        cout << "Dessert        : ";
                        cin >> x.dessert;
                        cout << "Harga          : ";
                        cin >> x.hargaAwal;
                        cout << "PPN            : ";
                        cin >> x.ppn;
                        P1 = alokasi_Parent(x);
                        //insertFirst_Parent(LP1, P1);
                        ASC_Parent(LP1, P1);
                    }
                } else if (insertc == 2){
                    system("cls");
                    cout << "Inputkan ID Child ke ID Parent: ";
                    cin >> x.ID_Parent;
                    address_parent tmp = findElm_Parent(LP1, x);
                    if (findElm_Parent(LP1, x)){
                        cout << "ID Makanan: ";
                        cin >> y.ID_Child;
                        //cout<<"Find Element anak"<<findElm_Child(LC1, y);
                        if (findElm_Child(LC1, y)==NULL){
                            cout << "Makanan: ";
                            cin >> y.mknan;
                            cout << "Porsi: ";
                            cin >> y.porsi;
                            cout << "Harga: ";
                            cin >> y.harga;
                            C1 = alokasi_Child(y);
                            //insertFirst_Child (tmp->child, C1);
                            ASC_Child(tmp->child,C1);
                        }
                    }
                }
                break;
            }
            case 2:
            {
                system ("cls");
                cout << "       Search and Delete   " << endl;
                cout << "1. Parent" << endl;
                cout << "2. Child" << endl;
                int a = 0;
                cin >> a;
                if (a == 1){
                    system ("cls");
                    cout << "Cari ID Parent yang ingin dihapus: ";
                    cin >> x.ID_Parent;
                    address_parent p = findElm_Parent(LP1, x);
                    if (p != NULL){
                        string hps;
                        cout << "ID Parent ditemukan. Apakah ingin dihapus? (Y/N)" << endl;
                        cin >> hps;
                        if (hps == "Y" || hps == "y"){
                            deletebyID_Parent(LP1, p);
                        } else if (hps == "N" || hps == "n"){
                            cout << "ID Parent tidak dihapus" << endl;
                        }
                    } else {
                        cout << "ID Parent tidak ditemukan" << endl;
                    }
                } else if (a == 2){
                    system ("cls");
                    cout << "Hapus ID Child pada ID Parent: ";
                    cin >> x.ID_Parent;
                    address_parent p = findElm_Parent(LP1, x);
                    if (p != NULL){
                        cout << "Cari ID Child yang akan dihapus: ";
                        cin >> y.ID_Child;
                        address_child cl = findElm_Child(p->child, y);
                        if (cl != NULL){
                            string hapus;
                            cout << "ID Child ditemukan. Apakah ingin dihapus? (Y/N) ";
                            cin >> hapus;
                            if (hapus == "Y" || hapus == "y"){
                                deletebyID_Child(p->child, cl);
                            } else if (hapus == "N" || hapus == "n"){
                                cout << "Data tidak dihapus" << endl;
                            }
                        } else {
                            cout << "Data tidak ditemukan" << endl;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                system("cls");
                cout << "       Search and View" << endl;
                cout << "1. Parent" << endl;
                cout << "2. Child" << endl;
                int d = 0;
                cin >> d;
                if (d == 1){
                    system("cls");
                    cout << "ID Parent yang dicari: ";
                    cin >> x.ID_Parent;
                    P1 = findElm_Parent(LP1,x);
                    if (P1 != NULL){
                        system("cls");
                        cout << "-------------------------" << endl;
                        cout << "ID Parent      : " << info(P1).ID_Parent << endl;
                        cout << "Menu Makanan   : " << info(P1).menu_makanan << endl;
                        cout << "Minuman        : " << info(P1).minuman << endl;
                        cout << "Bonus          : " << info(P1).dessert << endl;
                        cout << "Harga Awal     : " << info(P1).hargaAwal << endl;
                        cout << "PPN            : " << info(P1).ppn << "%" << endl;
                        cout << "-------------------------" << endl;
                    } else {
                        cout << "ID Parent tidak ditemukan" << endl;
                    }
                } else if (d == 2){
                    cout << "Cari Id Child pada ID Parent: ";
                    cin >> x.ID_Parent;
                    P1 = findElm_Parent(LP1, x);
                    if (P1 != NULL){
                        cout << "ID Child yang dicari: ";
                        cin >> y.ID_Child;
                        C1 = sentinelSearch(child(P1), y);
                        if (C1 != NULL){
                            system("cls");
                            cout << "-------------------------" << endl;
                            cout << "ID Child       : " << C1->info.ID_Child << endl;
                            cout << "Makanan        : " << C1->info.mknan << endl;
                            cout << "Porsi          : " << C1->info.porsi << endl;
                            cout << "Harga          : " << C1->info.harga << endl;
                            cout << "Total (+PPN)   : " << C1->info.totalHarga<< endl;
                            cout << "-------------------------" << endl;
                        } else {
                            cout << "Data tidak ditemukan" << endl;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                printInfo_Parent(LP1);
                //printInfo_Child(LC1);
                break;
            }
            case 5:
            {
                insertionSort_Parent(LP1);
                break;
            }
            case 6:
            {
                //address_child cc = L.
                printInfo_Parent(LP1);
                C1 = LC1.first;
                while (C1 != NULL) {
                    cout << "              ------------------------------------" << endl;
                    cout << "              Makanan    : " << info(C1).mknan << endl;
                    cout << "              Porsi      : " << info(C1).porsi << endl;
                    cout << "              Total Harga: " << info(C1).totalHarga<< endl;
                    cout << "              ------------------------------------" << endl;
                    cout << endl;
                    C1 = C1->next;
                }
                break;
            }
            default:
                cout << "Pilihan menu hanya 9" << endl;
            }
        } while (menus != 9);
    return 0;
}
