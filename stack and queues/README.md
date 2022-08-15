# Love Babbar Sheet 450 - Stacks and Queues
## Problem 1:
**[Implement Stack from Scratch](https://www.tutorialspoint.com/javaexamples/data_stack.htm)**<br />
Following example shows how to implement stack by creating user defined `push()` method for entering elements and `pop()` method for retrieving elements from the stack.<br />

```cpp
public class MyStack {
   private int maxSize;
   private long[] stackArray;
   private int top;
   
   public MyStack(int s) {
      maxSize = s;
      stackArray = new long[maxSize];
      top = -1;
   }
   public void push(long j) {
      stackArray[++top] = j;
   }
   public long pop() {
      return stackArray[top--];
   }
   public long peek() {
      return stackArray[top];
   }
   public boolean isEmpty() {
      return (top == -1);
   }
   public boolean isFull() {
      return (top == maxSize - 1);
   }
   public static void main(String[] args) {
      MyStack theStack = new MyStack(10); 
      theStack.push(10);
      theStack.push(20);
      theStack.push(30);
      theStack.push(40);
      theStack.push(50);
      
      while (!theStack.isEmpty()) {
         long value = theStack.pop();
         System.out.print(value);
         System.out.print(" ");
      }
      System.out.println("");
   }
}
```

>Result<br />
The above code sample will produce the following result.<br />
50 40 30 20 10<br />

The following is an another sample to implement stack by creating user defined `push()` method for entering elements and `pop()` method for retrieving elements from the stack.<br />

```java
import java.util.*;

public class Demo {
   static void showpush(Stack stack1, int a) {
      stack1.push(new Integer(a));
      System.out.println("push(" + a + ")");
      System.out.println("stack: " + stack1);
   } 
   static void showpop(Stack stack1) {
      Integer a = (Integer) stack1.pop();
      System.out.println(a);
      System.out.println("stack: " + stack1);
   } 
   public static void main(String args[]) {
      Stack stack1 = new Stack();
      System.out.println("stack: " + stack1);
      showpush(stack1, 40);
      showpush(stack1, 50);
      showpush(stack1, 60);
      showpop(stack1);
      showpop(stack1);
      showpop(stack1);
      try {
         showpop(stack1);
      } catch (EmptyStackException e) {
         System.out.println("it Is Empty Stack");
      } 
   }
```

>The above code sample will produce the following result.<br />
stack: []<br />
push(40)<br />
stack: [40]<br />
push(50)<br />
stack: [40, 50]<br />
push(60)<br />
stack: [40, 50, 60]<br />
60<br />
stack: [40, 50]<br />
50<br />
stack: [40]<br />
40<br />
stack: []<br />
it Is Empty Stack<br />



<br /><br /><br />
## Problem 2:
**[2. Implement Queue from Scratch](https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/)**<br />
Like `Stack`, `Queue` is a linear structure which follows a particular order in which the operations are performed. The order is `F`irst `I`n `F`irst `O`ut `(FIFO)`.  A good example of queue is any queue of consumers for a resource where the consumer that came first is served first. <br />
The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added.<br />

`Operations on Queue`:<br /> 
Mainly the following four basic operations are performed on queue:<br />
* `Enqueue`: Adds an item to the queue. If the queue is full, then it is said to be an Overflow condition.<br /> 
* `Dequeue`: Removes an item from the queue. The items are popped in the same order in which they are pushed. If the queue is empty, then it is said to be an Underflow condition. <br />
* `Front`: Get the front item from queue.<br /> 
* `Rear`: Get the last item from queue. <br />

<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/02/Queue.png">

`Applications of Queue`: <br />
Queue is used when things don’t have to be processed immediately, but have to be processed in First InFirst Out order like `Breadth First Search`. This property of Queue makes it also useful in following kind of scenarios.<br />
 **1)** When a resource is shared among multiple consumers. Examples include CPU scheduling, Disk Scheduling.<br /> 
 **2)** When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes. Examples include IO Buffers, pipes, file IO, etc.<br />

`Array implementation Of Queue`<br />
For implementing queue, we need to keep track of two indices, front and rear. We enqueue an item at the rear and dequeue an item from the front. If we simply increment front and rear indices, then there may be problems, the front may reach the end of the array. The solution to this problem is to increase front and rear in circular manner.<br />

`Steps for ENQUEUE`<br />
 1. Check the queue is full or not<br />
 2. If full, print overflow and exit<br />
 3. If queue is not full, increment tail and add the element<br />

`Steps for DEQUEUE`<br />
 1. Check queue is empty or not<br />
 2. if empty, print underflow and exit<br />
 3. if not empty, print element at the head and increment head<br />

```cpp
// CPP program for array
// implementation of queue
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a queue
class Queue {
public:
	int front, rear, size;
	unsigned capacity;
	int* array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
Queue* createQueue(unsigned capacity)
{
	Queue* queue = new Queue();
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	// This is important, see the enqueue
	queue->rear = capacity - 1;
	queue->array = new int[queue->capacity];
	return queue;
}

// Queue is full when size
// becomes equal to the capacity
int isFull(Queue* queue)
{
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(Queue* queue)
{
	return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1)
				% queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	cout << item << " enqueued to queue\n";
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)
				% queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Function to get front of queue
int front(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Function to get rear of queue
int rear(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

// Driver code
int main()
{
	Queue* queue = createQueue(1000);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);

	cout << dequeue(queue)
		<< " dequeued from queue\n";

	cout << "Front item is "
		<< front(queue) << endl;
	cout << "Rear item is "
		<< rear(queue) << endl;

	return 0;
}
```

>Output: <br />
10 enqueued to queue<br />
20 enqueued to queue<br />
30 enqueued to queue<br />
40 enqueued to queue<br />
10 dequeued from queue<br />
Front item is 20<br />
Rear item is 40<br />

`Complexity Analysis:  `

* Time Complexity:
<pre>
  Operations              Complexity
  Enque(insertion)           O(1)
  Deque(deletion)            O(1)
  Front(Get front)           O(1)
  Rear(Get Rear)             O(1)
 </pre>
 
* **Auxiliary Space: O(N)**. <br />
`N` is the size of array for storing elements.<br />

>Pros of Array Implementation:  <br />
 1. Easy to implement.<br />

>Cons of Array Implementation:<br />  
 1. Static Data Structure, fixed size.<br />
 2. If the queue has a large number of enqueue and dequeue operations, at some point (in case of linear increment of front and rear indexes) we may not be able to insert elements in the queue even if the queue is empty (this problem is avoided by using circular queue).<br />


 
 
<br /><br /><br />
## Problem 3:
**[Implement 2 stack in an array](https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1)**<br />
Your task is to implement  2 stacks in one array efficiently.<br />

>Example 1:<br />
Input:<br />
push1(2)<br />
push1(3)<br />
push2(4)<br />
pop1()<br />
pop2()<br />
pop2()<br />

>Output:<br />
3 4 -1<br />

>Explanation:<br />
push1(2) the stack1 will be {2}<br />
push1(3) the stack1 will be {2,3}<br />
push2(4) the stack2 will be {4}<br />
pop1()   the poped element will be 3 <br />
from stack1 and stack1 will be {2}<br />
pop2()   the poped element will be 4 <br />
from stack2 and now stack2 is empty<br />
pop2()   the stack2 is now empty hence -1 .<br />
 
Your Task:<br />
You don't need to read input or print anything. You are required to complete the 4 methods `push1`, `push2` which takes one argument an integer `'x'` to be pushed into stack one and two and `pop1`, `pop2` which returns the integer poped out from stack one and two. If no integer is present in the array return -1.<br />

* **Expected Time Complexity**: O(1) for all the four methods.<br />
  **Expected Auxiliary Space**: O(1) for all the four methods.<br />

* Constraints: `1 <= Number of queries <= 100`<br />
`1 <= value in the stack <= 100`<br />
The sum of elements in both the stacks < size of the given array<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}

//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{
    if(top1<top2 -1){
        top1++;
        arr[top1]=x;
    }
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    if(top1<top2 -1){
        top2--;
        arr[top2] = x;
    }
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if(top1>=0){
        int x = arr[top1];
        top1--;
        return x;
    }else return -1;
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2<size){
        int x = arr[top2];
        top2++;
        return x;
    }else return -1;
}
```



<br /><br /><br />
## Problem 4:
**[Find the middle element of a stack](https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/)**<br />
How to implement a stack which will support following operations in `O(1) time complexity`? <br />

  1) `push()` which adds an element to the top of stack. 
  2) `pop()` which removes an element from top of stack. 
  3) `findMiddle()` which will return middle element of the stack.
  4) `deleteMiddle()` which will delete the middle element. 
	
`Push` and `pop` are standard stack operations. <br />

>The important question is, whether to use a linked list or array for the implementation of the stack?<br /> 
Please note that we need to find and delete the `middle` element. Deleting an element from the middle is not `O(1)` for array. Also, we may need to move the `middle pointer` up when we `push` an element and move down when we `pop()`. In a `singly linked list`, moving the `middle pointer` in both directions is not possible.<br /> 
The idea is to use `Doubly Linked List (DLL)`. We can delete the `middle` element in `O(1)` time by maintaining `mid pointer`. We can move mid pointer in both directions using previous and next pointers. <br />
Following is implementation of `push()`, `pop()` and `findMiddle()` operations. Implementation of `deleteMiddle()` is left as an exercise. If there are `even` elements in stack, findMiddle() returns the `second middle element`. For example, if stack contains `{1, 2, 3, 4}`, then findMiddle() would return `3`.<br /> 

```cpp
/* C++ Program to implement a stack
that supports findMiddle() and
deleteMiddle in O(1) time */
#include <bits/stdc++.h>
using namespace std;

class myStack
{
	struct Node
	{
		int num;
		Node *next;
		Node *prev;

		Node(int num)
		{
			this->num = num;
		}
	};

	//Members of stack
	Node *head = NULL;
	Node *mid = NULL;
	int size = 0;

public:
	void push(int data)
	{
		Node *temp = new Node(data);
		if (size==0)
		{
			head = temp;
			mid = temp;
			size++;
			return;
		}

		head->next = temp;
		temp->prev = head;

		//update the pointers
		head = head->next;
		if (size%2==1)
		{
			mid = mid->next;
		}
		size++;
	}

	void pop()
	{
		if (size!=0)
		{
			if (size==1)
			{
				head = NULL;
				mid = NULL;
			}
			else
			{
				head = head->prev;
				head->next = NULL;
				if (size%2==0)
				{
					mid = mid->prev;
				}
			}
			size--;
		}
	}

	int findMiddle()
	{
		if (size==0)
		{
			return -1;
		}
		return mid->num;
	}

	void deleteMiddle()
	{
		if (size!=0)
		{
			if (size==1)
			{
				head = NULL;
				mid = NULL;
			}
			else if (size==2)
			{
				head = head->prev;
				mid = mid->prev;
				head->next =NULL;
			}
			else
			{
				mid->next->prev = mid->prev;
				mid->prev->next = mid->next;
				if (size%2==0)
				{
					mid = mid->prev;
				}
				else
				{
					mid = mid->next;
				}
			}
			size--;
		}
	}
};


int main()
{
	myStack st;
	st.push(11);
	st.push(22);
	st.push(33);
	st.push(44);
	st.push(55);
	st.pop();
	st.pop();
	st.pop();
	cout<<st.findMiddle()<<endl;
	st.deleteMiddle();
	cout<<st.findMiddle()<<endl;
	return 0;
}
```

Output<br />
<pre>
Item popped is 77
Item popped is 66
Item popped is 55
Middle Element is 33
Deleted Middle Element is 33
Middle Element is 22
</pre>







<br /><br /><br />
## Problem 5:
**[How to efficiently implement k stacks in a single array?](https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/)**<br />
Create a data structure `kStacks` that represents `k` stacks. Implementation of kStacks should use only one array, i.e., `k` stacks should use the **same array** for storing elements.<br />
Following functions must be supported by `kStacks`. **push(int x, int sn) –> pushes x to stack number ‘sn’** where `sn` is from `0` to `k-1` **pop(int sn) –> pops an element from stack number ‘sn’** where `sn` is from `0` to `k-1` <br />
<br /><br />**Method 1 (Divide the array in slots of size n/k)**<br />
A simple way to implement `k` stacks is to divide the array in `k` slots of size `n/k` each, and fix the slots for different stacks, i.e., use `arr[0]` to `arr[n/k-1]` for first stack, and `arr[n/k]` to `arr[2n/k-1]` for stack2 where `arr[]` is the array to be used to implement two stacks and size of array be `n`. The problem with this method is inefficient use of array space. A stack push operation may result in stack overflow even if there is space available in `arr[]`. For example, say the `k` is `2` and array `size (n)` is `6` and we push `3` elements to first and do not push anything to second second stack. When we push `4th` element to first, there will be overflow even if we have space for `3` more elements in array.<br />
<br /><br />**Method 2 (A space efficient implementation)**<br />
The idea is to use **two extra arrays** for efficient implementation of `k` stacks in an array. This may not make much sense for integer stacks, but stack items can be large for example stacks of employees, students, etc where every item is of hundreds of bytes. For such large stacks, the extra space used is comparatively very less as we use two integer arrays as extra space.<br />
Following are the two extra arrays are used:<br /> 

1) top[]: This is of size k and stores indexes of top elements in all stacks.<br /> 
2) next[]: This is of size n and stores indexes of next item for the items in array arr[].<br />

Here `arr[]` is actual array that stores `k` stacks. Together with `k` stacks, a stack of free slots in `arr[]` is also maintained. The top of this stack is stored in a variable ‘free’. All entries in `top[]` are initialized as `-1` to indicate that all stacks are empty. All entries `next[i]` are initialized as `i+1` because all slots are free initially and pointing to next slot. Top of free stack, `‘free’` is initialized as `0`.<br /> 
Following is implementation of the above idea.<br />
```cpp
// A C++ program to demonstrate implementation of k stacks in a single
// array in time and space efficient way
#include<bits/stdc++.h>
using namespace std;

// A C++ class to represent k stacks in a single array of size n
class kStacks
{
	int *arr; // Array of size n to store actual content to be stored in stacks
	int *top; // Array of size k to store indexes of top elements of stacks
	int *next; // Array of size n to store next entry in all stacks
				// and free list
	int n, k;
	int free; // To store beginning index of free list
public:
	//constructor to create k stacks in an array of size n
	kStacks(int k, int n);

	// A utility function to check if there is space available
	bool isFull() { return (free == -1); }

	// To push an item in stack number 'sn' where sn is from 0 to k-1
	void push(int item, int sn);

	// To pop an from stack number 'sn' where sn is from 0 to k-1
	int pop(int sn);

	// To check whether stack number 'sn' is empty or not
	bool isEmpty(int sn) { return (top[sn] == -1); }
};

//constructor to create k stacks in an array of size n
kStacks::kStacks(int k1, int n1)
{
	// Initialize n and k, and allocate memory for all arrays
	k = k1, n = n1;
	arr = new int[n];
	top = new int[k];
	next = new int[n];

	// Initialize all stacks as empty
	for (int i = 0; i < k; i++)
		top[i] = -1;

	// Initialize all spaces as free
	free = 0;
	for (int i=0; i<n-1; i++)
		next[i] = i+1;
	next[n-1] = -1; // -1 is used to indicate end of free list
}

// To push an item in stack number 'sn' where sn is from 0 to k-1
void kStacks::push(int item, int sn)
{
	// Overflow check
	if (isFull())
	{
		cout << "\nStack Overflow\n";
		return;
	}

	int i = free;	 // Store index of first free slot

	// Update index of free slot to index of next slot in free list
	free = next[i];

	// Update next of top and then top for stack number 'sn'
	next[i] = top[sn];
	top[sn] = i;

	// Put the item in array
	arr[i] = item;
}

// To pop an from stack number 'sn' where sn is from 0 to k-1
int kStacks::pop(int sn)
{
	// Underflow check
	if (isEmpty(sn))
	{
		cout << "\nStack Underflow\n";
		return INT_MAX;
	}


	// Find index of top item in stack number 'sn'
	int i = top[sn];

	top[sn] = next[i]; // Change top to store next of previous top

	// Attach the previous top to the beginning of free list
	next[i] = free;
	free = i;

	// Return the previous top item
	return arr[i];
}

/* Driver program to test twoStacks class */
int main()
{
	// Let us create 3 stacks in an array of size 10
	int k = 3, n = 10;
	kStacks ks(k, n);

	// Let us put some items in stack number 2
	ks.push(15, 2);
	ks.push(45, 2);

	// Let us put some items in stack number 1
	ks.push(17, 1);
	ks.push(49, 1);
	ks.push(39, 1);

	// Let us put some items in stack number 0
	ks.push(11, 0);
	ks.push(9, 0);
	ks.push(7, 0);

	cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
	cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
	cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

	return 0;
}
```
Output:<br />
<pre>
Popped element from stack 2 is 45
Popped element from stack 1 is 39
Popped element from stack 0 is 7
</pre>
<pre>
Time complexities of operations push() and pop() is O(1). 
The best part of above implementation is, if there is a slot available in stack, then an item can be pushed in any of the stacks, i.e., no wastage of space.
Time Complexity: O(N), as we are using a loop to traverse N times.
Auxiliary Space: O(N), as we are using extra space for stack.
</pre>





<br /><br /><br />
## Problem 6:
**[Balanced Parenthesis problem.[Imp]](https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1)**<br />
Given an expression string `x`. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return `'true'` for exp = `“[()]{}{[()()]()}”` and `'false'` for exp = `“[(])”`.

>Example 1:<br />
Input:<br />
{([])}<br />
Output: <br />
true<br />
Explanation:<br /> 
{ ( [ ] ) }. Same colored brackets can form balaced pairs, with 0 number of unbalanced bracket.<br />

>Example 2:<br />
Input: <br />
()<br />
Output: <br />
true<br />
Explanation:<br /> 
(). Same bracket can form balanced pairs, and here only 1 type of bracket is present and in balanced way.<br />

>Example 3:<br />
Input: <br />
([]<br />
Output: <br />
false<br />
Explanation:<br /> 
([]. Here square bracket is balanced but the small bracket is not balanced and Hence , the output will be unbalanced.<br />

Your Task:<br />
This is a function problem. You only need to complete the function `ispar()` that takes a string as a parameter and returns a boolean value `true` if brackets are balanced else returns `false`. The printing is done automatically by the driver code.<br />

<pre>
Expected Time Complexity: O(|x|)
Expected Auixilliary Space: O(|x|)
</pre>

* Constraints: `1 ≤ |x| ≤ 32000`<br />

Note: The drive code prints `"balanced"` if function return `true`, otherwise it prints `"not balanced"`.<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool ispar(string x){
        stack<char>s;
        for(int i = 0;i<x.size();i++){
            if(x[i]=='[' || x[i]=='{' || x[i]=='(')s.push(x[i]);
            else if(x[i]==']' || x[i]=='}' || x[i]==')'){
                if(s.empty() || !cmp(s.top(), x[i]))return false;
                else s.pop();
            }
        }
        if(s.empty())return true;
        else return false;
    }
    
    bool cmp(char b, char c){
        if(b=='{' && c=='}')return true;
        else if(b=='[' && c==']')return true;
        else if(b=='(' && c==')')return true;
        return false;
    }

};

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
} 
```










<br /><br /><br />
## Problem 7:
**[]()**<br />

<br /><br /><br />
## Problem 8:
**[]()**<br />

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

<br /><br /><br />
## Problem 37:
**[]()**<br />

<br /><br /><br />
## Problem 38:
**[]()**<br />


