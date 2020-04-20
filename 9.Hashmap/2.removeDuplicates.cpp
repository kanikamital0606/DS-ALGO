#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> removeDuplicates(int* arr, int size) {
	
	//create vector output
	vector<int> output;

	//create map seen
	unordered_map<int, bool> seen;
	
	for (int i = 0; i < size; i++) {
		if (seen.count(arr[i]) > 0) {
			continue;
		}
		seen[arr[i]] = true;
		output.push_back(arr[i]);
	}
	return output;
}

int main(){

	int arr[] = {1,2,3,3,2,1,4,3,6,5,5};
	vector<int> output = removeDuplicates(arr, 11);

	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << endl;
	}
}
