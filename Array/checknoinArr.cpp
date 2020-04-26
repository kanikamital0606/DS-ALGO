#include <iostream>
using namespace std;

//value to be find=x
bool checkNum(int arr[],int size,int x){ 

	if(size ==0) 
		return false;
	else if(arr[size-1]==x)
		return true;
	else
		return checkNum(arr, size-1, x);

}
int main() {
	int n;
    	cin >> n;
    	int *arr = new int[n];

    	for(int i=0; i<n;i++){
        	cin >> arr[i];
    	}
	int x;
	cin >>x;
	if(checkNum(arr,n,x)){
    		cout << "true"<<endl;
	}
	else{
		cout << "false"<< endl;
	}
}

