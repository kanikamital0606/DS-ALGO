#include <iostream>
using namespace std;


//create class NODE which containd data and pointer to connect wtih address of next node;

class Node{
public:
	int data;
	Node *next;

	Node(int data){
		this -> data = data;
		next = NULL;
	}
};


int main(){

	//Statically 

	Node n1(41);

	//keep adddress of n1

	Node *head = &n1;

	//create Node n2

	Node n2(45);
	Node n3(46);

	cout << n1.data << " " << n2.data;
	/* code */
	return 0;
}