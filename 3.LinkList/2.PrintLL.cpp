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

void print(Node *head){
	while(head !=NULL){
		cout << head -> data << " ";
		head = head -> next;
	}

}


int main(){


	//create Node Statically 

	Node n1(45);

	//keep adddress of n1
	Node *head = &n1;

	//create Node n2, n3,n4,n5

	Node n2(45);
	Node n3(46);
	Node n4(47);
	Node n5(48);

	//Connect them 

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
/********************************************* code*********************************************************** 
	//create nodes dynamically

	node *n6 = new Node(49);
	node *head = n6;

	node *n7 = new Node(50);

	n6 -> next = n7;
	
****************************************************************************************************************/

	print(head);

	//if want to print 2 times ll
	//print(head);
	return 0;
}
