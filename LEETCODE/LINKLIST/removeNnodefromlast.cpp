#include <iostream>
using namespace std;

#include <iostream>
using namespace std;


//create class NODE which containd data and pointer to connect wtih address of next node;

class Node{
public:
	int data;
	Node *next;

	Node(int data){
		this -> data = data;
		next = NULL;
	}
};

Node *takeInput(){
	int data;
	cin >> data;

	Node *head = NULL;  //head created 
	Node *tail = NULL;  //tail created 

	while(data != -1){
		Node *newNode = new Node(data); //create new node variable newNode

		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail -> next = newNode;
			tail =  tail-> next;

			//or 
			//tail = newNode;
		}
		cin >> data;
	}
	return head;
}

/////////////////////////////////////////19. Remove Nth Node From End of List////////>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Node* removeNthFromEnd(Node* head, int n){
	if (head == NULL){
		return NULL;
	}

	//create slow and fast pointing to head;
	Node *slow = head;
	Node *fast = head;

	//loop till work n-1
	for(int i=0; i<n; i++){
		fast = fast -> next;
	}

	//if fast == NULL
	if(fast == NULL){
		head = head -> next;
		return head;
	}

	while(fast -> next != NULL){
		fast = fast -> next;
		slow = slow -> next;

		return head;
	}


}

/////////////////////////////>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>find MIddle 876 NODE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Node *middleNode_sec(Node *head) // second middle node is our mid in even size.
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return fast->next == nullptr ? slow : slow->next;
    }

///////////////////////////>>>>>>>>>>>>>>>>>>>>>>Reverse 206
Node *reverseList(Node *head){

	Node* prev = nullptr;
    Node* curr = head;
    Node* forward = nullptr;
        
    while(curr != nullptr){
    	forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

/////////////////////////////////>>>>>>>>>>>>>>>>>>>>Palindrome 234

Node *middleNode(Node *head){
	Node *slow = head;
	Node *fast = head;

	while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool isPalindrome(Node *head){

	//condition
	if(head == NULL && head == NULL){
		return true;
	}

	Node *mid = middleNode(head);
	Node *nextHead = mid -> next;
	mid -> next = nullptr;

	nextHead = reverseList(head);

	//now check in second half
	Node *curr1 = mid;
	Node *curr2 = mid -> next;

	while(curr1 != nullptr && curr2 != nullptr){
		if(curr1 -> data != curr2 -> data){
			return false;
		}
		curr1 = curr1 -> next;
		curr2 = curr2 -> next;
	}
	nextHead = reverseList(head);
	mid->next = head;

	return true;


}

//////////////////////////////237. Delete Node in a Linked List>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void deleteNode(Node *a){
	//node -> val = node -> next -> val;
    //    node -> next = node -> next -> next;

    a -> data = a -> next -> data;
    a -> next = a -> next -> next;
        
}

void print(Node *head){
	while(head != NULL){
		cout << head -> data << "  ";
		head = head -> next;
	}
}

int main(){

	Node *head = takeInput();
	int i ;
	cout << "Enter value of i" << " ";
	cin >> i;

	head = removeNthFromEnd(head, i);
	head = reverseList(head);
	print(head);
	return 0;
}
