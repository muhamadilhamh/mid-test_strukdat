/*
Nama    = Muhamad Ilham Habib
NPM     = 140801810018
Kelas   = B
Tahun   = 2019
Deskripsi = tentang pesanan pke single link list
*/
#include<iostream>
#include<string.h>

using namespace std;

struct ElemtList{
    int no;
    string makanan;
    string harga;
    int jumlah;
    ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
    First=NULL;
}
void createElement(pointer& pBaru){
    pBaru=new ElemtList;
    cout << "No : "; cin >> pBaru->no;cin.ignore(255,'\n');
    cout << "Nama Makanan : "; getline(cin,pBaru->makanan);
    cout << "Harga : "; cin >> pBaru->harga;
    pBaru->next=NULL;
}

void insertLast(List& First, pointer pBaru){
    pointer last;
    if (First==NULL){
        First=pBaru;
 }
    else {
        last=First;
    while(last->next!=NULL){
        last=last->next;
  }
    last->next=pBaru;
    }
}

void update(List &First){
    pointer pBantu;
    pBantu=First;
 while(pBantu!=NULL){
    cout << "Jumlah Pesanan "<< pBantu->makanan<<endl;
    cout << "Jumlah : "; cin >> pBantu->jumlah;
    pBantu=pBantu->next;
    }
}
void tukar(pointer& a,pointer& b){
    int tempjumlah = a->jumlah;
    a->jumlah = b->jumlah;
    b->jumlah = tempjumlah;
    int tempno = a->no;
    a->no = b->no;
    b->no = tempno;
    string tempmakanan = a->makanan;
    a->makanan = b->makanan;
    b->makanan = tempmakanan;
    string tempharga = a->harga;
    a->harga = b->harga;
    b->harga = tempharga;
}

void sorting(List& First){
    int swapped, i;
    pointer ptr1;
    pointer lptr = NULL;

    if (First == NULL)
        return;

    do{
        swapped = 0;
        ptr1 = First;

        while(ptr1->next!=lptr){
            if (ptr1->jumlah>ptr1->next->jumlah){
                swap(ptr1,ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}

void traversal(List &First){
    pointer pBantu;
    pBantu=First;
 while(pBantu != NULL){
         cout <<pBantu->no<<"||"<<pBantu->makanan<<"||"<<pBantu->harga<<"||"<<pBantu->jumlah<<endl;
   pBantu=pBantu->next;
    }
}


int main (){
    List l;
    pointer p;
    int n;
    char nama;
    createList(l);
    cout<<"Jumlah makanan = "; cin>>n;
        for (int i=0;i<n;i++){
        createElement(p);
        insertLast(l,p);
 }
    update(l);
    sorting(l);
    traversal(l);
}
