#include <iostream>
using namespace std;

int lastIndex(int arr[], int size, int idx, int x){
	//base case
	if(idx== size){
		return -1;
	}
	int lssi = lastIndex(arr,size,idx+1,x); //reursion till last 
	if(lssi!= -1){
		return lssi;
	}
	else if(arr[idx]==x){
		return idx;
	}
	else{
		return -1;
	}
}
int main(){
	int size ;
	cin >> size;

	int arr[100000];
	for(int i=0; i<size; i++){
		cin >> arr[i];
	}
	int x;
	cin >> x;

	int di=lastIndex(arr, size, 0, x);
	cout << di;
	/* code */
	return 0;
}