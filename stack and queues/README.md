# Stacks and Queues
**[1. Implement Stack from Scratch](https://www.tutorialspoint.com/javaexamples/data_stack.htm)**<br />

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



<br /><br /><br />**[2. Implement Queue from Scratch](https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/)**<br />
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


 
