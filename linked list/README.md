# Love Babbar Sheet 450 - LinkedList
## Problem 1:
**[Write a Program to reverse the Linked List. (Both Iterative and recursive)](https://www.geeksforgeeks.org/reverse-a-linked-list/)**<br />
Given pointer to the head node of a linked list, the task is to reverse the linked list. We need to reverse the list by changing the links between nodes.<br />

>Example 1: <br />
>Input: Head of following linked list <br />
>1->2->3->4->NULL <br />
>Output: Linked list should be changed to, <br />
>4->3->2->1->NULL<br />

>Example 2: <br />
>Input: Head of following linked list <br />
>1->2->3->4->5->NULL <br />
>Output: Linked list should be changed to, <br />
>5->4->3->2->1->NULL<br />

>Example 3: <br />
>Input: NULL <br />
>Output: NULL<br />

>Example 4: <br />
>Input: 1->NULL <br />
>Output: 1->NULL <br />

* Iterative Method <br />
 1. Initialize three pointers prev as NULL, curr as head and next as NULL.<br />
 2. Iterate through the linked list. In loop, do following. <br />
    // Before changing next of current, <br />
    // store next node <br />
    next = curr->next<br />
    // Now change next of current <br />
    // This is where actual reversing happens <br />
    curr->next = prev <br />
    // Move prev and curr one step forward <br />
    prev = curr <br />
    curr = next<br />
	 
<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif">

Below is the implementation of the above approach: <br />
```cpp
// Iterative C++ program to reverse a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList() { head = NULL; }

	/* Function to reverse the linked list */
	void reverse()
	{
		// Initialize current, previous and next pointers
		Node* current = head;
		Node *prev = NULL, *next = NULL;

		while (current != NULL) {
			// Store next
			next = current->next;
			// Reverse current node's pointer
			current->next = prev;
			// Move pointers one position ahead.
			prev = current;
			current = next;
		}
		head = prev;
	}

	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

/* Driver code*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.reverse();

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}
```

>Output: <br />
>Given linked list<br />
>85 15 4 20 <br />
>Reversed Linked list <br />
>20 4 15 85<br /><br />

>Time Complexity: O(n) <br />
>Space Complexity: O(1)<br />

* Recursive Method:  <br />
   1) Divide the list in two parts - first node and 
      rest of the linked list.<br />
   2) Call reverse for the rest of the linked list.<br />
   3) Link rest to first.<br />
   4) Fix head pointer<br />

<div align="left">
<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/2009/07/Linked-List-Rverse.gif"><br />

Below is the implementation of the above approach: <br />
```cpp
// Recursive C++ program to reverse
// a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList()
	{
		head = NULL;
	}

	Node* reverse(Node* head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		/* reverse the rest list and put
		the first element at the end */
		Node* rest = reverse(head->next);
		head->next->next = head;

		/* tricky step -- see the diagram */
		head->next = NULL;

		/* fix the head pointer */
		return rest;
	}

	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.head = ll.reverse(ll.head);

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}
```
   
>Output: <br />
>Given linked list<br />
>85 15 4 20<br /> 
>Reversed Linked list<br />
>20 4 15 85<br />
    
>Time Complexity: O(n) <br />
>Space Complexity: O(1)<br />
    
* A Simpler and Tail Recursive Method :  <br />

Below is the implementation of the above approach: <br />
```cpp
// A simple and tail recursive C++ program to reverse
// a linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void reverseUtil(Node* curr, Node* prev, Node** head);

// This function mainly calls reverseUtil()
// with prev as NULL
void reverse(Node** head)
{
	if (!head)
		return;
	reverseUtil(*head, NULL, head);
}

// A simple and tail-recursive function to reverse
// a linked list. prev is passed as NULL initially.
void reverseUtil(Node* curr, Node* prev, Node** head)
{
	/* If last node mark it head*/
	if (!curr->next) {
		*head = curr;
		/* Update next to prev node */
		curr->next = prev;
		return;
	}
	/* Save curr->next node for recursive call */
	Node* next = curr->next;
	/* and update next ..*/
	curr->next = prev;
	reverseUtil(next, curr, head);
}

// A utility function to create a new node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

// A utility function to print a linked list
void printlist(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

// Driver code
int main()
{
	Node* head1 = newNode(1);
	head1->next = newNode(2);
	head1->next->next = newNode(3);
	head1->next->next->next = newNode(4);
	head1->next->next->next->next = newNode(5);
	head1->next->next->next->next->next = newNode(6);
	head1->next->next->next->next->next->next = newNode(7);
	head1->next->next->next->next->next->next->next = newNode(8);
	cout << "Given linked list\n";
	printlist(head1);
	reverse(&head1);
	cout << "\nReversed linked list\n";
	printlist(head1);
	return 0;
}

```

>Output<br />
>Given linked list<br />
>1 2 3 4 5 6 7 8 <br />
>Reversed linked list<br />
>8 7 6 5 4 3 2 1<br />

* Using Stack: :  <br />
Algorithm – 
  * Store the nodes(values and address) in the stack until all the values are entered. <br />
  * Once all entries are done, Update the Head pointer to the last location(i.e the last value). <br />
  * Start popping the nodes(value and address) and store them in the same order until the stack is empty. <br />
  * Update the next pointer of last Node in the stack by NULL. <br />

Below is the implementation of the above approach: <br />
```cpp
// C++ program for above approach
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Create a class Node to enter values and address in the list
class Node {
public:
	int data;
	Node* next;
};

// Function to reverse the linked list
void reverseLL(Node** head)
{
	// Create a stack "s" of Node type
	stack<Node*> s;
	Node* temp = *head;
	while (temp->next != NULL) {
		// Push all the nodes in to stack
		s.push(temp);
		temp = temp->next;
	}
	*head = temp;
	while (!s.empty()) {
		// Store the top value of stack in list
		temp->next = s.top();
		// Pop the value from stack
		s.pop();
		// update the next pointer in the in the list
		temp = temp->next;
	}
	temp->next = NULL;
}

// Function to Display the elements in List
void printlist(Node* temp)
{
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

// Program to insert back of the linked list
void insert_back(Node** head, int value)
{

	// we have used insertion at back method to enter values
	// in the list.(eg: head->1->2->3->4->Null)
	Node* temp = new Node();
	temp->data = value;
	temp->next = NULL;

	// If *head equals to NULL
	if (*head == NULL) {
		*head = temp;
		return;
	}
	else {
		Node* last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = temp;
		return;
	}
}

// Driver Code
int main()
{
	Node* head = NULL;
	insert_back(&head, 1);
	insert_back(&head, 2);
	insert_back(&head, 3);
	insert_back(&head, 4);
	cout << "Given linked list\n";
	printlist(head);
	reverseLL(&head);
	cout << "\nReversed linked list\n";
	printlist(head);
	return 0;
}
```
    
>Output<br />
>Given linked list<br />
>1 2 3 4 <br />
>Reversed linked list<br />
>4 3 2 1 <br />
   
* Using Array :  <br />
Algorithm – <br />
  * 1. Create a linked list.<br />
  * 2. Count the number of nodes present in the Linked List<br />
  * 3. Initialize an array with the size of the count.<br />
  * 4. Store the elements of the Linked list in array <br />
  * 5. Print the array from the last index to the first.<br />
   
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef struct node {
	int val;
	struct node* next;
} node;

node* head = NULL;

// Function to return the No of nodes present in the linked list
int count(node* head)
{
	node* p = head;
	int k = 1;
	while (p != NULL) {
		p = p->next;
		k++;
	}
	return k;
}

node* ll_reverse(node* head) // to reverse the linked list
{
	node* p = head;
	long int i = count(head), j = 1;
	long int arr[i];
	while (i && p != NULL) {
		arr[j++] = p->val;
		p = p->next;
		i--;
	}
	j--;
	while (j) // loop will break as soon as j=0
		cout << arr[j--] << " ";
	return head;
}

// Function to insert node at the end of linked list
node* insert_end(node* head, int data)
{
	node *q = head, *p = (node*)malloc(sizeof(node));
	p->val = data;
	while (q->next != NULL)
		q = q->next;
	q->next = p;
	p->next = NULL;
	return head;
}

node* create_ll(node* head, int data) // create ll
{
	node* p = (node*)malloc(sizeof(node));
	p->val = data;
	if (head == NULL) {
		head = p;
		p->next = NULL;
		return head;
	}
	else {
		head = insert_end(head, data);
		return head;
	}
}

// Driver code

int main()
{
	int i = 5, j = 1;
	while (i--)
		head = create_ll(head, j++);
	head = ll_reverse(head);
	return 0;
}
```
    
>Input :  1->2->3->4->5<br />
>Output: 5->4->3->2->1<br />
    
>Time complexity: O(n)<br />
>Space complexity: O(n)<br />
	
	
	

<br /> <br /> <br />	
## Problem 2:
**[Reverse a Linked List in group of Given Size. [Very Imp]](https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1)**<br />
Given a linked list of size `N`. The task is to reverse every `k` nodes (where `k` is an input to the function) in the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).<br />
	
>Example 1:<br />
>Input:<br />
>LinkedList: 1->2->2->4->5->6->7->8<br />
>K = 4<br />
>Output: 4 2 2 1 8 7 6 5 <br />
>Explanation: <br />
>The first 4 elements 1,2,2,4 are reversed first and then the next `4` elements `5,6,7,8`. Hence, the resultant linked list is `4->2->2->1->8->7->6->5`.<br />
	
>Example 2:<br />
>Input:<br />
>LinkedList: 1->2->3->4->5<br />
>K = 3<br />
>Output: 3 2 1 5 4 <br />
>Explanation: <br />
>The first `3` elements are `1,2,3` are reversed first and then elements `4,5` are reversed.Hence, the resultant linked list is `3->2->1->5->4`.<br />
	
Your Task:<br />
You don't need to read input or print anything. Your task is to complete the function `reverse()` which should reverse the linked list in group of size `k` and return the head of the modified linked list.<br />

**Expected Time Complexity : O(N)**<br />
**Expected Auxilliary Space : O(1)**<br />

* Constraints: `1 <= N <= 10^4`<br />
`1 <= k <= N`<br />
	
```cpp
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;

    node(int x){
        data=x;
        next=NULL;
    }
};

void printList(struct node *node){
    while (node!= NULL){
        printf("%d",node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node* current = head;
    	struct node* next = NULL;
    	struct node* prev = NULL;
    	int count = 0; 
    	
    	while (current != NULL && count < k)
    	// reversing k elements :
    	{
    		next = current->next;             // marking next node
    		current->next = prev;             // reversing link
    		prev = current;                   // updating prev
    		current = next;                   // updating current
    		count++;
    	}
    	
    	if (next != NULL)       // checking if there are nodes ahead
        	head->next = reverse(next, k);    // reversing those recursively
        
    	return prev; 
    }
};

int main(void){
    int t;
    cin>>t;
    while(t--){
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int value;
            cin>>value;
            if(i == 0){
                head = new node(value);
                temp = temp->next;
            }
            else{
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        int k;
        cin>>k;
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
    return 0;
}
```


	
	
	
	
<br /> <br /> <br />
## Problem 3:
**[Write a program to Detect loop in a linked list.](https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1)**<br />
Given a linked list of `N` nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.<br />
	
>Example 1:<br />
>Input:<br />
>N = 3<br />
>value[] = {1,3,4}<br />
>x(position at which tail is connected) = 2<br />
>Output: True<br />
>Explanation: In above test case N = 3. The linked list with nodes N = 3 is given. Then value of x=2 is given which means last node is connected with xth node of linked list. Therefore, there exists a loop.<br />
	
>Example 2:<br />
>Input:<br />
>N = 4<br />
>value[] = {1,8,3,4}<br />
>x = 0<br />
>Output: False<br />
>Explanation: For N = 4 ,x = 0 means then lastNode->next = NULL, then the Linked list does not contains any loop.<br />
	
Your Task:<br />
The task is to complete the function **`detectloop`**() which contains reference to the head as only argument. This function should return `true` if linked list contains loop, else return `false`.<br />

**Expected Time Complexity: O(N)**<br />
**Expected Auxiliary Space: O(1)**<br />

* Constraints: `1 ≤ N ≤ 10^4`<br />
`1 ≤ Data on Node ≤ 10^3`<br />
	
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)walk = walk->next;
    tail->next = walk;
}

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        if(!head) return false;
        Node* fast = head->next;
        Node* slow = head;
        
        while(fast != slow){
            if(!fast || !fast->next)return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        if(ob.detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}
```

	
	
	
	
<br /> <br /> <br />
## Problem 4:
**[Write a program to Delete loop in a linked list.](https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1)**<br />
Given a linked list of `N` nodes such that it may contain a loop.<br />
* A loop here means that the last node of the link list is connected to the node at position `X`. If the link list does not have any loop, X=0.<br />
Remove the loop from the linked list, if it is present.  <br />

>Example 1:<br />
Input:<br />
N = 3<br />
value[] = {1,3,4}<br />
X = 2<br />
Output: 1<br />
Explanation: The link list looks like<br />
<pre>
1 -> 3 -> 4<br />
     ^    |
     |____|<br />
</pre>
A loop is present. If you remove it successfully, the answer will be 1. <br />

>Example 2:<br />
Input:<br />
N = 4<br />
value[] = {1,8,3,4}<br />
X = 0<br />
Output: 1<br />
Explanation: The Linked list does not contains any loop. <br />

>Example 3:<br />
Input:<br />
N = 4<br />
value[] = {1,2,3,4}<br />
X = 1<br />
Output: 1<br />
Explanation: The link list looks like <br />
<pre>
1 -> 2 -> 3 -> 4<br />
|______________|<br />
</pre>
A loop is present. If you remove it successfully, the answer will be 1. <br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `removeLoop()` which takes the head of the linked list as the input parameter. Simply remove the loop in the list (if present) without disconnecting any nodes from the list.<br />
**Note**: The generated output will be `1` if your submitted code is correct.<br />

**Expected time complexity: O(N)**<br />
**Expected auxiliary space: O(1)**<br />


* Constraints: `1 ≤ N ≤ 10^4`<br />

```cpp
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(!head) return;
        
        //using two pointers and moving one pointer(slow) by one node and 
        //another pointer(fast) by two nodes in each iteration.
        Node* fast = head->next;
        Node* slow = head;
        
        while( fast != slow )
        {
            //if the node pointed by first pointer(fast) or the node 
            //next to it is null, then loop is not present.
            if( !fast || !fast->next ) 
            return;
            fast=fast->next->next;
            slow=slow->next;
        }
        //both pointers now point to the same node in the loop.
        
        int size = 1;
        fast = fast->next;
        
        //we start iterating the loop with first pointer and continue till 
        //both pointers point to same node again.
        while( fast != slow )
        {
            //incrementing the counter which stores length of loop.
            size++;
            fast = fast->next;
        }
        
        //updating the pointers again to starting node.
        slow = head;
        fast = head;
        
        //moving pointer (fast) by (size-1) nodes.
        for(int i=0; i<size-1; i++)
            fast = fast->next;
        
        //now we keep iterating with both pointers till fast reaches a node such
        //that the next node is pointed by slow. At this situation slow is at
        //the node where loop starts and first at last node so we simply 
        //update the link part of first.
        while( fast->next != slow )
        {
            fast = fast->next;
            slow = slow->next;
        }
        //storing null in link part of the last node.
        fast->next = NULL;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
```

	
	

<br /> <br /> <br />
## Problem 5:
**[Find the starting point of the loop](https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/)**<br />
Write a function `findFirstLoopNode()` that checks whether a given Linked List contains a loop. If the loop is present then it returns point to the first node of the loop. Else it returns `NULL`.<br />

>Example : <br />
Input : Head of below linked list<br />

<img src = "https://www.geeksforgeeks.org/wp-content/uploads/2009/04/Linked-List-Loop.gif"><br />
Output : Pointer to node 2<br />
	
We have discussed `Floyd’s loop detection algorithm`. Below are steps to find the first node of the loop.<br />
  1. If a loop is found, initialize a slow pointer to head, let fast pointer be at its position. <br />
  2. Move both slow and fast pointers one node at a time. <br />
  3. The point at which they meet is the start of the loop.<br />
	
```cpp
// C++ program to return first node of loop.
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

// A utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

// Function to detect and remove loop
// in a linked list that may contain loop
Node* detectAndRemoveLoop(Node* head)
{
	// If list is empty or has only one node
	// without loop
	if (head == NULL || head->next == NULL)
		return NULL;

	Node *slow = head, *fast = head;
	// Move slow and fast 1 and 2 steps
	// ahead respectively.
	slow = slow->next;
	fast = fast->next->next;
	// Search for loop using slow and
	// fast pointers
	while (fast && fast->next) {
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}
	// If loop does not exist
	if (slow != fast)
		return NULL;
	// If loop exists. Start slow from
	// head and fast from meeting point.
	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

/* Driver program to test above function*/
int main()
{
	Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	Node* res = detectAndRemoveLoop(head);
	if (res == NULL)
		cout << "Loop does not exist";
	else
		cout << "Loop starting node is " << res->key;
	return 0;
}
```
	
>Output:<br /> 
Loop starting node is 15<br />
	
How does this approach work? <br />
Let slow and fast meet at some point after Floyd’s Cycle finding algorithm. The below diagram shows the situation when the cycle is found.<br />

<img src = "http://www.geeksforgeeks.org/wp-content/uploads/LinkedListCycle.jpg">

We can conclude below from the above diagram <br />
<pre>
Distance traveled by fast pointer = 2 * (Distance traveled 
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by 
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by 
       slow pointer before they meet first time
	
</pre>

From the above equation, we can conclude below <br />
<pre>
    m + k = (x-2y)*n

Which means m+k is a multiple of n.
</pre>

So if we start moving both pointers again at the same speed such that one pointer (say slow) begins from the `head` node of the linked list and other pointers (say fast) begins from the meeting point. When the `slow` pointer reaches the `beginning` of the loop (has made m steps), the fast pointer would have made also moved m steps as they are now moving the same pace. Since `m+k` is a multiple of `n` and `fast` starts from `k`, they would meet at the beginning. Can they meet before also? No, because the slow pointer enters the cycle first time after `m` steps.<br />

* `Method 2:`<br />
In this method, a temporary node is created. The next pointer of each node that is traversed is made to point to this temporary node. This way we are using the next pointer of a node as a flag to indicate whether the node has been traversed or not. Every node is checked to see if the next is pointing to a `temporary` node or not. In the case of the first node of the loop, the second time we traverse it this condition will be true, hence we return that node. 
The code runs in `O(n) time complexity` and `uses constant memory space`.<br />

Below is the implementation of the above approach:<br />

```cpp
// C++ program to return first node of loop
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

// A utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

// Function to detect first node of loop
// in a linked list that may contain loop
Node* detectLoop(Node* head)
{

	// Create a temporary node
	Node* temp = new Node;
	while (head != NULL) {

		// This condition is for the case
		// when there is no loop
		if (head->next == NULL) {
			return NULL;
		}

		// Check if next is already
		// pointing to temp
		if (head->next == temp) {
			break;
		}

		// Store the pointer to the next node
		// in order to get to it in the next step
		Node* nex = head->next;

		// Make next point to temp
		head->next = temp;

		// Get to the next node in the list
		head = nex;
	}

	return head;
}

/* Driver program to test above function*/
int main()
{
	Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	Node* res = detectLoop(head);
	if (res == NULL)
		cout << "Loop does not exist";
	else
		cout << "Loop starting node is " << res->key;

	return 0;
}
```

>Output: <br />
Loop starting node is 15 <br />

* `Method 3:` 
We can also use the concept of `hashing` in order to detect the first node of the loop. The idea is simple just iterate over the entire linked list and store node addresses in a set(C++ STL) one by one, while adding the node address into the set check if it already contains that particular node address if not then add node address to set if it is already present in the set then the current node is the first node of the loop. <br />

```cpp
// The below function take head of Linked List as
// input and return Address of first node in
// the loop if present else return NULL.

/* Definition for singly-linked list.
* struct ListNode {
*	 int val;
*	 ListNode *next;
*	 ListNode(int x) : val(x), next(NULL) {}
* };*/
ListNode* detectCycle(ListNode* A)
{

	// declaring map to store node address
	unordered_set<ListNode*> uset;

	ListNode *ptr = A;

	// Default consider that no cycle is present
	while (ptr != NULL) {

		// checking if address is already present in map
		if (uset.find(ptr) != uset.end())
		return ptr;

		// if address not present then insert into the set
		else
			uset.insert(ptr);
		
		ptr = ptr->next;
	}
	return NULL;
}
```


	
	
	
	
<br /><br /><br />
## Problem 6:
**[Remove duplicate element from sorted Linked List](https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1)**<br />
Given a `singly linked list` consisting of `N` nodes. The task is to **remove** duplicates (nodes with duplicate values) from the given list (if exists).<br />
**Note:** Try not to use extra space. `Expected time complexity is O(N)`. The nodes are arranged in a sorted way.<br />
	
<pre>
Example 1:
Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 2 ->2 -> 4-> 5, only 2 occurs more than 1 time.
</pre>
<pre>
Example 2:
Input:
LinkedList: 2->2->2->2->2
Output: 2
Explanation: In the given linked list 2 ->2 ->2 ->2 ->2, 2 is the only element and is repeated 5 times.
</pre>
**Your Task:**<br />
The task is to complete the function `removeDuplicates()` which should remove the duplicates from linked list and return the **head of the linkedlist**.<br />

<pre>
Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)
</pre>
	
* Constraints: `1 <= Number of nodes <= 10^4`<br />
	
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}

Node* removeDuplicates(Node *root);
int main() {
    // your code goes here
    int T;
    cin>>T;

    while(T--)
    {
        int K;
        cin>>K;
        Node *head = NULL;
        Node *temp = head;

        for(int i=0;i<K;i++){
        int data;
        cin>>data;
            if(head==NULL)
            head=temp=new Node(data);
            else
            {
                temp->next = new Node(data);
                temp=temp->next;
            }
        }
        
        Node *result  = removeDuplicates(head);
        print(result);
        cout<<endl;
    }
    return 0;
}

//Function to remove duplicates from sorted linked list.
Node* removeDuplicates(Node *head)
{
   //using a pointer to iterate over linked list.
   struct Node* current = head;
    
    //traversing through the linked list.
    while (current->next != NULL)       
    {
        //if data at current node and next node are same, we store the node 
        //next to the next node of current node in link of current node.
        if (current->data == current->next->data)
           current->next = current->next->next;
           
        //else we just move the pointer to next node.
        else
           current = current->next; 
    }
    return head;   
}
```
	
	
	
	
	
	
	


<br /><br /><br />
## Problem 7:
**[Remove duplicates from an unsorted linked list](https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1)**<br />
Given an `unsorted linked list` of `N` nodes. The task is to **remove duplicate elements** from this `unsorted Linked List`. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.<br />

<pre>
Example 1:
Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are 5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain 5->2->4
</pre>
<pre>
Example 2:
Input:
N = 5
value[] = {2,2,2,2,2}
Output: 2
Explanation:Given linked list elements are 2->2->2->2->2, in which 2 is repeated. So,
we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain only 2.
</pre>
	
**Your Task:**<br />
You have to complete the method `removeDuplicates()` which takes `1` argument: the `head of the linked list`.  Your function should return _a pointer to a linked list with no duplicate element_.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
</pre>
	
* Constraints: `1 <= size of linked lists <= 10^6`<br />
`0 <= numbers in list <= 10^4`<br />
	
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root){
    Node *temp = root;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    { 
        //using set to store already seen values in list. 
        unordered_set<int> seen; 
      
        //using two pointers one of which stores first node other null.
        struct Node *curr = head; 
        struct Node *prev = NULL; 
        
        //traversing over the linked list.
        while (curr != NULL) 
        { 
            //if data at current node is already present in set, we skip the 
            //current node and store the node next to current in link of prev. 
            if (seen.find(curr->data) != seen.end()) 
            { 
               prev->next = curr->next;
               //deleting current node which contains duplicates. 
               delete (curr);             
            }
            
            //else we just insert the data at current node in set and update 
            //prev to the current node.
            else
            { 
               seen.insert(curr->data);
               prev = curr; 
            }
            //updating current to the next node of prev node.
            curr = prev->next; 
        } 
        return head;
    }
    
};

int main() {
    int T;
    cin>>T;
    
    while(T--)
    {
        int K;
        cin>>K;
        struct Node *head = NULL;
        struct Node *temp = head;
 
        for(int i=0;i<K;i++){
        int data;
        cin>>data;
            if(head==NULL)
            head=temp=new Node(data);
            else
            {
                temp->next = new Node(data);
                temp=temp->next;
            }
        }
        
        Solution ob;
        Node *result  = ob.removeDuplicates(head);
        print(result);
        cout<<endl;
        
    }
    return 0;
}
```
	
	
	
	
	
	
	
	
	
<br /><br /><br />
## Problem 8:
**[Move last element to front of a given Linked List](https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/)**<br />
Write a function that moves the **last element** to the front in a given `Singly Linked List`. For example, if the given Linked List is `1->2->3->4->5`, then the function should change the list to `5->1->2->3->4`.<br />
**Algorithm:**<br /> 
`Traverse` the list till last node. Use **two pointers:** one to store the address of last node and other for address of second last node. After the end of loop do following operations.<br />

 1. Make second last as last (secLast->next = NULL).<br />
 2. Set next of last as head (last->next = *head_ref).<br /> 
 3. Make last as head ( *head_ref = last)<br />
	
**Implementation:**<br />
```cpp
/* CPP Program to move last element
to front in a given linked list */
#include <bits/stdc++.h>
using namespace std;

/* A linked list node */
class Node
{
	public:
	int data;
	Node *next;
};

/* We are using a double pointer
head_ref here because we change
head of the linked list inside
this function.*/
void moveToFront(Node **head_ref)
{
	/* If linked list is empty, or
	it contains only one node,
	then nothing needs to be done,
	simply return */
	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return;

	/* Initialize second last
	and last pointers */
	Node *secLast = NULL;
	Node *last = *head_ref;

	/*After this loop secLast contains
	address of second last node and
	last contains address of last node in Linked List */
	while (last->next != NULL)
	{
		secLast = last;
		last = last->next;
	}

	/* Set the next of second last as NULL */
	secLast->next = NULL;

	/* Set next of last as head node */
	last->next = *head_ref;

	/* Change the head pointer
	to point to last node now */
	*head_ref = last;
}

/* UTILITY FUNCTIONS */
/* Function to add a node
at the beginning of Linked List */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}


/* Function to print nodes in a given linked list */
void printList(Node *node)
{
	while(node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

/* Driver code */
int main()
{
	Node *start = NULL;

	/* The constructed linked list is:
	1->2->3->4->5 */
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);

	cout<<"Linked list before moving last to front\n";
	printList(start);

	moveToFront(&start);

	cout<<"\nLinked list after removing last to front\n";
	printList(start);

	return 0;
}
```
Output:<br />
<pre>
Linked list before moving last to front 
1 2 3 4 5 
Linked list after removing last to front 
5 1 2 3 4
</pre>
<pre>
Time Complexity: O(N) 
As we need to traverse the list once.
Auxiliary Space: O(1)
As constant extra space is used.
</pre>
	
	
	
	
	
	
	
	

<br /><br /><br />
## Problem 9:
**[]()**<br />

<br /><br /><br />
## Problem 10:
**[]()**<br />

<br /><br /><br />
## Problem 11:
**[]()**<br />

<br /><br /><br />
## Problem 12:
**[]()**<br />

<br /><br /><br />
## Problem 13:
**[]()**<br />

<br /><br /><br />
## Problem 14:
**[]()**<br />

<br /><br /><br />
## Problem 15:
**[]()**<br />

<br /><br /><br />
## Problem 16:
**[]()**<br />

<br /><br /><br />
## Problem 17:
**[]()**<br />

<br /><br /><br />
## Problem 18:
**[]()**<br />

<br /><br /><br />
## Problem 19:
**[]()**<br />

<br /><br /><br />
## Problem 20:
**[]()**<br />

<br /><br /><br />
## Problem 21:
**[]()**<br />

<br /><br /><br />
## Problem 22:
**[]()**<br />

<br /><br /><br />
## Problem 23:
**[]()**<br />

<br /><br /><br />
## Problem 24:
**[]()**<br />

<br /><br /><br />
## Problem 25:
**[]()**<br />

<br /><br /><br />
## Problem 26:
**[]()**<br />

<br /><br /><br />
## Problem 27:
**[]()**<br />

<br /><br /><br />
## Problem 28:
**[]()**<br />

<br /><br /><br />
## Problem 29:
**[]()**<br />

<br /><br /><br />
## Problem 30:
**[]()**<br />

<br /><br /><br />
## Problem 31:
**[]()**<br />

<br /><br /><br />
## Problem 32:
**[]()**<br />

<br /><br /><br />
## Problem 33:
**[]()**<br />

<br /><br /><br />
## Problem 34:
**[]()**<br />

<br /><br /><br />
## Problem 35:
**[]()**<br />

<br /><br /><br />
## Problem 36:
**[]()**<br />
