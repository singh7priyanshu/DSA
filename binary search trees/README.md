# Love Babbar Sheet 450 - Binary Search Trees
## Problem 1:
**[Binary Search Tree | (Search and Insertion)](https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/)**<br />
**What is Binary Tree?**<br />
<pre>
A binary Search Tree is a node-based binary tree data structure which has the 
following properties:  

 * The left subtree of a node contains only nodes with keys lesser than the 
   node’s key.
 * The right subtree of a node contains only nodes with keys greater than the 
   node’s key.
 * The left and right subtree each must also be a binary search tree. 
   There must be no duplicate nodes.
   <img src = "https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png"><br />
</pre>
The above properties of `Binary Search Tree` provides an ordering among keys so that the operations like `search`, `minimum` and `maximum` can be done fast. If there is no ordering, then we may have to compare every key to search for a given key.<br />
**How to search a key in given Binary Tree?**<br />
For searching a value, if we had a `sorted array` we could have performed a `binary search`. Let’s say we want to `search a number in the array`, in **binary search**, we first define the complete list as our search space, the number can exist only within the search space. Now we compare the number to be searched or the element to be searched with the `middle element` (`median`) of the search space and if the record being searched is `less than the middle element`, we go searching in the `left half`, else we go searching in the `right half`, in case of equality we have found the element. In binary search, we start with `‘n’` elements in search space and if the `mid element` is not the element that we are looking for, we reduce the search space to `‘n/2’` we keep reducing the search space until we either find the record that we are looking for or we get to only one element in search space and be done with this whole reduction.<br />
`Search operations` in binary search trees will be very similar. Let’s say we want to search for the number, we **start** at the `root`, and then we compare the value to be searched with the value of the root, `if it’s equal we are done with the search` `if it’s smaller we know that we need to go to the left subtree` because in a binary search tree all the elements in the left subtree are smaller and `all the elements in the right subtree are larger`. Searching an element in the binary search tree is basically this traversal, at each step we go either **left** or **right** and at each step we discard one of the sub-trees. If the tree is balanced (we call a tree balanced if for all nodes the difference between the heights of left and right subtrees is not greater than one) we start with a search space of `‘n’` nodes and as we discard one of the sub-trees, we discard `‘n/2’` nodes so our search space gets reduced to `‘n/2’`. In the next step, we reduce the search space to `‘n/4’` and we repeat until we find the element or our search space is reduced to only one node. The search here is also a `binary search` hence the name; `Binary Search Tree`.<br />
Implementation:<br />
```cpp
// C function to search a given key in a given BST
struct node* search(struct node* root, int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->key == key)
	return root;
	
	// Key is greater than root's key
	if (root->key < key)
	return search(root->right, key);

	// Key is smaller than root's key
	return search(root->left, key);
}
```
Illustration to search 6 in below tree:<br />

 1. Start from the `root`.<br /> 
 2. Compare the searching element with root, if `less than root`, then recursively call **left subtree**, else **recursively call right subtree**.<br /> 
 3. If the element to search is found anywhere, return `true`, else return `false`.<br /> 

<img src = "https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png"><br />
**Insertion of a key :**<br />
A new key is always inserted at the `leaf`. We start searching for a key from the root until we hit a `leaf node`. Once a leaf node is found, the new node is added as a `child` of the leaf node. 
<pre>

         100                               100

        /   \        Insert 40            /    \

      20     500    ———>                20     500 

     /  \                              /  \  

    10   30                           10   30

                                              \   

                                              40
</pre>
**Implementation:**<br />
```cpp
// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;

class BST {
	int data;
	BST *left, *right;

public:
	// Default constructor.
	BST();

	// Parameterized constructor.
	BST(int);

	// Insert function.
	BST* Insert(BST*, int);

	// Inorder traversal.
	void Inorder(BST*);
};

// Default Constructor definition.
BST ::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}

// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
	if (!root) {
		// Insert the first node, if root is NULL.
		return new BST(value);
	}

	// Insert data.
	if (value > root->data) {
		// Insert right node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process right nodes.
		root->right = Insert(root->right, value);
	}
	else if (value < root->data){
		// Insert left node data, if the 'value'
		// to be inserted is smaller than 'root' node data.

		// Process left nodes.
		root->left = Insert(root->left, value);
	}

	// Return 'root' node, after insertion.
	return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}

// Driver code
int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);

	b.Inorder(root);
	return 0;
}
```
Output<br />
<pre>
20
30
40
50
60
70
80
</pre>
**Illustration to insert 2 in below tree:**<br /> 

 1. Start from the `root`.<br /> 
 2. Compare the `inserting element with root`, if `less than root`, then recursively **call left subtree**, else recursively **call right subtree**.<br /> 
 3. After reaching the `end`, just insert that node at `left(if less than current) or else right`.<br /> 

<img src = "https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png"><br />
<pre>
Time Complexity: The worst-case time complexity of search and insert operations is O(h) where h is the height of the Binary Search Tree. 
In the worst case, we may have to travel from root to the deepest leaf node. 
The height of a skewed tree may become n and the time complexity of search and insert operation may become O(n). 
</pre>
**Implementation: Insertion using loop.**<br />
```cpp
// C++ Code to insert node and to print inorder traversal
// using iteration
#include <bits/stdc++.h>
using namespace std;

// BST Node
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int val)
		: val(val)
		, left(NULL)
		, right(NULL)
	{
	}
};

// Utility function to insert node in BST
void insert(Node*& root, int key)
{
	Node* node = new Node(key);
	if (!root) {
		root = node;
		return;
	}
	Node* prev = NULL;
	Node* temp = root;
	while (temp) {
		if (temp->val > key) {
			prev = temp;
			temp = temp->left;
		}
		else if (temp->val < key) {
			prev = temp;
			temp = temp->right;
		}
	}
	if (prev->val > key)
		prev->left = node;
	else
		prev->right = node;
}

// Utiltiy function to print inorder traversal
void inorder(Node* root)
{
	Node* temp = root;
	stack<Node*> st;
	while (temp != NULL || !st.empty()) {
		if (temp != NULL) {
			st.push(temp);
			temp = temp->left;
		}
		else {
			temp = st.top();
			st.pop();
			cout << temp->val << " ";
			temp = temp->right;
		}
	}
}

// Driver code
int main()
{
	Node* root = NULL;
	insert(root, 30);
	insert(root, 50);
	insert(root, 15);
	insert(root, 20);
	insert(root, 10);
	insert(root, 40);
	insert(root, 60);

	inorder(root);

	return 0;
}
```
Output<br />
<pre>
10 15 20 30 40 50 60 
</pre>
**Some Interesting Facts:**<br />  

 1. `Inorder traversal` of BST always produces `sorted output`.<br />
 2. We can construct a `BST` with only `Preorder` or `Postorder` or `Level Order traversal`. Note that we can always get `inorder traversal` by sorting the only given traversal.<br />
 3. Number of `unique BSTs` with `n` distinct keys is `Catalan Number`<br />






<br /><br /><br />
## Problem 2:
**[]()**<br />

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
