#include<iostream>
using namespace std;

int fact(int n){
	if(n==0){
		return 1;
	}
	int smallOutput = fact(n-1);
	return n*smallOutput;

}

int main(){

	//take input 
	int n; 
	cin >>n;

	//make a function factn and pass n to it
	int output = fact(n);
	cout << output << endl;
	return 0;
}
