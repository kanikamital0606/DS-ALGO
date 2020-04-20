#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


int main(){

	unordered_map<string , int> ourmap;

	ourmap["abc"] =1;
	ourmap["def"] =2;
	ourmap["ghi"] =3;
	ourmap["jkl"] =4;
	ourmap["mno"] =5;

//unordered_map<string, int> :: iterator -> syntax it is name of iterator = ourmap.begin(); 


	unordered_map<string, int> :: iterator it = ourmap.begin(); 

	while(it != ourmap.end()){
		cout << "key: " << it->first << " value: " << it-> second << endl;
		it++;
	}

	//find
	unordered_map<string, int>::iterator it2 = ourmap.find("abc");
	ourmap.erase(it2, it2 + 4);

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it1 = v.begin();
	while (it1 != v.end()) {
		cout << *it1 << endl;
		it1++;
	}

}
