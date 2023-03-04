#include <iostream>
#include <conio.h>

using namespace std;

int jml, urut;

main(){
    cout << "Banyak data yang ingin diurutkan: ";
    cin >> jml;
    cout << endl;

    int nilai[jml];

    for(int i = 0; i < jml; i++){
        cout << "Nilai " << (i+1) << " : ";
        cin >> nilai[i];
    }
    for(int a = 1; a < jml; a++){
        for(int b = 0; b < jml - a; b++){
            if(nilai[b] > nilai[b + 1]){
                urut = nilai[b];
                nilai[b] = nilai[b + 1];
                nilai[b + 1] = urut;
            }
        }
    }
    cout << endl << "Hasil Pengurutan Adalah :";
    for(int i=0;i<jml;i++){
        cout << " " << nilai[i];
    }
    cout << endl;
    getch();
    return 0;
}