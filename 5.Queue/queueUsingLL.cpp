#include <iostream>
using namespace std;

template <typename T>
class Node {
	public: 
		T data;
		Node<T> *next;

		Node(T data) {
			this -> data = data;
			next = NULL;
		}
};

template <typename T>

class queueUsingLL{

	//Declare head and tail
	Node<T> *head;
	Node<T> *tail;
	int size;

	public: 

	queueUsingLL() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	int getSize(){
		return size;
	}

	bool isEmpty(){
		return size ==0;
	}

	void enqueue(T element){
		
		//create newNode 
		Node<T> *newNode = new Node<T>(element);
		
		//check empty
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail -> next = newNode;
			tail = newNode;
		}
		size ++;
	}

	//check front
	T front(){
		//chrc empty
		if (isEmpty()){
			/* code */
			return 0;
		}
		//return head data for front 
		return head -> data;
	}

	T dequeue(){
		if(isEmpty()){
			return 0;
		}
		//first store head in temp thn lik temp with head and delete head;

		T ans = head -> data; //ans = head;
		Node<T> *temp = head; //temp head
		head = head -> next;  //link head with next
		delete temp; //delete head(previous);
		size --;
		return ans;
	}
};

int main() {
        queueUsingLL<int> q;

        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);
        q.enqueue(60);


        cout << q.front() << endl;
        cout << q.dequeue() << endl;
        cout << q.dequeue() << endl;
        cout << q.dequeue() << endl;

        cout << q.getSize() << endl;
        cout << q.isEmpty() << endl;
}
