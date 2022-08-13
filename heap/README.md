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
Build Complete Binary Tree:  Build a complete binary tree from the array.
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20220802165905/1.png"><br /> 
          Build complete binary tree from the array

Transform into max heap: After that, the task is to construct a tree from that unsorted 
array and try to convert it into max heap.
 * To transform a heap into a max-heap, the parent node should always be 
   greater than or equal to the child nodes
    * Here, in this example, as the parent node 4 is smaller than the child node 
      10, thus, swap them to build a max-heap.
      
Transform it into a max heap image widget
 * Now, as seen, 4 as a parent is smaller than the child 5, thus swap both of 
   these again and the resulted heap and array should be like this:
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20220802170448/3.png"><br />
          Make the tree a max heap
	
Perform heap sort: Remove the maximum element in each step (i.e., move it to 
the end position and remove that) and then consider the remaining elements 
and transform it into a max heap.
 * Delete the root element (10) from the max heap. In order to delete this 
   node, try to swap it with the last node, i.e. (1). After removing the root 
   element, again heapify it to convert it into max heap.
    * Resulted heap and array should look like this:
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20220802170744/4.png"><br />
           Remove 10 and perform heapify
	   
  * Repeat the above steps and it will look like the following:
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20220802170850/5.png"><br />
           Remove 5 and perform heapify

  * Now remove the root (i.e. 3) again and perform heapify.
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20220802171042/6.png"><br />
           Remove 4 and perform heapify
	   
  * Now when the root is removed once again it is sorted. and the sorted array 
    will be like arr[] = {1, 3, 4, 5, 10}.
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20220802171331/7.png"><br />
           The sorted array
</pre>
**Implementation of Heap Sort**<br />
Below is the implementation of the above approach:<br />
```cpp
// C++ program for implementation of Heap Sort

#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest
	// so far
	if (r < N && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

	// Build heap (rearrange array)
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	// One by one extract an element
	// from heap
	for (int i = N - 1; i > 0; i--) {

		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver's code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr, N);

	cout << "Sorted array is \n";
	printArray(arr, N);
}
```
Output<br />
<pre>
Sorted array is 
5 6 7 11 12 13 
</pre>
<pre>
Time Complexity: O(N log N)
Auxiliary Space: O(1)
</pre>
<br />**Some FAQs related to Heap Sort**<br />

**What are the two phases of Heap Sort?**<br />
The heap sort algorithm consists of two phases. In the first phase the array is <br />
converted into a max heap. And in the second phase the highest element is removed <br />
(i.e., the one at the tree root) and the remaining elements are used to create a new <br />
max heap.<br />

**Why Heap Sort is not stable?**<br />
Heap sort algorithm is not a stable algorithm. This algorithm is not stable because <br />
the operations that are performed in a heap can change the relative ordering of the <br />
equivalent keys.<br />

**Is Heap Sort an example of “Divide and Conquer” algorithm?**<br />
Heap sort is NOT at all a Divide and Conquer algorithm. It uses a heap data structure <br />
to efficiently sort its element and not a “divide and conquer approach” to sort the <br />
elements.<br />

**Which sorting algorithm is better – Heap sort or Merge Sort?**<br />
The answer lies in the comparison of their time complexity and space requirement. <br />
The Merge sort is slightly faster than the Heap sort. But on the other hand merge sort <br />
takes extra memeory. Depending on the requirement, one should choose which one <br />
to use.<br />

**Why Heap sort better than Selection sort?**<br />
Heap sort is similar to selection sort, but with a better way to get the maximum <br />
element. It takes advantage of the heap data structure to get the maximum element in <br />
constant time.<br />











<br /><br /><br />
## Problem 3:
**[Sliding Window Maximum (Maximum of all subarrays of size k)](https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/)**<br />
Given an `array` and an integer `K`, find the **maximum** for each and every **contiguous subarray** of size `k`.<br />
Examples :<br /> 
<img src = "https://videocdn.geeksforgeeks.org/geeksforgeeks/MaximumofallsubarraysofsizekusingSlidingWindowTechnique/MaximumofallsubarraysofsizekusingSlidingWindowTechnique20220511150022.jpg"><br />
<pre>
Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
Output: 3 3 4 5 5 5 6
Explanation: 
Maximum of 1, 2, 3 is 3
Maximum of 2, 3, 1 is 3
Maximum of 3, 1, 4 is 4
Maximum of 1, 4, 5 is 5
Maximum of 4, 5, 2 is 5 
Maximum of 5, 2, 3 is 5
Maximum of 2, 3, 6 is 6

Input: arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, K = 4 
Output: 10 10 10 15 15 90 90
Explanation:
Maximum of first 4 elements is 10, similarly for next 4 
elements (i.e from index 1 to 4) is 10, So the sequence 
generated is 10 10 10 15 15 90 90
</pre>
<br /><br />**Method 1:** This is a simple method to solve the above problem.<br />
**Approach:**<br />
The idea is very basic run a nested loop, the outer loop which will mark the starting point of the subarray of length `k`, the inner loop will run from the starting index to `index+k`, `k` elements from **starting index** and print the `maximum` element among these `k` elements.<br />
**Algorithm:**<br />

 1. Create a nested loop, the outer loop from starting index to `n – k` th elements. The inner loop will run for `k` iterations.<br />
 2. Create a variable to store the maximum of `k` elements traversed by the inner loop.<br />
 3. Find the maximum of `k` elements traversed by the inner loop.<br />
 4. Print the maximum element in every iteration of outer loop<br />

**Implementation:**<br />
```cpp
// C++ Program to find the maximum for
// each and every contiguous subarray of size k.
#include <bits/stdc++.h>
using namespace std;

// Method to find the maximum for each
// and every contiguous subarray of size k.
void printKMax(int arr[], int n, int k)
{
	int j, max;

	for (int i = 0; i <= n - k; i++)
	{
		max = arr[i];

		for (j = 1; j < k; j++)
		{
			if (arr[i + j] > max)
				max = arr[i + j];
		}
		cout << max << " ";
	}
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	printKMax(arr, n, k);
	return 0;
}
```
Output<br />
<pre>
3 4 5 6 7 8 9 10 
</pre>
<pre>
Complexity Analysis: 
 * Time Complexity: O(N * K). 
   The outer loop runs n-k+1 times and the inner loop runs k times for every iteration 
   of outer loop. So time complexity is O((n-k+1)*k) which can also be written as 
   O(N * K).
 * Space Complexity: O(1). 
   No extra space is required.
</pre>

<br /><br />**Method 2:** This method uses the Self-Balancing BST to solve the given problem.<br />
**Approach:**<br />
To find maximum among `k` elements of the subarray the previous method uses a loop traversing through the elements. To reduce that time the idea is to use an `AVL tree` which returns _the maximum element in `log n` time_. So, traverse through the array and keep `k` elements in the `BST` and print the **maximum** in every iteration. `AVL tree` is a suitable data structure as `lookup`, `insertion`, and `deletion` all take `O(log n)` time in both the `average` and `worst` cases, where `n` is the **number of nodes** in the tree prior to the operation.<br />
<br />**Algorithm:**<br />

 1. Create a `Self-balancing BST (AVL tree)` to store and find the **maximum** element.<br />
 2. **Traverse** through the array from start to end.<br />
 3. Insert the element in the `AVL tree`.<br />
 4. If the loop counter is greater than or equal to `k` then delete `i-k` th element from the **BST**<br />
 5. Print the **maximum element** of the **BST**.<br />

**Implementation:**<br />
```cpp
// C++ program to delete a node from AVL Tree
#include<bits/stdc++.h>
using namespace std;

// An AVL tree node
class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};

// A utility function to get maximum
// of two integers
int max(int a, int b);

// A utility function to get height
// of the tree
int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */
Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially
					// added at leaf
	return(node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) -
		height(N->right);
}

Node* insert(Node* node, int key)
{
	/* 1. Perform the normal BST rotation */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys not allowed
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), height(node->right));

	/* 3. Get the balance factor of this
		ancestor node to check whether
		this node became unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced,
	// then there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
Node * minValueNode(Node* node)
{
	Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

// Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
Node* deleteNode(Node* root, int key)
{
	
	// STEP 1: PERFORM STANDARD BST DELETE
	if (root == NULL)
		return root;

	// If the key to be deleted is smaller
	// than the root's key, then it lies
	// in left subtree
	if ( key < root->key )
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater
	// than the root's key, then it lies
	// in right subtree
	else if( key > root->key )
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then
	// This is the node to be deleted
	else
	{
		// node with only one child or no child
		if( (root->left == NULL) ||
			(root->right == NULL) )
		{
			Node *temp = root->left ? root->left : 	root->right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
			*root = *temp; // Copy the contents of
						// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			Node* temp = minValueNode(root->right);

			// Copy the inorder successor's
			// data to this node
			root->key = temp->key;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->key);
		}
	}

	// If the tree had only one node
	// then return
	if (root == NULL)
	return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left), height(root->right));

	// STEP 3: GET THE BALANCE FACTOR OF
	// THIS NODE (to check whether this
	// node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced,
	// then there are 4 cases

	// Left Left Case
	if (balance > 1 &&
		getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 &&
		getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 &&
		getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 &&
		getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void preOrder(Node *root)
{
	if(root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

// Returns maximum value in a given
// Binary Tree
int findMax(Node* root)
{
	// Base case
	if (root == NULL)
	return INT_MIN;

	// Return maximum of 3 values:
	// 1) Root's data 2) Max in Left Subtree
	// 3) Max in right subtree
	int res = root->key;
	int lres = findMax(root->left);
	int rres = findMax(root->right);
	if (lres > res)
	res = lres;
	if (rres > res)
	res = rres;
	return res;
}

// Method to find the maximum for each
// and every contiguous subarray of size k.
void printKMax(int arr[], int n, int k)
{
	int c = 0,l=0;
	Node *root = NULL;

	
	//traverse the array ;
	for(int i=0; i<n; i++)
	{
		c++;
		//insert the element in BST
		root = insert(root, arr[i]);
		
		//size of subarray greater than k
		if(c > k)
		{
			root = deleteNode(root, arr[l++]);
			c--;
		}
		
		//size of subarray equal to k
		if(c == k)
		{
			cout<<findMax(root)<<" ";
		}
	}
}
// Driver code
int main()
{
	int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, k = 4;
	int n = sizeof(arr) / sizeof(arr[0]);
	printKMax(arr, n, k);
	return 0;
}
```
Output<br />
<pre>
10 10 10 15 15 90 90 
</pre>
<pre>
Complexity Analysis:   
 * Time Complexity: O(N * Log k). 
   Insertion, deletion and search takes log k time in a AVL tree. So the overall time 
   Complexity is O(N * log k)
 * Space Complexity: O(k). 
   The space required to store k elements in a BST is O(k).
</pre>
<br /><br />**Method 3:** This method uses `Deque` to solve the above problem<br />
**Approach:**<br /> 
Create a Deque, `Qi` of capacity `k`, that stores only useful elements of current window of `k` elements. An element is useful if it is in current window and is greater than all other elements on right side of it in current window. Process all array elements one by one and maintain `Qi` to contain useful elements of current window and these useful elements are maintained in sorted order. The element at front of the `Qi` is the largest and element at rear/back of `Qi` is the smallest of current window.<br />
**Dry run of the above approach:**<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190626175333/SlidingWindowMaximum.png"><br />
<br />**Algorithm:**<br />

 1. Create a `deque` to store `k` elements.<br />
 2. Run a loop and insert `first k` elements in the `deque`. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque, until all elements left in the `deque` are **greater than** the current element. Then insert the current element, at the back of the `deque`.<br />
 3. Now, run a loop from `k` to end of the array.<br />
 4. Print the front element of the `deque`.<br />
 5. Remove the element from the front of the `queue` if they are out of the current window.<br />
 6. Insert the next element in the deque. Before inserting the element, check if the element at the back of the `queue` is **smaller than** the current element, if it is so remove the element from the back of the `deque`, until all elements left in the `deque` are **greater than** the current element. Then `insert` the current element, at the back of the `deque`.<br />
 7. Print the **maximum** element of the last window.<br />

**Implementation:**<br />
```cpp
// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// A Dequeue (Double ended queue) based
// method for printing maximum element of
// all subarrays of size k
void printKMax(int arr[], int n, int k)
{
	
	// Create a Double Ended Queue,
	// Qi that will store indexes
	// of array elements
	// The queue will store indexes
	// of useful elements in every
	// window and it will
	// maintain decreasing order of
	// values from front to rear in Qi, i.e.,
	// arr[Qi.front[]] to arr[Qi.rear()]
	// are sorted in decreasing order
	std::deque<int> Qi(k);

	/* Process first k (or first window)
	elements of array */
	int i;
	for (i = 0; i < k; ++i)
	{
	
		// For every element, the previous
		// smaller elements are useless so
		// remove them from Qi
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
		
			// Remove from rear
			Qi.pop_back();

		// Add new element at rear of queue
		Qi.push_back(i);
	}

	// Process rest of the elements,
	// i.e., from arr[k] to arr[n-1]
	for (; i < n; ++i)
	{
	
		// The element at the front of
		// the queue is the largest element of
		// previous window, so print it
		cout << arr[Qi.front()] << " ";

		// Remove the elements which
		// are out of this window
		while ((!Qi.empty()) && Qi.front() <= i - k)
		
			// Remove from front of queue
			Qi.pop_front();

		// Remove all elements
		// smaller than the currently
		// being added element (remove
		// useless elements)
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back();

		// Add current element at the rear of Qi
		Qi.push_back(i);
	}

	// Print the maximum element
	// of last window
	cout << arr[Qi.front()];
}

// Driver code
int main()
{
	int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	printKMax(arr, n, k);
	return 0;
}
```
Output<br />
<pre>
78 90 90 90 89
</pre>
<pre>
Complexity Analysis: 

 * Time Complexity: O(n). 
   It seems more than O(n) at first look. It can be observed that every element of 
   array is added and removed at most once. So there are total 2n operations.
 * Auxiliary Space: O(k). 
   Elements stored in the dequeue take O(k) space.
</pre>
<br /><br />**Method 4:** This method is modification in `queue` implementation of two stack:<br />
**Algorithm :**<br />

 * While pushing the element, we constantly push in stack `2`. The maximum of stack `2` will always be the **maximum** of the top element of stack `2`.<br />
 * While popping, we will always pop from stack `1`, and if stack `1` is empty then we shall push every element of stack `2` to stack `1` and updating the maximum<br />
 * The above two-step are followed in queue implementation of `stack`<br />
 * Now to find the maximum of the whole queue (Same as both stack), we will take the top element of both stack maximum; hence this is the **maximum** of the whole `queue`.<br />
 * Now, this technique can be used to **slide window** and get `maximum`.<br />
 * while sliding window by `1` index delete the last one, insert the new one and then take a **maximum** of both stack<br />

**Implementation**<br />
```cpp
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	int maximum;
};

// it is a modification in the way of implementation of queue using two stack

void insert(stack<node> &s2 , int val)
{
	//inserting the element in s2
	node other;
	other.data=val;
	
	if(s2.empty()) other.maximum=val;
	else
	{
		node front=s2.top();
		//updating maximum in that stack push it
		other.maximum=max(val,front.maximum);
	}
	s2.push(other);
	return;
}

void delete(stack<node> &s1 ,stack<node> &s2 )
{
	//if s1 is not empty directly pop
	//else we have to push all element from s2 and thatn pop from s1
	//while pushing from s2 to s1 update maximum variable in s1
	if(s1.size()) s1.pop();
	else
	{
		while(!s2.empty())
		{
			node val=s2.top();
			insert(s1,val.data);
			s2.pop();
		}
		s1.pop();
	}
}

int get_max(stack<node> &s1 ,stack<node> &s2 )
{
	// the maximum of both stack will be the maximum of overall window
	int ans=-1;
	if(s1.size()) ans=max(ans,s1.top().maximum);
	if(s2.size()) ans=max(ans,s2.top().maximum);
	return ans;
}


vector<int> slidingMaximum(int a[], int b,int n) {
	//s2 for push
	//s1 for pop
	vector<int>ans;
	stack<node>s1,s2;
	
	//shifting all value except the last one if first window
	for(int i=0;i<b-1;i++) insert(s2,a[i]);
	
	for(int i=0;i<=n-b;i++)
	{
		//removing the last element of previous window as window has shift by one
		if(i-1>=0) delete(s1,s2);
		
		//adding the new element to the window as the window is shift by one
		insert(s2,a[i+b-1]);
		
		ans.push_back(get_max(s1,s2));
	}
	return ans;
}

int main()
{
	int arr[] = { 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	vector<int> ans=slidingMaximum(arr,k,n);
	for(auto x:ans) cout<<x<<" ";
	return 0;
}
```
Output<br />
<pre>
78 90 90 90 89 
</pre>
<pre>
Complexity Analysis: 

 * Time Complexity: O(N): This is because every element will just two types push and pop; 
   hence time complexity is linear. 
 * Space Complexity: O(K): This is because at any moment, the sum of stack size of 
   both stacks will exactly equal to K, As every time we pop exactly one element and 
   push exactly One.
</pre>
<br /><br />**Method 5:** This method uses `Max-Heap` to solve the above problem.<br />
**Approach:**<br />
In the above-mentioned methods, one of them was using `AVL tree`. This approach is very similar to that approach. The difference is that instead of using the `AVL tree`, `Max-Heap` will be used in this approach. The elements of the current window will be stored in the `Max-Heap` and the **maximum** element or the root will be printed in each iteration. <br />
`Max-heap` is a suitable data structure as it provides **constant-time retrieval** and **logarithmic** time removal of both the **minimum** and **maximum** elements in it, i.e. it takes constant time to find the **maximum** element, and **insertion** and **deletion** takes `log n` time.  <br />

<br />**Algorithm:**<br />
 1. Pick first `k` elements and create a max heap of size `k`.<br />
 2. Perform `heapify` and print the root element.<br />
 3. Store the next and last element from the array<br />
 4. Run a loop from `k – 1` to `n` <br />
     * Replace the value of element which is got out of the window with new element which came inside the window.<br />
     * Perform heapify.<br />
     * Print the root of the Heap.<br />





<br /><br /><br />
## Problem 4:
**[“k” largest element in an array](https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1)**<br />
Given an array `Arr` of `N` positive integers, find `K` largest elements from the array.  The output elements should be printed in **decreasing order**.<br />

>Example 1:<br />
Input:<br />
N = 5, K = 2<br />
Arr[] = {12, 5, 787, 1, 23}<br />
Output: 787 23<br />
Explanation: 1st largest element in the array is 787 and second largest is 23.<br />

>Example 2:<br />
Input:<br />
N = 7, K = 3<br />
Arr[] = {1, 23, 12, 9, 30, 2, 50}<br />
Output: 50 30 23<br />
Explanation: 3 Largest element in the array are 50, 30 and 23.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `kLargest()` which takes the array of integers `arr`, `n` and `k` as parameters and returns _an array of integers denoting the answer_. The array should be in **decreasing order**.<br />

<pre>
Expected Time Complexity: O(N + KlogK)
Expected Auxiliary Space: O(K+(N-K)*logK)
</pre>

* Constraints: `1 ≤ K ≤ N ≤ 10^5`<br />
`1 ≤ Arr[i] ≤ 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> kLargest(int arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            if (pq.size() == k) {
                if (pq.top() < arr[i]) {
                    pq.pop();
                    pq.push(arr[i]);
                }
            } else {
                pq.push(arr[i]);
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for(auto x : ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
```







<br /><br /><br />
## Problem 5:
**[K’th Smallest/Largest Element in Unsorted Array](https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/)**<br />
Given an `array` and a number `k` where `k` is **smaller than** the `size of the array`, we need to find the `k’th` smallest element in the given array. It is given that all array elements are distinct.<br />
Examples:<br />
<pre>
Input: arr[] = {7, 10, 4, 3, 20, 15}, k = 3 
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15}, k = 4 
Output: 10 
</pre>
<br /><br />**Method 1** `(Simple Solution)`<br />
A simple solution is to sort the given array using an `O(N log N)` sorting algorithm like `Merge Sort`, `Heap Sort`, etc, and return _the element at index `k-1` in the sorted array_. <br />
The Time Complexity of this solution is `O(N log N)`<br />
```cpp
// Simple C++ program to find k'th smallest element
#include <bits/stdc++.h>
using namespace std;

// Function to return k'th smallest element in a given array
int kthSmallest(int arr[], int n, int k)
{
	// Sort the given array
	sort(arr, arr + n);

	// Return k'th element in the sorted array
	return arr[k - 1];
}

// Driver program to test above methods
int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int n = sizeof(arr) / sizeof(arr[0]), k = 2;
	cout << "K'th smallest element is " << kthSmallest(arr, n, k);
	return 0;
}
```
Output<br />
<pre>
K'th smallest element is 5
</pre>
<br /><br />**Method 2** `(using set from C++ STL)`<br />
we can find the `kth` smallest element in time complexity better than `O(N log N)`. we know the Set in **C++ STL** is implemented using **Binary Search Tree** and we also know that the time complexity of all cases(**searching**, **inserting**, **deleting** ) in `BST` is `log (n)` in the **average case** and `O(n)` in the **worst case**. We are using set because it is mentioned in the question that all the elements in an array are distinct.<br />
The following is the C++ implementation of the above method.<br />
```cpp
/* the following code demonstrates how to find kth smallest
element using set from C++ STL */

#include <bits/stdc++.h>
using namespace std;

int main()
{

	int arr[] = { 12, 3, 5, 7, 19 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;

	set<int> s(arr, arr + n);
	set<int>::iterator itr 	= s.begin(); // s.begin() returns a pointer to first
					// element in the set
	advance(itr, k - 1); 		// itr points to kth element in set

	cout << *itr << "\n";

	return 0;
}
```
Output<br />
<pre>
12
</pre>
<pre>
Time Complexity:  O(N*log N) in Average Case and O(N) in Worst Case
Auxiliary Space: O(N)
</pre>
<br /><br />**Method 3** `(Using Min Heap – HeapSelect)`<br />
We can find `k’th` smallest element in time complexity better than `O(N Log N)`. A simple optimization is to create a `Min Heap` of the given `n` elements and call `extractMin()` `k` times.<br />
The following is C++ implementation of above method.<br />
```cpp
// A C++ program to find k'th smallest element using min heap
#include <climits>
#include <iostream>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int* x, int* y);

// A class for Min Heap
class MinHeap {
	int* harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:
	MinHeap(int a[], int size); // Constructor
	void MinHeapify(int i); // To minheapify subtree rooted with index i
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }

	int extractMin(); // extracts root (minimum) element
	int getMin() { return harr[0]; } // Returns minimum
};

MinHeap::MinHeap(int a[], int size)
{
	heap_size = size;
	harr = a; // store address of array
	int i = (heap_size - 1) / 2;
	while (i >= 0) {
		MinHeapify(i);
		i--;
	}
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
	if (heap_size == 0)
		return INT_MAX;

	// Store the minimum value.
	int root = harr[0];

	// If there are more than 1 items, move the last item to root
	// and call heapify.
	if (heap_size > 1) {
		harr[0] = harr[heap_size - 1];
		MinHeapify(0);
	}
	heap_size--;

	return root;
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i) {
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

// A utility function to swap two elements
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Function to return k'th smallest element in a given array
int kthSmallest(int arr[], int n, int k)
{
	// Build a heap of n elements: O(n) time
	MinHeap mh(arr, n);

	// Do extract min (k-1) times
	for (int i = 0; i < k - 1; i++)
		mh.extractMin();

	// Return root
	return mh.getMin();
}

// Driver program to test above methods
int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int n = sizeof(arr) / sizeof(arr[0]), k = 2;
	cout << "K'th smallest element is " << kthSmallest(arr, n, k);
	return 0;
}
```
Output<br />
<pre>
K'th smallest element is 5
</pre>
<pre>
Time complexity: O(n + kLogn).
Space complexity: O(n) for call stack
</pre>
<br /><br />**Method 4** `(Using Max-Heap)`<br />
We can also use Max Heap for finding the k’th smallest element. Following is an algorithm.<br /> 

1) Build a Max-Heap `MH` of the first `k` elements (`arr[0] to arr[k-1]`) of the given array. `O(k)`<br />
2) For each element, after the `k’th` element (`arr[k] to arr[n-1]`), compare it with root of `MH`. <br />
……a) If the element is less than the root then make it root and call **heapify** for `MH` <br />
……b) Else ignore it. <br />

// The step 2 is `O((n-k)*logk)`<br />
3) Finally, the root of the `MH` is the **kth smallest** element.<br />
Time complexity of this solution is `O(k + (n-k)*Logk)`<br />

The following is C++ implementation of the above algorithm <br />
```cpp
// A C++ program to find k'th smallest element using max heap
#include <climits>
#include <iostream>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int* x, int* y);

// A class for Max Heap
class MaxHeap {
	int* harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of max heap
	int heap_size; // Current number of elements in max heap
public:
	MaxHeap(int a[], int size); // Constructor
	void maxHeapify(int i); // To maxHeapify subtree rooted with index i
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }

	int extractMax(); // extracts root (maximum) element
	int getMax() { return harr[0]; } // Returns maximum

	// to replace root with new node x and heapify() new root
	void replaceMax(int x)
	{
		harr[0] = x;
		maxHeapify(0);
	}
};

MaxHeap::MaxHeap(int a[], int size)
{
	heap_size = size;
	harr = a; // store address of array
	int i = (heap_size - 1) / 2;
	while (i >= 0) {
		maxHeapify(i);
		i--;
	}
}

// Method to remove maximum element (or root) from max heap
int MaxHeap::extractMax()
{
	if (heap_size == 0)
		return INT_MAX;

	// Store the maximum value.
	int root = harr[0];

	// If there are more than 1 items, move the last item to root
	// and call heapify.
	if (heap_size > 1) {
		harr[0] = harr[heap_size - 1];
		maxHeapify(0);
	}
	heap_size--;

	return root;
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::maxHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l < heap_size && harr[l] > harr[i])
		largest = l;
	if (r < heap_size && harr[r] > harr[largest])
		largest = r;
	if (largest != i) {
		swap(&harr[i], &harr[largest]);
		maxHeapify(largest);
	}
}

// A utility function to swap two elements
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Function to return k'th largest element in a given array
int kthSmallest(int arr[], int n, int k)
{
	// Build a heap of first k elements: O(k) time
	MaxHeap mh(arr, k);

	// Process remaining n-k elements. If current element is
	// smaller than root, replace root with current element
	for (int i = k; i < n; i++)
		if (arr[i] < mh.getMax())
			mh.replaceMax(arr[i]);

	// Return root
	return mh.getMax();
}

// Driver program to test above methods
int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int n = sizeof(arr) / sizeof(arr[0]), k = 4;
	cout << "K'th smallest element is " << kthSmallest(arr, n, k);
	return 0;
}
```
Output<br />
<pre>
K'th smallest element is 12
</pre>
<br /><br />**Method 5** `(QuickSelect)`<br />
This is an optimization over method `1` if `QuickSort` is used as a sorting algorithm in first step. In `QuickSort`, we pick a `pivot element`, then move the pivot element to its correct position and partition the surrounding array. The idea is, not to do complete quicksort, but stop at the point where pivot itself is `k’th smallest element`. Also, not to `recur` for both `left` and `right` sides of pivot, but `recur` for one of them according to the position of pivot. The **worst case** time complexity of this method is `O(n^2)`, but it works in `O(n)` on **average**.<br />
```cpp
#include <climits>
#include <iostream>
using namespace std;

int partition(int arr[], int l, int r);

// This function returns k'th smallest element in arr[l..r] using
// QuickSort based method. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
	// If k is smaller than number of elements in array
	if (k > 0 && k <= r - l + 1) {
		// Partition the array around last element and get
		// position of pivot element in sorted array
		int pos = partition(arr, l, r);

		// If position is same as k
		if (pos - l == k - 1)
			return arr[pos];
		if (pos - l > k - 1) // If position is more, recur for left subarray
			return kthSmallest(arr, l, pos - 1, k);

		// Else recur for right subarray
		return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
	}

	// If k is more than number of elements in array
	return INT_MAX;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Standard partition process of QuickSort(). It considers the last
// element as pivot and moves all smaller element to left of it
// and greater elements to right
int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

// Driver program to test above methods
int main()
{
	int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
	int n = sizeof(arr) / sizeof(arr[0]), k = 3;
	cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k);
	return 0;
}
```
Output<br />
<pre>
K'th smallest element is 5
</pre>
<br /><br />**Method 6** `(Map STL)`<br />
A map-based `STL` approach is although very much similar to the **quickselect** and `counting sort algorithm` but much easier to implement. We can use an **ordered map** and **map** each element with its frequency. And as we know that an ordered map would store the data in a sorted manner, we keep on adding the frequency of each element till it does not become greater than or equal to `k` so that we reach the `k’th` element from the `start` i.e. the `k’th` smallest element.<br />
Eg – Array={7,0,25,6,16,17,0}    k=3<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210602230640/UntitledDiagram29-230x300.jpg"><br />
Now in order to get the `k’th` largest element, we need to add the frequencies till it becomes **greater than or equal** to `3`. It is clear from the above that the `frequency of 0 + frequency of 6` will become equal to `3` so the **third smallest number** in the array will be `6`.<br />
We can achieve the above using an iterator to **traverse** the map.<br />
```cpp
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
int Kth_smallest(map<int, int> m, int k)
{
	int freq = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		freq += (it->second); // adding the frequencies of
							// each element
		if (freq >= k) // if at any point frequency becomes
					// greater than or equal to k then
					// return that element
		{
			return it->first;
		}
	}
	return -1; // returning -1 if k>size of the array which
			// is an impossible scenario
}
int main()
{
	int n = 5;
	int k = 2;
	vector<int> arr = { 12, 3, 5, 7, 19 };
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		m[arr[i]] += 1; // mapping every element with it's
						// frequency
	}
	int ans = Kth_smallest(m, k);
if(k==1){
	cout << "The " << k << "st smallest element is " << ans << endl;
}
else if(k==2){
	cout << "The " << k << "nd smallest element is " << ans << endl;
}
else if(k==3){
	cout << "The " << k << "rd smallest element is " << ans << endl;
}
else{
	cout << "The " << k << "th smallest element is " << ans << endl;
}
	return 0;
}
```
Output<br />
<pre>
The 2nd smallest element is 5
</pre>
<br /><br />There are two more solutions that are better than the above-discussed ones: One solution is to do a `randomized version of quickSelect()` and the other solution is the **worst-case linear time algorithm**.<br />
<br /><br />**Method 7** `(Max heap using STL):`<br />
We can implement **max** and **min** heap using a **priority queue**.<br />
To find the **kth minimum element** in an array we will max **heapify** the array until the size of the heap becomes `k`.<br /> 
After that for each entry we will pop the top element from the **heap/Priority Queue**.<br /> 
Below is the implementation of the above approach:<br />
```cpp
// C++ code to implement the approach
#include<bits/stdc++.h>
using namespace std;

// Function to find the kth smallest array element
int kthSmallest(int arr[], int n, int k) {

	// For finding min element we need (Max heap)priority queue
	priority_queue<int> pq;
	
	for(int i = 0; i < k; i++)
	{		
		// First push first K elememts into heap
		pq.push(arr[i]);
	}
	// Now check from k to last element
	for(int i = k; i < n; i++)
	{
	
		// If current element is < top that means
		// there are other k-1 lesser elements
		// are present at bottom thus, pop that element
		// and add kth largest element into the heap till curr
		// at last all the greater element than kth element will get pop off
		// and at the top of heap there will be kth smallest element
		if(arr[i] < pq.top())
		{
			pq.pop();
			// Push curr element
			pq.push(arr[i]);
		}
	}

	// Return top of element
	return pq.top();
}


// Driver's code:
int main()
{
	int n = 10;
	int arr[n] = {10, 5, 4 , 3 ,48, 6 , 2 , 33, 53, 10};
	int k = 4;
	cout<< "Kth Smallest Element is: "<<kthSmallest(arr, n, k);

}
```
Output<br />
<pre>
Kth Smallest Element is: 5
</pre>
<pre>
Time complexity: O(nlogk)
Auxiliary Space: O(logK)
</pre>
<br /><br />**Method 8** `(Using Binary Search):`<br />
The idea to solve this problem is that the `Kth` smallest element would be the element at the `kth` position if the array was sorted in **increasing order**. Using this logic, we use **binary search** to predict the index of an element as if the array was sorted but without actually sorting the array.<br /> 
Example: {1, 4, 5, 3, 19, 3} & k = 2 <br />
Here we find that element which has exactly `k + 1` elements (including itself) lesser to it. Hence, the `kth` smallest element would be `3` in this case.<br /><br /> 
Follow the steps below to implement the above idea:<br />

  1. Find low and high that is the range where our answer can lie.<br /> 
  2. Apply **Binary Search** on this range. <br />
  3. If the selected element which would be mid has less than `k` elements lesser to it then increase the number that is `low = mid + 1`.<br />
  4. Otherwise, Decrement the number and try to find a better answer (to understand this please try running on an array containing duplicates).<br />
  5. The Binary Search will end when only one element remains in the answer space which would be our answer.<br />
  
Below is the implementation of the above approach:<br />
```cpp
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int count(vector <int>& nums, int& mid)
{//function to calculate number of elements less than equal to mid
		int cnt = 0;
		
		for(int i = 0; i < nums.size(); i++)
		if(nums[i] <= mid)
			cnt++;
		
		return cnt;
}
	

int kthSmallest(vector <int> nums, int& k)
{
		int low = INT_MAX;
		int high = INT_MIN;
		//calculate minimum and maximum the array.
		for(int i = 0; i < nums.size(); i++)
		{
			low = min(low, nums[i]);
			high = max(high, nums[i]);
		}
		//Our answer range lies between minimum and maximum element of the array on which Binary Search is Applied
		while(low < high)
		{
			int mid = low + (high - low) / 2;
		/*if the count of number of elements in the array less than equal to mid is less than k
			then increase the number. Otherwise decrement the number and try to find a better answer.
		*/
			if(count(nums, mid) < k)
			low = mid + 1;
				
			else
				high = mid;
		}
		
		return low;
}

int main()
{

	vector <int> nums{1, 4, 5, 3, 19, 3};
	int k = 3;
	cout << "K'th smallest element is " << kthSmallest(nums, k);
	return 0;
}
```
Output<br />
<pre>
K'th smallest element is 3
</pre>
<pre>
Time complexity: O((mx-mn)(log(mx-mn))), where mn be minimum and mx be maximum.
Auxiliary Space: O(1)
</pre>





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
**[Minimum Cost of ropes / Connect “n” ropes with minimum cost](https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1)**<br />
There are given `N` ropes of different lengths, we need to connect these ropes into `one` rope. The cost to connect two ropes is equal to `sum of their lengths`. The task _is to connect the ropes with `minimum` cost_.<br />

>Example 1:<br />
Input:<br />
n = 4<br />
arr[] = {4, 3, 2, 6}<br />
Output:<br /> 
29<br />
**Explanation:**<br />
<pre>
For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can
connect the ropes in following ways. 
1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all ropes have connected. Total cost for connecting all ropes is 5 + 9 + 15 = 29. 
   This is the optimized cost for connecting ropes. Other ways of connecting ropes would always have same or more cost. 
   For example, if we connect 4 and 6 first (we get three strings of 3, 2 and 10), then connect 10 and 3 (we get two strings of 13 and 2). 
   Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.
</pre>

>Example 2:<br />
Input:<br />
n = 5<br />
arr[] = {4, 2, 7, 6, 9}<br />
Output:<br /> 
62 <br />
**Explanation:**<br />
<pre>
First, connect ropes 4 and 2, which makes the array {6,7,6,9}. Next, add ropes 6 and
6, which results in {12,7,9}. Then, add 7 and 9, which makes the array {12,16}. And
finally add these two which gives {28}.
Hence, the total cost is 6 + 12 + 16 + 28 = 62.
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task isto complete the function `minCost()` which takes `2` arguments and returns _the minimum cost_.<br />

<pre>
Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
</pre>

* Constraints: `1 ≤ N ≤ 100000`<br />
`1 ≤ arr[i] ≤ 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long> > pq(arr, arr + n);
        long long res = 0;
        while (pq.size() > 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            res += first + second;
            pq.push(first + second);
        }
        return res;
    }
};

int main(){
    long long t; cin>>t;
    while(t--){
        long long n; cin>>n;
        long long i, a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.minCost(a, n)<<endl;
    }
    return 0;
}
```

<br /><br /><br />
## Problem 15:
**[Convert BST to Min Heap](https://www.geeksforgeeks.org/convert-bst-min-heap/)**<br />
Given a **binary search tree** which is also a **complete binary tree**. The problem is to convert the given `BST` into a `Min Heap` with the condition that all the values in the `left subtree` of a node should be **less than** all the values in the `right subtree` of the node. This condition is applied on all the nodes in the so converted `Min Heap`.<br />
Examples:<br />
<pre>
Input :          4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output :        1
              /   \
             2     5
           /  \   /  \
          3   4  6    7 

The given BST has been transformed into a
Min Heap.
All the nodes in the Min Heap satisfies the given
condition, that is, values in the left subtree of
a node should be less than the values in the right
subtree of the node.
</pre>

 * Create an array `arr[]` of size `n`, where `n` is the number of nodes in the given `BST`.<br />
 * Perform the `inorder traversal` of the `BST` and copy the node values in the `arr[]` in sorted order.<br />
 * Now perform the `preorder traversal` of the tree.<br />
 * While traversing the root during the `preorder traversal`, one by one copy the values from the array `arr[]` to the nodes.<br />

**Implementation:**<br />
```cpp
// C++ implementation to convert the given
// BST to Min Heap
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node {
	int data;
	Node *left, *right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
struct Node* getNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// function prototype for preorder traversal
// of the given tree
void preorderTraversal(Node*);

// function for the inorder traversal of the tree
// so as to store the node values in 'arr' in
// sorted order
void inorderTraversal(Node* root, vector<int>& arr)
{
	if (root == NULL)
		return;

	// first recur on left subtree
	inorderTraversal(root->left, arr);

	// then copy the data of the node
	arr.push_back(root->data);

	// now recur for right subtree
	inorderTraversal(root->right, arr);
}

// function to convert the given BST to MIN HEAP
// performs preorder traversal of the tree
void BSTToMinHeap(Node* root, vector<int> arr, int* i)
{
	if (root == NULL)
		return;

	// first copy data at index 'i' of 'arr' to
	// the node
	root->data = arr[++*i];

	// then recur on left subtree
	BSTToMinHeap(root->left, arr, i);

	// now recur on right subtree
	BSTToMinHeap(root->right, arr, i);
}

// utility function to convert the given BST to
// MIN HEAP
void convertToMinHeapUtil(Node* root)
{
	// vector to store the data of all the
	// nodes of the BST
	vector<int> arr;
	int i = -1;

	// inorder traversal to populate 'arr'
	inorderTraversal(root, arr);

	// BST to MIN HEAP conversion
	BSTToMinHeap(root, arr, &i);
}

// function for the preorder traversal of the tree
void preorderTraversal(Node* root)
{
	if (!root)
		return;

	// first print the root's data
	cout << root->data << " ";

	// then recur on left subtree
	preorderTraversal(root->left);

	// now recur on right subtree
	preorderTraversal(root->right);
}

// Driver program to test above
int main()
{
	// BST formation
	struct Node* root = getNode(4);
	root->left = getNode(2);
	root->right = getNode(6);
	root->left->left = getNode(1);
	root->left->right = getNode(3);
	root->right->left = getNode(5);
	root->right->right = getNode(7);

	convertToMinHeapUtil(root);
	cout << "Preorder Traversal:" << endl;
	preorderTraversal(root);

	return 0;
}
```
Output<br />
<pre>
Preorder Traversal:
1 2 3 4 5 6 7
</pre>
<pre>
Time Complexity: O(n) 
Auxiliary Space: O(n) 
</pre>






<br /><br /><br />
## Problem 16:
**[Convert min Heap to max Heap](https://www.geeksforgeeks.org/convert-min-heap-to-max-heap/)**<br />
Given `array` representation of `min Heap`, convert it to **max Heap** in `O(n)` time.<br /> 
Example :<br />
<pre>
Input: arr[] = [3 5 9 6 8 20 10 12 18 9]
         3
      /     \
     5       9
   /   \    /  \
  6     8  20   10
 /  \   /
12   18 9 


Output: arr[] = [20 18 10 12 9 9 3 5 6 8] OR 
       [any Max Heap formed from input elements]

         20
       /    \
     18      10
   /    \    /  \
  12     9  9    3
 /  \   /
5    6 8 
</pre>
The problem might look complex at first look. But our final goal is to only build the `max heap`. The idea is very simple – we simply build `Max Heap` without caring about the input. We start from the bottom-most and rightmost internal mode of `min Heap` and `heapify` all internal modes in the `bottom-up` way to build the `Max heap`.<br />
Below is its implementation<br />
```cpp
// A C++ program to convert min Heap to max Heap
#include<bits/stdc++.h>
using namespace std;

// to heapify a subtree with root at given index
void MaxHeapify(int arr[], int i, int n)
{
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest = i;
	if (l < n && arr[l] > arr[i])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		MaxHeapify(arr, largest, n);
	}
}

// This function basically builds max heap
void convertMaxHeap(int arr[], int n)
{
	// Start from bottommost and rightmost
	// internal mode and heapify all internal
	// modes in bottom up way
	for (int i = (n-2)/2; i >= 0; --i)
		MaxHeapify(arr, i, n);
}

// A utility function to print a given array
// of given size
void printArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
	// array representing Min Heap
	int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("Min Heap array : ");
	printArray(arr, n);

	convertMaxHeap(arr, n);

	printf("\nMax Heap array : ");
	printArray(arr, n);

	return 0;
}
```
Output :<br />
<pre>
Min Heap array : 3 5 9 6 8 20 10 12 18 9 
Max Heap array : 20 18 10 12 9 9 3 5 6 8 
</pre>
<pre>
The complexity of above solution might looks like O(nLogn) but it is O(n). 
Space Complexity: O(n) for call stack since using recursion.
</pre>






<br /><br /><br />
## Problem 17:
**[Rearrange characters in a string such that no two adjacent are same](https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1)**<br />
Given a string `S` with repeated characters. The task is to rearrange characters in a string such that **no two adjacent characters are the same**.<br />
**Note:** The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.<br />

>Example 1:<br />
Input : str = "geeksforgeeks"<br />
Output: 1<br />
Explanation: All the repeated characters of the given string can be rearranged so that no <br />
adjacent characters in the string is equal. Any correct rearrangement will show a output of 1.<br />

>Example 2:<br />
Input : str = "bbbbb"<br />
Output: 0<br />
Explanation: Repeated characters in the string cannot be rearranged such that there should not<br />
be any adjacent repeated character.<br />

**Your task :**<br />
You don't have to read input or print anything. Your task is to complete the `functionrearrangeString()` which takes the string as input and returns the modified string. If the string cannot be modified return `"-1"`.<br />
**Note:**The generatedoutput is `1` if the string is successfully rearranged and is `0` if rearranging is not possible.<br />

<pre> 
Expected Time Complexity : O(NlogN), N = length of String
Expected Auxiliary Space : O(number of english alphabets)
</pre>

* Constraints : `1 <= length of string <= 10^4`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

class Solution{
    public:
    struct Key{
        int freq;
        char ch;
        bool operator<(const Key &k) const{
            return freq < k.freq;
        }
    };
    
    string rearrangeString(string str){
        int n = str.length();
        int count[MAX_CHAR] = {0};
        for(int i = 0;i<n;i++)count[str[i]-'a']++;
        priority_queue<Key>pq;
        for(char c = 'a' ; c<='z';c++){
            if(count[c-'a'])pq.push(Key{count[c-'a'], c});
        }
        str = "";
        Key prev {-1, '#'};
        while(!pq.empty()){
            Key k = pq.top();
            pq.pop();
            str = str + k.ch;
            if(prev.freq>0)pq.push(prev);
            (k.freq)--;
            prev = k;
        }
        if(n != str.length())return "-1";
        else return str;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string str; cin>>str;
        Solution ob;
        string str1 = ob.rearrangeString(str);
        int flag = 1;
        int c[26] = {0};
        for(int i = 0;i<str.length();i++)c[str[i]-'a']+=1;
        int f = 0;
        int x = (str.length()+1)/2;
        for(int i = 0;i<26;i++){
            if(c[i]>x)f=1;
        }
        if(f){
            if(str1=="-1")cout<<0<<endl;
            else cout<<1<<endl;
        }
        else{
            int a[26] = {0};
            int b[26] = {0};
            for(int i = 0;i<str.length();i++)a[str[i]-'a']+=1;
            for(int i = 0;i<str1.length();i++)b[str1[i]-'a']+=1;
            for(int i = 0;i<26;i++){
                if(a[i]!=b[i])flag = 0;
            }
            for(int i = 0;i<str1.length();i++){
                if(i>0){
                    if(str1[i-1]==str1[i])flag = 0;
                }
            }
            if(flag == 1)cout<<"1\n";
            else cout<<"0\n";
        }
    }
    return 0;
}
```

<br /><br /><br />
## Problem 18:
**[Minimum sum of two numbers formed from digits of an array](https://practice.geeksforgeeks.org/problems/minimum-sum4058/1)**<br />
Given an array `Arr` of size `N` such that each element is from the range `0` to `9`. Find the **minimum** possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the **two** numbers.<br />

>Example 1:<br />
Input:<br />
N = 6<br />
Arr[] = {6, 8, 4, 5, 2, 3}<br />
Output: 604<br />
Explanation: The minimum sum is formed by numbers 358 and 246.<br />

>Example 2:<br />
Input:<br />
N = 5<br />
Arr[] = {5, 3, 0, 7, 4}<br />
Output: 82<br />
Explanation: The minimum sum is formed by numbers 35 and 047.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `solve()` which takes `arr[]` and `n` as input parameters and returns _the minimum possible sum_. As the number can be large, return string presentation of the number without leading zeroes.<br />
 
<pre>
Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ N ≤ 10^7`<br />
`0 ≤ Arri ≤ 9`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    // Function for finding sum of larger numbers
    string findSum(string str1, string str2) {
        // Before proceeding further, make sure length
        // of str2 is larger.
        if (str1.length() > str2.length()) swap(str1, str2);

        // Take an empty string for storing result
        string str = "";

        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;

        // Initially take carry zero
        int carry = 0;

        // Traverse from end of both strings
        for (int i = n1 - 1; i >= 0; i--) {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((str1[i] - '0') + (str2[i + diff] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // Add remaining digits of str2[]
        for (int i = n2 - n1 - 1; i >= 0; i--) {
            int sum = ((str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // Add remaining carry
        if (carry) str.push_back(carry + '0');

        // reverse resultant string
        reverse(str.begin(), str.end());

        return str;
    }


    string solve(int arr[], int n) {
        // sort the array
        sort(arr, arr + n);

        // let two numbers be a and b
        string a, b;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0 && i!=n-1) continue;
            // fill a and b with every alternate digit
            // of input array
            if (i & 1)
                a += (char)(arr[i] + '0');
            else
                b += (char)(arr[i] + '0');
        }

        // return the sum
        return findSum(a, b);
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout<<ans<<endl;
    }
}
```
