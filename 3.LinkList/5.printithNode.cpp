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


void printIthnode(Node *head, int i){

	int count = 0;

	//store head in temp variable
	Node *temp = head;
	
	while(temp!= NULL){
		//check if count = i

		if(count == i){
			cout << temp -> data;
		return ;
		}
		count ++;
		temp = temp -> next;
		
	}
}


int main(){

	Node *head = takeInput();
	int pos;
	cin >> pos;
	
	printIthnode(head, pos);
	return 0;
}
