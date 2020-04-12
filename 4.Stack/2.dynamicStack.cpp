#include <iostream>
using namespace std;
#include <climits>

class stackusingArray{
	int *data;
	int nextIndex;
	int capacity;

public:

	stackusingArray(){
		//data input
		data = new int[4];
		nextIndex=0;
		capacity =4;
	}

	//return the number of elements passed in my stack 

	int size(){
		return nextIndex;
	}

	//check if empty
	bool isempty(){
		return nextIndex ==0;
	}

	//insert element 

	void push(int element){
		if(nextIndex == capacity){
			int *newdata = new int[2*capacity];
			for(int i=0; i<capacity; i++){
				newdata[i] = data[i];
			}
			capacity*=2;
			delete []data;
			data = newdata;
		}
		data[nextIndex] = element;
		nextIndex++;
	}
};

int main(){

	stackusingArray s;

//insert in array stack
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);


	//to check size 
	cout << "size" << endl;

	cout << s.size() << endl;

	cout << s.isempty() << endl;
	return 0;


}