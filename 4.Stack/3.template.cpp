#include <iostream>
using namespace std;


//create template name T.  v , W for 
//					   int, double and  char



template <typename T, typename V>


//create class pair
class Pair{

	// int x;
	// int y;
	//replace int with template T

	// T x; T for same either int type or  double type
	// T y; 

	T x;  //for p3 as we want ifferent integers int and double
	V y;

public:
	void setX(T x){
		this -> x = x;
	}

	T getX(){
		return x;
	}

	void setY(V y){
		this -> y = y;
	}

	V getY(){
		return y;
	}


};


int main(){


	//class <class <int, int> >, int > object name; 

	Pair<Pair<int, int>, int> p2;
	p2.setY(10);

    Pair<int, int> p4;// X mein bhi X and Y bnega
	p4.setX(15);
	p4.setY(16);

	p2.setX(p4);
	cout << p2.getX().getX() <<  " " << p2.getX().getY() << " " << p2.getY() << endl;

/*
	//class<datatype> classname
	Pair<int , double> p1;  //here T = int ; V = double

	p1.setX(100.34);
    p1.setY(100.34);

    cout << p1.getX() << " " << p1.getY() << endl;

/*
	//class<datatype> classname
	Pair<int> p1;  //T here == int type
	
	//to check 
	p1.setX(10);
    p1.setY(20);

    cout << p1.getX() << " " << p1.getY() << endl;


	Pair<double> p2;//T here ==double type

	
	p2.setX(100.34);
	p2.setY(34.21);
        
    cout << p2.getX() << " " << p2.getY() << endl;

    //Now we want pair x integer type and pair y double type
	Pair<char> p3;
	

	*/
	return 0;
}