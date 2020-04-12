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

Node *takeInput(){
	int data;
	cin >> data;

	Node *head = NULL;  //head created 
	Node *tail = NULL;  //tail created 

	while(data != -1){
		Node *newNode = new Node(data); //create new node variable newNode

		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail -> next = newNode;
			tail =  tail-> next;

			//or 
			//tail = newNode;
		}
		cin >> data;
	}
	return head;
}


int lengthofll(Node *head){
	if(head == NULL){
		return 0;
	}
	else{
		return lengthofll(head -> next)+1;
	}
}


int main(){

	Node *head = takeInput();
	cout << lengthofll(head);
	return 0;
}
