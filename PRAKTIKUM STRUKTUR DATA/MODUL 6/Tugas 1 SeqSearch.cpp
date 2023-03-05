#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    bool ketemu;
    char ul;
    int i, n;
    string A[10], B[10], C[10], cari;
    
	cout << "\n\nBanyak Data yang Ingin Diinputkan: ";
	cin >> n;
	for(i = 0; i < n; i++){
	    cout << "\n\nData ke - " << i+1;
		cout << "\nJam Pembelian   : ";
	    cin >> A[i];
	    cout << "Menit Pembelian : ";
	    cin >> B[i];
	    cout << "Waktu Pembelian : ";
	    cout << A[i] << "." << B[i] << " WIB";
	    cout << "\nID PELANGGAN    : ";
	    C[i] = A[i] + B[i];
	    cout << C[i] << endl;
	}
	
	do{
		system("cls");
		ketemu = false;
	    cout << endl;
	    cout << "Input ID Pelanggan yang cari : ";
		cin >> cari;
	    cout << endl;
	
	    for(i = 0; i < 10; i++){
	        if (C[i] == cari){
	            ketemu = true;
		      	break;
	        }
	    }
	    if(ketemu)
	        cout << "Data ditemukan pada indeks ke - " << i << ".";
	    else
	    	cout << "Data tidak ditemukan.";
	    cout << "\n\nTekan N untuk mengakhiri program dan tekan Y untuk kembali mencari.";
	    ul = getche();
	} while(ul != 'N' && ul != 'n');
}