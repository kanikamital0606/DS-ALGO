#include<iostream>
using namespace std;

int fact(int n){
	if(n==1)return 1;
	int var=fact(n-1);
	return n*var;
}

int main(){
	int n;
	cin>>n;
	cout <<fact(n)<<endl;
	return 0;
}
