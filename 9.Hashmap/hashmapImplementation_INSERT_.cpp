#include <iostream>
#include <string>
using namespace std;

template <typename V>

//create class mapNode
class mapNode{
public:

	string key;
	V value;
	mapNode *next;
	
	mapNode(string key, V value){
		this -> key = key;
		this -> value = value;
		next = NULL;
	}
	//destructor
	~mapNode(){
		delete next;
	}
	
};

template <typename V >
class ourmap{
	//array which is head of linklist  
	mapNode<V>** buckets;
	int size;
	//int count;
	int numBuckets;
public:
	ourmap(){
		size =0;
		numBuckets =20;
		buckets = new mapNode<V>*[numBuckets]; 

		//remove garbage value from everywhere 
		for(int i=0; i< numBuckets; i++){
			buckets[i] = NULL;
		}
	}

	//destructor linklist
	~ourmap(){
		for(int i=0; i< numBuckets; i++){
			/* code */
			delete buckets[i];
		}
		delete [] buckets; //delete array as well;
	}

	//Function 1
	int size(){
		return count;
	}

	// Function 2
	V getValue(string key) {
		int bucketIndex = getBucketIndex(key);
		mapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				return head->value;
			}
			head = head->next;
		}
		return 0;
		
	}

private:

	int getBucketIndex(string key){

		int hashCode =0;
		int currentCoeff = 1;
		
		for (int i = key.length() - 1; i >= 0; i--) {
			
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;
			currentCoeff *= 37;
			currentCoeff = currentCoeff % numBuckets;
		}

		return hashCode % numBuckets;
	}

	void rehash(){
		mapNode<V>** temp = buckets;
		buckets = new mapNode<V>[2* numBuckets]; //increase size 

		//remove garbage i.e empty array
		for (int i = 0; i < 2*numBuckets; i++)
		{
			buckets[i] = NULL; 
		}
		int oldBucketsCount = numBuckets;
		numBuckets *=2;
		count = 0;   //behaving as an empty map

		for (int i = 0; i < oldBucketsCount; i++)
		{
			mapNode<V>* head = temp[i];

			while(head != NULL){

				string key = head-> key;
				V value = head -> value;
				insert(key, value);
				head = head->next;
			}
		}
		//delete old
		for (int i = 0; i < oldBucketsCount; i++){

			mapNode<V>* head = temp[i];
			delete head;
		}
		delete []temp;
	}

	public: //
	double getLoadFactor(){
		return (1.0* count / numBuckets);
	}
//////////////////////////////insert 
public:
	void insert(string key, V value) {

		int bucketIndex = getBucketIndex(key);
		mapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = buckets[bucketIndex];
		mapNode<V>* node = new mapNode<V>(key, value);
		node->next = head;
		buckets[bucketIndex] = node;
		count ++;

		//////////////loadFactor
		double loadFactor = (1.0*count/numBuckets); //1.0 multiplied to get exact in points which we were not getting  int/int;

		if (loadFactor >0.7){
			//rehashing
			rehash(); 
		}
	}

	///////////////////////////////remove || DELETE

	V remove(string key){

		//bucket mein find key
		int bucketIndex = getBucketIndex(string key);
		
		mapNode<V>* head = buckets[bucketIndex];
		mapNode<V>* prev = NULL;
		while (head != NULL) {
			if (head->key == key){ //if key match
				
				if (prev == NULL) { //check if prev = NULL
					buckets[bucketIndex] = head->next;                                          
				} 
				else{
					prev->next = head->next; //
				}
				V value = head->value;
				head->next = NULL;
				delete head;
				count--;
				return value;
			}
			prev = head;
			head = head->next;
		}
		return 0;
	}
};

int main(){
	ourmap<int>map;
	for (int i = 0; i < 10; i++){
		char c = '0' +i;
		string key = "abc";
		key = key+c;
		int value = i+1;
		map.insert(key, value);
		cout << map.getLoadFactor() << endl;
	}


	cout << map.size() << endl;
	map.remove("abc2");
	map.remove("abc7");

	cout << map.size() << endl;
	for (int i = 0; i < 10; i++){
		char c = '0' +i;
		string key = "abc";
		key = key+c;
		cout << key << ":" << map.size() << endl;

	}

	cout << map.size() << endl;
	

}