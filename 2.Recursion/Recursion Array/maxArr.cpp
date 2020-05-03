#include <iostream>
using namespace std;

int maxArr(int arr[] , int size,int idx){

	if(idx == size-1){
		return arr[idx];
	}

	int max = maxArr(arr,size, idx+1);
	if(max > arr[idx]){
		return max;
	}
	else{
		return arr[idx];
	}
}

int main(){

	int size;
	cin >> size;

	int arr[100000];

	for(int i = 0; i < size; i++){
		cin >> arr[i];
	}

	int x = maxArr(arr,size,0);
	cout << x;
}