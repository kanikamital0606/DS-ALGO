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


Node *deletenode(Node *head, int i){

	if (head == NULL){
		return head;
	}

	if(i == 0){
		Node *a = head;
		head = head -> next;
		delete a;
		return head;
	}
	else{
		Node *h = deletenode(head -> next, i-1);
		head -> next = h;
	}
}

void print(Node *head){
	while(head != NULL){
		cout << head -> data << "  ";
		head = head -> next;
	}
}

int main(){

	Node *head = takeInput();
	int i ;
	cout << "Enter value of i" << " ";
	cin >> i;
	head = deletenode(head, i);
	print(head);
	return 0;
}
