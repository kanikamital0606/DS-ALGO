#include <iostream>
using namespace std;

#include <climits>

template <typename T>

//replace int data type with T
class stackUsingArray{

	T *data;
	int nextIndex;
	int  capacity;

public:

	stackUsingArray(){
		data = new T[4];
		nextIndex = 0;
		capacity = 4;
	}

	//return the no of elements present in my stack 
	int size(){
		return nextIndex;
	}

	//is stack empty
	bool isempty(){
		return nextIndex ==0;
	}

	//insert
	void push(T element) {
		if(nextIndex == capacity) {
        	T *newData = new T[2 * capacity];
            for(int i = 0; i < capacity; i++) {
            	newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }


	//delete element
	T pop() {
		if(isempty()){
			cout << "Stack is empty " << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

	//top check
	T top() {
		if(isempty()) {
			cout << "Stack is empty " << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};

int main(){

	//stackUsingArray<int>s;
	stackUsingArray<char> s;

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

	cout << s.size() << endl;

	cout << s.isempty() << endl;
}