#include <iostream>
using namespace std;

int fact(int n){

	int smallFact = (n-1);
	int out = n* smallFact;

	return out;
}

int main(){
	int n; 
	cin >> n;

	int ans = fact(n);
	cout << ans;
}