#include <iostream>
using namespace std ;

int firstIndex(int arr[], int size, int idx, int x){

	//base case
	if(idx == size){
		return -1;
	}

	if(arr[idx]==x){
		return idx;
	}
	else{
		int fssi = firstIndex(arr,size,idx+1,x);
		return fssi;
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

	int fi=firstIndex(arr, size, 0, x);
	cout << fi;
	/* code */
	return 0;
}