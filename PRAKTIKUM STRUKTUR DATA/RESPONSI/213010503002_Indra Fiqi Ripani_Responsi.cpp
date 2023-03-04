#include <iostream>
#include <limits>
#include <conio.h>

using namespace std;

struct node{
	string judul, pengarang, terbit;
	long harga;
	node *next;
};

node *head, *tail;

void print(){
	node *bantu;
	if(head == NULL){
	cout << "\nBelum ada data.\n";
	} else {
		bantu = head;
		while(bantu != NULL){
			cout << "\nJUDUL BUKU     : " << bantu -> judul << endl;
			cout << "NAMA PENGARANG : " << bantu -> pengarang << endl;
			cout << "TAHUN TERBIT   : " << bantu -> terbit << endl;
			cout << "HARGA BUKU     : " << "Rp" << bantu -> harga << endl;
			bantu = bantu -> next;
		}
	}
}

void printAll(){
	node *bantu;
	if(head == NULL){
	cout << "\nBelum ada data.\n";
	} else {
		bantu = head;
		while(bantu != NULL){
			cout << "\nJUDUL BUKU     : " << bantu -> judul << endl;
			cout << "NAMA PENGARANG : " << bantu -> pengarang << endl;
			cout << "TAHUN TERBIT   : " << bantu -> terbit << endl;
			cout << "HARGA BUKU     : " << "Rp" << bantu -> harga << endl;
			bantu = bantu -> next;
		}
	}
	cout << "\nPress Any Button to Continue...";
	getch();
}

int count(){
	node *cur;
	cur = head;
	int jumlah = 0;
	while(cur != NULL){
		jumlah++;
		cur = cur -> next;
	}
	return jumlah;
}

void inputDepan(){
	node *baru;
	baru = new node;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n=== PROSES MEMASUKKAN DATA ===\n\n";
	cout << "JUDUL BUKU      : "; getline(cin, baru -> judul);
	cout << "NAMA PENGARANG  : "; getline(cin, baru -> pengarang);
	cout << "TAHUN TERBIT    : "; getline(cin, baru -> terbit);
	cout << "HARGA BUKU      : "; cin >> baru -> harga;
	baru -> next = NULL;
	if(head == NULL){
		head = tail = baru;
		head -> next = NULL;
	} else {
		baru -> next = head; //pointer baru ke head sebelumnya
		head = baru;
	}
	cout << "\nData telah dimasukkan\n\n" << "== DATA TERBARU ==";
	printAll();
}

void inputBelakang(){
	node *baru;
	baru = new node;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n=== PROSES MEMASUKKAN DATA ===\n\n";
	cout << "JUDUL BUKU      : "; getline(cin, baru -> judul);
	cout << "NAMA PENGARANG  : "; getline(cin, baru -> pengarang);
	cout << "TAHUN TERBIT    : "; getline(cin, baru -> terbit);
	cout << "HARGA BUKU      : "; cin >> baru -> harga;
	baru -> next = NULL;
	if(head == NULL){
		head = baru;
	} else {
		tail -> next = baru; //ekor ke node baru
	}
	tail = baru;
	tail -> next = NULL;
	cout << "\nData telah dimasukkan\n\n" << "== DATA TERBARU ==";
	printAll();
}

void hapusDepan(){
	node *hapus;
	if (head == NULL){
		cout << "";
	} else {
		cout<< "\nData telah dihapus\n\n" << "== DATA TERBARU ==\n";
		hapus = head;
		head = head -> next;
		delete hapus;
	}
	printAll();
}

void hapusBelakang(){
	node *bantu, *hapus;
	if(head == NULL){
		cout << "";
	} else if(head == tail){
		cout << "\nData telah dihapus\n\n" << "== DATA TERBARU ==\n";
		hapus = head;
		head = head -> next;
		delete hapus;
	} else {
		cout<< "\nData telah dihapus\n\n" << "== DATA TERBARU ==\n";
		bantu = head;
		hapus = tail;
		while(bantu -> next != tail){
			bantu = bantu -> next;
		}
		tail = bantu;
		tail -> next = NULL;
		delete hapus;	
	}
	printAll();
}

void searching(){
	bool ketemu;
	char ul;
	string cari;
	node *temp;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if(head == NULL)
		printAll();
	else{
		do{
			ketemu = false;
		    temp = head;
		    system("cls");
		    cout << "Masukkan Judul Buku: "; getline(cin, cari); 
		    while(temp != NULL){
		        if(temp -> judul == cari){
		            ketemu = true;
		            cout << "\nDATA BERHASIL DITEMUKAN" << endl;
		            cout << "JUDUL BUKU     : " << temp -> judul << endl;
		            cout << "NAMA PENGARANG : " << temp -> pengarang << endl;
		            cout << "TAHUN TERBIT   : " << temp -> terbit << endl;
		            cout << "HARGA BUKU     : " << temp -> harga << endl;
		        }
		    	temp = temp -> next;
		    }
		    if(ketemu == false){
		        cout << "\nBuku dengan judul " << cari << " tidak ditemukan.\n";
		    }
		    cout << "\nTekan Y untuk mencari kembali dan Tekan T untuk kembali ke menu utama.";
		    ul = getche();
		} while(ul != 'T' && ul != 't');
	}
}

void sorting(){
	char menu;
	if(head == NULL)
		printAll();
	else{
		do{
			node *curr = head, *index = NULL;
			system("cls");
			cout << "Tampilan Data Sebelum Sorting\n";
			print();
			cout << "\nPengurutan Secara\n"
		     	 << "1. Ascending\n"
		     	 << "2. Descending\n"
		     	 << "3. Ke Menu Utama\n"
		     	 << "Pilih : ";
			menu = getche();
			if(menu == '1'){
			    while (curr != NULL){
			        index = curr -> next;
			        while(index != NULL){
			            if(curr -> harga > index -> harga){
			                string tjudul = curr -> judul;
							string tpengarang = curr -> pengarang;
							string tterbit = curr -> terbit;
			                long tharga = curr -> harga;
							curr -> judul = index -> judul;
							curr -> pengarang = index -> pengarang;
							curr -> terbit = index -> terbit; 
			                curr -> harga = index -> harga;
							index -> judul = tjudul;
							index -> pengarang = tpengarang;
							index -> terbit = tterbit;                    
			                index -> harga = tharga;
			            }
			            index = index -> next;
			        }
			        curr = curr -> next;
			    }
			    cout << endl;
			    printAll();
			} else if(menu == '2'){
			    while (curr != NULL){
			        index = curr -> next;
			        while(index != NULL){
			            if(curr -> harga < index -> harga){
			                string tjudul = curr -> judul;
							string tpengarang = curr -> pengarang;
							string tterbit = curr -> terbit;
			                long tharga = curr -> harga;
							curr -> judul = index -> judul;
							curr -> pengarang = index -> pengarang;
							curr -> terbit = index -> terbit; 
			                curr -> harga = index -> harga;
							index -> judul = tjudul;
							index -> pengarang = tpengarang;
							index -> terbit = tterbit;                    
			                index -> harga = tharga;
			            }
			            index = index -> next;
			        }
			        curr = curr -> next;
			    }
			    cout << endl;
			    printAll();
			} else if(menu == '3'){
				break;
			} 
		} while(menu != '3');
	}
}

int main(){
	int pil;
	do{
		system("cls");
		cout << "==================================\n"
			 <<	"      MENU UTAMA LINKED LIST\n"
			 << "==================================\n"
			 << "== 1. Input Data dari Depan     ==\n"
			 << "== 2. Input Data dari Belakang  ==\n"
			 << "== 3. Hapus Data dari Depan     ==\n"
			 << "== 4. Hapus Data dari Belakang  ==\n"
			 << "== 5. Searching Data Tertentu   ==\n"
			 << "== 6. Sorting Data              ==\n"
			 << "== 7. Tampilkan Semua Data      ==\n"
			 << "== 8. Keluar                    ==\n"
			 << "==================================\n\n"
			 << "Pilih Menu \t: ";
		cin >> pil;
		switch (pil){
			case 1:{
				inputDepan();
				break;
			}
			case 2:{
				inputBelakang();
				break;
			}
			case 3:{
				hapusDepan();
				break;
			}
			case 4:{
				hapusBelakang();
				break;
			}
			case 5:{
				searching();
				break;
			}
			case 6:{
				sorting();
				break;
			}
			case 7:{
				cout << "\nBanyak data di dalam Linked List adalah sebanyak " << count() << "\n";
				printAll();
				break;
			}
			case 8:{
				cout << "\nProgram Selesai";
				break;
			}
			default:{
				cout << "\nMasukan tidak valid.\n" << endl;
				cout << "\nPress Any Button to Continue...";
				getch();
			}
		}
	} while (pil != 8); 	 
}