#include <iostream>
using namespace std;


void displayReverse(int arr[], int size, int idx){

	//base case
	if(idx==size){
		return;
	}
	//(print from last hence idx+1)
	displayReverse(arr, size, idx+1);
	cout << arr[idx] << endl;
}
int main(){

	int size;
	cin >> size;

	int arr[100000];

	for(int i = 0; i <size; i++){
		cin >> arr[i];
	}

	displayReverse(arr,size,0);
}

/*
size =5
Input =1 2 3 4 5
Output: 	
		5
		4
		3
		2
		1
		*/	
