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












<br /> <br /> <br />**[315. Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)**<br />
You are given an integer array `nums` and you have to return a new `counts` array. The `counts` array has the property where `counts[i]` is the number of smaller elements to the right of `nums[i]`.<br />

>Example 1:<br />
Input: nums = [5,2,6,1]<br />
Output: [2,1,1,0]<br />
Explanation:<br />
To the right of 5 there are 2 smaller elements (2 and 1).<br />
To the right of 2 there is only 1 smaller element (1).<br />
To the right of 6 there is 1 smaller element (1).<br />
To the right of 1 there is 0 smaller element.<br />

>Example 2:<br />
Input: nums = [-1]<br />
Output: [0]<br />

>Example 3:<br />
Input: nums = [-1,-1]<br />
Output: [0,0]<br />
 
* Constraints: `1 <= nums.length <= 10^5`<br />
`-10^4 <= nums[i] <= 10^4`<br />

```cpp
class Solution {
public:
    void merge(vector<int>& arr, int l, int mid, int r,vector<pair<int,int>>& v,vector<int>& count){
        vector<pair<int,int>> temp(r-l+1);
        int i = l;
        int j= mid + 1;
        int k = 0;
        
        while(i<=mid && j<=r){                                                    
            if(v[i].first<=v[j].first) temp[k++] = v[j++];
            else{
                count[v[i].second] += r-j+1;
                temp[k++] = v[i++];
            }
        }
        
        while(i<=mid)temp[k++] = v[i++];
        while(j<=r)temp[k++] = v[j++];
        
        for(int i=l;i<=r;i++)v[i] = temp[i-l];
        
    }
    void mergeSort(vector<int>& arr, int l, int r,vector<pair<int,int>>& v,vector<int>& count){
        if(l>=r) return ;
        int mid = (l+r)/2;
        mergeSort(arr,l,mid,v,count);
        mergeSort(arr,mid+1,r,v,count);
        merge(arr,l,mid,r,v,count);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);                                        
        for(int i=0;i<n;i++) v[i] = {nums[i],i};
        vector<int> count(n,0);                                       
        mergeSort(nums,0,n-1,v,count);                                
       // for(int i=0;i<n;i++) cout<<v[i].first<<" ";
        return count;
    }
};
//Time Complexity : O(nlongn)     //Due to merge sort
//Space Complexity : O(n)         //For implementing vector of size n
```










<br /> <br /> <br />**[1220. Count Vowels Permutation](https://leetcode.com/problems/count-vowels-permutation/)**<br />
Given an integer `n`, your task is to count how many strings of length `n` can be formed under the following rules:<br />

 * Each character is a lower case vowel `('a', 'e', 'i', 'o', 'u')`<br />
 * Each vowel `'a'` may only be followed by an `'e'`.<br />
 * Each vowel `'e'` may only be followed by an `'a'` or an `'i'`.<br />
 * Each vowel `'i'` **may not** be followed by another `'i'`.<br />
 * Each vowel `'o'` may only be followed by an `'i'` or a `'u'`.<br />
 * Each vowel `'u'` may only be followed by an `'a'`.<br />

Since the answer may be too large, return it modulo `10^9 + 7`.<br />

>Example 1:<br />
Input: n = 1<br />
Output: 5<br />
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".<br />

>Example 2:<br />
Input: n = 2<br />
Output: 10<br />
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".<br />

>Example 3: <br />
Input: n = 5<br />
Output: 68<br />

* Constraints: `1 <= n <= 2 * 10^4`<br />

```cpp
class Solution {
public:
    int countVowelPermutation(int n) {
         long a = 1, e = 1, i = 1, o = 1, u = 1, mod = pow(10, 9)+7;
        long a2, e2, i2, o2, u2; 
        
        for (int j = 2; j <= n; j++) {
            a2 = (e + i + u) % mod;
            e2 = (a + i) % mod;
            i2 = (e + o) % mod;
            o2 = i;
            u2 = (o + i) % mod;
            
            a = a2, e = e2, i = i2, o = o2, u = u2;
        }
        return (a + e + i + o + u) % mod;
    }
};
```
Each vowel allows some number of subsequent characters. These transitions are like a tree. This problem is asking, "what's the width of the tree with height n?"<br />
<img src = "https://assets.leetcode.com/users/images/6423763e-0cb1-4ecd-af60-a979c08d01b7_1659839040.3599339.png"><br />
solution keeps track of the number of each vowel at a level in this tree. To calculate say `'A'`, we calculate how many nodes in the previous level produce `'A'`. This is the number of `'E'`, `'I'`, and `'U'` nodes.<br />





<br /> <br /> <br />**[30. Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)**<br />
You are given a string `s` and an array of strings `words` of **the same length**. Return all starting indices of substring(s) in `s` that is a concatenation of each word in `words` **exactly once, in any order**, and **without any intervening characters**.<br />
You can return the answer in **any order**.<br />

>Example 1:<br />
Input: s = "barfoothefoobarman", words = ["foo","bar"]<br />
Output: [0,9]<br />
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.<br />
The output order does not matter, returning [9,0] is fine too.<br />

>Example 2:<br />
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]<br />
Output: []<br />

>Example 3:<br />
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]<br />
Output: [6,9,12]<br />

* Constraints: `1 <= s.length <= 10^4`<br />
`1 <= words.length <= 5000`<br />
`1 <= words[i].length <= 30`<br />
`s` and `words[i]` consist of lowercase English letters.<br />

```cpp
class Solution {
public:
    void find_sub_str(string s, vector<string>& words, int start, vector<int>&ans,unordered_map<string,int> count){
        int word_size = words[0].size();	//each word size
        int times = words.size();		//times that I should get a substr 
        int end_pos = start + times*word_size - 1;
        if(end_pos > s.size() )			//if end pos > s.size() return
            return;
        
        unordered_map<string,int> record;	//record the count of word we have used
        for(int i=start;i<=end_pos;){		//from start to end_pos
            while(times){
                string sub_str = s.substr(i,word_size);		//get substring
				
						// find if substring in words 
                auto it = find(words.begin(),words.end(),sub_str);
                if(it != words.end()){		//true
                    record[sub_str]++;		//record it and count it
                }else{//false return 
                    return;
                }
                i+=word_size;
                times--;
            }
        }
		
						//check if two unordered_map  is  same
        if(record == count) 			//true push_back the start index to ans
            ans.push_back(start);
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int word_size = words[0].size(); 	//each word size
        int times = words.size(); 		//times that I should get a substr 
		
						// we should calculate the times of each word (in words) 
						// this unordered_map will be used in the function 
        unordered_map<string,int> count;
        for(auto w:words)
            count[w] += 1;
		
		/*
		 At the begining, I use the same way in the above function to find corrected substring
		 (use word size to get substring and let start_pos += word size )
		 but it will get WA
		 
		 ex: s = "fofoobar" words=["foo","bar"]
		
		- WA solution,  word size = 3
		 start_pos = 0 , substr = "fof" (not match in words)
		 start_pos = 0 + 3 = 3,  substr = "oob"
		 
		 but it will miss the correct answer
		 start_pos = 2 , substr = "foo"
		 -> get answer 2
		 
		 -Correct Soltuion
		 each char in s should get a substr
		 then we won't miss any substr
		*/
        for(int i=0;i<s.size();i++){    
            string sub_str = s.substr(i,word_size);
  
            auto it = find(words.begin(),words.end(),sub_str);
            if(it != words.end()){			//if substr in words
                find_sub_str(s, words, i,ans,count); 	//do the function
            }
        }     
        return ans;
    }
};
```




<br /> <br /> <br />**[871. Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/)**<br />
A car travels from a starting position to a destination which is `target` miles east of the starting position.<br />
There are gas stations along the way. The gas stations are represented as an array `stations` where `stations[i] = [positioni, fueli]` indicates that the `ith` gas station is `positioni` miles east of the starting position and has `fueli` liters of gas.<br />
The car starts with an infinite tank of gas, which initially has `startFuel` liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.<br />
Return _the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination_, return `-1`.<br />
**Note**<br />
that if the car reaches a gas station with `0` fuel left, the car can still refuel there. If the car reaches the destination with `0` fuel left, it is still considered to have arrived.<br />

>Example 1:<br />
Input: target = 1, startFuel = 1, stations = []<br />
Output: 0<br />
Explanation: We can reach the target without refueling.<br />

>Example 2:<br />
Input: target = 100, startFuel = 1, stations = [[10,100]]<br />
Output: -1<br />
Explanation: We can not reach the target (or even the first gas station).<br />

>Example 3:<br />
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]<br />
Output: 2<br />
Explanation: We start with 10 liters of fuel.<br />
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.<br />
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),<br />
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.<br />
We made 2 refueling stops along the way, so we return 2. <br />

* Constraints: `1 <= target, startFuel <= 10^9`<br />
`0 <= stations.length <= 500`<br />
`1 <= positioni < positioni+1 < target`<br />
`1 <= fueli < 10^9`<br />

```cpp
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        priority_queue<int> pq; //max heap
        /*
			if we can't reach target, I will first use the largestfuel Station
			(which can take me farthest) and move ahead and keep doing this.
        */
        int curr = startFuel; //my current position
        int i = 0; //station index
        int result = 0;
        while(curr < target) { //until I reach my target
            while(i < n && curr >= stations[i][0]) {
                /*
					  Sice, I am already ahead of or at this station
					  (i.e. curr >= stations[i][0])  we don't use this
					  station and try to move ahead but I store this
					  station in maxheap to use in future
				*/
                pq.push(stations[i][1]);
				//Keep the station at top which can take me farthest (maximum gas)
                i++;
            }
            
            if(pq.empty()) //we can't move further now
                return -1;
            
            int dist = pq.top();
            pq.pop();
            
            curr += dist;
            result++;
        }
        
        return result;
        
    }
};
//O(nlog(n)) using max-heap
```





<br /> <br /> <br />**[936. Stamping The Sequence](https://leetcode.com/problems/stamping-the-sequence/)**<br />
You are given two strings `stamp` and `target`. Initially, there is a string `s` of length `target.length` with all `s[i] == '?'`.<br />
In one turn, you can place `stamp` over `s` and replace every letter in the `s` with the corresponding letter from `stamp`.<br />

 * For example, if `stamp = "abc"` and `target = "abcba"`, then `s` is `"?????"` initially. In one turn you can:<br />
   * place `stamp` at index `0` of `s` to obtain `"abc??"`,<br />
   * place `stamp` at index `1` of `s` to obtain `"?abc?"`, or<br />
   * place `stamp` at index `2` of `s` to obtain `"??abc"`.<br />
 Note that `stamp` must be fully contained in the boundaries of `s` in order to stamp (i.e., you cannot place `stamp` at index `3` of `s`).<br />
 
We want to convert `s` to `target` using **at most** `10 * target.length` turns.<br />
Return _an array of the index of the left-most letter being stamped at each turn_. If we cannot obtain `target` from `s` within `10 * target.length` turns, return an empty array.<br />

Example 1:<br />
<pre>
Input: stamp = "abc", target = "ababc"
Output: [0,2]
Explanation: Initially s = "?????".
- Place stamp at index 0 to get "abc??".
- Place stamp at index 2 to get "ababc".
[1,0,2] would also be accepted as an answer, as well as some other answers.
</pre>
Example 2:<br />
<pre>
Input: stamp = "abca", target = "aabcaca"
Output: [3,0,1]
Explanation: Initially s = "???????".
- Place stamp at index 3 to get "???abca".
- Place stamp at index 0 to get "abcabca".
- Place stamp at index 1 to get "aabcaca".
</pre>

* Constraints: `1 <= stamp.length <= target.length <= 1000`<br />
`stamp` and `target` consist of lowercase English letters.<br />

```cpp
class Solution {
public:
    
    bool canReplace(string &stamp,string &target,int pos){
        int m=stamp.size(),n=target.size();
        for(int i=0;i<m;i++){
            if(target[i+pos]!='?' and target[i+pos]!=stamp[i])
                return false;
        }
        return true;
    }
    
    
    int replace(string &stamp,string &target,int pos){
        int cnt=0;
        int m=stamp.size(),n=target.size();
        for(int i=0;i<m;i++){
            if(target[i+pos]!='?'){
                cnt++;
                target[i+pos]='?';
            }
        }
        return cnt;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        
        vector<int> ans;
        
        int m=stamp.size(),n=target.size();
        
        int count=0;
        
        vector<int> vis(n+1,0);
        
        while(count!=n){
            bool flag=false;
            for(int i=0;i<=n-m;i++){
                if(!vis[i] and canReplace(stamp,target,i)){
                    vis[i]=1;
                    count+=replace(stamp,target,i);
                    flag=true;
                    ans.push_back(i);
                    if(count==n) break;
                }
            }
            if(!flag) return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```



<br /> <br /> <br />**[363. Max Sum of Rectangle No Larger Than K](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)**<br />
Given an `m x n` matrix `matrix` and an integer `k`, return _the max sum of a rectangle in the matrix such that its sum is no larger than k_.<br />
It is **guaranteed** that there will be a rectangle with a sum no larger than `k`.<br />

Example 1:
<pre>
<img src = "https://assets.leetcode.com/uploads/2021/03/18/sum-grid.jpg">
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, 
and 2 is the max number no larger than k (k = 2).
</pre>
Example 2:
<pre>
Input: matrix = [[2,2,-1]], k = 3
Output: 3
</pre>

* Constraints: `m == matrix.length`<br />
`n == matrix[i].length`<br />
`1 <= m, n <= 200`<br />
`-100 <= matrix[i][j] <= 100`<br />
`-10^5 <= k <= 10^5`<br />

```cpp
class Solution {
public:
    int maxSubarraySum(vector<int>& sum, int k, int row){
        int curSum= 0, curMax = INT_MIN;
        set<int>sumSet;
        sumSet.insert(0);
        for(int r = 0;r<row;r++){
            curSum += sum[r];
            auto it = sumSet.lower_bound(curSum - k);
            if(it != sumSet.end()){
                curMax = max(curMax, curSum - *it);
            }
            sumSet.insert(curSum);
        }
        return curMax;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ret = INT_MIN;
        for(int i = 0;i<col;i++){
            vector<int>sum(row, 0);
            for(int j = i;j<col;j++){
                for(int r = 0;r<row;r++){
                    sum[r] += matrix[r][j];
                }
                int cur_max = maxSubarraySum(sum, k, row);
                ret = max(ret, cur_max);
            }
        }
        return ret;
    }
};
```




<br /> <br /> <br />**[987. Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)**<br />
Given the `root` of a binary tree, calculate the **vertical order traversal** of the binary tree.<br />
For each node at position `(row, col)`, its left and right children will be at positions `(row + 1, col - 1)` and `(row + 1, col + 1)` respectively. The root of the tree is at `(0, 0)`.<br />
The **vertical order traversal** of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.<br />
Return the **vertical order traversal** of the binary tree.<br />

Example 1:
<pre>
<img src = "https://assets.leetcode.com/uploads/2021/01/29/vtree1.jpg">
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
</pre>
Example 2:
<pre>
<img src = "https://assets.leetcode.com/uploads/2021/01/29/vtree2.jpg">
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.
</pre>
Example 3:
<pre>
<img src = "https://assets.leetcode.com/uploads/2021/01/29/vtree3.jpg">
Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
</pre>

* Constraints: The number of nodes in the tree is in the range `[1, 1000]`.<br />
`0 <= Node.val <= 1000`<br />

**Intuition:**<br />
 * We firstly need to assign `vertical` and `level` to every node.<br />
 * After we complete the assigning part then we need to figure out how can we store them in a suitable `Data Structure`.<br />
 * The data structure should give us the nodes with `left-side vertical` first and in every vertical, top-level `node` should appear `first`.<br />

**Visualization of how the vertical lines passing through the nodes will look like:**<br />
<img src = "https://lh3.googleusercontent.com/CGWyay17cv42ML-r95VSl7rjxHCbfPG4ZbTEMtPWl-XMzdrx3g8ebGA2ppUsLXBb61Eg0bPAK2j7QKloCiVmtYvuOjdHUkggnEX5yalfqOSU09-sB6gJWPT9sS_mveAXwy066_py"><br />
**Approach:**<br />
 * We will perform a `tree traversal` and assign a `vertical` and `level` to every node.<br />
 * Based on this vertical and node, we store the node in our `special` data structure that we are gonna create.<br />
 * For easy understanding, let's break it into `three` steps:<br />

**Step-1: Vertical and Level Assign to every node:**<br />
 * We are going to use `level` order traversal, initially we will push the `root` in the queue and also two more variables one for `vertical` and the other for `level`, both intialized with `0`.<br />
 * Whenever we push the `left child` we are going to decrease the vertical by one and increase level by 1 and in the case of right child we are going to increase both the vertical and level both by 1.<br />

**Step-2: Storing Verticals and Levels to our Data Structure:**<br />
 * We require a data structure that can store nodes according to their vertical value and give us the nodes of least values first.<br />
 * Hence we will use a `map` as it satisfies both criterias.<br />
 * Lastly for every level, we need a data-structure which can store node values in a `sorted` order.<br />
 * Moreover, as `duplicate` values are allowed in our tree, our data structure needs to handle this well. This is acheived by using `multiset` in C++<br />
   How the data structure will look like --> `map<int,map<int,multiset>> mp`;<br />
   
**Step-3: Finally just print the vertical order traversal from the data structure that we have built:**<br />
 * Just iterate over our verticals by using the data structure that we created.<br />
 * In every iteration, we take a `list`(to store all nodes of that vertical) and again iterate over the levels. We then push the nodes of the level (stored in the multiset/priority queue) and push it to our vertical list.<br />
 * Once we iterate over all verticals we get our vertical order traversal.<br />

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            mp[x][y].insert(node->val);
            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto q:mp){
            vector<int> col;
            for(auto p:q.second){
                col.insert(col.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

//Time Complexity: O(NlogNlogN*logN)
//Space Complexity: O(N)
```




<br /> <br /> <br />**[1383. Maximum Performance of a Team](https://leetcode.com/problems/maximum-performance-of-a-team/)**<br />
You are given two integers `n` and `k` and two integer arrays `speed` and `efficiency` both of length `n`. There are `n` engineers numbered from `1` to `n`. `speed[i]` and `efficiency[i]` represent the speed and efficiency of the `ith` engineer respectively.<br />
Choose **at most** `k` different engineers out of the `n` engineers to form a team with the maximum `performance`.<br />
The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.<br />
Return _the maximum performance of this team_. Since the answer can be a huge number, return it **modulo** `10^9 + 7`.<br />

Example 1:
<pre>
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation: 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) 
and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
</pre>
Example 2:
<pre>
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and 
engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
</pre>
Example 3:
<pre>
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72
</pre> 

* Constraints: `1 <= k <= n <= 10^5`<br />
`speed.length == n`<br />
`efficiency.length == n`<br />
`1 <= speed[i] <= 10^5`<br />
`1 <= efficiency[i] <= 10^8`<br />

```cpp
class Solution{
public:
    const int mod = (int)1e9 + 7;
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k){
      // to maintain the heap of size k we will use priority queue
      priority_queue<int, vector<int>, greater<int>> pq;
      // to store the pair of efficiency and speed
      vector<pair<int, int>> v;
      for (int i = 0; i < n; i++){
        v.push_back({efficiency[i], speed[i]});
      }
	  // sort in decreasing order of efficiency
      sort(v.rbegin(), v.rend()); 
	  // totSpeed is the sum of speed of k engineers
      long totSpeed = 0, ans = 0;
	  // iterate over all engineers
      for (int i = 0; i < n; i++) {
        int currEff = v[i].first;
        int currSpeed = v[i].second;
		// if the size of pq is k
        if (pq.size() == k) {
		  // remove the minimum speed from the pq
          totSpeed -= pq.top();
          pq.pop();
        }
		// push the current speed in the pq
        pq.push(currSpeed); 
		// add the current speed to the totSpeed
        totSpeed += currSpeed; 
		// update the ans
        ans = max(ans, totSpeed * currEff); 
      }
      return ans % mod;
    }
};

//Time Complexity: O(N * (logN + logK))
//Space Complexity: O(N + K) where N is the total number of candidates and K is the size of team
```








<br /> <br /> <br />**[1770. Maximum Score from Performing Multiplication Operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/)**<br />
You are given two **0-indexed** integer arrays `nums` and `multipliers` of size `n` and `m` respectively, where `n >= m`.<br />
You begin with a score of `0`. You want to perform **exactly** `m` operations. On the `ith` operation (**0-indexed**) you will:<br />

* Choose one integer `x` from **either the start or the end** of the array `nums`.<br />
* Add `multipliers[i] * x` to your score.<br />
  * Note that `multipliers[0]` corresponds to the first operation, `multipliers[1]` to the second operation, and so on.<br />
* Remove `x` from `nums`.<br />

Return _the **maximum** score after performing `m` operations_.<br />
<pre>
Example 1:
Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
</pre>
<pre>
Example 2:
Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
The total score is 50 + 15 - 9 + 4 + 42 = 102.
</pre>

* Constraints: `n == nums.length`<br />
`m == multipliers.length`<br />
`1 <= m <= 300`<br />
`m <= n <= 10^5`<br />
`-1000 <= nums[i], multipliers[i] <= 1000`<br />

```cpp
class Solution {
public:
     	vector<vector<int>> dp;
   	int helper(int index,vector<int>& nums, vector<int>& multi, int start) {    
		if (dp[index][start] != INT_MIN) return dp[index][start];
    		int end= nums.size()-1-(index-start);
      		if(index== multi.size())  return 0;
       		return dp[index][start]= max(multi[index]*nums[start]+ helper(index+1, nums,multi, start+1),multi[index]*nums[end]+ helper(index+1, nums, multi, start) );   
   	}
    	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        	int n= nums.size();
        	int m= multipliers.size();
         	dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        	return helper(0, nums, multipliers, 0);
    	}
};
```









<br /> <br /> <br />**[336. Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/)**<br />
You are given a `0-indexed` array of `unique` strings `words`.<br />
A **palindrome pair** is a pair of integers `(i, j)` such that:<br />

* `0 <= i, j < word.length`,<br />
* `i != j`, and<br />
* `words[i] + words[j]` (the concatenation of the two strings) is a palindrome string.<br />

Return _an array of all the **palindrome pairs** of `words`._<br />

<pre>
Example 1:
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
</pre>
<pre>
Example 2:
Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
</pre>
<pre>
Example 3:
Input: words = ["a",""]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["a","a"]
</pre>
* Constraints: `1 <= words.length <= 5000`<br />
`0 <= words[i].length <= 300`<br />
`words[i]` consists of lowercase English letters.<br />

```cpp
struct TrieNode {
    TrieNode *next[26] = {};
    int index = -1;
    vector<int> palindromeIndexes;
};

class Solution {
    TrieNode root; // Suffix trie
    void add(string &s, int i) {
        auto node = &root;
        for (int j = s.size() - 1; j >= 0; --j) {
            if (isPalindrome(s, 0, j)) node->palindromeIndexes.push_back(i); // A[i]'s prefix forms a palindrome
            int c = s[j] - 'a';
            if (!node->next[c]) node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->index = i;
        node->palindromeIndexes.push_back(i); // A[i]'s prefix is empty string here, which is a palindrome.
    }
    
    bool isPalindrome(string &s, int i, int j) {
        while (i < j && s[i] == s[j]) ++i, --j;
        return i >= j;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& A) {
        int N = A.size();
        for (int i = 0; i < N; ++i) add(A[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < N; ++i) {
            auto s = A[i];
            auto node = &root;
            for (int j = 0; j < s.size() && node; ++j) {
                if (node->index != -1 && node->index != i && isPalindrome(s, j, s.size() - 1)) ans.push_back({ i, node->index }); 
                // A[i]'s prefix matches this word and A[i]'s suffix forms a palindrome
                node = node->next[s[j] - 'a'];
            }
            if (!node) continue;
            for (int j : node->palindromeIndexes) { 
                // A[i] is exhausted in the matching above. 
                // If a word whose prefix is palindrome after matching its suffix with A[i], 
                // then this is also a valid pair
                if (i != j) ans.push_back({ i, j });
            }
        }
        return ans;
    }
};
```











<br /> <br /> <br />**[]()**<br />
