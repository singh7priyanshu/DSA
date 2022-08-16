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
**[450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)**<br />
Given a `root node reference of a BST` and a `key`, `delete` the node with the `given key` in the **BST**. Return _the root node reference (possibly updated) of the BST_.<br />
Basically, the deletion can be divided into two stages:<br />

 1. Search for a node to remove.<br />
 2. If the node is found, delete the node.<br />
 
>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/09/04/del_node_1.jpg"><br />
Input: root = [5,3,6,2,4,null,7], key = 3<br />
Output: [5,4,6,2,null,null,7]<br />
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.<br />
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.<br />
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.<br />
<img src = "https://assets.leetcode.com/uploads/2020/09/04/del_node_supp.jpg"><br />

>Example 2:<br />
Input: root = [5,3,6,2,4,null,7], key = 0<br />
Output: [5,3,6,2,4,null,7]<br />
Explanation: The tree does not contain a node with value = 0.<br />

>Example 3:<br />
Input: root = [], key = 0<br />
Output: []<br />
 
* Constraints: The number of nodes in the tree is in the range `[0, 10^4]`.<br />
`-10^5 <= Node.val <= 10^5`<br />
Each node has a **unique** value.<br />
`root` is a valid binary search tree.<br />
`-10^5 <= key <= 10^5`<br />

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int inorder_predecessor(TreeNode* root) {
        root = root->left;
        while(root->right) root = root->right;
        return root->val;
    }
    int inorder_successor(TreeNode* root) {
        root = root->right;
        while(root->left) root = root->left;
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
      if(!root) return root;
      if(key < root->val) root->left = deleteNode(root->left, key);
      else if(key > root->val) root->right = deleteNode(root->right, key);
      else {
          if(!root->left && !root->right) root = nullptr;
          else if(root->left){
              root->val = inorder_predecessor(root);   //Find inorder predecessor
              root->left = deleteNode(root->left, root->val);
          } else {
              root->val = inorder_successor(root);     //Find inorder successor
              root->right = deleteNode(root->right, root->val);
          }
       }
      return root;      
    }
};
```







<br /><br /><br />
## Problem 3:
**[Minimum element in BST](https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1)**<br />
Given a `Binary Search Tree`. The task is to find _the minimum element in this given BST_.<br />
<pre>
Example 1:
Input: 5 4 6 3 N N 7 1 
           5
         /    \
        4      6
       /        \
      3          7
     /
    1
Output: 1
</pre>
<pre>
Example 2:
Input: 9 N 10 N N N 11
             9
              \
               10
                \
                 11
Output: 9
</pre>
**Your Task:**<br />
The task is to complete the function `minValue()` which takes `root` as the argument and returns _the minimum element of BST_. If the tree is empty, there is no `minimum element`, so return `-1` in that case.

<pre>
Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).
</pre>

* Constraints: `0 <= N <= 10^4`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data; 
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* buildTree(string str){
    if(str.length() == 0 || str[0] == 'N')return NULL;
    vector<string>ip;
    istringstream iss(str);
    for(string str; iss >> str;)ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*>queue;
    queue.push(root);
    int i = 1;
    while(!queue.empty() && i<ip.size()){
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal != "N"){
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())break;
        currVal = ip[i];
        if(currVal != "N"){
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

int minValue(Node* root);

int main(){
    int t; cin>>t;
    while(t--){
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        cout<<minValue(root)<<endl;
    }
    return 1;
}

// Function to find the minimum element in the given BST.
int minValue(Node* root) {
    // base case
    if (root == NULL) return -1;

    struct Node* current = root;

    // leftmost node is minimum so we move in BST till left node is not NULL.
    while (current->left != NULL) {
        current = current->left;
    }
    // returning the data at leftmost node.
    return (current->data);
}
```








<br /><br /><br />
## Problem 4:
**[Find inorder successor and inorder predecessor in a BST](https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1)**<br />
There is `BST` given with `root node` with key part as an integer only. You need to find the `in-order successor` and `predecessor` of a given key. If either **predecessor** or **successor** is not found, then set it to `NULL`.<br />

>Example:<br />
Input:<br />
2<br />
6<br />
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R<br />
65<br />
6<br />
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R<br />
100<br />
Output:<br />
60 70<br />
80 -1<br />

**Input:**<br />
The first line of input contains an integer `T` denoting the number of test cases. Then `T` test cases follow. Each test case contains `n` denoting the number of edges of the BST. The next line contains the `edges of the BST`. The last line contains the `key`.<br />

**Output:**<br />
Find the predecessor and successor of the key in BST and _sets pre and suc as predecessor and successor_, respectively Otherwise, set to `NULL`.<br />

**Your Task:**<br />
You don't need to print anything. You only need to set `p.pre` to the `predecessor` and `s.succ` to the `successor`. `p` and `s` have been passed in the function parameter.<br />

<pre>
Time Complexity: O(N) 
Auxiliary Space: O(1)
</pre>

* Constraints: `1<=T<=100`<br />
`1<=n<=100`<br />
`1<=data of node<=100`<br />
`1<=key<=100`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x){
        key = x;
        left = NULL;
        right = NULL;
    }
};

int key = 0;
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

void insert(struct Node *root, int n1, int n2, char lr){
    if(root == NULL)return;
    if(root->key == n1){
        switch(lr){
            case 'L' : root->left = new Node(n2);
                    break;
            case 'R' : root->right = new Node(n2);
                    break;
        }
    }
    else{
        insert(root->left, n1, n2, lr);
        insert(root->right, n1, n2, lr);
    }
}

int main(){
    int t, k; cin>>t; 
    while(t--){
        int n; cin>>n;
        struct Node *root = NULL;
        Node *pre = NULL;
        Node *suc = NULL;
        while(n--){
            char lr;
            int n1, n2; cin>>n1>>n2;
            cin>>lr;
            if(root == NULL){
                root = new Node(n1);
                switch(lr){
                    case 'L' : root->left = new Node(n2);
                            break;
                    case 'R' : root->right = new Node(n2);
                            break;
                    }
            }
            else{
                insert(root, n1, n2, lr);
            }
        }
        cin>>key;
        findPreSuc(root, pre, suc, key);
        if(pre != NULL)cout<<pre->key<<" ";
        else cout<<"-1";
        if(suc != NULL)cout<<suc->key<<" "<<endl;
        else cout<<" "<<"-1"<<endl;
    }
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if (root == NULL)
        return;
 
    // Search for given key in BST.
    while (root != NULL) {
 
        // If root is given key.
        if (root->key == key) {
 
            // the minimum value in right subtree
            // is successor.
            if (root->right) {
                suc = root->right;
                while (suc->left)
                    suc = suc->left;
            }
 
            // the maximum value in left subtree
            // is predecessor.
            if (root->left) {
                pre = root->left;
                while (pre->right)
                    pre = pre->right;
            }
 
            return;
        }
 
        // If key is greater than root, then
        // key lies in right subtree. Root
        // could be predecessor if left
        // subtree of key is null.
        else if (root->key < key) {
            pre = root;
            root = root->right;
        }
 
        // If key is smaller than root, then
        // key lies in left subtree. Root
        // could be successor if right
        // subtree of key is null.
        else {
            suc = root;
            root = root->left;
        }
    }
}
```










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
