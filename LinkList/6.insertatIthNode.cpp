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


Node *insertIthnode(Node *head, int i, int data){

	Node *newNode = new Node(data); //crete node 
	int count = 0;

	//store head in temp variable
	Node *temp = head;

	if(i == 0){
		newNode -> next = head;
		head = newNode;
		return head;
	}

	while(temp!= NULL && count < i-1){

		temp = temp -> next; 
		count ++;
	}

	if (temp != NULL){
		Node *a = temp -> next; //node a = next node of head to be insert
		temp -> next = newNode;
		newNode -> next = a;
	}
	return head;
}

void print(Node *head){
	while(head != NULL){
		cout << head -> data << "  ";
		head = head -> next;
	}
}

int main(){

	Node *head = takeInput();
	int i, data;
	cout << "Enter value of i" << " ";
	cin >> i;
	cout <<"Enter data " << " ";
	cin >> data;

	head = insertIthnode(head, i, data);
	print(head);
	return 0;
}
