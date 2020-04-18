#include <vector>

using namespace std;

//create template
template <typename T>


//create class Tree containg data and chidren

class treeNode{
public:
	T data;
	vector<treeNode*> children;
	treeNode(T data){
		this -> data = data;
	}
};