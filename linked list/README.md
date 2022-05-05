# LinkedList
**[1. Write a Program to reverse the Linked List. (Both Iterative and recursive)](https://www.geeksforgeeks.org/reverse-a-linked-list/)**<br />
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

![](https://github.com/singh7priyanshu/Competitive-Programming-Essentials-Master-Algorithms-2022/blob/main/linked%20list/source%20images/ll1.gif?raw=true)<br />

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
<img src="https://raw.githubusercontent.com/singh7priyanshu/Competitive-Programming-Essentials-Master-Algorithms-2022/master/linked%20list/source%20images/ll2.png"><br />

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
