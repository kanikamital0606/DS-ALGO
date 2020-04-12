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


Node *deleteNode(Node *head, int i){

	if(i==0){ 
		Node *a = head;
		head -> next = NULL;
		delete a;
		return head;
	}

	Node *temp =head;
	int count =0;
	
	while(temp!= NULL && count < i-1){

		count ++;
		temp = temp -> next;
	}

	if (temp == NULL){
		return head;
	}

	if(temp -> next != NULL){
		Node *a = temp -> next; //node a = next node of head to be insert
		if( a-> next != NULL){
			temp -> next = a -> next;
		}
		else{
			temp -> next = NULL;
		}
		delete a;
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
	
	head = deleteNode(head, i);
	print(head);
	return 0;
}
