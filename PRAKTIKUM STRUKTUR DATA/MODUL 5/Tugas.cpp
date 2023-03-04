#include<iostream>
#include<conio.h>

using namespace std;

void buble(int arr[]){
	int i, j, tmp;
  	for (i = 0; i < 11; i++){
    	for (j = 0; j < 11 - i - 1; j++){
      		if (arr[j] > arr[j + 1]){
        		tmp = arr[j];
        		arr[j] = arr[j + 1];
        		arr[j + 1] = tmp;
      		}
		}
  	}
  	
  	cout << "Data setelah diurutkan:\n";
  	for (i = 0; i < 11; i++)
  		cout << arr[i] << "  ";
}

void selection(int arr[]){
	int i, j, temp, tukar;
	for (i = 0; i < 11; i++){
    	tukar = i;
        for(j = i + 1; j < 11; j++){
            if(arr[j] < arr[tukar]){
                tukar = j;
            }
        }   
        temp = arr[tukar];
        arr[tukar] = arr[i];
        arr[i] = temp;
    }
    
    cout << "Data setelah diurutkan:\n";
  	for (i = 0; i < 11; i++)
  		cout << arr[i] << "  ";
}

void insertion(int arr[]){
	int i, j, temp;
	for(i = 1; i < 11; i++){
		temp = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > temp){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
    
    cout << "Data setelah diurutkan:\n";
  	for (i = 0; i < 11; i++)
  		cout << arr[i] << "  ";
}

void shell(int arr[]){
	int i, j, temp, y;
	for(i = 11/2; i > 0 ; i = i/2){
       for(int j = i; j < 11; j++){
          for (y = j - i; y >= 0; y -= i){
             if(arr[y+i] < arr[y]){
            	temp = arr[y+i];
            	arr[y+i] = arr[y];
               	arr[y] = temp;
            }
         }
      }
   }
   
	cout << "Data setelah diurutkan:\n";
	for (i = 0; i < 11; i++)
  		cout << arr[i] << "  ";
}

int main(){
	int i, pil;
	do{
		system("cls");
		int data[] = {15, 8, 0, -2, 19, 42, 31, 81, -72, 1, 2};
		cout << "==========================================\n";
		cout << "==      Menu Utama Operasi Sorting      ==" << endl;
		cout << "==========================================" << endl;
		cout << "== 1. Buble Sorting                     ==" << endl;
		cout << "== 2. Selection Sorting                 ==" << endl;
		cout << "== 3. Insertion Sorting                 ==" << endl;
		cout << "== 4. Shell Sort                        ==" << endl;
		cout << "== 5. Exit                              ==" << endl;
		cout << "==========================================\n";
		cout << "Masukkan Pilihan : ";
		cin >> pil;
		
		cout << "\nData sebelum diurutkan:\n";
	  	for (i = 0; i < 11; i++)
	  		cout << data[i] << "  ";
	  	cout << "\n\n";
	  		
	  	switch(pil){
	  		case 1:
	  			buble(data);
	  			getch();
	  			break;
	  		case 2:
	  			selection(data);
	  			getch();
	  			break;
	  		case 3:
	  			insertion(data);
	  			getch();
	  			break;
	  		case 4:
	  			shell(data);
	  			getch();
	  			break;
	  		case 5:
	  			cout << "Program selesai.";
	  			break;
	  		default:
	  			cout << "Menu yang dipilih tidak tersedia.";
	  			getch();
		}
	} while(pil != 5);
}