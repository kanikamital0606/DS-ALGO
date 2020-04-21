#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>

class treeNode{
public:
	T data;
	vector<treeNode*> children;
	treeNode(T data){
		this -> data = data;
	}

	~treeNode(){ //destructor

		for (int i = 0; i < children.size(); i++)
		{
			delete children[i];
		}
	}
};

treeNode<int>* takeInputLevelWise(){
	//take root data
	int rootData;
	cout << "Enter root data " << endl;
	cin >> rootData;

	//now make root
	treeNode<int>* root = new treeNode<int>(rootData);

	//make queue to insert
	queue<treeNode<int>*> pendingNodes;

	//now in pending node push root
	pendingNodes.push(root);

	while(pendingNodes.size() != 0){

		//make front to pop out
		treeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front-> data << endl;
		
		//make child of root data (here 2,3,4)
		int numchild; //3
		cin >> numchild;

		//make loop to enter for 2,3,4
		for (int i = 0; i < numchild; i++){

			int childData;
			cout << "Enter" << i << "th child" << front->data << endl;
			cin >> childData;

			//dynamic create node child to store childData
			treeNode<int>* child = new treeNode<int>(childData);

			front->children.push_back(child); //connect 1&2;
			pendingNodes.push(child);	
		}
	}
	return root;
}

void printLevelWise(treeNode<int>* root) {

	//insert in queue

	queue<treeNode<int>*> pendingNodes;

	pendingNodes.push(root);

	while(pendingNodes.size()!=0){

		treeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		cout << front->data << ":";
	

		for (int i = 0; i < front->children.size(); i++){

			if(i< ((front-> children.size())-1)){
				cout << front->children[i]->data << " ";
			}

			else{
				cout << front-> children[i] -> data;
			}
			pendingNodes.push(front -> children[i]);
		}
		cout << endl;
	}
}
/////////////////////depth of tree
void printAtlevelK(treeNode<int>* root, int k){

	if(root == NULL){
		return;
	}

	if(k==0){
		cout << root -> data << endl;
		return ;
	}

	for (int i = 0; i < root-> children.size(); i++){

		printAtlevelK(root -> children[i], k-1);
	}
}

////////////////////////count Nodes
                  //only root gven 
int numNodes(treeNode<int>*root){

	if(root == NULL){
		return 0;
	}
	//initilly ans =1
	int ans =1;

	for (int i = 0; i< root->children.size(); i++)
	{
		ans+= numNodes(root->children[i]);
	}
	return ans;
}

///////////////////////////////sum of Nodes
int sumOfNodes(treeNode<int>*root){

	int sum = root->data;

	for(int i=0; i< root->children.size()-1; i++){
		sum += sumOfNodes(root-> children[i]);
	}
	return sum;
}

////////////////////////////max data Node 

treeNode<int>* maxNode(treeNode<int>* root){

	if(root == NULL){
		return root;
	}

	treeNode<int>* max = root;

	for (int i=0; i<root-> children.size(); i++){

		treeNode<int>* temp = maxNode(root->children[i]);
		if(temp-> data > max-> data){
			max= temp;
		}
	}
	return max;
}

////////////////////////height 
int height(treeNode<int>* root){

	int ans =0;
	for (int i = 0; i < root-> children.size(); i++){

		int childHeight = height(root->children[i]);
		if(childHeight > ans){
			ans = childHeight;
		}
	}
	return ans+1;

}
/////////////////////////////////count Leaf Nodes
int numLeafNodes(treeNode<int>* root){

	int count =0;
	if(root -> children.size() ==0){
		count ++;
	}

	for (int i=0; i<root->children.size(); i++){

		count += numLeafNodes(root->children[i]);
	}
	return count;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>traversals 

/////////////////////////////////preorder ->  root left right 
void preorder(treeNode<int>* root){

	if (root == NULL)
	{
		return; 
	}
	cout << root -> data << " ";

	//print left child of root
	for (int i=0; i<root->children.size(); i++){

		preorder(root->children[i]);
	}

}

//////////////////////////////////postorder -> root left child then right then root 
void postorder(treeNode<int>* root){

	if(root==NULL){
		return;
	}
	for(int i=0; i< root-> children.size(); i++){
		postorder(root-> children[i]);
	}
	// bcs root will print at last 
	cout << root-> data << " " ;
}

///////////////////////////destructor t delete dynamic tree
void deleteTree(treeNode<int>*root){

	//delete children one by one
	for (int i = 0; i < root->children.size(); i++){

		deleteTree(root->children[i]);
	}
	delete root;
}


int main(){

	treeNode<int>* root = takeInputLevelWise();
	printLevelWise(root);
	cout << "num: " << numNodes(root) << endl;
	cout << "Level 2: " << endl;
	printAtlevelK(root, 2);
	preorder(root);


	//dynamically allocated tree need to be deleted
	//deleteTree(root);
	delete root;
	
	return 0;
}

//take input 
//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 