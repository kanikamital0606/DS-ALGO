#include <iostream>
using namespace std;
int main() {
	int n;
	cin >>n;

	for(int i=2; i<=n; i++){
		if(n%i==0){
			cout << "Not Prime";
		}
		else{
			cout << "prime";
		}
		break;
		
	}
	if(n==2){
		cout<<"prime";
	}
	return 0;
}
