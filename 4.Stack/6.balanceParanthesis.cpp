#include <iostream>
using namespace std;

#include <stack>
#include <cstring>

bool checkBalanced(char *exp){
	stack <char>s;

	//length of string
	int len = strlen(exp);

	for(int i=0; i<len; i++){

		if(exp[i] == '(' || '{' || '['){
			s.push(exp[i]);
		}
		else if(exp[i] == ')' || '}' || '}'){
			
			//check if empty
			if (s.empty()){
				return false;
			}

			//top should be equal to starting bracket here ch = top 
			char ch = s.top();
			s.pop();

			if(exp[i] == ')' && '('){
				continue;
			}
			else if(exp[i] == '}' && '{'){
				continue;
			}
			else{
				return false;
			}
		}
	}
}

int main() {
	char input[100000];
    cin.getline(input, 100000);

//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
