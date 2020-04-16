template <typename T>

class dynamicQueue{
	T *data;
	int nextIndex =0;
	int firstIndex = 0;
	int size = 0;
	int capacity =0;
public:
	dynamicQueue(int s){
		data = new T[s];
		nextIndex=0;
		firstIndex = -1;
		size=0;
		capacity = s;
	}

	int getSize(){
		return size;
	}

	bool isEmpty(){
		return size == 0;
	}

	//insert element
	void enqueue(T element){
		if(size == capacity){

			//create newData array
			T *newData = new T[ 2* capacity];
			int j=0;
			for(int i=firstIndex; i< capacity; i++){

				//copy in j newData from old data i then update j 
				newData[j] = data[i];
				j++;
			}
			for (int i = 0; i < firstIndex; i++){
				
				newData[j] = data[i];
				j++;
			}
			//now delete data after copying 
			delete [] data;
			data = newData;
			firstIndex =0;
			nextIndex = capacity;
			capacity *= 2;
		}

		data[nextIndex] = element;
		nextIndex = (nextIndex +1) % capacity;

		if (firstIndex = -1)
		{
			firstIndex =0;
		}
		size ++;
	}

	T front() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

	T dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		T ans = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if(size == 0) {
			firstIndex = -1;
			nextIndex = 0;
		}
		return ans;
	}	
};