# Leetcode daily  hard question 
**[2183. Count Array Pairs Divisible by K](https://leetcode.com/problems/count-array-pairs-divisible-by-k/)**<br />
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

	
	
	
	
	
	

<br /> <br /> <br />**[1473. Paint House III](https://leetcode.com/problems/paint-house-iii/)**<br />
There is a row of `m` houses in a small city, each house must be painted with one of the `n` colors (labeled from `1` to `n`), some houses that have been painted last summer should not be painted again.<br />
A neighborhood is a maximal group of continuous houses that are painted with the same color.<br />

 * For example: `houses = [1,2,2,3,3,2,1,1]` contains `5` neighborhoods `[{1}, {2,2}, {3,3}, {2}, {1,1}]`.<br />
 
Given an array `houses`, an `m x n` matrix `cost` and an integer `target` where:<br />

 * `houses[i]`: is the color of the house `i`, and `0` if the house is not painted yet.<br />
 * `cost[i][j]`: is the cost of paint the house `i` with the color `j + 1`.<br />
 
Return the _minimum cost of painting all the remaining houses in such a way that there are exactly `target` neighborhoods_. If it is not possible, return `-1`.<br />

>Example 1:<br />
Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3<br />
Output: 9<br />
Explanation: Paint houses of this way [1,2,2,1,1]<br />
This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].<br />
Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.<br />

>Example 2:<br />
Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3<br />
Output: 11<br />
Explanation: Some houses are already painted, Paint the houses of this way [2,2,1,2,2]<br />
This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}].<br /> 
Cost of paint the first and last house (10 + 1) = 11.<br />

>Example 3:<br />
Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3<br />
Output: -1<br />
Explanation: Houses are already painted with a total of 4 neighborhoods [{3},{1},{2},{3}] different of target = 3.<br />
 
* Constraints: `m == houses.length == cost.length`<br />
`n == cost[i].length`<br />
`1 <= m <= 100`<br />
`1 <= n <= 20`<br />
`1 <= target <= m`<br />
`0 <= houses[i] <= n`<br />
`1 <= cost[i][j] <= 10^4`<br />	

```cpp
int n;
vector<int> houses;
vector<vector<int>> cost;
vector<vector<vector<int>>> dp;
int c;
int rec(int i, int last, int target) {
    // Pruning
    if(target < 0 ) return -1; // we cant make negative target, also we can't access dp[][][-veTarget] so prune it initially.
	
    // cout<<"Checking Base case : "<<endl;
    // base case
    if(i==n && target!=0) { // it can be so that we have not made required targets.
        return -1;
    }
    if(i==n && target==0) {
        return 0;
    }
    
    // cache check
    // cout<<"Checking Cache : "<<endl;
    
    if(dp[i][last][target]!=-2) {
        return dp[i][last][target];
    }
    // cout<<"Cache not found"<<endl;
	
    int ans=INT_MAX; // keeping answer as INT_MAX because we will take minimum with possible answer.
    bool possible=false; // No color is possible till now 
	
    // cout<<"Checking if house already colored "<<endl;
    if(houses[i]!=0) {
        if(houses[i]!=last) {
            return dp[i][last][target]=rec(i+1,houses[i],target-1);
        }
        else {
            return dp[i][last][target]=rec(i+1,houses[i],target);
            }
    }
    // cout<<"House Not colored last summer"<<endl;
	
    // cout<<"Trying all colors : "<<endl;
    for(int k=0;k<c;k++) {
        // choice of color is k+1
        // index is k
        // cout<<"Trying color : "<<k+1<<endl;
        int temp;
        if(k+1 != last) {
         temp=rec(i+1,k+1,target-1);        
        }
        else {
            temp=rec(i+1,k+1,target);        
        }
        // if this color is possible
        if(temp!=-1) {
            // cout<<k+1<<" color is possible"<<endl;
            possible=true;
            ans=min(ans,cost[i][k]+temp);
        }
    }
    if(possible) {
    return dp[i][last][target]=ans;
                
    }
    else { // no possible color found for this place, as we need to color all houses, => answer is -1.
        return dp[i][last][target]=-1;
    }
    
}

class Solution {
public:
    int minCost(vector<int>& house, vector<vector<int>>& cst, int r, int col, int target) {
        cost=cst;
        houses=house;
        c=col;
        n=r;
		dp.resize(n+1);
        for(int i=0;i<=n;i++) {
            dp[i].resize(n+1);
            for(int j=0;j<=n;j++) {
                dp[i][j].resize(target+1);
                for(int k=0;k<=target;k++) {
                    dp[i][j][k]=-2;
                }
            }
        }
		//dp.resize(m+1 , vector<vector<int>>(n+1 , vector<int>(target+1 , -2));
        // cout<<"initialised: "<<endl;
        return rec(0,0,target); // hope nobody acceses -1 index in dp
        // return -1;
    }
};
```












<br /> <br /> <br />**[629. K Inverse Pairs Array](https://leetcode.com/problems/k-inverse-pairs-array/)**<br />
For an integer array `nums`, an **inverse pair** is a pair of integers `[i, j]` where `0 <= i < j < nums.length` and `nums[i] > nums[j]`.<br />
Given two integers n and k, return the number of different arrays consist of numbers from `1` to `n` such that there are exactly `k` **inverse pairs**. Since the answer can be huge, return it **modulo** `10^9 + 7`.<br />

>Example 1:<br />
Input: n = 3, k = 0<br />
Output: 1<br />
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.<br />

>Example 2:<br />
Input: n = 3, k = 1<br />
Output: 2<br />
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.<br />

* Constraints: `1 <= n <= 1000`<br />
`0 <= k <= 1000`<br />

```cpp
const int mod = 1e9 + 7, N = 1010;

class Solution {
    int f[N][N] = {};
public:
    int kInversePairs(int n, int K) {
        f[0][0] = 1;
        for (int i = 1; i <= n; ++ i) // 1000
        {
            long long s = 0; // maintain a window that is length min(i, j);
            for (int j = 0; j <= K; ++ j) // 1000
            {
                s += f[i - 1][j];
                if (j >= i)
                    s -= f[i - 1][j - i];
                f[i][j] = ((long long)f[i][j] + s) % mod; 
            }
        }
        return f[n][K];
    }
};
```













<br /> <br /> <br />**[1074. Number of Submatrices That Sum to Target](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/)**<br />
Given a `matrix` and a `target`, return the number of non-empty submatrices that sum to target.<br />
A submatrix `x1`, `y1`, `x2`, `y2` is the set of all cells `matrix[x][y]` with `x1 <= x <= x2` and `y1 <= y <= y2`.<br />
Two submatrices `(x1, y1, x2, y2)` and `(x1', y1', x2', y2')` are different if they have some coordinate that is different: for example, if `x1 != x1'`.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/09/02/mate1.jpg"><br />
Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0<br />
Output: 4<br />
Explanation: The four 1x1 submatrices that only contain 0.<br />

>Example 2:<br />
Input: matrix = [[1,-1],[-1,1]], target = 0<br />
Output: 5<br />
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.<br />

>Example 3:<br />
Input: matrix = [[904]], target = 0<br />
Output: 0<br />
 
* Constraints: `1 <= matrix.length <= 100`<br />
`1 <= matrix[0].length <= 100`<br />
`-1000 <= matrix[i] <= 1000`<br />
`-10^8 <= target <= 10^8`<br />

```cpp
//  Prefix-Sum || Sliding Window
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 1; j < n; j++){
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        int count = 0;        
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                map<int, int> mp;
                mp[0] = 1;
                int sum = 0;
                for (int k = 0; k < m; k++){
                    sum += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    count += mp[sum - target];
                    mp[sum]++;
                }
            }
        }
        return count;
    }
};
```
