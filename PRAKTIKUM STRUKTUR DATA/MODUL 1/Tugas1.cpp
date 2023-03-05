#include<iostream>
using namespace std;

struct datamhs{
	string nama, nim, email;
};

int main(){
	int jmlh_data;
	cout<<"Banyak mahasiswa yang ingin diinput datanya: "; cin>>jmlh_data;
	cout<<endl;
	datamhs mhs[jmlh_data];
	cout<<"==============================\n";
	cout<<endl;
	cout<<"MASUKKAN DATA\n";
	cout<<endl;
	for(int a = 0; a < jmlh_data; a++){
		cout<<"Data Mahasiswa ke - "<<a+1<<endl;
		cout<<"Nama  \t:"; cin>>mhs[a].nama;
		cout<<"NIM   \t:"; cin>>mhs[a].nama;
		cout<<"Email \t:"; cin>>mhs[a].email;
		cout<<endl;
	}
	cout<<"==============================\n";
	cout<<endl;
	cout<<"MENAMPILKAN HASIL INPUT\n";
	cout<<endl;
	for(int a = 0; a < jmlh_data; a++){
		cout<<"Data Mahasiswa ke - "<<a+1<<endl;
		cout<<"Nama  \t:"<<mhs[a].nama<<endl;
		cout<<"NIM   \t:"<<mhs[a].nim<<endl;
		cout<<"Email \t:"<<mhs[a].email<<endl;
		cout<<endl;
	}
	cout<<"==============================\n"; 
}