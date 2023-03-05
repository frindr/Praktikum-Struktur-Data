#include<iostream>

using namespace std;

void findPrefix(string pola, int m, int prefArray[]){
	int len = 0;
	prefArray[0] = 0;
	for(int i = 1; i < m; i++){
		if(pola[i] == pola[len]){
			len++;
			prefArray[i] = len;
		}
		else{
			if(len != 0){
				len = prefArray[len-1];
				i--;
			}
			else
				prefArray[i] = 0;
		}
	}
}

void KMPSearch(string txt, string pola, int *locArray, int &loc){
	int i = 0, j = 0, m = pola.size(), n = txt.size(), prefArray[m];
	findPrefix(pola, m, prefArray);
	loc = 0;
	
	while(i < n){
		if(txt[i] == pola[j]){
			i++;
			j++;
		}
		if(j == m){
			locArray[loc] = i-j;
			loc++;
			j = prefArray[j-1];
		}
		else if(i < n && pola[j] != txt[i]){
			if(j != 0)
				j = prefArray[j-1];
			else
				i++;
		}
	}
}

int main(){
	string txt = "mimpimu memiliki akhir yang tidak terbatas, tarik napas yang dalam dan coba lagi", pola1 = "mimpimu", pola2 = "coba";
	int locArray[txt.size()], index;
	cout << txt << endl << endl;
	
	KMPSearch(txt, pola1, locArray, index);
	for(int i = 0; i < index; i++){
		cout << pola1 << " ditemukan pada indeks ke - " << locArray[i] << endl;
	}
	
	KMPSearch(txt, pola2, locArray, index);
	for(int i = 0; i < index; i++){
		cout << pola2 << " ditemukan pada indeks ke - " << locArray[i] << endl;
	}
}