#include<iostream>
using namespace std;

int countZeroes(int n){
	if(n>0){
		if((n%10)==0){
			return countZeroes(n/10)+1;
		}
		return countZeroes(n/10);
	}
}

int main(){
	int n;
	cin >>n;
	
	cout << countZeroes(n);

}
