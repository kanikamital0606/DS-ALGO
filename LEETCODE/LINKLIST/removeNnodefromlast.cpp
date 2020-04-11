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

    	forward= curr ->next; //backup.

        curr->next = prev; // link join.

        prev = curr; // move forward.
        curr = forward;
    }

    return prev; // new head.
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

////////////////////////////////////////////////////////////////////141. Linked List Cycle///////////////////////////////////////////////////////


bool hasCycle(Node *head){

	if(head == nullptr || head -> next == nullptr){
		return false;
	}

	Node *slow = head;
	Node * fast = head;

	//check 
	while(fast != nullptr && fast -> next != nullptr){
		
		slow = slow-> next;
		fast = fast -> next -> next;

		if(slow ==  fast){
			break;
		}
	}
	return slow == fast;
}

//////////////////////////////////////////142. Linked List Cycle II Destect cycle begins ======================================================
Node *detectCycle(Node *head){

	if (head == nullptr || head->next == nullptr)

		return nullptr;

	Node *slow = head;
	Node *fast = head;
        
    while (fast != nullptr && fast->next != nullptr){
    	slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast)
        	break;
    }

    if (slow == fast){
    	slow = head;
      	
      	while (slow != fast){
      		slow = slow->next;
            fast = fast->next;
            
        }
        return slow;
    }
    return nullptr;
}
//////////////////////////////////////////leetcode 160 Intersection of Two Linked Lists ======================================================

Node *getIntersectionNode(Node *headA, Node *headB){
	if (headA == nullptr || headB == nullptr)
		return nullptr;
    if (headA->next == nullptr && headB->next == nullptr && headA-> data == headB-> data)
    	return headA;
    
    Node *tail = nullptr;
    Node *curr = headA;
   
    while (curr != nullptr){
    	tail = curr;
        curr = curr->next;
    }

    tail->next = headB; //cycle
    Node *ans = detectCycle(headA);
    tail->next = nullptr;

    return ans;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
Node *mergeTwoLists(Node *A, Node *B){

	if (A == nullptr)
        return B;
    if (B == nullptr)
        return A;

    Node *head = new Node(0); // dummyNode;
    Node *curr = head;

    while (A != nullptr && B != nullptr)
    {
        if (A->data <= B->data)
        {
            curr->next = A;
            A = A->next;
        }
        else
        {
            curr->next = B;
            B = B->next;
        }
        curr = curr->next;
    }

    if (A != nullptr)
        curr->next = A;
    else if (B != nullptr)
        curr->next = B;

    return head->next;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>leetcode 148.Sort List ===========================================

Node *middleNodeByINDEX(Node *head){ // first middle node is our mid in even size.
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//148
Node *sortList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *mid = middleNodeByINDEX(head);
    Node *nhead = mid->next;
    mid->next = nullptr;

    Node *a = sortList(head);
    Node *b = sortList(nhead);
    return mergeTwoLists(a, b);
}

//leetcode 23==================================================

Node *mergeKLists_(vector<Node *> &lists, int si, int ei)
{
    if (si == ei)
        return lists[si]; // only one list.
    if (si + 1 == ei)
        return mergeTwoLists(lists[si], lists[ei]); // by merging two list we get one sorted list.

    int mid = (si + ei) / 2;
    Node *a = mergeKLists_(lists, si, mid);
    Node *b = mergeKLists_(lists, mid + 1, ei);

    return mergeTwoLists(a, b);
}
struct compare{
    bool operator()(const Node *a, const Node *b) const{
        return a->data > b->data;
    }
};

Node *mergeKListsPQ_(vector<Node *> &lists){

	priority_queue<Node *, vector<Node *>, compare> pq; //java : PriorityQueue<Node> pq=new PriorityQueue<>((Node a,Node b)->{return a.val - b.val;});
    for (Node *l : lists){

    	if (l != nullptr)
    		pq.push(l);
    }
    if (pq.empty())
    	return nullptr;

    Node *head = new Node(-1);
    Node *curr = head;

    while (!pq.empty()){
    	Node *l = pq.top();
        pq.pop();

        curr->next = l;
        curr = curr->next;

        if (l->next != nullptr)
            pq.push(l->next);
    }

    return head->next;
}

Node *mergeKLists(vector<Node *> &lists)
{
    if (lists.size() == 0)
        return nullptr;

    return mergeKLists_(lists, 0, lists.size() - 1);
    // return mergeKListsPQ_(lists);
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>1290. Convert Binary Number in a Linked List to Integer.==============================================================

int getDecimalValue(Node *head)
{
    head = reverse(head);
    int ans = 0;
    int mul = 1;
    while (head != nullptr)
    {
        ans += mul * head->val;
        head = head->next;
        mul *= 2;
    }

    return ans;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>leetcode 143. Reorder List.==========================================================

void reorderList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node *mid = middleNodeByINDEX(head);
    Node *nhead = mid->next;
    mid->next = nullptr;

    nhead = reverseList(nhead);

    Node *curr1 = head;
    Node *forw1 = nullptr;

    Node *curr2 = nhead;
    Node *forw2 = nullptr;

    while (curr1 != nullptr && curr2 != nullptr)
    {
        forw1 = curr1->next;
        forw2 = curr2->next;

        curr1->next = curr2;
        curr2->next = forw1;

        curr1 = forw1;
        curr2 = forw2;
    }
}

void againReorderList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node *c1 = head;

    Node *nhead = head->next;
    Node *c2 = head->next;

    while (c1 != nullptr && c2 != nullptr)
    {
        if (c2->next != nullptr)
        {
            c1->next = c2->next;
            c1 = c1->next;
        }
        else
            break;

        if (c1->next != nullptr)
        {
            c2->next = c1->next;
            c2 = c2->next;
        }
        else
            break;
    }

    c1->next = nullptr;
    c2->next = nullptr;

    nhead = reverseList(nhead);
    c1->next = nhead;
    nhead = reverseList(nhead);
}

///////////////////>>>>>>>>>>>>>>>>>>>>>>>> 2. Add Two Numbers>>>>>>>>>>>>>>>>>>>>......

Node* addTwoNumbers(Node* l1, Node* l2) {
	
	int sum=0;
    
    Node *l3=NULL;
    Node **node=&l3;
    
    while(l1!=NULL||l2!=NULL||sum>0){
    	if(l1!=NULL){

    		sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
        	sum+=l2->val;
            l2=l2->next;
        }
        (*node)=new Node(sum%10);
        sum/=10;
        node=&((*node)->next);
    }        
    return l3;
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
