#include <iostream>
#include <stdlib.h>

using namespace std;

class loc{
	int longitudine, latitudine;
	public:
		loc(){} //utilizat pt a construi temporare
		loc(int lg, int lt){
			longitudine = lg;
			latitudine = lt;
		}

		void arata(){
			cout << longitudine << " ";
			cout << latitudine << endl;
		}

		void *operator new(size_t dimensiune);
		void operator delete(void *p);
		void *operator new[](size_t dimensiune);
		void operator delete[](void *p);
};

void *loc::operator new(size_t dimensiune){
	cout << "Functia new proprie." << endl;
	return malloc(dimensiune);
}
void loc::operator delete(void *p){
	cout << "Functia delete proprie." << endl;
	free(p);
}

void *loc::operator new[](size_t dimensiune){
	cout << "Functia new proprie pt alocarea matricei." << endl;
	return malloc(dimensiune);
}

void loc::operator delete[](void *p){
	cout << "Elibereaza matricea cu functia delete proprie." << endl;
	free(p);
}

void main(){
	loc *p1, *p2;
	int i;
	p1 = new loc(10,20);
	if(!p1){
		cout << "Eroare la alocare" << endl;
		exit(1);
	}
	p2 = new loc[10];
	if (!p2){
		cout << "Eroare la alocare" << endl;
		exit(1);
	}
	p1->arata();
	for(i=0;i<10;i++){
		p2[i].arata();
	}
	delete p1;
	delete [] p2;
	

	system("pause");
}