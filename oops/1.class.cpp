//How to create class student 

#include<iostream>
using namespace std;


class student{
	public:
	char name[100];	
	int rollNumber;
	int age;

};


int main(){
	//create obj statically
	student s1;
	student s2;
	student s3,s4,s5;

	s1.age=24;
	s1.rollNumber=15;

	cout << s1.age << endl;
	cout <<s1.rollNumber<< endl;


	s2.age = 25;
	s2.rollNumber=116;

	cout << s2.age << endl;
        cout << s2.rollNumber<< endl;



	//create obj dynamically
	student *s6 = new student;
	
	(*s6).age=23;
	(*s6).rollNumber=104;

	s6 -> age = 23;
	s6 -> rollNumber = 104;
	
}
