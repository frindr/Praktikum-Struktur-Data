#include <iostream> 
#include <conio.h> 
#include <limits> 
#define MAX 50
  
using namespace std;
 
int top = -1; 
int ukuran = 0; 

struct datamhs{
	string nama, nim, email;
};

datamhs mhs[MAX];

int isEmpty(){
	return (top == -1) ? 1 : 0;
}

int isFull(){
	return (top == MAX - 1) ? 1 : 0;
}

void input(){
	if (!isFull()){
		ukuran++;
		top++;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		cout << "\n ========== Input Data Mahasiswa ========== \n";
		cout << "\n Masukkan Nama Mahasiswa  \t: ";
		getline(cin, mhs[top].nama);
		cout << "\n Masukkan NIM Mahasiswa   \t: ";
		getline(cin, mhs[top].nim);
		cout << "\n Masukkan Email Mahasiswa \t: ";
		getline(cin, mhs[top].email);
		
	}else{
		cout << " Data Sudah Penuh!";
	}
}

void pop(){
	if (isEmpty()){
		cout << "\n Data masih kosong" << endl;
	}else{
		cout << "\n Data Yang Dikeluarkan:" << endl;
		cout << " Nama  : " << mhs[top].nama << endl;
		cout << " NIM   : " << mhs[top].nim << endl;
		cout << " Email : " << mhs[top].email << endl;
		ukuran--;
		top--;
	}
}

void dequeue(){
	if (isEmpty()){
		cout << "\n Data masih kosong\n";
	}else{
		cout << "\n Data Yang Dikeluarkan:" << endl;
		cout << " Nama  : " << mhs[0].nama << endl;
		cout << " NIM   : " << mhs[0].nim << endl;
		cout << " Email : " << mhs[0].email << endl;		
		for (int i = 0; i < ukuran; i++){
			mhs[i].nama = mhs[i + 1].nama;
			mhs[i].nim = mhs[i + 1].nim;
			mhs[i].email = mhs[i + 1].email;
		}
		ukuran--;
		top--;
	}
}


void tampil(){
	if (!isEmpty()){
		cout << "\n Isi Antrian " << endl;
		for (int i = top; i >= 0; i--){
			cout << "\n Data ke - " << i + 1 << endl;
			cout << " Nama  : " << mhs[i].nama << endl;
			cout << " NIM   : " << mhs[i].nim << endl;
			cout << " Email : " << mhs[i].email << endl;
		}
	}
	else{
		cout << "\n Data masih kosong\n";
	}
}

void clear(){
	top = -1;
}

int main(){
	int a;
	do{
		system("cls");
		cout << " ==================================================" << endl;
		cout << " =====               Menu Utama               =====" << endl;
		cout << " ==================================================" << endl;
		cout << " == 1. PUSH (Input Data)                         ==" << endl;
		cout << " == 2. POP (Ambil Satu Data Terakhir)            ==" << endl;
		cout << " == 3. DEQUEUE (Ambil Satu Data Pertama)         ==" << endl;
		cout << " == 4. CLEAR (Hapus Semua Data)                  ==" << endl;
		cout << " == 5. PRINT (Cetak Data Pada Layar)             ==" << endl;
		cout << " == 6. TERMINATE (Keluar)                        ==" << endl;
		cout << " ==================================================\n" << endl;
		cout << " Pilih Menu: "; cin >> a;
		switch (a){
			case 1:{
				input();
				break;
			}
			case 2:{
				pop();
				cout << "\n Press Any Button to Continue...";
				getch();
				break;
			}
			case 3:{
				dequeue();
				cout << "\n Press Any Button to Continue...";
				getch();
				break;
			}
			case 4:{
				clear();
				break;
			}
			case 5:{
				tampil();
				cout << "\n Press Any Button to Continue...";
				getch();
				break;
			}
			case 6:{
				cout << "";
				break;
			}
			default:{
				cout << "\n Masukan tidak valid." << endl;
				cout << "\n Press Any Button to Continue...";
				getch();
			}
		}
	}while (a != 6); 
	return 0;
}