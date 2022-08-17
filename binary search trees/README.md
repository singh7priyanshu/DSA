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
**[Check if a tree is a BST or not](https://practice.geeksforgeeks.org/problems/check-for-bst/1)**<br />
Given the `root` of a `binary tree`. Check _whether it is a BST or not_.<br />
**Note:**<br /> 
We are considering that `BST`s can not contain duplicate Nodes.<br />
A `BST` is defined as follows:<br />

 * The `left subtree` of a node contains only nodes with keys **less than** the node's key.<br />
 * The `right subtree` of a node contains only nodes with keys **greater than** the node's key.<br />
 * Both the `left` and `right` subtrees must also be `binary search trees`.<br />
 
<pre>
Example 1:
Input: 2 1 3
   2
 /    \
1      3
Output: 1 
Explanation: 
The left subtree of root node contains node with key lesser than the root nodes key and 
the right subtree of root node contains node with key greater than the root nodes key.
Hence, the tree is a BST.
</pre>
<pre>
Example 2:
Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 
Explanation: 
Since the node with value 7 has right subtree nodes with keys less than 7, this is not a BST.
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `isBST()` which takes the `root` of the tree as a parameter and returns `true` if the given binary tree is BST, else returns `false`.<br /> 

<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).
</pre>

* Constraints: `0 <= Number of edges <= 100000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(struct Node* node)
    {
      return(isBSTUtil(node, INT_MIN, INT_MAX));
    }
    
    public:
    int isBSTUtil(struct Node* node, int min, int max)
    {
        //an empty tree is BST so we return true.
        if (node==NULL)
         return 1;
        
        //returning false if this node violates the min/max constraint.
        if (node->data < min || node->data > max)
         return 0;
        
        //otherwise checking the subtrees recursively.
        //tightening the min or max constraint.
        return
            isBSTUtil(node->left, min, node->data-1) &&  
            isBSTUtil(node->right, node->data+1, max); 
    }
};

Node* buildTree(string str){
    if(str.length() == 0 || str[0] == 'N')return NULL;
    vector<string>ip;

    istringstream iss(str);
    for(string str; iss>>str;)ip.push_back(str);
    Node* root = new Node(stoi(ip[0]));
    queue<Node*>queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i<ip.size()){
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if(currVal != "N"){
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())break;
        currVal = ip[i];

        if(currVal != "N"){
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

void inorder(Node *root, vector<int> &v){
    if(root == NULL)return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main(){
    int t; string tc;
    getline(cin, tc);
    t = stoi(tc);
    while(t--){
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        if(ob.isBST(root))cout<<"1\n";
        else cout<<"0\n";
    }
}
```








<br /><br /><br />
## Problem 6:
**[Populate Inorder Successor for all nodes](https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1)**<br />
Given a `Binary Tree`, write a function to `populate next pointer for all nodes`. The next pointer for every node should be set to point to `inorder successor`.<br />

<pre>
Example 1:
Input: 10 8 12 3
        10
       /  \
      8    12
     /
    3
  

Output: 3->8 8->10 10->12 12->-1
Explanation: The inorder of the above tree is : 3 8 10 12. So the next pointer of node 3 is pointing to 8 , 
 	     next pointer of 8 is pointing to 10 and so on.And next pointer of 12 is pointing to -1 
	     as there is no inorder successor of 12.
</pre>
<pre>
Example 2:
Input:
        1
      /   \
     2     3
Output: 2->1 1->3 3->-1 
</pre>

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `populateNext()` that takes the **root node of the binary tree** as input parameter.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1<=n<=10^5`<br />
`1<=data of the node<=10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x){
        data = x;
        left = right = next = NULL;
    }
};

void printInorder(Node *node){
    if(node == NULL)return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

Node *buildTree(string str){
    if(str.length() == 0 || str[0] == 'N')return NULL;

    vector<string>ip;
    istringstream iss(str);
    for(string str; iss>>str;)ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *>queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size()){
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if(currVal != "N"){
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())break;
        currVal = ip[i];

        if(currVal != "N"){
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

Node *Inorder(Node *root){
    if(root->left == NULL)return root;
    Inorder(root->left);
}

class Solution
{
public:
    void populateNextRecur(Node *p, Node **next_ref)
    {
        if (p)
        {

            populateNextRecur(p->right, next_ref);

            p->next = *next_ref;

            *next_ref = p;

            populateNextRecur(p->left, next_ref);
        }
    }

    void populateNext(Node *root)
    {

        Node *next = NULL;

        populateNextRecur(root, &next);
    }
};

int main(){
    int t; cin>>t;
    cin.ignore();
    while(t--){
        string treeString; 
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        ob.populateNext(root);
        Node *ptr = Inorder(root);
        while(ptr){
            printf("%d->%d ", ptr->data, ptr->next ? ptr->next->data : -1);
            ptr = ptr->next;
        }
        cout<<endl;
    }
}
```








<br /><br /><br />
## Problem 7:
**[Find LCA (Lowest Common Ancestor) of 2 nodes in a BST](https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1)**<br />
Given a `Binary Search Tree` (with all values unique) and **two node values**. Find _the Lowest Common Ancestors of the two nodes in the BST_.<br />

<pre>
Example 1:
Input:
1
5 4 6 3 N N 7 N N N 8
7 8

              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
</pre>
<pre>
Example 2:
Input:
     2
   /   \
  1     3
n1 = 1, n2 = 3
Output: 2
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `LCA()` which takes the **root Node of the BST** and **two integer values** `n1` and `n2` as inputs and returns _the **Lowest Common Ancestor** of the Nodes with values `n1` and `n2` in the given BST_.<br /> 

<pre>
Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).
</pre>

* Constraints: `1 <= N <= 10^4`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str){
    if(str.length() == 0 || str[0] == 'N')return NULL;

    vector<string>ip;
    istringstream iss(str);
    for(string str; iss>>str;)ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *>queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size()){
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if(currVal != "N"){
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())break;
        currVal = ip[i];

        if(currVal != "N"){
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

Node* LCA(Node *root, int l, int h);

int main(){
    int t; cin>>t;
    while(t--){
        string s; int l, h;
        getline(cin, s);
        cin>>l>>h;
        Node *root = buildTree(s);
        cout<<LCA(root, l, h)->data<<endl;
    }
    return 1;
}

//Function to find the lowest common ancestor in a BST.
Node* LCA(Node *root, int n1, int n2)
{
    // base case
    if(root==NULL)
        return NULL;
    
    //If both n1 and n2 are smaller than data at current node, we call 
    //the function recursively for finding LCA in the left subtree. 
    if(n1<root->data and n2<root->data)
    {
        return LCA(root->left,n1,n2);
    }
    //If both n1 and n2 are greater than data at current node, we call 
    //the function recursively for finding LCA in the right subtree. 
    if(n1>root->data and n2 > root->data)
    {
        return LCA(root->right,n1,n2);
    }
    
    //returning the lowest common ancestor.
    return root;
}
```









<br /><br /><br />
## Problem 8:
**[Construct BST from given preorder traversal](https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/)**<br />
Given `preorder traversal` of a `binary search tree`, construct the BST.<br />
For example, if the given traversal is `{10, 5, 1, 7, 40, 50}`, then the output should be the `root` of the following tree.<br />
<pre>
     10
   /   \
  5     40
 /  \      \
1    7      50
</pre>
<br />**Method 1 ( O(n^2) time complexity ) :**<br />
The first element of `preorder traversal` is always root. We first construct the root. Then we find the index of the first element which is **greater than** the root. Let the index be `‘i’`. The values between root and `‘i’` will be part of the **left subtree**, and the values between `‘i'(inclusive)` and `‘n-1’` will be part of the right subtree. Divide given `pre[]` at index `“i”` and **recur** for **left** and **right** sub-trees.<br /> 
For example in `{10, 5, 1, 7, 40, 50}`, `10` is the first element, so we make it `root`. Now we look for the first element greater than `10`, we find `40`. So we know the structure of BST is as following.<br />
<pre>
             10
           /    \
          /      \
  {5, 1, 7}       {40, 50}
</pre>
We **recursively** follow above steps for subarrays `{5, 1, 7}` and `{40, 50}`, and get the complete tree.<br />
```cpp
/* A O(n^2) program for construction of BST from preorder
* traversal */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

// A utility function to create a node
node* newNode(int data)
{
	node* temp = new node();

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

// A recursive function to construct Full from pre[].
// preIndex is used to keep track of index in pre[].
node* constructTreeUtil(int pre[], int* preIndex, int low, int high, int size)
{
	// Base case
	if (*preIndex >= size || low > high)
		return NULL;

	// The first node in preorder traversal is root. So take
	// the node at preIndex from pre[] and make it root, and
	// increment preIndex
	node* root = newNode(pre[*preIndex]);
	*preIndex = *preIndex + 1;

	// If the current subarray has only one element, no need
	// to recur
	if (low == high)
		return root;

	// Search for the first element greater than root
	int i;
	for (i = low; i <= high; ++i)
		if (pre[i] > root->data)
			break;

	// Use the index of element found in preorder to divide
	// preorder array in two parts. Left subtree and right
	// subtree
	root->left = constructTreeUtil(pre, preIndex, *preIndex, i - 1, size);
	root->right
		= constructTreeUtil(pre, preIndex, i, high, size);

	return root;
}

// The main function to construct BST from given preorder
// traversal. This function mainly uses constructTreeUtil()
node* constructTree(int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, &preIndex, 0, size - 1, size);
}

// A utility function to print inorder traversal of a Binary
// Tree
void printInorder(node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

// Driver code
int main()
{
	int pre[] = { 10, 5, 1, 7, 40, 50 };
	int size = sizeof(pre) / sizeof(pre[0]);

	node* root = constructTree(pre, size);

	cout << "Inorder traversal of the constructed tree: \n";
	printInorder(root);

	return 0;
}
```
Output<br />
<pre>
Inorder traversal of the constructed tree: 
1 5 7 10 40 50 
</pre>
<pre>
Time Complexity: O(n^2)
</pre>
<br />**Method 2 ( O(n) time complexity ):**<br />
The trick is to set a range `{min .. max}` for every node. Initialize the range as `{INT_MIN .. INT_MAX}`. The first node will definitely be in range, so create a root node. To construct the **left subtree**, set the range as `{INT_MIN …root->data}`. If a value is in the range `{INT_MIN .. root->data}`, the values are part of the **left subtree**. To construct the **right subtree**, set the range as `{root->data..max .. INT_MAX}`.<br />
Below is the implementation of the above idea:<br />
```cpp
/* A O(n) program for construction
of BST from preorder traversal */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

// A utility function to create a node
node* newNode(int data)
{
	node* temp = new node();

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

// A recursive function to construct
// BST from pre[]. preIndex is used
// to keep track of index in pre[].
node* constructTreeUtil(int pre[], int* preIndex, int key, int min, int max, int size)
{
	// Base case
	if (*preIndex >= size)
		return NULL;

	node* root = NULL;

	// If current element of pre[] is in range, then
	// only it is part of current subtree
	if (key > min && key < max) {
		// Allocate memory for root of this
		// subtree and increment *preIndex
		root = newNode(key);
		*preIndex = *preIndex + 1;

		if (*preIndex < size) {
			// Construct the subtree under root
			// All nodes which are in range
			// {min .. key} will go in left
			// subtree, and first such node
			// will be root of left subtree.
			root->left = constructTreeUtil(pre, preIndex, pre[*preIndex], min, key, size);
		}
		if (*preIndex < size) {
			// All nodes which are in range
			// {key..max} will go in right
			// subtree, and first such node
			// will be root of right subtree.
			root->right = constructTreeUtil(pre, preIndex, pre[*preIndex], key, max, size);
		}
	}

	return root;
}

// The main function to construct BST
// from given preorder traversal.
// This function mainly uses constructTreeUtil()
node* constructTree(int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);
}

// A utility function to print inorder
// traversal of a Binary Tree
void printInorder(node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

// Driver code
int main()
{
	int pre[] = { 10, 5, 1, 7, 40, 50 };
	int size = sizeof(pre) / sizeof(pre[0]);

	// Function call
	node* root = constructTree(pre, size);

	cout << "Inorder traversal of the constructed tree: \n";
	printInorder(root);

	return 0;
}
```
Output<br />
<pre>
Inorder traversal of the constructed tree: 
1 5 7 10 40 50 
</pre>
<pre>
Time Complexity: O(n)
</pre>
<br />**Method 3 ( O(n^2) time complexity ):**<br />
Simply do that just by using the `recursion concept` and iterating through the array of the given elements like below.<br />
```cpp
// C++ Program for the same approach
#include <bits/stdc++.h>
using namespace std;

/*Construct a BST from given pre-order traversal
for example if the given traversal is {10, 5, 1, 7, 40, 50},
then the output should be the root of the following tree.
	10
       / \
      5	 40
    / \	   \
   1   7    50 */

class Node {
public:
int data;
Node* left;
Node* right;
Node(int data)
{
	this->data = data;
	this->left = this->right = NULL;
}
};

static Node* node;

// This will create the BST
Node* createNode(Node* node, int data)
{
if (node == NULL)
	node = new Node(data);

if (node->data > data)
	node->left = createNode(node->left, data);
if (node->data < data)
	node->right = createNode(node->right, data);

return node;
}

// A wrapper function of createNode
void create(int data)
{
node = createNode(node, data);
}
// A function to print BST in inorder
void inorderRec(Node* root)
{
if (root != NULL) {
	inorderRec(root->left);
	cout<<root->data<<endl;
	inorderRec(root->right);
}
}

// Driver code
int main()
{
vector<int> nodeData = { 10, 5, 1, 7, 40, 50 };

for (int i = 0; i < nodeData.size(); i++) {
	create(nodeData[i]);
}
inorderRec(node);
}
```
Output<br />
<pre>
1
5
7
10
40
50
</pre>








<br /><br /><br />
## Problem 9:
**[Convert Binary tree into BST](https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1)**<br />
Given a `Binary Tree`, convert it to `Binary Search Tree` in such a way that keeps the original structure of Binary Tree intact.<br /> 
<pre>
Example 1:
Input:
      1
    /   \
   2     3
Output: 1 2 3
</pre>
<pre>
Example 2:
Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `binaryTreeToBST()` which takes the root of the Binary tree as input and returns `the root of the BST`. The driver code will print inorder traversal of the converted BST.<br />

<pre>
Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).
</pre>

* Constraints: `1 <= Number of nodes <= 1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void printInorder(struct Node* node){
    if(node == NULL)return;

    printInorder(node->left);
    printf("%d", node->data);
    printInorder(node->right);
}

Node *buildTree(string str){
    if(str.length() == 0 || str[0] == 'N')return NULL;

    vector<string>ip;
    istringstream iss(str);
    for(string str; iss>>str;)ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *>queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size()){
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if(currVal != "N"){
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())break;
        currVal = ip[i];

        if(currVal != "N"){
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

class Solution{
  public:
    //Back-end complete function template for C++
    
    void getArr(int arr[],int *index,Node *root)
    {
        if(root==NULL)
            return ;
        getArr(arr,index,root->left);
        arr[*index]=root->data;
        *index+=1;
        getArr(arr,index,root->right);
    }
    
    
    void convert(Node *root,int arr[],int *index)
    {
        if(root==NULL)
            return ;
    
        convert(root->left,arr,index);
        root->data=arr[*index];
        *index+=1;
        convert(root->right,arr,index);
    }
    
    Node * binaryTreeToBST (Node *root)
    {
        if(root==NULL)
            return NULL ;
        int *arr=new int[1000];
        int index=0;
        getArr(arr,&index,root);
        sort(arr,arr+index);
        index=0;
        convert(root,arr,&index);
        return root;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        Node *res = ob.binaryTreeToBST(root);
        printInorder(res);
        cout<<endl;
    }
    return 1;
}
```








<br /><br /><br />
## Problem 10:
**[Convert a normal BST to Balanced BST](https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/)**<br />
Given a `BST (Binary Search Tree)` that may be **unbalanced**, convert _it into a balanced BST that has minimum possible height_.<br />
Examples :<br /> 
<pre>
Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30


Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 

Input:
          4
        /   \
       3     5
      /       \
     2         6 
    /           \
   1             7
Output:
       4
    /    \
   2      6
 /  \    /  \
1    3  5    7 
</pre>
<br />**Simple Solution**<br />
A **Simple Solution** is to traverse nodes in `Inorder` and one by one insert into a `self-balancing BST` like `AVL tree`. Time complexity of this solution is `O(n Log n)` and this solution doesn’t guarantee<br />
An Efficient Solution can **construct balanced BST** in `O(n)` time with **minimum possible height**. Below are steps.<br />

 1. Traverse given **BST in inorder** and store result in an array. This step takes `O(n)` time. Note that this array would be sorted as **inorder traversal of BST always produces sorted sequence**.<br />
 2. Build a `balanced BST` from the above created sorted array using the recursive approach. This step also takes `O(n)` time as we traverse every element exactly once and processing an element takes `O(1)` time.<br />

Below is the implementation of above steps.<br />
```cpp
// C++ program to convert a left unbalanced BST to
// a balanced BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};

/* This function traverse the skewed binary tree and
stores its nodes pointers in vector nodes[] */
void storeBSTNodes(Node* root, vector<Node*> &nodes)
{
	// Base case
	if (root==NULL)
		return;

	// Store nodes in Inorder (which is sorted
	// order for BST)
	storeBSTNodes(root->left, nodes);
	nodes.push_back(root);
	storeBSTNodes(root->right, nodes);
}

/* Recursive function to construct binary tree */
Node* buildTreeUtil(vector<Node*> &nodes, int start, int end)
{
	// base case
	if (start > end)
		return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	Node *root = nodes[mid];

	/* Using index in Inorder traversal, construct
	left and right subtress */
	root->left = buildTreeUtil(nodes, start, mid-1);
	root->right = buildTreeUtil(nodes, mid+1, end);

	return root;
}

// This functions converts an unbalanced BST to
// a balanced BST
Node* buildTree(Node* root)
{
	// Store nodes of given BST in sorted order
	vector<Node *> nodes;
	storeBSTNodes(root, nodes);

	// Constructs BST from nodes[]
	int n = nodes.size();
	return buildTreeUtil(nodes, 0, n-1);
}

// Utility function to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* Function to do preorder traversal of tree */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// Driver program
int main()
{
	/* Constructed skewed binary tree is
				10
			       /
			     8
			   /
			 7
		       /
		     6
		   /
		 5 
		 */

	Node* root = newNode(10);
	root->left = newNode(8);
	root->left->left = newNode(7);
	root->left->left->left = newNode(6);
	root->left->left->left->left = newNode(5);

	root = buildTree(root);

	printf("Preorder traversal of balanced " "BST is : \n");
	preOrder(root);

	return 0;
}
```
Output<br />
<pre>
Preorder traversal of balanced BST is : 
7 5 6 8 10 
</pre>









<br /><br /><br />
## Problem 11:
**[Merge two BST [ V.V.V>IMP ]](https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/)**<br />
You are given two `balanced binary search trees` e.g., `AVL` or `Red-Black Tree`. Write a function that **merges the two given balanced BSTs into a balanced binary search tree**. Let there be `m` elements in the first tree and `n` elements in the other tree. Your merge function should take `O(m+n)` time.<br />
In the following solutions, it is assumed that the sizes of trees are also given as input. If the size is not given, then we can get the **size by traversing the tree**.<br />
<br />**Method 1 (Insert elements of the first tree to second):**<br />
Take all elements of `first BST` one by one, and **insert them into the second BST**. Inserting an element to a **self balancing BST** takes `Logn` time where `n` is **size of the BST**. So time complexity of this method is `Log(n) + Log(n+1) … Log(m+n-1)`. The value of this expression will be between `mLogn` and `mLog(m+n-1)`. As an optimization, we can pick the smaller tree as first tree.<br />
<br />**Method 2 (Merge Inorder Traversals):**<br />

 1. Do **inorder traversal** of `first tree` and store the traversal in `one temp array arr1[]`. This step takes `O(m)` time.<br />  
 2. Do **inorder traversal** of `second tree` and store the traversal in `another temp array arr2[]`. This step takes `O(n)` time.<br /> 
 3. The arrays created in step 1 and 2 are `sorted arrays`. Merge the two sorted arrays into one array of size `m + n`. This step takes `O(m+n)` time.<br /> 
 4. Construct a balanced tree from the merged array using the technique discussed. This step takes `O(m+n)` time.

Time complexity of this method is `O(m+n)` which is better than method `1`. This method takes `O(m+n)` time even if the input **BSTs** are not balanced. 
Following is implementation of this method.<br />
```cpp
// C++ program to Merge Two Balanced Binary Search Trees
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
	public:
	int data;
	node* left;
	node* right;
};

// A utility function to merge two sorted arrays into one
int *merge(int arr1[], int arr2[], int m, int n);

// A helper function that stores inorder
// traversal of a tree in inorder array
void storeInorder(node* node, int inorder[], int *index_ptr);

/* A function that constructs Balanced
Binary Search Tree from a sorted array
See https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/ */
node* sortedArrayToBST(int arr[], int start, int end);

/* This function merges two balanced
BSTs with roots as root1 and root2.
m and n are the sizes of the trees respectively */
node* mergeTrees(node *root1, node *root2, int m, int n)
{
	// Store inorder traversal of
	// first tree in an array arr1[]
	int *arr1 = new int[m];
	int i = 0;
	storeInorder(root1, arr1, &i);

	// Store inorder traversal of second
	// tree in another array arr2[]
	int *arr2 = new int[n];
	int j = 0;
	storeInorder(root2, arr2, &j);

	// Merge the two sorted array into one
	int *mergedArr = merge(arr1, arr2, m, n);

	// Construct a tree from the merged
	// array and return root of the tree
	return sortedArrayToBST (mergedArr, 0, m + n - 1);
}

/* Helper function that allocates
a new node with the given data and
NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}

// A utility function to print inorder
// traversal of a given binary tree
void printInorder(node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

// A utility function to merge
// two sorted arrays into one
int *merge(int arr1[], int arr2[], int m, int n)
{
	// mergedArr[] is going to contain result
	int *mergedArr = new int[m + n];
	int i = 0, j = 0, k = 0;

	// Traverse through both arrays
	while (i < m && j < n)
	{
		// Pick the smaller element and put it in mergedArr
		if (arr1[i] < arr2[j])
		{
			mergedArr[k] = arr1[i];
			i++;
		}
		else
		{
			mergedArr[k] = arr2[j];
			j++;
		}
		k++;
	}

	// If there are more elements in first array
	while (i < m)
	{
		mergedArr[k] = arr1[i];
		i++; k++;
	}

	// If there are more elements in second array
	while (j < n)
	{
		mergedArr[k] = arr2[j];
		j++; k++;
	}

	return mergedArr;
}

// A helper function that stores inorder
// traversal of a tree rooted with node
void storeInorder(node* node, int inorder[], int *index_ptr)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	storeInorder(node->left, inorder, index_ptr);

	inorder[*index_ptr] = node->data;
	(*index_ptr)++; // increase index for next entry

	/* now recur on right child */
	storeInorder(node->right, inorder, index_ptr);
}

/* A function that constructs Balanced
// Binary Search Tree from a sorted array
See https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/ */
node* sortedArrayToBST(int arr[], int start, int end)
{
	/* Base Case */
	if (start > end)
	return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	node *root = newNode(arr[mid]);

	/* Recursively construct the left subtree and make it
	left child of root */
	root->left = sortedArrayToBST(arr, start, mid-1);

	/* Recursively construct the right subtree and make it
	right child of root */
	root->right = sortedArrayToBST(arr, mid+1, end);

	return root;
}

/* Driver code*/
int main()
{
	/* Create following tree as first balanced BST
		100
		/ \
	       50 300
	      / \
	     20 70
	*/
	node *root1 = newNode(100);
	root1->left	 = newNode(50);
	root1->right = newNode(300);
	root1->left->left = newNode(20);
	root1->left->right = newNode(70);

	/* Create following tree as second balanced BST
		 80
		/ \
		40 120
	*/
	node *root2 = newNode(80);
	root2->left = newNode(40);
	root2->right = newNode(120);

	node *mergedTree = mergeTrees(root1, root2, 5, 3);

	cout << "Following is Inorder traversal of the merged tree \n";
	printInorder(mergedTree);

	return 0;
}
```
Output:<br />  
<pre>
Following is Inorder traversal of the merged tree
20 40 50 70 80 100 120 300
</pre>
<br />**Method 3 (In-Place Merge using DLL):**<br />
We can use a `Doubly Linked List` to merge trees in place. Following are the steps.<br />

 1. Convert the given `two Binary Search Trees` into `doubly linked list` in place.<br /> 
 2. **Merge** the two sorted Linked Lists.<br /> 
 3. Build a **Balanced Binary Search Tree from the merged list created in step 2**.<br />

Time complexity of this method is also `O(m+n)` and this method does conversion in place.<br />






<br /><br /><br />
## Problem 12:
**[Kth largest element in BST](https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1)**<br />
Given a `Binary search tree`. Your task is to complete the function which will return **the Kth largest element without doing any modification in Binary Search Tree**.<br />

<pre>
Example 1:
Input:
1
4 2 9
2

      4
    /   \
   2     9
k = 2 
Output: 4
</pre>

<pre>
Example 2:
Input:
       9
        \ 
          10
K = 1
Output: 10
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `kthLargest()` which takes the `root of the BST` and an integer `K` as inputs and returns _the Kth largest element in the given BST_.<br />

<pre>
Expected Time Complexity: O(H + K).
Expected Auxiliary Space: O(H)
</pre>

* Constraints: `1 <= N <= 1000`<br />
`1 <= K <= N`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str){
    if(str.length() == 0 || str[0] == 'N')return NULL;

    vector<string>ip;
    istringstream iss(str);
    for(string str; iss>>str;)ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *>queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size()){
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if(currVal != "N"){
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())break;
        currVal = ip[i];

        if(currVal != "N"){
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

class Solution
{
    public:
    void kthLargestUtil(Node *root, int k, int &c, int &res)
    {
        if (root == NULL || c >= k)
            return;
        
        kthLargestUtil(root->right, k, c, res);
        
        c++;
        if (c == k)
        {
            res = root->data;
            return;
        }
        
        kthLargestUtil(root->left, k, c, res);
    }
    
    public:
    int kthLargest(Node *root, int k)
    {
        int c = 0;
        int res = -1;
        kthLargestUtil(root, k, c, res);
        return res;
    }

};

int main(){
    int t; cin>>t;
    getchar();
    while(t--){
        string s;
        getline(cin, s);
        Node *head = buildTree(s);
        int k; cin>>k;
        getchar();
        Solution ob;
        cout<<ob.kthLargest(head, k)<<endl;
    }
    return 1;
}
```








<br /><br /><br />
## Problem 13:
**[k-th smallest element in BST](https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1)**<br />
Given a `BST` and an integer `K`. Find the **Kth Smallest element in the BST**.<br /> 

<pre>
Example 1:
Input:
1
2 1 3
2
      2
    /   \
   1     3
K = 2
Output: 2
</pre>
<pre>
Example 2:
Input:
        2
      /  \
     1    3
K = 5
Output: -1
</pre> 

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `KthSmallestElement()` which takes the `root of the BST` and integer `K` as inputs and return the _Kth smallest element in the BST_, if no such element exists return `-1`.<br />

<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
</pre>

* Constraints: `1<=Number of nodes<=100000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str){
    if(str.length() == 0 || str[0] == 'N')return NULL;

    vector<string>ip;
    istringstream iss(str);
    for(string str; iss>>str;)ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *>queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size()){
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if(currVal != "N"){
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())break;
        currVal = ip[i];

        if(currVal != "N"){
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

class Solution {
  public:
    int KthSmallestElement(Node *root, int k) {
        Node *cur = root, *pre;

        int ans = -1;

        // Inorder morris traversal
        // https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
        while (cur != NULL) {
            if (cur->left == NULL) {
                if (k == 1) ans = cur->data;
                k--;
                cur = cur->right;
            } else {
                pre = cur->left;

                while (pre->right != NULL and pre->right != cur)
                    pre = pre->right;

                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    if (k == 1) ans = cur->data;
                    k--;
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};

int main(){
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while(t--){
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);

        Solution ob;
        cout<<ob.KthSmallestElement(root, k)<<endl;
    }
    return 0;
}
```










<br /><br /><br />
## Problem 14:
**[Count pairs from 2 BST whose sum is equal to given value "X"](https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1)**<br />
Given `two BSTs` containing `N1` and `N2` distinct nodes respectively and given a value `x`. Your task is to complete the function `countPairs()`, that returns _the count of all pairs from both the **BSTs** whose sum is equal to **x**_.<br />

<pre>
Example 1:
Input:
1
5 3 7 2 4 6 8 
10 6 15 3 8 11 18 
16

BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8

BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18

x = 16
Output:
3
Explanation: The pairs are: (5, 11), (6, 10) and (8, 8)
</pre>
<pre>
Example 2:
Input:
BST1:
  1
   \
    3
   /
  2
BST2:
    3
   / \
  2   4
 /     
1

x = 4
Output:
3
Explanation: The pairs are: (2, 2), (3, 1) and (1, 3)
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `countPairs()`, which takes `2 BST's` as parameter in form of `root1` and `root2` and the integer `x`, that returns _the count of all pairs from both the `BSTs` whose sum is equal to `x`_.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1 ≤ Number of nodes ≤ 10^5`<br />
`1 ≤ Data of a node ≤ 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str){
    if(str.length() == 0 || str[0] == 'N')return NULL;

    vector<string>ip;
    istringstream iss(str);
    for(string str; iss>>str;)ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *>queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size()){
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if(currVal != "N"){
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())break;
        currVal = ip[i];

        if(currVal != "N"){
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        // Code here
        if (root1 == NULL || root2 == NULL)return 0;
        stack<Node*> st1, st2;
        Node* top1, *top2;
        int count = 0;
        while (1) {
            while (root1 != NULL) {
                st1.push(root1);
                root1 = root1->left;
            }
            while (root2 != NULL) {
                st2.push(root2);
                root2 = root2->right;
            }
            if (st1.empty() || st2.empty())break;
            top1 = st1.top();
            top2 = st2.top();
            if ((top1->data + top2->data) == x) {
                count++;
                st1.pop();
                st2.pop();
                root1 = top1->right;
                root2 = top2->left;
            }
            else if ((top1->data + top2->data) < x) {
                st1.pop();
                root1 = top1->right;
            }
            else {
                st2.pop();
                root2 = top2->left;
            }
        }
        return count;
    }
};

int main(){
    int t; cin>>t;
    cin.ignore();
    while(t--){
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x; cin>>x;
        cin.ignore();
        Solution ob;
        cout<<ob.countPairs(root1, root2, x)<<"\n";
    }
    return 0;
}
```










<br /><br /><br />
## Problem 15:
**[Find median of BST in O(n) time and O(1) space](https://www.geeksforgeeks.org/find-median-bst-time-o1-space/)**<br />
Given a `Binary Search Tree`, find the **median** of it.<br /> 

 * If no. of nodes are `even`: then `median = ((n/2th node + ((n)/2th+1) node) /2`.<br /> 
 * If no. of nodes are `odd` : then `median = (n+1)/2th node`.<br />
 
For example, a `median` of below `BST` is 12. <br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/BST.gif"><br />
More Examples:<br />
<pre>
 Given BST(with odd no. of nodes) is : 
                    6
                 /    \
                3       8
              /   \    /  \
             1     4  7    9

Inorder of Given BST will be : 1, 3, 4, 6, 7, 8, 9
So, here median will 6.

Given BST(with even no. of nodes) is :  
                    6
                 /    \
                3       8
              /   \    /  
             1     4  7    

Inorder of Given BST will be : 1, 3, 4, 6, 7, 8
So, here median will  (4+6)/2 = 5.
</pre>
To find the **median**, we need to find the `Inorder` of the `BST` because its **Inorder** will be in sorted order and then find the median i.e.<br /> 
The idea is based on `K’th smallest element in BST using O(1) Extra Space`<br />
The task is very simple if we are allowed to use **extra space** but `Inorder to traversal using recursion` and `stack` both **use Space which is not allowed here**. So, the solution is to `do Morris Inorder traversal` as it doesn’t require any extra space.<br />

<pre>
Implementation:
1- Count the no. of nodes in the given BST
   using Morris Inorder Traversal.
2- Then Perform Morris Inorder traversal one 
   more time by counting nodes and by checking if 
   count is equal to the median point.
   To consider even no. of nodes an extra pointer
   pointing to the previous node is used.
</pre>
Below is the implementation of the above approach:<br />
```cpp
/* C++ program to find the median of BST in O(n)
time and O(1) space*/
#include<bits/stdc++.h>
using namespace std;

/* A binary search tree Node has data, pointer
to left child and a pointer to right child */
struct Node
{
	int data;
	struct Node* left, *right;
};

// A utility function to create a new BST node
struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

/* A utility function to insert a new node with
given key in BST */
struct Node* insert(struct Node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

/* Function to count nodes in a binary search tree
using Morris Inorder traversal*/
int counNodes(struct Node *root)
{
	struct Node *current, *pre;

	// Initialise count of nodes as 0
	int count = 0;

	if (root == NULL)
		return count;

	current = root;
	while (current != NULL)
	{
		if (current->left == NULL)
		{
			// Count node if its left is NULL
			count++;

			// Move to its right
			current = current->right;
		}
		else
		{
			/* Find the inorder predecessor of current */
			pre = current->left;

			while (pre->right != NULL &&
				pre->right != current)
				pre = pre->right;

			/* Make current as right child of its
			inorder predecessor */
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}

			/* Revert the changes made in if part to
			restore the original tree i.e., fix
			the right child of predecessor */
			else
			{
				pre->right = NULL;

				// Increment count if the current
				// node is to be visited
				count++;
				current = current->right;
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */

	return count;
}


/* Function to find median in O(n) time and O(1) space
using Morris Inorder traversal*/
int findMedian(struct Node *root)
{
if (root == NULL)
		return 0;

	int count = counNodes(root);
	int currCount = 0;
	struct Node *current = root, *pre, *prev;

	while (current != NULL)
	{
		if (current->left == NULL)
		{
			// count current node
			currCount++;

			// check if current node is the median
			// Odd case
			if (count % 2 != 0 && currCount == (count+1)/2)
				return current->data;

			// Even case
			else if (count % 2 == 0 && currCount == (count/2)+1)
				return (prev->data + current->data)/2;

			// Update prev for even no. of nodes
			prev = current;

			//Move to the right
			current = current->right;
		}
		else
		{
			/* Find the inorder predecessor of current */
			pre = current->left;
			while (pre->right != NULL && pre->right != current)
				pre = pre->right;

			/* Make current as right child of its inorder predecessor */
			if (pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}

			/* Revert the changes made in if part to restore the original
			tree i.e., fix the right child of predecessor */
			else
			{
				pre->right = NULL;

				prev = pre;

				// Count current node
				currCount++;

				// Check if the current node is the median
				if (count % 2 != 0 && currCount == (count+1)/2 )
					return current->data;

				else if (count%2==0 && currCount == (count/2)+1)
					return (prev->data+current->data)/2;

				// update prev node for the case of even
				// no. of nodes
				prev = current;
				current = current->right;

			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */
}

/* Driver program to test above functions*/
int main()
{

	/* Let us create following BST
				50
			      /   \
			     30	   70
			    / \   / \
		           20 40 60 80 
			   */
	struct Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	cout << "\nMedian of BST is " << findMedian(root);
	return 0;
}
```
Output<br />
<pre>
Median of BST is 50
</pre>




<br /><br /><br />
## Problem 16:
**[Count BST nodes that lie in a given range](https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1)**<br />
Given a `Binary Search Tree (BST)` and a `range l-h(inclusive)`, count _the number of nodes in the BST that lie in the given range_.<br />

 * The values **smaller** than root go to the `left side`<br />
 * The values **greater** and equal to the root go to the `right side`<br />

<pre>
Example 1:
Input:
      10
     /  \
    5    50
   /    /  \
  1    40  100
l = 5, h = 45
Output: 3
Explanation: 5 10 40 are the node in the range.
</pre>
<pre>
Example 2:
Input:
1
5 4 6 3 N N 7 1
2 8
     5
    /  \
   4    6
  /      \
 3        7
l = 2, h = 8
Output: 5
Explanation: All the nodes are in the given range.
</pre>
**Your Task:**<br />
This is a function problem. You don't have to take input. You are required to complete the function `getCountOfNode()` that takes `root`, `l` ,`h` as parameters and returns _the count_.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the BST).
</pre>

* Constraints: `1 <= Number of nodes <= 100`<br />
`1 <= l < h < 10^3`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *buildTree(string str){
    if(str.length() == 0 || str[0] == 'N')return NULL;

    vector<string>ip;
    istringstream iss(str);
    for(string str; iss>>str;)ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));
    queue<Node *>queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size()){
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

//Function to count number of nodes in BST that lie in the given range.
class Solution{
public:
    int getCount(Node* root, int low, int high)
    {
        if (!root) 
            return 0;
    
        //if data at current node is equal to lower and upper range, we return 1.
        if (root->data == high && root->data == low)
            return 1;
    
        //if data at current node is within range then we include it in count 
        //and call function recursively for its left and right children.
        if (root->data <= high && root->data >= low)
            return 1+getCount(root->left,low,high)+getCount(root->right,low,high);
    
        //else if data at current node is smaller than lower range then
        //we call function recursively only for right child.
        else if (root->data < low)
            return getCount(root->right, low, high);
    
        //else we call function recursively only for left child.
        else return getCount(root->left, low, high);
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string s;
        getline(cin>>ws, s);
        int l, r; cin>>l>>r;
        Solution ob;
        Node* root = buildTree(s);
        cout<<ob.getCount(root, l, r)<<endl;
    }
    return 1;
}
```









<br /><br /><br />
## Problem 17:
**[Replace every element with the least greater element on its right](https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/)**<br />
Given an `array of integers`, replace _every element with the `least greater element` on its right side in the array_. If there are no greater elements on the `right side`, replace it with `-1`.<br />
Examples:<br />
<pre>
Input: [8, 58, 71, 18, 31, 32, 63, 92, 
         43, 3, 91, 93, 25, 80, 28]
Output: [18, 63, 80, 25, 32, 43, 80, 93, 
         80, 25, 93, -1, 28, -1, -1]
</pre>
A `naive method` is to run two loops. The `outer loop` will one by **one pick array elements from left to right**. The `inner loop` will `find the smallest element greater than the picked element on its right side`. Finally, the `outer loop` will **replace the picked element with the element found by inner loop**. The time complexity of this method will be `O(n^2)`.<br />
A tricky solution would be to use `Binary Search Trees`. We start scanning the `array from right to left` and **insert each element into the BST**. For each inserted element, we replace it in the array by its `inorder successor` in `BST`. If the element inserted is the `maximum` so far (i.e. its **inorder successor doesn’t exist**), we replace it by `-1`.<br />
Below is the implementation of the above idea –<br />
```cpp
// C++ program to replace every element with the
// least greater element on its right
#include <bits/stdc++.h>
using namespace std;

// A binary Tree node
struct Node {
	int data;
	Node *left, *right;
};

// A utility function to create a new BST node
Node* newNode(int item)
{
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;

	return temp;
}

/* A utility function to insert a new node with
given data in BST and find its successor */
Node* insert(Node* node, int data, Node*& succ)
{
	
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return node = newNode(data);

	// If key is smaller than root's key, go to left
	// subtree and set successor as current node
	if (data < node->data) {
		succ = node;
		node->left = insert(node->left, data, succ);
	}

	// go to right subtree
	else if (data > node->data)
		node->right = insert(node->right, data, succ);
	return node;
}

// Function to replace every element with the
// least greater element on its right
void replace(int arr[], int n)
{
	Node* root = NULL;

	// start from right to left
	for (int i = n - 1; i >= 0; i--) {
		Node* succ = NULL;

		// insert current element into BST and
		// find its inorder successor
		root = insert(root, arr[i], succ);

		// replace element by its inorder
		// successor in BST
		if (succ)
			arr[i] = succ->data;
		else // No inorder successor
			arr[i] = -1;
	}
}

// Driver Program to test above functions
int main()
{
	int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28 };
	int n = sizeof(arr) / sizeof(arr[0]);

	replace(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
```
Output<br />
<pre>
18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1 
</pre>
<pre>
The worst-case time complexity of the above solution is also O(n^2) as it uses BST. 
The worst-case will happen when array is sorted in ascending or descending order. 
The complexity can easily be reduced to O(nlogn) by using balanced trees like red-black trees.
</pre>
<br />**Another Approach:**<br />
We can use the `Next Greater Element` using stack algorithm to solve this problem in `O(Nlog(N))` time and `O(N)` space.<br />
**Algorithm:**<br />
<pre>
1. First, we take an array of pairs namely temp, and store each element and its 
   index in this array,i.e. temp[i] will be storing {arr[i],i}.
2. Sort the array according to the array elements.
3. Now get the next greater index for each and every index of the temp array in 
   an array namely index by using Next Greater Element using stack.
4. Now index[i] stores the index of the next least greater element of the 
   element temp[i].first and if index[i] is -1, then it means that there is no 
   least greater element of the element temp[i].second at its right side.
5. Now take a result array where result[i] will be equal to 
   a[indexes[temp[i].second]] if index[i] is not -1 otherwise result[i] will be 
   equal to -1.
</pre>
Below is the implementation of the above approach<br />
```cpp
#include <bits/stdc++.h>
using namespace std;
// function to get the next least greater index for each and
// every temp.second of the temp array using stack this
// function is similar to the Next Greater element for each
// and every element of an array using stack difference is
// we are finding the next greater index not value and the
// indexes are stored in the temp[i].second for all i
vector<int> nextGreaterIndex(vector<pair<int, int> >& temp)
{
	int n = temp.size();
	// initially result[i] for all i is -1
	vector<int> res(n, -1);
	stack<int> stack;
	for (int i = 0; i < n; i++) {
		// if the stack is empty or this index is smaller
		// than the index stored at top of the stack then we
		// push this index to the stack
		if (stack.empty() || temp[i].second < stack.top())
			stack.push(
				temp[i].second); // notice temp[i].second is
								// the index
		// else this index (i.e. temp[i].second) is greater
		// than the index stored at top of the stack we pop
		// all the indexes stored at stack's top and for all
		// these indexes we make this index i.e.
		// temp[i].second as their next greater index
		else {
			while (!stack.empty()
				&& temp[i].second > stack.top()) {
				res[stack.top()] = temp[i].second;
				stack.pop();
			}
			// after that push the current index to the stack
			stack.push(temp[i].second);
		}
	}
	// now res will store the next least greater indexes for
	// each and every indexes stored at temp[i].second for
	// all i
	return res;
}
// now we will be using above function for finding the next
// greater index for each and every indexes stored at
// temp[i].second
vector<int> replaceByLeastGreaterUsingStack(int arr[], int n)
{
	// first of all in temp we store the pairs of {arr[i].i}
	vector<pair<int, int> > temp;
	for (int i = 0; i < n; i++) {
		temp.push_back({ arr[i], i });
	}
	// we sort the temp according to the first of the pair
	// i.e value
	sort(temp.begin(),temp.end(),[](const pair<int,int> &a,const pair<int,int> &b){
			if(a.first==b.first)
			return a.second>b.second;
			return a.first<b.first;});
	// now indexes vector will store the next greater index
	// for each temp[i].second index
	vector<int> indexes = nextGreaterIndex(temp);
	// we initialize a result vector with all -1
	vector<int> res(n, -1);
	for (int i = 0; i < n; i++) {
		// now if there is no next greater index after the
		// index temp[i].second the result will be -1
		// otherwise the result will be the element of the
		// array arr at index indexes[temp[i].second]
		if (indexes[temp[i].second] != -1)
			res[temp[i].second] = arr[indexes[temp[i].second]];
	}
	// return the res which will store the least greater
	// element of each and every element in the array at its
	// right side
	return res;
}
// driver code
int main()
{
	int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28 };
	int n = sizeof(arr) / sizeof(int);
	auto res = replaceByLeastGreaterUsingStack(arr, n);
	cout << "Least Greater elements on the right side are " << endl;
	for (int i : res)
		cout << i << ' ';
	cout << endl;
	return 0;
```
Output<br />
<pre>
Least Greater elements on the right side are 
18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1
</pre>
<br />**Another approach with set**<br />
A different way to think about the problem is listing our requirements and then thinking over it to find a solution. If we `traverse the array from backwards`, we need  a **data structure(ds)** to support:<br />

 1. Insert an element into our ds in `sorted order` (so at any point of time the elements in our ds are sorted)<br />
 2. Finding the `upper bound` of the current element (upper bound will give just greater element from our ds if present)<br />

Carefully observing at our requirements, a set is what comes in mind.<br />
Why not multiset? Well we can use a **multiset but there is no need to store an element more than once**.<br />
Let’s code our approach<br />
<pre>
Time and space complexity: 
We insert each element in our set and find upper bound for each element using a loop so 
its time complexity is O(n*log(n)). 
We are storing each element in our set so space complexity is O(n)
</pre>
```cpp
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve(vector<int>& arr) {
	set<int> s;
	vector<int> ans(arr.size());
	for(int i=arr.size()-1;i>=0;i--) { //traversing the array backwards
		s.insert(arr[i]); // inserting the element into set
		auto it = s.upper_bound(arr[i]); // finding upper bound
		if(it == s.end()) arr[i] = -1; // if upper_bound does not exist then -1
		else arr[i] = *it; // if upper_bound exists, lets take it
	}
}

void printArray(vector<int>& arr) {
	for(int i : arr) cout << i << " ";
	cout << "\n";
}

int main() {
	vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
	printArray(arr);
	solve(arr);
	printArray(arr);
	return 0;
}
```
Output<br />
<pre>
8 58 71 18 31 32 63 92 43 3 91 93 25 80 28 
18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1 
</pre>






<br /><br /><br />
## Problem 18:
**[Given n appointments, find all conflicting appointments](https://www.geeksforgeeks.org/given-n-appointments-find-conflicting-appointments/)**<br />
Given `n` appointments, find all conflicting appointments.<br />
Examples:<br />
<pre>
Input: appointments[] = { {1, 5} {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}}
Output: Following are conflicting intervals
[3,7] Conflicts with [1,5]
[2,6] Conflicts with [1,5]
[5,6] Conflicts with [3,7]
[4,100] Conflicts with [1,5]
</pre>
An appointment is conflicting if it conflicts with any of the previous appointments in the array.<br />
A `Simple Solution` is to one by one process all appointments from the second appointment to last. For every appointment `i`, check if it conflicts with `i-1`, `i-2`, … `0`. The time complexity of this method is `O(n^2)`.<br />
We can use `Interval Tree` to solve this problem in `O(nLogn)` time. Following is a detailed algorithm.<br />
<pre>
 1. Create an Interval Tree, initially with the first appointment.
 2. Do following for all other appointments starting from the second one.
     1. Check if the current appointment conflicts with any of the existing  appointments in Interval Tree.  
        If conflicts, then print the current appointment. This step can be done O(Logn) time.
     2. Insert the current appointment in Interval Tree. This step also can be done O(Logn) time.
</pre>
Following is the implementation of the above idea.<br />
```cpp
// C++ program to print all conflicting appointments in a
// given set of appointments
#include <bits/stdc++.h>
using namespace std;

// Structure to represent an interval
struct Interval
{
	int low, high;
};

// Structure to represent a node in Interval Search Tree
struct ITNode
{
	Interval *i; // 'i' could also be a normal variable
	int max;
	ITNode *left, *right;
};

// A utility function to create a new Interval Search Tree Node
ITNode * newNode(Interval i)
{
	ITNode *temp = new ITNode;
	temp->i = new Interval(i);
	temp->max = i.high;
	temp->left = temp->right = NULL;
	return temp;
};

// A utility function to insert a new Interval Search Tree
// Node. This is similar to BST Insert. Here the low value
// of interval is used tomaintain BST property
ITNode *insert(ITNode *root, Interval i)
{
	// Base case: Tree is empty, new node becomes root
	if (root == NULL)
		return newNode(i);

	// Get low value of interval at root
	int l = root->i->low;

	// If root's low value is smaller, then new interval
	// goes to left subtree
	if (i.low < l)
		root->left = insert(root->left, i);

	// Else, new node goes to right subtree.
	else
		root->right = insert(root->right, i);

	// Update the max value of this ancestor if needed
	if (root->max < i.high)
		root->max = i.high;

	return root;
}

// A utility function to check if given two intervals overlap
bool doOVerlap(Interval i1, Interval i2)
{
	if (i1.low < i2.high && i2.low < i1.high)
		return true;
	return false;
}

// The main function that searches a given interval i
// in a given Interval Tree.
Interval *overlapSearch(ITNode *root, Interval i)
{
	// Base Case, tree is empty
	if (root == NULL) return NULL;

	// If given interval overlaps with root
	if (doOVerlap(*(root->i), i))
		return root->i;

	// If left child of root is present and max of left child
	// is greater than or equal to given interval, then i may
	// overlap with an interval is left subtree
	if (root->left != NULL && root->left->max >= i.low)
		return overlapSearch(root->left, i);

	// Else interval can only overlap with right subtree
	return overlapSearch(root->right, i);
}

// This function prints all conflicting appointments in a given
// array of appointments.
void printConflicting(Interval appt[], int n)
{
	// Create an empty Interval Search Tree, add first
	// appointment
	ITNode *root = NULL;
	root = insert(root, appt[0]);

	// Process rest of the intervals
	for (int i=1; i<n; i++)
	{
		// If current appointment conflicts with any of the
		// existing intervals, print it
		Interval *res = overlapSearch(root, appt[i]);
		if (res != NULL)
			cout << "[" << appt[i].low << "," << appt[i].high << "] Conflicts with [" << res->low << "," << res->high << "]\n";

		// Insert this appointment
		root = insert(root, appt[i]);
	}
}


// Driver program to test above functions
int main()
{
	// Let us create interval tree shown in above figure
	Interval appt[] = { {1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
	int n = sizeof(appt)/sizeof(appt[0]);
	cout << "Following are conflicting intervals\n";
	printConflicting(appt, n);
	return 0;
}
```
Output<br />
<pre>
Following are conflicting intervals
[3,7] Conflicts with [1,5]
[2,6] Conflicts with [1,5]
[5,6] Conflicts with [3,7]
[4,100] Conflicts with [1,5]
</pre>
<pre>
Note that the above implementation uses a simple Binary Search Tree insert operations. 
Therefore, the time complexity of the above implementation is more than O(nLogn). 
We can use Red-Black Tree or AVL Tree balancing techniques to make the above implementation O(nLogn).
</pre>






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
