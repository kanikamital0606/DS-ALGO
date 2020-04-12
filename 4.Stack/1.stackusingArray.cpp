#include <iostream>
using namespace std;
#include <climits>



class stackusingArray{
	
	//in private create data , nextIndex, capacity of array,
	int *data;
	int nextIndex;
	int capacity;

public:

	//size of array
	stackusingArray(int totalSize){

		data = new int[totalSize];

		//node initialise from 0;
		nextIndex =0;
		capacity = totalSize;
	}

	//2.return no of array present in my stack: size()

	int size(){
		return nextIndex;
	}
	
	//3. check empty or not
	bool isEmpty(){

		// if (nextIndex ==0)
		// 	return true;
		// else
		// 	return false;

		return nextIndex ==0;
	}

	//4. insert element requires only data>>>>>>>>>>>> :push()

	void push(int element){

		//check empty or not
		if(nextIndex == capacity) {
        	cout << "Stack full " << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++; //increment nextIndex by 1;
    }

	//5. delete element
	int pop(){
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

	//6. to check top element use top()
	int top() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};


int main(){

	stackusingArray s(4);

//insert in array stack
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	//to read top element 
	cout << " Top element" << endl;
	cout << s.top() << endl;


	//delete following element 
	cout << "following are deleted" << endl;
	
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	
	//to check size 
	cout << "size" << endl;

	cout << s.size() << endl;

	cout << s.isEmpty() << endl;
	return 0;
}