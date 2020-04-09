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

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>function to insert Recursively>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Node *insert(Node *head, int i, int data){

	if(head == NULL){
		if(i==0){
			Node *newNode = new Node(data);
			return newNode;
		}
		else{
			return head;
		}
	}
		//create newNode
	Node *newNode = new Node(data);

	//check if node to be insert at pos at 0
	if(i==0){
		newNode -> next = head;
		head = newNode;
		return head;
	}

	head -> next = insert(head -> next, i-1, data); 
	return head;
}


void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}


int main(){

	Node *head = takeInput();
	int i, data;
	cout << "Enter value of i" << " ";
	cin >> i;
	cout <<"Enter data " << " ";
	cin >> data;

	head = insert(head, i, data);
	print(head);
	return 0;
}
