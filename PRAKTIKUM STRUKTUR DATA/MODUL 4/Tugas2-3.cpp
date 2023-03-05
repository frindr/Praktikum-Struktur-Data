#include <iostream>
#include <conio.h>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* root;

bool isEmpty(){
	return root == NULL;
}

void insert(int d){
	node* baru = new node;
	node* parent;
	baru -> data = d;
	baru -> left = NULL;
	baru -> right = NULL;
	parent = NULL;
	if(isEmpty())
		root = baru;
	else{
		node* curr;
		curr = root;
		while(curr != NULL){
			parent = curr;
			if(baru -> data > curr -> data)
				curr = curr -> right;
			else
				curr = curr -> left;
		}
		if(baru -> data < parent -> data)
			parent -> left = baru;
		else
			parent -> right = baru;
	}
}

void preorder(node* p){
	if(p != NULL){
		cout << p -> data << " ";
		preorder(p -> left);
		preorder(p -> right);
	}
}

int size(node* p){
	if(p == NULL)
		return 0;
	return size(p -> left) + size(p -> right) + 1;
}

int height(node* p){
	if(p == NULL)
		return 0;
	int u = height(p -> left), v = height(p -> right);
	if(u > v)
		return u+1;
	else
		return v+1;
}

int cari_terbesar(node* p){
	node* curr = p;
	while(curr -> right != NULL){
		curr = curr -> right;
	}
	return(curr -> data);
}

int cari_terkecil(node* p){
	node* curr = p;
	while(curr -> left != NULL){
		curr = curr -> left;
	}
	return(curr -> data);
}
			
			
int main(){
	root = NULL;
	int pil, tmp;	
	do{
		system("cls");
		cout << endl;
		cout << "==========================================\n";
		cout << "==    Menu Utama Operasi Pohon Biner    ==" << endl;
		cout << "==========================================" << endl;
		cout << "== 1. Insert Data                       ==" << endl;
		cout << "== 2. Kunjungan Pre-Order               ==" << endl;
		cout << "== 3. Menghitung Jumlah Node            ==" << endl;
		cout << "== 4. Menghitung Tinggi Pohon           ==" << endl;
		cout << "== 5. Mencari Data Terbesar             ==" << endl;
		cout << "== 6. Mencari Data Terkecil             ==" << endl;
		cout << "== 7. Exit                              ==" << endl;
		cout << "==========================================\n";
		cout << "Masukkan Pilihan : ";
		cin >> pil;
		cout << endl;
		switch(pil){
			case 1:
				cout << "Masukan Data: ";
				cin >> tmp;
				insert(tmp);
				break;
			case 2:
				cout << endl;
				cout << "Kunjungan Pre-Order" << endl;
				cout << "------------------" << endl;
				preorder(root);
				cout << "\n\nPress Any Button to Continue...";
				getch();
				break;
			case 3:
				cout << "Menghitung Jumlah Node" << endl;
				cout << "----------------------" << endl;
				cout << "Jumlah Node = " << size(root);
				cout << "\n\nPress Any Button to Continue...";
				getch();
				break;
			case 4:
				cout << "Menghitung Tinggi Pohon" << endl;
				cout << "-----------------------" << endl;
				cout << "Tinggi Pohon = " << height(root);
				cout << "\n\nPress Any Button to Continue...";
				getch();
				break;
			case 5:
				cout << "Mecari Data Terbesar" << endl;
				cout << "--------------------" << endl;
				cout << "Data Terbesar Adalah = " << cari_terbesar(root);
				cout << "\n\nPress Any Button to Continue...";
				getch();
				break;
			case 6:
				cout << "Mecari Data Terkecil" << endl;
				cout << "--------------------" << endl;
				cout << "Data Terkecil Adalah = " << cari_terkecil(root);
				cout << "\n\nPress Any Button to Continue...";
				getch();
				break;
			case 7:
				cout << "\nProgram selesai.";
				break;
			default:
				cout << "Menu tidak tersedia." << endl;
				cout << "\n\nPress Any Button to Continue...";
				getch();
		}
	} while (pil != 7);
}