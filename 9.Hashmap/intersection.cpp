#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void intersection(int *arr1, int *arr2, int size1, int size2){

	map<int,int> mapp;		

	for (int i = 0; i<size1; i++)
	{
		mapp[arr1[i]]++;
	}

	for (int i = 0; i < size2; i++)
	{
		if (mapp[arr2[i]] > 0){
			
			mapp[arr2[i]]--;
			cout << arr2[i] << endl;
		}

	}

}


int main() {

	int size1,size2;
	cin>>size1;
	
	int *arr1=new int[1+size1];	
	
	for(int i=0;i<size1;i++)
		cin>>arr1[i];

	cin>>size2;
	int *arr2=new int[1+size2];	
	
	for(int i=0;i<size2;i++)
		cin>>arr2[i];
	
	
	intersection(arr1,arr2,size1,size2);
	return 0;
}
