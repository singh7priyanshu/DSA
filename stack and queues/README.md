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
**[Reverse a string using Stack](https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1)**<br />
You are given a string `S`, the task is to reverse the string using stack.<br />

>Example 1:<br />
Input: S="GeeksforGeeks"<br />
Output: skeeGrofskeeG<br />
 
**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `reverse()` which takes the string `S` as an input parameter and returns the reversed string.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
</pre>
 
* Constraints: `1 ≤ length of the string ≤ 100`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *S, int len);

int main(){
    long long int t; cin>>t;
    while(t--){
        char str[10000];
        cin>>str;
        long long int len = strlen(str);
        char *ch = reverse(str, len);
        for(int i = 0;i<len;i++)cout<<ch[i];
        cout<<endl;
    }
}

char* reverse(char *S, int len)
{
    stack<char> st;

    for(int i = 0; i < len;i++)
        st.push(S[i]);

    for(int i = 0; i < len; i++)
    {
        S[i] = st.top();
        st.pop();
    }
    return S;
}
```






<br /><br /><br />
## Problem 8:
**[Design a Stack that supports getMin() in O(1) time and O(1) extra space](https://practice.geeksforgeeks.org/problems/special-stack/1)**<br />
Design a data-structure `SpecialStack` that supports all the stack operations like `push()`, `pop()`, `isEmpty()`, `isFull()` and an additional operation `getMin()` which should return `minimum` element from the SpecialStack. Your task is to **complete all the functions**, using stack data-Structure.<br />

>Example 1:<br />
Input:<br />
Stack: 18 19 29 15 16<br />
Output: 15<br />
Explanation: The minimum element of the stack is 15.<br />

**Your Task:**<br />
Since this is a function problem, you don't need to take inputs.<br /> 
You just have to complete 5 functions, `push()` which takes the stack and an integer `x` as input and pushes it into the stack; `pop()` which takes the stack as input and pops out the topmost element from the stack;<br /> 
`isEmpty()` which takes the stack as input and returns **true/false** depending upon whether the stack is empty or not;<br /> 
`isFull()` which takes the stack and the size of the stack as input and returns **true/false** depending upon whether the stack is full or not (depending upon the given size);<br /> 
`getMin()` which takes the stack as input and returns the minimum element of the stack.<br /> 
**Note:** The output of the code will be the value returned by `getMin()` function.<br />

<pre>
Expected Time Complexity: O(N) for getMin, O(1) for remaining all 4 functions.
Expected Auxiliary Space: O(1) for all the 5 functions.
</pre>

* Constraints: `1 ≤ N ≤ 10^4`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
void push(stack<int>& s, int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);

stack<int>s;

int main(){
    long long int t; cin>>t;
    while(t--){
        int n, a; cin>>n;
        while(!isEmpty(s))pop(s);
        while(!isFull(s, n)){
            cin>>a;
            push(s, a);
        }
        cout<<getMin(s)<<endl;
    }
}

void push(stack<int>& s, int a){
    s.push(a);
}
bool isFull(stack<int>& s,int n){
    if(s.size()==n)
        return true;
    return false;
}
bool isEmpty(stack<int>& s){
    if(s.size()==0)
        return true;
    return false;
}
int pop(stack<int>& s){
    int a= s.top();
    s.pop();
    return a;
}
int getMin(stack<int>& s){
    int m=pop(s);
    while(!isEmpty(s)){
        int n=pop(s);
        if(n<m)
            m=n;
    }
    return m;
}
```





<br /><br /><br />
## Problem 9:
**[Find the next Greater element](https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1)**<br />
Given an array `arr[ ]` of size `N` having distinct elements, the task is to find **the next greater element for each element of the array** in order of their appearance in the array.<br />
Next greater element of an element in the array is the `nearest element on the right` which is greater than the current element.<br />
If there does not exist next greater of current element, then next greater element for current element is `-1`. For example, next greater of the last element is always `-1`.<br />

>Example 1:<br />
Input: <br />
N = 4, arr[] = [1 3 2 4]<br />
Output:<br />
3 4 4 -1<br />
Explanation:<br />
In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ?<br /> 
since it doesn't exist, it is -1.<br />

>Example 2:<br />
Input: <br />
N = 5, arr[] [6 8 0 1 3]<br />
Output:<br />
8 -1 1 3 -1<br />
Explanation:<br />
In the array, the next larger element to 6 is 8, for 8 there is no larger elements <br />
hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.<br />

**Your Task:**<br />
This is a function problem. You only need to complete the function `nextLargerElement()` that takes list of integers `arr[ ]` and `N` as input parameters and returns _list of integers of length `N` denoting the next greater elements for all the corresponding elements in the input array_.<br />

<pre>
Expected Time Complexity : O(N)
Expected Auxiliary Space : O(N)
</pre>

* Constraints: `1 ≤ N ≤ 10^6`<br />
`1 ≤ Ai ≤ 10^18`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long > s;
        vector<long long > res (n);
        
        //traversing the array from last element in backward direction.
        for (int i = n-1; i >= 0; i--)
        {
            //while element at top of stack is less than or equal to
            //current array element, we pop elements from the stack.
            while (!s.empty () and s.top () <= arr[i])
                s.pop ();
            
            //if stack becomes empty, we store -1 in the answer list 
            //else we store the top element of the stack.   
            if (s.empty ())
                res[i] = -1;
            else 
                res[i] = s.top ();
            
            //pushing the current array element into the stack.  
            s.push (arr[i]);
        }
        //returning the list.
        return res;
    }
};

int main(){
    long long int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long>arr(n);
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        vector<long long>res = ob.nextLargerElement(arr, n);
        for(long long i : res)cout<<i<<" ";
        cout<<endl;
    }
}
```






<br /><br /><br />
## Problem 10:
**[The celebrity Problem](https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1)**<br />
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of `N` people, find if there is a celebrity in the party or not.
A square `NxN` matrix `M[][]` is used to represent people at the party such that if an element of row `i` and column `j`  is set to `1` it means `ith` person knows `jth` person. Here `M[i][i]` will always be `0`.<br />
**Note:** Follow `0` based indexing.<br />
 
<pre>
Example 1:
Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
</pre>
<pre>
Example 2:
Input:
N = 2
M[][] = {{0 1}
         {1 0}}
Output: -1
Explanation: The two people at the party both know each other. None of them is a celebrity.
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Complete the function `celebrity()` which takes the matrix `M` and its size `N` as input parameters and returns _the index of the celebrity_. If no such celebrity is present, return `-1`.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `2 <= N <= 3000`<br />
`0 <= M[][] <= 1`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //initializing two pointers for two corners.
        int a = 0;
        int b = n - 1;
        
        //we keep moving till the a<b. 
        while (a < b) {
            if (M[a][b])
                a++;
            else
                b--;
        }
        
        //checking if a is actually a celebrity or not.
        for (int i = 0; i < n; i++)
        {
            //if any person doesn't know a or a knows any person, we return -1. 
            if ( (i != a) && (M[a][i] || !M[i][a]) )
                return -1;
        }
        //if we reach here a is celebrity so we retun a.
        return a;
    }
};

int main(){
    long long int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>>M(n, vector<int>(n, 0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++)cin>>M[i][j];
        }
        Solution ob;
        cout<<ob.celebrity(M, n)<<endl;
    }
}
```





<br /><br /><br />
## Problem 11:
**[Arithmetic Expression Evaluation](https://www.geeksforgeeks.org/arithmetic-expression-evalution/)**<br />
The stack organization is very effective in evaluating arithmetic expressions. Expressions are usually represented in what is known as `Infix notation`, in which each operator is written between two operands `(i.e., A + B)`. With this notation, we must distinguish between `( A + B )*C and A + ( B * C )` by using either parentheses or some **operator-precedence** convention. Thus, the order of operators and operands in an arithmetic expression does not uniquely determine the order in which the operations are to be performed.<br />
<br />**1. Polish notation (prefix notation) –**<br />
It refers to the notation in which the operator is placed before its two operands. Here no parentheses are required, i.e.,<br />
<pre>
+AB 
</pre>
<br />**2. Reverse Polish notation(postfix notation) –**<br />
It refers to the **analogous notation** in which the operator is placed after its two operands. Again, no parentheses is required in **Reverse Polish notation**, i.e.,<br />
<pre>
AB+ 
</pre>
Stack-organized computers are better suited for `post-fix notation` than the traditional infix notation. Thus, the `infix notation` must be converted to the `postfix notation`. The conversion from **infix notation to postfix notation must take into consideration the operational hierarchy**.<br />
<br />There are `3` levels of precedence for `5` binary operators as given below:<br />
<pre>
Highest: Exponentiation (^)
Next highest: Multiplication (*) and division (/)
Lowest: Addition (+) and Subtraction (-) 
</pre>
**For example –**<br />
<pre>
Infix notation: (A-B)*[C/(D+E)+F]
Post-fix notation: AB- CDE +/F +* 
</pre>
Here, we first perform the arithmetic inside the parentheses `(A-B)` and `(D+E)`. The division of `C/(D+E)` must be done prior to the addition with `F`. After that multiply the two terms inside the parentheses and bracket.<br /> 
Now we need to calculate the value of these arithmetic operations by using a stack.<br /> 
The procedure for getting the result is:<br />
 
 1. Convert the expression in **Reverse Polish notation**( post-fix notation).<br /> 
 2. Push the operands into the stack in the order they appear.<br /> 
 3. When any operator encounters then pop two topmost operands for executing the operation.<br /> 
 4. After execution push the result obtained into the stack.<br /> 
 5. After the complete execution of expression, the final result remains on the top of the stack.<br /> 

**For example –**<br />
<pre>
Infix notation: (2+4) * (4+6)
Post-fix notation: 2 4 + 4 6 + *
Result: 60 
</pre>
The stack operations for this expression evaluation is shown below:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/s1-9.png"><br />





<br /><br /><br />
## Problem 12:
**[Evaluation of Postfix Expression](https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1)**<br />
Given string `S` representing a `postfix expression`, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like `*, /, + and -`.<br />

>Example 1:<br />
Input: S = "231*+9-"<br />
Output: -4<br />
Explanation:<br />
After solving the given expression, we have -4 as result.<br />

>Example 2:<br />
Input: S = "123+*8-"<br />
Output: -3<br />
Explanation:<br />
After solving the given postfix expression, we have -3 as result.<br />

**Your Task:**<br />
You do not need to read input or print anything. Complete the function `evaluatePostfixExpression()` that takes the string `S` denoting the expression as input parameter and returns the evaluated value.<br />

<pre>
Expected Time Complexity: O(|S|)
Expected Auixilliary Space: O(|S|)
</pre>

* Constraints: `1 ≤ |S| ≤ 10^5`<br />
`0 ≤ |Si|≤ 9` (And given operators)<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        
        //iterating over the given string.
        for (int i = 0; i<S.size(); ++i)
        {
            //if current character is an operand, we push it to the stack.
            if (isdigit(S[i]))
                st.push(S[i] - '0');
    
            //else current character is an operator.
            else
            {
                //we pop and store the values of first two elements of stack.
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                
                //we perform required operation and push the result in stack.
                switch (S[i])
                {
                 case '+': st.push(val2 + val1); break;
                 case '-': st.push(val2 - val1); break;
                 case '*': st.push(val2 * val1); break;
                 case '/': st.push(val2 / val1); break;
                }
            }
        }
        //returning the top element of the stack.
        return st.top();
    }
};

int main(){
    long long int t; cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string S; cin>>S;
        Solution ob;
        cout<<ob.evaluatePostfix(S)<<endl;
    }
}
```








<br /><br /><br />
## Problem 13:
**[Implement a method to insert an element at its bottom without using any other data structure](https://stackoverflow.com/questions/45130465/inserting-at-the-end-of-stack)**<br />
```cpp
static void insert_at_bottom(char x){

    if(st.isEmpty())
        st.push(x);

    else{
        /* All items are held in Function Call Stack until we
           reach end of the stack. When the stack becomes
           empty, the st.size() becomes 0, the
           above if part is executed and the item is inserted
           at the bottom */

        char a = st.peek();
        st.pop();
        insert_at_bottom(x);

        //push all the items held in Function Call Stack
        //once the item is inserted at the bottom
        st.push(a);
    }
}
```






<br /><br /><br />
## Problem 14:
**[Reverse a stack using recursion](https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/)**<br />
Write a program to reverse a `stack` using `recursion`. You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack `S`:<br />

 * isEmpty(S)<br /> 
 * push(S)<br /> 
 * pop(S)<br />

The idea of the solution is to hold all values in `Function Call Stack` until the stack becomes `empty`. When the stack becomes empty, insert all held items one by one at the bottom of the stack.<br /> 
For example, let the input stack be<br />
<pre>
    1  <-- top
    2
    3
    4    
</pre>
<pre>
First 4 is inserted at the bottom.
    4 <-- top

Then 3 is inserted at the bottom
    4 <-- top    
    3

Then 2 is inserted at the bottom
    4 <-- top    
    3 
    2
     
Then 1 is inserted at the bottom
    4 <-- top    
    3 
    2
    1
</pre>
So we need a function that inserts at the bottom of a stack using the above given basic stack function.<br /> 

 * `void insertAtBottom(()`: First **pops** all stack items and stores the popped item in function call stack using **recursion**. And when stack becomes empty, pushes new item and all items stored in call **stack**.<br />
 * `void reverse()`: This function mainly uses **insertAtBottom()** to **pop** all items one by one and insert the popped items at the bottom.<br />
 
 ```cpp
 // C++ code to reverse a
// stack using recursion
#include<bits/stdc++.h>
using namespace std;

// using std::stack for
// stack implementation
stack<char> st;

// initializing a string to store
// result of reversed stack
string ns;

// Below is a recursive function
// that inserts an element
// at the bottom of a stack.
void insert_at_bottom(char x)
{

	if(st.size() == 0)
	st.push(x);

	else
	{
		
		// All items are held in Function Call
		// Stack until we reach end of the stack
		// When the stack becomes empty, the
		// st.size() becomes 0, the above if
		// part is executed and the item is
		// inserted at the bottom
			
		char a = st.top();
		st.pop();
		insert_at_bottom(x);

		// push allthe items held in
		// Function Call Stack
		// once the item is inserted
		// at the bottom
		st.push(a);
	}
}

// Below is the function that
// reverses the given stack using
// insert_at_bottom()
void reverse()
{
	if(st.size()>0)
	{
		
		// Hold all items in Function
		// Call Stack until we
		// reach end of the stack
		char x = st.top();
		st.pop();
		reverse();
		
		// Insert all the items held
		// in Function Call Stack
		// one by one from the bottom
		// to top. Every item is
		// inserted at the bottom
		insert_at_bottom(x);
	}
}

// Driver Code
int main()
{
	
	// push elements into
	// the stack
	st.push('1');
	st.push('2');
	st.push('3');
	st.push('4');
	
	cout<<"Original Stack"<<endl;
	
	// print the elements
	// of original stack
	cout<<"1"<<" "<<"2"<<" " <<"3"<<" "<<"4" <<endl;
	
	// function to reverse
	// the stack
	reverse();
	cout<<"Reversed Stack" 	<<endl;
	
	// storing values of reversed
	// stack into a string for display
	while(!st.empty())
	{
		char p=st.top();
		st.pop();
		ns+=p;
	}
	
	//display of reversed stack
	cout<<ns[3]<<" "<<ns[2]<<" " <<ns[1]<<" "<<ns[0]<<endl;
	return 0;
}
```
Output:<br /> 
<pre>
 Original Stack 
 1  2  3  4 
 Reversed Stack 
 4  3  2  1
</pre>
<pre>
Time Complexity: This approach takes the worst time complexity of O(n^2), 
Auxiliary Space: O(n) since using call stack
</pre>







<br /><br /><br />
## Problem 15:
**[Sort a Stack using recursion](https://practice.geeksforgeeks.org/problems/sort-a-stack/1)**<br />
Given a `stack`, the task is to sort it such that the top of the stack has the greatest element.<br />

>Example 1:<br />
Input:<br />
Stack: 3 2 1<br />
Output: 3 2 1<br />

>Example 2:<br />
Input:<br />
Stack: 11 2 32 3 41<br />
Output: 41 32 11 3 2<br />

**Your Task:**<br /> 
You don't have to read input or print anything. Your task is to complete the function `sort()` which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)<br />

<pre>
Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.
</pre>

* Constraints: `1<=N<=100`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
    stack<int>s;
    void sort();
};

void printStack(stack<int>s){
    while(!s.empty()){
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

int main(){
    int t; cin>>t;
    while(t--){
        SortedStack *ss = new SortedStack();
        int n; cin>>n;
        for(int i = 0;i<n;i++){
            int k; cin>>k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}

void sortedInsert(stack<int> &s, int x)
{
    if(s.empty() or x>s.top())
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s,x);
    s.push(temp);
}

void SortedStack :: sort()
{
    if(!s.empty())
    {
        int x = s.top();
        s.pop();
        sort();
        sortedInsert(s,x);
    }
}
```







<br /><br /><br />
## Problem 16:
**[Merge Overlapping Intervals](https://www.geeksforgeeks.org/merging-intervals/)**<br />
Given a `set of time intervals` in any order, **merge all overlapping intervals into one** and output the result which should have only mutually exclusive intervals.<br />
Example:<br />
<pre>
Input: Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping intervals here,[1,3] and [2,4]. Therefore we will merge these two and return [1,4],[6,8], [9,10].

Input: Intervals = {{6,8},{1,9},{2,4},{4,7}}
Output: {{1, 9}} 
</pre>
<br />**Naive approach:**<br />
A simple approach is to start from the first interval and compare it with all other intervals for overlapping, if it overlaps with any other interval, then **remove** the other interval from the list and **merge** the other into the first interval. Repeat the same steps for the remaining intervals after the first. This approach cannot be implemented in better than `O(n^2) time`.<br />
<pre>
Time complexity: O(n^2)
Auxiliary Space: O(1)
</pre>
<br />**Efficient approach:**<br />
The idea to solve this problem is, first sort the intervals according to the `starting time`. Once we have the sorted intervals, we can combine all intervals in a **linear traversal**. The idea is, in sorted array of intervals, if `interval[i]` doesn’t overlap with `interval[i-1]`, then `interval[i+1]` cannot overlap with `interval[i-1]` because starting time of `interval[i+1]` must be greater than or equal to `interval[i]`.<br />
**Algorithm:**<br />

 1. **Sort** the intervals based on the **increasing order** of starting time.<br />
 2. **Push** the first interval into a `stack`.<br />
 3. For each interval do the following:<br />
    * If the **current interval does not overlap with the top** of the stack then, `push` the current interval into the stack.<br />
    * If the current interval overlap with the top of the stack then, `update` the stack top with the ending time of the current interval.<br />
 4. The **end stack** contains the merged intervals.<br /> 
 
Below is an implementation of the above approach.<br />
```cpp
// A C++ program for merging overlapping intervals
#include <bits/stdc++.h>
using namespace std;

// An interval has start time and end time
struct Interval {
	int start, end;
};

// Compares two intervals according to their starting time.
// This is needed for sorting the intervals using library
// function std::sort().
bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}

// The main function that takes a set of intervals, merges
// overlapping intervals and prints the result
void mergeIntervals(Interval arr[], int n)
{
	// Test if the given set has at least one interval
	if (n <= 0)
		return;

	// Create an empty stack of intervals
	stack<Interval> s;

	// sort the intervals in increasing order of start time
	sort(arr, arr + n, compareInterval);

	// push the first interval to stack
	s.push(arr[0]);

	// Start from the next interval and merge if necessary
	for (int i = 1; i < n; i++) {
		// get interval from stack top
		Interval top = s.top();

		// if current interval is not overlapping with stack
		// top, push it to the stack
		if (top.end < arr[i].start)
			s.push(arr[i]);

		// Otherwise update the ending time of top if ending
		// of current interval is more
		else if (top.end < arr[i].end) {
			top.end = arr[i].end;
			s.pop();
			s.push(top);
		}
	}

	// Print contents of stack
	cout << "\n The Merged Intervals are: ";
	while (!s.empty()) {
		Interval t = s.top();
		cout << "[" << t.start << "," << t.end << "] ";
		s.pop();
	}
	return;
}

// Driver program
int main()
{
	Interval arr[] = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeIntervals(arr, n);
	return 0;
}
```
Output<br />
<pre>
 The Merged Intervals are: [1,9] 
</pre>
<pre>
Time complexity: O(n*log(n)), which is for sorting. Once the array of intervals is sorted, merging takes linear time.
Auxiliary Space: O(n)
</pre>
<br />**Space optimized approach:**<br />
The above solution requires `O(n)` extra space for the stack. We can avoid the use of extra space by doing merge operations in place. Below are detailed steps.<br /> 

 1. Sort all intervals in **increasing order** of start time.<br />
 2. **Traverse** sorted intervals starting from the first interval,<br /> 
 3. Do the following for every interval.<br />
    * If the current interval is not the first interval and it overlaps with the previous interval, then `merge` it with the previous interval. Keep doing it while the interval overlaps with the previous one.<br />         
    * Otherwise, **Add** the current interval to the output list of intervals.<br />
    
Below is the implementation of the above approach:<br />
```cpp
// C++ program to merge overlapping Intervals in
// O(n Log n) time and O(1) extra space.
#include <bits/stdc++.h>
using namespace std;

// An Interval
struct Interval {
	int s, e;
};

// Function used in sort
bool mycomp(Interval a, Interval b) { return a.s < b.s; }

void mergeIntervals(Interval arr[], int n)
{
	// Sort Intervals in increasing order of
	// start time
	sort(arr, arr + n, mycomp);

	int index = 0; // Stores index of last element
	// in output array (modified arr[])

	// Traverse all input Intervals
	for (int i = 1; i < n; i++) {
		// If this is not first Interval and overlaps
		// with the previous one
		if (arr[index].e >= arr[i].s) {
			// Merge previous and current Intervals
			arr[index].e = max(arr[index].e, arr[i].e);
		}
		else {
			index++;
			arr[index] = arr[i];
		}
	}

	// Now arr[0..index-1] stores the merged Intervals
	cout << "\n The Merged Intervals are: ";
	for (int i = 0; i <= index; i++)
		cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}

// Driver program
int main()
{
	Interval arr[] = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeIntervals(arr, n);
	return 0;
}
```
Output<br />
<pre>
The Merged Intervals are: [1, 9] 
</pre>
<pre>
Time Complexity: O(n*log(n))
Auxiliary Space Complexity: O(1)
</pre>






<br /><br /><br />
## Problem 17:
**[Largest rectangular Area in Histogram](https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1)**<br />
Find the `largest rectangular` area possible in a given histogram where the largest rectangle can be made of a number of `contiguous bars`. For simplicity, assume that all bars have the same width and the width is `1` unit, there will be `N bars` height of each bar will be given by the array arr.<br />

>Example 1:<br />
Input:<br />
N = 7<br />
arr[] = {6,2,5,4,5,1,6}<br />
Output: 12<br />
Explanation: <br />
<img src = "http://d1hyf4ir1gqw6c.cloudfront.net/wp-content/uploads/histogram1.png"><br />

>Example 2:<br />
Input:<br />
N = 8<br />
arr[] = {7 2 8 9 1 3 6 5}<br />
Output: 16<br />
Explanation: Maximum size of the histogram will be 8  and there will be 2 consecutive <br />
histogram. And hence the area of the histogram will be 8x2 = 16.<br />

**Your Task:**<br />
The task is to complete the function `getMaxArea()` which takes the array `arr[]` and its size `N` as inputs and finds the **largest rectangular area possible** and returns the answer.<br />

<pre>
Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)
</pre>

* Constraints: `1 ≤ N ≤ 10^6`<br />
`1 ≤ arr[i] ≤ 10^12`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long hist[], long long n){
    
    //creating an empty stack. The stack holds indexes of hist[] array.
    //the bars stored in stack are always in increasing order of their heights. 
    stack<long long> s; 
  
    long long max_area = 0;  
    long long tp;  
    long long area_with_top; 
  
    long long i = 0; 
    
    //traversing the array.
    while (i < n) 
    { 
        //if current bar is greater than or equal to bar on top 
        //of stack, we push the index into stack. 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
  
        //if current bar is lower than bar on top of stack, we calculate
        //area of rectangle with top of stack as the smallest bar.  
        //i is rightindex for top and element before top in stack is leftindex
        else
        { 
            tp = s.top();  
            //popping the top element of stack.
            s.pop();  
  
            //calculating the area with hist[tp] stack as smallest bar. 
            area_with_top=hist[tp]*(s.empty()? i :i-s.top()-1); 
  
            //updating maximum area, if needed. 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
  
    //now popping the remaining bars from stack and calculating 
    //area with every popped bar as the smallest bar.
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        
        area_with_top=hist[tp]*(s.empty()? i :i-s.top()-1); 
  
        //updating maximum area, if needed. 
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
    //returning the maximum area.
    return max_area; 
}
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        long long arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    }
}
```








<br /><br /><br />
## Problem 18:
**[Length of the Longest Valid Substring](https://practice.geeksforgeeks.org/problems/valid-substring0624/1)**<br />
Given a string `S` consisting only of opening and closing parenthesis 'ie `'('`  and `')'`, find out the **length of the longest valid(well-formed) parentheses substring**.<br />
**NOTE:** Length of the smallest valid substring `( )` is `2`.<br />

>Example 1:<br />
Input: S = "(()("<br />
Output: 2<br />
Explanation: The longest valid substring is "()". Length = 2.<br />

>Example 2:<br />
Input: S = "()(())("<br />
Output: 6<br />
Explanation: The longest valid substring is "()(())". Length = 6.<br />

**Your Task:**<br />  
You dont need to read input or print anything. Complete the function `findMaxLen()` which takes `S` as input parameter and returns _the maxlength_.<br />

<pre>
Expected Time Complexity:O(n)
Expected Auxiliary Space: O(1)   
</pre>

* Constraints: `1 <= |S| <= 10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxLen(string s) {
        int n = s.length();

        // Variables for left and right counter.
        // maxlength to store the maximum length found so far
        int left = 0, right = 0, maxlength = 0;

        // Iterating the string from left to right
        for (int i = 0; i < n; i++) {
            // If "(" is encountered,
            // then left counter is incremented
            // else right counter is incremented
            if (s[i] == '(')
                left++;
            else
                right++;

            // Whenever left is equal to right, it signifies
            // that the subsequence is valid and
            if (left == right) maxlength = max(maxlength, 2 * right);

            // Reseting the counters when the subsequence
            // becomes invalid
            else if (right > left)
                left = right = 0;
        }

        left = right = 0;

        // Iterating the string from right to left
        for (int i = n - 1; i >= 0; i--) {

            // If "(" is encountered,
            // then left counter is incremented
            // else right counter is incremented
            if (s[i] == '(')
                left++;
            else
                right++;

            // Whenever left is equal to right, it signifies
            // that the subsequence is valid and
            if (left == right) maxlength = max(maxlength, 2 * left);

            // Reseting the counters when the subsequence
            // becomes invalid
            else if (left > right)
                left = right = 0;
        }
        return maxlength;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string S; cin>>S;
        Solution ob;
        cout<<ob.findMaxLen(S)<<endl;
    }
}
```







<br /><br /><br />
## Problem 19:
**[Expression contains redundant bracket or not](https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/)**<br />
Given a `string` of balanced expression, find if it contains a **redundant parenthesis or not**. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Print `‘Yes’` if redundant, else `‘No’`.<br />
**Note:** Expression may contain `‘+‘`, `‘*‘`, `‘–‘` and `‘/‘` operators. Given expression is valid and there are no white spaces present.<br />
Example:<br /> 
<pre>
Input: 
((a+b))
(a+(b)/c)
(a+b*(c-d))
Output: 
Yes
Yes
No

Explanation:
1. ((a+b)) can reduced to (a+b), this Redundant
2. (a+(b)/c) can reduced to (a+b/c) because b is
surrounded by () which is redundant.
3. (a+b*(c-d)) doesn't have any redundant or multiple
brackets.
</pre>
The idea is to use `stack`, which is discussed in this article. For any sub-expression of expression, if we are able to pick any sub-expression of expression surrounded by `()`, then we again left with `()` as part of string, we have redundant braces.<br /> 
We iterate through the given expression and for each character in the expression, if the character is an open parenthesis `‘(‘` or any of the operators or operands, we push it to the stack. If the character is close parenthesis `‘)’`, then **pop** characters from the stack till matching open parenthesis `‘(‘` is found.<br /> 
Now for redundancy two condition will arise while popping-<br /> 

 1. If immediate `pop` hits an open parenthesis `‘(‘`, then we have found a duplicate parenthesis. For example, `(((a+b))+c)` has duplicate brackets around `a+b`. When we reach the second `“)”` after `a+b`, we have `“((”` in the stack. Since the top of stack is an opening bracket, we conclude that there are duplicate brackets.<br /> 
 2. If immediate `pop` doesn’t hit any operand `(‘*’, ‘+’, ‘/’, ‘-‘)` then it indicates the presence of unwanted brackets surrounded by expression. For instance, `(a)+b` contain unwanted `()` around a thus it is redundant.<br />  

Implementation:<br />
```cpp
/* C++ Program to check whether valid
expression is redundant or not*/
#include <bits/stdc++.h>
using namespace std;

// Function to check redundant brackets in a
// balanced expression
bool checkRedundancy(string& str)
{
	// create a stack of characters
	stack<char> st;

	// Iterate through the given expression
	for (auto& ch : str) {

		// if current character is close parenthesis ')'
		if (ch == ')') {
			char top = st.top();
			st.pop();

			// If immediate pop have open parenthesis '('
			// duplicate brackets found
			bool flag = true;

			while (!st.empty() and top != '(') {

				// Check for operators in expression
				if (top == '+' || top == '-' ||
					top == '*' || top == '/')
					flag = false;

				// Fetch top element of stack
				top = st.top();
				st.pop();
			}

			// If operators not found
			if (flag == true)
				return true;
		}

		else
			st.push(ch); // push open parenthesis '(',
				// operators and operands to stack
	}
	return false;
}

// Function to check redundant brackets
void findRedundant(string& str)
{
	bool ans = checkRedundancy(str);
	if (ans == true)
		cout << "Yes\n";
	else
		cout << "No\n";
}

// Driver code
int main()
{
	string str = "((a+b))";
	findRedundant(str);

	str = "(a+(b)/c)";
	findRedundant(str);

	str = "(a+b*(c-d))";
	findRedundant(str);

	return 0;
}
```
Output<br />
<pre>
Yes
Yes
No
</pre>
<pre>
Time complexity : O(n) 
Auxiliary Space : O(n)
</pre>







<br /><br /><br />
## Problem 20:
**[Implement Stack using Queue](https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1)**<br />
Implement a `Stack` using two queues `q1` and `q2`.<br />

<pre>
Example 1:
Input:                      OR                     5
push(2)                                            1 2
push(3)                                            1 3 
pop()                                              2
push(4)                                            1 4
pop()                                              2 
Output: 3 4
Explanation:
push(2) the stack will be {2}
push(3) the stack will be {2 3}
pop()   poped element will be 3 the 
        stack will be {2}
push(4) the stack will be {2 4}
pop()   poped element will be 4  
</pre>
<pre>
Example 2:
Input:
push(2)
pop()
pop()
push(3)
Output: 2 -1
</pre>

**Your Task:**<br />
Since this is a function problem, you don't need to take inputs. You are required to complete the two methods `push()` which takes an integer 'x' as input denoting the element to be pushed into the stack and `pop()` which returns _the integer poped out from the stack_(`-1 if the stack is empty`).<br />

<pre>
Expected Time Complexity: O(1) for push() and O(N) for pop() (or vice-versa).
Expected Auxiliary Space: O(1) for both push() and pop().
</pre>

* Constraints: `1 <= Number of queries <= 100`<br />
`1 <= values of the stack <= 100`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
    queue<int>q1;
    queue<int>q2;
public:
    void push(int);
    int pop();
};

int main(){
    int t; cin>>t;
    while(t--){
        QueueStack *qs = new QueueStack();
        int Q; cin>>Q;
        while(Q--){
            int QueryType = 0; cin>>QueryType;
            if(QueryType == 1){
                int a; cin>>a;
                qs->push(a);
            }else if(QueryType == 2){
                cout<<qs->pop()<<" ";
            }
        }
        cout<<endl;
    }
}

// push operation


//Function to push an element into stack using two queues.
void QueueStack ::push(int num){
    
    //while first queue is not empty, we keep popping the front element
    //from first queue and storing that element in second queue.
    while(!q1.empty())
    {
        int k = q1.front();
        
        //popping element from first queue.
        q1.pop();
        
        //pushing it into second queue.
        q2.push(k);
    }
    
    //q1 is empty now and we push the given number into first queue.
    q1.push(num);
    
    //while second queue is not empty, we keep popping the front element
    //from second queue and storing that element in first queue.
    while(!q2.empty())
    {
        int k = q2.front();
        //popping element from second queue.
        q2.pop();
        
        //pushing it into first queue.
        q1.push(k);
    }
}
//Function to pop an element from stack using two queues. 
int QueueStack ::pop(){

    //if first queue is not empty, then we can pop an element.
    if(!q1.empty())
    {
        //we store the front element from the queue in a 
        //variable and pop that element.
        int r = q1.front();
        q1.pop();
        
        //returning the popped element.
        return r;
    }
    //else we return -1.
    return -1;
}
```







<br /><br /><br />
## Problem 21:
**[Implement Stack and Queue using Deque](https://www.geeksforgeeks.org/implement-stack-queue-using-deque/)**<br />
Deque also known as `double ended queue`, as name suggests is a special kind of queue in which insertions and deletions can be done at the last as well as at the beginning.<br />
A link-list representation of deque is such that each node points to the next node as well as the previous node. So that insertion and deletions take constant time at both the beginning and the last.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/deque-1.png"><br />
Now, deque can be used to implement a **stack and queue**. One simply needs to understand how deque can made to work as a stack or a queue.<br />
The functions of deque to tweak them to work as stack and queue are list below.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/stack-and-queue-using-deque.png"><br />
**Examples: Stack**<br />
<pre>
Input : Stack : 1 2 3
        Push(4)
Output : Stack : 1 2 3 4

Input : Stack : 1 2 3
        Pop()
Output : Stack : 1 2
</pre>
**Examples: Queue**<br />
<pre>
Input: Queue : 1 2 3
       Enqueue(4)
Output: Queue : 1 2 3 4

Input: Queue : 1 2 3
       Dequeue()
Output: Queue : 2 3
</pre>
**Implementation:**<br />
```cpp
// C++ Program to implement stack and queue using Deque
#include <bits/stdc++.h>
using namespace std;

// structure for a node of deque
struct DQueNode {
	int value;
	DQueNode* next;
	DQueNode* prev;
};

// Implementation of deque class
class Deque {
private:

	// pointers to head and tail of deque
	DQueNode* head;
	DQueNode* tail;

public:
	// constructor
	Deque()
	{
		head = tail = NULL;
	}

	// if list is empty
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		return false;
	}

	// count the number of nodes in list
	int size()
	{
		// if list is not empty
		if (!isEmpty()) {
			DQueNode* temp = head;
			int len = 0;
			while (temp != NULL) {
				len++;
				temp = temp->next;
			}
			return len;
		}
		return 0;
	}

	// insert at the first position
	void insert_first(int element)
	{
		// allocating node of DQueNode type
		DQueNode* temp = new DQueNode[sizeof(DQueNode)];
		temp->value = element;

		// if the element is first element
		if (head == NULL) {
			head = tail = temp;
			temp->next = temp->prev = NULL;
		}
		else {
			head->prev = temp;
			temp->next = head;
			temp->prev = NULL;
			head = temp;
		}
	}

	// insert at last position of deque
	void insert_last(int element)
	{
		// allocating node of DQueNode type
		DQueNode* temp = new DQueNode[sizeof(DQueNode)];
		temp->value = element;

		// if element is the first element
		if (head == NULL) {
			head = tail = temp;
			temp->next = temp->prev = NULL;
		}
		else {
			tail->next = temp;
			temp->next = NULL;
			temp->prev = tail;
			tail = temp;
		}
	}

	// remove element at the first position
	void remove_first()
	{
		// if list is not empty
		if (!isEmpty()) {
			DQueNode* temp = head;
			head = head->next;
			if(head) head->prev = NULL;
			delete temp;
			if(head == NULL) tail = NULL;
			return;
		}
		cout << "List is Empty" << endl;
	}

	// remove element at the last position
	void remove_last()
	{
		// if list is not empty
		if (!isEmpty()) {
			DQueNode* temp = tail;
			tail = tail->prev;
			if(tail) tail->next = NULL;
			delete temp;
			if(tail == NULL) head = NULL;
			return;
		}
		cout << "List is Empty" << endl;
	}

	// displays the elements in deque
	void display()
	{
		// if list is not empty
		if (!isEmpty()) {
			DQueNode* temp = head;
			while (temp != NULL) {
				cout << temp->value << " ";
				temp = temp->next;
			}
			cout << endl;
			return;
		}
		cout << "List is Empty" << endl;
	}
};

// Class to implement stack using Deque
class Stack : public Deque {
public:
	// push to push element at top of stack
	// using insert at last function of deque
	void push(int element)
	{
		insert_last(element);
	}

	// pop to remove element at top of stack
	// using remove at last function of deque
	void pop()
	{
		remove_last();
	}
};

// class to implement queue using deque
class Queue : public Deque {
public:
	// enqueue to insert element at last
	// using insert at last function of deque
	void enqueue(int element)
	{
		insert_last(element);
	}

	// dequeue to remove element from first
	// using remove at first function of deque
	void dequeue()
	{
		remove_first();
	}
};

// Driver Code
int main()
{
	// object of Stack
	Stack stk;

	// push 7 and 8 at top of stack
	stk.push(7);
	stk.push(8);
	cout << "Stack: ";
	stk.display();

	// pop an element
	stk.pop();
	cout << "Stack: ";
	stk.display();

	// object of Queue
	Queue que;

	// insert 12 and 13 in queue
	que.enqueue(12);
	que.enqueue(13);
	cout << "Queue: ";
	que.display();

	// delete an element from queue
	que.dequeue();
	cout << "Queue: ";
	que.display();

	cout << "Size of Stack is " << stk.size() << endl;
	cout << "Size of Queue is " << que.size() << endl;
	return 0;
}
```
Output<br />
<pre>
Stack: 7 8 
Stack: 7 
Queue: 12 13 
Queue: 13 
Size of Stack is 1
Size of Queue is 1
</pre>
<pre>
Time Complexity: O(n)
Auxiliary Space: O(n)
</pre>









<br /><br /><br />
## Problem 22:
**[Stack Permutations (Check if an array is stack permutation of other)](https://www.geeksforgeeks.org/stack-permutations-check-if-an-array-is-stack-permutation-of-other/)**<br />
A stack permutation is a permutation of objects in the given input queue which is done by transferring elements from input queue to the output queue with the help of a stack and the built-in **push** and **pop** functions.<br />
The well defined rules are:<br />

 1. Only **dequeue** from the **input queue**.<br />
 2. Use inbuilt **push**, **pop** functions in the single stack.<br />
 3. **Stack** and **input queue** must be empty at the end.<br />
 4. Only **enqueue** to the output queue.<br />

There are a huge number of permutations possible using a stack for a single input queue.<br /> 
Given two arrays, both of **unique** elements. One represents the input **queue** and the other represents the output queue. Our task is to check if the given output is possible through stack permutation.<br />
Examples:<br />
<pre>
Input : First array: 1, 2, 3  
        Second array: 2, 1, 3
Output : Yes
Procedure:
push 1 from input to stack
push 2 from input to stack
pop 2 from stack to output
pop 1 from stack to output
push 3 from input to stack
pop 3 from stack to output


Input : First array: 1, 2, 3  
        Second array: 3, 1, 2
Output : Not Possible 
</pre>
The idea to do this is we will try to convert the input queue to output queue using a stack, if we are able to do so then the queue is permutable otherwise not.<br />
<pre>
Below is the step by step algorithm to do this: 
 1. Continuously pop elements from the input queue and check if it is equal to 
    the top of output queue or not, if it is not equal to the top of output queue 
    then we will push the element to stack. 
 2. Once we find an element in input queue such the top of input queue is equal 
    to top of output queue, we will pop a single element from both input and 
    output queues, and compare the top of stack and top of output queue now. If 
    top of both stack and output queue are equal then pop element from both 
    stack and output queue. If not equal, go to step 1. 
 3. Repeat above two steps until the input queue becomes empty. At the end if 
    both of the input queue and stack are empty then the input queue is 
    permutable otherwise not. 
</pre>
Below is implementation of above idea:<br />
```cpp
// Given two arrays, check if one array is
// stack permutation of other.
#include<bits/stdc++.h>
using namespace std;

// function to check if input queue is
// permutable to output queue
bool checkStackPermutation(int ip[], int op[], int n)
{
	// Input queue
	queue<int> input;
	for (int i=0;i<n;i++)
		input.push(ip[i]);

	// output queue
	queue<int> output;
	for (int i=0;i<n;i++)
		output.push(op[i]);

	// stack to be used for permutation
	stack <int> tempStack;
	while (!input.empty())
	{
		int ele = input.front();
		input.pop();
		if (ele == output.front())
		{
			output.pop();
			while (!tempStack.empty())
			{
				if (tempStack.top() == output.front())
				{
					tempStack.pop();
					output.pop();
				}
				else
					break;
			}
		}
		else
			tempStack.push(ele);
	}

	// If after processing, both input queue and
	// stack are empty then the input queue is
	// permutable otherwise not.
	return (input.empty()&&tempStack.empty());
}

// Driver program to test above function
int main()
{
	// Input Queue
	int input[] = {1, 2, 3};

	// Output Queue
	int output[] = {2, 1, 3};

	int n = 3;

	if (checkStackPermutation(input, output, n))
		cout << "Yes";
	else
		cout << "Not Possible";
	return 0;
}
```
Output<br />
<pre>
Yes
</pre>
<br />**Another Approach:  –**<br />
Idea –  we will start iterating on input array and storing its element one by one in a **stack** and if top of our stack matches with an element in output array we will `pop` that element from stack and `compare next element` of output array with top of our stack if again it matches then again **pop** until our stack isn’t empty<br />
Implementation:<br />
```cpp
// Given two arrays, check if one array is
// stack permutation of other.
#include<bits/stdc++.h>
using namespace std;

// function to check if input array is
// permutable to output array
bool checkStackPermutation(int ip[], int op[], int n)
{
	// we will be pushing elements from input array to stack uptill top of our stack
	// matches with first element of output array
	stack<int>s;
	
	// will maintain a variable j to iterate on output array
	int j=0;

	// will iterate one by one in input array
	for(int i=0;i<n;i++)
	{
		// pushed an element from input array to stack
		s.push(ip[i]);
		// if our stack isnt empty and top matches with output array
		// then we will keep popping out from stack uptill top matches with
		// output array
		while(!s.empty() and s.top()==op[j])
		{
		s.pop();
		// increasing j so next time we can compare next element in output array
		j++;
		}
	}
	
	// if output array was a correct permutation of input array then
	// by now our stack should be empty
	if(s.empty())
	{
		return true;
	}
	return false;
	
}

// Driver program to test above function
int main()
{
	// Input Array
	int input[] = {4,5,6,7,8};

	// Output Array
	int output[] = {8,7,6,5,4};

	int n = 5;

	if (checkStackPermutation(input, output, n))
		cout << "Yes";
	else
		cout << "Not Possible";
	return 0;
}
```
Output<br />
<pre>
Yes
</pre>
<pre>
Time Complexity –  O(N)
Space Complexity – O(N)
</pre>







<br /><br /><br />
## Problem 23:
**[Implement Queue using Stack](https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1)**<br />
Implement a Queue using 2 stacks `s1` and `s2` .<br />
A Query `Q` is of `2` Types<br />

(i) **1 x (a query of this type means  pushing 'x' into the queue)**<br />
(ii) **2   (a query of this type means to pop element from queue and print the poped element)**<br />

<pre>
Example 1:
Input:
5
1 2 1 3 2 1 4 2

Output: 
2 3

Explanation: 
In the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the queue 
    will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3.
</pre>
<pre>
Example 2:
Input:
4
1 2 2 2 1 4

Output: 
2 -1

Explanation: 
In the second testcase 
1 2 the queue will be {2}
2   poped element will be 2 and 
    then the queue will be empty
2   the queue is empty and hence -1
1 4 the queue will be {4}.
</pre>
**Your Task:**<br />
You are required to complete the two methods push which take one argument an integer `'x'` to be pushed into the `queue` and `pop` which returns **a integer poped out from other queue**`(-1 if the queue is empty)`. The printing is done automatically by the driver code.

<pre>
Expected Time Complexity : O(1) for push() and O(N) for pop() or O(N) for push() and O(1) for pop()  
Expected Auxilliary Space : O(1).
</pre>

* Constraints: `1 <= Q <= 100`<br />
`1 <= x <= 100`<br />

**Note:**<br />
The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class StackQueue{
private:
    stack<int>s1;
    stack<int>s2;
public:
    void push(int B);
    int pop();
};

int main(){
    int t; cin>>t;
    while(t--){
        StackQueue *sq = new StackQueue();
        int Q; cin>>Q;
        while(Q--){
            int QueryType; cin>>QueryType;
            if(QueryType == 1){
                int a; cin>>a;
                sq->push(a);
            }else if(QueryType == 2){
                cout<<sq->pop()<<" ";
            }
        }
        cout<<endl;
    }
}

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int B)
{
    //inserting the element in first stack.
    s1.push(B);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop(){
    if(s2.empty())
    {
        //if both stacks are empty, we return -1.
        if(s1.empty())
            return -1;
        //we keep removing the top element from first stack and keep
        //pushing them in second stack. Thus, the order gets reversed.
        while(!s1.empty())
        {
            int r=s1.top();
            s1.pop(); 
            s2.push(r);
        }
    }
    //second stack holds the elements in reversed order so we just store 
    //and then pop the element at top of the stack.
    int k=s2.top();
    s2.pop();
    return k;
}
```












<br /><br /><br />
## Problem 24:
**[Implement "n" queue in an array](https://www.geeksforgeeks.org/efficiently-implement-k-queues-single-array/)**<br />
Create a data structure kQueues that represents `k` queues. Implementation of `kQueues` should use only one array, i.e., `k` queues should use the same array for storing elements. Following functions must be supported by `kQueues`.<br />

 * `enqueue(int x, int qn)` –> adds `x` to queue number `‘qn’` where `qn` is from `0` to `k-1`<br /> 
 * `dequeue(int qn)` –> deletes an element from queue number `‘qn’` where `qn` is from `0` to `k-1` <br />

<br />**Method 1 (Divide the array in slots of size n/k):**<br />
A simple way to implement `k` queues is to divide the array in `k` slots of size `n/k` each, and fix the slots for different queues, i.e., use `arr[0] to arr[n/k-1]` for the first queue, and `arr[n/k]` to `arr[2n/k-1]` for queue2 where `arr[]` is the array to be used to implement two queues and size of array be `n`.<br />
The problem with this method is an inefficient use of array space. An `enqueue` operation may result in overflow even if there is space available in `arr[]`. For example, consider `k` as `2` and array size `n` as `6`. Let we enqueue `3` elements to first and do not enqueue anything to the second queue. When we enqueue the `4th` element to the first queue, there will be overflow even if we have space for `3` more elements in the array.<br />
<br />**Method 2 (A space efficient implementation):**<br />
The idea is similar to the stack post, here we need to use **three extra arrays**. In stack post, we needed **two extra arrays**, one more array is required because in `queues`, `enqueue()` and `dequeue()` operations are done at different ends.<br />
Following are the three extra arrays are used:<br />

 1. `front[]:` This is of size `k` and stores indexes of front elements in all queues. <br />
 2. `rear[]:` This is of size `k` and stores indexes of rear elements in all queues. <br />
 3. `next[]:` This is of size `n` and stores indexes of next item for all items in array arr[].<br />

Here `arr[]` is the actual array that stores `k` stacks.<br />
Together with `k` queues, a stack of free slots in `arr[]` is also maintained. The top of this stack is stored in a variable `‘free’`.<br />
All entries in `front[]` are initialized as `-1` to indicate that all queues are empty. All entries `next[i]` are initialized as `i+1` because all slots are free initially and pointing to the next slot. Top of the free stack, `‘free’` is initialized as `0`.<br />
Following is C++ implementation of the above idea.<br />
```cpp
// A C++ program to demonstrate implementation
// of k queues in a single
// array in time and space efficient way
#include<iostream>
#include<climits>
using namespace std;

// A C++ class to represent k queues
// in a single array of size n
class kQueues
{
	// Array of size n to store actual
	// content to be stored in queue
	int *arr;

	// Array of size k to store indexes
	// of front elements of the queue
	int *front;

	// Array of size k to store indexes
	// of rear elements of queue
	int *rear;

	// Array of size n to store next
	// entry in all queues		
	int *next;
	int n, k;

	int free; // To store the beginning index of the free list

public:
	//constructor to create k queue
	// in an array of size n
	kQueues(int k, int n);

	// A utility function to check if
	// there is space available
	bool isFull() { return (free == -1); }

	// To enqueue an item in queue number
	// 'qn' where qn is from 0 to k-1
	void enqueue(int item, int qn);

	// To dequeue an from queue number
	// 'qn' where qn is from 0 to k-1
	int dequeue(int qn);

	// To check whether queue number
	// 'qn' is empty or not
	bool isEmpty(int qn) { return (front[qn] == -1); }
};

// Constructor to create k queues
// in an array of size n
kQueues::kQueues(int k1, int n1)
{
	// Initialize n and k, and allocate
	// memory for all arrays
	k = k1, n = n1;
	arr = new int[n];
	front = new int[k];
	rear = new int[k];
	next = new int[n];

	// Initialize all queues as empty
	for (int i = 0; i < k; i++)
		front[i] = -1;

	// Initialize all spaces as free
	free = 0;
	for (int i=0; i<n-1; i++)
		next[i] = i+1;
	next[n-1] = -1; // -1 is used to indicate end of free list
}

// To enqueue an item in queue number
// 'qn' where qn is from 0 to k-1
void kQueues::enqueue(int item, int qn)
{
	// Overflow check
	if (isFull())
	{
		cout << "\nQueue Overflow\n";
		return;
	}

	int i = free;	 // Store index of first free slot

	// Update index of free slot to index of next slot in free list
	free = next[i];

	if (isEmpty(qn))
		front[qn] = i;
	else
		next[rear[qn]] = i;

	next[i] = -1;

	// Update next of rear and then rear for queue number 'qn'
	rear[qn] = i;

	// Put the item in array
	arr[i] = item;
}

// To dequeue an from queue number 'qn' where qn is from 0 to k-1
int kQueues::dequeue(int qn)
{
	// Underflow checkSAS
	if (isEmpty(qn))
	{
		cout << "\nQueue Underflow\n";
		return INT_MAX;
	}

	// Find index of front item in queue number 'qn'
	int i = front[qn];

	// Change top to store next of previous top
	front[qn] = next[i];

	// Attach the previous front to the
	// beginning of free list
	next[i] = free;
	free = i;

	// Return the previous front item
	return arr[i];
}

/* Driver program to test kStacks class */
int main()
{
	// Let us create 3 queue in an array of size 10
	int k = 3, n = 10;
	kQueues ks(k, n);

	// Let us put some items in queue number 2
	ks.enqueue(15, 2);
	ks.enqueue(45, 2);

	// Let us put some items in queue number 1
	ks.enqueue(17, 1);
	ks.enqueue(49, 1);
	ks.enqueue(39, 1);

	// Let us put some items in queue number 0
	ks.enqueue(11, 0);
	ks.enqueue(9, 0);
	ks.enqueue(7, 0);

	cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
	cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
	cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

	return 0;
}
```
Output<br />
<pre>
Dequeued element from queue 2 is 15
Dequeued element from queue 1 is 17
Dequeued element from queue 0 is 11
</pre>
<pre>
Time complexities of enqueue() and dequeue() is O(1).
</pre>
<pre>
The best part of the above implementation is, if there is a slot available in the queue, 
then an item can be enqueued in any of the queues, i.e., no wastage of space. 
This method requires some extra space. Space may not be an issue because queue items are 
typically large, for example, queues of employees, students, etc where every item is of hundreds of bytes. 
For such large queues, the extra space used is comparatively very less as we use three integer arrays as extra space.
</pre>







<br /><br /><br />
## Problem 25:
**[Implement a Circular queue](https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/)**<br />
**What is a Circular Queue?**<br />
<pre>
A Circular Queue is a special version of queue where the last element of the 
queue is connected to the first element of the queue forming a circle.
</pre>
The operations are performed based on `FIFO (First In First Out)` principle. It is also called `‘Ring Buffer’`.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/Circular-queue.png"><br />
In a normal Queue, we can insert elements until queue becomes full. But once queue becomes full, we **can not insert** the next element even if there is a space in front of queue.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/Circular-queue_1.png"><br />
<br />**Operations on Circular Queue:**<br />

 * `Front:` Get the front item from queue.<br />
 * `Rear:` Get the last item from queue.<br />
 * `enQueue(value)` This function is used to insert an element into the circular queue. In a circular queue, the new element is always inserted at Rear position.<br /> 
   1. Check whether queue is Full – `Check ((rear == SIZE-1 && front == 0) || (rear == front-1))`.<br />
   2. If it is full then display Queue is full. If queue is not full then, check if `(rear == SIZE – 1 && front != 0)` if it is `true` then set `rear=0` and insert element.<br />
 * `deQueue()` This function is used to delete an element from the `circular queue`. In a circular queue, the element is always `deleted` from front position.<br /> 
   1. Check whether queue is Empty means check `(front==-1)`.<br />
   2. If it is `empty` then display Queue is empty. If queue is not empty then step 3<br />
   3. Check if `(front==rear)` if it is true then set `front=rear= -1` else check if `(front==size-1)`, if it is true then set `front=0` and return the element.<br />
   
**Implementation:**<br />

```cpp
// C or C++ program for insertion and
// deletion in Circular Queue
#include<bits/stdc++.h>
using namespace std;

class Queue
{
	// Initialize front and rear
	int rear, front;

	// Circular Queue
	int size;
	int *arr;
public:
	Queue(int s)
	{
	front = rear = -1;
	size = s;
	arr = new int[s];
	}

	void enQueue(int value);
	int deQueue();
	void displayQueue();
};


/* Function to create Circular queue */
void Queue::enQueue(int value)
{
	if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))
	{
		printf("\nQueue is Full");
		return;
	}

	else if (front == -1) /* Insert First Element */
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size-1 && front != 0)
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}
	printf("\nElements in Circular Queue are: ");
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			printf("%d ",arr[i]);
	}
	else
	{
		for (int i = front; i < size; i++)
			printf("%d ", arr[i]);

		for (int i = 0; i <= rear; i++)
			printf("%d ", arr[i]);
	}
}

/* Driver of the program */
int main()
{
	Queue q(5);

	// Inserting elements in Circular Queue
	q.enQueue(14);
	q.enQueue(22);
	q.enQueue(13);
	q.enQueue(-6);

	// Display elements present in Circular Queue
	q.displayQueue();

	// Deleting elements from Circular Queue
	printf("\nDeleted value = %d", q.deQueue());
	printf("\nDeleted value = %d", q.deQueue());

	q.displayQueue();

	q.enQueue(9);
	q.enQueue(20);
	q.enQueue(5);

	q.displayQueue();

	q.enQueue(20);
	return 0;
}
```
Output<br />
<pre>
Elements in Circular Queue are: 14 22 13 -6 
Deleted value = 14
Deleted value = 22
Elements in Circular Queue are: 13 -6 
Elements in Circular Queue are: 13 -6 9 20 5 
Queue is Full
</pre>
<pre>
Time Complexity: Time complexity of enQueue(), deQueue() operation is O(1) as there is no loop in any of the operation.
</pre>
<br />**Applications:**<br />

 1. `Memory Management:` The unused memory locations in the case of ordinary queues can be utilized in circular queues.<br />
 2. `Traffic system:` In computer controlled traffic system, circular queues are used to switch on the traffic lights one by one repeatedly as per the time set.<br />
 3. `CPU Scheduling:` Operating systems often maintain a queue of processes that are ready to execute or that are waiting for a particular event to occur.<br />







<br /><br /><br />
## Problem 26:
**[LRU Cache Implementationa](https://practice.geeksforgeeks.org/problems/lru-cache/1)**<br />
Design a data structure that works like a `LRU Cache`. Here cap denotes the capacity of the `cache` and `Q` denotes the number of queries. Query can be of two types:<br />

 1. `SET x y :` sets the value of the key `x` with value `y`<br />
 2. `GET x :` gets the key of `x` if present else returns `-1`.<br />

The LRUCache class has two methods `get()` and `set()` which are defined as follows.<br />

 1. `get(key)   :` returns the value of the key if it already exists in the cache otherwise returns `-1`.<br />
 2. `set(key, value) :` if the key is already present, update its value. If not present, **add** the key-value pair to the cache. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.<br />
 3. In the **constructor** of the class the capacity of the cache should be intitialized.<br />
 
<pre>
Example 1:
Input:
cap = 2
Q = 2
Queries = SET 1 2 GET 1
Output: 2
Explanation: 
Cache Size = 2

SET 1 2 GET 1
SET 1 2 : 1 -> 2

GET 1 : Print the value corresponding to Key 1, ie 2.
</pre>
<pre>
Example 2:
Input:
cap = 2
Q = 8
Queries = SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 SET 1 2 GET 3
Output: 5 -1

Explanation: 
Cache Size = 2

SET 1 2 : 1 -> 2

SET 2 3 : 1 -> 2, 2 -> 3 (the most recently 
used one is kept at the rightmost position) 

SET 1 5 : 2 -> 3, 1 -> 5

SET 4 5 : 1 -> 5, 4 -> 5 (Cache size is 2, hence 
we delete the least recently used key-value pair)

SET 6 7 : 4 -> 5, 6 -> 7 

GET 4 : Prints 5 (The cache now looks like
6 -> 7, 4->5)

SET 1 2 : 4 -> 5, 1 -> 2 
(Cache size is 2, hence we delete the least 
recently used key-value pair)

GET 3 : No key value pair having 
key = 3. Hence, -1 is printed.
</pre>

**Your Task:**<br />
You don't need to read input or print anything . Complete the `constructor` and `get()`, `set()` methods of the class LRUcache.<br /> 

<pre>
Expected Time Complexity: O(1) for both get() and set().
Expected Auxiliary Space: O(1) for both get() and set(). 
(Although, you may use extra space for cache storage and implementation purposes).
</pre>

* Constraints: `1 <= cap <= 1000`<br />
`1 <= Q <= 100000`<br />
`1 <= x, y <= 1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int value;
    Node *next, *pre;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = pre = NULL;
    }
};

class LRUCache
{
    private:
    static unordered_map<int, Node *> hsmap;
    static int capacity, count;
    static Node *head, *tail;

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        unordered_map<int, Node *> temp;
        hsmap = temp;
        capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        head->pre = NULL;
        tail->next = NULL;
        tail->pre = head;
        count = 0;
    }

    void addToHead(Node *node)
    {
        node->next = head->next;
        node->next->pre = node;
        node->pre = head;
        head->next = node;
    }

    //Function to delete a node.
    void deleteNode(Node *node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        //if element is present in map,
        if (hsmap.count(key) > 0)
        {
            Node *node = hsmap[key];
            int result = node->value;
            
            deleteNode(node);
            addToHead(node);
            
            //returning the value.
            return result;
        }
        //else we return -1.
        return -1;
    }

    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if (hsmap.count(key) > 0)
        {
            Node *node = hsmap[key];
            node->value = value;
            deleteNode(node);
            addToHead(node);
        }
        else
        {
            Node *node = new Node(key, value);
            hsmap[key] = node;
            if (count < capacity) {
                count++;
                addToHead(node);
            } 
            else {
                hsmap.erase(tail->pre->key);
                deleteNode(tail->pre);
                addToHead(node);
            }
        }
    }
};

//initializing static members.
unordered_map<int, Node *> temp;
int LRUCache::capacity = 0;
Node *LRUCache::head = new Node(0, 0);
Node *LRUCache::tail = new Node(0, 0);
int LRUCache::count = 0;
unordered_map<int, Node *> LRUCache::hsmap = temp;

int main(){
    int t; cin>>t;
    while(t--){
        int capacity; cin>>capacity;
        LRUCache *cache = new LRUCache(capacity);
        int queries; cin>>queries;
        while(queries--){
            string q; cin>>q;
            if(q == "SET"){
                int key; cin>>key;
                int value; cin>>value;
                cache->set(key, value);
            }else{
                int key; cin>>key;
                cout<<cache->get(key)<<" ";
            }
        }
        cout<<endl;
    }
}
```








<br /><br /><br />
## Problem 27:
**[Reverse a Queue using recursion](https://practice.geeksforgeeks.org/problems/queue-reversal/1)**<br />
Given a `Queue Q` containing `N` elements. The task is to _reverse the Queue_. Your task is to complete the function `rev()`, that reverses the `N` elements of the queue.<br />

>Example 1:<br />
Input:<br />
6<br />
4 3 1 10 2 6<br />
Output: <br />
6 2 10 1 3 4<br />
Explanation: <br />
After reversing the given elements of the queue , the resultant queue will be 6 2 10 1 3 4.<br />

>Example 2:
Input:<br />
4<br />
4 3 2 1 <br />
Output: <br />
1 2 3 4<br />
Explanation:<br /> 
After reversing the given elements of the queue , the resultant queue will be 1 2 3 4.<br />

**Your Task:**<br />
You only need to complete the function rev that takes a `queue` as parameter and returns the `reversed queue`. The printing is done automatically by the driver code.<br />

<pre>
Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)
</pre>

* Constraints: `1 ≤ N ≤ 10^5`<br />
`1 ≤ elements of Queue ≤ 10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

queue<int>rev(queue<int>q);

int main(){
    int t; cin>>t;
    while(t--){
        queue<int>q;
        int n, var;
        cin>>n;
        while(n--){
            cin>>var;
            q.push(var);
        }
        queue<int> a = rev(q);
        while(!a.empty()){
            cout<<a.front()<<" ";
            a.pop();
        }
        cout<<endl;
    }
}

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    //using a stack to reverse the queue.
    stack<int> s;      
    while(!q.empty())
    {
        //pushing elements from queue into stack and removing them from queue.
        s.push(q.front());       
        q.pop();                 
    }
    //creating new queue.
    queue<int> a;
    while(!s.empty())
    {
        //now pushing elements back into the queue from stack and removing them 
        //from stack. queue gets reversed as stack follows last in first out.
        a.push(s.top());         
        s.pop();                
    }
    //returning reversed queue.
    return a;
}
```





<br /><br /><br />
## Problem 28:
**[Reverse First K elements of Queue](https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1)**<br />
Given an integer `K` and a `queue` of integers, we need to reverse the order of the first `K` elements of the queue, leaving the other elements in the same relative order.<br />
Only following standard operations are allowed on queue.<br />

 * `enqueue(x) :` Add an item `x` to `rear` of queue<br />
 * `dequeue() :` Remove an item from `front` of queue<br />
 * `size() :` Returns number of elements in queue.<br />
 * `front() :` Finds front item. <br />
 
**Note:** The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.<br />

>Example 1:<br />
Input:<br />
5 3<br />
1 2 3 4 5<br />
Output: <br />
3 2 1 4 5<br />
Explanation: <br />
After reversing the given input from the 3rd position the resultant output will be 3 2 1 4 5.<br />

>Example 2:<br />
Input:<br />
4 4<br />
4 3 2 1<br />
Output: <br />
1 2 3 4<br />
Explanation: <br />
After reversing the given input from the 4th position the resultant output will be 1 2 3 4.<br />

**Your Task:**<br />
Complete the provided function `modifyQueue` that takes `queue` and `k` as parameters and returns _a modified queue_. The printing is done automatically by the driver code.<br />

<pre>
Expected Time Complexity : O(N)
Expected Auxiliary Space : O(K)
</pre>

* Constraints: `1 <= N <= 1000`<br />
`1 <= K <= N`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

queue<int>modifyQueue(queue<int>q, int k);

int main(){
    int t; cin>>t;
    while(t-- > 0){
        int n, k; cin>>n>>k;
        queue<int>q;
        while(n-- > 0){
            int a; cin>>a;
            q.push(a);
        }
        queue<int>ans = modifyQueue(q, k);
        while(!ans.empty()){
            int a = ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // using a stack and another queue to reverse first k elements.
    stack<int> s;
    queue<int> qq;

    // we pop first k elements from queue and push it in the stack.
    while (k-- > 0) {
        int a = q.front();
        q.pop();
        s.push(a);
    }

    // while stack is not empty, we push the elements into the new queue.
    while (!s.empty()) {
        int a = s.top();
        s.pop();
        qq.push(a);
    }

    // then we add rest of the elements of original queue to the new queue.
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        qq.push(a);
    }

    // returning the new queue.
    return qq;
}
```





<br /><br /><br />
## Problem 29:
**[Interleave the first half of the queue with second half](https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/)**<br />
Given a `queue` of integers of `even length`, rearrange the elements by interleaving the **first half** of the queue with the **second half** of the queue.<br />
Examples:<br />
<pre>
Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20
</pre>
**Using Stack**<br />
<pre>
Following are the steps to solve the problem: 
  1. Push the first half elements of the queue to stack. 
  2. Enqueue back the stack elements. 
  3. Dequeue the first half elements of the queue and enqueue them back. 
  4. Again push the first half elements into the stack. 
  5. Interleave the elements of queue and stack. 
</pre>
**Implementation:**<br />
```cpp
// C++ program to interleave the first half of the queue
// with the second half
#include <bits/stdc++.h>
using namespace std;

// Function to interleave the queue
void interLeaveQueue(queue<int>& q)
{
	// To check the even number of elements
	if (q.size() % 2 != 0)
		cout << "Input even number of integers." << endl;

	// Initialize an empty stack of int type
	stack<int> s;
	int halfSize = q.size() / 2;

	// Push first half elements into the stack
	// queue:16 17 18 19 20, stack: 15(T) 14 13 12 11
	for (int i = 0; i < halfSize; i++) {
		s.push(q.front());
		q.pop();
	}

	// enqueue back the stack elements
	// queue: 16 17 18 19 20 15 14 13 12 11
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}

	// dequeue the first half elements of queue
	// and enqueue them back
	// queue: 15 14 13 12 11 16 17 18 19 20
	for (int i = 0; i < halfSize; i++) {
		q.push(q.front());
		q.pop();
	}

	// Again push the first half elements into the stack
	// queue: 16 17 18 19 20, stack: 11(T) 12 13 14 15
	for (int i = 0; i < halfSize; i++) {
		s.push(q.front());
		q.pop();
	}

	// interleave the elements of queue and stack
	// queue: 11 16 12 17 13 18 14 19 15 20
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
}

// Driver program to test above function
int main()
{
	queue<int> q;
	q.push(11);
	q.push(12);
	q.push(13);
	q.push(14);
	q.push(15);
	q.push(16);
	q.push(17);
	q.push(18);
	q.push(19);
	q.push(20);
	interLeaveQueue(q);
	int length = q.size();
	for (int i = 0; i < length; i++) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
```
Output<br />
<pre>
11 16 12 17 13 18 14 19 15 20 
</pre>
<pre>
Time complexity: O(n). 
Auxiliary Space: O(n).
</pre>
<br />Using Queue<br />
We can also solve the given problem by using a `queue` instead of a stack. The idea is to move the **first half** to another queue, and then push values from the **temporary queue** and **original queue** into the original queue. The original queue will get converted to the interleaved queue after the operations.<br />
**Steps to solve :**<br /> 

 1. Make a `temporary queue` and push the first half of the `original queue` into the temp queue.<br />
 2. Till the `temp queue` is empty<br />
   1. Pop the front of the **temp queue** and push it to the **original queue**<br />
   2. Pop the front of the **original queue** and push it to the **original queue**<br />
 3. The `original queue` is converted to the `interleaved queue`.<br />

![Moving-first-half-to-another-queue](https://user-images.githubusercontent.com/71781982/184675118-5112fbf1-5fe9-4151-a617-f6deae882c19.gif)
<pre>
	Move the first half to the temporary queue
</pre>

![Interleaving-in-original-queue](https://user-images.githubusercontent.com/71781982/184675095-7e2e6ed2-dcce-4d4a-9df6-b102b2a2ce8e.gif)
<pre>
	Interleaving the two halves
</pre>
```cpp
// C++ program to interleave the first half of the queue
// with the second half using queue
#include <bits/stdc++.h>
using namespace std;

// Function to interleave the queue
void interLeaveQueue(queue<int>& q)
{
	// To check the even number of elements
	if (q.size() % 2 != 0)
		cout << "Input even number of integers." << endl;

	// Initialize an empty queue of int type
	queue<int> temp;
	int halfSize = q.size() / 2;

	// Push first half elements into the stack
	// queue:16 17 18 19 20, queue: 11 12 13 14 15
	for (int i = 0; i < halfSize; i++) {
		temp.push(q.front());
		q.pop();
	}

	// enqueue back the queue elements alternatively
	// queue: 11 16 12 17 13 18 14 19 15 20
	while (!temp.empty()) {
		q.push(temp.front());
		q.push(q.front());
		q.pop();
		temp.pop();
	}
}

// Driver program to test above function
int main()
{
	queue<int> q;
	q.push(11);
	q.push(12);
	q.push(13);
	q.push(14);
	q.push(15);
	q.push(16);
	q.push(17);
	q.push(18);
	q.push(19);
	q.push(20);
	interLeaveQueue(q);
	int length = q.size();
	for (int i = 0; i < length; i++) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
```
Output<br />
<pre>
11 16 12 17 13 18 14 19 15 20 
</pre>
<pre>
Time complexity: O(n)  
Auxiliary Space: O(n).
</pre>








<br /><br /><br />
## Problem 30:
**[Find the first circular tour that visits all Petrol Pumps](https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1)**<br />
Suppose there is a `circle`. There are `N` petrol pumps on that `circle`. You will be given **two sets of data**.<br />

  1. The amount of petrol that every petrol pump has.<br />
  2. Distance from that petrol pump to the next petrol pump.<br />

Find a `starting point` where the truck can start to get through the **complete circle without exhausting its petrol** in between.<br />
**Note :**  Assume for `1` litre petrol, the truck can go `1` unit of distance.<br />

>Example 1:<br />
Input:<br />
N = 4<br />
Petrol = 4 6 7 4<br />
Distance = 6 5 3 5<br />
Output: 1<br />
Explanation: There are 4 petrol pumps with amount of petrol and distance to next<br />
petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}. The first point from<br />
where truck can make a circular tour is 2nd petrol pump. Output in this case is 1<br />
(index of 2nd petrol pump).<br />

**Your Task:**<br />
Your task is to complete the function `tour()` which takes the `required data` as inputs and returns _an integer denoting a point from where a truck will be able to complete the circle_ (The truck will stop at each petrol pump and it has `infinite capacity`). If there exists multiple such `starting points`, then the function must return _the first one out of those_. (return `-1` otherwise)<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space : O(1)
</pre>

* Constraints: `2 ≤ N ≤ 10000`<br />
`1 ≤ petrol, distance ≤ 1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct petrolPump{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int start = 0;
       int end = 1 ;
       int cur_pet = p[start].petrol-p[start].distance;
       while(end!=start or cur_pet <0){
           while(cur_pet<0 and start!=end){
               cur_pet -= p[start].petrol-p[start].distance;
               start= (start +1 )%n;
               if(start==0){
                   return -1;
               }
           }
           cur_pet += p[end].petrol -p[end].distance;
           end= (end +1)%n;
       }
       return start;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        petrolPump p[n];
        for(int i = 0;i<n;i++)cin>>p[i].petrol>>p[i].distance;
        Solution ob;
        cout<<ob.tour(p, n)<<endl;
    }
}
```







<br /><br /><br />
## Problem 31:
**[Minimum time required to rot all oranges](https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1)**<br />
Given a grid of dimension `nxm` where each cell in the grid can have values `0`, `1` or `2` which has the following meaning:<br />

 0 : Empty cell<br />
 1 : Cells have fresh oranges<br />
 2 : Cells have rotten oranges<br />

We have to determine what is the `minimum time` required to rot all oranges. A rotten orange at `index [i,j]` can rot other fresh orange at `indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1]` (`up`, `down`, `left` and `right`) in unit time.<br /> 
 
>Example 1:<br />
Input: grid = {{0,1,2},{0,1,2},{2,1,1}}<br />
Output: 1<br />
Explanation: The grid is-<br />
0 1 2<br />
0 1 2<br />
2 1 1<br />
Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time.<br />

>Example 2:<br />
Input: grid = {{2,2,0,1}}<br />
Output: -1<br />
Explanation: The grid is-<br />
2 2 0 1<br />
Oranges at (0,0) and (0,1) can't rot orange at (0,3).<br />

**Your Task:**<br />
You don't need to read or print anything, Your task is to complete the function `orangesRotting()` which takes grid as `input parameter` and returns _the minimum time to rot all the fresh oranges_. If not possible returns `-1`.<br />
 
<pre>
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n)
</pre>

* Constraints: `1 ≤ n, m ≤ 500`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int ct=0, res=-1;
        //queue to store cells which have rotten oranges.
        queue<vector<int>> q;
        vector<vector<int>> dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        //traversing over all the cells of the matrix.
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++) 
            {
                //if grid value is more than 0, we increment the counter.
                if(grid[i][j]>0) 
                    ct++;
                //if grid value is 2, we push the cell indexes into queue.
                if(grid[i][j]==2) 
                    q.push({i, j});
            }
        }
        while(!q.empty())
        {
            //incrementing result counter.
            res++;
            int size=q.size();
            for(int k=0;k<size;k++) 
            {
                //popping the front element of queue and storing cell indexes.
                vector<int> cur=q.front();
                ct--;
                q.pop();
                
                //traversing the adjacent vertices.
                for(int i=0;i<4;i++) 
                {
                    int x=cur[0]+dir[i][0], y=cur[1]+dir[i][1];
                    
                    //if cell indexes are within matrix bounds and grid value
                    //is not 1, we continue the loop else we store 2 in current
                    //cell and push the cell indexes in the queue.
                    if(x>=grid.size()||x<0||y>=grid[0].size()||y<0||grid[x][y]!=1) 
                        continue;
                    grid[x][y]=2;
                    q.push({x, y});
                }
            }
        }
        //returning the minimum time.
        if(ct==0) return max(0, res);
        return -1;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<vector<int>>grid(n, vector<int>(m, -1));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++)cin>>grid[i][j];
        }
        Solution ob;
        int ans = ob.orangesRotting(grid);
        cout<<ans<<endl;
    }
}
```










<br /><br /><br />
## Problem 32:
**[Distance of nearest cell having 1 in a binary matrix](https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1)**<br />
Given a `binary grid` of `n*m`. Find the distance of the nearest `1` in the grid for each cell.<br />
The distance is calculated as `|i1  - i2| + |j1 - j2|`, where `i1`, `j1` are the **row number** and **column number** of the current cell, and `i2`, `j2` are the **row number** and **column number** of the nearest cell having value `1`.<br />
 
>Example 1:<br />
Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}<br />
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}<br />
Explanation: The grid is-<br />
0 1 1 0 <br />
1 1 0 0 <br />
0 0 1 1 <br />
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at (0,1), (0,2), (0,2), (2,3), (1,0) and (1,1) respectively.<br />

>Example 2:<br />
Input: grid = {{1,0,1},{1,1,0},{1,0,0}}<br />
Output: {{0,1,0},{0,0,1},{0,1,2}}<br />
Explanation: The grid is-<br />
1 0 1<br />
1 1 0<br />
1 0 0<br />
0's at (0,1), (1,2), (2,1) and (2,2) are at a distance of 1, 1, 1 and 2 from 1's at (0,0), (0,2), (2,0) and (1,1) respectively.<br />

**Your Task:**<br />
You don't need to read or print anything, Your task is to complete the function `nearest()` which takes the `grid` as an input parameter and returns _a matrix of the same dimensions where the value at index `(i, j)` in the resultant matrix signifies the minimum distance of `1` in the matrix from `grid[i][j]`_.<br />
 
<pre>
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
</pre>

* Constraints: `1 ≤ n, m ≤ 500`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int>dx = {1,-1,0,0};
    vector<int>dy = {0,0,1,-1};
    
    //Function to check whether the cell is within the matrix bounds.
    bool isValid(int x, int y, int n, int m){
        return (x >=0 and x < n and y >=0 and y < m);
    }
    
    //Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>>nearest(vector<vector<int>>grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        //queue to store the cell indexes which have grid value 1.
        queue<pair<int, int>>q;
        
        //using dp list which will store the output.
        vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
        
        //traversing all the cells of the matrix.
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                //if grid value is 1, we update the dp value at same cell as 0 
                //and push the cell indexes into queue.
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            //storing the cell indexes at top of queue and popping them.
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            //iterating over the adjacent cells.
            for(int i = 0; i < 4; i++)
            {
                int n_x = x + dx[i];
                int n_y = y + dy[i];
                if(isValid(n_x, n_y, n, m) and dp[n_x][n_y] > dp[x][y] + 1)
                {
                    //updating dp and pushing cell indexes in queue.
                    dp[n_x][n_y] = dp[x][y] + 1;
                    q.push({n_x, n_y});
                }
            }
        }
        //returning the dp list.
        return dp;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<vector<int>>grid(n, vector<int>(m, -1));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++)cin>>grid[i][j];
        }
        Solution ob;
        vector<vector<int>>ans = ob.nearest(grid);
        for(auto i : ans){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
}
```







<br /><br /><br />
## Problem 33:
**[First negative integer in every window of size k](https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1)**<br />
Given an array `A[]` of size `N` and a positive integer `K`, find _the **first negative integer** for each and every window(contiguous subarray) of size `K`_.<br />

>Example 1:<br />
Input : <br />
N = 5<br />
A[] = {-8, 2, 3, -6, 10}<br />
K = 2<br />
Output : <br />
-8 0 -6 -6<br />
Explanation :<br />
First negative integer for each window of size k<br />
{-8, 2} = -8<br />
{2, 3} = 0 (does not contain a negative integer)<br />
{3, -6} = -6<br />
{-6, 10} = -6<br />
 
>Example 2:<br />
Input : <br />
N = 8<br />
A[] = {12, -1, -7, 8, -15, 30, 16, 28}<br />
K = 3<br />
Output :<br />
-1 -1 -7 -15 -15 0 <br />
 
**Your Task:**<br />  
You don't need to read input or print anything. Your task is to complete the function `printFirstNegativeInteger()` which takes the array `A[]`, its size `N` and an integer `K` as inputs and returns _the **first negative number** in every window of size `K` starting from the first till the end_. If a window does not contain a negative integer , then return `0` for that window.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)
</pre>

* Constraints: `1 <= N <= 10^5`<br />
`-10^5 <= A[i] <= 10^5`<br />
`1 <= K <= N`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k);

int main(){
    long long int t, i; cin>>t;
    while(t--){
        long long int n; cin>>n;
        long long int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        long long k; cin>>k;
        vector<long long>ans = printFirstNegativeInteger(arr, n, k);
        for(auto it : ans)cout<<it<<" ";
        cout<<endl;
    }
}

// function to find the first negative
// integer in every window of size k
vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
    // A Double Ended Queue, Di that will store indexes of
    // useful array elements for the current window of size k.
    // The useful elements are all negative integers.
    deque<long long int> Di;
    vector<long long> ans;

    /* Process first k (or first window) elements of array */
    long long int i;
    for (i = 0; i < k; i++)
        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0) Di.push_back(i);

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (; i < n; i++) {
        // if Di is not empty then the element at the
        // front of the queue is the first negative integer
        // of the previous window
        if (!Di.empty()) ans.push_back(arr[Di.front()]);

        // else the window does not have a
        // negative integer
        else
            ans.push_back(0);

        // Remove the elements which are out of this window
        while ((!Di.empty()) && Di.front() < (i - k + 1))
            Di.pop_front(); // Remove from front of queue

        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0) Di.push_back(i);
    }

    // Print the first negative
    // integer of last window
    if (!Di.empty())
        ans.push_back(arr[Di.front()]);
    else
        ans.push_back(0);

    return ans;
}
```






<br /><br /><br />
## Problem 34:
**[Check if all levels of two trees are anagrams or not](https://www.geeksforgeeks.org/check-if-all-levels-of-two-trees-are-anagrams-or-not/)**<br />
Given `two binary trees`, we have to check if each of their levels are `anagrams of each other or not`.<br />
Example:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/MirrorTree1-1.gif"><br />
<pre>
Tree 1:
Level 0 : 1
Level 1 : 3, 2
Level 2 : 5, 4

Tree 2:
Level 0 : 1
Level 1 : 2, 3
Level 2 : 4, 5
</pre>
As we can clearly see all the levels of above `two binary trees` are anagrams of each other, hence return `true`.<br />
<br />**Naive Approach:**<br />
Below is the step by step explanation of the naive approach to do this:<br />

 1. Write a **recursive program** for level order traversal of a tree.<br />
 2. **Traverse** each level of both the trees one by one and store the result of traversals in `2` different vectors, one for each tree.<br />
 3. Sort both the vectors and compare them iteratively for each level, if they are same for each level then return `true` else return `false`.<br />
<pre>
Time Complexity: O(n^2), where n is the number of nodes.
</pre>

<br />**Efficient Approach:**<br />
We **traverse** both trees simultaneously level by level. We store each level both trees in `vectors` (or array). To check if two vectors are `anagram` or not, we **sort** both and then compare.<br />
<pre>
Time Complexity: O(nlogn), where n is the number of nodes.
</pre>
```cpp
/* Iterative program to check if two trees are level
by level anagram. */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	struct Node *left, *right;
	int data;
};

// Returns true if trees with root1 and root2
// are level by level anagram, else returns false.
bool areAnagrams(Node *root1, Node *root2)
{
	// Base Cases
	if (root1 == NULL && root2 == NULL)
		return true;
	if (root1 == NULL || root2 == NULL)
		return false;

	// start level order traversal of two trees
	// using two queues.
	queue<Node *> q1, q2;
	q1.push(root1);
	q2.push(root2);

	while (1)
	{
		// n1 (queue size) indicates number of Nodes
		// at current level in first tree and n2 indicates
		// number of nodes in current level of second tree.
		int n1 = q1.size(), n2 = q2.size();

		// If n1 and n2 are different
		if (n1 != n2)
			return false;

		// If level order traversal is over
		if (n1 == 0)
			break;

		// Dequeue all Nodes of current level and
		// Enqueue all Nodes of next level
		vector<int> curr_level1, curr_level2;
		while (n1 > 0)
		{
			Node *node1 = q1.front();
			q1.pop();
			if (node1->left != NULL)
				q1.push(node1->left);
			if (node1->right != NULL)
				q1.push(node1->right);
			n1--;

			Node *node2 = q2.front();
			q2.pop();
			if (node2->left != NULL)
				q2.push(node2->left);
			if (node2->right != NULL)
				q2.push(node2->right);

			curr_level1.push_back(node1->data);
			curr_level2.push_back(node2->data);
		}

		// Check if nodes of current levels are
		// anagrams or not.
		sort(curr_level1.begin(), curr_level1.end());
		sort(curr_level2.begin(), curr_level2.end());
		if (curr_level1 != curr_level2)
			return false;
	}

	return true;
}

// Utility function to create a new tree Node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Constructing both the trees.
	struct Node* root1 = newNode(1);
	root1->left = newNode(3);
	root1->right = newNode(2);
	root1->right->left = newNode(5);
	root1->right->right = newNode(4);

	struct Node* root2 = newNode(1);
	root2->left = newNode(2);
	root2->right = newNode(3);
	root2->left->left = newNode(4);
	root2->left->right = newNode(5);

	areAnagrams(root1, root2)? cout << "Yes" : cout << "No";
	return 0;
}
```
Output<br />
<pre>
Yes
</pre>
**Note:**<br /> 
In the above program we are **comparing the vectors storing each level** of a tree directly using `not equal to function` `‘ != ‘` which compares the `vectors first on the basis of their size` and then on the `basis of their content`, hence saving our work of iteratively comparing the vectors.<br />
<br />**Efficient Approach:**<br />
We can solve the problem in `O(n) time complexity` by using `Hash tables` during `level order traversal`. The idea is to do a level order traversal and in each level check whether the level is an **anagram** with help of hash tables.<br />
```cpp
/* Iterative program to check if two trees are level
by level anagram. */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
	struct Node *left, *right;
	int data;
};

// Returns true if trees with root1 and root2
// are level by level anagram, else returns false.
bool areAnagrams(Node* root1, Node* root2)
{
	// Base Cases
	if (root1 == NULL && root2 == NULL)
		return true;
	if (root1 == NULL || root2 == NULL)
		return false;

	// start level order traversal of two trees
	// using two queues.
	queue<Node*> q1, q2;
	q1.push(root1);
	q2.push(root2);

	// Hashmap to store the elements that occur in each
	// level.
	unordered_map<int, int> m;

	while (!q1.empty() && !q2.empty()) {
		// n1 (queue size) indicates number of Nodes
		// at current level in first tree and n2 indicates
		// number of nodes in current level of second tree.
		int n1 = q1.size(), n2 = q2.size();

		// If n1 and n2 are different
		if (n1 != n2)
			return false;

		// If level order traversal is over
		if (n1 == 0)
			break;

		// Dequeue all Nodes of current level and
		// Enqueue all Nodes of next level
		while (n1--) {
			Node* node1 = q1.front();
			q1.pop();

			// Insert element into hashmap
			m[node1->data]++;

			// Insert left and right nodes into queue if
			// exists.
			if (node1->left != NULL)
				q1.push(node1->left);
			if (node1->right != NULL)
				q1.push(node1->right);
		}

		while (n2--) {
			Node* node2 = q2.front();
			q2.pop();

			// if element from second tree isn't present in
			// the first tree of same level then it can't be
			// an anagram.
			if (m.find(node2->data) == m.end())
				return false;

			// Reduce frequency of element if present else
			// adds it element to hash map with negative
			// frequency.
			m[node2->data]--;

			// If frequency of the element becomes zero then
			// remove the element from hashmap.
			if (m[node2->data] == 0)
				m.erase(node2->data);

			// Insert left and right nodes into queue if
			// exists.
			if (node2->left != NULL)
				q2.push(node2->left);
			if (node2->right != NULL)
				q2.push(node2->right);
		}

		// If nodes of current levels are anagrams the
		// hashmap wouldn't contain any elements.
		if (m.size() > 0)
			return false;
	}
if(q1.empty() && q2.empty())
	return true;
return false;
}

// Utility function to create a new tree Node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Constructing both the trees.
	struct Node* root1 = newNode(1);
	root1->left = newNode(3);
	root1->right = newNode(2);
	root1->right->left = newNode(5);
	root1->right->right = newNode(4);

	struct Node* root2 = newNode(1);
	root2->left = newNode(2);
	root2->right = newNode(3);
	root2->left->left = newNode(4);
	root2->left->right = newNode(5);

	areAnagrams(root1, root2) ? cout << "Yes" : cout << "No";
	return 0;
}
```
Output<br />
<pre>
Yes
</pre>
<pre>
Time complexity: O(N), where N is maximum number of nodes in either of the trees.
</pre>





<br /><br /><br />
## Problem 35:
**[Sum of minimum and maximum elements of all subarrays of size k](https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/)**<br />
Given an array of both `positive` and `negative integers`, the task is to _compute sum of minimum and maximum elements of all sub-array of size `k`_.<br />
Examples:<br />
<pre>
Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 4
Output : 18
Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     Sum of all min & max = 6 + 4 + 4 + 4 
                          = 18     
</pre>
<br />**Method 1 (Simple):**<br />
Run two loops to generate all subarrays of size `k` and find `maximum` and `minimum` values. Finally, return _sum of all maximum and minimum elements_.<br /> 
<pre>
Time taken by this solution is O(n*k).
</pre>
<br />**Method 2 (Efficient using Dequeue):**<br /> 
The idea is to use `Dequeue` data structure and `sliding window concept`. We create two `empty double-ended queues` of size `k` (`‘S’` , `‘G’`) that only store indices of elements of `current window` that are not useless. An element is useless if it can not be `maximum` or `minimum` of next subarrays.<br />
<pre>
 a) In deque 'G', we maintain decreasing order of 
    values from front to rear
 b) In deque 'S', we maintain increasing order of 
    values from front to rear

1) First window size K
  1.1) For deque 'G', if current element is greater 
       than rear end element, we remove rear while 
       current is greater.
  1.2) For deque 'S', if current element is smaller 
       than rear end element, we just pop it while 
       current is smaller.
  1.3) insert current element in both deque 'G' 'S'

2) After step 1, front of 'G' contains maximum element
   of first window and front of 'S' contains minimum 
   element of first window. Remaining elements of G
   and S may store maximum/minimum for subsequent 
   windows.

3) After that we do traversal for rest array elements.
  3.1) Front element of deque 'G' is greatest and 'S' 
       is smallest element of previous window 
  3.2) Remove all elements which are out of this 
       window [remove element at front of queue ]
  3.3) Repeat steps 1.1 , 1.2 ,1.3 

4) Return sum of minimum and maximum element of all 
   sub-array size k.
</pre>
Below is implementation of above idea<br />
```cpp
// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.
#include<bits/stdc++.h>
using namespace std;

// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int arr[] , int n , int k)
{
	int sum = 0; // Initialize result

	// The queue will store indexes of useful elements
	// in every window
	// In deque 'G' we maintain decreasing order of
	// values from front to rear
	// In deque 'S' we maintain increasing order of
	// values from front to rear
	deque< int > S(k), G(k);

	// Process first window of size K
	int i = 0;
	for (i = 0; i < k; i++)
	{
		// Remove all previous greater elements
		// that are useless.
		while ( (!S.empty()) && arr[S.back()] >= arr[i])
			S.pop_back(); // Remove from rear

		// Remove all previous smaller that are elements
		// are useless.
		while ( (!G.empty()) && arr[G.back()] <= arr[i])
			G.pop_back(); // Remove from rear

		// Add current element at rear of both deque
		G.push_back(i);
		S.push_back(i);
	}

	// Process rest of the Array elements
	for ( ; i < n; i++ )
	{
		// Element at the front of the deque 'G' & 'S'
		// is the largest and smallest
		// element of previous window respectively
		sum += arr[S.front()] + arr[G.front()];

		// Remove all elements which are out of this
		// window
		while ( !S.empty() && S.front() <= i - k)
			S.pop_front();
		while ( !G.empty() && G.front() <= i - k)
			G.pop_front();

		// remove all previous greater element that are
		// useless
		while ( (!S.empty()) && arr[S.back()] >= arr[i])
			S.pop_back(); // Remove from rear

		// remove all previous smaller that are elements
		// are useless
		while ( (!G.empty()) && arr[G.back()] <= arr[i])
			G.pop_back(); // Remove from rear

		// Add current element at rear of both deque
		G.push_back(i);
		S.push_back(i);
	}

	// Sum of minimum and maximum element of last window
	sum += arr[S.front()] + arr[G.front()];

	return sum;
}

// Driver program to test above functions
int main()
{
	int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << SumOfKsubArray(arr, n, k) ;
	return 0;
}
```
Output<br />
<pre>
14
</pre>
<pre>
Time Complexity: O(n)
Auxiliary Space: O(k)
</pre>





<br /><br /><br />
## Problem 36:
**[Minimum sum of squares of character counts in a given string after removing “k” characters.](https://practice.geeksforgeeks.org/problems/game-with-string4100/1)**<br />
Given a string `s` of lowercase alphabets and a number `k`, the task is to _print the `minimum value of the string` after removal of `‘k’` characters_. The value of a string is defined as the **sum of squares of the count of each distinct character**.<br />
 
>Example 1:<br />
Input: s = abccc, k = 1<br />
Output: 6<br />
Explaination: We remove c to get the value as 12 + 12 + 22<br />

>Example 2:<br />
Input: s = aabcbcbcabcc, k = 3<br />
Output: 27<br />
Explaination: We remove two 'c' and one 'b'. Now we get the value as 32 + 32 + 32.<br />

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `minValue()` which takes `s` and `k` as input parameters and returns _the minimum possible required value_.<br />

<pre>
Expected Time Complexity: O(N*logN)  where N is the length of string
Expected Auxiliary Space: O(N)
</pre>
 
* Constraints: `1 ≤ k ≤ |string length| ≤ 100`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minValue(string s, int k){
        map<char, int> mp;
        priority_queue<int> pq;
        for(int i = 0;i < s.size();i++)
            mp[s[i]]++;
        for(auto it = mp.begin();it != mp.end();it++)
            pq.push(it->second);
        while(k--){
            int x = pq.top();
            x--;
            pq.pop();
            pq.push(x);
        }
        int result = 0;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            result += (x*x);
        }
        return result;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int k; cin>>k;
        Solution ob;
        cout<<ob.minValue(s, k)<<endl;
    }
}
```









<br /><br /><br />
## Problem 37:
**[Queue based approach or first non-repeating character in a stream](https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1)**<br />
Given an **input stream** of `A` of `n` characters consisting only of **lower case alphabets**. The task is to find the `first non repeating character`, each time a character is **inserted** to the stream. If there is no such character then append `'#'` to the answer.<br />
 
>Example 1:<br />
Input: A = "aabc"<br />
Output: "a#bb"<br />
Explanation: For every character first non repeating character is as follow-<br />
"a" - first non-repeating character is 'a'<br />
"aa" - no non-repeating character so '#'<br />
"aab" - first non-repeating character is 'b'<br />
"aabc" - first non-repeating character is 'b'<br />

>Example 2:<br />
Input: A = "zz"<br />
Output: "z#"<br />
Explanation: For every character first non repeating character is as follow-<br />
"z" - first non-repeating character is 'z'<br />
"zz" - no non-repeating character so '#'<br />
 
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
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        Solution ob;
        cout<<ob.FirstNonRepeating(s)<<endl;
    }
}
```









<br /><br /><br />
## Problem 38:
**[Next Smaller Element](https://www.geeksforgeeks.org/next-smaller-element/)**<br />
Given an array, print the `Next Smaller Element (NSE)` for every element. The `NSE` for an element `x` is the first smaller element on the right side of `x` in array.<br />
Elements for which no `smaller element exist` (on right side), consider `NSE` as `-1`.<br /> 
Examples:<br />

	 a) For any array, **rightmost element always** has `NSE` as `-1`.<br /> 
 	 b) For an array which is sorted in increasing order, all elements have `NSE` as `-1`.<br /> 
	 c) For the input array `[4, 8, 5, 2, 25}`, the `NSE` for each element are as follows.<br />
 
 <pre>
 Element         NSE
   4      -->    2
   8      -->    5
   5      -->    2
   2      -->   -1
   25     -->   -1
 </pre>
 
 	 d) For the input array `[13, 7, 6, 12}`, the `next smaller elements` for each element are as follows.<br />
<pre>
  Element        NSE
   13      -->    7
   7       -->    6
   6       -->   -1
   12      -->   -1
</pre>
<br />**Method 1 (Simple)**<br />
`Use two loops:` The **outer loop picks** all the elements `one by one`. The `inner loop` looks for the first smaller element for the element **picked by outer loop**. If a `smaller element` is found then that element is printed as `next`, otherwise, `-1` is printed.<br />
```cpp
// Simple C++ program to print
// next smaller elements in a given array
#include "bits/stdc++.h"
using namespace std;

/* prints element and NSE pair
for all elements of arr[] of size n */
void printNSE(int arr[], int n)
{
	int next, i, j;
	for (i = 0; i < n; i++)
	{
		next = -1;
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				next = arr[j];
				break;
			}
		}
		cout << arr[i] << " -- " << next << endl;
	}
}

// Driver Code
int main()
{
	int arr[]= {11, 13, 21, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	printNSE(arr, n);
	return 0;
}
```
Output<br />
<pre>
11 -- 3
13 -- 3
21 -- 3
3 -- -1
</pre>
<pre>
Time Complexity: O(N^2)     
The worst case occurs when all elements are sorted in decreasing order.
Auxiliary Space: O(1) 
As constant extra space is used
</pre>
<br />**Method 2 (Using Segment Tree and Binary Search)**<br />
This method is also pretty simple if one knows `Segment trees and Binary Search`. Lets consider an array `a` and lets suppose `NSE` for `ai` is `aj`, we simply need to binary search for `j` in range `i + 1` to `n - 1`. `j` will be the first index `k` , such that range minimum of elements from index `i + 1` to `k` `forall k in [i+1, n - 1]`) is lesser than `ai`.<br />
```cpp
#include <bits/stdc++.h>
using namespace std;

// Program to find next smaller element for all elements in
// an array, using segment tree and binary search

// --------Segment Tree Starts Here-----------------

vector<int> seg_tree;

// combine function for combining two nodes of the tree, in
// this case we need to take min of two
int combine(int a, int b) { return min(a, b); }

// build function, builds seg_tree based on vector parameter
// arr
void build(vector<int>& arr, int node, int tl, int tr)
{
	// if current range consists only of one element, then
	// node should be this element
	if (tl == tr) {
		seg_tree[node] = arr[tl];
	}
	else {
		// divide the build operations into two parts
		int tm = (tr - tl) / 2 + tl;

		build(arr, 2 * node, tl, tm);
		build(arr, 2 * node + 1, tm + 1, tr);

		// combine the results from two parts, and store it
		// into current node
		seg_tree[node] = combine(seg_tree[2 * node], seg_tree[2 * node + 1]);
	}
}

// query function, returns minimum in the range [l, r]
int query(int node, int tl, int tr, int l, int r)
{
	// if range is invalid, then return infinity
	if (l > r) {
		return INT32_MAX;
	}

	// if range completely aligns with a segment tree node,
	// then value of this node should be returned
	if (l == tl && r == tr) {
		return seg_tree[node];
	}

	// else divide the query into two parts
	int tm = (tr - tl) / 2 + tl;

	int q1 = query(2 * node, tl, tm, l, min(r, tm));
	int q2 = query(2 * node + 1, tm + 1, tr, max(l, tm + 1),
				r);

	// and combine the results from the two parts and return
	// it
	return combine(q1, q2);
}

// --------Segment Tree Ends Here-----------------

void printNSE(vector<int> arr, int n)
{
	seg_tree = vector<int>(4 * n);

	// build segment tree initially
	build(arr, 1, 0, n - 1);

	int q, l, r, mid, ans;
	for (int i = 0; i < n; i++) {
		// binary search for ans in range [i + 1, n - 1],
		// initially ans is -1 representing there is no NSE
		// for this element
		l = i + 1;
		r = n - 1;
		ans = -1;

		while (l <= r) {
			mid = (r - l) / 2 + l;
			// q is the minimum element in range [l, mid]
			q = query(1, 0, n - 1, l, mid);

			// if the minimum element in range [l, mid] is
			// less than arr[i], then mid can be answer, we
			// mark it, and look for a better answer in left
			// half. Else if q is greater than arr[i], mid
			// can't be an answer, we should search in right
			// half

			if (q < arr[i]) {
				ans = arr[mid];
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		// print NSE for arr[i]
		cout << arr[i] << " ---> " << ans << "\n";
	}
}

// Driver program to test above functions
int main()
{
	vector<int> arr = { 11, 13, 21, 3 };
	printNSE(arr, 4);
	return 0;
}
```
Output<br />
<pre>
11 ---> 3
13 ---> 3
21 ---> 3
3 ---> -1
</pre>
<pre>
Time Complexity : O(N(log(N))^2)   
For each of n array elements we do a binary search, which includes log(N) steps, and each step costs log(N) operations [range minimum queries].
Auxiliary Space: O(N)
As extra space is used for storing the elements of the segment tree.
</pre>
<br />**Method 3 (Using Segment Tree and Coordinate Compression)**<br />
In this approach, we build a segment tree on indices of compressed array elements:<br />
<pre>
 1. Somewhere along the lines, we would build a array aux such-that aux[i] is the smallest index at which i is present in input array.
 2. Its easy to see that we need to compress the input array so as to build this array aux because if i 
    exceeds 10^7 (memory limit of online judge) chances are we would get a segmentation fault.
 3. To compress we sort the input array, and then for each new value seen in array we map it to a corresponding 
    smaller value, if possible. Use these mapped values to generate a compressed array with same order as input array.
 4. So now that we are done with compression, we can begin with the query part:
   * Suppose in previous step, we compressed the array to ctr distinct values. Initially set 
     aux[i] =  -1 forall i in [0, ctr), this signifies no value is processed at any index as of now.
   * Traverse the compressed array in reverse order, this would imply that in past we would have only 
     processed elements that are on the right side.
       * For compressed[i], query (and store in ans[i]) the smallest index of values [0, compressed[i]) using 
         segment tree, this must be the NSE for compressed[i]!
       * Update the index of compressed[i] to i.
 5. We stored the index of NSEs for all array elements, we can easily print NSEs themselves as shown in code.
</pre>
**Note:**In implementation we use `INT32_MAX` instead of `-1` because storing `INT32_MAX` doesn’t affect our min-segment tree and still serves the purpose of identifying unprocessed values.<br />
As `extra space` is used for storing the elements of the `segment tree`.<br />
```cpp
#include <bits/stdc++.h>
using namespace std;

// Program to find next smaller element for all elements in
// an array, using segment tree and coordinate compression

// --------Segment Tree Starts Here-----------------

vector<int> seg_tree;

// combine function for combining two nodes of the tree, in
// this case we need to take min of two
int combine(int a, int b) { return min(a, b); }

// build function, builds seg_tree based on vector parameter
// arr
void build(vector<int>& arr, int node, int tl, int tr)
{
	// if current range consists only of one element, then
	// node should be this element
	if (tl == tr) {
		seg_tree[node] = arr[tl];
	}
	else {
		// divide the build operations into two parts
		int tm = (tr - tl) / 2 + tl;

		build(arr, 2 * node, tl, tm);
		build(arr, 2 * node + 1, tm + 1, tr);

		// combine the results from two parts, and store it
		// into current node
		seg_tree[node] = combine(seg_tree[2 * node], seg_tree[2 * node + 1]);
	}
}

// update function, used to make a point update, update
// arr[pos] to new_val and make required changes to segtree
void update(int node, int tl, int tr, int pos, int new_val)
{
	// if current range only contains one point, this must
	// be arr[pos], update the corresponding node to new_val
	if (tl == tr) {
		seg_tree[node] = new_val;
	}
	else {
		// else divide the range into two parts
		int tm = (tr - tl) / 2 + tl;

		// if pos lies in first half, update this half, else
		// update second half
		if (pos <= tm) {
			update(2 * node, tl, tm, pos, new_val);
		}
		else {
			update(2 * node + 1, tm + 1, tr, pos, new_val);
		}

		// combine results from both halfs
		seg_tree[node] = combine(seg_tree[2 * node], seg_tree[2 * node + 1]);
	}
}

// query function, returns minimum in the range [l, r]
int query(int node, int tl, int tr, int l, int r)
{
	// if range is invalid, then return infinity
	if (l > r) {
		return INT32_MAX;
	}

	// if range completely aligns with a segment tree node,
	// then value of this node should be returned
	if (l == tl && r == tr) {
		return seg_tree[node];
	}

	// else divide the query into two parts
	int tm = (tr - tl) / 2 + tl;

	int q1 = query(2 * node, tl, tm, l, min(r, tm));
	int q2 = query(2 * node + 1, tm + 1, tr, max(l, tm + 1),
				r);

	// and combine the results from the two parts and return
	// it
	return combine(q1, q2);
}

// --------Segment Tree Ends Here-----------------

void printNSE(vector<int> original, int n)
{
	vector<int> sorted(n);
	map<int, int> encode;

	// -------Coordinate Compression Starts Here ------

	// created a temporary sorted array out of original
	for (int i = 0; i < n; i++) {
		sorted[i] = original[i];
	}
	sort(sorted.begin(), sorted.end());

	// encode each value to a new value in sorted array
	int ctr = 0;
	for (int i = 0; i < n; i++) {
		if (encode.count(sorted[i]) == 0) {
			encode[sorted[i]] = ctr++;
		}
	}

	// use encode to compress original array
	vector<int> compressed(n);
	for (int i = 0; i < n; i++) {
		compressed[i] = encode[original[i]];
	}

	// -------Coordinate Compression Ends Here ------

	// Create an aux array of size ctr, and build a segtree
	// based on this array

	vector<int> aux(ctr, INT32_MAX);
	seg_tree = vector<int>(4 * ctr);

	build(aux, 1, 0, ctr - 1);

	// For each compressed[i], query for index of NSE and
	// update segment tree

	vector<int> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = query(1, 0, ctr - 1, 0, compressed[i] - 1);
		update(1, 0, ctr - 1, compressed[i], i);
	}

	// Print -1 if NSE doesn't exist, otherwise print NSE
	// itself

	for (int i = 0; i < n; i++) {
		cout << original[i] << " ---> ";
		if (ans[i] == INT32_MAX) {
			cout << -1;
		}
		else {
			cout << original[ans[i]];
		}
		cout << "\n";
	}
}

// Driver program to test above functions
int main()
{
	vector<int> arr = { 11, 13, 21, 3 };
	printNSE(arr, 4);
	return 0;
}
```
Output<br />
<pre>
11 ---> 3
13 ---> 3
21 ---> 3
3 ---> -1
</pre>
<pre>
Time Complexity: O(Nlog(N))      
Auxiliary Space: O(N)
</pre>
<br />**Method 4 (Using Stack)**<br />
This problem is `similar to next greater element`. Here we **maintain items in increasing order** in the `stack` (`instead of decreasing in next greater element` problem).<br />

 1. Push the **first element** to stack.<br />
 2. Pick rest of the elements one by one and follow following steps in loop.<br />
   * Mark the `current element as next`.<br />
   * If `stack is not empty`, then `compare` **next with stack top**. If `next is smaller` than top then `next is the NSE for the top`. Keep `popping` from the stack while `top is greater than next`. **next becomes the NSE** for all such `popped elements`<br />
   * Push `next into the stack`<br />
 3. After the loop in step 2 is over, `pop all the elements from stack` and print `-1` as next element for them.<br />
 
**Note:** To achieve same order, we use a stack of pairs, where first element is the value and second element is index of array element.<br />
```cpp
// A Stack based C++ program to find next
// smaller element for all array elements
#include <bits/stdc++.h>
using namespace std;

// prints NSE for elements of array arr[] of size n

void printNSE(int arr[], int n)
{
	stack<pair<int, int> > s;
	vector<int> ans(n);

	// iterate for rest of the elements
	for (int i = 0; i < n; i++) {
		int next = arr[i];

		// if stack is empty then this element cant be NSE
		// for any other element, so just push it to stack
		// so that we can find NSE for it, and continue
		if (s.empty()) {
			s.push({ next, i });
			continue;
		}

		// while stack is not empty and the top element is
		// greater than next
		// a) NSE for top is next, use tops index to
		// maintain original order
		// b) pop the top element from stack

		while (!s.empty() && s.top().first > next) {
			ans[s.top().second] = next;
			s.pop();
		}

		// push next to stack so that we can find NSE for it

		s.push({ next, i });
	}

	// After iterating over the loop, the remaining elements
	// in stack do not have any NSE, so set -1 for them

	while (!s.empty()) {
		ans[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ---> " << ans[i] << endl;
	}
}

// Driver program to test above functions
int main()
{
	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNSE(arr, n);
	return 0;
}
```
Output<br />
<pre>
11 ---> 3
13 ---> 3
21 ---> 3
3 ---> -1
</pre>
<pre>
Time Complexity: O(N)    
As we use only single for loop and all the elements in the stack are push and popped atmost once.
Auxiliary Space: O(N)
As extra space is used for storing the elements of the stack.
</pre>
