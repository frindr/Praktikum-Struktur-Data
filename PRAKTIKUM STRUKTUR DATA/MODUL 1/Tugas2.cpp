#include <iostream>
#define max 50

using namespace std;

int fibo(int n, int a){
	int arr[max];
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < n; i++){
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[a];
}

int main(){
	int a, num, ptr;
	a = 0;
	cout << "Banyak deret fibonacci: ";
	cin >> num;
	for (int i = 0; i < num; i++){
		ptr = fibo(num, a);
		cout<<ptr<<" ";
		a++;
	}
}

int fibo(int n, int a){
	int arr[max];
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < n; i++){
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[a];
}
