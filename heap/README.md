# Love Babbar Sheet 450 - Heap
## Problem 1:
**[Implement a Maxheap/MinHeap using arrays and recursion.](https://www.geeksforgeeks.org/building-heap-from-array/)**<br />
Given an array of `N` elements. The task is to build a Binary Heap from the given array. The heap can be either `Max Heap` or `Min Heap`.<br />
Examples:<br /> 
<pre>
Input: arr[] = {4, 10, 3, 5, 1}
Output: Corresponding Max-Heap:

       10
     /   \
   5     3
  /  \
4    1

Input: arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
Output: Corresponding Max-Heap:

                 17
              /      \
          15         13
         /    \      /  \
       9      6    5   10
     / \    /  \
   4   8  3    1
</pre>
**Note**<br />
<pre>
 * Root is at index 0 in array.
 * Left child of i-th node is at (2*i + 1)th index.
 * Right child of i-th node is at (2*i + 2)th index.
 * Parent of i-th node is at (i-1)/2 index.
</pre>
`Naive Approach:` **To solve the problem follow the below idea:**<br />
<pre>
To build a Max-Heap from the above-given array elements, It can be clearly seen that the above complete binary tree 
formed does not follow the Heap property. So, the idea is to heapify the complete binary tree formed 
from the array in reverse level order following a top-down approach. That is first heapify, the last node 
in level order traversal of the tree, then heapify the second last node and so on. 
</pre>
`Time Complexity Analysis:`<br />
Heapify a single node takes **O(log N)** time complexity where `N` is the total number of Nodes. Therefore, building the entire Heap will take `N` heapify operations and the total time complexity will be `O(N*logN)`.<br />
`Efficient Approach:` **To solve the problem using this approach follow the below idea:**<br />
<pre>
The above approach can be optimized by observing the fact that the leaf nodes 
need not to be heapified as they already follow the heap property. Also, the 
array representation of the complete binary tree contains the level order 
traversal of the tree. So the idea is to find the position of the last non-leaf node 
and perform the heapify operation of each non-leaf node in reverse level order. 
 
Last non-leaf node = parent of last-node.
or, Last non-leaf node = parent of node at (n-1)th index.
or, Last non-leaf node = Node at index ((n-1) – 1)/2 = (n/2) – 1.
</pre>
**Heapify Illustration:**<br />
<pre>
Array = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
Corresponding Complete Binary Tree is:

                 1
              /     \
           3         5
        /    \     /  \
      4      6   13  10
     / \    / \
   9   8  15 17

The task to build a Max-Heap from above array.

Total Nodes = 11.
Last Non-leaf node index = (11/2) – 1 = 4.
Therefore, last non-leaf node = 6.

To build the heap, heapify only the nodes: [1, 3, 5, 4, 6] in reverse order.

Heapify 6: Swap 6 and 17.

                 1
              /     \
           3         5
        /    \      /  \
     4      17   13  10
    / \    /  \
  9   8  15   6

Heapify 4: Swap 4 and 9.

                 1
              /     \
           3         5
        /    \      /  \
     9      17   13  10
    / \    /  \
  4   8  15   6

Heapify 5: Swap 13 and 5.

                 1
              /     \
           3         13
        /    \      /  \
     9      17   5   10
    / \    /  \
 4   8  15   6

Heapify 3: First Swap 3 and 17, again swap 3 and 15.

                 1
             /     \
        17         13
       /    \      /  \
    9      15   5   10
   / \    /  \
 4   8  3   6

Heapify 1: First Swap 1 and 17, again swap 1 and 15, finally swap 1 and 6.

                 17
              /      \
          15         13
         /    \      /  \
       9      6    5   10
      / \    /  \
    4   8  3    1
</pre>
Below is the implementation of the above approach:<br />
```cpp
// C++ program for building Heap from Array

#include <bits/stdc++.h>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify(int arr[], int N, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < N && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, N, largest);
	}
}

// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int N)
{
	// Index of last non-leaf node
	int startIdx = (N / 2) - 1;

	// Perform reverse level order traversal
	// from last non-leaf node and heapify
	// each node
	for (int i = startIdx; i >= 0; i--) {
		heapify(arr, N, i);
	}
}

// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int N)
{
	cout << "Array representation of Heap is:\n";

	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver Code
int main()
{
	// Binary Tree Representation
	// of input array
	//		  1
	//	    	 / \
	//	        3   5
	//	      /  \	/ \
	//	     4	 6 13  10
	//      / \ / \
	//     9  8 15 17
	int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	buildHeap(arr, N);
	printHeap(arr, N);

	// Final Heap:
	//		     17
	//		    / \
	//		  15   13
	//		 / \   / \
	//	    9	6 5  10
	//	   / \ / \
	//	  4  8 3  1

	return 0;
}
```
Output<br />
<pre>
Array representation of Heap is:
17 15 13 9 6 5 10 4 8 3 1 
</pre>
<pre>
Time Complexity: O(N)
Auxiliary Space: O(N)
</pre>




<br /><br /><br />
## Problem 2:
**[Sort an Array using heap. (HeapSort)](https://www.geeksforgeeks.org/heap-sort/)**<br />
**What is Heap Sort**<br />
<pre>
Heap sort is a comparison-based sorting technique based on Binary Heap data 
structure. It is similar to the selection sort where we first find the minimum 
element and place the minimum element at the beginning. Repeat the same 
process for the remaining elements.
</pre>

 * Heap sort is an in-place algorithm.<br />
 * Its typical implementation is not stable, but can be made stable<br />
 * Typically 2-3 times slower than well-implemented `QuickSort`.  The reason for slowness is a lack of locality of reference.<br />

**Advantages of heapsort:**<br />

 * **Efficiency** –  The time required to perform Heap sort increases `logarithmically` while other algorithms may grow exponentially slower as the number of items to sort increases. This sorting algorithm is very efficient.<br />
 * **Memory Usage** – Memory usage is minimal because apart from what is necessary to hold the initial list of items to be sorted, it needs no additional memory space to work<br />
 * **Simplicity** –  It is simpler to understand than other equally efficient sorting algorithms because it does not use advanced computer science concepts such as `recursion`.<br />

**Applications of HeapSort:**<br />

 * Heapsort is mainly used in hybrid algorithms like the `IntroSort`.<br />
 * `Sort a nearly sorted (or K sorted) array` <br />
 * `k largest(or smallest) elements in an array` <br />

The heap sort algorithm has limited uses because `Quicksort` and `Mergesort` are better in practice. Nevertheless, the Heap data structure itself is enormously used.<br />
**What is meant by Heapify?**<br />
Heapify is the process of creating a heap data structure from a `binary tree` represented using an `array`. It is used to create `Min-Heap` or `Max-heap`. Start from the first index of the `non-leaf node` whose index is given by `n/2 – 1`. Heapify uses `recursion`.<br />
**Algorithm for Heapify:**<br />
<pre>
heapify(array)
 Root = array[0]

   Largest = largest( array[0] , array [2 * 0 + 1]/ array[2 * 0 + 2])
if(Root != Largest)
 Swap(Root, Largest)
</pre>
**How does Heapify work?**<br />
<pre>
Array = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
Corresponding Complete Binary Tree is:

                 1
              /     \
           3         5
        /    \     /  \
      4      6   13  10
     / \    / \
   9   8  15 17

The task to build a Max-Heap from above array.

Total Nodes = 11.
Last Non-leaf node index = (11/2) – 1 = 4.
Therefore, last non-leaf node = 6.

To build the heap, heapify only the nodes: [1, 3, 5, 4, 6] in reverse order.

Heapify 6: Swap 6 and 17.

                 1
              /     \
           3         5
        /    \      /  \
     4      17   13  10
    / \    /  \
  9   8  15   6

Heapify 4: Swap 4 and 9.

                 1
              /     \
           3         5
        /    \      /  \
     9      17   13  10
    / \    /  \
  4   8  15   6

Heapify 5: Swap 13 and 5.

                 1
              /     \
           3         13
        /    \      /  \
     9      17   5   10
    / \    /  \
 4   8  15   6

Heapify 3: First Swap 3 and 17, again swap 3 and 15.

                 1
             /     \
        17         13
       /    \      /  \
    9      15   5   10
   / \    /  \
 4   8  3   6

Heapify 1: First Swap 1 and 17, again swap 1 and 15, finally swap 1 and 6.

                 17
              /      \
          15         13
         /    \      /  \
       9      6    5   10
      / \    /  \
    4   8  3    1
</pre>
`Heap Sort Algorithm`<br />
**To solve the problem follow the below idea:**<br />
<pre>
 First convert the array into heap data structure using heapify, than one by one 
 delete the root node of the Max-heap and replace it with the last node in the 
 heap and then heapify the root of the heap. Repeat this process until size of 
 heap is greater than 1.
</pre>
**Follow the given steps to solve the problem:**<br />

 * Build a max heap from the input data.<br /> 
 * At this point, the maximum element is stored at the root of the heap. Replace it with the `last` item of the heap followed by reducing the size of the heap by `1`. Finally, heapify the `root` of the tree.<br /> 
 * Repeat step 2 while the size of the `heap` is **greater than 1**.<br />

**Note:** The heapify procedure can only be applied to a node if its `children nodes` are heapified. So the heapification must be performed in the `bottom-up order`.<br />
**Detailed Working of Heap Sort**<br />
<pre>
To understand heap sort more clearly, let’s take an unsorted array and try to 
sort it using heap sort.
Consider the array: arr[] = {4, 10, 3, 5, 1}.
_**Build Complete Binary Tree:**_ Build a complete binary tree from the array.
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20220802165905/1.png"><br />
</pre>














<br /><br /><br />
## Problem 3:
**[]()**<br />

<br /><br /><br />
## Problem 4:
**[]()**<br />

<br /><br /><br />
## Problem 5:
**[]()**<br />

<br /><br /><br />
## Problem 6:
**[]()**<br />

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
