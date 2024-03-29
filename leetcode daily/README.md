# Leetcode daily question 
**[1260. Shift 2D Grid](https://leetcode.com/problems/shift-2d-grid/)**<br />
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

 

<br /> <br /> <br /> **[289. Game of Life](https://leetcode.com/problems/game-of-life/)**<br />
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

	
	
	
<br /> <br /> <br />**[2183. Count Array Pairs Divisible by K](https://leetcode.com/problems/count-array-pairs-divisible-by-k/)**<br />
Given a **0-indexed** integer array `nums` of length `n` and an integer `k`, return the _**number of pairs**_ `(i, j)` such that:<br />
* `0 <= i < j <= n - 1` and<br />
* `nums[i] * nums[j]` is divisible by `k`.<br />
	      
>Example 1:<br />
>Input: nums = [1,2,3,4,5], k = 2<br />
>Output: 7<br />
>Explanation: <br />
>The 7 pairs of indices whose corresponding products are divisible by 2 are<br />
>(0, 1), (0, 3), (1, 2), (1, 3), (1, 4), (2, 3), and (3, 4).<br />
>Their products are 2, 4, 6, 8, 10, 12, and 20 respectively.<br />
>Other pairs such as (0, 2) and (2, 4) have products 3 and 15 respectively, which are not divisible by 2.<br />
	      
>Example 2:<br />
>Input: nums = [1,2,3,4], k = 5<br />
>Output: 0<br />
>Explanation: There does not exist any pair of indices whose corresponding product is divisible by 5.<br />

* Constraints:`1 <= nums.length <= 10^5`<br />
`1 <= nums[i], k <= 10^5`<br />
	
```cpp
class Solution{
    public:
    long long countPairs(vector<int>& nums, int k) {
       long long ans = 0;
       unordered_map<int, int> mp;
       for(auto ele:nums){
           long long gcd = __gcd(k,ele);
           long long x=k/gcd;
           
           for(auto it:mp)
               if(it.first%x==0) 
                   ans+=it.second;
            mp[gcd]++;
       }
       return ans;
    }
};
/*
// CPP program to illustrate
// gcd function of C++ STL
#include <iostream>
#include <algorithm>
// #include<numeric> for C++17

using namespace std;

int main()
{
	cout << "gcd(6, 20) = " << __gcd(6, 20) << endl; // gcd(2.0,8) for C++17
}

Output
gcd(6, 20) = 2
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
	
	
	

<br /> <br /> <br />**[1192. Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/)**<br />
There are `n` servers numbered from `0` to `n - 1` connected by undirected server-to-server `connections` forming a network where `connections[i] = [ai, bi]` represents a connection between servers `ai` and `bi`. Any server can reach other servers directly or indirectly through the network.<br />
A _critical connection_ is a connection that, if removed, will make some servers unable to reach some other server.<br />
Return all critical connections in the network in any order.<br />
	
>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2019/09/03/1537_ex1_2.png"><br />
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]<br />
Output: [[1,3]]<br />
Explanation: [[3,1]] is also accepted.<br />
	
>Example 2:<br />
Input: n = 2, connections = [[0,1]]<br />
Output: [[0,1]]<br />
 
* Constraints: `2 <= n <= 10^5`<br />
`n - 1 <= connections.length <= 10^5`<br />
`0 <= ai, bi <= n - 1`<br />
`ai != bi`<br />
There are no repeated connections.<br />

```cpp
class Solution {
public:
    //use find the bridges in a graph approach to get all critical connections
	//Tarjans Algorithm / DFS
    void dfs(int node, int parent, vector<int> &tin, vector<int> &low, vector<int> &vis, vector<int> graph[], vector<vector<int>> &ans, int &time)
    {
        //when we visite node first time, tin and low of the node are equal to the time
        tin[node]=low[node]=time++;
        vis[node] = 1; //mark node as visited
        
        for(auto it : graph[node])
        {
            if(it == parent) continue; //to avoid backtracking
            
            //if node is not visited, call the dfs function
            if(!vis[it])
            {
                dfs(it, node, tin, low, vis, graph, ans, time);
                
                //when we return, low of the node is equal to the minimum of low of its child and low of itself
                low[node] = min(low[node], low[it]);
                
                //when we get low of child is greater than tin of the node
                //it means there is only path to cover child that's why {node, it} will be our critical connections or bridge 
                if(low[it] > tin[node])
                    ans.push_back({node, it});
            }
            
            //if node is already visited and tin of the child is less than the low of itself
            //we assign tin of the child to the low of the node
            else
                low[node] = min(low[node], tin[it]);
            
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        //tin - time of insertion at the node
        //low - lowest time of insertion at the node
        //vis - mark visited node 
        vector<int> tin(n, -1), low(n, -1), vis(n, 0);
        vector<vector<int>> ans;
        vector<int> graph[n]; //stores connections in the form of graph
        int time=0;
        
        for(auto it: connections)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        //call dfs function
        dfs(0, -1, tin, low, vis, graph, ans, time);
        return ans;
    }
};
```
	
	
	
	
<br /> <br /> <br />**[329. Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)**<br />
Given an `m x n` integers `matrix`, return _the length of the longest increasing path in `matrix`_.<br />
From each cell, you can either move in four directions: left, right, up, or down. You **may not** move **diagonally** or move **outside the boundary** (i.e., wrap-around is not allowed).<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg"><br />
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]<br />
Output: 4<br />
Explanation: The longest increasing path is [1, 2, 6, 9].<br />
	
>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg"><br />
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]<br />
Output: 4<br />
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.<br />

>Example 3:<br />
Input: matrix = [[1]]<br />
Output: 1<br />

* Constraints: `m == matrix.length`<br />
`n == matrix[i].length`<br />
`1 <= m, n <= 200`<br />
`0 <= matrix[i][j] <= 2^31 - 1`<br />

```cpp
class Solution {
    
    //possible moving directions {up, left, right, down}
    vector<vector<int>> dirs = {
            {-1,0},
    {0,-1},        {0,1},
            {1,0}
    };
    
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp, int prev) 
    {
        //boundary conditon
        if(r<0 || r>=matrix.size() || c<0 || c>=matrix[0].size()) return 0;
        
        //if current value is less than or equal to the previous value return 0;
        if(matrix[r][c] <= prev) return 0;
        
        //if we have already the path length of the cell, we return it (dp concept)
        if(dp[r][c] != -1) return dp[r][c];
        int best = 0; //store best path length
        
        //moving in all 4 directions and call dfs function
        for(auto dir : dirs) {
            int next_r = dir[0] + r;
            int next_c = dir[1] + c;
            int cur = dfs(matrix, next_r, next_c, dp, matrix[r][c]);
            best = max(best, cur); //store max. path length
        }
        
        return dp[r][c] = best + 1; //return path length of the cell
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        //getting no. of row and col of the matrix
        int row = matrix.size(), col = matrix[0].size();
        
        //for dp, create mxn matrix and initialize it with -1
        vector<vector<int>> dp(row, vector<int>(col, -1));
        
        //store longest path
        int longest_path = 0;
        
        //traverse through the matrix
        for(int i=0; i<row; i++) 
        {
            for(int j=0; j<col; j++) 
            {
                int path = dfs(matrix, i, j, dp, -1000000); //call dfs function
                longest_path = max(longest_path, path); //store the maximum path
            }
        }
        
        return longest_path; //return maximum path
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
<br /> <br /> <br />**[32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)**<br />
Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.<br />

>Example 1:<br />
Input: s = "(()"<br />
Output: 2<br />
Explanation: The longest valid parentheses substring is "()".<br />
	
>Example 2:<br />
Input: s = ")()())"<br />
Output: 4<br />
Explanation: The longest valid parentheses substring is "()()".<br />
	
>Example 3:<br />
Input: s = ""<br />
Output: 0<br />
 
* Constraints: `0 <= s.length <= 3 * 10^4`<br />
`s[i]` is `'('`, or `')'`.<br />

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0){
            return 0;
        }
        vector<int>stack={-1};
        int ans =  0;
        for (int i=0;i<s.length();i++){
            if(s[i]=='(') stack.push_back(i);
            else if (stack.size()== 1) stack[0]=i;
            else{
                stack.pop_back();
                ans = max(ans,i-stack.back());
            }
        }
        return ans;
    }
};
```
					
					
					
					
<br /> <br /> <br />**[354. Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/)**<br />
You are given a 2D array of integers `envelopes` where `envelopes[i] = [wi, hi]` represents the width and the height of an envelope.<br />
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.<br />
Return _the maximum number of envelopes you can Russian doll (i.e., put one inside the other)_.<br />
**Note**: You cannot rotate an envelope.<br />

>Example 1:<br />
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]<br />
Output: 3<br />
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).<br />

>Example 2:<br />
Input: envelopes = [[1,1],[1,1],[1,1]]<br />
Output: 1<br />
 
* Constraints: `1 <= envelopes.length <= 10^5`<br />
`envelopes[i].length == 2`<br />
`1 <= wi, hi <= 10^5`<br />

```cpp
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int>list;
        for(int i = 0;i<n;i++){
            int ele = envelopes[i][1];
            int index = lower_bound(list.begin(), list.end(), ele)- list.begin();
            
            if(index>=list.size())list.push_back(ele);
            else list[index] = ele;
        }
        return list.size();
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
	
	
	
<br /> <br /> <br />**[51. N-Queens](https://leetcode.com/problems/n-queens/)**<br />
The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.<br />
Given an integer `n`, return _all distinct solutions to the **n-queens puzzle**_. You may return the answer in **any order**.<br />
Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/11/13/queens.jpg"><br />
Input: n = 4<br />
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]<br />
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above<br />

>Example 2:<br />
Input: n = 1<br />
Output: [["Q"]]<br />

* Constraints: `1 <= n <= 9`<br />

```cpp
class Solution {
public:
    vector<vector<string> > sols; // 2D vector of strings to store the solutions
    vector<vector<string>> solveNQueens(int n) {    
	    vector<string> board(n, string(n, '.'));  // creating an empty board
	    solve(board, 0); // calling the recursive function
	    return sols; 
    }
    bool isSafe(vector<string>& board, int row, int col) {
	    int n = size(board);
	    for(int i = 0; i < n; i++) {
			// checking if there is a queen in the same column
		    if(board[i][col] == 'Q') return false; 
		    // checking if there is a queen in the same diagonal (left to right)
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
		    // No need to traverse more since the lower rows below current row attribute will always be safe.
			/* if(row + i <  n && col - i >= 0 && board[row + i][col - i] == 'Q') return false;
			if(row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') return false; */
	    }
	    return true;
    }
    // Recursive Function (solve) - It basically tries all possible placement of queen for the current row & recurses for it's next row
    void solve(vector<string>& board, int row) {
	// Base condition. 
    // We reached the last row, so we have a solution so we add it to the solution vector
	    if(row == size(board)) { 
		    sols.push_back(board);
		    return;
    	}            
	    // Try placing a queen on each column for a given row. 
        // Explore next row by placing Q at each valid column for the current row
	    for(int col = 0; col < size(board); col++){
		    if(isSafe(board, row, col)) {
			    board[row][col] = 'Q';    // Queen placed on a valid cell
			    solve(board, row + 1);    // Exploring next row
			    board[row][col] = '.';    // Backtracking to get all possible solutions
		    }
        }
    }
};
```
					       
					       
					       
					      
<br /> <br /> <br />**[52. N-Queens II](https://leetcode.com/problems/n-queens-ii/)**<br />
The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.<br />
Given an integer `n`, return _the number of distinct solutions to the **n-queens puzzle**_.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/11/13/queens.jpg"><br />
Input: n = 4<br />
Output: 2<br />
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.<br />

>Example 2:<br />
Input: n = 1<br />
Output: 1<br />

* Constraints: `1 <= n <= 9`<br />
	
```cpp
class Solution {
public:
    int totalNQueens(int n) {
	vector<bool> col(n), diag(2*n-1), anti_diag(2*n-1);
	return solve(col, diag, anti_diag, 0);
}
   
int solve(vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag, int row) {
	int n = size(col), count = 0;
    if(row == n) return 1;
	for(int column = 0; column < n; column++)           
		if(!col[column] && !diag[row + column] && !anti_diag[row - column + n - 1]){ 
			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = true;
			count += solve(col, diag, anti_diag, row + 1); 
			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = false; 
		}                                
	return count;
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
	
	
	
	
<br /> <br /> <br />**[968. Binary Tree Cameras](https://leetcode.com/problems/binary-tree-cameras/)**<br />
You are given the `root` of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.<br />
Return _the minimum number of cameras needed to monitor all nodes of the tree_.<br />
	
>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_01.png"><br />
Input: root = [0,0,null,0,0]<br />
Output: 1<br />
Explanation: One camera is enough to monitor all nodes if placed as shown.<br />
	
>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_02.png"><br />
Input: root = [0,0,null,0,null,0,null,null,0]<br />
Output: 2<br />
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.<br />
 
* Constraints: The number of nodes in the tree is in the range `[1, 1000]`.<br />
`Node.val == 0`<br />
	
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
    
    int camera(TreeNode* root){
        if (root->left==NULL && root->right==NULL){
            root->val=1;
            return 0;
        }
        int res=0,l=2,r=2;
        if (root->left){
            res += camera(root->left);
            l = root->left->val;
        }
        if (root->right){
            res += camera(root->right);
            r = root->right->val;
        }
		// children are unwatched so camera needed
        if (l==1 || r==1){
            root->val = 3;
            return (res+1);
        }
		// camera present
        if (l==3 || r==3){
            root->val = 2;
            return res;
        }
		// current node is unwatched, so it will be watched from its parent node
        root->val=1;
        return res;
    }
    
    int minCameraCover(TreeNode* root) {
        int res = camera(root);
        if (root->val == 1){
            res++;
        }
        return res;
    }
};
```
	

	
	
	
	
<br /> <br /> <br />**[745. Prefix and Suffix Search](https://leetcode.com/problems/prefix-and-suffix-search/)**<br />
Design a special dictionary that searches the words in it by a prefix and a suffix.<br />
Implement the `WordFilter` class:<br />
	
* `WordFilter(string[] words)` Initializes the object with the `words` in the dictionary.<br />
* `f(string prefix, string suffix)` Returns _the index of the word in the dictionary_, which has the prefix `prefix` and the suffix `suffix`. If there is more than one valid index, return **the largest** of them. If there is no such word in the dictionary, return `-1`.<br />
 
>Example 1:<br />
Input<br />
["WordFilter", "f"]<br />
[[["apple"]], ["a", "e"]]<br />
Output<br />
[null, 0]<br /><br />
Explanation<br />
WordFilter wordFilter = new WordFilter(["apple"]);<br />
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".<br />
 
* Constraints: `1 <= words.length <= 15000`<br />
`1 <= words[i].length <= 10`<br />
`1 <= prefix.length, suffix.length <= 10`<br />
`words[i]`, `prefix` and `suffix` consist of lower-case English letters only.<br />
At most `15000` calls will be made to the function `f`.<br />
	
```cpp
class WordFilter {
public:
    unordered_map<string, int> mp; //stores preffix and suffix sequence in it
    
    WordFilter(vector<string>& words) {
        int n = words.size(); 
        for(int i=0; i<n; i++) //cover each word in words
        {
            string word = words[i]; 
            int wordsize = word.size();
            
            //storing all possible sequence of prefix and suffix of a word in the hashmap
            for(int j=1; j<=wordsize; j++) //for preffix 
            {
                string pre = word.substr(0,j);
                
                for(int k=0; k<wordsize; k++) //for suffix
                {
                    string suff = word.substr(k, wordsize);
                    mp[pre + "|" + suff] = i+1; //set index i+1 for all possible sequence of a word
                    //we set i+1 to handle i=0 because by-default map initialized with 0 
                }
            }
        }
    }
    
    int f(string prefix, string suffix) 
    {
        string s = prefix + "|" + suffix;
        return mp[s]-1; //if sequence found in hashmap we return its index
    }
};
/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
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
				 
				 
				 
				 
<br /> <br /> <br />**[630. Course Schedule III](https://leetcode.com/problems/course-schedule-iii/)**<br />
There are `n` different online courses numbered from `1` to `n`. You are given an array `courses` where `courses[i] = [durationi, lastDayi]` indicate that the `ith` course should be taken **continuously** for `durationi` days and must be finished before or on `lastDayi`.<br />
You will start on the `1st` day and you cannot take two or more courses simultaneously.<br />
Return _the maximum number of courses that you can take_.<br />

>Example 1:<br />
Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]<br />
Output: 3<br />
Explanation: <br />
There are totally 4 courses, but you can take 3 courses at most:<br />
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.<br />
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. <br />
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. <br />
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.<br />

>Example 2:<br />
Input: courses = [[1,2]]<br />
Output: 1<br />

>Example 3:<br />
Input: courses = [[3,2],[4,3]]<br />
Output: 0<br />
 
* Constraints: `1 <= courses.length <= 10^4`<br />
`1 <= durationi, lastDayi <= 10^4`<br />
	
```cpp
class Solution
{
public:
    //comparartor function to comare if the lastday of a course
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>> &courses){
        
        //soring according to lastday in increasing order.
        sort(courses.begin(), courses.end(), comp);
        
        //priority queue to store duration of couses
        priority_queue<int> maxD;

        int time = 0; // time to store the total time taken
        for (auto course : courses){
            
            //if total time taken including this course is lesser than or equak to the last day then add couse to queue and add the time to total time
            if (time + course[0] <= course[1]){
                time += course[0];
                maxD.push(course[0]);
            }
            
            //else if there are element in priority queue then check if current course is shorter than the max previous couse then just replace that with current
            else if (!maxD.empty() && maxD.top() >= course[0]){
                time = time - maxD.top() + course[0]; //replacing max previous course with current in toytal time
                maxD.pop();                           //taking out max previous
                maxD.push(course[0]);                 //adding current course
            }
        }
        
        //as queue only contains the courses taken so size of queue is the number of courses.
        return maxD.size();
    }
};
```
	
	

	
	
	
<br /> <br /> <br />**[1354. Construct Target Array With Multiple Sums](https://leetcode.com/problems/construct-target-array-with-multiple-sums/)**<br />
You are given an array `target` of n integers. From a starting array `arr` consisting of `n` 1's, you may perform the following procedure :<br />

 * let `x` be the sum of all elements currently in your array.<br />
 * choose index `i`, such that `0 <= i < n` and set the value of `arr` at index `i` to `x`.<br />
 * You may repeat this procedure as many times as needed.<br />

Return `true` _if it is possible to construct the `target` array from `arr`, otherwise, return_ `false`.<br />

>Example 1:<br />
Input: target = [9,3,5]<br />
Output: true<br />
Explanation: Start with arr = [1, 1, 1]<br /> 
[1, 1, 1], sum = 3 choose index 1<br />
[1, 3, 1], sum = 5 choose index 2<br />
[1, 3, 5], sum = 9 choose index 0<br />
[9, 3, 5] Done<br />

>Example 2:<br />
Input: target = [1,1,1,2]<br />
Output: false<br />
Explanation: Impossible to create target array from [1,1,1,1].<br />

>Example 3:<br />
Input: target = [8,5]<br />
Output: true<br />
 
* Constraints: `n == target.length`<br />
`1 <= n <= 5 * 10^4`<br />
`1 <= target[i] <= 10^9`<br />

```cpp
class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        //Priority queue for storing all the nums in taget in decreasing order.
        priority_queue<int> pq;
        long long sum = 0; //for storing total sum

        for(auto num : target){ //adding the nums in pq and sum
            pq.push(num);
            sum+=num;
        }
        
        //iterating untill all elements in pq become 1 (in turn pq.top() will also become 1);
        while(pq.top() != 1){

            sum -= pq.top(); //removing the greatest element as it was last upadted when converting [1,1,1...] array to target. So we are left with sum of other elements.
            
            //when there are elements greeter than 1 then sum of other elements can not be 0 or sum can not be greater than top element because sum + x(any number>0) is pq.top().
            if(sum == 0 || sum >= pq.top()) return false;
            
            //if we delete all copies of sum from pq.top() we get an old element.
            int old = pq.top() % sum;
            
            //all old elements were > 0 so it can not be 0 unless sum is 1 (This is only possible if array has only 2 elements)
            if(sum != 1 && old == 0) return false;
            
            pq.pop();     //Deleting greatest element

            pq.push(old); //Adding old element to restore array.
            sum += old;   //Updating sum
        }
        
        //if all elements are 1 then return true
        return true;
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

								
								
								
								
							
<br /> <br /> <br />**[135. Candy](https://leetcode.com/problems/candy/)**<br />
There are `n` children standing in a line. Each child is assigned a rating value given in the integer array `ratings`.<br />
You are giving candies to these children subjected to the following requirements:<br />
	
 * Each child must have at least one candy.<br />
 * Children with a higher rating get more candies than their neighbors.<br />
	
Return `the minimum number of candies you need to have to distribute the candies to the children`.<br />

>Example 1:<br />
Input: ratings = [1,0,2]<br />
Output: 5<br />
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.<br />

>Example 2:<br />
Input: ratings = [1,2,2]<br />
Output: 4<br />
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.<br />
The third child gets 1 candy because it satisfies the above two conditions.<br />
 
* Constraints: `n == ratings.length`<br />
`1 <= n <= 2 * 10^4`<br />
`0 <= ratings[i] <= 2 * 10^4`<br />
	
```cpp
Alternate O(n) Space Approach :

We can easily calculate the number of candy needed by using an array to store the candy of each child. 
And after that traverse the rating array twice. The first loop makes sure children with a higher rating
get more candy than its left neighbor, the second loop makes sure children with a higher rating get more 
candy than its right neighbor. At last add the total number of candies. This approach is O(n) time and O(n) space. 

class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size(), sum = 0;
        vector<int> res(n, 1);  // initialize the resultant array with all elements 1 since each child will get minimum 1 candy
        
        if (n == 1) 
        {
            return 1;
        }
        
        // traverse the given ratings array and if the value of rat[i + 1] is greater than rat[i],
        // then update the value of ans[i + 1] as ans[i] + 1
        // this is to make sure higher rating one gets more than right neighbour
        for(int i=0; i<n-1; i++)
        {
            if (rat[i+1] > rat[i]) 
            {
                res[i+1] = res[i] + 1;
            }
        }
        
        // traverse the given array from the back and if the value of rat[i] > rat[i + 1] and the value of res[i] <= res[i + 1],
        // then update the value of res[i] as res[i + 1] + 1
        // this is to make sure higher rating one gets more than left neighbour
        for (int i=n-2; i>=0; i--) 
        {
            if (rat[i] > rat[i+1] && res[i] <= res[i+1]) 
            {
                res[i] = res[i+1]+1;
            }
        
            sum += res[i]; // increment the sum by res[i]
        }
        
        sum += res[n-1]; // increment with last element as it was left earlier
        
        return sum; // return the resultant sum
    }
};



O(1) Space Approach :
We can consider this problem like valley and peak problem. In each valley there should be 1 candy 
and for each increasing solpe in either side we need to increse candy by 1. Peaks have highest candy. 
If any equal rating is found then candy resets to 1 as two equal neighbours may have any number of candies. 
The peak should contain the higher number of candy between which is calculated from the incresing slope and 
which is calculated from decreasing slope. Because this will satisfy the condition that peak element is 
having more candies than its neighbours.

Example :

Let take the Rating as : [1,3,6,8,9,5,3,6,8,5,4,2,2,3,7,7,9,8,6,6,6,4,2]

Each child represented as rating(candy he is given)
Peak = max(peak, valley)

See when peak is encountered we take max of the peak calculated from left and valley calculated from right.
When we get any equal element it gets reset to 1 candy or if it is peak we take max(0, right valley)

           (5)         (4)                         (3)
            9           8                           9
           /|\         /|\                         /|\
          / | \       / | \                (3)    / | \
      (4)8  |  5(2)  6  |  5(3)             7 __ 7  |  8(2)
        /   |   \   (2) |   \              /|   (1) |   \
       /    |    \ /    |    \            / |    |  |    \         (3)
   (3)6     |     3     |     4(2)       3(2)    |  |     6 __ 6 __ 6    -> Total candy = 50
     /      |    (1)    |      \        /   | Reset |    (1)  (1)   |\
    /       |           |       \      /    |  to 1 |          |    | \
(2)3        |           |        2 __ 2     |       |          |    |  4(2)
  /         |           |       (1)  (1)    |       |        Reset  |   \
 /          |           |                   |       |         to 1  |    \
1(1)        |           |                   |       |               |     2(1)
   Peak= max(5,3)  Peak= max(3,4)    Peak= max(3,0) |         Peak= max(0,3)
                                               Peak= max(2,3)   
Implementation :

So we take initially n candy for n children. Then we start traversing the rating array from the second element. 
If we find equal elements we continue to next element as they already have 1 candy.

If an increasing slop is found (ratings[i] > ratings [i-1]) we increase value of peak and and add the peak value to candy. 
After each iteration new peak is found and the value is added to candy. In this way we also get the value of minimum 
height of the peak at the end.

If a decreasing slope is found (ratings[i] < ratings [i-1]) we calculate the depth of the valley which is in turn 
the minimum height of the previous peak. In each iteration we increse the valley by 1 and add it to the candy. 
You can visualise it as 1 candy is added to each of the previous members untill peak or the new peak value is 
interted at the previous peak and other values are shifted to right by 1 place. We also need to check if it is 
going out of array if so then return the number of candy.

After this we can see we have added the peak value twice in candy once as peak and once as valley. 
But we need only the max value out of these two so we substract the min(peak, valley) from candy.

After that return the candy.

Note : We have considered the sequence increasing -> decreasing as peak should have the max value between the 
height of left (increasing) side and height of right (decreasing) side. In case of decresing -> increasing we 
dont need to give special attention as the vallley will always have 1 candy and in our code in this case peak 
will have 0 value so nothing will be substracted from the candy in the end of iteration.

See the example for better understanding :

In our code we increase the peak and add peak value untill we get the minimum actual peak.
In case of the decreasing part take this example.

[7,5,3,2], initial candy = 4, In each iteration valley++ and candy += valley

7 starting (valley = 0, candy = 4, candy configuaration  = [1,1,1,1])
 \
  5 (valley = 1, candy = 4+1 = 5, candy configuaration  = [2,1,1,1])
   \
    3 (valley = 2, candy = 5+2 = 7, candy configuaration = [3,2,1,1])
     \
      2 [valley = 3, candy = 7+3 = 10, candy configuartion = [4,3,2,1])
	  
Here see the valley is at last equal to the minimum previous peak value.

As we have given 1 candy to all before so the peak and valley values are actually 1 less than the actual candy they should get.


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n, i=1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            
            //For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }
            candy -= min(peak, valley); //Keep only the higher peak
        }
        return candy;
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
