#include <iostream>
using namespace std;

int main(){

	int a;
	int b;
	cin >> a;
	cin >> b;

	int acopy = a;
	int bcopy = b;

	while(acopy % bcopy !=0){

		int rem = acopy % bcopy;
		acopy = bcopy;
		bcopy = rem;
	}
	int lcm = (a*b)/bcopy;
	cout << bcopy << endl;
	cout << lcm << endl;
	/* code */
	return 0;
} 