#include<iostream>
using namespace std;

int sumOfdigits(int n){
	if(n==0) return 0;
	
	return (n%10 + sumOfdigits(n/10));
}

int main(){
	int n;
	cin >>n;
	cout << sumOfdigits(n);
}
