
template <typename T>

class queueUsingArray{

	T *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity; //to hold size;

public:	
	queueUsingArray(int s){

		data = new T [s];
		nextIndex =0;
		firstIndex = -1;
		size = 0;
		capacity=s;
	}

	//to get size
	int getSize(){
		return size;
	}

	bool isEmpty(){
		return nextIndex =0;
	}

	//insert 
	void enqueue(T element){
		//check if queue is full
		if(size == capacity){
			cout << "queue is Full" << endl;
			return;
		}
		// else create newNode to insert
		data[nextIndex] = element;
		nextIndex = (nextIndex+1) % capacity;
		if (firstIndex = -1){
			//reset
			firstIndex =0;
		}
		size++;
	}

	T front(){
		//check
		if (isEmpty()){
			cout << "Qeue is Empty" << endl;
			return 0;
		}
		return data[firstIndex];
	}
	
	//to delete the elemet
	T dequeue(){
		//check
		if (isEmpty()){
			cout << "Qeue is Empty" << endl;
			return 0;
		}
		//else
		//first store head in temp thn lik temp with head and delete head;

		T ans = data[firstIndex];
		firstIndex = (firstIndex+1)% capacity;
		size --;
		if (size ==0){
			firstIndex =0;
			nextIndex =0;
		}
		return ans;
	}
};