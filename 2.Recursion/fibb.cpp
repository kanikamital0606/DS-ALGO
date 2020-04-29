#include <iostream>
using namespace std;


int fibb(int n){

	//base case 
	if(n<=1){
		return n;
	}

	return fibb(n-1)+(n-2);
}
int main(){
	/* code */
	int n; 
	cin >>n;
	cout << fibb(n);
	return 0;
}