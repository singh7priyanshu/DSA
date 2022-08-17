# Love Babbar Sheet 450 - Binary Trees
## Problem 1:
**[Level order traversal](https://practice.geeksforgeeks.org/problems/level-order-traversal/1)**<br />
Given a `binary tree`, find its **level order traversal**. `Level order traversal of a tree is breadth-first traversal for the tree`.<br />

<pre>
Example 1:
Input:
    1
  /   \ 
 3     2
 
Output:1 3 2
</pre>
<pre>
Example 2:
Input:
        10
     /      \
    20       30
  /   \
 40   60
 
Output:10 20 30 40 60
</pre>
**Your Task:**<br />
You don't have to take any input. Complete the function `levelOrder()` that takes the `root node` as input parameter and returns _a list of integers containing the level order traversal of the given Binary Tree_.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1 ≤ Number of nodes ≤ 10^5`<br />
`1 ≤ Data of a node ≤ 10^5`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
              vector <int> res;
        
        //if node is null, we return the list.
        if (node == NULL) 
        return res;
        
        //creating an empty queue for level order traversal.
        queue<Node *> q;
    
        q.push(node);
    
        while (q.empty() == false)
        {
            //storing front element of queue in list and removing it from queue.
            Node *node = q.front();
            res.push_back (node->data);
            q.pop();
    
            //storing the left child of the parent node in queue.
            if (node->left != NULL)
                q.push(node->left);
    
            //storing the right child of the parent node in queue.
            if (node->right != NULL)
                q.push(node->right);
        }
        //returning the list.
        return res;
    }
};

void inOrder(struct Node* node)
{
  if (node == NULL)
    return;

  inOrder(node->left);
  printf("%d ", node->data);

  inOrder(node->right);
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.levelOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
  }
  return 0;
}
```











<br /><br /><br />
## Problem 2:
**[Reverse Level Order Traversal](https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1)**<br />
Given a `binary tree` of size `N`, find its **reverse level order traversal**. ie- the traversal must begin from the last level.<br />

<pre>
Example 1:
Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
</pre>
<pre>
Example 2:
Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10
</pre>

**Your Task:**<br /> 
You dont need to read input or print anything. Complete the function `reverseLevelOrder()` which takes the `root of the tree` as input parameter and returns _a list containing the **reverse level order traversal** of the given tree_.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1 ≤ N ≤ 10^4`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

vector<int> reverseLevelOrder(Node* root);

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> result = reverseLevelOrder(root);
        for (int i = 0; i < result.size(); ++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 1;
}

vector<int> reverseLevelOrder(Node *root)
{
   vector<int>ans;
   queue<Node*>q;
   q.push(root);
   q.push(NULL);
   while(!q.empty()){
       Node *temp=q.front();
       q.pop();
       if(temp!=NULL){
           ans.push_back(temp->data);
           if(temp->right)
           q.push(temp->right);
            if(temp->left)
           q.push(temp->left);
       }
       else if(!q.empty()){
           q.push(NULL);
       }
   }
   reverse(ans.begin(),ans.end());
   return ans;
}
```












<br /><br /><br />
## Problem 3:
**[Height of Binary Tree](https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1)**<br />
Given a `binary tree`, find _its **height**_.<br />

<pre>
Example 1:
Input:
     1
    /  \
   2    3
Output: 2
</pre>
<pre>
Example 2:
Input:
  2
   \
    1
   /
 3
Output: 3   
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `height()` which takes `root node` of the tree as **input parameter** and returns _an integer denoting the height of the tree_. If the tree is empty, return `0`.<br /> 

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1 <= Number of nodes <= 10^5`<br />
`1 <= Data of a node <= 10^5`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node)
    {
        //if node is null, we return 0.
        if (node==NULL)
            return 0;

        //else we call the recursive function, height for left and right 
        //subtree and choose their maximum. we also add 1 to the result
        //which indicates height of root of the tree.
        else
            return 1 + max(height(node->left), height(node->right));
    }    
};

int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string treeString;
        getline(cin,treeString);
        Node* root = buildTree(treeString);
        Solution ob;
        cout<<ob.height(root)<<endl;
    }
    return 0;
}
```











<br /><br /><br />
## Problem 4:
**[Diameter of a Binary Tree](https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1)**<br />
The `diameter of a tree` (sometimes called the **width**) is the number of **nodes on the longest path between two end nodes**. The diagram below shows two trees each with diameter `nine`, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).<br />
<img src = "https://contribute.geeksforgeeks.org/wp-content/uploads/diameter.jpg"><br />
<pre>
Example 1:
Input:
       1
     /  \
    2    3
Output: 3
</pre>
<pre>
Example 2:
Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
</pre>

**Your Task:**<br />
You need to complete the function `diameter()` that takes `root` as parameter and returns _the diameter_.<br />

<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
</pre>

* Constraints: `1 <= Number of nodes <= 10000`<br />
`1 <= Data of a node <= 1000`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
  public:
    // Function to find the diameter of a Binary Tree.
    int go(Node* n, int* dia) {
        // if node becomes null, we return 0.
        if (!n) return 0;

        // calling the go function recursively for the left and
        // right subtrees to find their heights.
        int l = go(n->left, dia);
        int r = go(n->right, dia);

        // storing the maximum possible value of l+r+1 in diameter.
        if (l + r + 1 > *dia) *dia = l + r + 1;

        // returning height of subtree.
        return 1 + max(l, r);
    }

  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int dia = 0;
        // calling the function to find the result.
        go(root, &dia);
        // returning the result.
        return dia;
    }
};

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}
```














<br /><br /><br />
## Problem 5:
**[Create a mirror tree from the given binary tree](https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/)**<br />
Given a `binary tree`, the task is to create a `new binary tree` which is a mirror image of the given **binary tree**.<br />
Examples:<br /> 
<pre>
Input:
        5
       / \
      3   6
     / \
    2   4
Output:
Inorder of original tree: 2 3 4 5 6 
Inorder of mirror tree: 6 5 4 3 2
Mirror tree will be:
  5
 / \
6   3
   / \
  4   2

Input:
        2
       / \
      1   8
     /     \
    12      9
Output:
Inorder of original tree: 12 1 2 8 9 
Inorder of mirror tree: 9 8 2 1 12
</pre>
**Approach:**<br />
Write a `recursive function` that will take two nodes as the argument, one of the original tree and the other of the newly created tree. Now, for every **passed** node of the original tree, create a corresponding node in the mirror tree and then `recursively` call the same method for the child nodes but passing the `left child` of the original tree node with the `right child` of the mirror tree node and the `right child` of the original tree node with the `left child` of the mirror tree node.<br />
Below is the implementation of the above approach:<br />
```cpp
// C++ implementation of the approach
#include <iostream>
using namespace std;

// A binary tree node has data, pointer to
// left child and a pointer to right child
typedef struct treenode {
	int val;
	struct treenode* left;
	struct treenode* right;
} node;

// Helper function that allocates a new node with the
// given data and NULL left and right pointers
node* createNode(int val)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// Helper function to print Inorder traversal
void inorder(node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout <<" "<< root->val;
	inorder(root->right);
}

// mirrorify function takes two trees,
// original tree and a mirror tree
// It recurses on both the trees,
// but when original tree recurses on left,
// mirror tree recurses on right and
// vice-versa
void mirrorify(node* root, node** mirror)
{
	if (root == NULL) {
		mirror = NULL;
		return;
	}

	// Create new mirror node from original tree node
	*mirror = createNode(root->val);
	mirrorify(root->left, &((*mirror)->right));
	mirrorify(root->right, &((*mirror)->left));
}

// Driver code
int main()
{

	node* tree = createNode(5);
	tree->left = createNode(3);
	tree->right = createNode(6);
	tree->left->left = createNode(2);
	tree->left->right = createNode(4);

	// Print inorder traversal of the input tree
	cout <<"Inorder of original tree: ";
	inorder(tree);
	node* mirror = NULL;
	mirrorify(tree, &mirror);

	// Print inorder traversal of the mirror tree
	cout <<"\nInorder of mirror tree: ";
	inorder(mirror);

	return 0;
}
```
Output<br />
<pre>
Inorder of original tree: 2 3 4 5 6 
Inorder of mirror tree: 6 5 4 3 2 
</pre>
**Approach 2:**<br />
In order to change the original tree in its mirror tree, then we simply swap the **left** and **right** link of each node. If the `node is leaf node` then do nothing.<br />
```cpp
#include <iostream>
using namespace std;

typedef struct treenode {
	int val;
	struct treenode* left;
	struct treenode* right;
} node;

// Helper function that
// allocates a new node with the
// given data and NULL left and right pointers
node* createNode(int val)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// Function to print the inrder traversal
void inorder(node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

// Function to convert to mirror tree
treenode* mirrorTree(node* root)
{
	// Base Case
	if (root == NULL)
		return root;
	node* t = root->left;
	root->left = root->right;
	root->right = t;

	if (root->left)
		mirrorTree(root->left);
	if (root->right)
		mirrorTree(root->right);

return root;
}

// Driver Code
int main()
{

	node* tree = createNode(5);
	tree->left = createNode(3);
	tree->right = createNode(6);
	tree->left->left = createNode(2);
	tree->left->right = createNode(4);
	printf("Inorder of original tree: ");
	inorder(tree);

	// Function call
	mirrorTree(tree);

	printf("\nInorder of Mirror tree: ");
	inorder(tree);
	return 0;
}
```
Output<br />
<pre>
Inorder of original tree: 2 3 4 5 6 
Inorder of Mirror tree: 6 5 4 3 2 
</pre>








<br /><br /><br />
## Problem 6:
**[Inorder Tree Traversal – Iterative and Recursive](https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/)**<br />
Unlike linked lists, one-dimensional arrays, and other linear data structures, which are traversed in linear order, trees can be traversed in multiple ways in `depth–first order` (`preorder`, `inorder`, and `postorder`) or `breadth–first order` (`level order traversal`). Beyond these basic traversals, various more complex or hybrid schemes are possible, such as depth-limited searches like `iterative deepening depth–first search`.`Inorder tree traversal` is discussed in detail.<br />
Traversing a tree involves iterating over all nodes in some manner. As the tree is not a `linear data structure`, there can be more than one possible next node from a given node, so some nodes must be deferred, i.e., stored in some way for later visiting. The traversal can be done `iteratively` where the deferred nodes are stored in the stack, or it can be done by `recursion`, where the deferred nodes are stored implicitly in the `call stack`.<br />
For `traversing` a `(non-empty)` `binary tree` in an `inorder fashion`, we must do these three things for every node `n` starting from the `tree’s root`:<br />

 * (L) `Recursively traverse` its `left` subtree. When this step is finished, we are back at `n` again.<br />
 * (N) Process `n` itself.<br />
 * (R) `Recursively traverse` its `right` subtree. When this step is finished, we are back at `n` again.<br />
 
In `normal inorder traversal`, we visit the `left subtree` before the `right subtree`. If we **visit the right subtree before visiting the left subtree**, it is referred to as `reverse inorder traversal`.<br />
<img src = "https://www.techiedelight.com/wp-content/uploads/Inorder-Traversal.png"><br />
<br />`Recursive Implementation`<br />
As we can see, before processing any node, the `left subtree` is processed first, followed by the node, and the `right subtree` is processed at last. These operations can be defined `recursively` for each node. The **recursive implementation** is referred to as a `Depth–first search (DFS)`, as the search tree is deepened as much as possible on each child before going to the next sibling.<br />
```cpp
#include <iostream>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to perform inorder traversal on the tree
void inorder(Node* root)
{
    // return if the current node is empty
    if (root == nullptr) {
        return;
    }
 
    // Traverse the left subtree
    inorder(root->left);
 
    // Display the data part of the root (or current node)
    cout << root->data << " ";
 
    // Traverse the right subtree
    inorder(root->right);
}
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    inorder(root);
 
    return 0;
}
```
<br />**Iterative Implementation**<br />
To convert the above `recursive procedure` into an iterative one, we need an explicit stack. Following is a `simple stack-based iterative algorithm` to perform `inorder traversal`:<br />
<pre>
iterativeInorder(node)
 
  s —> empty stack
  while (not s.isEmpty() or node != null)
    if (node != null)
      s.push(node)
      node —> node.left
    else
      node —> s.pop()
      visit(node)
      node —> node.right
 </pre>
 ```cpp
 #include <iostream>
#include <stack>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Iterative function to perform inorder traversal on the tree
void inorderIterative(Node* root)
{
    // create an empty stack
    stack<Node*> stack;
 
    // start from the root node (set current node to the root node)
    Node* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
    }
}
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    inorderIterative(root);
 
    return 0;
}
```
<pre>
The time complexity of the above solutions is O(n), where n is the total number of nodes in the binary tree. 
The space complexity of the program is O(n) as the space required is proportional to the height of the tree, 
which can be equal to the total number of nodes in the tree in worst-case for skewed trees.
</pre>





<br /><br /><br />
## Problem 7:
**[Preorder Traversal of a tree both using recursion and Iteration](https://www.techiedelight.com/preorder-tree-traversal-iterative-recursive/)**<br />
Unlike **linked lists**, **one-dimensional arrays**, and other **linear data structures**, which are traversed in `linear order`, trees can be traversed in multiple ways in `depth–first order` (`preorder`, `inorder`, and `postorder`) or `breadth–first order` (`level order traversal`). Beyond these basic traversals, various more complex or hybrid schemes are possible, such as `depth-limited searches` like `iterative deepening depth–first search`. In this post, `preorder tree traversal` is discussed in detail.<br />
Traversing a tree involves iterating over all nodes in some manner. As the tree is not a `linear data structure`, there can be more than one possible next node from a given node, so some nodes must be deferred, i.e., stored in some way for later visiting. The traversal can be done iteratively where the deferred nodes are stored in the stack, or it can be done by `recursion`, where the deferred nodes are stored implicitly in the call stack.<br />
For traversing a `(non-empty) binary tree` in a `preorder` fashion, we must do these three things for every node n starting from the tree’s root:<br />

 * (N) Process `n` itself.<br />
 * (L) `Recursively` traverse its `left subtree`. When this step is finished, we are back at `n` again.<br />
 * (R) `Recursively` traverse its `right subtree`. When this step is finished, we are back at `n` again.<br />
 
In `normal preorder traversal`, visit the `left subtree before the right subtree`. If we visit the `right subtree before visiting the left subtree`, it is referred to as `reverse preorder traversal`.<br />
<img src = "https://www.techiedelight.com/wp-content/uploads/Preorder-Traversal.png"><br />
<br />**Recursive Implementation**<br />
As we can see, only after processing any node, the `left subtree` is processed, followed by the `right subtree`. These operations can be defined recursively for each node. The `recursive implementation` is referred to as a `Depth–first search (DFS)`, as the search tree is deepened as much as possible on each child before going to the next sibling.<br />
```cpp
#include <iostream>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to perform preorder traversal on the tree
void preorder(Node* root)
{
    // if the current node is empty
    if (root == nullptr) {
        return;
    }
 
    // Display the data part of the root (or current node)
    cout << root->data << " ";
 
    // Traverse the left subtree
    preorder(root->left);
 
    // Traverse the right subtree
    preorder(root->right);
}
 
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    preorder(root);
 
    return 0;
}
```
**Iterative Implementation**<br />
To convert the above `recursive procedure` into an `iterative one`, we need an `explicit stack`. Following is a simple stack-based iterative algorithm to perform `preorder traversal`:<br />
<pre>
iterativePreorder(node)
 
if (node = null)
  return
s —> empty stack
s.push(node)
while (not s.isEmpty())
  node —> s.pop()
  visit(node)
  if (node.right != null)
    s.push(node.right)
  if (node.left != null)
    s.push(node.left)
 </pre>
 ```cpp
#include <iostream>
#include <stack>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Iterative function to perform preorder traversal on the tree
void preorderIterative(Node* root)
{
    // return if the tree is empty
    if (root == nullptr)
    return;
 
    // create an empty stack and push the root node
    stack<Node*> stack;
    stack.push(root);
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // pop a node from the stack and print it
        Node* curr = stack.top();
        stack.pop();
 
        cout << curr->data << " ";
 
        // push the right child of the popped node into the stack
        if (curr->right) {
            stack.push(curr->right);
        }
 
        // push the left child of the popped node into the stack
        if (curr->left) {
            stack.push(curr->left);
        }
 
        // the right child must be pushed first so that the left child
        // is processed first (LIFO order)
    }
}
 
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    preorderIterative(root);
 
    return 0;
}
```
The above solution can be further optimized by `pushing only the right children to the stack`.<br />
```cpp
#include <iostream>
#include <stack>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Iterative function to perform preorder traversal on the tree
void preorderIterative(Node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // create an empty stack and push the root node
    stack<Node*> stack;
    stack.push(root);
 
    // start from the root node (set current node to the root node)
    Node* curr = root;
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // if the current node exists, print it and push its right child
        // to the stack before moving to its left child
        if (curr != nullptr)
        {
            cout << curr->data << " ";
 
            if (curr->right) {
                stack.push(curr->right);
            }
 
            curr = curr->left;
        }
        // if the current node is null, pop a node from the stack
        // set the current node to the popped node
        else {
            curr = stack.top();
            stack.pop();
        }
    }
}
 
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    preorderIterative(root);
 
    return 0;
}
```
<pre>
The time complexity of the above solutions is O(n), where n is the total number of nodes in the binary tree. 
The space complexity of the program is O(n) as the space required is proportional to the tree’s height, 
which can be equal to the total number of nodes in the tree in the worst case for skewed trees.
</pre>








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
