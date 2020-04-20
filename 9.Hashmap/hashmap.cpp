#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){

	unordered_map<string, int> ourmap;

/////////insert
	
	//create pair
	pair<string, int> p("abc", 1);

	ourmap.insert(p);

	//another method to insert map["string"] = value
	ourmap["def"] =2;

	//2 find or access

	cout << ourmap["abc"] << endl;
	cout << ourmap.at("abc") << endl;

	//cout << ourmap.at("ghi") << endl;
	cout << "size : " << ourmap.size() << endl;
	cout << ourmap["ghi"] << endl;
	cout << "size : " << ourmap.size() << endl;

	// check Presense
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

	// erase
	ourmap.erase("ghi");
	cout << "size : " << ourmap.size() << endl;
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

}
