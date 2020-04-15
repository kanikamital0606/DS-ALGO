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

class Stack {

	Node<T> *head;
	int size;               // number of elements prsent in stack
public:
	
	Stack() {
		head = NULL;
		size = 0;
	}
	
	int getSize(){
		return size;
	}

	bool isempty(){
		return size ==0;
	}

	void push(T element){
		Node<T> *newNode = new Node<T>(element);
		newNode -> next = head;
		head =  newNode;
		size++;
	}

	T pop(){
		if(isempty()){
			return 0;
		}
		T ans = head -> data;
        Node<T> *temp = head;
        head = head -> next;
        delete temp;
        size--;
        return ans;
    }

    T top(){
    	if(isempty()){
    		return 0;
    	}
    	return head -> data;
    }

};

int main(){

	//stackUsingArray<int>s;
	Stack<char> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);


	//to read top element 
	cout << "Top element" << endl;
	cout << s.top() << endl;


	//delete following element 
	cout << "following are deleted" << endl;
	
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	
	//to check size 
	cout << "size" << endl;

	cout << s.getSize() << endl;

	cout << s.isempty() << endl;
}