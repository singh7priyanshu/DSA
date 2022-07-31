# Leetcode daily medium questions 
**[289. Game of Life](https://leetcode.com/problems/game-of-life/)**<br />
According to `Wikipedia's article`: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."<br />

The board is made up of an `m x n` grid of cells, where each cell has an initial state: live (represented by a `1`) or dead (represented by a `0`). Each cell interacts with its `eight neighbors` (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):<br />

1. Any live cell with fewer than two live neighbors dies as if caused by under-population.<br />
2. Any live cell with two or three live neighbors lives on to the next generation.<br />
3. Any live cell with more than three live neighbors dies, as if by over-population.<br />
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.<br />
 
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the `m x n` grid `board`, return the next state.<br />
 
>Example 1: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/12/26/grid1.jpg"><br />
>Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]<br />
>Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]<br />

>Example 2: <br />
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/12/26/grid2.jpg"><br />
>Input: board = [[1,1],[1,0]]<br />
>Output: [[1,1],[1,1]]<br />

* Constraints:<br />`m == board.length`<br />
`n == board[i].length`<br />
`1 <= m, n <= 25`<br />
`board[i][j] is 0 or 1`<br />
```cpp
class Solution {
public:
    int R, C;
    bool isLive(int status) {
        return status == 1;
    }
    int getLiveNeighborsCnt(int row, int col, vector<vector<int>>& board) {
        int cnt = 0;
        cnt += row - 1 >= 0 && board[row - 1][col] ? 1 : 0;
        cnt += row + 1 < R && board[row + 1][col] ? 1 : 0;
        cnt += col - 1 >= 0 && board[row][col - 1] ? 1 : 0;
        cnt += col + 1 < C && board[row][col + 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col + 1 < C && board[row - 1][col + 1] ? 1 : 0;
        cnt += row + 1 < R && col - 1 >= 0 && board[row + 1][col - 1] ? 1 : 0;
        cnt += row + 1 < R && col + 1 < C && board[row + 1][col + 1] ? 1 : 0;
        
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        R = board.size(), C = board[0].size();
		int liveNeighborsCnt;
        vector<vector<int>> tempBoard = board;        
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                liveNeighborsCnt = getLiveNeighborsCnt(r, c, tempBoard);
                if(isLive(board[r][c])) {
                    if(liveNeighborsCnt < 2 || liveNeighborsCnt > 3) board[r][c] = 0;
                } else {
                    board[r][c] = liveNeighborsCnt == 3 ? 1 : 0;
                }
            }
        }
    }
};
```
	
	

 <br /> <br /> <br /> **[1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)**<br />
Given an array of integers `nums` and an integer `limit`, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to `limit`.

>Example 1: <br /> 
>Input: nums = [8,2,4,7], limit = 4<br />
>Output: 2 <br />
>Explanation: All subarrays are: <br />
>[8] with maximum absolute diff |8-8| = 0 <= 4.<br />
>[8,2] with maximum absolute diff |8-2| = 6 > 4. <br />
>[8,2,4] with maximum absolute diff |8-2| = 6 > 4.<br />
>[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.<br />
>[2] with maximum absolute diff |2-2| = 0 <= 4.<br />
>[2,4] with maximum absolute diff |2-4| = 2 <= 4.<br />
>[2,4,7] with maximum absolute diff |2-7| = 5 > 4.<br />
>[4] with maximum absolute diff |4-4| = 0 <= 4.<br />
>[4,7] with maximum absolute diff |4-7| = 3 <= 4.<br />
>[7] with maximum absolute diff |7-7| = 0 <= 4. <br />
>Therefore, the size of the longest subarray is 2.<br />

>Example 2: <br /> 
>Input: nums = [10,1,2,4,7,2], limit = 5<br />
>Output: 4 <br />
>Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.<br />

>Example 3: <br /> 
>Input: nums = [4,2,2,2,4,4,2,2], limit = 0 <br /> 
>Output: 3 <br /> 

* Constraints:<br />`1 <= nums.length <= 10^5`<br /> 
`1 <= nums[i] <= 10^9`<br /> 
`0 <= limit <= 10^9`<br /> 

```cpp
class Solution {
public:
  
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int start = 0;
        int diff;
        deque<int> minQ;
        deque<int> maxQ;
        int maxws = INT_MIN;
        for(int end=0;end<n;end++){
            while(!minQ.empty() && nums[minQ.back()]>=nums[end])minQ.pop_back();
            minQ.push_back(end);
            while(!maxQ.empty() && nums[maxQ.back()]<=nums[end])maxQ.pop_back();
            maxQ.push_back(end);
            
            diff = nums[maxQ.front()]-nums[minQ.front()];
            
            while(diff>limit){
                start++;
                while(!minQ.empty() && minQ.front()<start) minQ.pop_front();
                while(!maxQ.empty() && maxQ.front()<start) maxQ.pop_front();
                diff= nums[maxQ.front()] - nums[minQ.front()];
            }
            if(diff<=limit){
                int ws = end-start+1;
                maxws = max(maxws,ws);
            }
        }
        return maxws;
    }
};
```

			    

<br /> <br /> <br /> **[59. Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)**<br />
Given a positive integer `n`, generate an `n x n matrix` filled with elements from `1` to n<sup>2</sup> in spiral order.
>Example 1: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg"><br />
>Input: n = 3<br /> 
>Output: [[1,2,3],[8,9,4],[7,6,5]]<br /> 

>Example 2: <br /> 
>Input: n = 1 <br /> 
>Output: [[1]] <br /> 

* Constraints:<br />`1 <= n <= 20`<br /> 

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r1 = 0, r2 = n-1;
        int c1 = 0, c2 = n-1;
        int val = 0;
        vector<vector<int>> v(n, vector<int> (n));
        while(r1 <= r2 && c1 <= c2){
            for(int i = c1; i <= c2; ++i)v[r1][i] = ++val;
            for(int i = r1+1; i <= r2; ++i)v[i][c2] = ++val;
            if(r1 < r2 && c1 < c2){
                for(int i = c2-1; i>c1; --i)v[r2][i] = ++val;
					for(int i = r2; i>r1; --i)v[i][c1] = ++val;
            }
            ++r1; --r2; ++c1; --c2;
        }
        return v;
    }
};	
```
	
	
	
<br /> <br /> <br /> **[669. Trim a Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree/)**<br />
Given the `root` of a binary search tree and the lowest and highest boundaries as `low` and `high`, trim the tree so that all its elements lies in `[low, high]`. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a `unique answer`.<br /> 
Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.<br /> 

>Example 1: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/09/09/trim1.jpg"><br />
>Input: root = [1,0,2], low = 1, high = 2<br />
>Output: [1,null,2]<br />

>Example 2: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/09/09/trim2.jpg"><br />
>Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3<br />
>Output: [3,2,null,1]<br />
	
* Constraints:<br />The number of nodes in the tree is in the range `[1, 10^4]`.<br /> 
`0 <= Node.val <= 10^4`<br />
The value of each node in the tree is `unique`.<br />
`root` is guaranteed to be a valid binary search tree.<br />
`0 <= low <= high <= 10^4`<br />
	
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return nullptr;
        if(root->val < low)return trimBST(root->right, low, high);
        else if (root->val > high)return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
```


  
  
  
  
<br /> <br /> <br /> **[538. Convert BST to Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/)**<br />
Given the `root` of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.<br />
As a reminder, a binary search tree is a tree that satisfies these constraints:<br />
* The left subtree of a node contains only nodes with keys `less than` the node's key.<br />
* The right subtree of a node contains only nodes with keys `greater than` the node's key.<br />
* Both the left and right subtrees must also be binary search trees.<br />
    
>Example 1: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2019/05/02/tree.png"><br />
>Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]<br />
>Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]<br />

>Example 2: <br /> 
>Input: root = [0,null,1]<br />
>Output: [1,null,1]<br />
	
* Constraints:<br />The number of nodes in the tree is in the range `[0, 10^4]`.<br /> 
`-10^4 <= Node.val <= 10^4`<br /> 
All the values in the tree are `unique`.<br /> 
`root` is guaranteed to be a valid binary search tree.<br /> 
	
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
    int dfs(TreeNode* root, int aboveSum) {
        if(!root) return 0;
        int right = dfs(root->right, aboveSum);
        int left = dfs(root->left, right + root->val + aboveSum);
        int sumBelow = root->val + left + right; 
        root->val += aboveSum + right;
        return sumBelow;
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
};
```

	

  
  
  
<br /> <br /> <br /> **[230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)**<br />	
Given the `root` of a binary search tree, and an integer `k`, return the `kth` smallest value `(1-indexed)` of all the values of the nodes in the tree.<br />

>Example 1: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg"><br />
>Input: root = [3,1,4,null,2], k = 1<br />
>Output: 1<br />

>Example 2: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg"><br />
>Input: root = [5,3,6,2,4,null,null,1], k = 3<br />
>Output: 3<br />
	
* Constraints:<br />The number of nodes in the tree is `n`.<br /> 
`1 <= k <= n <= 10^4`<br /> 
`0 <= Node.val <= 10^4`<br /> 
	
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
    vector<int> result;
    void getinorder(TreeNode *root){
        if(root==nullptr) return;
        getinorder(root->left);
        result.push_back(root->val);
        getinorder(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        getinorder(root);
        return result[k-1];
    }
};
```
	
	

<br /> <br /> <br />**[99. Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/)**<br />
You are given the `root` of a binary search tree (BST), where the values of **exactly** two nodes of the tree were swapped by mistake. _Recover the tree without changing its structure_.<br />

>Example 1: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg"><br />
>Input: root = [1,3,null,null,2]<br /> 
>Output: [3,1,null,null,2]<br /> 
>Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.<br /> 
	
>Example 2: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/10/28/recover2.jpg"><br />
>Input: root = [3,1,4,null,null,2]<br /> 
>Output: [2,1,4,null,null,3]<br /> 
>Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.<br /> 
	
* Constraints:<br />The number of nodes in the tree is in the range `[2, 1000]`.<br /> 
`-2^31 <= Node.val <= 2^31 - 1`<br />

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
    TreeNode* first, *last, *prev;
public:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev!=NULL && (root->val<prev->val)){
            if(first==NULL){
                first=prev;
                last=root; 
            }
            else
                last=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=last=prev=NULL;
        inorder(root);
        swap(first->val,last->val);
    }
};
```

	
	
<br /> <br /> <br />**[173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/)**<br />
Implement the `BSTIterator` class that represents an iterator over the **in-order traversal** of a binary search tree (BST):<br />
* `BSTIterator(TreeNode root)` Initializes an object of the `BSTIterator` class. The `root` of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.<br />
* `boolean hasNext()` Returns `true` if there exists a number in the traversal to the right of the pointer, otherwise returns `false`.<br />
* `int next()` Moves the pointer to the right, then returns the number at the pointer.<br />

Notice that by initializing the pointer to a non-existent smallest number, the first call to `next()` will return the smallest element in the BST.<br />
You may assume that `next()` calls will always be valid. That is, there will be at least a next number in the in-order traversal when `next()` is called.<br />

>Example 1: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2018/12/25/bst-tree.png"><br />
>Input:<br />
>["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]<br />
>[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]<br />
>Output:
>[null, 3, 7, true, 9, true, 15, true, 20, false]<br />
>Explanation<br />
>BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);<br />
>bSTIterator.next();    // return 3<br />
>bSTIterator.next();    // return 7<br />
>bSTIterator.hasNext(); // return True<br />
>bSTIterator.next();    // return 9<br />
>bSTIterator.hasNext(); // return True<br />
>bSTIterator.next();    // return 15<br />
>bSTIterator.hasNext(); // return True<br />
>bSTIterator.next();    // return 20<br />
>bSTIterator.hasNext(); // return False<br />

* Constraints:<br />The number of nodes in the tree is in the range `[1, 10^5]`.<br /> 
`0 <= Node.val <= 10^6`<br /> 
At most `10^5` calls will be made to `hasNext`, and `next`.<br /> 

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
class BSTIterator {
public:
     stack<TreeNode*> st;
    BSTIterator(TreeNode *root) {
        Lefttree(root);
    }
    
    bool hasNext() {
    return st.empty() ? false : true;
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != NULL)
            Lefttree(top->right);  
     return top->val;
    }
    
    void Lefttree(TreeNode* root)
    {
        TreeNode* p = root;
        while (p)
        {
            st.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
	


  
  
<br /> <br /> <br />**[535. Encode and Decode TinyURL](https://leetcode.com/problems/encode-and-decode-tinyurl/)**<br />
* Note: This is a companion problem to the System Design problem: [Design TinyURL](https://leetcode.com/discuss/interview-question/124658/Design-a-URL-Shortener-(-TinyURL-)-System/).<br />
TinyURL is a URL shortening service where you enter a URL such as `https://leetcode.com/problems/design-tinyurl` and it returns a short URL such as `http://tinyurl.com/4e9iAk`. Design a class to encode a URL and decode a tiny URL.<br />
There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.<br />
Implement the `Solution` class:<br />
* `Solution()` Initializes the object of the system.<br />
* `String encode(String longUrl)` Returns a tiny URL for the given `longUrl`.<br />
* `String decode(String shortUrl)` Returns the original long URL for the given `shortUrl`. It is guaranteed that the given `shortUrl` was encoded by the same object.<br />
	
>Example 1: <br /> 
>Input: url = "`https://leetcode.com/problems/design-tinyurl`" <br />
>Output: "`https://leetcode.com/problems/design-tinyurl`" <br />
>Explanation: <br />
>Solution obj = new Solution(); <br />
>string tiny = obj.encode(url); // returns the encoded tiny url. <br />
>string ans = obj.decode(tiny); // returns the original url after deconding it. <br />

* Constraints:<br />`1 <= url.length <= 10^4`.<br />
`url` is guranteed to be a valid URL. <br />
	
```cpp
class Solution {
public:
    unordered_map<string, string>mp;
    int length = 6;
    
    string hashing(string longUrl){
        string hashCode = "";
        
        for(int i=0; i<length; i++){
            int random = rand() % 3;
            
            if(random == 0)
                hashCode += ('0' + rand() % 10);
            else if(random == 1)
                hashCode += ('a' + rand() % 26);
            else
                hashCode += ('A' + rand() % 26);
        }
        
        if(mp.find(hashCode) !=mp.end())
            return hashing(longUrl);
        else{
            mp[hashCode] = longUrl;
            return hashCode;
        }
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string tinyUrl = "http://tinyurl.com/";
        string hashCode = hashing(longUrl);
        return tinyUrl + hashCode;
    }
    
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string hashCode = shortUrl.substr(shortUrl.size() - length, length);
        return mp[hashCode];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```
			       
			       
			   
<br /> <br /> <br />**[1396. Design Underground System](https://leetcode.com/problems/design-underground-system/)**<br />
An underground railway system is keeping track of customer travel times between different stations. They are using this data to calculate the average time it takes to travel from one station to another.<br />
Implement the `UndergroundSystem` class:<br />
* `void checkIn(int id, string stationName, int t)`<br />
  * A customer with a card ID equal to `id`, checks in at the station `stationName` at time `t`.<br />
  * A customer can only be checked into one place at a time.<br />
* `void checkOut(int id, string stationName, int t)`<br />
  * A customer with a card ID equal to `id`, checks out from the station `stationName` at time `t`.<br />
* `double getAverageTime(string startStation, string endStation)`<br />
  * Returns the average time it takes to travel from `startStation` to `endStation`.<br />
  * The average time is computed from all the previous traveling times from `startStation` to `endStation` that happened **directly**, meaning a check in at `startStation` followed by a check out from `endStation`.<br />
  * The time it takes to travel from `startStation` to `endStation` **may be different** from the time it takes to travel from `endStation` to `startStation`.<br />
  * There will be at least one customer that has traveled from `startStation` to `endStation` before `getAverageTime` is called.<br />

You may assume all calls to the `checkIn` and `checkOut` methods are consistent. If a customer checks in at time `t1` then checks out at time `t2`, then `t1 < t2`. All events happen in chronological order.<br />

>Example 1: <br /> 
>Input:<br />
>["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]<br />
>[[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]<br />
>Output:<br />
>[null,null,null,null,null,null,null,14.00000,11.00000,null,11.00000,null,12.00000]<br />
>Explanation:<br />
>UndergroundSystem undergroundSystem = new UndergroundSystem();<br />
>undergroundSystem.checkIn(45, "Leyton", 3);<br />
>undergroundSystem.checkIn(32, "Paradise", 8);<br />
>undergroundSystem.checkIn(27, "Leyton", 10);<br />
>undergroundSystem.checkOut(45, "Waterloo", 15);  // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12<br />
>undergroundSystem.checkOut(27, "Waterloo", 20);  // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10<br />
>undergroundSystem.checkOut(32, "Cambridge", 22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14<br />
>undergroundSystem.getAverageTime("Paradise", "Cambridge"); // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14<br />
>undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11<br />
>undergroundSystem.checkIn(10, "Leyton", 24);<br />
>undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 11.00000<br />
>undergroundSystem.checkOut(10, "Waterloo", 38);  // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14<br />
>undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12<br />
	
>Example 2:<br />
>Input:<br />
>["UndergroundSystem","checkIn","checkOut","getAverageTime","checkIn","checkOut","getAverageTime","checkIn","checkOut","getAverageTime"]<br />
>[[],[10,"Leyton",3],[10,"Paradise",8],<br />["Leyton","Paradise"],[5,"Leyton",10],<br />[5,"Paradise",16],["Leyton","Paradise"],<br />[2,"Leyton",21],[2,"Paradise",30],<br />["Leyton","Paradise"]]<br />
>Output:<br />
>[null,null,null,5.00000,null,null,5.50000,null,null,6.66667]<br />
>Explanation:<br />
>UndergroundSystem undergroundSystem = new UndergroundSystem();<br />
>undergroundSystem.checkIn(10, "Leyton", 3);<br />
>undergroundSystem.checkOut(10, "Paradise", 8); // Customer 10 "Leyton" -> "Paradise" in 8-3 = 5<br />
>undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.00000, (5) / 1 = 5<br />
>undergroundSystem.checkIn(5, "Leyton", 10);<br />
>undergroundSystem.checkOut(5, "Paradise", 16); // Customer 5 "Leyton" -> "Paradise" in 16-10 = 6<br />
>undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.50000, (5 + 6) / 2 = 5.5<br />
>undergroundSystem.checkIn(2, "Leyton", 21);<br />
>undergroundSystem.checkOut(2, "Paradise", 30); // Customer 2 "Leyton" -> "Paradise" in 30-21 = 9<br />
>undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 6.66667, (5 + 6 + 9) / 3 = 6.66667<br />
	
* Constraints:<br />`1 <= id, t <= 10^6`.<br />
`1 <= stationName.length, startStation.length, endStation.length <= 10`<br />
All strings consist of uppercase and lowercase English letters and digits.<br />
There will be at most `2 * 10^4` calls **in total** to `checkIn`, `checkOut`, and `getAverageTime`.<br />
Answers within `10^-5` of the actual value will be accepted.<br />
	
```cpp
class UndergroundSystem {
public:
    unordered_map<string, pair<long long, int>> stationTimes;
    unordered_map<int, pair<string,int>> inTransit;
    UndergroundSystem() {
        stationTimes.clear();
        inTransit.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        if(inTransit.find(id) != inTransit.end()) return;
        inTransit[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& info = inTransit[id];
        string startStation = info.first;
        int startTime = info.second;
        string key = startStation + ":" + stationName;
        int time = t - startTime;
        
        if(stationTimes.find(key) != stationTimes.end()) {
            auto& oldTimes = stationTimes[key];
            oldTimes.first += time;
            oldTimes.second++;
        } else {
            stationTimes[key] = {time, 1};
        }
        inTransit.erase(id);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + ":" + endStation;
        auto& info = stationTimes[key];
        double avg = (double)info.first / (double)info.second;
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
```
	



<br /> <br /> <br />**[284. Peeking Iterator](https://leetcode.com/problems/peeking-iterator/)**<br />
Design an iterator that supports the `peek` operation on an existing iterator in addition to the `hasNext` and the `next` operations.<br />
Implement the `PeekingIterator` class:<br />
* `PeekingIterator(Iterator<int> nums)` Initializes the object with the given integer iterator `iterator`.
* `int next()` Returns the next element in the array and moves the pointer to the next element.
* `boolean hasNext()` Returns `true` if there are still elements in the array.
* `int peek()` Returns the next element in the array **without** moving the pointer.
> **Note**: Each language may have a different implementation of the constructor and `Iterator`, but they all support the `int next()` and `boolean hasNext()` functions.<br />

>Example 1:<br />
>Input:<br />
>["PeekingIterator", "next", "peek", "next", "next", "hasNext"]<br />
>[[[1, 2, 3]], [], [], [], [], []]<br />
>Output:<br />
>[null, 1, 2, 2, 3, false]<br />
>Explanation:<br />
>PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]<br />
>peekingIterator.next();    // return 1, the pointer moves to the next element [1,2,3].<br />
>peekingIterator.peek();    // return 2, the pointer does not move [1,2,3].<br />
>peekingIterator.next();    // return 2, the pointer moves to the next element [1,2,3]<br />
>peekingIterator.next();    // return 3, the pointer moves to the next element [1,2,3]<br />
>peekingIterator.hasNext(); // return False<br />
	
* Constraints:`1 <= nums.length <= 1000`<br />
`1 <= nums[i] <= 1000`<br />
All the calls to `next` and `peek` are valid.<br />
At most `1000` calls will be made to `next`, `hasNext`, and `peek`.<br />
	
```cpp
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        Iterator temp = (*this); //taking a new iterator and storing the current value
        return temp.next();//return the next of that iterator
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return Iterator::next();// override
	}
	
	bool hasNext() const {
	    return Iterator::hasNext(); // override
	}
};
```
	
	
	

<br /> <br /> <br />**[1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)**<br />
You are given an array `points` representing integer coordinates of some points on a 2D-plane, where `points[i] = [xi, yi]`.<br />
The cost of connecting two points [xi, yi] and [xj, yj] is the **manhattan distance** between them: `|xi - xj| + |yi - yj|`, where `|val|` denotes the absolute value of `val`.<br />
Return the _minimum cost to make all points connected_. All points are connected if there is **exactly one** simple path between any two points.<br />

>Example 1: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/08/26/d.png"><br />
>Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]<br />
>Output: 20<br />
>Explanation:<br />
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/08/26/c.png"><br />
>We can connect the points as shown above to get the minimum cost of 20.<br />
Notice that there is a unique path between every pair of points.<br />

>Example 2: <br />
>Input: points = [[3,12],[-2,5],[-4,1]]<br />
>Output: 18<br />

* Constraints:`1 <= points.length <= 1000`<br />
`-10^6 <= xi, yi <= 10^6`<br />
All pairs `(xi, yi)` are distinct.<br />
	
```cpp
class Solution {
public:
    int getParent(vector<int>& parents, int idx){
        if(parents[idx]==idx)return idx;
        parents[idx] = getParent(parents, parents[parents[idx]]);
        return parents[idx]; 
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> parents(n);        
        iota(parents.begin(), parents.end(), 0);
        int ans = 0, edges = 0;
        priority_queue<vector<int>> pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j)pq.push({-1*(abs(points[i][0] - points[j][0]) + abs(points[i][1] -                                                                          points[j][1])), i, j});   
            }
        }
        while(edges!=n-1){
            vector<int> edge = pq.top();
            int p1 = getParent(parents, edge[1]);
            int p2 = getParent(parents, edge[2]);
            if(p1!=p2){
                ans += -1*edge[0];
                parents[p1] = p2;
                edges++;
            }
            pq.pop();
        }
        return ans;
    }
};
```
	
	
	
<br /> <br /> <br />**[1202. Smallest String With Swaps](https://leetcode.com/problems/smallest-string-with-swaps/)**<br />
You are given a string `s`, and an array of pairs of indices in the string `pairs` where `pairs[i] = [a, b]` indicates 2 indices(0-indexed) of the string.<br />
You can swap the characters at any pair of indices in the given `pairs` **any number of times**.<br />
Return the lexicographically smallest string that `s` can be changed to after using the swaps.<br />

>Example 1:<br />
>Input: s = "dcab", pairs = [[0,3],[1,2]]<br />
>Output: "bacd"<br />
>Explaination:<br /> 
>Swap s[0] and s[3], s = "bcad"<br />
>Swap s[1] and s[2], s = "bacd"<br />
	
>Example 2:<br />
>Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]<br />
>Output: "abcd"<br />
>Explaination: <br />
>Swap s[0] and s[3], s = "bcad"<br />
>Swap s[0] and s[2], s = "acbd"<br />
>Swap s[1] and s[2], s = "abcd"<br />
	
>Example 3:<br />
>Input: s = "cba", pairs = [[0,1],[1,2]]<br />
>Output: "abc"<br />
>Explaination: <br />
>Swap s[0] and s[1], s = "bca"<br />
>Swap s[1] and s[2], s = "bac"<br />
>Swap s[0] and s[1], s = "abc"<br />
 
* Constraints:`1 <= s.length <= 10^5`.<br />
`0 <= pairs.length <= 10^5`.<br />
`0 <= pairs[i][0], pairs[i][1] < s.length`.<br />
`s` only contains lower case English letters.<br />
	
```cpp
class Solution {
public:
    void dfs(vector<vector<int>>& adjList, int x, unordered_set<int>& seen, vector<string>& sets, int seti, unordered_map<int, int>& parentSet, string& s) {
        if(seen.find(x) != seen.end()) return;
        seen.insert(x);
        sets[seti].push_back(s[x]);
        parentSet[x] = seti;
        auto& children = adjList[x];
        for(auto child : children) {
            dfs(adjList, child, seen, sets, seti, parentSet, s);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<vector<int>> adjList(n);
        for(auto& pair : pairs) {
            adjList[pair[0]].push_back(pair[1]);
            adjList[pair[1]].push_back(pair[0]);
        }
        unordered_set<int> seen;
        vector<string> sets;
        unordered_map<int, int> parentSet;
        int seti = 0;
        for(int i = 0; i < n; i++) {
            if(seen.find(i) == seen.end()) {
                string newSet = "";
                sets.push_back(newSet);
                dfs(adjList, i, seen, sets, seti, parentSet, s);
                seti++;
            }
        }
        int setSize = sets.size();
        vector<int> its(setSize);
        for(auto& thing : sets) {
            sort(thing.begin(), thing.end());
        }
        for(int i = 0; i < n; i++) {
            int j = parentSet[i];      
            s[i]  = sets[j][its[j]++];  
        }
        return s;
    }
};
```

			     
			     
		

<br /> <br /> <br />**[1631. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)**<br />
You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e., **0-indexed**). You can move `up`, `down`, `left`, or `right`, and you wish to find a route that requires the minimum `effort`.<br />
A route's `effort` is the `maximum absolute difference` in heights between two consecutive cells of the route.<br />
Return _the **minimum effort** required to travel from the top-left cell to the bottom-right cell_.<br />
	
>Example 1:<br />
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/10/04/ex1.png"><br />
>Input: heights = [[1,2,2],[3,8,2],[5,3,5]]<br />
>Output: 2<br />
>Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.<br />
>This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.<br />
	
>Example 2:<br />
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/10/04/ex2.png"><br />
>Input: heights = [[1,2,3],[3,8,4],[5,3,5]]<br />
>Output: 1<br />
>Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].<br />
	
>Example 3:<br />
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/10/04/ex3.png"><br />
>Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]<br />
>Output: 0<br />
>Explanation: This route does not require any effort.<br />
	
* Constraints:`rows == heights.length`<br />
`columns == heights[i].length`<br />
`1 <= rows, columns <= 100`<br />
`1 <= heights[i][j] <= 10^6`<br />

```cpp
class Solution {
    vector<vector<int>> dirs = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };
    bool isValid(vector<vector<int>>& heights, int mx) {
        queue<pair<int,int>> q;
        int ROWS = heights.size();
        int COLS = heights[0].size();
        
        vector<vector<bool>> seen(ROWS, vector<bool>(COLS, false));
        q.push({0,0});
        seen[0][0] = true;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;
            if(r == ROWS - 1 && c == COLS - 1) return true;
            for(auto& dir : dirs) {
                int dr = dir[0] + r;
                int dc = dir[1] + c;
                if(dr < 0 || dr >= ROWS) continue;
                if(dc < 0 || dc >= COLS) continue;
                if(seen[dr][dc]) continue;
                if(abs(heights[r][c] - heights[dr][dc]) > mx) continue;
                seen[dr][dc] = true;
                q.push({dr, dc});
            }
        }
        return false;
    }
	
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int L = 0;
        int R = INT_MAX;
        int best = INT_MAX;
        while(L <= R) {
            int M = L + (R-L) / 2;
            if(isValid(heights, M)) {
                R = M - 1;
                best = min(best, M);
            } else L = M + 1;
        } 
        return best;
    }
};
```
		   
		    
		  

<br /> <br /> <br />**[785. Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/)**<br />
There is an **undirected** graph with `n` nodes, where each node is numbered between `0` and `n - 1`. You are given a 2D array `graph`, where `graph[u]` is an array of nodes that node `u` is adjacent to. More formally, for each `v` in `graph[u]`, there is an undirected edge between node `u` and node `v`. The graph has the following properties:<br />
* There are no self-edges (`graph[u]` does not contain `u`).<br />
* There are no parallel edges (`graph[u]` does not contain duplicate values).<br />
* If `v` is in `graph[u]`, then `u` is in `graph[v]` (the graph is undirected).<br />
* The graph may not be connected, meaning there may be two nodes `u` and `v` such that there is no path between them.<br />
A graph is **bipartite** if the nodes can be partitioned into two independent sets `A` and `B` such that **every** edge in the graph connects a node in set `A` and a node in set `B`.<br />
Return `true` _if and only if it is **bipartite**_.<br />
	
>Example 1:<br />
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/10/21/bi2.jpg"><br />
>Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]<br />
>Output: false<br />
>Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.<br />

>Example 2:<br />
><div align="left">
><img src="https://assets.leetcode.com/uploads/2020/10/21/bi1.jpg"><br />
>Input: graph = [[1,3],[0,2],[1,3],[0,2]]<br />
>Output: true<br />
>Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.<br />

* Constraints:`graph.length == n`<br />
`1 <= n <= 100`<br />
`0 <= graph[u].length < n`<br />
`0 <= graph[u][i] <= n - 1`<br />
`graph[u]` does not contain u.<br />
All the values of `graph[u]` are **unique**.<br />
If `graph[u]` contains `v`, then `graph[v]` contains `u`.<br />

```cpp
class Solution {
public:
    vector<int>vis,col;
    bool dfs(int v, int c, vector<vector<int>>& graph){
        vis[v]=1;
        col[v]=c;
        for(int child:graph[v]){
            if(vis[child]==0){
                // here c^1 is for flipping 1 by 0 or 0 by 1, that is flip the current color
                if(dfs(child,c^1,graph)==false)return false; 
            }
            else{
                if(col[v]==col[child])return false;     
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.resize(n);
        col.resize(n);
        for(int i=0;i<n;++i)if(vis[i]==0 && dfs(i,0,graph)==false)return false;
        return true;
    }
};
```

				      
				      
				     
<br /> <br /> <br />**[399. Evaluate Division](https://leetcode.com/problems/evaluate-division/)**<br />
You are given an array of variable pairs `equations` and an array of real numbers `values`, where `equations[i] = [Ai, Bi]` and `values[i]` represent the equation `Ai / Bi = values[i]`. Each `Ai` or `Bi` is a string that represents a single variable.<br />
You are also given some `queries`, where `queries[j] = [Cj, Dj]` represents the `jth` query where you must find the answer for `Cj / Dj = ?`.<br />
Return _the answers to all queries_. If a single answer cannot be determined, return `-1.0`.<br />
**Note:** The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.<br />
	
>Example 1:<br />
>Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]<br />
>Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]<br />
>Explanation: <br />
>Given: a / b = 2.0, b / c = 3.0<br />
>queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?<br />
>return: [6.0, 0.5, -1.0, 1.0, -1.0 ]<br />
	
>Example 2:<br />
>Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]<br />
>Output: [3.75000,0.40000,5.00000,0.20000]<br />
	
>Example 3:<br />
>Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]<br />
>Output: [0.50000,2.00000,-1.00000,-1.00000]<br />
 
* Constraints:`1 <= equations.length <= 20`.<br />
`equations[i].length == 2`<br />
`1 <= Ai.length, Bi.length <= 5`<br />
`values.length == equations.length`<br />
`0.0 < values[i] <= 20.0`<br />
`1 <= queries.length <= 20`<br />
`queries[i].length == 2`<br />
`1 <= Cj.length, Dj.length <= 5`<br />
`Ai`, `Bi`, `Cj`, `Dj` consist of lower case English letters and digits.<br />
	
```cpp
class Solution {
public:
void dfs(string start,string end,map<string,double>& mp,map<string,vector<string>>& graph,double& val,map<string,int>& visited,bool& found){
        visited[start]=1;
        if(found==true)  return ;
        for(auto child:graph[start]){
            if(visited[child]!=1){
                // cout<<start<<" "<<child<<"\n";
                val*=mp[start+"->"+child];
                if(end==child){
                    // cout<<end<<" -- "<<child<<"\n";
                    found=true;
                    return ;
                }
                dfs(child,end,mp,graph,val,visited,found);
                if(found==true)return ;
                else val/=mp[start+"->"+child];
            }
        }  
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        map<string,double> mp;
        map<string,vector<string>> graph;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            mp[u+"->"+v]=values[i];
            mp[v+"->"+u]=1/values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<queries.size();i++){
            string start=queries[i][0];
            string end=queries[i][1];
            if(graph.find(start)==graph.end()||graph.find(end)==graph.end())ans.push_back(-1);
            else{
                // ans.push_back(1);
                double val=1;
                map<string,int> visited;
                bool found=false;
                if(start==end)found=true;
                else dfs(start,end,mp,graph,val,visited,found);
                if(found==true)ans.push_back(val);
                else
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};
```

	
	
	
<br /> <br /> <br />**[581. Shortest Unsorted Continuous Subarray](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)**<br />
Given an integer array `nums`, you need to find one **continuous subarray** that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.<br />
Return _the shortest such subarray_ _and output its length_.<br />

>Example 1:<br />
>Input: nums = [2,6,4,8,10,9,15]<br />
>Output: 5<br />
>Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.<br />
	
>Example 2:<br />
>Input: nums = [1,2,3,4]<br />
>Output: 0<br />
	
>Example 3:<br />
>Input: nums = [1]<br />
>Output: 0<br />
 
Constraints:`1 <= nums.length <= 10^4`<br />
`-10^5 <= nums[i] <= 10^5`<br />
	
```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -1,  max = INT_MIN;
        for(int i=0; i<nums.size();i++){
            if(max>nums[i]){
                if(start == -1)start = i-1;
                while(start-1>=0 && nums[start-1]>nums[i])start--;
                end = i+1;
            }
            else max = nums[i];
        }
        return end - start;   
    }
};
```
	
	
	
	
<br /> <br /> <br />**[1679. Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs/)**<br />
You are given an integer array `nums` and an integer `k`.<br />
In one operation, you can pick two numbers from the array whose sum equals `k` and remove them from the array.<br />
Return the _maximum number of operations you can perform on the array_.<br />
	
>Example 1:<br />
>Input: nums = [1,2,3,4], k = 5<br />
>Output: 2<br />
>Explanation: Starting with nums = [1,2,3,4]:<br />
> - Remove numbers 1 and 4, then nums = [2,3]<br />
> - Remove numbers 2 and 3, then nums = []<br />
>There are no more pairs that sum up to 5, hence a total of 2 operations.<br />
	
>Example 2:<br />
>Input: nums = [3,1,3,4,3], k = 6<br />
>Output: 1<br />
>Explanation: Starting with nums = [3,1,3,4,3]:<br />
> - Remove the first two 3's, then nums = [1,4,3]<br />
>There are no more pairs that sum up to 6, hence a total of 1 operation.<br />

* Constraints:`1 <= nums.length <= 10^5`<br />
`1 <= nums[i] <= 10^9`<br />
`1 <= k <= 10^9`<br />
	
```cpp
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int>a;int c=0;
        for(int i: nums)
            if(a[k-i])a[k-i]--,c++;
            else a[i]++;
        return c;
    }
};
```
	
	


  
  
 <br /> <br /> <br />**[1209. Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)**<br />
You are given a string `s` and an integer `k`, a `k` **duplicate removal** consists of choosing `k` adjacent and equal letters from `s` and removing them, causing the left and the right side of the deleted substring to concatenate together.<br />
We repeatedly make `k` **duplicate removals** on `s` until we no longer can.<br />
Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.<br />

>Example 1:<br />
>Input: s = "abcd", k = 2<br />
>Output: "abcd"<br />
>Explanation: There's nothing to delete.<br />
	
>Example 2:<br />
>Input: s = "deeedbbcccbdaa", k = 3<br />
>Output: "aa"<br />
>Explanation: <br />
>First delete "eee" and "ccc", get "ddbbbdaa"<br />
>Then delete "bbb", get "dddaa"<br />
>Finally delete "ddd", get "aa"<br />
	
>Example 3:<br />
>Input: s = "pbbcggttciiippooaais", k = 2<br />
>Output: "ps"<br />
 
* Constraints: `1 <= s.length <= 10^5`<br />
`2 <= k <= 10^4`<br />
`s` only contains lower case English letters.<br />
	
```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k)return s;
        stack<pair<char,int>> stk;
        for(int i=0; i<n; ++i){
            if(stk.empty() || stk.top().first != s[i]) stk.push({s[i],1});
            else{
                auto prev = stk.top();
                stk.pop();
                stk.push({s[i], prev.second+1});
            }
            if(stk.top().second==k) stk.pop();
        }
        string ans = "";
        while(!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            while(cur.second--){
                ans.push_back(cur.first);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
			  
			  
			  
			 
<br /> <br /> <br />**[456. 132 Pattern](https://leetcode.com/problems/132-pattern/)**<br />
Given an array of `n` integers `nums`, a **132 pattern** is a subsequence of three integers `nums[i]`, `nums[j]` and `nums[k]` such that `i < j < k` and `nums[i] < nums[k] < nums[j]`.<br />
Return `true` if there is a **132 pattern** in `nums`, otherwise, return `false`.<br />

>Example 1:<br />
Input: nums = [1,2,3,4]<br />
Output: false<br />
Explanation: There is no 132 pattern in the sequence.<br />
	
>Example 2:<br />
Input: nums = [3,1,4,2]<br />
Output: true<br />
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].<br />
	
>Example 3:<br />
Input: nums = [-1,3,2,0]<br />
Output: true<br />
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].<br />

* Constraints: `n == nums.length`<br />
`1 <= n <= 2 * 10^5`<br />
`-10^9 <= nums[i] <= 10^9`<br />
	
```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> s;
        int mini = INT_MAX;  
        for(int i = 0;i<nums.size();i++){
            if(s.size()!=0)mini = min(mini,s.top().first);     
            while(s.size()!=0 && nums[i]>s.top().first) s.pop();
            if(s.size()!=0){  
                if((s.top().first > nums[i]) && (nums[i] > s.top().second))return true;
            }
            s.push({nums[i],mini}); 
        }
        return false;
        /*
        other solution
        int s3 = INT_MIN;
        int n = nums.size();
        stack<int>s;
        for(int i = n-1;i>=0;i--){
            if(nums[i]<s3)return true;
            else{
                while(!s.empty() && nums[i]>s.top()){
                    s3 = s.top();
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        return false;
        */
    }
};
```




<br /> <br /> <br />**[341. Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/)**<br />
You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.<br />
Implement the `NestedIterator` class:<br />
* `NestedIterator(List<NestedInteger> nestedList)` Initializes the iterator with the nested list `nestedList`.<br />
* `int next()` Returns the next integer in the nested list.<br />
* `boolean hasNext()` Returns `true` if there are still some integers in the nested list and `false` otherwise.<br />
	
Your code will be tested with the following pseudocode:<br />
<pre>
	initialize iterator with nestedList
	res = []
	while iterator.hasNext()
	    append iterator.next() to the end of res
	return res
</pre>	
	
If `res` matches the expected flattened list, then your code will be judged as correct.<br />
 
>Example 1:<br />
Input: nestedList = [[1,1],2,[1,1]]<br />
Output: [1,1,2,1,1]<br />
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].<br />
	
>Example 2:<br />
Input: nestedList = [1,[4,[6]]]<br />
Output: [1,4,6]<br />
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].<br />
 
* Constraints: `1 <= nestedList.length <= 500`<br />
The values of the integers in the nested list is in the range `[-10^6, 10^6]`.<br />
	
```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> v;
    int pos=0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    
    void flatten(vector<NestedInteger> &nestedList){
        for(auto x : nestedList){
            if(x.isInteger())v.push_back(x.getInteger());
            else flatten(x.getList());  
        }
    }
    
    int next() { return v[pos++]; }
    
    bool hasNext() { return pos < v.size();}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```

				       
				      
				       
<br /> <br /> <br />**[17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)**<br />	
Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.<br />	
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.<br />	

<img src = "https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png">

>Example 1:<br />	
Input: digits = "23"<br />	
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]<br />	
	
>Example 2:<br />	
Input: digits = ""<br />	
Output: []<br />	
	
>Example 3:<br />	
Input: digits = "2"<br />	
Output: ["a","b","c"]<br />	
 
* Constraints: `0 <= digits.length <= 4`<br />	
`digits[i]` is a digit in the range `['2', '9']`.<br />	
	
```cpp
class Solution {
public:
    char letters[3][10] = {{'a', 'a', 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'},
                           {'b', 'b', 'b', 'e', 'h', 'k', 'n', 'q', 'u', 'x'},
                           {'c', 'c', 'c', 'f', 'i', 'l', 'o', 'r', 'v', 'y'}};
    void helper(const string &digits, int index, string &s, vector<string> &result) {
        if (index >= s.size()) {
            return ;
        }
        int digit = digits[index] - '0';
        if (index + 1 == s.size()) {
            for (int i = 0; i < 3; ++i) {
                s[index] = letters[i][digit];
                result.push_back(s);
            }
            if (digit == 7) {
                s[index] = 's';
                result.push_back(s);
            } else if (digit == 9) {
                s[index] = 'z';
                result.push_back(s);
            }
            return ;
        }
        for (int i = 0; i < 3; ++i) {
            s[index] = letters[i][digit];
            helper(digits, index + 1, s, result);
        }
        if (digit == 7) {
            s[index] = 's';
            helper(digits, index + 1, s, result);
        } else if (digit == 9) {
            s[index] = 'z';
            helper(digits, index + 1, s, result);
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return vector<string>();
        string s = digits;
        vector<string> result;
        helper(digits, 0, s, result);
        return result;
    }
};
```

	
	
	
<br /> <br /> <br />**[216. Combination Sum III](https://leetcode.com/problems/combination-sum-iii/)**<br />	
Find all valid combinations of `k` numbers that sum up to `n` such that the following conditions are true:<br />
 - Only numbers `1` through `9` are used.<br />
 - Each number is used **at most once**.<br />
	
Return _a list of all possible valid combinations_. The list must not contain the same combination twice, and the combinations may be returned in any order.<br />

>Example 1:<br />
Input: k = 3, n = 7<br />
Output: [[1,2,4]]<br />
Explanation:<br />
1 + 2 + 4 = 7<br />
There are no other valid combinations.<br />
	
>Example 2:<br />
Input: k = 3, n = 9<br />
Output: [[1,2,6],[1,3,5],[2,3,4]]<br />
Explanation:<br />
1 + 2 + 6 = 9<br />
1 + 3 + 5 = 9<br />
2 + 3 + 4 = 9<br />
There are no other valid combinations.<br />
	
>Example 3:<br />
Input: k = 4, n = 1<br />
Output: []<br />
Explanation: There are no valid combinations.<br />
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.<br />

* Constraints: `2 <= k <= 9`<br />
`1 <= n <= 60`<br />
	
```cpp
class Solution {
public:
    void helper(int st,int k,int n,vector<int> &ds,vector<vector<int>> &ans){
            if(k<=0){
                if(n==0) ans.push_back(ds);
                return;
            }
            for(int i=st;i<=9;i++)    {
                ds.push_back(i);
                helper(i+1,k-1,n-i,ds,ans);
                ds.pop_back();
            }
        }
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>> ans;
            vector<int> ds;
            helper(1,k,n,ds,ans);
            return ans;
        }
    };
```
	
	
<br /> <br /> <br />**[1641. Count Sorted Vowel Strings](https://leetcode.com/problems/count-sorted-vowel-strings/)**<br />	
Given an integer `n`, return _the number of strings of length `n` that consist only of vowels `(a, e, i, o, u)` and are **lexicographically sorted**_.<br />
A string `s` is **lexicographically sorted** if for all valid `i`, `s[i]` is the same as or comes before `s[i+1]` in the alphabet.<br />

>Example 1:<br />
Input: n = 1<br />
Output: 5<br />
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].<br />
	
>Example 2:<br />
Input: n = 2<br />
Output: 15<br />
Explanation: The 15 sorted strings that consist of vowels only are<br />
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].<br />
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.<br />
	
>Example 3:<br />
Input: n = 33<br />
Output: 66045<br />
 
* Constraints: `1 <= n <= 50` <br />
	
```cpp
class Solution {
public:
    int countVowelStrings(int n) {
        string vowels= "aeiou";
		vector<vector<int>> dp(5, vector<int>(n+1)); 
		for(int i=0; i<5; ++i) dp[i][0]= 1; 
		for(int i=4; i>=0; --i){
		  for(int j=1; j<=n; ++j){
			int pick= 0, notPick= 0;
			pick= dp[i][j-1];
			if(i<4) notPick= dp[i+1][j];
			dp[i][j]= pick+notPick;
		  }
		}
		return dp[0][n]; 
    }
};
```

	
	
	
<br /> <br /> <br />**[47. Permutations II](https://leetcode.com/problems/permutations-ii/)**<br />
Given a collection of numbers, `nums`, that might contain duplicates, return _all possible unique permutations **in any order**_.<br />

>Example 1:<br />
>Input: nums = [1,1,2]<br />
>Output:<br />
>[[1,1,2],<br />
> [1,2,1],<br />
> [2,1,1]]<br />
	
>Example 2:<br />
>Input: nums = [1,2,3]<br />
>Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]<br />

* Constraints: `1 <= nums.length <= 8`<br />
`-10 <= nums[i] <= 10`<br />
	
```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        ans.push_back(nums);
        while(next_permutation(nums.begin(),nums.end()))
            ans.push_back(nums);
        return ans;
    }
};
```
	
	
	
	
	
	
<br /> <br /> <br />**[743. Network Delay Time](https://leetcode.com/problems/network-delay-time/)**<br />
You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of travel times as directed edges `times[i] = (ui, vi, wi)`, where `ui` is the source node, `vi` is the target node, and `wi` is the time it takes for a signal to travel from source to target.<br /><br />
We will send a signal from a given node `k`. Return the time it takes for all the `n` nodes to receive the signal. If it is impossible for all the `n` nodes to receive the signal, return `-1`.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png"><br />
>Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2<br />
>Output: 2<br />
	
>Example 2:<br />
>Input: times = [[1,2,1]], n = 2, k = 1<br />
>Output: 1<br />
	
>Example 3:<br />
>Input: times = [[1,2,1]], n = 2, k = 2<br />
>Output: -1<br />
 
* Constraints: `1 <= k <= n <= 100`<br />
`1 <= times.length <= 6000`<br />
`times[i].length == 3`<br />
`1 <= ui, vi <= n`<br />
`ui != vi`<br />
`0 <= wi <= 100`<br />
All the pairs `(ui, vi)` are **unique**. (i.e., no multiple edges.)<br />
	     
```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> vec(n+1);
        for(int i=0;i<times.size();i++){
           int j = times[i][0];
           vec[j].push_back({times[i][1],times[i][2]}); 
        }
        vector<int> signal(n+1,INT_MAX);
        queue<int> q;
        q.push(k);   
        signal[k] = 0;
        while (!q.empty()) {
            int currNode = q.front(); 
            q.pop();       
            for (pair<int,int> p : vec[currNode]) {                
                int time = p.second;
                int neighbor = p.first;
                int arrival = signal[currNode] + time;
                if (signal[neighbor] > arrival) {
                    signal[neighbor] = arrival;
                    q.push(neighbor);
                }
            }
        }
        int maxi = 0;
        for(int i =1;i<=n;i++){   
            if(signal[i]==INT_MAX)return -1;
            maxi = max(maxi,signal[i]);
        }
        return maxi;
    }
};
```

			       
			       
			       
			       
<br /> <br /> <br />**[1302. Deepest Leaves Sum](https://leetcode.com/problems/deepest-leaves-sum/)**<br />
Given the `root` of a binary tree, return _the sum of values of its deepest leaves_.<br />
 
>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2019/07/31/1483_ex1.png"><br />
>Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]<br />
>Output: 15<br />

>Example 2:<br />
>Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]<br />
>Output: 19<br />

* Constraints: The number of nodes in the tree is in the range `[1, 10^4]`.<br />
`1 <= Node.val <= 100`<br />
	
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
    int deepestLeavesSum(TreeNode* root) {
        // making queue for doing the level order traversal (BFS)
        queue<TreeNode*> q;
        q.push(root);
        // it is our final ans var that will store the leaves sum
        int ans = 0;
        // Applying BFS
        while(!q.empty()){
            int size = q.size();       // level size
            int sum = 0;               // it is sum that will store the sum for each level
            // just calculating the level sum 
            // and push new level in our queue
            for(int i=0;i<size;i++){
                TreeNode* top = q.front();
                q.pop();
                
                // add up the node val
                sum += top->val;
                
                // pushing the nodes for next level
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            // just updating our main ans with current level sum
            // logically at the last we have our last level sum in our ans that is nothing but our leaves sum
            ans = sum;
        }
        return ans;
    }
};
```
	

	
	
	
<br /> <br /> <br />**[1091. Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)**<br />
Given an `n x n` binary matrix `grid`, return _the length of the shortest **clear path** in the matrix_. If there is no clear path, return `-1`.<br />
A **clear path** in a binary matrix is a path from the **top-left cell** (i.e., `(0, 0)`) to the **bottom-right** cell (i.e., `(n - 1, n - 1)`) such that:<br />
 * All the visited cells of the path are `0`.<br />
 * All the adjacent cells of the path are **8-directionally** connected (i.e., they are different and they share an edge or a corner).<br />
The **length of a clear path** is the number of visited cells of this path.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/02/18/example1_1.png"><br />
Input: grid = [[0,1],[1,0]]<br />
Output: 2<br />
	
>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2021/02/18/example2_1.png"><br />
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]<br />
Output: 4<br />
	
>Example 3:<br />
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]<br />
Output: -1<br />
 

* Constraints: `n == grid.length`<br />
`n == grid[i].length`<br />
`1 <= n <= 100`<br />
`grid[i][j] is 0 or 1`<br />	
	
```cpp
/*Use BFS approach to find shortest path like we solve for graph problems. You can think of adjacent cells with value = 0 having an undirected edge between them.
Apply BFS and update counter at everly level.
To track levels I have used nodesPushed. It is equal to number of nodes in current level.
If you are able to reach (n-1, n-1) return its level otherwise return -1.
Little Optimization : Rather than keeping visited vector, after we have pushed a node in the queue make its value in grid equal to 1. This would make it unavailable to process next time we encounter it. However this method will corrupt the memory.
DP will not work here because the way we traverse the matrix in DP will not lead to formulation of correct solution or rather the optimal path. However, BFS will lead to an optimal path.
We can also get our answer by DFS but it would be computationaly more expensive and might give TLE on large inputs.*/
class Solution {
public:
    
    bool isValid(vector<vector<int>>& grid, int i, int j, int n, vector<vector<bool>>& visited){
        
        return (i>=0 and i<n and j>=0 and j<n and grid[i][j]==0 and !visited[i][j]);
        
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        queue<pair<int, int>> q;
        int ans = 0;
        int nodesPushed;
        
        if(grid[0][0] == 0){
            q.push({0, 0});
            visited[0][0] = true;
        }
                
        while(!q.empty()){
            
            nodesPushed = q.size();
            ans++;
            
            for(int cnt = 0; cnt < nodesPushed; cnt++){
                
                pair<int, int> frontNode = q.front();
                q.pop();
            
                int i = frontNode.first, j = frontNode.second;

                if(i==n-1 and j==n-1) return ans;

                for(int k = i - 1; k <= i + 1 ; k++){
                    for(int l = j - 1; l <= j + 1; l++){
                        if(isValid(grid, k, l, n, visited)){
                            q.push({k, l});
                            visited[k][l] = true;
                        }
                    }
                }                
                
            }            
            
        }
        
        return -1;
        
    }
};
```
	
	
	
<br /> <br /> <br />**[63. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)**<br />
You are given an `m x n` integer array `grid`. There is a robot initially located at the **top-left corner** (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner** (i.e., `grid[m-1][n-1]`). The robot can only move either down or right at any point in time.<br />
An obstacle and space are marked as `1` or `0` respectively in `grid`. A path that the robot takes cannot include **any** square that is an obstacle.<br />
Return _the number of possible unique paths that the robot can take to reach the bottom-right corner._<br />
The testcases are generated so that the answer will be less than or equal to `2 * 10^9`.<br />
	
>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg"><br />
>Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]<br />
>Output: 2<br />
>Explanation: There is one obstacle in the middle of the 3x3 grid above.<br />
>There are two ways to reach the bottom-right corner:<br />
>1. Right -> Right -> Down -> Down<br />
>2. Down -> Down -> Right -> Right<br />
	
>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg"><br />
Input: obstacleGrid = [[0,1],[0,0]]<br />
Output: 1<br />

* Constraints: `m == obstacleGrid.length`<br />
`n == obstacleGrid[i].length`<br />
`1 <= m, n <= 100`<br />
`obstacleGrid[i][j]` is `0` or `1`.<br />

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
				//2 way is possible go right or down
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};
```
	
	
	
<br /> <br /> <br />**[322. Coin Change](https://leetcode.com/problems/coin-change/)**<br />
You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.<br />
Return _the fewest number of coins that you need to make up that amount_. If that amount of money cannot be made up by any combination of the coins, return `-1`.<br />
You may assume that you have an infinite number of each kind of coin.<br />

>Example 1:<br />
Input: coins = [1,2,5], amount = 11<br />
Output: 3<br />
Explanation: 11 = 5 + 5 + 1<br />
	
>Example 2:<br />
Input: coins = [2], amount = 3<br />
Output: -1<br />
	
>Example 3:<br />
Input: coins = [1], amount = 0<br />
Output: 0<br />

* Constraints: `1 <= coins.length <= 12`<br />
`1 <= coins[i] <= 2^31 - 1`<br />
`0 <= amount <= 10^4`<br />
	
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        //dp with coins as rows and amount as columns
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        
        for(int i = 0; i <= coins.size(); i++){
            for(int j = 0; j <= amount; j++){
                
                if(j == 0)
                    dp[i][j] = 0;
                
                else if(i == 0)
                    dp[i][j] = 1e5;
                
                else if(coins[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                
                else
                    dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i - 1][j]);
            }
        }
        
        int ans = dp[coins.size()][amount];
        
        if(ans > 1e4)
            return -1;
        
        else
            return ans;
    }
};
```
	
<br /> <br /> <br />**[647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)**<br />
Given a string `s`, return _the number of **palindromic substrings** in it_.<br />
A string is a **palindrome** when it reads the same backward as forward.<br />
A **substring** is a contiguous sequence of characters within the string.<br />

>Example 1:<br />
Input: s = "abc"<br />
Output: 3<br />
Explanation: Three palindromic strings: "a", "b", "c".<br />
	
>Example 2:<br />
Input: s = "aaa"<br />
Output: 6<br />
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".<br />
 
* Constraints: `1 <= s.length <= 1000`<br />
`s` consists of lowercase English letters.<br />

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int ans = 0;
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                if(len==1) dp[i][i] = 1;
                else if(len==2){
                    if(s[i]==s[i+1]) dp[i][i+1] = 1;
                    else dp[i][i+1] = 0;
                }
                else if(s[i]==s[i+len-1] && dp[i+1][i+len-2]>0) dp[i][i+len-1] = 1;
                else dp[i][i+len-1] = 0;
                ans += dp[i][i+len-1];
            }
        }
        return ans;
    }
};
```
	
	
	
<br /> <br /> <br />**[474. Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/)**<br />
You are given an array of binary strings `strs` and two integers `m` and `n`.<br />
Return _the size of the largest subset of `strs` such that there are **at most** `m` `0's` and `n` `1's` in the subset_.<br />
A set `x` is a **subset** of a set `y` if all elements of `x` are also elements of `y`.<br />

>Example 1:<br />
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3<br />
Output: 4<br />
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.<br />
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.<br />
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.<br />

>Example 2:<br />
Input: strs = ["10","0","1"], m = 1, n = 1<br />
Output: 2<br />
Explanation: The largest subset is {"0", "1"}, so the answer is 2.<br />
 
* Constraints: `1 <= strs.length <= 600`<br />
`1 <= strs[i].length <= 100`<br />
`strs[i]` consists only of digits `'0'` and `'1'`.<br />
`1 <= m, n <= 100`<br />

```cpp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for(auto& s : strs) { 
            
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size();
            
            for(int i = m; i >= zeros; i--) 
                for(int j = n; j >= (ones - zeros); j--) 
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones + zeros]);
        }
        
        return dp[m][n];
    }
};
```





<br /> <br /> <br />**[318. Maximum Product of Word Lengths](https://leetcode.com/problems/maximum-product-of-word-lengths/)**<br />
Given a string array `words`, return _the maximum value of `length(word[i]) * length(word[j])` where the two words do not share common letters_. If no such two words exist, return `0`.<br />

>Example 1:<br />
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]<br />
Output: 16<br />
Explanation: The two words can be "abcw", "xtfn".<br />
	
>Example 2:<br />
Input: words = ["a","ab","abc","d","cd","bcd","abcd"]<br />
Output: 4<br />
Explanation: The two words can be "ab", "cd".<br />
	
>Example 3:<br />
Input: words = ["a","aa","aaa","aaaa"]<br />
Output: 0<br />
Explanation: No such pair of words.<br />
 
* Constraints: `2 <= words.length <= 1000`<br />
`1 <= words[i].length <= 1000`<br />
`words[i]` consists only of lowercase English letters.<br />
	
```cpp
class Solution {
public:
     
    int maxProduct(vector<string>& words) {
        int ans=0;
        vector<vector<int>>dp(words.size(),vector<int>(26));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                dp[i][words[i][j]-'a']++;
            }
        }
        
                    
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){   
                bool iscommon=true;
                for(int k=0;k<26;k++){
                    if(dp[i][k]>0 && dp[j][k]>0){
                        iscommon=false;
                    }
                }
                if(iscommon){
                    int cur=words[i].size()*words[j].size();
                    ans=max(ans,cur);
                }
            }
        }
    
        return ans;
    }
};
	
	
/*Using Bitset/HashMap
Time Complexity : O(n*n) , where n is the length of words
Space Complexity :O(n)
*/
class Solution {
public:
    bool checkCommon(bitset<26> &a, bitset<26> &b){ // function to check if two bitset are common
        for(int i=0;i<26;i++) if(a[i] && b[i]) return true; // if any of the bits are true, return true
        return false; // otherwise return false
    }
    int maxProduct(vector<string>& words) { // function to find the maximum product
        int n = words.size(); // number of words
        int ans=0; // initialize the answer
        vector<bitset<26>> chars(n); // vector of bitset
        for(int i=0;i<n;i++){ // iterate over all the words 
            for(auto &ch:words[i]) // iterate over all the characters in the words[i]
                chars[i][ch-'a'] =1; // set the bitset to 1
            for(int j=0;j<i;j++) // now check with all the other words
                if(!checkCommon(chars[i],chars[j])) // if the two words are not common
                    ans = max(ans, (int)words[i].size()*(int)words[j].size()); // update the answer
        }
        return ans; // return the answer
    }
};



/*Using BitMasking 
Time Complexity : O(n*n)
Space Complexity :O(n)
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {     // function to get the max product of two words
	int n = words.size(), ans = 0;       // n is the number of words and ans is the max product
	vector<int> mask(n);               // mask is the vector of bit masks
	for(int i = 0; i < n; i++) {      // loop to get the bit mask of each word
		for(auto& ch : words[i])     // for each character in the word          
			mask[i] |= 1 << (ch - 'a');   // hash the word
		for(int j = 0; j < i; j++) // loop to check if the word is a subset of another word
			if((mask[i] & mask[j]) == 0)    // if no common set bit is found in the hash of words[i] and words[j]
				ans = max(ans, int(size(words[i]) * size(words[j]))); // update the max product
	}    
	return ans; // return the max product
}
};

```

	
	
	
	
	
	
<br /> <br /> <br />**[29. Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)**<br />
Given two integers `dividend` and `divisor`, divide two integers **without** using multiplication, division, and mod operator.<br />
The integer division should truncate toward zero, which means losing its fractional part. For example, `8.345` would be truncated to `8`, and `-2.7335` would be truncated to `-2`.<br />
Return _the **quotient** after dividing `dividend` by `divisor`_.<br />
**Note**: Assume we are dealing with an environment that could only store integers within the **32-bit** signed integer range: `[−2^31, 2^31 − 1]`. For this problem, if the quotient is **strictly greater than** `2^31 - 1`, then return `2^31 - 1`, and if the quotient is **strictly less than** `-2^31`, then return `-2^31`.<br />

>Example 1:<br />
Input: dividend = 10, divisor = 3<br />
Output: 3<br />
Explanation: 10/3 = 3.33333.. which is truncated to 3.<br />
	
>Example 2:<br />
Input: dividend = 7, divisor = -3<br />
Output: -2<br />
Explanation: 7/-3 = -2.33333.. which is truncated to -2.<br />
 
* Constraints: `-2^31 <= dividend, divisor <= 2^31 - 1`<br />
`divisor != 0`<br />
	
```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dividend_long = labs(dividend), divisor_long = labs(divisor), res = 0;
        /*
        The labs() function in C++ returns the absolute value of a long or long int data.
        The labs() function can be thought as the long int version of abs(). 
        It is defined in <cstdlib> header file.
        */
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        while (dividend_long >= divisor_long) {
            long step = 1;
            long tmp = divisor_long;
            while (dividend_long >= tmp) {
                res += step;
                dividend_long -= tmp;
                step <<= 1;
                tmp <<= 1;
            }
        }
        res *= sign;
        return res > INT_MAX ? INT_MAX : res;
    }
};
```
	
	
	
	
	
	
<br /> <br /> <br />**[1461. Check If a String Contains All Binary Codes of Size K](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)**<br />
Given a binary string `s` and an integer `k`, return `true` _if every binary code of length `k` is a substring of `s`_. Otherwise, return `false`.<br />

>Example 1:<br />
Input: s = "00110110", k = 2<br />
Output: true<br />
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.<br />

>Example 2:<br />
Input: s = "0110", k = 1<br />
Output: true<br />
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. <br />

>Example 3:<br />
Input: s = "0110", k = 2<br />
Output: false<br />
Explanation: The binary code "00" is of length 2 and does not exist in the array.<br />
 
* Constraints: 1 <= s.length <= `5 * 10^5`<br />
`s[i]` is either '`0`' or '`1`'.<br />
`1 <= k <= 20`<br />
	
```cpp
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)return false;
        unordered_set<string>sol;
        for(int i = 0;i<=s.size()-k;i++)sol.insert(s.substr(i, k));
        return sol.size() == pow(2, k);
    }
};
```

							      
							      
							      
							
<br /> <br /> <br />**[142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)**<br />
Given the `head` of a linked list, return _the node where the cycle begins. If there is no cycle, return `null`_.<br />
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to (**0-indexed**). It is `-1` if there is no cycle. **Note that** `pos` **is not passed as a parameter**``.<br />
Do **not modify** the linked list.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png"><br />
Input: head = [3,2,0,-4], pos = 1<br />
Output: tail connects to node index 1<br />
Explanation: There is a cycle in the linked list, where tail connects to the second node.<br />

>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png"><br />
Input: head = [1,2], pos = 0<br />
Output: tail connects to node index 0<br />
Explanation: There is a cycle in the linked list, where tail connects to the first node.<br />

>Example 3:<br />
<img src = "https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png"><br />
Input: head = [1], pos = -1<br />
Output: no cycle<br />
Explanation: There is no cycle in the linked list.<br />

* Constraints: The number of the nodes in the list is in the range `[0, 10^4]`.<br />
`-10^5 <= Node.val <= 10^5`<br />
`pos` is `-1` or a **valid index** in the linked-list.<br />
	
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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        
        ListNode *slow=head,*fast=head;
        do{
            slow = slow->next;
            if(!slow) break;
            fast= fast->next;
            if(!fast) break;
            fast = fast->next;
            if(!fast) break;            
            
        }while(slow!=fast);
        if(!slow or !fast)
            return NULL;
        fast = head;
        while(fast !=slow)
            fast=fast->next, slow=slow->next;
        return fast;
    }
};
```

	
	
	
<br /> <br /> <br />**[304. Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/)**<br />	
Given a 2D matrix `matrix`, handle multiple queries of the following type:<br />
 * Calculate the **sum** of the elements of `matrix` inside the rectangle defined by its **upper left corner** `(row1, col1)` and **lower right corner** `(row2, col2)`.<br />
	
Implement the `NumMatrix` class:<br />
	
 * `NumMatrix(int[][] matrix)` Initializes the object with the integer matrix `matrix`.<br />
 * `int sumRegion(int row1, int col1, int row2, int col2)` Returns the **sum** of the elements of `matrix` inside the rectangle defined by its **upper left corner** `(row1, col1)` and **lower right corner** `(row2, col2)`.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/03/14/sum-grid.jpg"><br />
<pre>
Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
</pre><br />

* Constraints: `m == matrix.length`<br />
`n == matrix[i].length`<br />
`1 <= m, n <= 200`<br />
`-10^5 <= matrix[i][j] <= 10^5`<br />
`-10^9 <= sum(matrix[i][j]) <= 10^9`<br />
`0 <= row1 <= row2 < m`<br />
`0 <= col1 <= col2 < n`<br />
At most `10^4` calls will be made to `sumRegion`.<br />
	
```cpp
class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        sum = vector<vector<int>>(m + 1, vector<int>(n + 1)); // sum[i][j] is sum of all elements inside the rectangle [0,0,i,j]
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int r1, int c1, int r2, int c2) {
		// Since our `sum` starts by 1 so we need to increase r1, c1, r2, c2 by 1
        r1++; c1++; r2++; c2++; 
        return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```
	
	
	
<br /> <br /> <br />**[8. String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)**<br />
Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer (similar to C/C++'s `atoi` function).<br />
The algorithm for `myAtoi(string s)` is as follows:<br />

 1. Read in and ignore any leading whitespace.<br />
 2. Check if the next character (if not already at the end of the string) is `'-'` or `'+'`. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.<br />
 3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.<br />
 4. Convert these digits into an integer (i.e. `"123" -> 123`, `"0032" -> 32`). If no digits were read, then the integer is `0`. Change the sign as necessary (from step 2).<br />
 5. If the integer is out of the 32-bit signed integer range `[-2^31, 2^31 - 1]`, then clamp the integer so that it remains in the range. Specifically, integers less than `-2^31` should be clamped to `-2^31`, and integers greater than `2^31 - 1` should be clamped to `2^31 - 1`.<br />
 6. Return the integer as the final result.<br />

**Note:**<br />
 * Only the space character `' '` is considered a whitespace character.<br />
 * **Do not ignore** any characters other than the leading whitespace or the rest of the string after the digits.<br />
 
>Example 1:<br />
Input: s = "42"<br />
Output: 42<br />
Explanation: The underlined characters are what is read in, the caret is the current reader position.
<pre>
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-2^31, 2^31 - 1], the final result is 42.
</pre>
	
>Example 2:<br />
Input: s = "   -42"<br />
Output: -42<br />
Explanation:<br />
<pre>
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-2^31, 2^31 - 1], the final result is -42.
</pre>
	
>Example 3:<br />
Input: s = "4193 with words"<br />
Output: 4193<br />
Explanation:<br />
<pre>
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-2^31, 2^31 - 1], the final result is 4193.
</pre>

* Constraints: `0 <= s.length <= 200`<br />
`s` consists of English letters (lower-case and upper-case), digits (`0-9`), `' '`, `'+'`, `'-'`, and `'.'`.<br />
	
```cpp
class Solution {
    public:
        int myAtoi(string s) {
            if(s.length() == 0){
                return 0;
            }
            int i = 0;

            while(s[i] == ' '){
                i++;
            }
            bool isPositive = true;
            if(s[i] == '-' || s[i] == '+'){
                isPositive = (s[i] == '+' ? true : false);
                i++;
            }
            if(s[i] - '0' < 0 || s[i] - '0' > 9){
                return 0;
            }
            int num = 0;

            while(s[i] >= '0' && s[i] <= '9'){
                if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i] - '0' > 7)){
                    return isPositive ? INT_MAX : INT_MIN;
                }

                num = num*10 + (s[i] - '0');
                i++;
           }   
           return isPositive ? num : num*-1;
        }
    };
```

	
	
	
<br /> <br /> <br />**[1658. Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)**<br />
You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this **modifies** the array for future operations.<br />
Return _the **minimum number** of operations to reduce `x` to **exactly** `0` if it is possible, otherwise, return `-1`_.

>Example 1:<br />
Input: nums = [1,1,4,2,3], x = 5<br />
Output: 2<br />
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.<br />

>Example 2:<br />
Input: nums = [5,6,7,8,9], x = 4<br />
Output: -1<br />
	
>Example 3:<br />
Input: nums = [3,2,20,1,1,3], x = 10<br />
Output: 5<br />
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.<br />
 
* Constraints: `1 <= nums.length <= 10^5`<br />
`1 <= nums[i] <= 10^4`<br />
`1 <= x <= 10^9`<br />
	
```cpp
class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for (int i : nums) sum += i;
        int target = sum - x;
        int curr_sum = 0, max_len = 0;
        int start_idx = 0;
        bool found = false;
        for (int end_idx = 0; end_idx < n; end_idx++) {
            curr_sum += nums[end_idx];
            while (start_idx <= end_idx && curr_sum > target) {
                curr_sum -= nums[start_idx];
                start_idx += 1;
            }
            if (curr_sum == target) {
                found = true;
                max_len = max(max_len, end_idx - start_idx + 1);
            }
        }
        return found ? n - max_len : -1;
    }
};
```

	
	

<br /> <br /> <br />**[1695. Maximum Erasure Value](https://leetcode.com/problems/maximum-erasure-value/)**<br />
You are given an array of positive integers `nums` and want to erase a subarray containing **unique elements**. The **score** you get by erasing the subarray is equal to the **sum** of its elements.<br />
Return _the **maximum score** you can get by erasing **exactly one** subarray_.<br />
An array `b` is called to be a subarray of `a` if it forms a contiguous subsequence of `a`, that is, if it is equal to `a[l],a[l+1],...,a[r]` for some `(l,r)`.<br />

>Example 1:<br />
Input: nums = [4,2,4,5,6]<br />
Output: 17<br />
Explanation: The optimal subarray here is [2,4,5,6].<br />

>Example 2:<br />
Input: nums = [5,2,1,2,5,2,1,2,5]<br />
Output: 8<br />
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].<br />
	
* Constraints: `1 <= nums.length <= 10^5`<br />
`1 <= nums[i] <= 10^4`<br />
	
```cpp
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int curr_sum=0, res=0;
		
		//set to store the elements
        unordered_set<int> st;
        
        int i=0,j=0;
        while(j<nums.size()) {
            while(st.count(nums[j])>0) {
				//Removing the ith element untill we reach the repeating element
                st.erase(nums[i]);
                curr_sum-=nums[i];
                i++;
            }
			//Add the current element to set and curr_sum value
            curr_sum+=nums[j];
            st.insert(nums[j++]);
			
			//res variable to keep track of largest curr_sum encountered till now...
            res = max(res, curr_sum);
        }
        
        return res;
    }
};
```

	
	
	
<br /> <br /> <br />**[583. Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/)**<br />
Given two strings `word1` and `word2`, return _the minimum number of **steps** required to make `word1` and `word2` the same_.<br />
In one **step**, you can delete exactly one character in either string.<br />

>Example 1:<br />
Input: word1 = "sea", word2 = "eat"<br />
Output: 2<br />
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".<br />

>Example 2:<br />
Input: word1 = "leetcode", word2 = "etco"<br />
Output: 4<br />
 
* Constraints: `1 <= word1.length, word2.length <= 500`<br />
`word1` and `word2` consist of only lowercase English letters.<br />
	
```cpp
class Solution {
public:
    int operation(string &word1, string &word2,int i,int j,int l1,int l2, vector<vector<int>>&dp){
        if(i==l1 && j==l2)return 0;            
        if(i==l1 || j==l2)return max(l1-i,l2-j);
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j])return dp[i][j] = operation(word1,word2,i+1,j+1,l1,l2,dp);
        return dp[i][j] = 1 + min(operation(word1,word2,i,j+1,l1,l2,dp),operation(word1,word2,i+1,j,l1,l2,dp));
    }
    int minDistance(string word1, string word2) {
        int l1 = word1.length(),l2 = word2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
        return operation(word1,word2,0,0,l1,l2,dp);
    }
};
```

	
	
	
	
	
<br /> <br /> <br />**[1048. Longest String Chain](https://leetcode.com/problems/longest-string-chain/)**<br />
You are given an array of `words` where each word consists of lowercase English letters.<br />
`wordA` is a **predecessor** of `wordB` if and only if we can insert **exactly one** letter anywhere in `wordA` **without changing the order of the other characters** to make it equal to `wordB`.<br />
 * For example, `"abc"` is a **predecessor** of `"abac"`, while `"cba"` is not a **predecessor** of `"bcad"`.<br />
	
A **word chain** is a sequence of words `[word1, word2, ..., wordk]` with `k >= 1`, where `word1` is a **predecessor** of `word2`, `word2` is a **predecessor** of `word3`, and so on. A single word is trivially a **word chain** with `k == 1`.<br />
Return _the **length** of the **longest possible word chain** with words chosen from the given list of_ `words`.<br />
	
>Example 1:<br />
Input: words = ["a","b","ba","bca","bda","bdca"]<br />
Output: 4<br />
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].<br />

>Example 2:<br />
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]<br />
Output: 5<br />
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].<br />

>Example 3:<br />
Input: words = ["abcd","dbqca"]<br />
Output: 1<br />
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.<br />
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.<br />
 
* Constraints: `1 <= words.length <= 1000`<br />
`1 <= words[i].length <= 16`<br />
`words[i]` only consists of lowercase English letters.<br />
	
```cpp
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const std::string& first, const std::string& second){
            return first.size() < second.size();
        });
        map<string,int> m;
        int res = 0;
        for(string word:words){
            int longest =0;
            for(int i = 0;i<word.length();i++){
                string sub = word.substr(0,i) + word.substr(i+1,word.length()+1);
                longest = max(longest,m[sub]+1);   
            }        
            m[word] = longest;
            res = max(res,longest);
        }
        return res;
    }
};
```

						
						
						
						
						
<br /> <br /> <br />**[5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)**<br />
Given a string `s`, return _the longest palindromic substring in_ `s`.<br />

>Example 1:<br />
Input: s = "babad"<br />
Output: "bab"<br />
Explanation: "aba" is also a valid answer.<br />

>Example 2:<br />
Input: s = "cbbd"<br />
Output: "bb"<br />
	
* Constraints: `1 <= s.length <= 1000`<br />
`s` consist of only digits and English letters.<br />
	
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();        
        if(n<=1) return s;
        
        // table[i][j] represents whether string i to j is a palindrome or NOT
        
        bool table[n][n];
        memset(table,false,sizeof(table));
        // Base condition => Single letter is always a palindrome
        for(int i=0;i<n;i++)table[i][i]=true;       
        // ex. str => Asome_palindromeA
        //              i................j
        //  if str[i]==str[j] and string i+1 to j-1 is
        //    pallindrome then str i to j is palindrome  
        
        // if len of str is 2 then
        // str[i+1]==[i] is condition for str to be pall...
        // Example  str=> C.C 
        //                i.i+1
        
        int start =0;
        int maxLen=1;
        
        for(int i=0;i<n;i++){
            if(s[i]==s[i+1]){
                start=i;
                maxLen=2;
                table[i][i+1]=true;
            }
        }
        
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(s[i]==s[j] && table[i+1][j-1]==true){
                    table[i][j]=true;
                    start=i;
                    if(maxLen<j-i+1)
                        maxLen=j-i+1;
                }
            }
        }
               
        return s.substr(start,maxLen);
        
    }
};
```
	
	
	
	
<br /> <br /> <br />**[1268. Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/)**<br />
You are given an array of strings `products` and a string `searchWord`.<br />
Design a system that suggests at most three product names from `products` after each character of `searchWord` is typed. Suggested products should have common prefix with `searchWord`. If there are more than three products with a common prefix return the three lexicographically minimums products.<br />
Return _a list of lists of the suggested products after each character of `searchWord` is typed_.<br />

>Example 1:<br />
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"<br />
Output: [<br />
["mobile","moneypot","monitor"],<br />
["mobile","moneypot","monitor"],<br />
["mouse","mousepad"],<br />
["mouse","mousepad"],<br />
["mouse","mousepad"]<br />
]<br />
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]<br />
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]<br />
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]<br />

>Example 2:<br />
Input: products = ["havana"], searchWord = "havana"<br />
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]<br />

>Example 3:<br />
Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"<br />
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]<br />
 
* Constraints: `1 <= products.length <= 1000`<br />
`1 <= products[i].length <= 3000`<br />
`1 <= sum(products[i].length) <= 2 * 10^4`<br />
All the strings of `products` are **unique**.<br />
`products[i]` consists of lowercase English letters.<br />
`1 <= searchWord.length <= 1000`<br />
`searchWord` consists of lowercase English letters.<br />
	
```cpp
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int l=0,r=products.size()-1;
        vector<vector<string>> ans;
        for(int i=0;i<searchWord.size();i++){
            char ch=searchWord[i];
            vector<string>temp;
            while(l<=r && products[l][i]!=ch)
                l++;
            while(l<=r && products[r][i]!=ch)
                r--;
            for(int j=l;j<l+min(3,r-l+1);j++)
                temp.push_back(products[j]);
            ans.push_back(temp);
        }
        return ans;
    }  
};
```

					      
					      
					      
					     
<br /> <br /> <br />**[820. Short Encoding of Words](https://leetcode.com/problems/short-encoding-of-words/)**<br />
A **valid encoding** of an array of `words` is any reference string `s` and array of indices `indices` such that:<br />
	
 * `words.length == indices.length`<br />
 * The reference string s ends with the `'#'` character.<br />
 * For each index `indices[i]`, the **substring** of `s` starting from `indices[i]` and up to (but not including) the next `'#'` character is equal to `words[i]`.<br />
	
Given an array of `words`, return _the **length of the shortest reference string** `s` possible of any **valid encoding** of_ `words`.<br />

>Example 1:<br />
Input: words = ["time", "me", "bell"]<br />
Output: 10<br />
Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].<br />
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"<br />
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"<br />
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"<br />

>Example 2:<br />
Input: words = ["t"]<br />
Output: 2<br />
Explanation: A valid encoding would be s = "t#" and indices = [0].<br />
 
* Constraints: `1 <= words.length <= 2000`<br />
`1 <= words[i].length <= 7`<br />
`words[i]` consists of only lowercase letters.<br />

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        string ans;
        sort(words.begin(),words.end(),[](string &a,string &b){return a.size() > b.size();});
        for(string &s:words)
            if(ans.find(s + "#") == string::npos) ans += s + "#";
        return ans.size();
    }
};
	
// C++ program to demonstrate the use
// of string::npos
#include <bits/stdc++.h>
using namespace std;

// Function that using string::npos
// to find the index of the occurrence
// of any string in the given string
void fun(string s1, string s2)
{
	// Find position of string s2
	int found = s1.find(s2);

	// Check if position is -1 or not
	if (found != string::npos) {

		cout << "first " << s2
			<< " found at: "
			<< (found) << endl;
	}

	else
		cout << s2 << " is not in"
			<< "the string" << endl;
}

// Driver Code
int main()
{
	// Given strings
	string s1 = "geeksforgeeks";
	string s2 = "for";
	string s3 = "no";

	// Function Call
	fun(s1, s2);

	return 0;
}
```

	
	
	
	
	
<br /> <br /> <br />**[1642. Furthest Building You Can Reach](https://leetcode.com/problems/furthest-building-you-can-reach/)**<br />
You are given an integer array `heights` representing the heights of buildings, some `bricks`, and some `ladders`.<br />
You start your journey from building 0 and move to the next building by possibly using bricks or ladders.<br />
While moving from building `i` to building `i+1` (**0-indexed**),<br />

 * If the current building's height is **greater than or equal** to the next building's height, you do **not** need a ladder or bricks.<br />
 * If the current building's height is **less than** the next building's height, you can either use **one ladder** or `(h[i+1] - h[i])` **bricks**.<br />

Return _the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally_.<br />
	
>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/10/27/q4.gif"><br />
Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1<br />
Output: 4<br />
Explanation: Starting at building 0, you can follow these steps:<br />
- Go to building 1 without using ladders nor bricks since 4 >= 2.<br />
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.<br />
- Go to building 3 without using ladders nor bricks since 7 >= 6.<br />
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.<br />
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.<br />
											       
>Example 2:<br />
Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2<br />
Output: 7<br />
											       
>Example 3:<br />
Input: heights = [14,3,19,3], bricks = 17, ladders = 0<br />
Output: 3<br />

* Constraints: `1 <= heights.length <= 10^5`<br />
`1 <= heights[i] <= 10^6`<br />
`0 <= bricks <= 10^9`<br />
`0 <= ladders <= heights.length`<br />
		
```cpp
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
	
        int n = heights.size();
        int brickSum = 0;
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i-1];
            if(diff <= 0) continue;
            
            pq.push(diff);
            if(pq.size() > ladders) {
                brickSum += pq.top();
                pq.pop();
            }   
            if(brickSum > bricks) return i - 1;
        }
        return n-1;    
    }
};
```

	
	
	
	

<br /> <br /> <br />**[215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)**<br />
Given an integer array `nums` and an integer `k`, return _the `kth` largest element in the array_.<br />
Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.<br />
	
>Example 1:<br />
Input: nums = [3,2,1,5,6,4], k = 2<br />
Output: 5<br />
	
>Example 2:<br />
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4<br />
Output: 4<br />
 
* Constraints: `1 <= k <= nums.length <= 10^4`<br />
`-10^4 <= nums[i] <= 10^4`<br />

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<k;i++) pq.push(nums[i]);
        for(int i=k;i<nums.size();i++) {
            if(pq.top()<nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
```
				 
				 
				 
				 
<br /> <br /> <br />**[665. Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/)**<br />
Given an array `nums` with `n` integers, your task is to check if it could become non-decreasing by modifying **at most one element**.<br />
We define an array is non-decreasing if `nums[i] <= nums[i + 1]` holds for every `i` (**0-based**) such that (`0 <= i <= n - 2`).<br />

>Example 1:<br />
Input: nums = [4,2,3]<br />
Output: true<br />
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.<br />

>Example 2:<br />
Input: nums = [4,2,1]<br />
Output: false<br />
Explanation: You can't get a non-decreasing array by modify at most one element.<br />
 
* Constraints: `n == nums.length`<br />
`1 <= n <= 10^4`<br />
`-10^5 <= nums[i] <= 10^5`<br />

```cpp
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                if(i == 1)count++;
                else{
                    if(nums[i]<nums[i-2] && (i<nums.size()-1 && nums[i+1]<=nums[i-1]))return false;
                    else count++;
                }
            }
            if(count>1)return false;;
        }
        return true;
    }
};
```
	

	
	
	
	
	
	
<br /> <br /> <br />**[1423. Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)**<br />
There are several cards **arranged in a row**, and each card has an associated number of points. The points are given in the integer array `cardPoints`.<br />
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly `k` cards.<br />
Your score is the sum of the points of the cards you have taken.<br />
Given the integer array `cardPoints` and the integer `k`, return the _maximum score_ you can obtain.<br />

>Example 1:<br />
Input: cardPoints = [1,2,3,4,5,6,1], k = 3<br />
Output: 12<br />
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.<br />

>Example 2:<br />
Input: cardPoints = [2,2,2], k = 2<br />
Output: 4<br />
Explanation: Regardless of which two cards you take, your score will always be 4.<br />

>Example 3:<br />
Input: cardPoints = [9,7,7,9,7,7,9], k = 7<br />
Output: 55<br />
Explanation: You have to take all the cards. Your score is the sum of points of all cards.<br />
 
* Constraints: `1 <= cardPoints.length <= 10^5`<br />
`1 <= cardPoints[i] <= 10^4`<br />
`1 <= k <= cardPoints.length`<br />

```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int result = 0, current = 0;
        for(int i = 0;i<k;i++)result += cardPoints[i];
        current = result;
        for(int i = k-1;i>=0;i--){
            current -= cardPoints[i];
            current += cardPoints[cardPoints.size()-k+i];
            result = max(current, result);
        }
        return result;
    }
};
```

	
	
	
	
	

<br /> <br /> <br />**[1689. Partitioning Into Minimum Number Of Deci-Binary Numbers](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)**<br />
A decimal number is called **deci-binary** if each of its digits is either `0` or `1` without any leading zeros. For example, `101` and `1100` are **deci-binary**, while `112` and `3001` are not.<br />
Given a string `n` that represents a positive decimal integer, return _the **minimum** number of positive **deci-binary** numbers needed so that they sum up to_ `n`.<br />

>Example 1:<br />
Input: n = "32"<br />
Output: 3<br />
Explanation: 10 + 11 + 11 = 32<br />

>Example 2:<br />
Input: n = "82734"<br />
Output: 8<br />

>Example 3:<br />
Input: n = "27346209830709182346"<br />
Output: 9<br />
 
* Constraints: `1 <= n.length <= 10^5`<br />
`n` consists of only digits.<br />
`n` does not contain any leading zeros and represents a positive integer.<br />
	
```cpp
class Solution {
public:
    int minPartitions(string n) {
        sort(n.begin(), n.end());
        char lastcharacter = n.back();
        lastcharacter -= '0';
        return lastcharacter;
    }
};

// OR
-
class Solution {
public:
    int minPartitions(string n) {
        int len = n.length();
        int max_digit_in_string = 0;
        
        for(auto element : n)
        {
            // convert the string number into integer number by subtracting the ascii value.
            int digit = element - '0';
            max_digit_in_string = max(max_digit_in_string,digit);
        }
        
        return max_digit_in_string;
    }
};
```
	
	
	
	
	
	
<br /> <br /> <br />**[1647. Minimum Deletions to Make Character Frequencies Unique](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)**<br />
A string `s` is called **good** if there are no two different characters in `s` that have the same **frequency**.<br />
Given a string `s`, return _the **minimum** number of characters you need to delete to make `s` **good**_.<br />
The **frequency** of a character in a string is the number of times it appears in the string. For example, in the string `"aab"`, the **frequency** of `'a'` is `2`, while the **frequency** of `'b'` is `1`.<br />

>Example 1:<br />
Input: s = "aab"<br />
Output: 0<br />
Explanation: s is already good.<br />

>Example 2:<br />
Input: s = "aaabbbcc"<br />
Output: 2<br />
Explanation: You can delete two 'b's resulting in the good string "aaabcc".<br />
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".<br />

>Example 3:<br />
Input: s = "ceabaacb"<br />
Output: 2<br />
Explanation: You can delete both 'c's resulting in the good string "eabaab".<br />
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).<br />
 
* Constraints: `1 <= s.length <= 10^5`<br />
`s` contains only lowercase English letters.<br />

```cpp
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int>charcnt;
        unordered_map<int,int>uniquefreq;
        int count=0;
        for(int i=0;i<s.size();i++){
            charcnt[s[i]-'a']++;
        }
        for(auto &it : charcnt){
            int x= it.second;
            if(uniquefreq[x]!=0){
                while(x>0 && uniquefreq[x]!=0){
                    x--;
                    count++;
                }
            }
            if(x>0)uniquefreq[x]++;
        }
        return count;
    }
};
```
	
	
	
	
	
<br /> <br /> <br />**[406. Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height/)**<br />
You are given an array of people, `people`, which are the attributes of some people in a queue (not necessarily in order). Each `people[i] = [hi, ki]` represents the `ith` person of height `hi` with **exactly** `ki` other people in front who have a height greater than or equal to `hi`.<br />
Reconstruct and return _the queue that is represented by the input array_ `people`. The returned queue should be formatted as an array `queue`, where `queue[j] = [hj, kj]` is the attributes of the `jth` person in the queue (`queue[0]` is the person at the front of the queue).<br />

>Example 1:<br />
Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]<br />
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]<br />
Explanation:<br />
Person 0 has height 5 with no other people taller or the same height in front.<br />
Person 1 has height 7 with no other people taller or the same height in front.<br />
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.<br />
Person 3 has height 6 with one person taller or the same height in front, which is person 1.<br />
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.<br />
Person 5 has height 7 with one person taller or the same height in front, which is person 1.<br />
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.<br />

>Example 2:<br />
Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]<br />
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]<br />
 
* Constraints: `1 <= people.length <= 2000`<br />
`0 <= hi <= 10^6`<br />
`0 <= ki < people.length`<br />
It is guaranteed that the queue can be reconstructed.<br />

```cpp
class Solution {
public:
    static bool compare(vector<int>& a, vector<int> & b){
        if(a[0] == b[0])return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {   
        int n = people.size();
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> res; 
        for(int i = 0; i < n; i++){
            int idx = people[i][1];
            res.insert(res.begin() + idx, people[i]);
        }
        return res;   
    }
};
```
	
	
	
	
	
<br /> <br /> <br />**[462. Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)**<br />
Given an integer array `nums` of size `n`, return _the minimum number of moves required to make all array elements equal_.<br />
In one move, you can increment or decrement an element of the array by `1`.<br />
Test cases are designed so that the answer will fit in a **32-bit** integer.<br />

>Example 1:<br />
Input: nums = [1,2,3]<br />
Output: 2<br />
Explanation:<br />
Only two moves are needed (remember each move increments or decrements one element):<br />
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]<br />

>Example 2:<br />
Input: nums = [1,10,2,9]<br />
Output: 16<br />
	
* Constraints: `n == nums.length`<br />
`1 <= nums.length <= 10^5`<br />
`-10^9 <= nums[i] <= 10^9`<br />

```cpp
/*There is a function with syntax nth_element (RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);
The function of this is that it rearranges the array in such a way such that the element at the nth position is the one which should be at that position if we sort the list from the first to last iterator. It uses the quick select method for this. For more details google it.

In this problem we don't need full array sorted we just need the median which is the n/2 th element in the sorted array. So this can be achived by nth_element(nums.begin(), nums.begin()+(n/2), nums.end()). After that continue as in first approach.

The advantage of this approach is that the time complexity becomes O(n) as nth_element is O(n) fuction unlike sort.

Time Complexity : O(n) for finding median + O(n) for loop = O(n), Space complexity : O(1)
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end());
        int median = nums[n/2];
        for(int i=0; i<n; i++){
            steps += abs(nums[i] - median);
        }
        return steps;
    }
};
```

			  
			  
			  
			  
<br /> <br /> <br />**[1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/)**<br />
You are given a rectangular cake of size `h x w` and two arrays of integers `horizontalCuts` and `verticalCuts` where:<br />
	
 * `horizontalCuts[i]` is the distance from the top of the rectangular cake to the `ith` horizontal cut and similarly, and<br />
 * `verticalCuts[j]` is the distance from the left of the rectangular cake to the `jth` vertical cut.<br />
	
Return _the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays_ `horizontalCuts` and `verticalCuts`. Since the answer can be a large number, return this **modulo** `10^9 + 7`.<br />
	
>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/05/14/leetcode_max_area_2.png"><br />
Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]<br />
Output: 4 <br />
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.<br />

>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2020/05/14/leetcode_max_area_3.png"><br />
Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]<br />
Output: 6<br />
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.<br />

>Example 3:<br />
Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]<br />
Output: 9<br />
 
* Constraints: `2 <= h, w <= 10^9`<br />
`1 <= horizontalCuts.length <= min(h - 1, 10^5)`<br />
`1 <= verticalCuts.length <= min(w - 1, 10^5)`<br />
`1 <= horizontalCuts[i] < h`<br />
`1 <= verticalCuts[i] < w`<br />
All the elements in `horizontalCuts` are distinct.<br />
All the elements in `verticalCuts` are distinct.<br />
	
```cpp
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(),verticalCuts.end());
        
        
        long long int maxh=0, maxw=0;
        
        for(int i=0;i<horizontalCuts.size()-1;i++){
            if(maxh<(horizontalCuts[i+1]-horizontalCuts[i])){
                maxh = (horizontalCuts[i+1]-horizontalCuts[i])%1000000007;
            }
        }
        
         for(int i=0;i<verticalCuts.size()-1;i++){
            if(maxw<(verticalCuts[i+1]-verticalCuts[i])){
                maxw = (verticalCuts[i+1]-verticalCuts[i])%1000000007;
            }
        }
  
        return (maxh*maxw)%1000000007;
    }
};
```


	
	
	

<br /> <br /> <br />**[131. Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)**<br />
Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. Return all possible palindrome partitioning of `s`.<br />
A **palindrome** string is a string that reads the same backward as forward.<br />

>Example 1:<br />
Input: s = "aab"<br />
Output: [["a","a","b"],["aa","b"]]<br />

>Example 2:<br />
Input: s = "a"<br />
Output: [["a"]]<br />
 
* Constraints: `1 <= s.length <= 16`<br />
`s` contains only lowercase English letters.<br />
	
```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        partition(s, 0, path, result);//dfs calls
        return result;
    }
private: 
    //DFS steps
    void partition(string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        int n = s.length();
        if (start == n) {
            result.push_back(path);
        } else {
            for (int i = start; i < n; i++) {
                if (isPalindrome(s, start, i)) {
                    path.push_back(s.substr(start, i - start + 1));
                    partition(s, i + 1, path, result);
                    path.pop_back();
                }
            }
        }
    }
    //helper function to safe check whether a substr is palindrome or not
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
```
	
	
	
	
	
	
<br /> <br /> <br />**[376. Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/)**<br />
A **wiggle sequence** is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.<br />

 * For example, `[1, 7, 4, 9, 2, 5]` is a **wiggle sequence** because the differences `(6, -3, 5, -7, 3)` alternate between positive and negative.<br />
 * In contrast, `[1, 4, 7, 2, 5]` and `[1, 7, 4, 5, 5]` are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.<br />
	
A **subsequence** is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.<br />
Given an integer array `nums`, return _the length of the longest **wiggle subsequence** of_ `nums`.<br />

>Example 1:<br />
Input: nums = [1,7,4,9,2,5]<br />
Output: 6<br />
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).<br />

>Example 2:<br />
Input: nums = [1,17,5,10,13,15,10,5,16,8]<br />
Output: 7<br />
Explanation: There are several subsequences that achieve this length.<br />
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).<br />

>Example 3:<br />
Input: nums = [1,2,3,4,5,6,7,8,9]<br />
Output: 2<br />
 
* Constraints: 1 <= nums.length <= 1000<br />
0 <= nums[i] <= 1000<br />

```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2)return nums.size();
			int up = 1, down = 1;
			for(int i = 1; i < nums.size(); i++){
				if(nums[i] > nums[i-1])up = down + 1;
				else if(nums[i] < nums[i-1])down  = up + 1;
			}
		return max(up, down); 
    }
};
```

								
								
								
								
							
<br /> <br /> <br />**[128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)**<br />
Given an unsorted array of integers `nums`, return _the length of the longest consecutive elements sequence_.<br />
You must write an algorithm that runs in `O(n)` time.<br />

>Example 1:<br />
Input: nums = [100,4,200,1,3,2]<br />
Output: 4<br />
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.<br />

>Example 2:<br />
Input: nums = [0,3,7,2,5,8,4,6,0,1]<br />
Output: 9<br />
 
* Constraints: `0 <= nums.length <= 10^5`<br />
`-10^9 <= nums[i] <= 10^9`<br />

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end()); // this is faster
        
        // for(int i = 0; i<nums.size(); i++)
        // {
        //     s.insert(nums[i]);
        // }
        
        int longest_sequence = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(s.find(nums[i] - 1)!=s.end())
                continue;
            
            else
            {
                int count = 0;
                int current_element = nums[i];
                
                while(s.find(current_element) != s.end())
                {
                    count++;
                    current_element++;
                }
                
                longest_sequence = max(longest_sequence,count);
            }
        }
        
        return longest_sequence;
    }
};
```

	
	
	
	
<br /> <br /> <br />**[97. Interleaving String](https://leetcode.com/problems/interleaving-string/)**<br />
Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an **interleaving** of `s1` and `s2`.<br />
An **interleaving** of two strings `s` and `t` is a configuration where they are divided into **non-empty** substrings such that:<br />

 * `s = s1 + s2 + ... + sn`<br />
 * `t = t1 + t2 + ... + tm`<br />
 * `|n - m| <= 1`<br />
 * The **interleaving** is `s1 + t1 + s2 + t2 + s3 + t3 + ...` or `t1 + s1 + t2 + s2 + t3 + s3 + ...`<br />
	   
**Note:** `a + b` is the concatenation of strings `a` and `b`.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/09/02/interleave.jpg"><br />
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"<br />
Output: true<br />

>Example 2:<br />
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"<br />
Output: false<br />

>Example 3:<br />
Input: s1 = "", s2 = "", s3 = ""<br />
Output: true<br />
 
* Constraints: `0 <= s1.length, s2.length <= 100`<br />
`0 <= s3.length <= 200`<br />
`s1`, `s2`, and `s3` consist of lowercase English letters.<br />
	
```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        if(m==0 && n==0 && s3.size()==0)return true;
        if(m+n !=s3.size())return false;
        if(m==0 && n==0)return false;
        vector<vector<bool>> dp(m+1 , vector<bool>(n+1 , false));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            if(s1[i-1]==s3[i-1] && dp[i-1][0]==true)dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            if(s2[i-1]==s3[i-1] && dp[0][i-1]==true)dp[0][i]=true;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int k=i+j-1;
                if(s1[i-1]==s3[k] && dp[i-1][j]==true) dp[i][j]=true;
                if(s2[j-1]==s3[k] && dp[i][j-1]==true)dp[i][j]=true;
            }
        }
        return dp[m][n];
    }
};
```
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[1696. Jump Game VI](https://leetcode.com/problems/jump-game-vi/)**<br />
You are given a **0-indexed** integer array `nums` and an integer `k`.<br />
You are initially standing at index `0`. In one move, you can jump at most `k` steps forward without going outside the boundaries of the array. That is, you can jump from index `i` to any index in the range `[i + 1, min(n - 1, i + k)]` **inclusive**.<br />
You want to reach the last index of the array (index `n - 1`). Your **score** is the **sum** of all `nums[j]` for each index `j` you visited in the array.<br />
Return _the **maximum score** you can get_.<br />

>Example 1:<br />
Input: nums = [1,-1,-2,4,-7,3], k = 2<br />
Output: 7<br />
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.<br />

>Example 2:<br />
Input: nums = [10,-5,-2,4,0,3], k = 3<br />
Output: 17<br />
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.<br />

>Example 3:<br />
Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2<br />
Output: 0<br />
 
* Constraints: `1 <= nums.length, k <= 10^5`<br />
`-10^4 <= nums[i] <= 10^4`<br />

```cpp
#define pii pair<int, int>
class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        int n=nums.size();
        int score[n];
        priority_queue<pii> pq;
        
        for(int i=n-1 ; i>=0 ; i--){
            while(pq.size() && pq.top().second>i+k)pq.pop();        
            score[i]=nums[i];
            score[i]+=(pq.size() ? pq.top().first : 0);
            pq.push({score[i], i});
        }
        
        return score[0];
    }
};
```

	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[199. Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)**<br />
Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return _the values of the nodes you can see ordered from top to bottom_.<br />
	
>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/02/14/tree.jpg"><br />
Input: root = [1,2,3,null,5,null,4]<br />
Output: [1,3,4]<br />

>Example 2:<br />
Input: root = [1,null,3]<br />
Output: [1,3]<br />

>Example 3:<br />
Input: root = []<br />
Output: []<br />
 
* Constraints: The number of nodes in the tree is in the range `[0, 100]`.<br />
`-100 <= Node.val <= 100`<br />
	

**APPROACH with no extra space**

Maintain an array / vector.

 * TRAVERSAL -> ROOT ->RIGHT -> LEFT This is the way traversal is done in array so that rightmost node at i level is visited first.
 * When at i level, check in array/vector, if there is an element already present at indexi in the array.
[ index represents the level in tree ]->[element at index i is rightmost node at level i]
 * If at that level, element is present,, just continue the traversal.
 * Else if no element is present at index i -> add that node to answer [res] at the i index.
	
<img src = "https://assets.leetcode.com/users/images/34815618-d722-485c-a276-94e1d7aa5caf_1657511962.541216.png">

	
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
    
    vector<int> solve(TreeNode* root, vector<int> res, int lvl){
        if (root==NULL){
            return res;
        }
        if (res.size()==lvl){                 // root
            res.push_back(root->val);
        }
        res = solve(root->right , res , lvl + 1);     // right
        res = solve(root->left , res , lvl + 1);       // left
        return res;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        res = solve( root , res , 0 );
        return res;
    }
};
```
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[473. Matchsticks to Square](https://leetcode.com/problems/matchsticks-to-square/)**<br />
You are given an integer array `matchsticks` where `matchsticks[i]` is the length of the `ith` matchstick. You want to use **all the matchsticks** to make one square. You **should not break** any stick, but you can link them up, and each matchstick must be used **exactly one time**.<br />
Return `true` if you can make this square and `false` otherwise.<br />
	
>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/04/09/matchsticks1-grid.jpg"><br />
Input: matchsticks = [1,1,2,2,2]<br />
Output: true<br />
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.<br />

>Example 2:<br />
Input: matchsticks = [3,3,3,3,4]<br />
Output: false<br />
Explanation: You cannot find a way to form a square with all the matchsticks.<br />
 
Constraints: `1 <= matchsticks.length <= 15`<br />
`1 <= matchsticks[i] <= 10^8`<br />

```cpp
# backtracking 
class Solution {
	// a,b,c,d are four sides of square
    int a,b,c,d;
    bool fun(vector<int>& matchsticks,int i){
        //Base Case
        if(i==matchsticks.size()){
            if(a==0 && b==0 && c==0 && d==0) return true;
            else return false;
        }
        
		//Now we will explore for all side for given index
		
		// if matchstick size is less than side(a or b or c or d)  size , then in that case we will not explore that because that will cause negative side which is not possible
        if(matchsticks[i]<=a){
            a-=matchsticks[i];
            if(fun(matchsticks,i+1)) return true;
            a+=matchsticks[i];      // backtrack step
        }
        
        if(matchsticks[i]<=b){
            b-=matchsticks[i];
            if(fun(matchsticks,i+1)) return true;
            b+=matchsticks[i];        // backtrack step                    
        }
        
        if(matchsticks[i]<=c){
            c-=matchsticks[i];
            if(fun(matchsticks,i+1)) return true;
            c+=matchsticks[i];         // backtrack step
        }
        
        if(matchsticks[i]<=d){
            d-=matchsticks[i];
            if(fun(matchsticks,i+1)) return true;
            d+=matchsticks[i];         // backtrack step
        }
		
		//If none of the explored option retuen true then  we have to return false
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
		//  if less than four number present in array , then we can not make square
        if(matchsticks.size()<4) return false;
        
		// if sum of all number of array is not divisible by 4 , then we can not create a square
		int sum = accumulate(matchsticks.begin(), matchsticks.end(),0);
        if(sum % 4 != 0) return false;
        
		int sizeSum=sum/4;
        a=sizeSum,b=sizeSum,c=sizeSum,d=sizeSum;
        
		// here we sort our array in reverse order to escape more cases
		sort(matchsticks.rbegin(), matchsticks.rend());
        
		return fun(matchsticks,0);
    }
};
```


<br />
	
```python 
# dfs cache backtracking
class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        value = sum(matchsticks)
        if value < 4:
            return False
        if value % 4 != 0:
            return False
        edge = value // 4
        matchsticks.sort(reverse=True)
        @cache
        def findedges(l1, l2, l3, l4, i):
            nonlocal edge
            if l1 == l2 == l3 == l4 == edge:
                return True
            if i > len(matchsticks) - 1:
                return False
            if l1 > edge or l2 > edge or l3 > edge or l4 > edge:
                return False
            return findedges(l1 + matchsticks[i], l2, l3, l4, i + 1) or findedges(l1, l2 + matchsticks[i] , l3, l4, i + 1) or findedges(l1, l2, l3 + matchsticks[i], l4, i + 1) or findedges(l1, l2, l3, l4 + matchsticks[i] , i + 1)
        return findedges(0, 0, 0, 0, 0)
```
	
<br /><br />
	
```cpp
# recursive and dp optmised 
class Solution {
private:
    bool canMake ( int index , int bucketsize , vector<int> &matchsticks , vector<int> &bucket){ 
        if ( index == matchsticks.size()) 
            return bucket[0]==bucket[1] and bucket[1]==bucket[2] and bucket[2]==bucket[3] ;
        
        for ( int i = 0 ; i < 4 ; i ++ ){
            if ( bucket[i] + matchsticks.at(index) > bucketsize) continue ;  
           
            int j = i ;
            while ( --j >= 0) 
                if ( bucket[i] == bucket[j]) break;
            
            if ( j != -1 ) continue ;
            
            bucket.at(i) += matchsticks.at(index);
            if ( canMake ( index + 1 , bucketsize , matchsticks , bucket )) return true;
            bucket.at(i) -= matchsticks.at(index);
        }
        
        return false;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
       
        int sum = 0 ;
        
        for ( int i : matchsticks) sum += i ;
        if ( sum == 0 or sum % 4 ) return false;
         
        sort( matchsticks.begin() , matchsticks.end() , greater<int>());
        
        vector<int> bucket(4, 0 );
        return canMake( 0 , sum / 4 , matchsticks , bucket);
    }
};
```

	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[576. Out of Boundary Paths](https://leetcode.com/problems/out-of-boundary-paths/)**<br />
There is an `m x n` grid with a ball. The ball is initially at the position `[startRow, startColumn]`. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply **at most** `maxMove` moves to the ball.<br />
Given the five integers `m`, `n`, `maxMove`, `startRow`, `startColumn`, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it **modulo** `10^9 + 7`.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_1.png"><br />
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0<br />
Output: 6<br />
	
>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_2.png"><br />
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1<br />
Output: 12<br />
	
* Constraints: `1 <= m, n <= 50`<br />
`0 <= maxMove <= 50`<br />
`0 <= startRow < m`<br />
`0 <= startColumn < n`<br />
	
```cpp
class Solution {
public:
    int dp[55][55][55];
    long long mod = 1e9 + 7;
    
    int dfs(int i, int j, int n, int m, int moves){
        if(i < 0 || i >= n || j < 0 || j >= m)return 1;
        if(moves <= 0)return 0;
        if(dp[i][j][moves] != -1)return dp[i][j][moves];
        int up = dfs(i - 1, j, n, m, moves - 1);
        int down = dfs(i + 1, j, n, m, moves - 1);
        int left = dfs(i, j - 1, n, m, moves - 1);
        int right = dfs(i, j + 1, n, m, moves - 1);
        return dp[i][j][moves] = (up % mod + down % mod + left % mod + right % mod) % mod;
    }
    
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return dfs(startRow, startColumn, n, m, maxMove);
    }
};
```
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
			   
<br /> <br /> <br />**[792. Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences/)**<br />
Given a string `s` and an array of strings `words`, return _the number of `words[i]` that is a subsequence of `s`_.<br />
A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.<br />
 * For example, `"ace"` is a subsequence of `"abcde"`.<br />

>Example 1:<br />
Input: s = "abcde", words = ["a","bb","acd","ace"]<br />
Output: 3<br />
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".<br />

>Example 2:<br />
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]<br />
Output: 2<br />
 
* Constraints: `1 <= s.length <= 5 * 10^4`<br />
`1 <= words.length <= 5000`<br />
`1 <= words[i].length <= 50`<br />
`s` and `words[i]` consist of only lowercase English letters.<br />
	
```cpp
class Solution {
public:
    int binary_search(vector<int> &arr, int x){
        int start = 0, end = arr.size()-1, ans = -1;
        while (start <= end){
            int mid = (start + end)/2;
            if (arr[mid] <= x)start = mid + 1;  
            else{
                ans = mid;
                end = mid - 1;
            }
        }
        return ans==-1 ? ans : arr[ans];
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<s.length();i++)mp[s[i]].push_back(i);
        int count = words.size();
        for(auto w : words){
            int prev = -1;
            for(int j=0;j<w.size();j++){
                int x = binary_search(mp[w[j]],prev);
                if(x == -1){
                    count--;
                    break;
                }
                else prev = x;
            }
        }
        return count;
    }
};
```
<pre>
can use C++ STL function upper bound instead of writing binary search code manually
Time Complexity : O( M * S * log(N) )
Space Complexity : O( N ) ,
where M is length of words array, S is length of a word and N is length of given string
</pre>
	
```cpp
class Solution {
public:
    bool isSubsequence(string s1, string s2, int m, int n){
        if(n == 0) return true;
        if(m == 0) return false;
        if(s1[m - 1] == s2[n - 1]) return isSubsequence(s1, s2, m - 1, n - 1);
        else return isSubsequence(s1, s2, m - 1, n);
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for(auto x: words)count += (isSubsequence(s, x, s.size(), x.size()) == true);
        return count;
    }
};
```

```cpp
class Solution {
public:
    bool isSubsequence(string s1, string s2, int m, int n){
        int j = 0;
        for(int i = 0; i < m && j < n; i++)if(s1[i] == s2[j]) j++;
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for(auto x: words)count += (isSubsequence(s, x, s.size(), x.size()) == true);
        return count;
    }
};
```
	
```cpp
class Solution {
public:
    bool isSubsequence(string s1, string s2, int m, int n){
        int j = 0;
        for(int i = 0; i < m && j < n; i++)if(s1[i] == s2[j])j++;
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        map<string, bool> mp;
        for(auto x: words){
            if(mp.find(x) != mp.end()) {
                if(mp[x] == true)count++; 		
                continue;
            }
            mp[x] = isSubsequence(s, x, s.size(), x.size());
            count += (mp[x] == true);
        }
        return count;
    }
};
```
	
```cpp
class Solution {
public:
	int numMatchingSubseq(string s, vector<string>& words){
		vector<vector<int>>v(26);
		for(int i=0;i<s.length();i++)v[s[i]-'a'].push_back(i); 
		int ans=0;
		for(int i=0;i<words.size();i++){
			int last;                                             
			if(v[words[i][0]-'a'].size()==0)continue;
			else last=*v[words[i][0]-'a'].begin();
			int flag=1;
			for(int j=1;j<words[i].size();j++){
				auto it=upper_bound(v[words[i][j]-'a'].begin(),v[words[i][j]-'a'].end(),last);       
				if(it==v[words[i][j]-'a'].end()){                        
					flag=0;
					break;
				}
				else last=*upper_bound(v[words[i][j]-'a'].begin(),v[words[i][j]-'a'].end(),last); 
			}
			if(flag)ans++;                                      
		}
		return ans;  
	}
};
```

							    
							    
							    
							    
							    
							    
							    
							    
							    
							    
							    
							    
							    
<br /> <br /> <br />**[890. Find and Replace Pattern](https://leetcode.com/problems/find-and-replace-pattern/)**<br />
Given a list of strings `words` and a string `pattern`, return _a list of `words[i]` that match `pattern`_. You may return the answer in **any order**.<br />
A word matches the pattern if there exists a permutation of letters `p` so that after replacing every letter `x` in the pattern with `p(x)`, we get the desired word.<br />
Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.<br />

>Example 1:<br />
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"<br />
Output: ["mee","aqq"]<br />
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. <br />
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.<br />

>Example 2:<br />
Input: words = ["a","b","c"], pattern = "a"<br />
Output: ["a","b","c"]<br />
 
* Constraints: `1 <= pattern.length <= 20`<br />
`1 <= words.length <= 50`<br />
`words[i].length == pattern.length`<br />
`pattern` and `words[i]` are lowercase English letters.<br />
	
```cpp
class Solution {
public:
    
    vector<int> found_Pattern(string pattern)
    {
	   // if string is empty return empty vector.
        if(pattern.size() == 0)
            return {};
        
        vector<int> v;
		
		// ind variable for keeping track of unique characters
        int ind = 0;
		
        unordered_map<char,int> mp;
        for(int i = 0; i<pattern.size(); ++i)
        {
			// if character not present in map, insert the char with an index,
			// increment index because for next unique character the index should be differnt.
           if(mp.find(pattern[i]) == mp.end())
           {
               mp.insert({pattern[i],ind++});
			   // also  push the index to v(numeric  pattern vector)
			   // mp[pattern[i]] gives the key to that character, here key is ind(which we are giving to every unique character)
               v.push_back(mp[pattern[i]]);
           }
            else
            {
				// if char is already in map than push index mapped to that character into the vector
                v.push_back(mp[pattern[i]]);
            }
        }
		// return numeric pattern
        return v;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       
		// store numeric patten of Pattern string in v
        vector<int> v = found_Pattern(pattern);
        
        int n = words.size();
        vector<string> ans;
        
		// iterating and comparing pattern of each word with v(numeric pattern of Pattern)
        for(int i = 0; i<n; ++i)
        {
            vector<int> pattern_word = found_Pattern(words[i]);
            
			// if matched add words[i] to answer vector
            if(v == pattern_word)
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};


// By using isomorphic string
/*
Two strings are isomorphic if one-to-one mapping is possible for every character of the 
first string to every character of the second string. For example, consider the 
two strings: “ACAB” and “XCXY”. 
We can map the characters of the first string to the characters of the second string as follows: 'A' maps to 'X'.
*/
class Solution {
public:
    bool helper(string s,string t)
    {
        map<char,char>m;
        for(int i=0;i<s.length();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                if(m[s[i]]!=t[i])
                    return false;
            }
            else
            {
                m[s[i]]=t[i];
            }
        }
        return true;
    }
    bool isIsomorphic(string s,string t)
    {
        return helper(s,t) and helper(t,s);
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int i=0;i<words.size();i++)
        {
            if(isIsomorphic(words[i],pattern))
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};


// in  O(1) Space O(n*length) Time
 bool show(string &s1 , string &s2 , int &n)
    {
        vector<int> mappedvalue(26,-1) , visited(26,0);
       for(int i=0;i<n;i++)
       {
             if(mappedvalue[s1[i]-'a']==-1) {
                 mappedvalue[s1[i]-'a']= s2[i]-'a';
                 if(visited[s2[i]-'a']++) return false; // if the character is already matched to some other character previously 
             }
              if(mappedvalue[s1[i]-'a'] != (s2[i]-'a')) return false;
       }
        return true;
        
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int n=pattern.length();
        for(auto &it : words)
        {
            if(show(it, pattern , n)) ans.emplace_back(it);
        }
        return ans;
    }
```
	

	
	
	
	
	
	
	
	
<br /> <br /> <br />**[916. Word Subsets](https://leetcode.com/problems/word-subsets/)**<br />
You are given two string arrays `words1` and `words2`.<br />
A string `b` is a **subset** of string `a` if every letter in `b` occurs in `a` including multiplicity.<br />

 * For example, `"wrr"` is a subset of `"warrior"` but is not a subset of `"world"`.<br />

A string `a` from `words1` is **universal** if for every string `b` in `words2`, `b` is a subset of `a`.<br />
Return an array of all the **universal** strings in `words1`. You may return the answer in **any order**.<br />

>Example 1:<br />
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]<br />
Output: ["facebook","google","leetcode"]<br />

>Example 2:<br />
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]<br />
Output: ["apple","google","leetcode"]<br />
 
* Constraints: `1 <= words1.length, words2.length <= 10^4`<br />
`1 <= words1[i].length, words2[i].length <= 10`<br />
`words1[i]` and `words2[i]` consist only of lowercase English letters.<br />
All the strings of `words1` are **unique**.<br />
	
```cpp
class Solution {
public:
    // calculate the frequency of string s
    vector<int> giveMeFreq(string s)
    {
        vector<int> freq(26,0);
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
       vector<string> ans; // store ans
       vector<int> max_Freq_w2(26, 0);   // store max freq of each character present in word2 stirngs
	   
        // we will Iterate over word to and try to find max freq for each character present in all strings.
		for(auto &x : words2) 
        {
            vector<int> freq = giveMeFreq(x);
            for(int i = 0; i < 26; i++)
            {
                max_Freq_w2[i] = max(freq[i], max_Freq_w2[i]);  // upadate freq to max freq
            }
        }
        
		// we will iterate for each string in words1 ans if it have all charaters present in freq array with freq >= that     then we will add it to ans
        for(auto &x : words1)
        {
            vector<int> freq = giveMeFreq(x);  // gives freq of characters for word in words1
            bool flag = true;
            for(int i = 0; i < 26; i++)
            {
                if(freq[i] < max_Freq_w2[i]) // specifies that word did not have all the characters from word2 array
                {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(x);   // string x is Universal string
        }
        return ans;
    }
};
```
<pre>
Time Complexity for this soltuion is : O(M + N) where m and n is size of words1 and words2 array
</pre>	
	
	
	
<br /> <br /> <br />**[307. Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/)**<br />
Given an integer array `nums`, handle multiple queries of the following types:<br />

 1. **Update** the value of an element in `nums`.<br />
 2. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.<br />

Implement the `NumArray` class:<br />

 * `NumArray(int[] nums)` Initializes the object with the integer array `nums`.<br />
 * `void update(int index, int val)` **Updates** the value of `nums[index]` to be `val`.<br />
 * `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).<br />

>Example 1:<br />
Input<br />
["NumArray", "sumRange", "update", "sumRange"]<br />
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]<br />
Output<br />
[null, 9, null, 8]<br />
Explanation<br />
NumArray numArray = new NumArray([1, 3, 5]);<br />
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9<br />
numArray.update(1, 2);   // nums = [1, 2, 5]<br />
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8<br />
 
* Constraints: `1 <= nums.length <= 3 * 10^4`<br />
`-100 <= nums[i] <= 100`<br />
`0 <= index < nums.length`<br />
`-100 <= val <= 100`<br />
`0 <= left <= right < nums.length`<br />
At most `3 * 10^4` calls will be made to `update` and `sumRange`.<br />
	
```cpp
class NumArray {
public:
    vector<int>v; //vector to store input vector.
    int sum; //sum of all element of vector 
    NumArray(vector<int>& nums) {
        v=nums;
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
    }
    
    void update(int index, int val) {
        sum-=v[index];     //subtract old element  from sum at index and then update by adding new element val.
        v[index]=val;
        sum+=val;
        
    }
    
    int sumRange(int left, int right) {
        int res=sum; 
        for(int i=0;i<left;i++){    //subtract all element before left and after right
            res-=v[i];
        }
        for(int i=right+1;i<v.size();i++){
            res-=v[i];
        }
        return res;// return res ie. our answer.
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
```
	
	
	
	
<br /> <br /> <br />**[]()**<br />
