#include<iostream>
using namespace std;

#include "queue.h"

int main(){

	queueUsingArray<int> q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);

	cout <<"Front" <<  q.front() << endl;

	cout << "Delete " << q.dequeue() << endl;
	cout << "Delete " << q.dequeue() << endl;
	cout << "Delete " << q.dequeue() << endl;

	cout << "Front " << q.front() << endl;

	cout << "Total size = "<< q.getSize() << endl;

	cout << "queue is empty or not " << q.isEmpty() << endl;
