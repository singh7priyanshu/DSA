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
**[Postorder Tree Traversal – Iterative and Recursive](https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/)**<br />
Unlike `linked lists`, `one-dimensional arrays`, and other linear data structures, which are traversed in `linear order`, trees can be traversed in multiple ways in `depth–first order` (`preorder`, `inorder`, and `postorder`) or `breadth–first order` (`level order traversal`). Beyond these basic traversals, various more complex or hybrid schemes are possible, such as `depth-limited searches` like `iterative deepening depth–first search`. In this post, `postorder tree traversal` is discussed in detail.<br />
Traversing a tree involves iterating over all nodes in some manner. As the tree is not a linear data structure, there can be more than one possible next node from a given node, so some nodes must be deferred, i.e., stored in some way for later visiting. The traversal can be done iteratively where the deferred nodes are stored in the **stack**, or it can be done by `recursion`, where the deferred nodes are stored implicitly in the `call stack`.<br />
For traversing a (non-empty) `binary tree` in a `postorder` fashion, we must do these three things for every node `n` starting from the tree’s root:<br />

 * (L) `Recursively` traverse its **left subtree**. When this step is finished, we are back at `n` again.<br />
 * (R) `Recursively` traverse its **right subtree**. When this step is finished, we are back at `n` again.<br />
 * (N) Process `n` itself.<br />
 
In normal `postorder traversal`, visit the left subtree before the right subtree. If we visit the `right subtree before visiting the left subtree`, it is referred to as **reverse postorder traversal**.<br />
<img src = "https://www.techiedelight.com/wp-content/uploads/Postorder-Traversal.png"><br />
<br />**Recursive Implementation**<br />
As we can see, before processing any node, the **left subtree** is processed first, followed by the **right subtree**, and the node is processed at last. These operations can be defined `recursively` for each node. The `recursive implementation` is referred to as a `Depth–first search (DFS)`, as the search tree is deepened as much as possible on each child before going to the next sibling.<br />
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
 
// Recursive function to perform postorder traversal on the tree
void postorder(Node* root)
{
    // if the current node is empty
    if (root == nullptr) {
        return;
    }
 
    // Traverse the left subtree
    postorder(root->left);
 
    // Traverse the right subtree
    postorder(root->right);
 
    // Display the data part of the root (or current node)
    cout << root->data << " ";
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
 
    postorder(root);
 
    return 0;
}
```
<br />**Iterative Implementation**<br />
To convert the above `recursive procedure` into an `iterative one`, we need an `explicit stack`. Following is a simple stack-based iterative algorithm to perform `postorder traversal`:<br />
<pre>
iterativePostorder(node)
 
s —> empty stack
t —> output stack
while (not s.isEmpty())
  node —> s.pop()
  t.push(node)
 
  if (node.left <> null)
    s.push(node.left)
 
  if (node.right <> null)
    s.push(node.right)
  
while (not t.isEmpty())
  node —> t.pop()
  visit(node)
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
 
// Iterative function to perform postorder traversal on the tree
void postorderIterative(Node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);
 
    // create another stack to store postorder traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        Node* curr = s.top();
        s.pop();
 
        out.push(curr->data);
 
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
 
    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
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
 
    postorderIterative(root);
 
    return 0;
}
```
<pre>
The time complexity of the above solutions is O(n), where n is the total number of nodes in the binary tree. 
The space complexity of the program is O(n) as the space required is proportional to the height of the tree, 
which can be equal to the total number of nodes in the tree in worst-case for skewed trees.
</pre>










<br /><br /><br />
## Problem 9:
**[Left View of Binary Tree](https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1)**<br />
Given a `Binary Tree`, print _Left view of it_. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function `leftView()`, which accepts **root of the tree as argument**.<br />
<pre>
Left view of following tree is 1 2 4 8.

          1
       /      \
     2          3
   /     \    /    \
  4       5  6      7
   \
     8   
</pre>
<pre>
Example 1:
Input:
   1
 /  \
3    2
Output: 1 3
</pre>
<pre>
Example 2:
Input:
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190221103723/leftview.jpg"><br />
Output: 10 20 40
</pre>

**Your Task:**<br />
You just have to complete the function `leftView()` that returns **an array containing the nodes that are in the left view**. The newline is automatically appended by the driver code.<br />

<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
</pre>

* Constraints: `0 <= Number of nodes <= 100`<br />
`1 <= Data of a node <= 1000`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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

        // Get the current nodes value from the string
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

int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}

//Function to get the left view of the binary tree.
void leftViewUtil(vector<int>&vec,struct Node *root, int level,int *max_level)
{
    //if root is null, we simply return.
    if (root==NULL)  return;
    
    //if this is the first node of its level then it is in the left view.
    if (*max_level < level)
    {
        //storing data of current node in list.
        vec.push_back(root->data);
        *max_level = level;
    }
    
    //calling function recursively for left and right subtrees of current node. 
    leftViewUtil(vec,root->left, level+1, max_level);
    leftViewUtil(vec,root->right, level+1, max_level);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(struct Node *root)
{
    int max_level = 0;
    vector<int> vec;
    leftViewUtil(vec,root, 1, &max_level);
    //returning the list.
    return vec;
}
```
















<br /><br /><br />
## Problem 10:
**[Right View of Binary Tree](https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1)**<br />
Given a `Binary Tree`, find _Right view of it_. `Right view` of a **Binary Tree** is set of nodes visible when tree is viewed from right side.<br />
<pre>
Right view of following tree is 1 3 7 8.

          1
       /     \
     2          3
   /   \      /    \
  4     5   6        7
    \
     8
</pre>
<pre>
Example 1:
Input:
       1
    /    \
   3      2
Output: 1 2
</pre>
<pre>
Example 2:
Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60
</pre>

**Your Task:**<br />
Just complete the function `rightView()` that takes `node as parameter` and returns _the right view as a list_.<br /> 

<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
</pre>

* Constraints: `1 ≤ Number of nodes ≤ 10^5`<br />
`1 ≤ Data of a node ≤ 10^5`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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

// Recursive function to print right view of a binary tree.
class Solution
{
    public:
    //Function to get the right view of the binary tree.
    void rightViewUtil(vector<int> &vec,struct Node *root,int level,int *max_level)
    {
        //if root is null, we simply return.
        if (root==NULL)  return;
    
         //if this is the last node of its level then it is in the right view.
        if (*max_level < level)
        {
            vec.push_back(root->data);
            *max_level = level;
        }
    
        //calling function recursively for right and left 
        //subtrees of current node.
        rightViewUtil(vec, root->right, level+1, max_level);
        rightViewUtil(vec, root->left, level+1, max_level);
    }
    
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(struct Node *root)
    {
        int max_level = 0;
        vector<int> vec;
        rightViewUtil(vec,root, 1, &max_level);
        //returning the list.
        return vec;
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

        // Get the current nodes value from the string
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

int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> vec = ob.rightView(root);
        for(int x : vec){
            cout<<x<<" ";
        }
        cout << endl;
    }
    return 0;
}
```








<br /><br /><br />
## Problem 11:
**[Top View of Binary Tree](https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1)**<br />
Given below is a `binary tree`. The task is to print the `top view` of **binary tree**. `Top view` of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree<br />

<pre>
       1
    /     \
   2        3
  /  \    /   \
4     5  6     7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.
</pre>
<pre>
Example 1:
Input:
      1
   /    \
  2      3
Output: 2 1 3
</pre>
<pre>
Example 2:
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
</pre>

**Your Task:**<br />
Since this is a function problem. You don't have to take input. Just complete the function `topView()` that takes `root node` as parameter and returns _a list of nodes visible from the top view from left to right_.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).
</pre>

* Constraints: `1 ≤ N ≤ 10^5`<br />
`1 ≤ Node Data ≤ 10^5`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

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

        // Get the current nodes value from the string
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
        if (i >= ip.size())
            break;
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

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        
        // base case
        if(root == NULL){
            return ans;
        }
    
        Node *temp = NULL;
        //creating empty queue for level order traversal.
        queue<pair<Node *, int>> q;
        //creating a map to store nodes at a particular horizontal distance.
        map<int, int> mp;
    
        q.push({root, 0});
        while(!q.empty())
        {
    
            temp = q.front().first;
            int d = q.front().second;
            q.pop();
            
            //storing temp->data in map.
            if(mp.find(d) == mp.end()){
                mp[d] = temp->data;
            }
            
            //if left child of temp exists, pushing it in
            //the queue with the horizontal distance.
            if(temp->left){
                q.push({temp->left, d-1});
            }
            //if right child of temp exists, pushing it in
            //the queue with the horizontal distance.
            if(temp->right){
                q.push({temp->right, d+1});
            }
        }
        //traversing the map and storing the nodes in list 
        //at every horizontal distance.
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        //returning the output list.
        return ans;
    }
};

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
```












<br /><br /><br />
## Problem 12:
**[Bottom View of Binary Tree](https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)**<br />
Given a `binary tree`, print the _bottom view from left to right_.<br />
A `node` is included in bottom view if it can be seen when we look at the tree from **bottom**.<br />
<pre>

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
</pre>
If there are multiple `bottom-most nodes` for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, `3` and `4` are both the `bottommost nodes` at `horizontal distance 0`, we need to print `4`.<br />
<pre>

                       20
                    /      \
                  8         22
                /   \     /    \
              5      3   4      25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
</pre> 
<pre>
Example 1:
Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.
<img src = "https://contribute.geeksforgeeks.org/wp-content/uploads/BT-1.jpg"><br />
Thus nodes of the binary tree will be printed as such 3 1 2.
</pre>
<pre>
Example 2:
Input:
         10
       /    \
      20     30
     /  \
    40   60
Output: 40 20 60 30
</pre>

**Your Task:**<br />
This is a functional problem, you don't need to care about input, just complete the function `bottomView()` which takes the `root node` of the tree as input and returns _an array containing the bottom view of the given tree_.<br />

<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
</pre>

* Constraints: `1 <= Number of nodes <= 10^5`<br />
`1 <= Data of a node <= 10^5`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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


vector <int> bottomView(Node *root);

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

        // Get the current nodes value from the string
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

//Function to return a list containing the bottom view of the given tree.
class Solution {
  public:
    vector <int> bottomView(Node *root)
    {
        vector <int> res;
        if (root == NULL)
            return res;
    
        //initializing a variable 'hd' with 0 for the root element.
        int hd = 0;
    
        //TreeMap which stores key value pair sorted on key value.
        map<int, int> m;
        map<Node  *, int> mh;
    
        //Queue to store tree nodes in level order traversal.
        queue<Node *> q;
    
        //assigning initialized horizontal distance value to 
        //root node and adding it to the queue.
        mh[root] = hd;
        q.push(root);
    
        
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
    
            //extracting the horizontal distance value from dequeued tree node.
            hd = mh[temp];
    
            //putting the dequeued tree node to TreeMap having key as  
            //horizontal distance. Every time we find a node having same
            //horizontal distance we need to replace the data in the map.
            m[hd] = temp->data;
    
            //if the dequeued node has a left child, adding it to 
            //the queue with a horizontal distance hd-1.
            if (temp->left != NULL)
            {
                mh[temp->left] = hd-1;
                q.push(temp->left);
            }
    
            //if the dequeued node has a right child adding it to 
            //the queue with a horizontal distance hd+1.
            if (temp->right != NULL)
            {
                mh[temp->right] = hd+1;
                q.push(temp->right);
            }
        }
        
        //traversing the map elements and storing nodes in the list.
        for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
            res.push_back (i->second);
            
        //returning the output list.
        return res;
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
```













<br /><br /><br />
## Problem 13:
**[Zig-Zag traversal of a binary tree](https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1)**<br />
Given a `Binary Tree`. Find the **Zig-Zag Level Order Traversal** of the **Binary Tree**.<br />
 
<pre>
Example 1:
Input:
        3
      /   \
     2     1
Output:
3 1 2
</pre>
<pre>
Example 2:
Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `zigZagTraversal()` which takes the `root node` of the Binary Tree as its input and returns _a list containing the node values as they appear in the **Zig-Zag Level-Order Traversal** of the Tree_.<br />

<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
</pre>
 
* Constraints: `1 <= N <= 10^4`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
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

        // Get the current node value from the string
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

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector <int> res;
        
        //if root is null, we return the list.
        if (!root)return res;
        
        //declaring two stacks to store the current and new level.
        stack<struct Node*> currentlevel;
        stack<struct Node*> nextlevel;
        
        //pushing the root in currentlevel stack.
        currentlevel.push(root);
        bool lefttoright = true;
        
        while (!currentlevel.empty())
        {
            //storing the top element of currentlevel stack in temp and popping it.
            Node* temp = currentlevel.top();
            currentlevel.pop();
            
            //if temp is not null, we store the data at temp in list.
            if (temp) 
            {
                res.push_back (temp->data);
                
                //if lefttoright is true then it stores nodes from left to right 
                //else from right to left in nextlevel stack.
                if (lefttoright)
                {
                    if (temp->left)
                        nextlevel.push(temp->left);
                    if (temp->right)
                        nextlevel.push(temp->right);
                }
                else 
                {
                    if (temp->right)
                        nextlevel.push(temp->right);
                    if (temp->left)
                        nextlevel.push(temp->left);
                }
            }
            
            //if currentlevel stack is empty lefttoright is flipped to change 
            //the order of storing the nodes and both stacks are swapped.
            if (currentlevel.empty()) 
            {
                lefttoright = !lefttoright;
                swap(currentlevel, nextlevel);
            }
        }
        //returning the list.
        return res;
    }
};
  
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}
```










<br /><br /><br />
## Problem 14:
**[Check if a tree is balanced or not](https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1)**<br />
Given a `binary tree`, find if it is _height balanced or not_.<br /> 
A tree is `height` balanced if difference between **heights of left and right subtrees** is not more than one for all nodes of tree.<br />
<pre>
A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5
</pre>
<pre>
Example 1:
Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced
</pre>
<pre>
Example 2:
Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height of left subtree and right subtree is 1.
Hence balanced. 
</pre>

**Your Task:**<br />
You don't need to take input. Just complete the function `isBalanced()` that takes root `node as parameter` and returns `true`, if the tree is balanced else returns `false`.<br />

* Constraints: `1 <= Number of nodes <= 10^5`<br />
`0 <= Data of a node <= 10^6`<br />

<pre>
Expected time complexity: O(N)
Expected auxiliary space: O(h) , where h = height of tree
</pre>

```cpp
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
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

        // Get the current node value from the string
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

//Function to check for balanced tree.
bool isBalancedRec(Node *root, int* height)
    {
      int lh = 0, rh = 0;
      int l = 0, r = 0;
    
      //if root is null, we return true.
      if(root == NULL)
      {
        *height = 0;
         return 1;
      }
    
      //calling the function isBalancedRec recursively for the heights of left and
      //right subtrees and storing the returned values in l and r.
      l = isBalancedRec(root->left, &lh);
      r = isBalancedRec(root->right,&rh);
    
      //height of current node is (max of heights of left and right subtrees) +1.
      *height = (lh > rh? lh: rh) + 1;
    
      //if difference between heights of left and right subtrees is 2 or more 
      //than 2 then this node is not balanced so we return false.
      if((lh - rh >= 2) || (rh - lh >= 2))
        return 0;
    
      //if this node is balanced and left and right subtrees are balanced 
      //then we return true.
      else 
      return l&&r;
    }
    
    //Function to check whether a binary tree is balanced or not.
    class Solution{
    public:
    bool isBalanced(Node *root)
    {
       int h = 0;
       return isBalancedRec(root, &h);
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}
```









<br /><br /><br />
## Problem 15:
**[Diagonal Traversal of Binary Tree](https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/)**<br />
Consider lines with a slope of `-1` that cross through nodes. Print **all diagonal elements in a binary tree** that belong to the same line, given a `binary tree`.<br />
<pre>
Input : Root of below tree
</pre>
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/d1-1.png"><br />
<pre>
Output : 
Diagonal Traversal of binary tree: 
 8 10 14
 3 6 7 13
 1 4
Observation : root and root->right values will be prioritized over all root->left values.
</pre>
The plan is to make use of a `map`. Different `slope distances are used in the map as a key`. The `map’s value is a node vector (or dynamic array)`. To save values in the map, we **traverse the tree**. We print the contents of the map after it has been constructed.<br />
Below is the implementation of the above idea.<br />
```cpp
// C++ program for diagonal
// traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;

// Tree node
struct Node
{
	int data;
	Node *left, *right;
};

/* root - root of the binary tree
d - distance of current line from rightmost
		-topmost slope.
diagonalPrint - multimap to store Diagonal elements (Passed by Reference) */
void diagonalPrintUtil(Node* root, int d, map<int, vector<int>> &diagonalPrint)
{
	// Base case
	if (!root)
		return;

	// Store all nodes of same
	// line together as a vector
	diagonalPrint[d].push_back(root->data);

	// Increase the vertical
	// distance if left child
	diagonalPrintUtil(root->left, d + 1, diagonalPrint);

	// Vertical distance remains
	// same for right child
	diagonalPrintUtil(root->right, 	d, diagonalPrint);
}

// Print diagonal traversal
// of given binary tree
void diagonalPrint(Node* root)
{
	
	// create a map of vectors
	// to store Diagonal elements
	map<int, vector<int> > diagonalPrint;
	diagonalPrintUtil(root, 0, diagonalPrint);

	cout << "Diagonal Traversal of binary tree : \n";
	for (auto it :diagonalPrint)
	{
		vector<int> v=it.second;
		for(auto it:v)
		cout<<it<<" ";
		cout<<endl;
	}
}

// Utility method to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// Driver program
int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);

	/* Node* root = newNode(1);
		root->left = newNode(2);
		root->right = newNode(3);
		root->left->left = newNode(9);
		root->left->right = newNode(6);
		root->right->left = newNode(4);
		root->right->right = newNode(5);
		root->right->left->right = newNode(7);
		root->right->left->left = newNode(12);
		root->left->right->left = newNode(11);
		root->left->left->right = newNode(10);*/

	diagonalPrint(root);

	return 0;
}
```
Output<br />
<pre>
Diagonal Traversal of binary tree : 
8 10 14 
3 6 7 13 
1 4 
</pre>
<pre>
Time complexity: O( N logN )
Auxiliary Space: O( N )
</pre>
The identical problem may be solved with a queue and an `iterative method`.<br />
```cpp
#include <bits/stdc++.h>
using namespace std;

// Tree node
struct Node {
	int data;
	Node *left, *right;
};

vector<int> diagonal(Node* root)
{
	vector<int> diagonalVals;
	if (!root)
		return diagonalVals;

	// The leftQueue will be a queue which will store all
	// left pointers while traversing the tree, and will be
	// utilized when at any point right pointer becomes NULL

	queue<Node*> leftQueue;
	Node* node = root;

	while (node) {

		// Add current node to output
		diagonalVals.push_back(node->data);
		// If left child available, add it to queue
		if (node->left)
			leftQueue.push(node->left);

		// if right child, transfer the node to right
		if (node->right)
			node = node->right;

		else {
			// If left child Queue is not empty, utilize it
			// to traverse further
			if (!leftQueue.empty()) {
				node = leftQueue.front();
				leftQueue.pop();
			}
			else {
				// All the right childs traversed and no
				// left child left
				node = NULL;
			}
		}
	}
	return diagonalVals;
}

// Utility method to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// Driver program
int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);

	/* Node* root = newNode(1);
			root->left = newNode(2);
			root->right = newNode(3);
			root->left->left = newNode(9);
			root->left->right = newNode(6);
			root->right->left = newNode(4);
			root->right->right = newNode(5);
			root->right->left->right = newNode(7);
			root->right->left->left = newNode(12);
			root->left->right->left = newNode(11);
			root->left->left->right = newNode(10);*/

	vector<int> diagonalValues = diagonal(root);
	for (int i = 0; i < diagonalValues.size(); i++) {
		cout << diagonalValues[i] << " ";
	}
	cout << endl;

	return 0;
}
```
Output<br />
<pre>
[8, 10, 14, 3, 6, 7, 13, 1, 4]
</pre>
<pre>
Time complexity: O( N log N )
Auxiliary Space: O(N)
</pre>
`Approach 2: Using Queue:`<br />
Every node will contribute to the formation of the following **diagonal**. Only when the **element’s left is available** will we push it into the `queue`. We’ll process the node and then go to the `right`.<br />
Below is the implementation of the above approach:<br />
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

vector <vector <int>> result;
void diagonalPrint(Node* root)
{
	if(root == NULL)
		return;

	queue <Node*> q;
	q.push(root);

	while(!q.empty())
	{
		int size = q.size();
		vector <int> answer;

		while(size--)
		{
			Node* temp = q.front();
			q.pop();

			// traversing each component;
			while(temp)
			{
				answer.push_back(temp->data);

				if(temp->left)
					q.push(temp->left);

				temp = temp->right;
			}
		}
		result.push_back(answer);
	}
}

int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);
	
	diagonalPrint(root);

	for(int i=0 ; i<result.size() ; i++)
	{
		for(int j=0 ; j<result[i].size() ; j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}
```
Output<br />
<pre>
8  10  14  
3  6  7  13  
1  4  
</pre>
<pre>
Time Complexity: O(N), because we are visiting nodes once.
Auxiliary Space: O(N), because we are using a queue.
</pre>








<br /><br /><br />
## Problem 16:
**[Boundary Traversal of binary tree](https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1)**<br />
Given a `Binary Tree`, find its `Boundary Traversal`. The traversal should be in the following order:<br />

 1. `Left boundary nodes:` defined as the path from the root to the **left-most node** ie- the leaf node you could reach when you always travel preferring the `left subtree over the right subtree`.<br /> 
 2. `Leaf nodes:` All the leaf nodes `except` for the ones that are **part of left or right boundary**.<br />
 3. `Reverse right boundary nodes:` defined as the path from the right-most node to the root. The `right-most node` is the `leaf node` you could reach when you always travel preferring the `right subtree over the left subtree`. **Exclude** the root from this as it was already included in the traversal of left boundary nodes.<br />

**Note:**<br />
If the root doesn't have a `left subtree or right subtree`, then the **root itself is the left or right boundary**.<br />

<pre>
Example 1:
Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
Explanation:
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20211103204119/graph4-300x300.png"><br />
</pre>
<pre>
Example 2:
Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8
Explanation:
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20211103204646/graph1-300x300.png"><br />
As you can see we have not taken the right subtree. 
</pre>

**Your Task:**<br />
This is a function problem. You don't have to take input. Just complete the function `boundary()` that takes the `root node` as input and returns an array containing the boundary values in **anti-clockwise**.<br />

<pre>
Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).
</pre>

* Constraints: `1 ≤ Number of nodes ≤ 10^5`<br />
`1 ≤ Data of a node ≤ 10^5`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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

        // Get the current node value from the string
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

class Solution
{
    void printLeaves(struct Node* root, vector <int> &res)
    {
        if (root == NULL)
            return;

        printLeaves(root->left, res);

        // Print it if it is a leaf node
        if (!(root->left) && !(root->right))
            res.push_back (root->data);

        printLeaves(root->right, res);
    }

// A function to print all left boundary nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
    void printBoundaryLeft(struct Node* root, vector <int> &res)
    {
        if (root == NULL)
            return;

        if (root->left) {

            // to ensure top down order, print the node
            // before calling itself for left subtree
            res.push_back (root->data);
            printBoundaryLeft(root->left, res);
        }
        else if (root->right) {
            res.push_back (root->data);
            printBoundaryLeft(root->right, res);
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output
    }

// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
    void printBoundaryRight(struct Node* root, vector <int> &res)
    {
        if (root == NULL)
            return;

        if (root->right) {
            // to ensure bottom up order, first call for right
            // subtree, then print this node
            printBoundaryRight(root->right, res);
            res.push_back (root->data);
        }
        else if (root->left) {
            printBoundaryRight(root->left, res);
            res.push_back (root->data);
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output
    }

// A function to do boundary traversal of a given binary tree
public:
    vector <int> boundary(struct Node* root)
    {
        vector <int> res;
        if (root == NULL)
            return res;

        res.push_back (root->data);

        // Print the left boundary in top-down manner.
        printBoundaryLeft(root->left, res);

        // Print all leaf nodes
        printLeaves(root->left, res);
        printLeaves(root->right, res);

        // Print the right boundary in bottom-up manner
        printBoundaryRight(root->right, res);
    }

};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
```








<br /><br /><br />
## Problem 17:
**[Construct Binary Tree from String with bracket representation](https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/)**<br />
Construct a `binary tree` from a string consisting of `parenthesis` and `integers`. The whole input represents a **binary tree**. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the `root’s value` and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the **left child node of the parent first if it exists**.<br />
Examples:<br />
<pre>
Input : "1(2)(3)" 
Output : 1 2 3
Explanation :
           1
          / \
         2   3
Explanation: first pair of parenthesis contains 
left subtree and second one contains the right 
subtree. Preorder of above tree is "1 2 3".  

Input : "4(2(3)(1))(6(5))"
Output : 4 2 3 1 6 5
Explanation :
           4
         /   \
        2     6
       / \   / 
      3   1 5   
</pre>
We know `first character in string is root`. Substring inside the `first adjacent pair of parenthesis is for left subtree` and `substring inside second pair of parenthesis is for right subtree` as in the below diagram.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/BtreeRepresent.jpg"><br />
We need to find the substring corresponding to `left subtree` and substring corresponding to `right subtree` and then **recursively call** on both of the substrings. 
For this **first find the index of starting index and end index** of each substring.<br />
To find the index of closing parenthesis of `left subtree substring`, use a `stack`. Let the found index be stored in `index variable`.<br />
```cpp
/* C++ program to construct a binary tree from
the given string */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
struct Node {
	int data;
	Node *left, *right;
};
/* Helper function that allocates a new node */
Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* This function is here just to test */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// function to return the index of close parenthesis
int findIndex(string str, int si, int ei)
{
	if (si > ei)
		return -1;

	// Inbuilt stack
	stack<char> s;

	for (int i = si; i <= ei; i++) {

		// if open parenthesis, push it
		if (str[i] == '(')
			s.push(str[i]);

		// if close parenthesis
		else if (str[i] == ')') {
			if (s.top() == '(') {
				s.pop();

				// if stack is empty, this is
				// the required index
				if (s.empty())
					return i;
			}
		}
	}
	// if not found return -1
	return -1;
}

// function to construct tree from string
Node* treeFromString(string str, int si, int ei)
{
	// Base case
	if (si > ei)
		return NULL;

	// new root
	Node* root = newNode(str[si] - '0');
	int index = -1;

	// if next char is '(' find the index of
	// its complement ')'
	if (si + 1 <= ei && str[si + 1] == '(')
		index = findIndex(str, si + 1, ei);

	// if index found
	if (index != -1) {

		// call for left subtree
		root->left = treeFromString(str, si + 2, index - 1);

		// call for right subtree
		root->right
			= treeFromString(str, index + 2, ei - 1);
	}
	return root;
}

// Driver Code
int main()
{
	string str = "4(2(3)(1))(6(5))";
	Node* root = treeFromString(str, 0, str.length() - 1);
	preOrder(root);
}
```
Output<br />
<pre>
4 2 3 1 6 5 
</pre>
<pre>
Time Complexity: O(N^2)
Auxiliary Space: O(N)
</pre>
**Another recursive approach:**<br />
`Algorithm:`<br />

 1. The very first element of the string is the `root`.<br />
 2. If the next two consecutive elements are `“(”` and `“)”`, this means there is `no left child otherwise` we will create and **add the left child to the parent node** `recursively`.<br />
 3. Once the left child is added recursively, we will look for consecutive `“(”` and add the `right child to the parent node`.<br />
 4. Encountering `“)”` means the `end of either left or right node` and we will increment the `start index`<br />
 5. The `recursion ends` **when** the `start index is greater than equal to the end index`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

// custom data type for tree building
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

// Below function accepts string and a pointer variable as
// an argument
// and draw the tree. Returns the root of the tree
Node* constructtree(string s, int* start)
{
	// Assuming there is/are no negative
	// character/characters in the string
	if (s.size() == 0 || *start >= s.size())
		return NULL;

	// constructing a number from the continuous digits
	int num = 0;
	while (*start < s.size() && s[*start] != '('
		&& s[*start] != ')') {
		int num_here = (int)(s[*start] - '0');
		num = num * 10 + num_here;
		*start = *start + 1;
	}

	// creating a node from the constructed number from
	// above loop
	struct Node* root = NULL;
	if(num > 0)
	root = new Node(num);

	// As soon as we see first right parenthesis from the
	// current node we start to construct the tree in the
	// left
	if (*start < s.size() && s[*start] == '(') {
		*start = *start + 1;
		root->left = constructtree(s, start);
	}
	if (*start < s.size() && s[*start] == ')')
	{
	*start = *start + 1;
	return root;
	}

	// As soon as we see second right parenthesis from the
	// current node we start to construct the tree in the
	// right
	if (*start < s.size() && s[*start] == '(') {
		*start = *start + 1;
		root->right = constructtree(s, start);
	}
	if (*start < s.size() && s[*start] == ')')
		*start = *start + 1;
	return root;
}
void preorder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	string s = "4(2(3)(1))(6(5))";
	// cin>>s;
	int start = 0;
	Node* root = constructtree(s, &start);
	preorder(root);
	return 0;
}
```
Output<br />
<pre>
4 2 3 1 6 5 
</pre>



<br /><br /><br />
## Problem 18:
**[Convert Binary tree into Doubly Linked List](https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1)**<br />
Given a `Binary Tree (BT)`, convert it to a `Doubly Linked List(DLL) In-Place`. The **left and right pointers in nodes are to be used as previous and next pointers** respectively in converted DLL. The `order of nodes in DLL must be same as Inorder` of the given Binary Tree. The **first node of Inorder traversal (leftmost node in BT)** must be the head node of the DLL.<br />
<img src = "http://www.geeksforgeeks.org/wp-content/uploads/TreeToList.png"><br />
<pre>
Example 1:
Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2
</pre>
<pre>
Example 2:
Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.
</pre>

**Your Task:**<br />
You don't have to take input. Complete the function `bToDLL()` that takes `root node of the tree` as a parameter and returns the **head of DLL** . The driver code prints the DLL both ways.<br />

<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for the recursion stack.
</pre>

* Constraints: `1 ≤ Number of nodes ≤ 10^5`<br />
`0 ≤ Data of a node ≤ 10^5`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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
            
        // Get the current node value from the string
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

class Solution
{
    public:
    //Function to convert a binary tree to doubly linked list.
    void bToDLLUtil(Node *root, Node **head_ref)
    {
        //base case for recursion.
        if(root == NULL)
            return;
    
        //calling function recursively to convert right subtrees.
        bToDLLUtil(root->right, head_ref);
    
        //inserting root into doubly linked list.
        root->right = *head_ref;
    
        //changing left pointer of previous head.
        if (*head_ref != NULL)
            (*head_ref)->left = root;
    
        //changing head of doubly linked list.
        *head_ref = root;
    
        //calling function recursively to convert left subtrees.
        bToDLLUtil(root->left, head_ref);
    }

    public:
    //Function to convert binary tree to doubly linked list and return it.
    Node* bToDLL(Node *root)
    {
        Node *head = NULL;
        //calling the function for conversion.
        bToDLLUtil(root,&head);
        return head;
        
    }
};

/* Function to print nodes in a given doubly linked list */
void printList(Node *node)
{
    Node *prev = NULL;
    while (node!=NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node *root)
{
   if (root != NULL)
   {
       inorder(root->left);
       cout << root->data;
       inorder(root->right);
   }
}

int main()
{
  int t;
  cin >> t;
  getchar();
  
  while (t--)
  {
     string inp;
     getline(cin, inp);
     Node *root = buildTree(inp);
     
     Solution ob; 
     Node *head = ob.bToDLL(root);
     printList(head);

  }
  return 0;
}
```












<br /><br /><br />
## Problem 19:
**[Convert Binary tree into Sum tree](https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1)**<br />
Given a `Binary Tree` of size `N` , where each node can have `positive or negative values`. Convert this to a tree where each node contains the `sum of the left and right sub trees` of the original tree. The values of leaf nodes are changed to `0`.<br />
<pre>
Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
</pre>

**Your Task:**<br />  
You dont need to read input or print anything. Complete the function `toSumTree()` which takes `root node` as input parameter and modifies the given `tree in-place`.<br />
**Note:**<br />
If you click on Compile and Test the output will be the `in-order traversal` of the modified tree.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
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
            
        // Get the current node value from the string
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

void inorder(Node * node)
{
    if(node==NULL)
        return;
    
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

class Solution {
  public:
    // Convert a given tree to a tree where  
    // every node contains sum of values of  
    // nodes in left and right subtrees in the original tree
    int toSumTreeUtil(Node *node)  
    {  
        // Base case  
        if(node == NULL)  
        return 0;  
      
        // Store the old value  
        int old_val = node->data;  
      
        // Recursively call for left and 
        // right subtrees and store the sum as  
        // new value of this node  
        node->data = toSumTreeUtil(node->left) + toSumTreeUtil(node->right);  
      
        // Return the sum of values of nodes 
        // in left and right subtrees and  
        // old_value of this node  
        return node->data + old_val;  
    } 
    
    void toSumTree(Node *node)
    {
        toSumTreeUtil(node);
    }
};

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        ob.toSumTree(root);
        inorder(root);
        cout<<endl;
    }
    return 1;
}
```









<br /><br /><br />
## Problem 20:
**[Construct Binary tree from Inorder and preorder traversal](https://practice.geeksforgeeks.org/problems/construct-tree-1/1)**<br />
Given `2` Arrays of `Inorder and preorder traversal`. Construct a tree and print the `Postorder traversal`.<br /> 

<pre>
Example 1:
Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
</pre>
<pre>
Example 2:
Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
</pre>

**Your Task:**<br />
Your task is to complete the function `buildTree()` which takes `3` arguments(`inorder traversal array`, `preorder traversal array`, and `size of tree n`) and returns `the root node to the tree constructed`. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)<br />

<pre>
Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).
</pre>

* Constraints: `1<=Number of Nodes<=1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if(root==NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

class Solution{
  public:
    int findIndex(int arr[], int start, int target)
    {
        int i=0;
        while( arr[start+i] != target ) i++;
        return i;
    }
    
    Node* buildUtil(int inorder[], int preorder[], int inStart, int preStart, int n)
    {
        if(n==0) return NULL;
        
        Node* ret = new Node( preorder[preStart] );
        
        int i = findIndex( inorder, inStart, preorder[preStart] );
        
        ret->left = buildUtil( inorder, preorder, inStart, preStart+1, i );
        ret->right = buildUtil( inorder, preorder, inStart+i+1, preStart+i+1, n-i-1 );
        
        return ret;
    }
    
    Node *buildTree(int inorder[], int preorder[], int n)
    {
        return buildUtil(inorder, preorder, 0, 0, n);
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int inorder[n], preorder[n];
        for(int i=0; i<n; i++)
            cin>> inorder[i];
        for(int i=0; i<n; i++)
            cin>> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout<< endl;
    }
}
```








<br /><br /><br />
## Problem 21:
**[Minimum swap required to convert binary tree to binary search tree](https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/)**<br />
Given the array representation of `Complete Binary Tree` i.e, if index `i` is the parent, index `2*i + 1` is the `left child` and index `2*i + 2` is the `right child`. The task is to find the _minimum number of swap required to convert it into Binary Search Tree_.<br />
Examples:<br />
<pre>
Input : arr[] = { 5, 6, 7, 8, 9, 10, 11 }
Output : 3
Binary tree of the given array:
</pre>
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/dig11.png"><br />
<pre>
Swap 1: Swap node 8 with node 5.
Swap 2: Swap node 9 with node 10.
Swap 3: Swap node 10 with node 7.
</pre>
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/dig21.png"><br />
<pre>
So, minimum 3 swaps are required.

Input : arr[] = { 1, 2, 3 }
Output : 1
Binary tree of the given array:
</pre>
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Dig3.png"><br />
<pre>
After swapping node 1 with node 2.
</pre>
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Dig41.png"><br />
<pre>
So, only 1 swap required.
</pre>
The idea is to use the fact that `inorder traversal` of `Binary Search Tree` is in increasing order of their value.<br /> 
So, find the `inorder traversal` of the `Binary Tree` and store it in the array and try to sort the array. The `minimum number` of swap required to get the array sorted will be the answer.<br />
<pre>
Time Complexity: O(n log n).
</pre>
Implementation:<br />
```cpp
// C++ program for Minimum swap required
// to convert binary tree to binary search tree
#include<bits/stdc++.h>
using namespace std;

// Inorder Traversal of Binary Tree
void inorder(int a[], std::vector<int> &v, int n, int index)
{
	// if index is greater or equal to vector size
	if(index >= n)
		return;
	inorder(a, v, n, 2 * index + 1);
	
	// push elements in vector
	v.push_back(a[index]);
	inorder(a, v, n, 2 * index + 2);
}

// Function to find minimum swaps to sort an array
int minSwaps(std::vector<int> &v)
{
	std::vector<pair<int,int> > t(v.size());
	int ans = 0;
	for(int i = 0; i < v.size(); i++)
		t[i].first = v[i], t[i].second = i;
	
	sort(t.begin(), t.end());
	for(int i = 0; i < t.size(); i++)
	{
		// second element is equal to i
		if(i == t[i].second)
			continue;
		else
		{
			// swapping of elements
			swap(t[i].first, t[t[i].second].first);
			swap(t[i].second, t[t[i].second].second);
		}
		
		// Second is not equal to i
		if(i != t[i].second)
			--i;
		ans++;
	}
	return ans;
}

// Driver code
int main()
{
	int a[] = { 5, 6, 7, 8, 9, 10, 11 };
	int n = sizeof(a) / sizeof(a[0]);
	std::vector<int> v;
	inorder(a, v, n, 0);
	cout << minSwaps(v) << endl;
}
```
Output<br />
<pre>
3
</pre>








<br /><br /><br />
## Problem 22:
**[Check if Binary tree is Sum tree or not](https://practice.geeksforgeeks.org/problems/sum-tree/1)**<br />
Given a `Binary Tree`. Return `true` if, for every `node X` in the tree other than the leaves, its value is equal to the sum of its `left subtree's value` and its `right subtree's value`. Else return `false`.<br />
An empty tree is also a **Sum Tree as the sum of an empty tree can be considered to be 0**. A leaf node is also considered a Sum Tree.<br />

<pre>
Example 1:
Input:
    3
  /   \    
 1     2

Output: 1
Explanation:
The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a sum tree.
</pre>
<pre>
Example 2:
Input:

          10
        /    \
      20      30
    /   \ 
   10    10

Output: 0
Explanation:
The given tree is not a sum tree. For the root node, sum of elements
in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.
</pre>

**Your Task:** 
You don't need to read input or print anything. Complete the function `isSumTree()` which takes **root node as input parameter** and returns `true` if the tree is a SumTree else it returns `false`.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the Tree)
</pre>

* Constraints: `1 ≤ number of nodes ≤ 10^4`<br />

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
            
        // Get the current node value from the string
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

class Solution
{
    public:
    int isLeaf(struct Node *node)
    {
        if(node == NULL)
            return 0;
        if(node->left == NULL && node->right == NULL)
            return 1;
        return 0;
    }
    
    /* returns 1 if SumTree property holds for the given
        tree */
    public:
    bool isSumTree(struct Node* node)
    {
        int ls; // for sum of nodes in left subtree
        int rs; // for sum of nodes in right subtree
    
        /* If node is NULL or it's a leaf node then
           return true */
        if(node == NULL || isLeaf(node))
            return 1;
    
        if( isSumTree(node->left) && isSumTree(node->right))
        {
            // Get the sum of nodes in left subtree
            if(node->left == NULL)
                ls = 0;
            else if(isLeaf(node->left))
                ls = node->left->data;
            else
                ls = 2*(node->left->data);
    
            // Get the sum of nodes in right subtree
            if(node->right == NULL)
                rs = 0;
            else if(isLeaf(node->right))
                rs = node->right->data;
            else
                rs = 2*(node->right->data);
    
            /* If root's data is equal to sum of nodes in left
               and right subtrees then return 1 else return 0*/
            return(node->data == ls + rs);
        }
    
        return 0;
    }

    
};

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout <<ob.isSumTree(root) << endl;
    }
    return 1;
}
```












<br /><br /><br />
## Problem 23:
**[Check if all leaf nodes are at same level or not](https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1)**<br />
Given a `Binary Tree`, **check if all leaves are at same level or not**.<br />

<pre>
Example 1:
Input: 
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.
</pre>
<pre>
Example 2:
Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.
</pre>

**Your Task:**<br /> 
You dont need to read input or print anything. Complete the function `check()` which takes root node as input parameter and returns `true/false` depending on whether all the leaf nodes are at the same level or not.<br />
 
<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
</pre> 

* Constraints: `1 ≤ N ≤ 10^3`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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

class Solution{
    public:
    /* Recursive function which checks whether
    all leaves are at same level */
    bool checkUtil(struct Node *root,
                int level, int *leafLevel)
    {
        // Base case
        if (root == NULL) return true;
     
        // If a leaf node is encountered
        if (root->left == NULL &&
            root->right == NULL)
        {
            // When a leaf node is found
            // first time
            if (*leafLevel == 0)
            {
                *leafLevel = level; // Set first found leaf's level
                return true;
            }
     
            // If this is not first leaf node, compare
            // its level with first leaf level
            return (level == *leafLevel);
        }
     
        // If this node is not leaf, recursively
        // check left and right subtrees
        return checkUtil(root->left, level + 1, leafLevel) &&
                checkUtil(root->right, level + 1, leafLevel);
    }
     
    /* The main function to check
    if all leafs are at same level.
    It mainly uses checkUtil() */
    bool check(struct Node *root)
    {
        int level = 0, leafLevel = 0;
        return checkUtil(root, level, &leafLevel);
    }
};
    
// Driver program to test size function
int main()
{
    int t;
    cin>> t;
    getchar();
    while (t--)
    {
        string s;
        getline( cin, s );
        Node* head = buildTree( s );
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}
```












<br /><br /><br />
## Problem 24:
**[Check if a Binary Tree contains duplicate subtrees of size 2 or more [ IMP ]](https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1)**<br />
Given a `binary tree`, find out whether it contains a `duplicate sub-tree` of size `two or more`, or not.<br />

<pre>
Example 1 :
Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
</pre>
<pre>
Example 2 :
Input : 
               1
             /   \ 
           2       3
Output: 0
Explanation: There is no duplicate sub-tree in the given binary tree.
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `dupSub()` which takes `root of the tree` as the only arguement and returns `1` if the binary tree contains a `duplicate sub-tree of size two or more`, else `0`.<br />
**Note:** Two same leaf nodes are not considered as subtree as size of a leaf node is one.<br />

* Constraints: `1 ≤ Number of nodes ≤ 100`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;

    Node(char x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
  public:
    unordered_set<string> subtrees;
    char MARKER = '$'; 
    // This function returns empty string if tree
    // contains a duplicate subtree of size 2 or more.
    string dupSubUtil(Node *root)
    {
        string s = "";
     
        // If current node is NULL, return marker
        if (root == NULL)
            return s + MARKER;
     
        // If left subtree has a duplicate subtree.
        string lStr = dupSubUtil(root->left);
        if (lStr.compare(s) == 0)
           return s;
     
        // Do same for right subtree
        string rStr = dupSubUtil(root->right);
        if (rStr.compare(s) == 0)
           return s;
     
        // Serialize current subtree
        s = s + root->data + lStr + rStr;
     
        // If current subtree already exists in hash
        // table. [Note that size of a serialized tree
        // with single node is 3 as it has two marker
        // nodes.
        if (s.length() > 3 and 
            subtrees.find(s) != subtrees.end())
           return "";
     
        subtrees.insert(s);
     
        return s;
    }
    
    int dupSub(Node *root)
    {
        //subtrees.clear();
        string str = dupSubUtil(root);
     
        if(str.compare("") == 0)
            return 1;
        else
            return 0;
    }
};

int main()
{
    
    int t;
    cin >> t;
    //cout << t << "\n";
    while (t--)
    {
        string treeString;
        getline(cin >> ws, treeString);
        struct Node* root = buildTree(treeString);
        Solution ob;
        cout << ob.dupSub(root) << "\n";
    }
    return 0;
}
```










<br /><br /><br />
## Problem 25:
**[Check if 2 trees are mirror or not](https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1)**<br />
Given two `n-ary trees`. Check if they are mirror images of each other or not. You are also given e denoting the `number of edges` in both trees, and two arrays, `A[]` and `B[]`. Each array has `2*e` space separated values `u`,`v` denoting an edge from `u` to `v` for the both trees.<br />

<pre>
Example 1:
Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 3, 1, 2}
Output:
1
Explanation:
   1          1
 / \        /  \
2   3      3    2 
As we can clearly see, the second tree is mirror image of the first.
</pre>
<pre>
Example 2:
Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 2, 1, 3}
Output:
0
Explanation:
   1          1
 / \        /  \
2   3      2    3 
As we can clearly see, the second tree isn't mirror image of the first.
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `checkMirrorTree()` which takes 2 Integers `n`, and `e`;  and two arrays `A[]` and `B[]` of size `2*e` as input and returns `1` if the trees are mirror images of each other and `0` if not.<br />

<pre>
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
</pre>

* Constraints: `1 <= n,e <= 10^5`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        
        vector<int> g1[100005];
        vector<int> g2[100005];
        
        for(int i=0; i<2*e; i+=2)
        {
            int x = A[i];
            int y = A[i+1];
            g1[x].push_back(y);
        }
        
        for(int i=0; i<2*e; i+=2)
        {
            int x = B[i];
            int y = B[i+1];
            g2[x].push_back(y);
        }
        
        stack<int> s;
        queue<int> q;
        
        s.push(1);
        q.push(1);
        bool f=0;
        while(!s.empty() and !q.empty())
        {
            int s1 = s.top();
            s.pop();
            int s2 = q.front();
            q.pop();
            
            if(s1!=s2)
            {
                f=1;
                break;
            }
            
            for(auto i = 0; i<g1[s1].size(); i++)
                s.push(g1[s1][i]);
                
            vector<int> k;
            while(!q.empty())
            {
                k.push_back(q.front());
                q.pop();
            }
            
            for(auto i=0; i<g2[s2].size(); i++)
                q.push(g2[s2][i]);
                
            for(int i=0; i<k.size(); i++)
                q.push(k[i]);
        }
        
        if(s.empty() and q.empty() and !f)
            return 1;
        else 
            return 0;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
```











<br /><br /><br />
## Problem 26:
**[Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)](https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1)**<br />
Given a `binary tree` of size `N`. Your task is to complete the function `sumOfLongRootToLeafPath()`, that find the **sum of all nodes on the longest path** from root to `leaf node`.<br />
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.<br />

<pre>
Example 1:
Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13
</pre>
<pre>
Example 2:
Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 11
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `sumOfLongRootToLeafPath()` which takes `root node` of the tree as input parameter and returns an integer denoting the **sum of the longest root to leaf path of the tree**. If the tree is empty, return `0`.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1 <= Number of nodes <= 10^4`<br />
`1 <= Data of a node <= 10^4`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    void sumOfLongRootToLeafPathUtil(Node *root, int sum, int len, int &maxLen, int &maxSum)
    {
        if (!root)
        {
            if (maxLen < len)
            {
                maxLen = len;
                maxSum = sum;
            }
            else if (maxLen == len && maxSum < sum)
                maxSum = sum;
            return;
        }
        sumOfLongRootToLeafPathUtil(root->left, sum + root->data, len + 1, maxLen, maxSum);
        sumOfLongRootToLeafPathUtil(root->right, sum + root->data, len + 1, maxLen, maxSum);
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        if (!root)
            return 0;
        // code here
        int maxSum = INT_MIN, maxLen = 0;
        sumOfLongRootToLeafPathUtil(root, 0, 0, maxLen, maxSum);
        return maxSum;
    }
};

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}
```











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
