#include <iostream>
using namespace std;

//value to be find=x
int lastIndex(int arr[],int size,int x){
	for(int i=size-1; i>0; i--){
		if(arr[i]==x) 
			return i;
	}
        return -1;
}
int main(){
        int n;
        cin >> n;

        int *arr = new int[n];

	for(int i=0;i<n;i++){	
		cin >> arr[i];
        }

        int x;
        cin >>x;

        cout << lastIndex(arr,n,x)<< endl;
        return 0;
}     
