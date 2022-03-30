#include<iostream>
#include <cstring>
using namespace std;


struct Tanc {
    char ime[15];
    char zemja[15];
};

struct Tancer {
    char ime[20];
    char prezime[20];
    Tanc niza[5];
};

void tancuvanje(Tancer *tanceri, int n, char *zemjaA) {
    for(int i=0; i<n;i++) {
        for(int j=0; j<5; j++) {
            if(!strcmp(tanceri[i].niza[j].zemja, zemjaA)) {
                cout<<tanceri[i].ime<<" "<<tanceri[i].prezime<<", "<<tanceri[i].niza[j].ime<<endl;
                break;
            }
        }
    }
}


int main()
{
    int i, j, n;
    char zemja[15];
	Tancer tanceri[5];
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> tanceri[i].ime;
        cin >> tanceri[i].prezime;
        for(j = 0; j < 3; j++){
            cin >> tanceri[i].niza[j].ime;
            cin >> tanceri[i].niza[j].zemja;
        }
    }
    cin >> zemja;
    tancuvanje(tanceri, n, zemja);
	return 0;
}