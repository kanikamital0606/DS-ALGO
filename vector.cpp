#include <iostream>
#include <vector>
using namespace std;

int main(){

	//vector<int> *vp = new vector<int>(); //Dynamic

	vector<int> v; //static;

	for (int i = 0; i < 100 ; i++){

		cout << "capacity: " << v.capacity();
		cout << "size: " << v.size();
		v.push_back(i+1);
	}

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	v[1] = 100; //to change value from 20 to 100 at index 1

	//dont use [] for inserting elements

	//v[3] = 1002;
	//v[4] = 5001;

	v.push_back(23);
	v.push_back(233);

	v.pop_back();

/*
	for (int i = 0; i < v.size(); i++){

		cout << v[i] << endl;
	}
	cout << v[0] << endl; // to kmow element at index 0
	cout << v[1] << endl; // to kmow element at index 1
	cout << v[2] << endl; // to kmow element at index 2
	cout << v[3] << endl; // to kmow element at index 3
	cout << v[4] << endl; // to kmow element at index 4
	cout << v[5] << endl; // to kmow element at index 5
	cout << v[6] << endl; // to kmow element at index 6

	cout << " Size: " << v.size() << endl;

	cout << v.at(2) << endl;
	cout << v.at(3) << endl;

*/
	return 0;
}