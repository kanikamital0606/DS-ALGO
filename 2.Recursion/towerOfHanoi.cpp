#include <iostream>
using namespace std;


void towerOfHanoi(int n, char src, char dest, char helper){

	if(n==0){
		return;
	}
	//Rec case 
	//First strep : move N-1 disc from sorce to Helper
	towerOfHanoi(n-1,src,dest,helper);
	cout << "Move"<< n << "disk from" << src << "to" << dest << endl;

	towerOfHanoi(n-1,helper,dest,src);
}

int main(){
	int n;
	cin >> n;
	towerOfHanoi(n,'A','C','B');
	return 0;
}