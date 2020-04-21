#include <iostream>
#include "treeNode.h"
using namespace std;

treeNode<int> *takeInput(){
	int rootData;
	cout << "Enter Data " << endl;
	cin >> rootData;

	treeNode<int>* root = new treeNode<int>(rootData);

	int n;
	cout << "No Of Children of " << rootData << endl;
	cin >> n;

	for(int i=0; i< n; i++){
		treeNode<int>* child =takeInput();
		root -> children.push_back(child);
	}
	return root;
}

//give root to tree  
void printTree(treeNode<int> *root){
	if(root == NULL){
		return;
	}
	cout << root-> data << ":";

	//call for each child 
	for (int i =0; i<root->children.size();i++){

		cout << root-> children[i]-> data << "," ;
		/* code */
	}
	cout << endl;
	for(int i = 0; i<root->children.size();i++) {
		printTree(root->children[i]);
    }
}

int main(){
	treeNode<int>* root = takeInput();
	printTree(root);

}
