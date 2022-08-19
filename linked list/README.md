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
**[Add 1 to a number represented as linked list](https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1)**<br />
A number `N` is represented in `Linked List` such that each digit corresponds to a **node in linked list**. You need to add `1` to it.<br />

<pre>
Example 1:
Input:
LinkedList: 4->5->6
Output: 457 
</pre>
<pre>
Example 2:
Input:
LinkedList: 1->2->3
Output: 124 
</pre>
	
**Your Task:**<br />
Your task is to complete the function `addOne()` which takes the `head of the linked list` as the only argument and returns _the head of the modified linked list_. The driver code prints the number.<br />
**Note:**<br />
The head represents the **left-most digit** of the number.<br />

<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
</pre>
	
* Constraints: `1 <= N <= 10^1000`<br />
	
```cpp
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution
{

    public:
        Node* reverse(Node *head) 
        {
            Node * prev = NULL;
            Node * current = head;
            Node * next;
            
            while (current != NULL) 
            { 
                next = current->next;     // storing next node
                current->next = prev;     // linking current node to previous
                prev = current;           // updating prev
                current = next;           // updating current
            }
            
            return prev; 
        } 
        
    public:
        Node* addOne(Node *head) 
        { 
            head = reverse(head);           // reversing list to make addition easy
            
            Node* current = head;
            int carry = 1;
            
            while(carry)
            {
                current->data += 1;         // adding one to current node
                
                if(current->data < 10) return reverse(head);
                    // if no carry we can reverse back list and return it
                else current->data = 0;
                    // else we continue with taking carry forward
                
                if(current->next == NULL) break;
                    // if, end of list, we break from loop
                else current = current->next;
                    // else we move to next node
            }
            
            current->next = new Node(1);  // adding new node for the carried 1
            return reverse(head);
        }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
}
```
	
	
	
	
	
	
	
	
	
	
	

<br /><br /><br />
## Problem 10:
**[Add two numbers represented by linked lists](https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1)**<br />
Given `two decimal numbers` represented by **two linked lists** of size `N` and `M` respectively. The task is to return _a linked list that represents the sum of these two numbers_.<br />
`For example`, the number 190 will be represented by the linked list, `1->9->0->null`, similarly `25` by `2->5->null`. Sum of these two numbers is `190 + 25 = 215`, which will be represented by `2->1->5->null`. You are required to return the head of the linked list `2->1->5->null`.<br />

<pre>
Example 1:
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked list (4 5) and (3 4 5), after adding
the two linked list resultant linked list will be (3 9 0).
</pre>
<pre>
Example 2:
Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked list (6 3) and (7), after adding the 
two linked list resultant linked list will be (7 0).
</pre>	
	
**Your Task:**<br />
The task is to complete the function `addTwoLists()` which has **node reference** of both the linked lists and returns _the head of the sum list_.<br />   

<pre>
Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.
</pre>

* Constraints: `1 <= N, M <= 5000`<br />
	
```cpp
#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

class Solution
{
    public:
    //Function to reverse the linked list.
    Node* reverse(Node *head) 
    {
        Node * prev = NULL;
        Node * current = head;
        Node * next;
        
        while (current != NULL) 
        { 
            next = current->next;     
            current->next = prev;     
            prev = current;          
            current = next;
        }
        
        return prev; 
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //reversing both lists to simplify addition.
        first = reverse(first);             
        second = reverse(second);            
        
        Node *sum=NULL;
        int carry=0;
        
        //using a loop till both lists and carry gets exhausted.
        while( first!=NULL || second!=NULL || carry!=0 )
        {
            //using a variable to store sum of two digits along with carry.
            int newVal = carry;
            
            //if nodes are left in any list, we add their data in newVal.
            if(first) newVal += first->data;
            if(second) newVal += second->data;
        
            //updating carry.
            carry = newVal/10;
            
            //using modulus to store only a single digit at that place.
            newVal = newVal%10;             
            
            //creating new node which gets connected with other nodes that 
            //we get after calculating sum of respective digits.
            Node* newNode = new Node(newVal);
            
            //storing the previously made nodes in the link part of new node.
            newNode->next = sum;
            
            //making the new node as the first node of all previously made node.
            sum = newNode;
            
            //moving ahead in both lists.
            if(first) first = first->next; 
            if(second) second = second->next;
        }
        return sum;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
```
	
	
	
	
	
	
	
	
	
	

<br /><br /><br />
## Problem 11:
**[Intersection of two sorted Linked lists](https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1)**<br />
Given `two lists` sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its **own memory** — the original lists should not be changed.<br />
**Note:**<br />
The list elements are not necessarily **distinct**.<br />

<pre>
Example 1:
Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two linked list, 2, 4 and 6 are the elements in the intersection.
</pre>
<pre>
Example 2:
Input:
L1 = 10->20->40->50
L2 = 15->40
Output: 40
</pre>
	
**Your Task:**<br />
The task is to complete the function `intersection()` which should find the intersection of two linked list and add all the elements in intersection to the third linked list and return _the head of the third linked list_.<br />

<pre>
Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(n+m)
Note: n,m are the size of the linked lists.
</pre>
	
* Constraints: `1 <= size of linked lists <= 5000`<br />
`1 <= Data in linked list nodes <= 1000`<br />
	
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>> n >> m;
        
        Node* head1 = inputList(n);
        Node* head2 = inputList(m);
        
        Node* result = findIntersection(head1, head2);
        
        printList(result);
        cout<< endl;
    }
    return 0;
}

Node* findIntersection(Node* head1, Node* head2)
{
    Node *p1=head1, *p2=head2;
    Node *head=NULL, *tail=NULL;
    
    while(p1 && p2)
        if(p1->data > p2->data)
            // nodes dont match
            // moving to next node in list with smaller node
            p2 = p2->next;
        
        else if(p2->data > p1->data)
            // nodes dont match
            // moving to next node in list with smaller node
            p1 = p1->next;
        
        else
        {
            // nodes match
            
            if(head==NULL)
                head = tail = new Node(p1->data);
                // creating new head for intersection list
            else
            {
                // appending new node at the end
                tail->next = new Node(p1->data);
                tail = tail->next;
            }
            p1 = p1->next;
            p2 = p2->next;
            // moving to next nodes in both lists
        }
    
    return head;
}
```
	
	
	
	
	
	
	
	
	
	
<br /><br /><br />
## Problem 12:
**[Intersection Point of two Linked Lists / Intersection Point in Y Shapped Linked Lists](https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1)**<br />
Given `two singly linked lists` of size `N` and `M`, write a program to get the point where **two linked lists intersect** each other.<br />
 
<pre>
Example 1:
Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
<img src = "https://contribute.geeksforgeeks.org/wp-content/uploads/linked.jpg"><br />
</pre>
<pre>
Example 2:
Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL   
</pre>
	
**Your Task:**<br />
You don't need to read input or print anything. The task is to complete the function `intersetPoint()` which takes the pointer to the head of **linklist1(head1)** and **linklist2(head2)** as input parameters and returns _data value of a node where two linked lists intersect_. If linked list do not merge at any point, then it should return `-1`.<br />

<pre>
Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ N + M ≤ 2*10^5`<br />
`-1000 ≤ value ≤ 1000`<br />
	
```cpp
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int n1=0, n2=0;
    Node* temp;
    
    //finding length of list1.
    for(temp = head1; temp; temp=temp->next)
        n1++;
        
    // finding length of list2.
    for(temp = head2; temp; temp=temp->next)
        n2++;
    
    //if list1 is longer, we ignore some of its starting
    //elements till it has as many elements as list2.
    for(  ; n1>n2 ; n1-- )
        head1 = head1->next;
        
    //similarly, if list2 is longer, we ignore some of its starting
    //elements till it has as many elements as list1.
    for(  ; n2>n1 ; n2-- )
        head2 = head2->next;
        
    //now we simply traverse ahead till we get the intersection point, if there 
    //is none, this loop will break when both pointers point at NULL.
    while( head1 != head2 )
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // if head1 is not NULL, we return its data otherwise we return -1.
    if(head1) 
    return head1->data;
    return -1;
}
```
	
	
	
	
	
	
	
	

<br /><br /><br />
## Problem 13:
**[Merge Sort For Linked lists [Very Important]](https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1)**<br />
Given `Pointer/Reference` to the head of the linked list, the task is to **Sort** the given linked list using `Merge Sort`.<br />
**Note:**<br />
If the length of linked list is `odd`, then the **extra node** should go in the first list while splitting.<br />

<pre>	
Example 1:
Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given linked list, the resultant matrix will be 1->2->3->4->5.
</pre>	
	
<pre>	
Example 2:
Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given linked list , resultant will be 0->9->15.
</pre>
	
**Your Task:**<br />
For `C++` and `Python`: The task is to complete the function `mergeSort()` which sort the linked list using merge sort function.<br />
For `Java`: The task is to complete the function `mergeSort()` and return the node which can be used to print the sorted linked list.<br />

<pre>
Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)
</pre>
	
* Constraints: `1 <= N <= 10^5`<br />
	
```cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution{
  public:
  
    //Function to split the list into two halves.
    void splitList(Node* source, Node** frontRef, Node** backRef) {
        
        //using two pointers to find the midpoint of list.
        struct Node* fast;
        struct Node* slow;
        if (source == NULL || source->next == NULL) {
            *frontRef = source;
            *backRef = NULL;
        } else {
            
            //first pointer, slow moves 1 node and second pointer, fast moves
            //2 nodes in one iteration.
            slow = source;
            fast = source->next;
            while (fast != NULL) {
                fast = fast->next;
                if (fast != NULL) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            
            //slow is before the midpoint in the list, so we split the 
            //list in two halves from that point.
            *frontRef = source;
            *backRef = slow->next;
            slow->next = NULL;
        }
    }
    
    //Function to merge two halves of list.
    Node* mergeList(struct Node* a, struct Node* b) {
        struct Node* result = NULL;
        
        //base cases when either of two halves is null.
        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);
            
        //comparing data in both halves and storing the smaller in result and
        //recursively calling the mergeList function for next node in result.
        if (a->data <= b->data) {
            result = a;
            result->next = mergeList(a->next, b);
        } else {
            result = b;
            result->next = mergeList(a, b->next);
        }
        //returning the resultant list.
        return (result);
    }
    
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node *head) {
        
        struct Node* a;
        struct Node* b;
        
        if (head == NULL || head->next == NULL) 
        return head;
        
        //splitting the list into two halves.
        splitList(head, &a, &b);
        
        //calling the mergeSort function recursively for both parts separately.
        a = mergeSort(a);
        b = mergeSort(b);
        
        //calling the function to merge both halves.
        return mergeList(a, b);
    }

};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
```
	
	
	
	
	
	
	
	

<br /><br /><br />
## Problem 14:
**[Quicksort for Linked Lists [Very Important]](https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1)**<br />
Sort the given Linked List using `quicksort`. which takes `O(n^2) time` in **worst case** and `O(nLogn)` in **average and best cases**, otherwise you may get `TLE`.<br />
	
<pre>
Input:
In this problem, method takes 1 argument: address of the head of the linked list. The function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
There are multiple test cases. For each test case, this method will be called individually.
</pre>
<pre>
Output:
Set *headRef to head of resultant linked list.
</pre>
**User Task:**<br />
The task is to complete the function `quickSort()` which should set the `*headRef to head` of the resultant linked list.<br />

* Constraints: `1<=T<=100`<br />
`1<=N<=200`<br />

**Note:**<br />
If you use "Test" or "Expected Output Button" use below example format<br />
<pre>
Example:
Input:
2
3
1 6 2
4
1 9 3 8
</pre>
<pre>
Output:
1 2 6
1 3 8 9
</pre>
<pre>
Explanation:
Testcase 1: After sorting the nodes, we have 1, 2 and 6.
Testcase 2: After sorting the nodes, we have 1, 3, 8 and 9.
</pre>
	
```cpp
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void quickSort(struct node **headRef);

int main()
{
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;n=n-1;
        cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
              cin>>x;
              temp->next=new node(x);
              temp=temp->next;
        }
    
        quickSort(&head);
     
        printList(head);

        while(head!= NULL){
             temp=head;
             head=head->next;
             free(temp);     
        }
    }
    return 0;
}

struct node *getTail(struct node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
// Partitions the list taking the last element as the pivot
struct node *partition(struct node *head, struct node *end,
                       struct node **newHead, struct node **newEnd)
{
    struct node *pivot = end;
    struct node *prev = NULL, *cur = head, *tail = pivot;
 
    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            struct node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}
 
//here the sorting happens exclusive of the end node
struct node *quickSortRecur(struct node *head, struct node *end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    node *newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    struct node *pivot = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        struct node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 
// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(struct node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
```
	
	
	
	
	
	
	
	
	
	

<br /><br /><br />
## Problem 15:
**[876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)**<br />    
Given the `head` of a singly linked list, return _the middle node of the linked list_.<br />
If there are two middle nodes, return **the second middle node**.<br />
                     
>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg"><br />   
>Input: head = [1,2,3,4,5]<br />
>Output: [3,4,5]<br />
>Explanation: The middle node of the list is node 3.<br />
                     
>Example 2:<br />
><img src = "https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg"><br />
>Input: head = [1,2,3,4,5,6]<br />
>Output: [4,5,6]<br />
>Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.<br />
                     
* Constraints: The number of nodes in the list is in the range `[1, 100]`.<br />
`1 <= Node.val <= 100 `<br />
                    
 ```cpp
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            head = head->next;
            fast = fast->next->next;
        }
        if(fast->next == NULL) return head;
        return head->next;
    }
};
```  
	
	
	
	
	

<br /><br /><br />
## Problem 16:
**[Check If Circular Linked List](https://practice.geeksforgeeks.org/problems/circular-linked-list/1)**<br />
Given head, the `head of a singly linked list`, find _if the linked list is circular or not_. A linked list is called circular if it `not NULL` terminated and all nodes are connected in the form of a cycle. `An empty linked list is considered as circular`.<br />
**Note:**<br />
The linked list does not contains any `inner loop`.<br />

<pre>
Example 1:
Input:
LinkedList: 1->2->3->4->5
(the first and last node is connected, i.e. 5 --> 1)
Output: 1
</pre>
<pre>
Example 2:
Input:
LinkedList: 2->4->6->7->5->1
Output: 0
</pre>
	
**Your Task:**<br />
The task is to complete the function `isCircular()` which checks if the given linked list is circular or not. It should return `true` or `false` accordingly. (the driver code prints `1` if the returned values is `true`, otherwise `0`)<br />

<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
</pre>
	
* Constraints: `1 <=Number of nodes<= 100`<br />

```cpp
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to get the middle of the linked list*/
bool isCircular(struct Node *head);

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){

        cin>>n>>k;
        Node *head=NULL, *tail = NULL;
        int x;
        cin >> x;
        head = new Node(x);
        tail = head;
        for(int i=0;i<n-1;i++)
        {
            cin>>x;
            tail -> next = new Node(x);
            tail = tail -> next;
        }
        if (k==1 && n >= 1)
              tail->next = head;


    printf("%d\n", isCircular(head));
    }
    return 0;
}

bool isCircular(struct Node *head)
{
    if(!head)
        return true;
    
    Node *temp=head;
    
    while(head&&head->next!=temp)
        head=head->next;
    
    if(!head||!(head->next))
        return false;
    
    return true;
}
```
	
	
	
	
	
	
	

<br /><br /><br />
## Problem 17:
**[Split a Circular Linked List into two halves](https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1)**<br />
Given a `Cirular Linked List` of size `N`, split it into **two halves circular lists**. If there are `odd` number of nodes in the given circular linked list then out of the resulting `two halved lists`, first list should have one node more than the `second list`. The resultant lists should also be **circular lists and not linear lists**.<br />

<pre>
Example 1:
Input:
Circular LinkedList: 1->5->7
Output:
1 5
7
</pre> 
<pre>
Example 2:
Input:
Circular LinkedList: 2->6->1->5
Output:
2 6
1 5
</pre>
	
**Your Task:**<br />
Your task is to complete the given function `splitList()`, which takes `3` input parameters: The `address of the head of the linked list`, `addresses of the head of the first` and `second halved resultant lists` and **Set the head1_ref** and **head2_ref** to the first resultant list and second resultant list respectively.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxilliary Space: O(1)
</pre>

* Constraints: `1 <= N <= 100`<br />
	
```cpp
#include<stdio.h> 
#include<stdlib.h> 
 
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
}; 

void splitList(struct Node *head, struct Node **head1_ref,   struct Node **head2_ref);
 struct Node* newNode(int key)
{
    struct Node *temp = new Node(key);
    
    return temp;
}

/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head Nodes of 
    the two resultant linked lists */

void printList(struct Node *head)
{
  struct Node *temp = head; 
  if(head != NULL)
  {
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
    printf("\n");
  }
}
 
/* Driver program to test above functions */
int main()
{
  
   int t,n,i,x;
    scanf("%d",&t);
   while(t--)
   {
       struct Node *temp,*head = NULL;
       struct Node *head1 = NULL;
       struct Node *head2 = NULL;
       scanf("%d",&n);
       scanf("%d",&x);
       head=new Node(x);
       temp=head;
       for(i=0;i<n-1;i++){
       scanf("%d",&x);
       
       temp->next=new Node(x);
       
       temp=temp->next;
           
       }
       
       temp->next=head;
  
       splitList(head, &head1, &head2);
  
     // printf("\nFirst Circular Linked List");
      printList(head1);  
 
     // printf("\nSecond Circular Linked List");
      printList(head2);  
   
   }
  return 0;
}

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref) 
{ 
    Node *slow_ptr = head; 
    Node *fast_ptr = head; 
      
    if(head == NULL) 
        return; 
      
    /* If there are odd nodes in the circular list then 
       fast_ptr->next becomes head and for even nodes 
       fast_ptr->next->next becomes head */
    while(fast_ptr->next != head && 
          fast_ptr->next->next != head) 
    { 
        fast_ptr = fast_ptr->next->next; 
        slow_ptr = slow_ptr->next; 
    } 
      
    /* If there are even elements in list
       then move fast_ptr */
    if(fast_ptr->next->next == head) 
        fast_ptr = fast_ptr->next; 
          
    /* Set the head pointer of first half */
    *head1_ref = head; 
          
    /* Set the head pointer of second half */
    if(head->next != head) 
        *head2_ref = slow_ptr->next; 
          
    /* Make second half circular */
    fast_ptr->next = slow_ptr->next; 
          
    /* Make first half circular */
    slow_ptr->next = head; 
} 
```
	
	
	
	
	
	
	
	
	
	
	
	

<br /><br /><br />
## Problem 18:
**[Check if Linked List is Palindrome](https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1)**<br />
Given a `singly linked list` of size `N` of integers. The task _is to check if the given linked list is palindrome or not_.<br />

<pre>
Example 1:
Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is 1 2 1 , which is a palindrome and Hence, the output is 1.
</pre>
<pre>
Example 2:
Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list is 1 2 3 4 , which is not a palindrome and Hence, the output is 0.
</pre>
	
**Your Task:**<br />
The task is to complete the function `isPalindrome()` which takes `head as reference` as the only parameter and returns `true` or `false` if linked list is palindrome or not respectively.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)
</pre>
	
* Constraints: `1 <= N <= 10^5`<br />
	
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
    public:
    //Function to reverse a linked list.
    Node* reverse_list(Node* head)
    {
        Node* prev = NULL;     
        Node* curr = head;   
        Node* next; 
        
        while(curr)
        {
            next = curr->next; 
            curr->next = prev;    
            prev = curr;         
            curr = next; 
        }
        return prev;
        
    }
    
    //Function to check whether two lists are identical.
    bool is_identical(Node* n1, Node* n2)
    {
        //iterating over both lists and returning 0 if data at any node
        //is not equal in both lists.
        for(  ; n1 && n2 ; n1=n1->next, n2=n2->next )
            if( n1->data != n2->data )
                return 0;
                
        //returning 1 if data at all nodes are equal.
        return 1;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        int size=0;
        Node* ptr;
        //finding number of nodes in the list.
        for( ptr=head ; ptr ; ptr=ptr->next )
            size++;
            
        
        if(size<2) return 1;
        
        //now, we split list into 2 halves. In case of odd number of elements, 
        //first half will have the middle element.
        
        ptr = head;
        int mid_pt = (size-1)/2;
        
        //using a pointer to get to middle element to get the second half of list.
        while(mid_pt--)
            ptr = ptr->next;
            
        //ptr now holds address of last element of first half.
        
        //storing the elements of second half separately in head2.
        Node* head2 = ptr->next;
        ptr->next = NULL;     
        
        //we reverse the second half of list.
        head2 = reverse_list(head2);
        
        //we check whether both halves are identical (for odd number of elements
        //first half will have one extra element).
        bool ret = is_identical(head, head2);
        
        //we reverse back the second half of list and connect it to the first half.
        head2 = reverse_list(head2);
        ptr->next = head2;
        
        //returning 1 if list is palindrome else 0.
        return ret;
    }

};

int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}
```
	
	
	
	
	
	
	
	
	
	
	
	
<br /><br /><br />
## Problem 19:
**[Deletion from a Circular Linked List](https://www.geeksforgeeks.org/deletion-circular-linked-list/)**<br />
Consider the linked list as shown below:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/delete_circular-linkedlist.png"><br />
We will be given a `node` and our task is to **delete that node from the circular linked list**.<br />
**Examples:**<br />
<pre>
Input : 2->5->7->8->10->(head node)
        data = 5
Output : 2->7->8->10->(head node)

Input : 2->5->7->8->10->(head node)
         7
Output : 2->5->8->10->(head node)
</pre>
**Algorithm**<br />
 `Case 1:` List is empty.<br />

 * If the list is empty we will simply `return`.<br />

 `Case 2:` List is not empty<br />

 * If the list is not empty then we define two pointers `curr` and `prev` and initialize the pointer `curr` with the `head` node.<br />
 * `Traverse` the list using curr to find the node to be deleted and before moving to curr to the next node, every time set `prev = curr`.<br />
 * If the node is found, check if it is the only node in the list. If yes, set `head = NULL` and `free(curr)`.<br />
 * If the list has more than one node, check if it is the first node of the list. Condition to check this `(curr == head)`. If yes, then move prev until it reaches the last node. After prev reaches the last node, set `head = head -> next` and `prev -> next = head`. Delete `curr`.<br />
 * If `curr` is not the first node, we check if it is the last node in the list. Condition to check this is `(curr -> next == head)`.<br />
 * If `curr` is the last node. Set `prev -> next = head` and delete the node curr by `free(curr)`.<br />
 * If the node to be deleted is neither the first node nor the last node, then set `prev -> next = curr -> next` and delete `curr`.<br />
	
Complete program to demonstrate deletion in `Circular Linked List`:<br /> 
```cpp
// C++ program to delete a given key from
// linked list.
#include <bits/stdc++.h>
using namespace std;

/* structure for a node */
class Node {
public:
	int data;
	Node* next;
};

/* Function to insert a node at the beginning of
a Circular linked list */
void push(Node** head_ref, int data)
{
	// Create a new node and make head as next
	// of it.
	Node* ptr1 = new Node();
	ptr1->data = data;
	ptr1->next = *head_ref;

	/* If linked list is not NULL then set the
	next of last node */
	if (*head_ref != NULL)
	{
		// Find the node before head and update
		// next of it.
		Node* temp = *head_ref;
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; /*For the first node */

	*head_ref = ptr1;
}

/* Function to print nodes in a given
circular linked list */
void printList(Node* head)
{
	Node* temp = head;
	if (head != NULL) {
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
	}

	cout << endl;
}

/* Function to delete a given node from the list */
void deleteNode(Node** head, int key)
{
	
	// If linked list is empty
	if (*head == NULL)
		return;
		
	// If the list contains only a single node
	if((*head)->data==key && (*head)->next==*head)
	{
		free(*head);
		*head=NULL;
		return;
	}
	
	Node *last=*head,*d;
	
	// If head is to be deleted
	if((*head)->data==key)
	{
		
		// Find the last node of the list
		while(last->next!=*head)
			last=last->next;
			
		// Point last node to the next of head i.e.
		// the second node of the list
		last->next=(*head)->next;
		free(*head);
		*head=last->next;
	return;
	}
	
	// Either the node to be deleted is not found
	// or the end of list is not reached
	while(last->next!=*head&&last->next->data!=key)
	{
		last=last->next;
	}
	
	// If node to be deleted was found
	if(last->next->data==key)
	{
		d=last->next;
		last->next=d->next;
		free(d);
	}
	else
		cout<<"no such keyfound";
	}

/* Driver code */
int main()
{
	/* Initialize lists as empty */
	Node* head = NULL;

	/* Created linked list will be 2->5->7->8->10 */
	push(&head, 2);
	push(&head, 5);
	push(&head, 7);
	push(&head, 8);
	push(&head, 10);

	cout << "List Before Deletion: ";
	printList(head);

	deleteNode(&head, 7);

	cout << "List After Deletion: ";
	printList(head);

	return 0;
}
```
Output<br />
<pre>
List Before Deletion: 10 8 7 5 2 
List After Deletion: 10 8 5 2 
</pre>
<pre>
Time Complexity: O(n)
Worst case occurs when the element to be deleted is the last element and we need to move through the whole list.
Auxiliary Space: O(1)
As constant extra space is used.
</pre>
	
	
	
	
	
	
	
	
	
	
<br /><br /><br />
## Problem 20:
**[Reverse a Doubly Linked List](https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1)**<br />
Given a `doubly linked list` of `n` elements. The task _is to reverse the doubly linked list_.<br />

<pre>
Example 1:
Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
</pre>
<pre>
Example 2:
Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75
</pre>
	
**Your Task:**<br />
Your task is to complete the given function `reverseDLL()`, which takes head reference as argument and should reverse the elements so that the tail becomes the new head and all pointers are correctly pointed. You need to return _the new head of the reversed list_. The printing and verification is done by the driver code.<br />

<pre>
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).
</pre>
	
* Constraints: `1 <= number of nodes <= 10^3`<br />
`0 <= value of nodes <= 10^3`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}

void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
}


int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}

bool verify(Node* head)
{
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}

Node* reverseDLL(Node * head)
{
    
    //Your code here
    if(head == NULL || head->next == NULL)
    return head;
    
    Node *prev = NULL, *curr = head;
    
    while(curr != NULL){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        
        curr = curr->prev;
    }
    
    return prev->prev;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Node *head=NULL, *tail=NULL;
        int x;
        cin>>x;
        head = newNode(x);
        tail = head;
        
        for(int i=0;i<n - 1;i++)
        {
            cin>>x;
            Node* temp=newNode(x);
            tail->next=temp;
            temp->prev= tail;
            tail = temp;
        }
        head=reverseDLL(head);
        
        
        if(verify(head))
        displayList(head);
        else
        cout<<"Your pointers are not correctly connected";
 
        cout<<endl;
    }
    return 0;
}
```
	
	
	
	
	
	
	
	
	
	
	

<br /><br /><br />
## Problem 21:
**[Find pairs with given sum in doubly linked list](https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/)**<br />
Given a sorted `doubly linked list` of **positive distinct elements**, the task is to find pairs in a `doubly-linked list` whose sum is equal to given value `x`, **without using any extra space?**<br />
Example:<br /> 
<pre>
Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)
</pre>
<pre>
The expected time complexity is O(n) and auxiliary space is O(1).
</pre>
A `simple approach` for this problem is to one by one pick each node and find a second element whose **sum** is equal to `x` in the remaining list by traversing in the forward direction. The `time complexity` for this problem will be `O(n^2)`, `n` is the total number of nodes in the `doubly linked list`.<br />
<pre>
An efficient solution algorithm :  

 1. Initialize two pointer variables to find the candidate elements in the sorted doubly linked list. 
    Initialize first with the start of the doubly linked list i.e; first=head and initialize second 
    with the last node of the doubly linked list i.e; second=last_node.
    
 2. We initialize first and second pointers as first and last nodes. Here we don’t have random access, 
    so to find the second pointer, we traverse the list to initialize the second.
    
 3. If current sum of first and second is less than x, then we move first in forward direction. 
    If current sum of first and second element is greater than x, then we move second in backward direction.
    
 4. Loop termination conditions are also different from arrays. The loop terminates when two pointers 
    cross each other (second->next = first), or they become the same (first == second).
    
 5. The case when no pairs are present will be handled by the condition “first==second”
</pre>
`Implementation:`<br />
```cpp
// C++ program to find a pair with given sum x.
#include<bits/stdc++.h>
using namespace std;

// structure of node of doubly linked list
struct Node
{
	int data;
	struct Node *next, *prev;
};

// Function to find pair whose sum equal to given value x.
void pairSum(struct Node *head, int x)
{
	// Set two pointers, first to the beginning of DLL
	// and second to the end of DLL.
	struct Node *first = head;
	struct Node *second = head;
	while (second->next != NULL)
		second = second->next;

	// To track if we find a pair or not
	bool found = false;

	// The loop terminates when two pointers
	// cross each other (second->next
	// == first), or they become same (first == second)
	while (first != second && second->next != first)
	{
		// pair found
		if ((first->data + second->data) == x)
		{
			found = true;
			cout << "(" << first->data<< ", "
				<< second->data << ")" << endl;

			// move first in forward direction
			first = first->next;

			// move second in backward direction
			second = second->prev;
		}
		else
		{
			if ((first->data + second->data) < x)
				first = first->next;
			else
				second = second->prev;
		}
	}

	// if pair is not present
	if (found == false)
		cout << "No pair found";
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node **head, int data)
{
	struct Node *temp = new Node;
	temp->data = data;
	temp->next = temp->prev = NULL;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Driver program
int main()
{
	struct Node *head = NULL;
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);
	int x = 7;

	pairSum(head, x);

	return 0;
}
```
Output<br />
<pre>
(1, 6)
(2, 5)
</pre>
<pre>
Time complexity : O(n) 
Auxiliary space : O(1)

If linked list is not sorted, then we can sort the list as a first step. 
But in that case overall time complexity would become O(n Log n). 
We can use Hashing in such cases if extra space is not a constraint.
</pre>












<br /><br /><br />
## Problem 22:
**[Count triplets in a sorted doubly linked list whose sum is equal to a given value x](https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/)**<br />
Given a **sorted** `doubly linked list` of **distinct nodes**(no two nodes have the same data) and a value `x`. Count triplets in the list that sum up to a given value `x`.<br />
Examples:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/dll7.jpg"><br />
<br />`Method 1 (Naive Approach):`<br /> 
Using **three nested loops** generate all triplets and check whether elements in the triplet sum up to `x` or not.<br />
```cpp
// C++ implementation to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
#include <bits/stdc++.h>

using namespace std;

// structure of node of doubly linked list
struct Node {
	int data;
	struct Node* next, *prev;
};

// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int countTriplets(struct Node* head, int x)
{
	struct Node* ptr1, *ptr2, *ptr3;
	int count = 0;

	// generate all possible triplets
	for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
		for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
			for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)

				// if elements in the current triplet sum up to 'x'
				if ((ptr1->data + ptr2->data + ptr3->data) == x)

					// increment count
					count++;

	// required count of triplets
	return count;
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node** head, int data)
{
	// allocate node
	struct Node* temp = new Node();

	// put in the data
	temp->data = data;
	temp->next = temp->prev = NULL;

	if ((*head) == NULL)
		(*head) = temp;
	else {
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Driver program to test above
int main()
{
	// start with an empty doubly linked list
	struct Node* head = NULL;

	// insert values in sorted order
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);

	int x = 17;

	cout << "Count = "
		<< countTriplets(head, x);
	return 0;
}
```
Output:<br />
<pre>
Count = 2
</pre>
<pre>
Time Complexity: O(n^3) 
Auxiliary Space: O(1)
</pre>
<br />`Method 2 (Hashing):`<br /> 
Create a `hash table` with `(key, value)` tuples represented as `(node data, node pointer)` tuples. Traverse the `doubly linked list` and store each node’s data and its pointer `pair(tuple)` in the hash table. Now, generate each possible pair of nodes. For each pair of nodes, calculate the `p_sum(sum of data in the two nodes)` and check whether `(x-p_sum)` exists in the hash table or not. If it exists, then also verify that the two nodes in the pair are not same to the node associated with `(x-p_sum)` in the hash table and finally increment count. Return `(count / 3)` as each triplet is counted `3` times in the above process.<br />
```cpp
// C++ implementation to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
#include <bits/stdc++.h>
using namespace std;

// structure of node of doubly linked list
struct Node {
	int data;
	struct Node* next, *prev;
};

// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int countTriplets(struct Node* head, int x)
{
	struct Node* ptr, *ptr1, *ptr2;
	int count = 0;

	// unordered_map 'um' implemented as hash table
	unordered_map<int, Node*> um;

	// insert the <node data, node pointer> tuple in 'um'
	for (ptr = head; ptr != NULL; ptr = ptr->next)
		um[ptr->data] = ptr;

	// generate all possible pairs
	for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
		for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {

			// p_sum - sum of elements in the current pair
			int p_sum = ptr1->data + ptr2->data;

			// if 'x-p_sum' is present in 'um' and either of the two nodes
			// are not equal to the 'um[x-p_sum]' node
			if (um.find(x - p_sum) != um.end() && um[x - p_sum] != ptr1
				&& um[x - p_sum] != ptr2)

				// increment count
				count++;
		}

	// required count of triplets
	// division by 3 as each triplet is counted 3 times
	return (count / 3);
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node** head, int data)
{
	// allocate node
	struct Node* temp = new Node();

	// put in the data
	temp->data = data;
	temp->next = temp->prev = NULL;

	if ((*head) == NULL)
		(*head) = temp;
	else {
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Driver program to test above
int main()
{
	// start with an empty doubly linked list
	struct Node* head = NULL;

	// insert values in sorted order
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);

	int x = 17;

	cout << "Count = "
		<< countTriplets(head, x);
	return 0;
}
```
Output:<br />
<pre>
Count = 2
</pre>
<pre>
Time Complexity: O(n^2) 
Auxiliary Space: O(n)
</pre>
<br />`Method 3 Efficient Approach(Use of two pointers):`<br /> 
Traverse the `doubly linked list` from `left` to `right`. For each current node during the traversal, initialize two pointers `first = pointer to the node next` to the **current node** and `last = pointer to the last node` of the list. Now, count pairs in the list from first to last pointer that sum up to value `(x – current node’s data)`. Add this count to the `total_count of triplets`. Pointer to the last node can be found only once in the beginning.<br />
```cpp
// C++ implementation to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
#include <bits/stdc++.h>
using namespace std;

// structure of node of doubly linked list
struct Node {
	int data;
	struct Node* next, *prev;
};

// function to count pairs whose sum equal to given 'value'
int countPairs(struct Node* first, struct Node* second, int value)
{
	int count = 0;

	// The loop terminates when either of two pointers
	// become NULL, or they cross each other (second->next
	// == first), or they become same (first == second)
	while (first != NULL && second != NULL &&
		first != second && second->next != first) {

		// pair found
		if ((first->data + second->data) == value) {

			// increment count
			count++;

			// move first in forward direction
			first = first->next;

			// move second in backward direction
			second = second->prev;
		}

		// if sum is greater than 'value'
		// move second in backward direction
		else if ((first->data + second->data) > value)
			second = second->prev;

		// else move first in forward direction
		else
			first = first->next;
	}

	// required count of pairs
	return count;
}

// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int countTriplets(struct Node* head, int x)
{
	// if list is empty
	if (head == NULL)
		return 0;

	struct Node* current, *first, *last;
	int count = 0;

	// get pointer to the last node of
	// the doubly linked list
	last = head;
	while (last->next != NULL)
		last = last->next;

	// traversing the doubly linked list
	for (current = head; current != NULL; current = current->next) {

		// for each current node
		first = current->next;

		// count pairs with sum(x - current->data) in the range
		// first to last and add it to the 'count' of triplets
		count += countPairs(first, last, x - current->data);
	}

	// required count of triplets
	return count;
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node** head, int data)
{
	// allocate node
	struct Node* temp = new Node();

	// put in the data
	temp->data = data;
	temp->next = temp->prev = NULL;

	if ((*head) == NULL)
		(*head) = temp;
	else {
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Driver program to test above
int main()
{
	// start with an empty doubly linked list
	struct Node* head = NULL;

	// insert values in sorted order
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);

	int x = 17;

	cout << "Count = "
		<< countTriplets(head, x);
	return 0;
}
```
Output:<br /> 
<pre>
Count = 2
</pre>
<pre>
Time Complexity: O(n^2) 
Auxiliary Space: O(1)
</pre>













<br /><br /><br />
## Problem 23:
**[Sort a “k”sorted Doubly Linked list.[Very IMP]](https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/)**<br />
Given a `doubly linked list` containing `n` nodes, where each node is at most `k` away from its target position in the list. The problem is to sort the given `doubly linked list`.<br />
For example, let us consider `k` is `2`, a node at position `7` in the sorted `doubly linked list`, can be at positions `5, 6, 7, 8, 9` in the given `doubly linked list`.<br />
Examples:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/dll15.jpg"><br />
<br />`Naive Approach:`<br />
Sort the given `doubly linked list` using the **insertion sort technique**. While `inserting` each element in the sorted part of the list, there will be at most `k` swaps to place the element to its correct position since it is at most `k` steps away from its correct position.<br />
Implementation:<br />
```cpp
// C++ implementation to sort a k sorted doubly
// linked list
#include<bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};


// function to sort a k sorted doubly linked list
struct Node* sortAKSortedDLL(struct Node* head, int k)
{
	if(head == NULL || head->next == NULL)
		return head;

	// perform on all the nodes in list
	for(Node *i = head->next; i != NULL; i = i->next) {
		Node *j = i;
		// There will be atmost k swaps for each element in the list
		// since each node is k steps away from its correct position
		while(j->prev != NULL && j->data < j->prev->data) {
			// swap j and j.prev node
			Node* temp = j->prev->prev;
			Node* temp2 = j->prev;
			Node *temp3 = j->next;
			j->prev->next = temp3;
			j->prev->prev = j;
			j->prev = temp;
			j->next = temp2;
			if(temp != NULL)
				temp->next = j;
			if(temp3 != NULL)
				temp3->prev = temp2;
		}
		// if j is now the new head
	// then reset head
		if(j->prev == NULL)
			head = j;
	}
	return head;
}

// Function to insert a node at the beginning
// of the Doubly Linked List
void push(struct Node** head_ref, int new_data)
{
	// allocate node
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	// put in the data
	new_node->data = new_data;

	// since we are adding at the beginning,
	// prev is always NULL
	new_node->prev = NULL;

	// link the old list off the new node
	new_node->next = (*head_ref);

	// change prev of head node to new node
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	// move the head to point to the new node
	(*head_ref) = new_node;
}

// Function to print nodes in a given doubly linked list
void printList(struct Node* head)
{
	// if list is empty
	if (head == NULL)
		cout << "Doubly Linked list empty";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	struct Node* head = NULL;

	// Create the doubly linked list:
	// 3<->6<->2<->12<->56<->8
	push(&head, 8);
	push(&head, 56);
	push(&head, 12);
	push(&head, 2);
	push(&head, 6);
	push(&head, 3);

	int k = 2;

	cout << "Original Doubly linked list:\n";
	printList(head);

	// sort the biotonic DLL
	head = sortAKSortedDLL(head, k);

	cout << "\nDoubly linked list after sorting:\n";
	printList(head);

	return 0;
}
```
Output<br />
<pre>
Original Doubly linked list:
3 6 2 12 56 8 
Doubly Linked List after sorting:
2 3 6 8 12 56 
</pre>
<pre>
Time Complexity: O(n*k)
Auxiliary Space: O(1)
</pre>
<br />`Efficient Approach:`<br />
We can sort the list using the `MIN HEAP data structure`. The approach has been explained in Sort a nearly sorted (or `K sorted`) array. We only have to be careful while traversing the input `doubly linked list` and adjusting the required next and previous links in the final sorted list.<br />
Implementation:<br />
```cpp
// C++ implementation to sort a k sorted doubly
// linked list
#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

// 'compare' function used to build up the
// priority queue
struct compare {
	bool operator()(struct Node* p1, struct Node* p2)
	{
		return p1->data > p2->data;
	}
};

// function to sort a k sorted doubly linked list
struct Node* sortAKSortedDLL(struct Node* head, int k)
{
	// if list is empty
	if (head == NULL)
		return head;

	// priority_queue 'pq' implemented as min heap with the
	// help of 'compare' function
	priority_queue<Node*, vector<Node*>, compare> pq;

	struct Node* newHead = NULL, *last;

	// Create a Min Heap of first (k+1) elements from
	// input doubly linked list
	for (int i = 0; head != NULL && i <= k; i++) {
		// push the node on to 'pq'
		pq.push(head);

		// move to the next node
		head = head->next;
	}

	// loop till there are elements in 'pq'
	while (!pq.empty()) {

		// place root or top of 'pq' at the end of the
		// result sorted list so far having the first node
		// pointed to by 'newHead'
		// and adjust the required links
		if (newHead == NULL) {
			newHead = pq.top();
			newHead->prev = NULL;

			// 'last' points to the last node
			// of the result sorted list so far
			last = newHead;
		}

		else {
			last->next = pq.top();
			pq.top()->prev = last;
			last = pq.top();
		}

		// remove element from 'pq'
		pq.pop();

		// if there are more nodes left in the input list
		if (head != NULL) {
			// push the node on to 'pq'
			pq.push(head);

			// move to the next node
			head = head->next;
		}
	}

	// making 'next' of last node point to NULL
	last->next = NULL;

	// new head of the required sorted DLL
	return newHead;
}

// Function to insert a node at the beginning
// of the Doubly Linked List
void push(struct Node** head_ref, int new_data)
{
	// allocate node
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	// put in the data
	new_node->data = new_data;

	// since we are adding at the beginning,
	// prev is always NULL
	new_node->prev = NULL;

	// link the old list off the new node
	new_node->next = (*head_ref);

	// change prev of head node to new node
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	// move the head to point to the new node
	(*head_ref) = new_node;
}

// Function to print nodes in a given doubly linked list
void printList(struct Node* head)
{
	// if list is empty
	if (head == NULL)
		cout << "Doubly Linked list empty";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	struct Node* head = NULL;

	// Create the doubly linked list:
	// 3<->6<->2<->12<->56<->8
	push(&head, 8);
	push(&head, 56);
	push(&head, 12);
	push(&head, 2);
	push(&head, 6);
	push(&head, 3);

	int k = 2;

	cout << "Original Doubly linked list:\n";
	printList(head);

	// sort the biotonic DLL
	head = sortAKSortedDLL(head, k);

	cout << "\nDoubly linked list after sorting:\n";
	printList(head);

	return 0;
}
```
Output<br />
<pre>
Original Doubly linked list:
3 6 2 12 56 8 
Doubly linked list after sorting:
2 3 6 8 12 56 
</pre>
<pre>
Time Complexity: O(n*log k)
Auxiliary Space: O(k)
</pre>











<br /><br /><br />
## Problem 24:
**[Rotate Doubly linked list by N nodes](https://www.geeksforgeeks.org/rotate-doubly-linked-list-n-nodes/)**<br />
Given a `doubly-linked list`, rotate the `linked list` counter-clockwise by `N` nodes. Here `N` is a given positive integer and is smaller than the count of nodes in linked list.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/doublylinkedlist-1-1.png"><br />
N = 2<br />
Rotated List:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/doublylinkedlist-1.png"><br />
Examples:<br />
<pre>
Input : a  b  c  d  e   N = 2
Output : c  d  e  a  b 

Input : a  b  c  d  e  f  g  h   N = 4
Output : e  f  g  h  a  b  c  d 
</pre>

 1. To rotate the `Doubly linked list`, first, we need to traverse through the linked list and find the address of the last node.<br /> 
 2. Then make it a `circular linked list`.<br />
 3. Then move the head as well as a temp by `n` nodes.<br />
 4. Then make the linked list as `un-circular`.<br />

<br />`Solution 1:`<br />
```cpp
#include<iostream>
using namespace std;

class Node
{
	public:
		char data;
		Node* next;
		Node* pre;
	Node(int data)
	{
		this->data=data;
		pre=NULL;
		next=NULL;
	}
};

void insertAtHead(Node* &head, int data)
{
	Node* n = new Node(data);
	if(head==NULL)
	{
		head=n;
		return;
	}
	n->next=head;
	head->pre=n;
	head=n;
	return;
}
void insertAtTail(Node* &head, int data)
{
	if(head==NULL)
	{
		insertAtHead(head,data);
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	Node* n=new Node(data);
	temp->next=n;
	n->pre=temp;
	return;
}
void display(Node* head)
{
	while(head!=NULL)
	{
		cout << head->data << "-->";
		head=head->next;
	}
	cout << "NULL\n";
}

void rotateByN(Node* &head, int pos)
{
	// return without any changes if position is 0.
	if(pos==0) return;

	// Finding last node.
	Node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	// making the list circular.
	temp->next=head;
	head->pre=temp;

	// move head and temp by the given position.
	int count=1;
	while(count<=pos)
	{
		head=head->next;
		temp=temp->next;
		count++;
	}

	// now again make list un-circular.
	temp->next=NULL;
	head->pre=NULL;
}
int main()
{
	Node* head=NULL;
	insertAtTail(head,'a');
	insertAtTail(head,'b');
	insertAtTail(head,'c');
	insertAtTail(head,'d');
	insertAtTail(head,'e');

	int n=2;
	cout << "\nBefore Rotation : \n";
	display(head);
	rotateByN(head,n);
	cout << "\nAfter Rotation : \n";
	display(head);
	cout << "\n\n";

	return 0;
}
```
Output<br />
<pre>
Before Rotation : 
a-->b-->c-->d-->e-->NULL

After Rotation : 
c-->d-->e-->a-->b-->NULL
</pre>
<pre>
Time Complexity: O(N)
Space Complexity: O(1)
</pre>
<br />`Solution 2:`<br />
```cpp
#include<iostream>
using namespace std;

class Node
{
	public:
		char data;
		Node* next;
		Node* pre;
	Node(int data)
	{
		this->data=data;
		pre=NULL;
		next=NULL;
	}
};

void insertAtHead(Node* &head, int data)
{
	Node* n = new Node(data);
	if(head==NULL)
	{
		head=n;
		return;
	}
	n->next=head;
	head->pre=n;
	head=n;
	return;
}
void insertAtTail(Node* &head, int data)
{
	if(head==NULL)
	{
		insertAtHead(head,data);
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	Node* n=new Node(data);
	temp->next=n;
	n->pre=temp;
	return;
}
void display(Node* head)
{
	while(head!=NULL)
	{
		cout << head->data << "-->";
		head=head->next;
	}
	cout << "NULL\n";
}

void rotateByN(Node *&head, int pos)
{
	if (pos == 0)
		return;

	Node *curr = head;

	while (pos)
	{
		curr = curr->next;
		pos--;
	}

	Node *tail = curr->pre;
	Node *NewHead = curr;
	tail->next = NULL;
	curr->pre = NULL;

	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	
	curr->next = head;
	head->pre = curr;
	head = NewHead;
}

int main()
{
	Node* head=NULL;
	insertAtTail(head,'a');
	insertAtTail(head,'b');
	insertAtTail(head,'c');
	insertAtTail(head,'d');
	insertAtTail(head,'e');

	int n=2;
	cout << "\nBefore Rotation : \n";
	display(head);
	rotateByN(head,n);
	cout << "\nAfter Rotation : \n";
	display(head);
	cout << "\n\n";

	return 0;
}
```
Output<br />
<pre>
Before Rotation : 
a-->b-->c-->d-->e-->NULL

After Rotation : 
c-->d-->e-->a-->b-->NULL
</pre>
<pre>
Time Complexity: O(N)
Space Complexity: O(1)
</pre>












<br /><br /><br />
## Problem 25:
**[Rotate a Doubly Linked list in group of Given Size.[Very IMP]](https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/)**<br />
Given a `doubly linked list` containing `n` nodes. The problem is to reverse every group of `k` nodes in the list.<br />
Examples:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/rev_dll_in_group_of_size_k.jpg"><br />
**Approach:**<br />
Create a `recursive function` say `reverse(head, k)`. This function receives the `head` or the first node of each group of `k` nodes. It reverses those groups of `k` nodes by applying the approach discussed in `Reverse a doubly linked list`. After reversing the group of `k` nodes the function checks whether next group of nodes exists in the list or not. If a group exists then it makes a `recursive call` to itself with the first node of the next group and makes the necessary adjustments with the next and previous links of that group. Finally, it returns the new head node of the reversed group.<br />
```cpp
// C++ implementation to reverse a doubly linked list
// in groups of given size
#include <bits/stdc++.h>

using namespace std;

// a node of the doubly linked list
struct Node {
	int data;
	Node *next, *prev;
};

// function to get a new node
Node* getNode(int data)
{
	// allocate space
	Node* new_node = (Node*)malloc(sizeof(Node));

	// put in the data
	new_node->data = data;
	new_node->next = new_node->prev = NULL;
	return new_node;
}

// function to insert a node at the beginning
// of the Doubly Linked List
void push(Node** head_ref, Node* new_node)
{
	// since we are adding at the beginning,
	// prev is always NULL
	new_node->prev = NULL;

	// link the old list off the new node
	new_node->next = (*head_ref);

	// change prev of head node to new node
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	// move the head to point to the new node
	(*head_ref) = new_node;
}

// function to reverse a doubly linked list
// in groups of given size
Node* revListInGroupOfGivenSize(Node* head, int k)
{
	Node *current = head;
	Node* next = NULL;
	Node* newHead = NULL;
	int count = 0;
	
	// reversing the current group of k
	// or less than k nodes by adding
	// them at the beginning of list
	// 'newHead'
	while (current != NULL && count < k)
	{
		next = current->next;
		push(&newHead, current);
		current = next;
		count++;
	}
	
	// if next group exists then making the desired
	// adjustments in the link
	if (next != NULL)
	{
		head->next = revListInGroupOfGivenSize(next, k);
		head->next->prev = head;
	}
	
	// pointer to the new head of the
	// reversed group
	// pointer to the new head should point to NULL, otherwise you won't be able to traverse list in reverse order using 'prev'
	newHead->prev = NULL;
	return newHead;
}

// Function to print nodes in a
// given doubly linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	// Start with the empty list
	Node* head = NULL;

	// Create doubly linked: 10<->8<->4<->2
	push(&head, getNode(2));
	push(&head, getNode(4));
	push(&head, getNode(8));
	push(&head, getNode(10));
	
	int k = 2;

	cout << "Original list: ";
	printList(head);

	// Reverse doubly linked list in groups of
	// size 'k'
	head = revListInGroupOfGivenSize(head, k);

	cout << "\nModified list: ";
	printList(head);

	return 0;
}
```
Output<br />
<pre>
Original list: 10 8 4 2 
Modified list: 8 10 2 4 
</pre>
<pre>
Time Complexity: O(n).
</pre>
We can further simplify the implementation of this algorithm using the same idea with `recursion` in just one function.<br />
```cpp
#include <iostream>
using namespace std;
struct Node {
	int data;
	Node *next, *prev;
};
// function to add Node at the end of a Doubly LinkedList
Node* insertAtEnd(Node* head, int data)
{

	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	Node* temp = head;
	if (head == NULL) {
		new_node->prev = NULL;
		head = new_node;
		return head;
	}

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
	return head;
}
// function to print Doubly LinkedList
void printDLL(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
// function to Reverse a doubly linked list
// in groups of given size
Node* reverseByN(Node* head, int k)
{
	if (!head)
		return NULL;
	head->prev = NULL;
	Node *temp, *curr = head, *newHead;
	int count = 0;
	while (curr != NULL && count < k) {
		newHead = curr;
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
		count++;
	}
	// checking if the reversed LinkedList size is
	// equal to K or not
	// if it is not equal to k that means we have reversed
	// the last set of size K and we don't need to call the
	// recursive function
	if (count >= k) {
		Node* rest = reverseByN(curr, k);
		head->next = rest;
		if (rest != NULL)
			// it is required for prev link otherwise u wont
			// be backtrack list due to broken links
			rest->prev = head;
	}
	return newHead;
}
int main()
{
	Node* head;
	for (int i = 1; i <= 10; i++) {
		head = insertAtEnd(head, i);
	}
	printDLL(head);
	int n = 4;
	head = reverseByN(head, n);
	printDLL(head);
}
```
Output<br />
<pre>
1 2 3 4 5 6 7 8 9 10 
4 3 2 1 8 7 6 5 10 9 
</pre>
<br />`Another approach (Iterative Method) :`<br />  
Here we will be using the `iterative method` in which we will begin from head node and reverse `k` nodes in the group. After reversing the `k` nodes we will continue this process with the next node after the `k` node until it becomes `null`. We will the achieving the desired result in only a single pass of the linked list with the `time complexity of O(n)` and `space complexity of O(1)`.<br />
```cpp
// C++ implementation to reverse a doubly linked list
// in groups of given size without recursion
// Iterative Method

#include <iostream>
using namespace std;

// Represents a node of doubly linked list
struct Node {
	int data;
	Node *next, *prev;
};

// function to get a new node
Node* getNode(int data)
{
	// allocating node
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = new_node->prev = NULL;

	return new_node;
}

// function to insert a node at the beginning
// of the Doubly Linked List
Node* push(Node* head, Node* new_node)
{
	// since we are adding at the beginning,
	// prev is always NULL
	new_node->prev = NULL;

	// link the old list off the new node
	new_node->next = head;
	// change prev of head node to new node
	if (head != NULL)
		head->prev = new_node;

	// move the head to point to the new node
	head = new_node;
	return head;
}

// function to reverse a doubly linked list
// in groups of given size
Node* revListInGroupOfGivenSize(Node* head, int k)
{
	if (!head)
		return head;

	Node* st = head;
	Node* globprev = NULL;
	Node* ans = NULL;
	while (st) {
		int count = 1; // to count k nodes
		Node* curr = st;
		Node* prev = NULL;
		Node* next = NULL;
		while (curr && count <= k) { // reversing k nodes
			next = curr->next;
			curr->prev = next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count++;
		}

		if (!ans) {
			ans = prev; // to store ans i.e the new head
			ans->prev = NULL;
		}

		if (!globprev)
			globprev = st; // assigning the last node of the
						// reversed k nodes
		else {
			globprev->next = prev;
			prev->prev
				= globprev; // connecting last node of last
							// k group to the first node of
							// present k group
			globprev = st;
		}

		st = curr; // advancing the pointer for the next k
				// group
	}
	return ans;
}

// Function to print nodes in a
// given doubly linked list
void printList(Node* head)
{
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver code
int main()
{
	// Start with the empty list
	Node* head = NULL;

	// Create doubly linked: 10<->8<->4<->2
	head = push(head, getNode(2));
	head = push(head, getNode(4));
	head = push(head, getNode(8));
	head = push(head, getNode(10));

	int k = 2;

	cout << "Original list: ";
	printList(head);

	// Reverse doubly linked list in groups of
	// size 'k'
	head = revListInGroupOfGivenSize(head, k);

	cout << "\nModified list: ";
	printList(head);
	return 0;
}
```
Output<br />
<pre>
Original list: 10 8 4 2 
Modified list: 8 10 2 4 
</pre>
<pre>
Time Complexity: O(n) , where n is the number of nodes in the original list
Auxiliary Space: O(1)
</pre>












<br /><br /><br />
## Problem 26:
**[Can we reverse a linked list in less than O(n)?](https://www.geeksforgeeks.org/can-we-reverse-a-linked-list-in-less-than-on/#:~:text=It%20is%20not%20possible%20to,recursive%20and%20iterative%20methods.)**<br />
<br />It is `not possible` to reverse a `simple singly linked list` in less than `O(n)`. A simple `singly linked list can only be reversed in O(n) time using recursive and iterative methods`.<br />
A `doubly linked list` with head and tail pointers while only requiring swapping the head and tail pointers which require lesser operations than a singly linked list can also not be done in `less than O(n)` since we need to traverse till the end of the list anyway to find the tail node.<br />














<br /><br /><br />
## Problem 27:
**[Why Quick Sort preferred for Arrays and Merge Sort for Linked Lists?](https://www.geeksforgeeks.org/why-quick-sort-preferred-for-arrays-and-merge-sort-for-linked-lists/)**<br />
<br />`Why is Quick Sort preferred for arrays?`<br />
<pre>
 1. Quick Sort in its general form is an in-place sort (i.e. it doesn’t require any extra storage) 
    whereas merge sort requires O(N) extra storage, N denoting the array size which may be 
    quite expensive. Allocating and de-allocating the extra space used for merge sort increases 
    the running time of the algorithm.
 2. Comparing average complexity we find that both type of sorts have O(NlogN) average 
    complexity but the constants differ. For arrays, merge sort loses due to the use of extra O(N) 
    storage space. 
 3. Most practical implementations of Quick Sort use randomized version. The randomized 
    version has expected time complexity of O(nLogn). The worst case is possible in randomized 
    version also, but worst case doesn’t occur for a particular pattern (like sorted array) and 
    randomized Quick Sort works well in practice.
 4. Quick Sort is also a cache friendly sorting algorithm as it has good locality of reference when 
    used for arrays.
 5. Quick Sort is also tail recursive, therefore tail call optimizations is done.
</pre>
<br />`Why is Merge Sort preferred for Linked Lists?`<br />
<pre>
 1. In case of linked lists the case is different mainly due to difference in memory allocation of 
    arrays and linked lists. Unlike arrays, linked list nodes may not be adjacent in memory.
 2. Unlike array, in linked list, we can insert items in the middle in O(1) extra space and O(1) time 
    if we are given reference/pointer to the previous node. Therefore merge operation of merge 
    sort can be implemented without extra space for linked lists.
 3. In arrays, we can do random access as elements are continuous in memory. Let us say we 
    have an integer (4-byte) array A and let the address of A[0] be x then to access A[i], we can 
    directly access the memory at (x + i*4). Unlike arrays, we can not do random access in linked list.
 4. Quick Sort requires a lot of this kind of access. In linked list to access i’th index, we have to 
    travel each and every node from the head to i’th node as we don’t have continuous block of memory. 
    Therefore, the overhead increases for quick sort. Merge sort accesses data sequentially and 
    the need of random access is low.
</pre>















<br /><br /><br />
## Problem 28:
**[Flattening a Linked List](https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1)**<br />
Given a `Linked List` of size `N`, where every node represents a `sub-linked-list` and contains two pointers:<br />
  
  * (i) a next pointer to the next node,<br />
  * (ii) a bottom pointer to a `linked list` where this node is head.<br />

Each of the `sub-linked-list` is in sorted order.<br />
Flatten the Link List such that all the nodes appear in a `single level` while maintaining the **sorted order**.<br />

**Note:**<br />
The flattened list will be printed using the **bottom pointer** instead of next pointer. For more clearity have a look at the `printList()` function in the driver code.<br />

<pre>
Example 1:
Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every node in a single level.

(Note: | represents the bottom pointer.)
</pre>
<pre>
Example 2:
Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->22->28->30->50
Explanation:
The resultant linked lists has every node in a single level.

(Note: | represents the bottom pointer.)
</pre> 
 
**Your Task:**<br />
You do not need to read input or print anything. Complete the function `flatten()` that takes the `head of the linked list` as input parameter and returns _the head of flattened link list_.<br />
 
<pre>
Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `0 <= N <= 50`<br />
`1 <= Mi <= 20`<br />
`1 <= Element of linked list <= 10^3`<br />

```cpp
#include <bits/stdc++.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
    
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

    int t;
    cin>>t;
    while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
    struct Node * head=NULL;
    struct Node * pre=NULL;
    struct Node * tempB=NULL;
    struct Node * preB=NULL;
        cin>>n;
        int work[n];
        for(int i=0;i<n;i++)
            cin>>work[i];
        for(int i=0;i<n;i++){
            m=work[i];
            --m;
            int data;
            scanf("%d",&data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;
            
            if(flag){
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else{
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for(int j=0;j<m;j++){
                
                int temp_data;
                scanf("%d",&temp_data);
                tempB = new Node(temp_data);

                if(flag1){
                    temp->bottom=tempB;
                    preB=tempB;
                    flag1=0;
                }
                else{
                    preB->bottom=tempB;
                    preB=tempB;
                }
            }
        }
           Node *fun = head;
           Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

    }
    return 0;
}

Node* merge( Node* a, Node* b )
{

    if (a == NULL)
        return b;


    if (b == NULL)
        return a;

    Node* result;
    if (a->data < b->data)
    {
        result = a;
        result->bottom = merge( a->bottom, b );
    }
    else
    {
        result = b;
        result->bottom = merge( a, b->bottom );
    }

    return result;
}

Node* flatten (Node* root)
{
    // Base cases
    if (root == NULL || root->next == NULL)
        return root;
    return merge( root, flatten(root->next) );
}
```












<br /><br /><br />
## Problem 29:
**[Given a linked list of 0s, 1s and 2s, sort it](https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1)**<br />
Given a `linked list` of `N` nodes where nodes can contain values `0s`, `1s`, and `2s` only. The task is to segregate `0s`, `1s`, and `2s` linked list such that all **zeros segregate** to head side, `2s` at the end of the linked list, and `1s` in the mid of `0s` and `2s`.<br />

<pre>
Example 1:
Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated to the left end of the linked list, 
2s to the right end of the list, and 1s in between.
</pre>

<pre>
Example 2:
Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.
</pre>

**Your Task:**<br />
The task is to complete the function `segregate()` which segregates the nodes in the `linked list` as asked in the problem statement and returns _the head of the modified linked list_. The printing is done automatically by the driver code.<br />

<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
</pre>

* Constraints: `1 <= N <= 10^3`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(struct Node *head) {
    if (!head || !(head->next))
        return head;
  
    //creating three dummy nodes to point to beginning of three linked lists. 
    Node* zeroD = new Node(0); 
    Node* oneD = new Node(0); 
    Node* twoD = new Node(0); 
  
    //initializing current pointers for three lists. 
    Node* zero = zeroD, *one = oneD, *two = twoD; 
  
    //traversing over the list with a pointer. 
    Node* curr = head; 
    while (curr) { 
        
        //we check data at current node and store the node in it's respective
        //list and update the link part of that list.
        if (curr->data == 0) { 
            zero->next = curr; 
            zero = zero->next; 
            curr = curr->next; 
        }
        else if (curr->data == 1) { 
            one->next = curr; 
            one = one->next; 
            curr = curr->next; 
        } 
        else { 
            two->next = curr; 
            two = two->next; 
            curr = curr->next; 
        } 
    } 
  
    //attaching the three lists containing 0s,1s and 2s respectively.
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next); 
    one->next = twoD->next; 
    two->next = NULL; 
  
    //updating the head of the list.
    head = zeroD->next; 
  
    //deleting dummy nodes.
    delete zeroD; 
    delete oneD; 
    delete twoD; 
  
    return head;
}
};

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
```










<br /><br /><br />
## Problem 30:
**[Clone a linked list with next and random pointer](https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1)**<br />
You are given a `special linked list` with `N` nodes where each node has a next pointer pointing to its next node. You are also given `M` random pointers, where you will be given `M` number of pairs denoting two nodes `a` and `b`  i.e. `a->arb = b`.<br />
Construct a copy of the given list. The copy should consist of exactly `N` new nodes, where each new node has its value set to the value of its corresponding original node. Both the **next and random pointer** of the new nodes should point to new nodes in the copied list such that the pointers in the **original list** and **copied list** represent the same **list state**. None of the pointers in the `new list` should point to nodes in the `original list`.<br />
`For example`, if there are two nodes `X` and `Y` in the original list, where `X.random --> Y`, then for the corresponding two nodes `x` and `y` in the copied list, `x.random --> y`.<br />
Return the `head` of the copied linked list.<br />
<img src = "https://contribute.geeksforgeeks.org/wp-content/uploads/clone.jpg"><br />

<pre>
Example 1:
Input:
N = 4, M = 2
value = {1,2,3,4}
pairs = {{1,2},{2,4}}
Output: 1
Explanation: In this test case, there are 4 nodes in linked list.  Among these
4 nodes,  2 nodes have arbitrary pointer set, rest two nodes have arbitrary pointer
as NULL. Second line tells us the value of four nodes. The third line gives the
information about arbitrary pointers. 
The first node arbitrary pointer is set to node 2.  The second node arbitrary pointer is set to node 4.
</pre>
<pre>
Example 2:
Input:
N = 4, M = 2
value[] = {1,3,5,9}
pairs[] = {{1,1},{3,4}}
Output: 1
Explanation: In the given testcase , applying the method as stated in the above example, the output will be 1.
</pre>

**Your Task:**<br />
The task is to complete the function `copyList()` which takes **one argument the head of the linked list** to be cloned and should return the head of the cloned linked list.<br />

**NOTE :**<br /> 
1. If there is any node whose arbitrary pointer is not given then it's by default `NULL`. <br />
2. Your solution return an output `1` if your clone linked list is correct, else it returns `0`.<br />

<pre>
Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)
</pre>

* Constraints: `1 <= N <= 100`<br />
`1 <= M <= N`<br />
`1 <= a, b <= 100`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

class Solution
{
    public:
    Node *copyList(Node *head)
    {
    if (head == NULL) return head;

    Node *t = head;
    while (t != NULL)
    {
        //making an identical list merged with original list.
        //creating the copy of node 1 and inserting it between node 1 
        //& node 2in original Linked List, creating a copy of 2 and 
        //inserting it between 2 & 3 and continuing this.
        Node *n = new Node(t->data);
        n->next = t->next;
        t->next = n;
        t = n->next;
    }
    
    t = head;
    Node *head2 = head->next;
    while (t != NULL)
    {
        //setting the arbitrary(random) pointers of duplicate list.
        //this works because original->next is nothing but copy of original 
        //and Original->random->next is nothing but copy of random.
        if (t->arb == NULL)
            t->next->arb = NULL;
        else 
            t->next->arb = t->arb->next;
        
        t = t->next->next;
    }
    
    t = head;
    while (t != NULL)
    {
        //separating the 2 merged lists (duplicate and original).
        head = t->next->next;
        
        if(head)
        t->next->next = head->next;
        else 
        t->next->next = NULL;
        
        t->next = head;
        t = head;
    }
    //returning the cloned list.
    return head2;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

void append(Node **head_ref, Node **tail_ref, int new_data) {

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {

    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2) return false;

    temp1 = head;
    temp2 = res;
    map<Node*,Node*> a;
    while (temp1 != NULL) {
        
        if(temp1==temp2)
            return false;
        
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1]=temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (a[temp1->arb] != temp2->arb) return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

int main() {

    int T, i, n, l, k;
    Node *generated_addr = NULL;
     /*reading input stuff*/
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
         for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }

            // when both a is greater than N
            if (a <= n){
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        /*read finished*/

        generated_addr = head;
        Solution ob;
        struct Node *res = ob.copyList(head);
        if(validation(head2,res)&&validation(head,res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
```












<br /><br /><br />
## Problem 31:
**[Merge K sorted linked lists](https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1)**<br />
Given `K` sorted `linked lists` of different sizes. The task _is to merge them in such a way that after merging they will be a single sorted linked list_.<br />

<pre>
Example 1:
Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be 1->2->3->4->5->5->6->7->8.
</pre>

<pre>
Example 2:
Input:
K = 3
value = {{1,3},{4,5,6},{8}}
Output: 1 3 4 5 6 8
Explanation:
The test case has 3 sorted linked list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be 1->3->4->5->6->8.
</pre>

**Your Task:**<br />
The task is to complete the function `mergeKList()` which merges the `K` given lists into a sorted one. The printing is done automatically by the driver code.<br />

<pre>
Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)
Note: n is the maximum size of all the k link list
</pre>

* Constraints: `1 <= K <= 10^3`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout<<endl;
}

class Solution{
  public:
    //Function to merge two sorted list into one sorted list.
    Node* SortedMerge(Node* a, Node* b)
    {
        Node* result = NULL;
    
        //base cases when either of two lists is null.
        if (a == NULL)
            return (b);
        else if(b == NULL)
            return (a);
    
        //comparing data in both lists and storing the smaller in result and
        //recursively calling the SortedMerge function for next node in result.
        if(a->data <= b->data)
        {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        //returning the resultant list.
        return result;
    }
    
    //Function to merge K sorted linked list.
    Node* mergeKLists(Node* arr[], int K)
    {
        int N = K;
        int last=N-1; 
        while (last != 0)
        {
            int i = 0, j = last;
            while (i < j)
            {
                //calling SortedMerge function to merge two different list into
                //one list which has sorted elements.
                arr[i] = SortedMerge(arr[i], arr[j]);
    
                //going for the next pair of lists.
                i++, j--;
    
                //if all pairs are merged, we update the last.
                if (i >= j)
                    last = j;
            }
        }
        //returning the merged list.
        return arr[0];
    }
};

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int N;
       cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr,N);
        printList(res);

   }

    return 0;
}
```










<br /><br /><br />
## Problem 32:
**[Multiply two linked lists](https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1)**<br />
Given elements as `nodes` of the `two linked lists`. The task is to multiply these **two linked lists**, say `L1` and `L2`.<br /> 
**Note:**<br />
The output could be large take modulo `10^9+7`.<br />

<pre>
Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow, the first line of each test case contains an integer N denoting the size of the first linked list (L1). 
In the next line are the space separated values of the first linked list. 
The third line of each test case contains an integer M denoting the size of the second linked list (L2). 
In the forth line are space separated values of the second linked list.
</pre>
<pre>
Output:
For each test case output will be an integer denoting the product of the two linked list.
</pre>
**User Task:**<br />
The task is to complete the function `multiplyTwoLists()` which should multiply the given `two linked lists` and return the result.<br />

* Constraints: `1 <= T <= 100`<br />
`1 <= N, M <= 100`<br />

<pre>
Example:
Input:
2
2
3 2
1
2
3
1 0 0
2
1 0 
</pre>
<pre>
Output:
64
1000
</pre>
<pre>
Explanation:
Testcase 1: 32*2 = 64.
Testcase 2: 100*10 = 1000.
</pre>
```cpp
#include<bits/stdc++.h>
using namespace std;
 
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
 
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);
    
    return new_Node;
}
 
 Node *reverse(Node **r)
{
    Node *prev =NULL;
    Node *cur = *r;
    Node *nxt;
    while(cur!=NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}

/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node = newNode(new_data);
 
    /* link the old list off the new Node */
    new_Node->next = (*head_ref);
 
    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}

void freeList(struct Node *Node)
{
    struct Node* temp;
    while(Node != NULL)
    {

        temp=Node;
        Node = Node->next;
        free(temp);
    }

}
 
/* Multiply contents of two linked lists */
long long  multiplyTwoLists (struct Node* , struct Node*);
 
// A utility function to print a linked list
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
 
int main(void)
{


   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {

    struct Node* first = NULL;
    struct Node* second = NULL;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>x;
            push(&first, x);
        }
         cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>x;
        push(&second, x);
        }

         reverse(&first);
         reverse(&second);
         long long res = multiplyTwoLists(first,second);
        
        cout<<res<<endl;
        freeList(first);
        freeList(second);

   }
   return 0;
}

#define mod 1000000007
long long  multiplyTwoLists (Node* first, Node* second)
{
    long long num1 = 0, num2 = 0;
    while (first || second)
    {
        if(first){
            num1 = ((num1*10)%mod + (first->data)%mod)%mod;
            first = first->next;
        }
        if(second)
        {
            num2 = ((num2*10)%mod + second->data%mod)%mod;
            second = second->next;
        }
    }
 
 
    return (num1%mod*num2%mod)%mod;
}
```









<br /><br /><br />
## Problem 33:
**[Delete nodes having greater value on right](https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1)**<br />
Given a `singly linked list`, remove _all the nodes which have a greater value on their right side_.<br />

<pre>
Example 1:
Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are the elements which have greater elements
on the following nodes. So, after deleting them, the linked list would like be 15, 11, 6, 3.
</pre>
<pre>
Example 2:
Input:
LinkedList = 10->20->30->40->50->60
Output: 60
</pre>

**Your Task:**<br />
The task is to complete the function `compute()` which should modify the list as required and return _the head of the modified linked list_. The printing is done by the driver code,<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ size of linked list ≤ 1000`<br />
`1 ≤ element of linked list ≤ 1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
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

class Solution
{
    public:
    Node *compute(Node *head)
    {
        // First reversed the linked list
    
        Node *cur = head;
        Node *prev = NULL;
        Node *next;
    
        while(cur!=NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    
        head = prev;
    
        // Link list is reversed till here
    
        // Computing and deleting the nodes which have larger nodes
        // on the left
    
        Node *current = head;
    
        Node *maxNode = head;
        Node *temp;
    
         while (current != NULL && current->next != NULL)
         {
             if(current->next->data < maxNode->data)
             {
                 temp = current->next;
                 current->next = temp->next;
                 free(temp);
             }
             else
             {
                 current = current->next;
                 maxNode= current;
             }
         }
         
         // reversing list again to get required result :-
         
         cur = head;
         prev = NULL;
         next;
         while(cur!=NULL)
         {
             next = cur->next;
             cur->next = prev;
             prev = cur;
             cur = next;
         }
    
         head = prev;
         
         // head of list can be returned now
    
        return head;
    
    }
};

int main()
{
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
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
```








<br /><br /><br />
## Problem 34:
**[Segregate even and odd nodes in a Link List](https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1)**<br />
Given a `link list` of size `N`, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each **segregation** should be same as that in the original list.<br />
**NOTE:**<br />
Don't create a new linked list, instead rearrange the provided one.<br />

<pre>
Example 1:
Input: 
N = 7
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL
Output: 8 2 4 6 17 15 9
Explaination: 8,2,4,6 are the even numbers so they appear first and 17,15,9 are odd numbers that appear later.
</pre>
<pre>
Example 2:
Input:
N = 4
Link List:
1 -> 3 -> 5 -> 7
Output: 1 3 5 7
Explaination: There is no even number. So ne need for modification.
</pre>

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `divide()` which takes `N` and `head of Link List` as input parameters and returns the **head of modified link list**. Don't create a new linked list, instead rearrange the provided one.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ N ≤ 10^5`<br />
`1 ≤ Each element of the list ≤ 10^5`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution
{
public:
        Node* divide(int N, Node *head)
        {
                // code here
                Node *dummy = new Node(0);
                dummy->next = head;
                Node *temp1 = dummy, *temp2 = dummy;
                while (temp2->next && (temp2->next->data) % 2 == 0)
                {
                        temp2 = temp2->next;
                }
                temp1 = temp2;
                while (temp2->next)
                {
                        if ((temp2->next->data) % 2 == 0)
                        {
                                Node *h = temp2->next;
                                temp2->next = temp2->next->next;
                                h->next = temp1->next;
                                temp1->next = h;
                                // h->next=head;
                                temp1 = temp1->next;
                        }
                        else
                        {
                                temp2 = temp2->next;
                        }
                }
                return dummy->next;
        }
};

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
```












<br /><br /><br />
## Problem 35:
**[Nth node from end of linked list](https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1)**<br />
Given a `linked list` consisting of `L` nodes and given a number `N`. The task is to find the `Nth` node from the `end of the linked list`.<br />

<pre>
Example 1:
Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node from end os 8.  
</pre>
<pre>
Example 2:
Input:
N = 5
LinkedList: 10->5->100->5
Output: -1
Explanation: In the second example, there are 4 nodes in the linked list and we
need to find 5th from the end. Since 'n' is more than the number of nodes in the linked list, the output is -1.
</pre>

**Your Task:**<br />
The task is to complete the function `getNthFromLast()` which takes two arguments: `reference to head` and `N` and you need to return `Nth` from the end or `-1` in case node doesn't exist..<br />

<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
</pre>

* Constraints: `1 <= L <= 10^6`<br />
`1 <= N <= 10^6`<br />

```cpp
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
      int data;
      struct Node *next;
      Node(int x) {
        data = x;
        next = NULL;
      }
};

/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    //using two pointers, similar to finding middle element.
    Node *currNode = head , *nthNode = head;
    
    //traversing first n elements with first pointer.
    while(n!=0)
        {
            if(currNode==NULL)
                return -1;
            currNode = currNode->next;
            n--;
        }
    //now traversing with both pointers and when first pointer gives null 
    //we have got the nth node from end in second pointer since the first 
    //pointer had already traversed n nodes and thus had difference of n 
    //nodes with second pointer.
    while(currNode!=NULL)   
        {
            nthNode = nthNode->next;
            currNode = currNode->next;
        }
    
    //returning the data of nth node from end.
    if(nthNode!=NULL)
        return nthNode->data;
    else
        return -1;
        
}
```



<br /><br /><br />
## Problem 36:
**[First non-repeating character in a stream](https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1)**<br />
Given an input stream of `A` of `n` characters consisting only of **lower case alphabets**. The task is to find the first **non repeating character**, each time a character is inserted to the stream. If there is no such character then **append** `'#'` to the answer.<br />
 
<pre>
Example 1:
Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'
</pre>

<pre>
Example 2:
Input: A = "zz"
Output: "z#"
Explanation: For every character first non repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'
</pre> 

**Your Task:**<br />
You don't need to read or print anything. Your task is to complete the function `FirstNonRepeating()` which takes `A` as input parameter and returns _a string after processing the input stream_.<br />
 
<pre>
Expected Time Complexity: O(26 * n)
Expected Space Complexity: O(26)
</pre>

* Constraints: `1 <= n <= 10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string FirstNonRepeating(string A){
            int n = A.size();
            vector<int>f(26, 0);
            vector<int>last(26, -1);
            for(int i = 0; i < A.size(); i++){
                if(last[A[i] - 'a'] == -1)
                    last[A[i] - 'a'] = i;
            }
            string ans="";
            for(int i = 0; i < A.size(); i++){
                f[A[i] - 'a']++;
                char ch = '#';
                int x = A.size() + 1;
                for(int j = 0; j < 26; j++){
                    if(f[j] == 1 and x > last[j]){
                        ch = char(j + 'a');
                        x = last[j];
                    }
                }
                ans += ch;
            }
            return ans;
        }

};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}
```
