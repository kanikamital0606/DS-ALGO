#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;

unordered_map<int, int> m;
int maxFrequency(int *arr, int size){

	
	
	for (int i=0; i<size; i++)
	{
		int key = arr[i];

		if (m.count(key) ==0)
		{
			m[key] =1; //initailising Frequency value
		}
		else{
			m[key]++;  //incrementing Frequency value
		}
	}

	int maximum = m[arr[0]];
	int ans = arr[0];
	int j=1;

	while(j<size){

		if(m[arr[j]] > maximum ){

			maximum = m[arr[j]];
			ans = arr[j];
		}
		j++;
	}
	return ans;
}

int main(){
	int n;
    int arr[100000];
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    int maxKey= maxFrequency(arr, n);
    cout<<maxKey;
    return 0;
}

