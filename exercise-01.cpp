//	nama	: naufal ariful amri
//	npm	: 140810180009
//	kelas	: A
//	tanggal	: 19 maret 2019

#include <iostream>
using namespace std ;

struct data{
	string nama ;
	string posisi ;
	long int gaji ;
	data* next ;
};
typedef data* pointer ;
typedef data* list ;

void pembukaan () {
	cout << "1. INPUT AWAL \n2. INPUT AKHIR\n3. DELETE AWAL\n4. DELETE AKHIR\n() SHOW\n" ;
}

void create (list& first) {
	first = NULL ;
}
void elem (list& first , pointer& p){
	p = new data ;
	cout << "Nama	: " ; cin >> p->nama ;
	cout << "Posisi	: " ; cin >> p->posisi ;
	cout << "Gaji	: " ; cin >> p->gaji ;
	p->next = NULL ;
}
void insert_first (list& first, pointer pBaru){
	if (first == NULL) {
		first = pBaru ;
	}
	else {
		pBaru->next = first ;
		first = pBaru ;
	}
}

void insert_last (list& first , pointer pBaru ) {
	pointer last ;
	last = first ;
	
	if (first == NULL) {
		first = pBaru ;
	}
	else {
		while (last != NULL){
			last = last->next ;
		}
		last->next = pBaru ;
	}
}

void traversal(list first ) {
	pointer cek ;
	cek = first ;
	cout << "NAMA" << "	POSISI" << "	GAJI\n" ;
	while (cek != NULL) {
		cout << cek->nama << " " << cek->posisi << " " << cek->gaji << endl ;
		cek = cek->next ;
	}
}

void delete_first (list& first ,pointer& pHapus) {
	if (first == NULL) {
		cout << "KOSONG\n" ;
	}
	else {
		pHapus = first ;
		first = first->next ;
		pHapus->next = NULL ;
	}
}

void delete_last (list& first , pointer& pHapus){
	pointer last ;
	pointer prelast ;
	if (first == NULL ){
		pHapus =first ;
		first = NULL ;
	}
	else {
		last = first ;
		prelast = NULL ;
		while (last != NULL) {
			prelast = last ;
			last = last->next ;
		}
		pHapus = last ;
		prelast->next = NULL ;
	}
	
}



int main () {
	pointer p ;
	list f ;
	int a = 1 ;
	
	create(f) ;
	pembukaan() ;
	
	while (a != 0) {
		cout << "input " ;
		cin >> a ;
		if (a == 1){
			elem (f,p) ;
			insert_first(f,p) ;
			pembukaan() ;
		}
		else if (a == 2) {
			elem(f,p) ;
			insert_last(f,p) ;
			pembukaan() ;
		}
		else if (a == 3 ) {
			delete_first(f,p) ;
			traversal(f) ;
			pembukaan () ;
		}
		else if (a == 4) {
			delete_last(f,p) ;
			traversal(f) ;
			pembukaan () ;
		}
		else {
			traversal(f) ;
		}
	}
		cout << "THANK YOU " << endl ;
	
}
