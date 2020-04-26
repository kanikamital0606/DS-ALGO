#include <iostream>
using namespace std;

//value to be find=x
int firstIndex(int arr[],int size,int x){

	for(int i=0; i<size; i++){
		if(arr[i]==x) return i;
	}
	return -1;
	
}
int main(){
	int n;
	cin >> n;
        
	int *arr = new int[n];

        for(int i=0; i<n;i++){
		cin >> arr[i];
        }
	int x;
	cin >>x;
	cout << firstIndex(arr,n,x);
	
	return 0;
}
