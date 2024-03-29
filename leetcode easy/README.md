# Leetcode daily easy questions
<br />* [Go to Bottom](#This-is-Bottom)<br /><br />
**[509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)**<br />
The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,<br />
<pre>
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
</pre>
Given `n`, calculate `F(n)`.<br />

>Example 1:<br />
Input: n = 2<br />
Output: 1<br />
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.<br />

>Example 2:<br />
Input: n = 3<br />
Output: 2<br />
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.<br />

>Example 3:<br />
Input: n = 4<br />
Output: 3<br />
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.<br />
 
* Constraints: `0 <= n <= 30`<br />

```cpp
class Solution {
public:
    int fib(int n) {
        if(n <= 1)return n;
        return fib(n-1) + fib(n-2);
    }
};
```






<br /><br /><br />**[1260. Shift 2D Grid](https://leetcode.com/problems/shift-2d-grid/)**<br />
Given a 2D `grid` of size `m x n` and an integer `k`. You need to shift the `grid k` times.<br />
In one shift operation:<br />
  *  Element at `grid[i][j]` moves to `grid[i][j + 1]`.<br />
  *  Element at `grid[i][n - 1]` moves to `grid[i + 1][0]`.<br />
  *  Element at `grid[m - 1][n - 1]` moves to `grid[0][0]`.<br />
  
Return the 2D grid after applying shift operation `k` times.<br />
>Example 1: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2019/11/05/e1.png"><br />
>Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1 <br />
>Output: [[9,1,2],[3,4,5],[6,7,8]] <br /> 

>Example 2: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2019/11/05/e2.png"><br />
>Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4 <br /> 
>Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]] <br /> 

>Example 3: <br /> 
>Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9 <br /> 
>Output: [[1,2,3],[4,5,6],[7,8,9]]


* Constraints:<br />`m == grid.length`<br /> 
`n == grid[i].length`<br />
`1 <= m <= 50`<br />
`1 <= n <= 50`<br />
`-1000 <= grid[i][j] <= 1000`<br />
`0 <= k <= 100`<br />
```cpp
class Solution {
public:
     vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // (j + numbers of columns added)%m
                int newJ=(j+k)%m; 
                // (i + numbers of rows added)%n 
                int newI=(i+(j+k)/m)%n; 
                ans[newI][newJ]=grid[i][j];
            }
        }
        return ans;
    }
};
```

 

<br /> <br /> <br /> **[700. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)**<br />
You are given the `root` of a binary search tree (BST) and an integer `val`.<br />
Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.<br />

>Example 1: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg"><br />
>Input: root = [4,2,7,1,3], val = 2<br /> 
>Output: [2,1,3]<br /> 
	
>Example 2: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg"><br />
>Input: root = [4,2,7,1,3], val = 5<br /> 
>Output: []<br /> 
	
* Constraints:<br />`The number of nodes in the tree is in the range [1, 5000].`<br /> 
`1 <= Node.val <= 10^7`<br /> 
`root` is a binary search tree.<br /> 
`1 <= val <= 10^7`<br /> 
	
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
    void dfs(TreeNode* root, int val, TreeNode*& ans) {
        if(!root) return;
        if(root->val == val)ans = root;
        else if(root->val > val)dfs(root->left, val, ans);
        else if(root->val < val)dfs(root->right, val, ans);
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = nullptr;
        dfs(root, val, ans);
        return ans; 
    }
};
```
	



<br /> <br /> <br /> **[897. Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/)**<br />	
Given the `root` of a binary search tree, rearrange the tree in `in-order` so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

>Example 1: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/11/17/ex1.jpg"><br />
>Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]<br /> 
>Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]<br /> 

>Example 2: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/11/17/ex2.jpg"><br />
>Input: root = [5,1,7]<br />
>Output: [1,null,5,null,7]<br />
	
* Constraints:<br />The number of nodes in the given tree will be in the range `[1, 100]`.<br /> 
`0 <= Node.val <= 1000`<br />

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
public:
    TreeNode * inorder(TreeNode *root,TreeNode *tmp){
        if(root==NULL) return tmp;
        tmp=inorder(root->left,tmp);
        tmp->right=root;
        root->left=NULL;
        tmp=root;
        return inorder(root->right,tmp);
    }
    
    TreeNode* increasingBST(TreeNode* root){
        TreeNode* dummy=new TreeNode(0);
        TreeNode* tmp=dummy;
        inorder(root,tmp);
        return dummy->right;
    }
};
```
	
	

 
 
<br /> <br /> <br />**[705. Design HashSet](https://leetcode.com/problems/design-hashset/)**<br />
Design a `HashSet` without using any built-in hash table libraries.<br />
Implement `MyHashSet` class:<br />

* `void add(key)` Inserts the value `key` into the HashSet.<br />
* `bool contains(key)` Returns whether the value `key` exists in the HashSet or not.<br />
* `void remove(key)` Removes the value `key` in the HashSet. If `key` does not exist in the HashSet, do nothing.<br />

>Example 1: <br /> 
>Input: <br /> 
>["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"] <br /> 
>[[], [1], [2], [1], [3], [2], [2], [2], [2]] <br /> 
>Output: <br /> 
>[null, null, null, true, false, null, true, null, false] <br /> 
>Explanation <br /> 
>MyHashSet myHashSet = new MyHashSet(); <br /> 
>myHashSet.add(1);      // set = [1] <br /> 
>myHashSet.add(2);      // set = [1, 2] <br /> 
>myHashSet.contains(1); // return True <br /> 
>myHashSet.contains(3); // return False, (not found) <br /> 
>myHashSet.add(2);      // set = [1, 2] <br /> 
>myHashSet.contains(2); // return True <br /> 
>myHashSet.remove(2);   // set = [1] <br /> 
>myHashSet.contains(2); // return False, (already removed) <br /> 

* Constraints:<br />`0 <= key <= 10^6`.<br /> 
At most `10^4` calls will be made to `add`, `remove`, and `contains`.<br /> 

```cpp
class MyHashSet {
public:
    vector<bool>sol;
    MyHashSet() {
        sol.resize(1e6+1, false);
    }
    
    void add(int key) {
        sol[key] = true;
    }
    
    void remove(int key) {
        sol[key] = false;
    }
    
    bool contains(int key) {
        return sol[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```

	
	
	
<br /> <br /> <br />**[706. Design HashMap](https://leetcode.com/problems/design-hashmap/)**<br />
Design a HashMap without using any built-in hash table libraries.<br />
Implement the `MyHashMap` class:<br />
	
* `MyHashMap()` initializes the object with an empty map.
* `void put(int key, int value)` inserts a `(key, value)` pair into the HashMap. If the `key` already exists in the map, update the corresponding `value`.
* `int get(int key)` returns the `value` to which the specified `key` is mapped, or `-1` if this map contains no mapping for the `key`.
* `void remove(key)` removes the `key` and its corresponding `value` if the map contains the mapping for the `key`.

>Example 1: <br /> 
>Input:<br /> 
>["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]<br /> 
>[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]<br /> 
>Output:<br /> 
>[null, null, null, 1, -1, null, 1, null, -1]<br /> 
>Explanation:<br /> 
>MyHashMap myHashMap = new MyHashMap();<br /> 
>myHashMap.put(1, 1); // The map is now [[1,1]]<br /> 
>myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]<br /> 
>myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]<br /> 
>myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]<br /> 
>myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)<br /> 
>myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]<br /> 
>myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]<br /> 
>myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]<br /> 
	
* Constraints:<br />`0 <= key, value <= 10^6`.<br /> 
At most `10^4` calls will be made to `put`, `get`, and `remove`.<br /> 
	
```cpp
static int fastIO = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

class linkedList{
    private: 
        class node{
            public:
                int key, value; 
                node* next; 
                node(int k=0, int v=0, node* nextptr=NULL) : key(k), value(v), next(nextptr){}}; 
        node* head; 
        node* tail; 
        void deleteHead(){
            if((head == tail) && (head == NULL)) return; 
            node* delNode = head;
            if((head == tail) && (head != NULL))head = tail = NULL;   
            else head = head->next;
            delete delNode; 
        } 

        void deleteTail(){
            if((head == tail) && (tail == NULL))return; 
            node* delNode = tail; 
            if((head == tail) && (tail != NULL))head = tail = NULL;
            else{
                node* curr = head; 
                while(curr->next != delNode)curr = curr->next;
                tail = curr; 
                tail->next = NULL;
            }
            delete delNode; 
        }

        node* getNode(int key){
            node* curr = head; 
            while(curr){
                if(curr->key == key) return curr; 
                curr = curr->next; 
            }
            return NULL; 
        }

    public: 
        linkedList(){
            head = NULL; 
            tail = NULL; 
        }

        int getKeyValue(int key){
            node* addr = getNode(key); 
            return ( addr != NULL ? addr->value : -1); 
        }

        void addNode(int key, int value){
            node* addr = getNode(key); 
            if(addr != NULL){
                addr->value = value; 
                return; 
            }

            node* newNode = new node(key, value);
            if((head == tail) && (tail == NULL)){ 
                head = tail = newNode;            
                return; 
            }

            tail->next = newNode; 
            tail = newNode; 
        }
    
        void deleteNode(int key){
            if((head == tail) && (head == NULL))return; 
            node* prevNode = head; 
            if(prevNode->key == key){
                deleteHead(); 
                return; 
            }

            bool found = false; 
            while(prevNode->next){
                if((prevNode->next)->key == key){
                    found = true; 
                    break; 
                }
                prevNode = prevNode->next;
            }

            if(!found) return;
            if(prevNode->next == tail)
                deleteTail(); 
            else{
                node* delNode = prevNode->next; 
                prevNode->next = delNode->next; 
                delNode->next = NULL; 
                delete delNode;
            }
        }        
};


class MyHashMap : protected linkedList{
    private: 
        linkedList* buckets;
    public: 
        int tsize;
        MyHashMap(int _tsize = 499){
            tsize = _tsize; 
            buckets = new linkedList[tsize];
        }

        void put(int key, int value){
            buckets[(key % tsize)].addNode(key, value); 
        }

        int get(int key){ 
            return buckets[(key % tsize)].getKeyValue(key); 
        }

        void remove(int key){
            buckets[(key % tsize)].deleteNode(key); 
        }
}; 

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
```
	
	


 
 
 
 <br /> <br /> <br />**[1961. Check If String Is a Prefix of Array](https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/)**<br />
Given a string `s` and an array of strings `words`, determine whether `s` is a **prefix string** of `words`.<br />
A string `s` is a **prefix string** of `words` if `s` can be made by concatenating the first `k` strings in `words` for some **positive** `k` no larger than `words.length`.<br />
Return `true` if `s` is a **prefix string** of `words`, or `false` otherwise.<br />
	
>Example 1:<br />
>Input: s = "iloveleetcode", words = ["i","love","leetcode","apples"]<br />
>Output: true<br />
>Explanation:<br />
>s can be made by concatenating "i", "love", and "leetcode" together.<br />
	
>Example 2:<br />
>Input: s = "iloveleetcode", words = ["apples","i","love","leetcode"]<br />
>Output: false<br />
>Explanation:<br />
>It is impossible to make s using a prefix of arr.<br />
	
* Constraints:`1 <= words.length <= 100`<br />
`1 <= words[i].length <= 20`<br />
`1 <= s.length <= 1000`<br />
`words[i]` and `s` consist of only lowercase English letters.<br />
	
```cpp
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int is = 0;
        for (int i = 0; i < words.size(); i++){
            for (int j = 0; j < words[i].length(); j++){
                if (s[is] != words[i][j])return false;  
                is++;
                if (is == s.length())return j == words[i].length() - 1;
            }
        }
        return false;
    }
};
```
	
	
	
<br /> <br /> <br />**[228. Summary Ranges](https://leetcode.com/problems/summary-ranges/)**<br />
You are given a **sorted unique** integer array `nums`.
A **range** `[a,b]` is the set of all integers from `a` to `b` (inclusive).<br />
Return the **smallest sorted** list of ranges that **cover all the numbers in the array exactly**. That is, each element of `nums` is covered by exactly one of the ranges, and there is no integer `x` such that `x` is in one of the ranges but not in `nums`.<br />
Each range `[a,b]` in the list should be output as:<br />
* `"a->b"` if `a != b`<br />
* `"a"` if `a == b`<br />
 
>Example 1:<br />
>Input: nums = [0,1,2,4,5,7]<br />
>Output: ["0->2","4->5","7"]<br />
>Explanation: The ranges are:<br />
>[0,2] --> "0->2"<br />
>[4,5] --> "4->5"<br />
>[7,7] --> "7"<br />
	
>Example 2:<br />
>Input: nums = [0,2,3,4,6,8,9]<br />
>Output: ["0","2->4","6","8->9"]<br />
>Explanation: The ranges are:<br />
>[0,0] --> "0"<br />
>[2,4] --> "2->4"<br />
>[6,6] --> "6"<br />
>[8,9] --> "8->9"<br />
 
* Constraints:`0 <= nums.length <= 20`<br />
`-2^31 <= nums[i] <= 2^31 - 1`.<br />
All the values of `nums` are **unique**.<br />
`nums` is sorted in ascending order.<br />
	
```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {
        int n = arr.size(); 
        vector<string> ans; 
        string temp = ""; 
        for(int i = 0; i < n; i++){
            int j = i;        
            while(j + 1 < n && arr[j + 1] == arr[j] + 1)j++;
            if(j > i){
                temp += to_string(arr[i]); 
                temp += "->"; 
                temp += to_string(arr[j]);
            }
            else temp += to_string(arr[i]); 
            ans.push_back(temp); 
            temp = ""; 
            i = j; 
        }
        return ans; 
    }
};
```
	


<br /> <br /> <br />**[844. Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/)**<br />
Given two strings `s` and `t`, return `true` _if they are equal when both are typed into empty text editors_. `'#'` means a backspace character.<br />
Note that after backspacing an empty text, the text will continue empty.<br />

>Example 1:<br />
>Input: s = "ab#c", t = "ad#c"<br />
>Output: true<br />
>Explanation: Both s and t become "ac".<br />
	
>Example 2:<br />
>Input: s = "ab##", t = "c#d#"<br />
>Output: true<br />
>Explanation: Both s and t become "".<br />
	
>Example 3:<br />
>Input: s = "a#c", t = "b"<br />
>Output: false<br />
>Explanation: s becomes "c" while t becomes "b".<br />

* Constraints:`1 <= s.length, t.length <= 200`<br />
`s` and `t` only contain lowercase letters and `'#'` characters.<br />
	
```cpp
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sFinal = processString(s);
        string tFinal = processString(t);
        return sFinal == tFinal;
    }
    string processString(string s) {
        stack<char> stk;
        for(char c : s) {
            if(c == '#') {
                if(!stk.empty())stk.pop();
            } else stk.push(c);
        }
        string processed = "";
        while(!stk.empty()) {
            processed += stk.top();
            stk.pop();
        }
        return processed;
    }
};
```
	
	
	
	
<br /> <br /> <br />**[905. Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/)**<br />
Given an integer array `nums`, move all the even integers at the beginning of the array followed by all the odd integers.<br />
Return **any array** that satisfies this condition.<br />

>Example 1:<br />
>Input: nums = [3,1,2,4]<br />
>Output: [2,4,3,1]<br />
>Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.<br />
	
>Example 2:<br />
>Input: nums = [0]<br />
>Output: [0]<br />

* Constraints:`1 <= nums.length <= 5000`<br />
`0 <= nums[i] <= 5000`<br />
	
```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int s = 0, n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)swap(nums[s++],nums[i]);  
        }
        return nums;
    }
};
```
			      
			      
			      

                              
                              
<br /> <br /> <br />**[225. Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)**<br />
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).<br />
Implement the `MyStack` class:<br />
* `void push(int x)` Pushes element x to the top of the stack.<br />
* `int pop()` Removes the element on the top of the stack and returns it.<br />
* `int top()` Returns the element on the top of the stack.<br />
* `boolean empty()` Returns `true` if the stack is empty, `false` otherwise.<br />
Notes:<br />
* You must use **only** standard operations of a queue, which means that only `push to back`, `peek/pop from front`, `size` and `is empty` operations are valid.<br />
* Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.<br />
 
>Example 1:<br />
>Input:<br />
>["MyStack", "push", "push", "top", "pop", "empty"]<br />
>[[], [1], [2], [], [], []]<br />
>Output:<br />
>[null, null, null, 2, 2, false]<br />
>Explanation<br />
>MyStack myStack = new MyStack();<br />
>myStack.push(1);<br />
>myStack.push(2);<br />
>myStack.top(); // return 2<br />
>myStack.pop(); // return 2<br />
>myStack.empty(); // return False<br />
 
* Constraints:`1 <= x <= 9`<br />
At most `100` calls will be made to `push`, `pop`, `top`, and `empty`.<br />
All the calls to `pop` and `top` are valid.<br />
	
```cpp
class MyStack {
private:
    queue<int> data;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        for (int i = 0; i < data.size() - 1; ++i) {
            data.push(pop());
        }
    }
    
    int pop() {
        int result = top();
        data.pop();
        return result;
    }
    
    int top() {
        return data.front();
    }
    
    bool empty() {
        return data.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```
	

	

 <br /> <br /> <br />**[1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/)**<br />
Given two binary trees `original` and `cloned` and given a reference to a node `target` in the original tree.<br />
The `cloned` tree is a **copy of** the `original` tree.<br />
_Return a reference to the same node_ in the `cloned` tree.<br />
**Note** that you are **not allowed** to change any of the two trees or the `target` node and the answer **must be** a reference to a node in the `cloned` tree. <br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/02/21/e1.png"><br />
Input: tree = [7,4,3,null,null,6,19], target = 3<br />
Output: 3<br />
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.<br />
	
>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2020/02/21/e2.png"><br />
Input: tree = [7], target =  7<br />
Output: 7<br />
	
>Example 3:<br />
<img src = "https://assets.leetcode.com/uploads/2020/02/21/e3.png"><br />
Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4<br />
Output: 4<br />

* Constraints: The number of nodes in the tree is in the range `[1, 10^4]`.<br />
The values of the nodes of the `tree` are unique.<br />
`target` node is a node from the `original` tree and is not `null`.<br />

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* og, TreeNode* copy, TreeNode* target, TreeNode*& ans) {
        if(!og) return;
        if(og == target)ans = copy;
        dfs(og->left, copy->left, target, ans);
        dfs(og->right, copy->right, target, ans);
        return;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = nullptr;
        dfs(original, cloned, target, ans);
        return ans;
    }
};
```
	
	
	

<br /> <br /> <br />**[1342. Number of Steps to Reduce a Number to Zero](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/)**<br />
Given an integer `num`, return _the number of steps to reduce it to zero_.<br />
In one step, if the current number is even, you have to divide it by `2`, otherwise, you have to subtract `1` from it.<br />

>Example 1:<br />
Input: num = 14<br />
Output: 6<br />
Explanation: <br />
Step 1) 14 is even; divide by 2 and obtain 7. <br />
Step 2) 7 is odd; subtract 1 and obtain 6.<br />
Step 3) 6 is even; divide by 2 and obtain 3. <br />
Step 4) 3 is odd; subtract 1 and obtain 2. <br />
Step 5) 2 is even; divide by 2 and obtain 1. <br />
Step 6) 1 is odd; subtract 1 and obtain 0.<br />
	
>Example 2:<br />
Input: num = 8<br />
Output: 4<br />
Explanation: <br />
Step 1) 8 is even; divide by 2 and obtain 4. <br />
Step 2) 4 is even; divide by 2 and obtain 2. <br />
Step 3) 2 is even; divide by 2 and obtain 1. <br />
Step 4) 1 is odd; subtract 1 and obtain 0.<br />
	
>Example 3:<br />
Input: num = 123<br />
Output: 12<br />

* Constraints: `0 <= num <= 10^6`<br />

```cpp
class Solution {
public:
    int numberOfSteps(int num) {
        int step = 0;
        while(num!=0){
            if(num%2==0){
                num /= 2;
                step++;
            }
            else {
                num -= 1;
                step++;
            }
        }
        return step;
    }
};

/*
class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0) return 0;
        int ans = log2(num);
        while(num > 0)
        {
            ans++;
            num &= num-1;
        }
        return ans;
    }
};
*/
	
/*
int numberOfSteps(int num) {
        if(num == 0) return 0 ;
		int bit_length = sizeof(num) * 8 - __builtin_clz(num); // 6 = 0...0110 => only [110].length = 3;
		int number_of_1s = __builtin_popcount(num); // 1s in [110] = #[1] = 2
		int operations_to_remove_0s =  bit_length -  number_of_1s; // 0s in [110] = #[0] = [110].length - #[1]
		int operations_to_remove_1s =  2 * (number_of_1s) - 1; // all 1s will take 2 operation except the last one because for last 1, 0...01 - 1 = 0 it will take only one Operation 
		return operations_to_remove_0s + operations_to_remove_1s;
    }	
*/
```

	
	

<br /> <br /> <br />**[268. Missing Number](https://leetcode.com/problems/missing-number/)**<br />
Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return _the only number in the range that is missing from the array_.<br />
	
>Example 1:<br />
Input: nums = [3,0,1]<br />
Output: 2<br />
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.<br />
	
>Example 2:<br />
Input: nums = [0,1]<br />
Output: 2<br />
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.<br />
	
>Example 3:<br />
Input: nums = [9,6,4,2,3,5,7,0,1]<br />
Output: 8<br />
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.<br />
 
* Constraints: `n == nums.length`<br />
`1 <= n <= 10^4`<br />
`0 <= nums[i] <= n`<br />
All the numbers of `nums` are **unique**.<br />

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, total = (n*(n+1))/2;
        for(int i = 0;i<n;i++)sum+=nums[i];
        return (total-sum);
    }
};
```

				   
				   
				   

 <br /> <br /> <br />**[1480. Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)**<br />
Given an array `nums`. We define a running sum of an array as `runningSum[i] = sum(nums[0]…nums[i])`.<br />
Return the running sum of `nums`.<br />

>Example 1:<br />
Input: nums = [1,2,3,4]<br />
Output: [1,3,6,10]<br />
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].<br />

>Example 2:<br />
Input: nums = [1,1,1,1,1]<br />
Output: [1,2,3,4,5]<br />
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].<br />

>Example 3:<br />
Input: nums = [3,1,2,10,1]<br />
Output: [3,4,6,16,17]<br />
 
* Constraints: `1 <= nums.length <= 1000`<br />
`-10^6 <= nums[i] <= 10^6`<br />
	
```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>run_sum;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            run_sum.push_back(sum);
        }
        return run_sum;
    }
};
```
					  
					  
					  
					  
<br /> <br /> <br />**[867. Transpose Matrix](https://leetcode.com/problems/transpose-matrix/)**<br />					  
Given a 2D integer array `matrix`, return _the **transpose** of_ `matrix`.<br />
The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.<br />
<img src = "https://assets.leetcode.com/uploads/2021/02/10/hint_transpose.png"><br />

>Example 1:<br />
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]<br />
Output: [[1,4,7],[2,5,8],[3,6,9]]<br />

>Example 2:<br />
Input: matrix = [[1,2,3],[4,5,6]]<br />
Output: [[1,4],[2,5],[3,6]]<br />
 
* Constraints: `m == matrix.length`<br />
`n == matrix[i].length`<br />
`1 <= m, n <= 1000`<br />
`1 <= m * n <= 10^5`<br />
`-10^9 <= matrix[i][j] <= 10^9`<br />

```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> res(m,vector<int> (n,0)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[j][i] = matrix[i][j]; 
            }
        }
        return res;
    }
};
```
	
	
	
	
	
<br /> <br /> <br />**[160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)**<br />
Given the heads of two singly linked-lists `headA` and `headB`, return _the node at which the two lists intersect_. If the two linked lists have no intersection at all, return `null`.<br />

For example, the following two linked lists begin to intersect at node c1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/03/05/160_statement.png"><br />
	
The test cases are generated such that there are no cycles anywhere in the entire linked structure.<br />

**Note** that the linked lists must **retain their original structure** after the function returns.<br />

**Custom Judge:**<br />

The inputs to the **judge** are given as follows (your program is **not** given these inputs):<br />

* `intersectVal` - The value of the node where the intersection occurs. This is `0` if there is no intersected node.<br />
* `listA` - The first linked list.<br />
* `listB` - The second linked list.<br />
* `skipA` - The number of nodes to skip ahead in `listA` (starting from the head) to get to the intersected node.<br />
* `skipB` - The number of nodes to skip ahead in `listB` (starting from the head) to get to the intersected node.<br />
	
The judge will then create the linked structure based on these inputs and pass the two heads, `headA` and `headB` to your program. If you correctly return the intersected node, then your solution will be **accepted**.<br />

 

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/03/05/160_example_1_1.png"><br />
<pre>
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
</pre>
	
>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2021/03/05/160_example_2.png"><br />
<pre>
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
</pre>

>Example 3:<br />
<img src = "https://assets.leetcode.com/uploads/2021/03/05/160_example_3.png"><br />
<pre>
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
</pre>
 

* Constraints: The number of nodes of `listA` is in the `m`.<br />
The number of nodes of `listB` is in the `n`.<br />
`1 <= m, n <= 3 * 10^4`<br />
`1 <= Node.val <= 10^5`<br />
`0 <= skipA < m`<br />
`0 <= skipB < n`<br />
`intersectVal` is `0` if `listA` and `listB` do not intersect.<br />
`intersectVal == listA[skipA] == listB[skipB]` if `listA` and `listB` intersect.<br />
	
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1=headA;
        ListNode* t2=headB;
        int l1=1;
        int l2=1;
        while (t1->next){
            l1+=1;
            t1=t1->next;
        }
        while (t2->next){
            l2+=1;
            t2=t2->next;
        }
        if (t1!=t2){
            return NULL;
        }
        int move1 = max(0,l1-l2);
        int move2 = max(0,l2-l1);
        while (move1>0){
            headA=headA->next;
            move1--;
        }
        while (move2>0){
            headB=headB->next;
            move2--;
        }
        while (headA!=headB){
            headB=headB->next;
            headA=headA->next;
        }
        return headA;
    }
};
```
	

	
	
	
<br /> <br /> <br />**[1332. Remove Palindromic Subsequences](https://leetcode.com/problems/remove-palindromic-subsequences/)**<br />
You are given a string `s` consisting **only** of letters `'a'` and `'b'`. In a single step you can remove one **palindromic subsequence** from `s`.<br />
Return the _**minimum** number of steps to make the given string empty_.<br />
A string is a **subsequence** of a given string if it is generated by deleting some characters of a given string without changing its order. Note that a subsequence does **not** necessarily need to be contiguous.<br />
A string is called **palindrome** if is one that reads the same backward as well as forward.<br />
	
>Example 1:<br />
Input: s = "ababa"<br />
Output: 1<br />
Explanation: s is already a palindrome, so its entirety can be removed in a single step.<br />

>Example 2:<br />
Input: s = "abb"<br />
Output: 2<br />
Explanation: "abb" -> "bb" -> "".<br /> 
Remove palindromic subsequence "a" then "bb".<br />

>Example 3:<br />
Input: s = "baabb"<br />
Output: 2<br />
Explanation: "baabb" -> "b" -> "".<br /> 
Remove palindromic subsequence "baab" then "b".<br />
 
* Constraints: `1 <= s.length <= 1000`<br />
`s[i]` is either `'a'` or `'b'`.<br />

```cpp
class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0, len = s.size()-1;
        while(i<len) {
            if(s[i]!=s[len]) return 2;
            i++;
            len--;
        }
        return 1;
    }
};
```
		     
		     
		     
		     
		     
		 
<br /> <br /> <br />**[1710. Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/)**<br />
You are assigned to put some amount of boxes onto **one truck**. You are given a 2D array `boxTypes`, where `boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:`<br />

 * `numberOfBoxesi` is the number of boxes of type `i`.<br />
 * `numberOfUnitsPerBoxi` is the number of units in each box of the type `i`.<br />
	
You are also given an integer `truckSize`, which is the **maximum** number of **boxes** that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed `truckSize`.<br />
Return the **maximum** total number of **units** that can be put on the truck.<br />

>Example 1:<br />
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4<br />
Output: 8<br />
Explanation: There are:<br />
- 1 box of the first type that contains 3 units.<br />
- 2 boxes of the second type that contain 2 units each.<br />
- 3 boxes of the third type that contain 1 unit each.<br />
You can take all the boxes of the first and second types, and one box of the third type.<br />
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.<br />

>Example 2:<br />
Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10<br />
Output: 91<br />
 
* Constraints: `1 <= boxTypes.length <= 1000`<br />
`1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000`<br />
`1 <= truckSize <= 10^6`<br />
	
```cpp
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
        int res = 0, sizeBucket[1001] = {}, maxBucket = INT_MIN, minBucket = INT_MAX;
        for (auto &boxType: boxes) {
            maxBucket = max(maxBucket, boxType[1]);
            minBucket = min(minBucket, boxType[1]);
            sizeBucket[boxType[1]] += boxType[0];
        }
        for (int i = maxBucket, size, currBatch; i >= minBucket; i--) {
            size = sizeBucket[i];
            if (!size) continue;
            currBatch = min(size, truckSize);
            truckSize -= currBatch;
            res += currBatch * i;
            if (!truckSize) break;
        }
        return res;
    }
};
```

	
	
	

<br /> <br /> <br />**[997. Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/)**<br />
In a town, there are `n` people labeled from `1` to `n`. There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:<br />
	
 1. The town judge trusts nobody.<br />
 2. Everybody (except for the town judge) trusts the town judge.<br />
 3. There is exactly one person that satisfies properties `1` and `2`.<br />
	
You are given an array `trust` where `trust[i] = [ai, bi]` representing that the person labeled `ai` trusts the person labeled `bi`.<br />
Return _the label of the town judge if the town judge exists and can be identified, or return_ `-1` _otherwise_.<br />

>Example 1:<br />
Input: n = 2, trust = [[1,2]]<br />
Output: 2<br />

>Example 2:<br />
Input: n = 3, trust = [[1,3],[2,3]]<br />
Output: 3<br />

>Example 3:<br />
Input: n = 3, trust = [[1,3],[2,3],[3,1]]<br />
Output: -1<br />
 
* Constraints: `1 <= n <= 1000`<br />
`0 <= trust.length <= 10^4`<br />
`trust[i].length == 2`<br />
All the pairs of `trust` are **unique**.<br />
`ai != bi`<br />
`1 <= ai, bi <= n`<br />
	
```cpp
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> a(n+1,0), b(n+1, 0); // a -> b
        for (auto p : trust)a[p[0]]++, b[p[1]]++;
        if (count(a.begin() + 1, a.end(), 0) != 1)return -1;
        if (count(b.begin() + 1, b.end(), n - 1) != 1)return -1;
        return find(a.begin() + 1, a.end(), 0) - a.begin();  
    }
};
```
	
	
	
	
	
	
<br /> <br /> <br />**[67. Add Binary](https://leetcode.com/problems/add-binary/)**<br />
Given two binary strings `a` and `b`, return _their sum as a binary string_.<br />

>Example 1:<br />
Input: a = "11", b = "1"<br />
Output: "100"<br />

>Example 2:<br />
Input: a = "1010", b = "1011"<br />
Output: "10101"<br />
 
* Constraints: `1 <= a.length, b.length <= 10^4`<br />
`a` and `b` consist only of `'0'` or `'1'` characters.<br />
Each string does not contain leading zeros except for the zero itself.<br />
	
```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size()-1 ; int j = b.size()-1;
        int sum , carry = 0;
        while(i>=0 || j>=0){
            sum = carry;
            if(i>= 0) sum += a[i--] - '0';
            if(j>= 0) sum += b[j--] - '0';
            result += to_string(sum % 2);
            carry = sum /2;
        }
        if(carry != 0) result +='1';
        reverse(result.begin(),result.end());
        return result;
    }
};
```
	
	
	
	
	
	
	

	
	
	
	
	
<br /> <br /> <br />**[746. Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)**<br />
You are given an integer array `cost` where `cost[i]` is the cost of `ith` step on a staircase. Once you pay the cost, you can either climb one or two steps.<br />
You can either start from the step with index `0`, or the step with index `1`.<br />
Return _the minimum cost to reach the top of the floor_.<br />

>Example 1:<br />
Input: cost = [10,15,20]<br />
Output: 15<br />
Explanation: You will start at index 1.<br />
- Pay 15 and climb two steps to reach the top.<br />
The total cost is 15.<br />

>Example 2:<br />
Input: cost = [1,100,1,1,1,100,1,1,100,1]<br />
Output: 6<br />
Explanation: You will start at index 0.<br />
- Pay 1 and climb two steps to reach index 2.<br />
- Pay 1 and climb two steps to reach index 4.<br />
- Pay 1 and climb two steps to reach index 6.<br />
- Pay 1 and climb one step to reach index 7.<br />
- Pay 1 and climb two steps to reach index 9.<br />
- Pay 1 and climb one step to reach the top.<br />
The total cost is 6.<br />
 
* Constraints: `2 <= cost.length <= 1000`<br />
`0 <= cost[i] <= 999`<br />
	
```cpp

//Recursive solutions
//it give tle
class Solution {
public:
int f(vector<int> a, int i){
        if(i<=1)    return a[i];
        int pick =  f(a, i-1);
        int nonpick = f(a, i-2);
        return  a[i] + min(pick, nonpick);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(f(cost, n-1), f(cost, n-2));
    }
};

//Memoization
class Solution {
public:
int f(vector<int> a, int i, vector<int>&dp){
        if(i<=1)    return dp[i] = a[i];
        if(dp[i]!=-1)   return dp[i];
        int pick =  f(a, i-1, dp);
        int nonpick = f(a, i-2, dp);
        return dp[i] = a[i] + min(pick, nonpick);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(f(cost, n-1, dp), f(cost, n-2, dp));
    }
};

//Tabulation
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1); 
        for (int i = 2; i <= n; i++) {
            int jumpOneStep = dp[i - 1] + cost[i - 1];  
            int jumpTwoStep = dp[i - 2] + cost[i - 2];  
            dp[i] = min(jumpOneStep, jumpTwoStep);
        }
        return dp[n];
    }
};

//Space-Optimization
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev = 0, sec_prev = 0; 
        for (int i = 2; i <= n; i++) {
            int jumpOneStep = prev + cost[i - 1];  
            int jumpTwoStep = sec_prev + cost[i - 2]; 
            sec_prev = prev;
            prev = min(jumpOneStep, jumpTwoStep);
            
        }
       return prev;
    }
};
```
			      
			      
			  
			      
			      
			     
<br /> <br /> <br />**[13. Roman to Integer](https://leetcode.com/problems/roman-to-integer/)**<br />
Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.<br />
<pre>
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
</pre>
For example, `2` is written as `II` in Roman numeral, just two ones added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.<br />
Roman numerals are usually written `largest to smallest from left to right`. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`.<br />
Because the one is before the five we subtract it making `four`. The same principle applies to the number `nine`, which is written as `IX`. **There are six instances where subtraction is used**:<br />

 * `I` can be placed before `V (5)` and `X (10)` to make `4` and `9`.<br /> 
 * `X` can be placed before `L (50)` and `C (100)` to make `40` and `90`.<br /> 
 * `C` can be placed before `D (500)` and `M (1000)` to make `400` and `900`.<br />
	
Given a roman numeral, convert it to an integer.<br /> 

>Example 1:<br />
Input: s = "III"<br />
Output: 3<br />
Explanation: III = 3.<br />

>Example 2:<br />
Input: s = "LVIII"<br />
Output: 58<br />
Explanation: L = 50, V= 5, III = 3.<br />
	
>Example 3:<br />
Input: s = "MCMXCIV"<br />
Output: 1994<br />
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.<br />

* Constraints: `1 <= s.length <= 15`<br />
`s` contains only the characters `('I', 'V', 'X', 'L', 'C', 'D', 'M')`.<br />
It is **guaranteed** that `s` is a valid roman numeral in the range `[1, 3999]`.<br />
	
```cpp
class Solution {
public:
    int romanToInt(string S) {
        int ans = 0, num = 0;
        for (int i = S.size()-1; ~i; i--) {
            switch(S[i]) {
                case 'I': num = 1; break;
                case 'V': num = 5; break;
                case 'X': num = 10; break;
                case 'L': num = 50; break;
                case 'C': num = 100; break;
                case 'D': num = 500; break;
                case 'M': num = 1000; break;
            }
            if (4 * num < ans) ans -= num;
            else ans += num;
        }
        return ans;        
    }
};
```
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[804. Unique Morse Code Words](https://leetcode.com/problems/unique-morse-code-words/)**<br />
International `Morse Code` defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:<br />

 * `'a'` maps to `".-"`,<br />
 * `'b'` maps to `"-..."`,<br />
 * `'c'` maps to `"-.-."`, and so on.<br />
	
For convenience, the full table for the `26` letters of the English alphabet is given below:<br />

[`".-"`,`"-..."`,`"-.-."`,`"-.."`,`"."`,`"..-."`,`"--."`,`"...."`,`".."`,`".---"`,`"-.-"`,`".-.."`,`"--"`,`"-."`,`"---"`,`".--."`,`"--.-"`,`".-."`,`"..."`,`"-"`,`"..-"`,`"...-"`,`".--"`,`"-..-"`,`"-.--"`,`"--.."`]<br />
	
Given an array of strings `words` where each word can be written as a concatenation of the **Morse code** of each letter.<br />

 * For example, `"cab"` can be written as `"-.-..--..."`, which is the concatenation of `"-.-."`, `".-"`, and `"-..."`. We will call such a concatenation the **transformation** of a word.<br />
	
Return _the number of different **transformations** among all words we have_.<br />

>Example 1:<br />
Input: words = ["gin","zen","gig","msg"]<br />
Output: 2<br />
Explanation: The transformation of each word is:<br />
"gin" -> "--...-."<br />
"zen" -> "--...-."<br />
"gig" -> "--...--."<br />
"msg" -> "--...--."<br />
There are 2 different transformations: "--...-." and "--...--.".<br />
	
>Example 2:<br />
Input: words = ["a"]<br />
Output: 1<br />

* Constraints: `1 <= words.length <= 100`<br />
`1 <= words[i].length <= 12`<br />
`words[i]` consists of lowercase English letters.<br />
	
```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> t = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;

        for(int i = 0; i < words.size();i++){
            string tt = words[i]; 
            string temp = "";

            for(int j= 0 ;j < tt.length(); j++){
                int e = tt[j] - 'a';
                temp += t[e];
            }
            s.insert(temp);
        }
        return s.size();
    }
};
```
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[342. Power of Four](https://leetcode.com/problems/power-of-four/)**<br />
Given an integer `n`, return `true` if it is a _power of four_. Otherwise, return `false`.<br />
An integer `n` is a power of four, if there exists an integer `x` such that `n == 4^x`.<br />
	
Example 1:
<pre>
Input: n = 16
Output: true
</pre>
Example 2:
<pre>
Input: n = 5
Output: false
</pre>
Example 3:
<pre>
Input: n = 1
Output: true
</pre>

* Constraints: `-2^31 <= n <= 2^31 - 1`<br />
	
```cpp
class Solution {
    public:
        bool isPowerOfFour(int n) { 
       if(n<=0) return false;
       if(n==1) return true;
       if(n%4!=0){
            return false;
        }
        return isPowerOfFour(n/4);
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n&(n-1))==0 && (n&0x55555555);
		// n>0, n should be positive
		// n&(n-1) ensure it is power of 2
		// 5 is "0101" so n&0x55555... ensure that set bit is at the even position.
		// soo if n is power of 2 and set bit is at even position -> n is power of 4
    }
};
```
	
	
<br /> <br /> <br />**[326. Power of Three](https://leetcode.com/problems/power-of-three/)**<br />
Given an integer `n`, return `true` _if it is a power of three. Otherwise, return_ `false`.<br />
An integer `n` is a power of three, if there exists an integer `x` such that `n == 3^x`.<br />
	
Example 1:
<pre>
Input: n = 27
Output: true
Explanation: 27 = 33
</pre>
Example 2:
<pre>
Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.
</pre>
Example 3:
<pre>
Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).
</pre>

* Constraints: `-2^31 <= n <= 2^31 - 1`<br />
	
```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
       if(n==1) return true;
       if(n%3!=0){
            return false;
        }
        return isPowerOfThree(n/3);
    }
};
```

		
		
		
<br /> <br /> <br />**[383. Ransom Note](https://leetcode.com/problems/ransom-note/)**<br />
Given two strings `ransomNote` and `magazine`, return _`true` if `ransomNote` can be constructed by using the letters from `magazine` and `false` otherwise_.<br />
Each letter in `magazine` can only be used once in `ransomNote`.<br />
	
Example 1:
<pre>
Input: ransomNote = "a", magazine = "b"
Output: false
</pre>
Example 2:
<pre>
Input: ransomNote = "aa", magazine = "ab"
Output: false
</pre>
Example 3:
<pre>
Input: ransomNote = "aa", magazine = "aab"
Output: true
</pre>

* Constraints: `1 <= ransomNote.length, magazine.length <= 10^5`<br />
`ransomNote` and `magazine` consist of lowercase English letters.<br />
	
```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(char c : magazine)m[c]++;
        for(char c : ransomNote) {
            if(m[c] == 0) return false;
            m[c]--;
        }
        return true;
    }
};
```
	
<br /> <br /> <br />**[219. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)**<br />
Given an integer array `nums` and an integer `k`, return `true` if there are **two distinct** indices `i` and `j` in the array such that `nums[i] == nums[j]` and `abs(i - j) <= k`.<br /><br />	
Example 1:
<pre>
Input: nums = [1,2,3,1], k = 3
Output: true
</pre>
Example 2:
<pre>
Input: nums = [1,0,1,1], k = 1
Output: true
</pre>
Example 3:
<pre>
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
</pre>

* Constraints: `1 <= nums.length <= 10^5`<br />
`-10^9 <= nums[i] <= 10^9`<br />
`0 <= k <= 10^5`<br />
	
```cpp
//psuedocode
if(not present){
    insert the key value pairs.
}
else{
    Check the difference between 
    the new index value and the initial index stored.
    if
        difference <= k return true
    else 
        update the index of current element.

}

/*
Time complexity:
Since the array is traversed completely,
Time Complexity = O(n);

Space complexity:
An extra space of map is used hence,
Space Complexity = O(n).
*/   

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        int len = nums.size();
        for(int i = 0;i<len; i++){
            if(m.find(nums[i]) == m.end()) m[nums[i]] = i;
            else{
                int diff = (abs(i - m[nums[i]]));
                if(diff <=k)
                    return true;
                else
                    m[nums[i]] = i;
            }
        }
        return false;
    }
};

//Time and Space Complexity => O(n), where n is the size of nums
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            // mp.count() will tell whatever ith index that I want, have I seen it before?
            if(mp.count(nums[i]))
            {
                // if I have already seen this number, then check for condition abs(i - j) <= k
                if(abs(i-mp[nums[i]])<=k)
                    return true;
            }
            // if I have not seen this number before, insert the number with its position in the map
            // and if the number is already present in the map, then update the position of that number
            mp[nums[i]] = i;
        }
        // after the complete traversal, if we dont find a pair to satisfy the condition, return false
        return false;
    }
};
```	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[645. Set Mismatch](https://leetcode.com/problems/set-mismatch/)**<br />
You have a set of integers `s`, which originally contains all the numbers from `1` to `n`. Unfortunately, due to some error, one of the numbers in `s` got duplicated to another number in the set, which results in **repetition of one** number and **loss of another** number.<br />
You are given an integer array `nums` representing the data status of this set after the error.<br />
Find the number that occurs twice and the number that is missing and return _them in the form of an array_.<br />

Example 1:
<pre>
Input: nums = [1,2,2,4]
Output: [2,3]
</pre>
Example 2:
<pre>
Input: nums = [1,1]
Output: [1,2]
</pre>

* Constraints: `2 <= nums.length <= 10^4`<br />
`1 <= nums[i] <= 10^4`<br />
	
```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    //sum of elements on nums
    int initialSum = accumulate(nums.begin(), nums.end(), 0);

    //put the element of nums into set to remove the duplicate number
    set<int> s;
    for(auto &i: nums){
        s.insert(i);
    }

    //sum of elements of the set
    int sum = accumulate(s.begin(), s.end(), 0);

    //difference of initialSum and sum will give us the repeated number
    int repeatedNum = initialSum - sum;

    //subtracting the sum of elements in set i.e. sum from the sum of the natural numbers will give us the missing number
	int n = nums.size();
    int missingNum = n * (n+1)/2 - sum;

    return {repeatedNum, missingNum};
    }
};
```	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[1662. Check If Two String Arrays are Equivalent](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/)**<br />
Given two string arrays `word1` and `word2`, return `true` if the two arrays **represent** the same string, and `false` otherwise.<br />
A string is **represented** by an array if the array elements concatenated **in order** forms the string.<br />
	
Example 1:
<pre>
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
</pre>
Example 2:
<pre>
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
</pre>
Example 3:
<pre>
Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
</pre> 

* Constraints: `1 <= word1.length, word2.length <= 10^3`<br />
`1 <= word1[i].length, word2[i].length <= 10^3`<br />
`1 <= sum(word1[i].length), sum(word2[i].length) <= 10^3`<br />
`word1[i]` and `word2[i]` consist of lowercase letters.<br />
	
```cpp
//mysol
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int onesize = word1.size();
        int twosize = word2.size();
        //sort(word1.begin(), word1.end());
        //sort(word2.begin(), word2.end());
        string wordone = "", wordtwo = "";
        for(int i = 0; i<=onesize-1;i++)wordone += word1[i];
        for(int i = 0; i<=twosize-1;i++)wordtwo += word2[i];
        if(wordone == wordtwo)return true;
        else return false;
    }
};

//Using cpp stl
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        auto w1=reduce(word1.begin(),word1.end());
        auto w2=reduce(word2.begin(),word2.end());
        return (w1==w2);
    }
};

//using pointers 
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0; // word pointers
        int m = 0, n = 0; // char pointers
        
        while (i < word1.size() and j < word2.size()) {            
            if (word1[i][m++] != word2[j][n++])
                return false;
            
            if (m >= word1[i].size())
                i++, m = 0;
            
            if (n >= word2[j].size())
                j++, n = 0;
        }
        
        return i == word1.size() and j == word2.size();
    }
};

//matrix
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        int wordIdx1 = 0, wordIdx2 = 0, chIdx1 = 0, chIdx2 = 0;
        while(true)
        {
            char ch1 = word1[wordIdx1][chIdx1];
            char ch2 = word2[wordIdx2][chIdx2];
            if (ch1 != ch2) return false;
            
            chIdx1++; //incrementing the character index of current word from "word1"
            chIdx2++; //incrementing the character index of current word from "word2";
            //=========================================================
            if (chIdx1 == word1[wordIdx1].size()) //if current word from "word1" is over
            { 
                wordIdx1++;  //move to next word in "word1"
                chIdx1 = 0;  //reset character index to 0
            }
            if (chIdx2 == word2[wordIdx2].size()) //if  current word from "word2" is over
            { 
                wordIdx2++;  //move to next word  in "word2"
                chIdx2 = 0; //reset character index to 0
            }
            //=================================================================
            if (wordIdx1 == word1.size() && wordIdx2 == word2.size()) break; // words in both arrays are finished
            
            if (wordIdx1 == word1.size() || wordIdx2 == word2.size()) return false;
            //if words in any onr of the arrays are finished and other still has some words in it
            //then there is no way same string could be formed on concatenation
        }
        return true; 
    }
};
```
	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[345. Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/)**<br />
Given a string `s`, reverse only all the vowels in the string and return it.<br />
The vowels are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`, and they can appear in both lower and upper cases, more than once.<br />

Example 1:
<pre>
Input: s = "hello"
Output: "holle"
</pre>
Example 2:
<pre>
Input: s = "leetcode"
Output: "leotcede"
</pre> 

* Constraints: `1 <= s.length <= 3 * 10^5`<br />
`s` consist of **printable ASCII** characters.<br />	
	
```cpp
    static bool isVowel(char ch) {
        return
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
```	
Other implementations could use a lookup in the a bit / bool vector and avoid the branching, and do something like<br />
```cpp
    static constexpr bool is_vowel[256] = {
        ['a'] = true, ['e'] = true, ['i'] = true, ['o'] = true, ['u'] = true,
        ['A'] = true, ['E'] = true, ['I'] = true, ['O'] = true, ['U'] = true,        
    };
	
	// We would likley drop this wrapper
	static constexpr bool isVowel(char ch) {
		return is_vowel[ch];
	}
```
	
`Approach 1:`extract, reverse, update<br />
We extract all the vowels, reverse them, and then update the string.
```cpp
    static string reverseVowels(string s) {
        string vowels;
        vowels.reserve(size(s));
        copy_if(begin(s), end(s), back_inserter(vowels), isVowel);
        reverse(begin(vowels), end(vowels));
        for (int i = 0, v = 0; i < size(s); ++i)
            if (isVowel(s[i])) s[i] = vowels[v++];
        return s;
    }
//Time Complexity: O(n)
//Space Complexity: O(n)
```
`Approach 2:`extract w/ index, reverse, update<br />	
Similar to approach 1, but instead of scanning the full string again, we keep track where we found the vowels and just update these positions. This approach is faster than approach 1 if there are only very few vowels in a long string.
```cpp
    static string reverseVowels(string s) {
        string vowels;
        vowels.reserve(size(s));
        vector<int> idx;
        idx.reserve(size(s));
        for (int i = 0; i < size(s); ++i) {
            if (isVowel(s[i])) {
                vowels.push_back(s[i]);
                idx.push_back(i);
            }
        }
        reverse(begin(vowels), end(vowels));
        for (int i = 0; i < size(idx); ++i)
            s[idx[i]] = vowels[i];
        return s;
    }
```
Instead of reversing vowels we could just read the vowels or the index from the back, i.e. do something like:<br />
```cpp
        for (int i = 0; i < size(idx); ++i)
            s[idx[size(idx) - 1 - i]] = vowels[i];
```
```cpp
//Time Complexity: O(n)
//Space Complexity: O(n)
```	
`Approach 3:`stack<br />
Runtime wise this is similar to approach 1. ... and yeah, `string` or a `vector` are a perfectly fine stack, but obviously we could use a `stack<char>` too.
```cpp
    static string reverseVowels(string s) {
        string st;
        st.reserve(size(s));
        for (char ch : s)
            if (isVowel(ch)) st.push_back(ch);
        for (char& ch : s)
            if (isVowel(ch)) {
                ch = st.back();
                st.pop_back();
            }
        return s;
    }
//Time Complexity: O(n)
//Space Complexity: O(n)
```	
`Approach 4:`two pointers<br />	
In my opinion this is the best approach. Btw. doing `swap(s[l++], s[r--]);` instead of `if (l < r) swap(s[l++], s[r--]);` will swap a character with itself at the end, but that doesnot matter.	
```cpp
    static string reverseVowels(string s) {
        for (int l = 0, r = size(s) - 1; l < r; ) {
            while (l < r && !isVowel(s[l])) ++l;
            while (l < r && !isVowel(s[r])) --r;
            swap(s[l++], s[r--]);
        }
        return s;
    }
//Time Complexity: O(n)
//Space Complexity: O(1)
```	
`Approach 5:` `string::find_first_of`, `string::find_last_of`<br />
```cpp
    static string reverseVowels(string s) {
        for (int l = 0, r = size(s) - 1; l < r; ) {
            l = s.find_first_of("aeiouAEIOU", l);
            r = s.find_last_of("aeiouAEIOU", r);
            if (l < r) swap(s[l++], s[r--]);
        }
        return s;
    }
//Time Complexity: O(n)
//Space Complexity: O(1)
```
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[1323. Maximum 69 Number](https://leetcode.com/problems/maximum-69-number/)**<br />
You are given a positive integer `num` consisting only of digits `6` and `9`.<br />
Return the maximum number you can get by changing at most one digit (`6` becomes `9`, and `9` becomes `6`).<br />
	
Example 1:
<pre>
Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
</pre>
Example 2:
<pre>
Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
</pre>
Example 3:
<pre>
Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
</pre>
	
* Constraints: `1 <= num <= 10^4`<br />
`num` consists of only `6` and `9` digits.<br />
	
```cpp
class Solution {
public:
    int maximum69Number (int num) {
        
        string s = to_string(num);
        
        /* You can change at the most one digit,
           so traverse from left and change the first
           encountered 6  to  9  (to increase th value of num) */
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '6')
            {
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
    }
};
```
	
	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[1544. Make The String Great](https://leetcode.com/problems/make-the-string-great/)**<br />
Given a string `s` of lower and upper case English letters.<br />
A good string is a string which doesn't have **two adjacent characters** `s[i]` and `s[i + 1]` where:<br />

 * `0 <= i <= s.length - 2`<br />
 * `s[i]` is a lower-case letter and `s[i + 1]` is the same letter but in upper-case or **vice-versa**.<br />
	
To make the string good, you can choose **two adjacent** characters that make the string bad and remove them. You can keep doing this until the string becomes good.<br />
Return the string after making it good. The answer is guaranteed to be unique under the given constraints.<br />
**Notice** that an empty string is also good.<br />
	
Example 1:
<pre>
Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
</pre>
Example 2:
<pre>
Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
</pre>
Example 3:
<pre>
Input: s = "s"
Output: "s"
</pre>
	
* Constraints: `1 <= s.length <= 100`<br />
`s` contains only lower and upper case English letters.<br />
	
```cpp
class Solution {
public:
    string makeGood(string s) {
        
        string ans;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            ans.push_back(s[i]);
            
            while(ans.size() && (ans.back()==s[i+1]+32 || ans.back()==s[i+1]-32))
            {
                ans.pop_back();
                i++;
            }
        }
        
        return ans;
    }
};
```
Explanation:
<pre>
Consider Sample Example 2   s = "abBAcC"
</pre>
<pre>
      i = 0   ans = a          s[i+1] = b
</pre>
<pre>
      i = 1   ans = ab         s[i+1] = B
</pre>
<pre>
      i = 2   ans = a          s[i+1] = A
</pre>
<pre>
      i = 3   ans = ""         s[i+1] = c
</pre>
<pre>
      i = 4   ans = c          s[i+1] = C
</pre>
<pre>
      i = 5   ans = "" 
</pre>
<pre>
      Finally ans = "" 
</pre>

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[1047. Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/)**<br />
You are given a string `s` consisting of lowercase English letters. A **duplicate removal** consists of choosing two **adjacent** and **equal** letters and removing them.<br />
We repeatedly make **duplicate removals** on `s` until we no longer can.<br />
Return the final string after all such duplicate removals have been made. It can be proven that the answer is **unique**.<br />	

Example 1:
<pre>
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
</pre>
Example 2:
<pre>
Input: s = "azxxzy"
Output: "ay"
</pre>

* Constraints: `1 <= s.length <= 10^5`<br />
`s` consists of lowercase English letters.<br />
	
```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        stack<char>checkthetop;
        for(int i = 0;i<s.length();i++){
            if(!checkthetop.empty() && s[i] == checkthetop.top()){
                checkthetop.pop();
                continue;
            }
            else(checkthetop.push(s[i]));
        }
        while(!checkthetop.empty()){
            ans += checkthetop.top();
            checkthetop.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//TC : 0(n) SC : O(n)
```
Explanation :
<pre>
			s = "abbaca"
</pre>
<pre>
		ans = a              s[i+1] = b
</pre>	
<pre>
		ans = ab             s[i+1] = b
</pre>	
<pre>
		ans = a              s[i+1] = a
</pre>		
<pre>
		ans = c              s[i+1] = a
</pre>		
<pre>
		ans = ca      
 				 
		Finally ans = "ca" 
</pre>		
	
	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)**<br />
Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates `in-place` such that each unique element appears only **once**. The **relative order** of the elements should be kept the **same**.<br />
Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the **first part** of the array `nums`. More formally, if there are `k` elements after removing the duplicates, then the first `k` elements of `nums` should hold the final result. It does not matter what you leave beyond the first `k` elements.<br />
Return `k` after placing the final result in the first `k` slots of **nums**.<br />
Do **not** allocate extra space for another array. You must do this by **modifying the input array** `in-place` with O(1) extra memory.<br /><br />
**Custom Judge**:<br />
The judge will test your solution with the following code:<br />
<pre>
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
</pre>
If all assertions pass, then your solution will be **accepted**.<br />

Example 1:
<pre>
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>
Example 2:
<pre>
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

* Constraints: `1 <= nums.length <= 3 * 10^4`<br />
`-100 <= nums[i] <= 100`<br />
`nums` is sorted in **non-decreasing** order.<br />

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count =0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) count++;
            else nums[i - count] = nums[i];
        }
        return nums.size()-count;
    } 
};
```
	
	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[374. Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/description/)**<br />
We are playing the Guess Game. The game is as follows:<br />
I pick a number from `1` to `n`. You have to guess which number I picked.<br />
Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.<br />
You call a pre-defined API `int guess(int num)`, which returns three possible results:<br />

 * `-1`: Your guess is higher than the number I picked (i.e. `num > pick`).<br />
 * `1`: Your guess is lower than the number I picked (i.e. `num < pick`).<br />
 * `0`: your guess is equal to the number I picked (i.e. `num == pick`).<br />

Return the number that I picked.<br />

Example 1:
<pre>
Input: n = 10, pick = 6
Output: 6
</pre>
Example 2:
<pre>
Input: n = 1, pick = 1
Output: 1
</pre>
Example 3:
<pre>
Input: n = 2, pick = 1
Output: 1
</pre>

* Constraints: `1 <= n <= 2^31 - 1`<br />
`1 <= pick <= n`<br />

```cpp
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
      int guessNumber(const int n) {
        int lo = 1;
        int hi = n;
        while (lo <= hi) {
            const int mid = lo + (hi - lo) / 2;
            const int g = guess(mid);
            if (g == 0) {
                return mid;
            } else if (g == -1) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        // unreachable
        assert(false);
        return -1;
    }
};

//Time Complexity: O(log n)
//Space Complexity: O(1)
```

















	
<br /> <br /> <br />**[263. Ugly Number](https://leetcode.com/problems/ugly-number/description/)**<br />
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.<br />
Given an integer n, return true if n is an ugly number.<br />

Example 1:
<pre>
Input: n = 6
Output: true
Explanation: 6 = 2 × 3
</pre>
Example 2:
<pre>
Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
</pre>
Example 3:
<pre>
Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.
</pre>

* Constraints: `-2^31 <= n <= 2^31 - 1`<br />

```cpp
class Solution {
public:
    bool isUgly(int n) 
    {
        if (n <= 0) return false;
        while(n > 1)
        {
            if (n % 2 == 0) n = n / 2;
            else if (n % 3 == 0) n = n / 3;
            else if (n % 5 == 0) n = n / 5;
            else break;
        }
        return (n == 1);
    }
};
```














	
<br /> <br /> <br />**[1207. Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/)**<br />
Given an array of integers `arr`, return `true` if the number of occurrences of each value in the array is unique or `false` otherwise.<br />

Example 1:
<pre>
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
</pre>
Example 2:
<pre>
Input: arr = [1,2]
Output: false
</pre>
Example 3:
<pre>
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
</pre>

* Constraints: `1 <= arr.length <= 1000`<br />
`-1000 <= arr[i] <= 1000`<br />

```cpp
class Solution 
{
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int, int> cnt;
        unordered_set<int> unq;
        for (int n   : arr) cnt[n]++;               // [1] count frequencies
        for (auto& c : cnt) unq.insert(c.second);   // [2] collect unique frequencies
        return cnt.size() == unq.size();
    }
};
```





















	
<br /> <br /> <br />**[1704. Determine if String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/)**<br />
You are given a string `s` of even length. Split this string into two halves of equal lengths, and let `a` be the first half and `b` be the second half.<br />
Two strings are alike if they have the same number of vowels (`'a'`, `'e'`, `'i'`, `'o'`, `'u'`, `'A'`, `'E'`, `'I'`, `'O'`, `'U'`). Notice that `s` contains uppercase and lowercase letters.<br />
Return `true` if `a` and `b` are **alike**. Otherwise, return `false`.<br />

Example 1:
<pre>
Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
</pre>
Example 2:
<pre>
Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
</pre>

* Constraints: `2 <= s.length <= 1000`<br />
`s.length` is even.<br />
`s` consists of **uppercase and lowercase** letters.<br />

```cpp
class Solution {
public:
    bool halvesAreAlike(string s) {
        int frontvowels = 0, endvowels = 0;
        for(int i = 0;i<s.length()/2;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')frontvowels++;
        }
        for(int i = s.length()/2;i<s.length();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')endvowels++;
        }
        return (frontvowels == endvowels);
    }
};
```

















	
<br /> <br /> <br />**[938. Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/description/)**<br />
Given the `root` node of a binary search tree and two integers `low` and `high`, return the sum of values of all nodes with a value in the inclusive range `[low, high]`.<br />

Example 1:
<pre>
<img src = "https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg">
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
</pre>
Example 2:
<pre>
<img src = "https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg">
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
</pre>

* Constraints: The number of nodes in the tree is in the range `[1, 2 * 10^4]`.<br />
`1 <= Node.val <= 10^5`<br />
`1 <= low <= high <= 10^5`<br />
All `Node.val` are **unique**.<br />

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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
    if(!root || low > high)
        return 0;
    
    if(root->val < low)
        return rangeSumBST(root->right, low, high);
    
    if(root->val > high)
        return rangeSumBST(root->left, low, high);
    
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);    
    }
};
```












	
<br /> <br /> <br />**[872. Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/description/)**<br />
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a **leaf value sequence**.<br />
<img src = "https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png"><br />
For example, in the given tree above, the leaf value sequence is (`6, 7, 4, 9, 8`).<br />
Two binary trees are considered leaf-similar if their leaf value sequence is the same.<br />
Return `true` if and only if the two given trees with head nodes `root1` and `root2` are leaf-similar.<br />

Example 1:
<pre>
<img src = "https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-1.jpg">
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
</pre>
Example 2:
<pre>
<img src = "https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-2.jpg">
Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
</pre>

* Constraints: The number of nodes in each tree will be in the range `[1, 200]`.<br />
Both of the given trees will have values in the range `[0, 200]`.<br />

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
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1 , s2;
        s1.push(root1); s2.push(root2);
        while (!s1.empty() && !s2.empty())
            if (dfs(s1) != dfs(s2)) return false;
        return s1.empty() && s2.empty();
    }

    int dfs(stack<TreeNode*>& s) {
        while (true) {
            TreeNode* node = s.top(); s.pop();
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
            if (!node->left && !node->right) return node->val;
        }
    }
};

/*
Here I share an idea of comparing node by node using O(H) space,
where H is the height of the tree.

Use a stack<TreeNode> to keep dfs path.
dfs(stack) will return next leaf.
Check leaves one by one, until the end or difference.
Only O(H) space for stack, no extra space for comparation.
O(1) is also possible if we can modify the tree.
*/
```











<br /> <br /> <br />**[70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)**<br />
You are climbing a staircase. It takes `n` steps to reach the top.<br />
Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?<br />

Example 1:
<pre>
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
</pre>
Example 2:
<pre>
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
</pre>

* Constraints: `1 <= n <= 45`<br />

`DP solution`
```cpp
class Solution {
public:
    int helper(int ind, vector<int> &dp){
        if(ind==0)return dp[ind]+=1;
        if(dp[ind]!=0)return  dp[ind];
        if(ind>2)return dp[ind]=helper(ind-1,dp)+helper(ind-2,dp);
        return 0;
    }
    
    int climbStairs(int n) {
        if(n<=2)return n;
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        helper(n,dp);
        return dp[n];
    }
};
```

`Fibonacci solution`
```cpp
int climbStairs(int n) {
   if(n == 0||n==1)return n;
   int b = 1;
   int a = 2;    
   for(int i=3;i<=n;i++){
       a = a+b;
       b = a-b; 
   }
   return a; 
}
```













# This is Bottom	
<br /> <br /> <br />**[]()**<br />
