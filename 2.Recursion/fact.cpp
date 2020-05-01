#include <iostream>
using namespace std;

int fact(int n){
	int smallFact = (n-1);
	int out = n* smallFact;
	return out;
}

//Increasing
void incPrint(int n){
	if(n==0){
		return;
	}
	incPrint(n-1);
	cout << n << " ";
}

//Decreasing
void decPrint(int n){
	if(n==0){
		return;
	}
	cout << n << " ";
	decPrint(n-1);
}

int main(){
	int n; 
	cin >> n;

	int ans = fact(n);
	cout << ans << endl;
	incPrint(n);
	decPrint(n);
}