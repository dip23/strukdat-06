/*
Nama		: Difa Bagasputra M
NPM			: 140810180057
Nama Program: Program Multi Linked List Exercise 4
Tahun		: 2019
*/
#include <iostream>
#include <string.h>

using namespace std;

struct Contact {
	char name[10];
	char phone[12];
	Contact* nextCon;
};

struct Indext{
	char Index[20];
	Contact* FirstCon;
	Indext* next;
};

typedef Indext* pointerIn;
typedef Contact* pointerCon;
typedef pointerIn ListIn;

void createList(ListIn& First)
{
    First = NULL;
}

void createElementIndex(pointerIn& pBaru)
{
    pBaru = new Indext;
    cout << "Index : "; cin >> pBaru->Index;
    pBaru->next= NULL;
    pBaru->FirstCon=NULL;
}

void createElementCon(pointerCon& pBaru)
{
    pBaru = new Contact;
    cout << "Nama Kontak : "; cin >> pBaru->name;
    cout << "No. Telepon : "; cin >> pBaru->phone;
    pBaru->nextCon = NULL;
}

void traversalIn(ListIn First)
{
	pointerIn pBantu;
	if(First==NULL){
		cout << "List kosong"<<endl;
	}
	else{
		pBantu=First;
		do{
			cout << pBantu->Index;
			pBantu= pBantu->next;
		}while(pBantu!=NULL);
	}
}

void linearSearch(ListIn First,char key[20],int& status, pointerIn&   pCari)
{
	status=0;
	pCari=First;
	while (status==0 && pCari!=NULL) {
		if (strcmp(pCari->Index,key)==0)
			status=1;
		else
			pCari=pCari->next;
	}
}

void insertFirstIn(ListIn& First, pointerIn pBaru)
{
	if(First==NULL)
		First=pBaru;
	else{
		pBaru->next=First;
		First=pBaru;
	}
}

void deleteFirstIn(ListIn& First, pointerIn& pHapus)
{
	if (First==NULL){
		pHapus=NULL;
		cout << "List kosong, tidak ada yang dihapus"<<endl;
	}
	else if(First->next==NULL){
		pHapus=First;
		First=NULL;
	}
	else{
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
	}
}

void insertFirstCon(ListIn& First, pointerCon pBaru){
	pointerIn pIndex;
	int ketemu;
	char key[20];
	cout<<"Masukkan Index : ";cin>>key;
	linearSearch(First,key,ketemu,pIndex);
	if (ketemu){ 
		cout<<"Ditemukan"<<endl;
		if (pIndex->FirstCon==NULL){
			pIndex->FirstCon=pBaru;
		}
		else {
			pBaru->nextCon=pIndex->FirstCon;
			pIndex->FirstCon=pBaru;
		}
	}
	else{
		cout<<"Tidak ditemukan"<<endl;
	}
}

void deleteFirstCon(ListIn& First, pointerCon& pHapus){
	pointerIn pIndex;
	int ketemu;
	char key[20];
	cout<<"Masukkan Index : ";cin>>key;
	linearSearch(First,key,ketemu,pIndex);
	if (ketemu) {
		if (pIndex->FirstCon==NULL){ // kosong
			pHapus=NULL;
			cout<<"List kosong, tidak ada hapus"<<endl;
		}else if (pIndex->FirstCon->nextCon==NULL){
			//isi 1 elemen
			pHapus=pIndex->FirstCon;
			pIndex->FirstCon=NULL;
		}else { // isi > 1 elemen
			pHapus=pIndex->FirstCon;
			pIndex->FirstCon=pIndex->FirstCon->nextCon;
			pHapus->nextCon=NULL;
		}
	}else{
		cout<<"Tidak ditemukan"<<endl;
	}
}

void traversalInCon(ListIn First){
	pointerIn pBantuIn;
	pointerCon pBantuCon;
	cout<<"Traversal Pegawai"<<endl;
	pBantuIn=First;
	int i=1;
	while (pBantuIn!=NULL){ 
		cout<<i<<"."<<pBantuIn->Index <<endl;
		pBantuCon=pBantuIn->FirstCon;
		while (pBantuCon!=NULL) { 
			cout<<"=>"<<pBantuCon->name<<"\t"<<pBantuCon->phone<<endl;
			pBantuCon=pBantuCon->nextCon;
		}
		pBantuIn=pBantuIn->next;
		cout<<endl;
		i++;
	}
}

void updateKontak(ListIn First,pointerIn& pIndex){
	char key[10];
	int status=0;

	pointerCon pK,pb;
	pIndex=First;
	pK=pIndex->FirstCon;
	cout<<"Masukan nama kontak :"; cin>>key;
	while(pIndex!=NULL){
		while(status== 0 && pK!=NULL){
			if(strcmp(pK->name,key)==0){
				cout<<"Masukan Nama :"; cin>>pK->name;
				cout<<"Masukan Nomor :"; cin>>pK->phone;
			status=1;
			}
			else {
				pK=pK->nextCon;
			}
		}

		pIndex=pIndex->next;
	}
}

int main(){
	ListIn l;
	pointerIn pb,phI;
	pointerCon pC,ph;
	int nD,nK;
	
	createList(l);
	cout<<"Banyak Index : ";cin>>nD;
	for(int i=0;i<nD;i++){
		createElementIndex(pb);
		insertFirstIn(l,pb);
	}
	cout<<"Banyak Contact : ";cin>>nK;
	for(int i=0;i<nK;i++){
		createElementCon(pC);
		insertFirstCon(l,pC);
	}

	traversalInCon(l);
	cout<<"===Delete Kontak===\n";
	deleteFirstCon(l,ph);
	traversalInCon(l);
	cout<<"===Delete Index====\n";
	deleteFirstIn(l,phI);
	cout<<"Index Berhasil dihapus..\n";
	traversalInCon(l);
	cout<<"===Update Kontak===\n";
	updateKontak(l,pb);
	traversalInCon(l);
}
