#include <iostream>
using namespace std;

void displayArr(int arr[], int size, int idx){
	if(idx==size){
		return;
	}
	cout << arr[idx] << endl;
	displayArr(arr, size, idx+1);
}
int main(){
	int n;
	cin >>n;

	int arr[1000000];

	for(int i = 0; i <n ; i++){
		cin >> arr[i];
	}

	displayArr(arr,n,0); 
}
