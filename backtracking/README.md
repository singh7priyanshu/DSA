# Love Babbar Sheet 450 - Backtracking
## Problem 1:
**[Rat in a maze Problem](https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)**<br />
Consider a rat placed at `(0, 0)` in a square matrix of order `N * N`. It has to reach the destination at `(N - 1, N - 1)`. Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are `'U'(up)`, `'D'(down)`, `'L' (left)`, `'R' (right)`.<br />
Value `0` at a cell in the matrix represents that it is blocked and rat cannot move to it while value `1` at a cell in the matrix represents that rat can be travel through it.<br />
**Note:** In a path, no cell can be visited more than one time. If the source cell is `0`, the rat cannot move to any other cell.<br />

>Example 1:<br />
<pre>
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
</pre>

>Example 2:
<pre>
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is blocked.
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Complete the function `printPath()` which takes `N` and `2D array m[ ][ ]` as input parameters and returns the list of paths in lexicographically increasing order.<br /> 
`Note:` In case of no path, return an `empty list`. The driver will output `"-1"` automatically.<br />

<pre>
Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.
</pre>

* Constraints: `2 ≤ N ≤ 5`<br />
`0 ≤ m[i][j] ≤ 1`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> visited(5, vector<int> (5,0));
vector<string> result;

class Solution{
    public:
    void path(vector<vector<int>> &m, int x, int y, string dir, int n) {
        if (x == n - 1 and y == n - 1) {
            result.push_back(dir);
            return;
        }
    
        if (m[x][y] == 0 or visited[x][y] == 1) return;
    
        // DFS
        visited[x][y] = 1;
        if (x > 0) path(m, x - 1, y, dir + 'U', n);
        if (y > 0) path(m, x, y - 1, dir + 'L', n);
        if (x < n - 1) path(m, x + 1, y, dir + 'D', n);
        if (y < n - 1) path(m, x, y + 1, dir + 'R', n);
        visited[x][y] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                visited[i][j] = false;
            }
        }
        result.clear();
    
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0) return result;
    
        path(m, 0, 0, "", n);
    
        sort(result.begin(), result.end());
        return result;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>m(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>m[i][j];
            }
        }
        Solution obj;
        vector<string>result = obj.findPath(m,n);
        if(result.size()==0){
            cout<<-1;
        }
        else{
            for(int i =0;i<result.size();i++) cout<< result[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```









<br /><br /><br />
## Problem 2:
**[Printing all solutions in N-Queen Problem](https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/)**<br />
The `N Queen` is the problem of placing `N chess queens` on an `N×N` chessboard so that no two queens attack each other. For example, following is a solution for 4 Queen problem.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/ratinmaze_filled11-1-e1518086835222.png"><br />
the task is to print all solutions in `N-Queen` Problem. Each solution contains distinct board configurations of the `N-queens`’ placement, where the solutions are a permutation of `[1,2,3..n]` in increasing order, here the number in the `ith` place denotes that the `ith-column` queen is placed in the row with that number. For the example above solution is written as `[[2 4 1 3 ] [3 1 4 2 ]]`.<br /><br />
**Backtracking Algorithm**<br /> 
The idea is to place queens one by one in different columns, starting from the leftmost column. When we place a queen in a column, we check for clashes with already placed queens. In the current column, if we find a row for which there is no clash, we mark this row and column as part of the solution. If we do not find such a row due to clashes then we backtrack and return `false`.<br />
<pre>
1) Start in the leftmost column
2) If all queens are placed
    return true
3) Try all rows in the current column.  Do following
   for every tried row.
    a) If the queen can be placed safely in this row
       then mark this [row, column] as part of the 
       solution and recursively check if placing  
       queen here leads to a solution.
    b) If placing queen in [row, column] leads to a
       solution then return true.
    c) If placing queen doesn't lead to a solution 
       then unmark this [row, column] (Backtrack) 
       and go to step (a) to try other rows.
3) If all rows have been tried and nothing worked, 
   return false to trigger backtracking.
</pre>
<pre>
A modification is that we can find whether we have a previously placed queen in a column or in left diagonal or in right diagonal in O(1) time. We can observe that 
 1. For all cells in a particular left diagonal , their row + col  = constant.
 2. For all cells in a particular right diagonal, their row – col + n – 1 = constant.
</pre>
**Let say n = 5, then we have a total of 2n-1 left and right diagonals**<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210513134448/left-660x374.jpg"><br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210513134618/right-660x373.jpg"><br />
<pre>
Let say we placed a queen at (2,0) 
(2,0) have leftDiagonal value = 2. Now we can not place another queen at (1,1) and (0,2) 
because both of these have same leftDiagonal value as for (2,0). Similar thing can be 
noticed for right diagonal as well.
</pre>
**Implementation:**<br />
```cpp
/* C/C++ program to solve N Queen Problem using
backtracking */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > result;

/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(vector<vector<int> > board,
			int row, int col)
{
	int i, j;
	int N = board.size();

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(vector<vector<int> >& board, int col)
{
	/* base case: If all queens are placed
	then return true */
	int N = board.size();
	if (col == N) {
		vector<int> v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 1)
					v.push_back(j + 1);
			}
		}
		result.push_back(v);
		return true;
	}

	/* Consider this column and try placing
	this queen in all rows one by one */
	bool res = false;
	for (int i = 0; i < N; i++) {
		/* Check if queen can be placed on
		board[i][col] */
		if (isSafe(board, i, col)) {
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			// Make result true if any placement
			// is possible
			res = solveNQUtil(board, col + 1) || res;

			/* If placing queen in board[i][col]
			doesn't lead to a solution, then
			remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK
		}
	}

	/* If queen can not be place in any row in
		this column col then return false */
	return res;
}

/* This function solves the N Queen problem using
Backtracking. It mainly uses solveNQUtil() to
solve the problem. It returns false if queens
cannot be placed, otherwise return true and
prints placement of queens in the form of 1s.
Please note that there may be more than one
solutions, this function prints one of the
feasible solutions.*/

vector<vector<int> > nQueen(int n)
{
	result.clear();
	vector<vector<int> > board(n, vector<int>(n, 0));

	if (solveNQUtil(board, 0) == false) {
		return {};
	}

	sort(result.begin(), result.end());
	return result;
}

// Driver Code
int main()
{
	int n = 4;
	vector<vector<int> > v = nQueen(n);

	for (auto ar : v) {
		cout << "[";
		for (auto it : ar)
			cout << it << " ";
		cout << "]";
	}

	return 0;
}
```
Output<br />
<pre>
[2 4 1 3 ][3 1 4 2 ]
</pre>
**Efficient Backtracking Approach Using Bit-Masking**<br /> 
Algorithm:<br />
There is always only one queen in each row and each column, so idea of backtracking is to start placing queen from the leftmost column of each row and find a column where the queen could be placed without collision with previously placed queens. It is repeated from the first row till the last row. While placing a queen, it is tracked as if it is not making a collision (row-wise, column-wise and diagonally) with queens placed in previous rows. Once it is found that the queen can’t be placed at a particular column index in a row, the algorithm backtracks and change the position of the queen placed in the previous row then moves forward to place the queen in the next row.<br />
<pre>
 1. Start with three-bit vector which is used to track safe place for queen placement 
    row-wise, column-wise and diagonally in each iteration.
 2. Three-bit vector will contain information as bellow:
         * rowmask: set bit index (i) of this bit vector will indicate, the queen can’t be placed at ith column of next row.
         * ldmask: set bit index (i) of this bit vector will indicate, the queen can’t e placed at ith column of next row. 
           It represents the unsafe column index for next row falls under left diagonal of queens placed in previous rows.
         * rdmask: set bit index (i) of this bit vector will indicate, the queen can’t be placed at ith column of next row. 
           It represents the unsafe column index for next row falls right diagonal of queens placed in previous rows.
 3. There is a 2-D (NxN) matrix (board), which will have ‘ ‘ character at all indexes in 
    beginning and it gets filled by ‘Q’ row-by-row. Once all rows are filled by ‘Q’, the 
    current solution is pushed into the result list.
</pre>
Below is the implementation of the above approach:<br />
```cpp
// CPP program for above approach
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > result;
// Program to solve N Queens problem
void solveBoard(vector<vector<char> >& board, int row, int rowmask, int ldmask, int rdmask, int& ways)
{
	int n = board.size();

	// All_rows_filled is a bit mask having all N bits set
	int all_rows_filled = (1 << n) - 1;

	// If rowmask will have all bits set, means queen has
	// been placed successfully in all rows and board is
	// displayed
	if (rowmask == all_rows_filled) {

		vector<int> v;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board.size(); j++) {
				if (board[i][j] == 'Q')
					v.push_back(j + 1);
			}
		}
		result.push_back(v);
		return;
	}

	// We extract a bit mask(safe) by rowmask,
	// ldmask and rdmask. all set bits of 'safe'
	// indicates the safe column index for queen
	// placement of this iteration for row index(row).
	int safe = all_rows_filled & (~(rowmask | ldmask | rdmask));
	while (safe) {

		// Extracts the right-most set bit
		// (safe column index) where queen
		// can be placed for this row
		int p = safe & (-safe);
		int col = (int)log2(p);
		board[row][col] = 'Q';

		// This is very important:
		// we need to update rowmask, ldmask and rdmask
		// for next row as safe index for queen placement
		// will be decided by these three bit masks.

		// We have all three rowmask, ldmask and
		// rdmask as 0 in beginning. Suppose, we are placing
		// queen at 1st column index at 0th row. rowmask,
		// ldmask and rdmask will change for next row as
		// below:

		// rowmask's 1st bit will be set by OR operation
		// rowmask = 00000000000000000000000000000010

		// ldmask will change by setting 1st
		// bit by OR operation and left shifting
		// by 1 as it has to block the next column
		// of next row because that will fall on left
		// diagonal. ldmask =
		// 00000000000000000000000000000100

		// rdmask will change by setting 1st bit
		// by OR operation and right shifting by 1
		// as it has to block the previous column
		// of next row because that will fall on right
		// diagonal. rdmask =
		// 00000000000000000000000000000001

		// these bit masks will keep updated in each
		// iteration for next row
		solveBoard(board, row + 1, rowmask | p, (ldmask | p) << 1, (rdmask | p) >> 1, ways);

		// Reset right-most set bit to 0 so,
		// next iteration will continue by placing the queen
		// at another safe column index of this row
		safe = safe & (safe - 1);

		// Backtracking, replace 'Q' by ' '
		board[row][col] = ' ';
	}
	return;
}

// Driver Code
int main()
{
	// Board size
	int n = 4;
	int ways = 0;

	vector<vector<char> > board;
	for (int i = 0; i < n; i++) {
		vector<char> tmp;
		for (int j = 0; j < n; j++) {
			tmp.push_back(' ');
		}
		board.push_back(tmp);
	}

	int rowmask = 0, ldmask = 0, rdmask = 0;
	int row = 0;

	// Function Call
	result.clear();
	solveBoard(board, row, rowmask, ldmask, rdmask, ways);
	sort(result.begin(),result.end());
	for (auto ar : result) {
		cout << "[";
		for (auto it : ar)
			cout << it << " ";
		cout << "]";
	}
	return 0;
}
```
Output<br />
<pre>
[2 4 1 3 ][3 1 4 2 ]
</pre>













<br /><br /><br />
## Problem 3:
**[Word Break Problem using Backtracking](https://practice.geeksforgeeks.org/problems/word-break-part-23249/1)**<br />
Given a string `s` and a dictionary of words `dict` of length `n`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.<br />
Follow examples for better understanding.<br />

>Example 1:<br />
Input: s = "catsanddog", n = 5 <br />
dict = {"cats", "cat", "and", "sand", "dog"}<br />
Output: (cats and dog)(cat sand dog)<br />
Explanation: All the words in the given sentences are present in the dictionary.<br />

>Example 2:<br />
Input: s = "catsandog", n = 5<br />
dict = {"cats", "cat", "and", "sand", "dog"}<br />
Output: Empty<br />
Explanation: There is no possible breaking of the string s where all the words are present in dict.<br />

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `wordBreak()` which takes `n`, `dict` and `s` as input parameters and returns a list of possible sentences. If no sentence is possible it returns an `empty list`.<br />

<pre>
Expected Time Complexity: O(N^2*n) where N = |s|
Expected Auxiliary Space: O(N^2)
</pre>

* Constraints: `1 ≤ n ≤ 20`<br />
`1 ≤ dict[i] ≤ 15`<br />
`1 ≤ |s| ≤ 500` <br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    unordered_map<string, vector<string>> m;
    
    void combine(vector<string> &v, string w){
        for(int i = 0;i < v.size();i++){
            v[i] += " "+w;
        }
    }
    
    vector<string> cal(string s, unordered_set<string> &mp){
        if(m.find(s) != m.end()) 
            return m[s];
        vector<string> result;
        if(mp.find(s) != mp.end()) 
            result.push_back(s);
        for(int i = 1;i < s.size();i++){
            string rem = s.substr(i);
            if(mp.find(rem) != mp.end()){
                vector<string> v = cal(s.substr(0,i), mp);
                combine(v, rem);
                result.insert(result.end(), v.begin(), v.end());
            }
        }
        m[s] = result;
        return result;
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s) 
    {
        unordered_set<string> mp;
        for(int i = 0;i < n;i++)
            mp.insert(dict[i]);
        vector<string> ans = cal(s, mp);
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n;
        vector<string>dict;
        string s;
        cin>>n;
        for(int i = 0;i<n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        Solution ob;
        vector<string>ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)cout<<"Empty"<<endl;
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i<ans.size();i++)cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
```









<br /><br /><br />
## Problem 4:
**[301. Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/)**<br />
Given a string `s` that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.<br />
Return _all the possible results_. You may return the answer in **any order**.<br />

>Example 1:<br />
Input: s = "()())()"<br />
Output: ["(())()","()()()"]<br />

>Example 2:<br />
Input: s = "(a)())()"<br />
Output: ["(a())()","(a)()()"]<br />

>Example 3:<br />
Input: s = ")("<br />
Output: [""]<br />
 
* Constraints: `1 <= s.length <= 25`<br />
`s` consists of lowercase English letters and parentheses `'('` and `')'`.<br />
There will be at most `20` parentheses in `s`.<br />

```cpp
class Solution {
public:
    unordered_set<string> res, vis;
    
    int get_min(string &str){
        int n = str.size();
        stack<char> st;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == '(')st.push(str[i]);
            else if(str[i] == ')'){
                if(st.empty()) count++;
                else st.pop();
            }
        }
        count += st.size();
        return count;
    }
    void helper(string str, int min_removal){
        if(vis.find(str) != vis.end())return;
        vis.insert(str);
        if(min_removal == 0){
            res.insert(str);
            return;
        }
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(' || str[i] == ')'){
                string left = str.substr(0, i);
                string right = str.substr(i + 1);
                helper(left + right, min_removal - 1);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string str) {
        int n = str.size();
        int min_removal = get_min(str);
        helper(str, min_removal);
        vector<string> ans;
        for(auto x : res){
            if(get_min(x) == 0)ans.push_back(x);
        }
        return ans;
    }
};
```









<br /><br /><br />
## Problem 5:
**[Sudoku Solver](https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1)**<br />
Given an incomplete Sudoku configuration in terms of a `9 x 9`  `2-D square matrix (grid[][])`, the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.<br />
Sample Sudoku for you to get the logic for its solution:<br />
<img src = "https://contribute.geeksforgeeks.org/wp-content/uploads/sudoku.png"><br />

>Example 1:<br />
Input:<br />
grid[][] = <br />
[[3 0 6 5 0 8 4 0 0],<br />
[5 2 0 0 0 0 0 0 0],<br />
[0 8 7 0 0 0 0 3 1 ],<br />
[0 0 3 0 1 0 0 8 0],<br />
[9 0 0 8 6 3 0 0 5],<br />
[0 5 0 0 9 0 6 0 0],<br />
[1 3 0 0 0 0 2 5 0],<br />
[0 0 0 0 0 0 0 7 4],<br />
[0 0 5 2 0 6 3 0 0]]<br />
Output:<br />
3 1 6 5 7 8 4 9 2<br />
5 2 9 1 3 4 7 6 8<br />
4 8 7 6 2 9 5 3 1<br />
2 6 3 4 1 5 9 8 7<br />
9 7 4 8 6 3 1 2 5<br />
8 5 1 7 9 2 6 4 3<br />
1 3 8 9 4 7 2 5 6<br />
6 9 2 3 5 1 8 7 4<br />
7 4 5 2 8 6 3 1 9<br />

**Your Task:**<br />
You need to complete the two functions:<br />
`SolveSudoku():` Takes a grid as its argument and returns `true` if a solution is possible and `false` if it is not.<br />
`printGrid():` Takes a grid as its argument and prints the `81` numbers of the solved Sudoku in a single line with space separation.<br />
**NOTE:** Do not give a new line character after printing the grid. It has already been taken care of in the Driver Code.<br />

<pre>
Expected Time Complexity: O(9N*N).
Expected Auxiliary Space: O(N*N).
</pre>

* Constraints: `0 ≤ grid[i][j] ≤ 9`<br />

```cpp
#include<bits/stdc++.h>
        using namespace std;
        // UNASSIGNED is used for empty cells in sudoku grid
        #define UNASSIGNED 0

        // N is used for the size of Sudoku grid.
        // Size will be NxN
        #define N 9

        class Solution{
                public:
                //This function searches the grid to find an entry that is still unassigned.
                //If found, the reference parameters row, col will be set the location  
                //that is unassigned, and true is returned.  
                //If no unassigned entries remain, false is returned. 
                bool FindUnassignedLocation(int grid[N][N],int &row, int &col)  {  
                        for (row = 0; row < N; row++)  
                            for (col = 0; col < N; col++)  
                                if (grid[row][col] == UNASSIGNED)  
                                        return true;  
                        return false;  
                }  
    
                //Function to print grids of the Sudoku.
                void printGrid(int grid[N][N])  {  
                        for (int row = 0; row < N; row++)  
                                for (int col = 0; col < N; col++)  
                                        cout << grid[row][col] << " ";  
                } 
    
                //Function to return a boolean which indicates whether an assigned  
                //entry in the specified row matches the given number. 
                bool UsedInRow(int grid[N][N], int row, int num) {  
                        for (int col = 0; col < N; col++)  
                                if (grid[row][col] == num)  
                                        return true;  
                        return false;  
                }  
      
                //Function to return a boolean which indicates whether an assigned  
                //entry in the specified column matches the given number. 
                bool UsedInCol(int grid[N][N], int col, int num)  {  
                        for (int row = 0; row < N; row++)  
                                if (grid[row][col] == num)  
                                        return true;  
                        return false;  
                }  
      
                //Function to return a boolean which indicates whether an assigned
                //entry within the specified 3x3 box matches the given number.
                bool UsedInBox(int grid[N][N], int boxStartRow,int boxStartCol, int num)  {  
                        for (int row = 0; row < 3; row++)  
                                for (int col = 0; col < 3; col++)  
                                        if (grid[row + boxStartRow] 
                                                [col + boxStartCol] == num)  
                                        return true;  
                        return false;  
                }
      
    
                //Function to return a boolean which indicates whether it will be 
                //legal to assign num to the given row, column location. 
                bool isSafe(int grid[N][N], int row, int col, int num)  {  
                        //checking if 'num' is not already placed in  
                        //current row, current column and current 3x3 box.
                        return !UsedInRow(grid, row, num) &&  
                                !UsedInCol(grid, col, num) &&  
                                !UsedInBox(grid, row - row % 3 ,  
                                        col - col % 3, num) &&  
                                grid[row][col] == UNASSIGNED;  
                } 
    
                //Function to find a solved Sudoku. 
                bool SolveSudoku(int grid[N][N])  {  
                        int row, col;  
      
                        //if there is no unassigned location, we are done.
                        if (!FindUnassignedLocation(grid, row, col))  
                                return true;
      
                        //considering digits from 1 to 9  
                        for (int num = 1; num <= 9; num++)  {   
                                if (isSafe(grid, row, col, num))  {  
                                        //making tentative assignment  
                                        grid[row][col] = num;  
      
                                        //if success, return true  
                                        if (SolveSudoku(grid))  
                                                return true;  
      
                                        //failure, unmake & try again  
                                        grid[row][col] = UNASSIGNED;  
                                }  
                        }  
                        // this triggers backtracking 
                        return false;  
                }  
        };

        int main (){
                int t;
                cin>>t;
                while(t--){
                        int grid[N][N];
                        for(int i=0;i<9;i++)
                                for(int j=0;j<9;j++)
                                        cin>>grid[i][j];
    
                        Solution ob;
                        if(ob.SolveSudoku(grid)==true)
                                ob.printGrid(grid);
                        else 
                                cout<<"No solution exists";
                        cout<<endl;
                }
                return 0;
        }
```










<br /><br /><br />
## Problem 6:
**[M Coloring Problem](https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1)**<br />
Given an `undirected graph` and an integer `M`. The task is to determine if the graph can be colored with at most `M` colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print `1` if it is possible to colour vertices and `0` otherwise.<br />

>Example 1:<br />
Input:<br />
N = 4<br />
M = 3<br />
E = 5<br />
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}<br />
Output: 1<br />
Explanation: It is possible to colour the given graph using 3 colours.<br />

>Example 2:<br />
Input:<br />
N = 3<br />
M = 2<br />
E = 3<br />
Edges[] = {(0,1),(1,2),(0,2)}<br />
Output: 0<br />

**Your Task:**<br />
Your task is to complete the function `graphColoring()` which takes the `2d-array graph[]`, the number of colours and the number of nodes as inputs and returns `true` if answer exists otherwise `false`. `1` is printed if the returned value is `true`, `0` otherwise. The printing is done by the driver's code.<br />
**Note:** In Example there are Edges not the graph. Graph will be like, if there is an edge between vertex `X` and vertex `Y` `graph[]` will contain `1` at `graph[X-1][Y-1]`, else `0`. In `2d-array graph[ ]`, nodes are `0-based` indexed, i.e. from `0` to `N-1`.Function will be contain `2-D graph` not the edges.<br />

<pre>
Expected Time Complexity: O(M^N).
Expected Auxiliary Space: O(N).
</pre>

* Constraints: `1 ≤ N ≤ 20`<br />
`1 ≤ E ≤ (N*(N-1))/2`<br />
`1 ≤ M ≤ N`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int v, bool graph[101][101], int color[101], int c, int V) {
    //checking if the connected nodes to v have same colour as c.
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i]) return false;
    //returning true if no connected node has same colour.
    return true;
}

bool graphColoringUtil(bool graph[101][101], int m, int color[101], int v, int V) {
    //if all vertices have been assigned colour then we return true.
    if (v == V) return true;
    for (int c = 1; c <= m; c++){
        //checking if this colour can be given to a particular node.
        if (isSafe(v, graph, color, c, V)){
            //assigning colour to the node.
            color[v] = c;
            //calling function recursively and checking if other nodes 
            //can be assigned other colours.
            if (graphColoringUtil(graph, m, color, v + 1, V) == true)  return true; 
                //returning true if the current allocation was successful.
            //if not true, we backtrack and remove the colour for that node.
            color[v] = 0;
        }
    }
    //if no colour can be assigned, we return false.
    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V){
    int *color = new int[V];
    for (int i = 0; i < V; i++) color[i] = 0;
    //checking if colours can be assigned.
    if (graphColoringUtil(graph, m, color, 0, V) == false)return false;
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n, m, e; cin>>n>>m>>e;
        bool graph[101][101];
        for(int i = 0;i<e;i++)memset(graph[i], 0, sizeof(graph[i]));
        for(int i = 0;i<e;i++){
            int a, b; cin>>a>>b;
            graph[a-1][b-1] = 1;
            graph[b-1][a-1] = 1;
        }
        cout<<graphColoring(graph, m, n)<<endl;
    }
    return 0;
}
```







<br /><br /><br />
## Problem 7:
**[Print all palindromic partitions of a string](https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/)**<br />
Given a `string`, find all possible palindromic partitions of given string.<br />
>Example:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/AllPalindromPArtition.png"><br />
Note that this problem is different from Palindrome Partitioning Problem, there the task was to find the partitioning with minimum cuts in input string. Here we need to print all possible partitions.<br />
The idea is to go through every substring starting from first character, check if it is palindrome. If `yes`, then add the substring to solution and recur for remaining part. Below is complete algorithm.<br />
Below is the implementation of above idea.<br />
```cpp
// C++ program to print all palindromic partitions of a given string
#include<bits/stdc++.h>
using namespace std;

// A utility function to check if str is palindrome
bool isPalindrome(string str, int low, int high)
{
	while (low < high)
	{
		if (str[low] != str[high])
			return false;
		low++;
		high--;
	}
	return true;
}

// Recursive function to find all palindromic partitions of str[start..n-1]
// allPart --> A vector of vector of strings. Every vector inside it stores
//			 a partition
// currPart --> A vector of strings to store current partition
void allPalPartUtil(vector<vector<string> >&allPart, vector<string> &currPart, int start, int n, string str)
{
	// If 'start' has reached len
	if (start >= n)
	{
		allPart.push_back(currPart);
		return;
	}

	// Pick all possible ending points for substrings
	for (int i=start; i<n; i++)
	{
		// If substring str[start..i] is palindrome
		if (isPalindrome(str, start, i))
		{
			// Add the substring to result
			currPart.push_back(str.substr(start, i-start+1));

			// Recur for remaining substring
			allPalPartUtil(allPart, currPart, i+1, n, str);
			
			// Remove substring str[start..i] from current
			// partition
			currPart.pop_back();
		}
	}
}

// Function to print all possible palindromic partitions of
// str. It mainly creates vectors and calls allPalPartUtil()
void allPalPartitions(string str)
{
	int n = str.length();

	// To Store all palindromic partitions
	vector<vector<string> > allPart;

	// To store current palindromic partition
	vector<string> currPart;

	// Call recursive function to generate all partitions
	// and store in allPart
	allPalPartUtil(allPart, currPart, 0, n, str);

	// Print all partitions generated by above call
	for (int i=0; i< allPart.size(); i++ )
	{
		for (int j=0; j<allPart[i].size(); j++)
			cout << allPart[i][j] << " ";
		cout << "\n";
	}
}

// Driver program
int main()
{
	string str = "nitin";
	allPalPartitions(str);
	return 0;
}
```
Output<br />
<pre>
n i t i n 
n iti n 
nitin
</pre>
<pre>
Time complexity: O(n*2^n)
Auxiliary Space: O(n^2)
</pre>
<br />**Approach 2: Expand around every palindrome**<br />
The idea is to split the string into all palindromes of length `1` that is convert the string to a list of its characters (but as string data type) and then expand the smaller palindromes to bigger palindromes by checking if its left and right (reversed) are equal or not if they are equal then merge them and solve for new list recursively. Also if two adjacent strings of this list are equal (when one of them is reversed), merging them would also give a palindrome so merge them and solve recursively.<br />
```python
class GFG:
	def solve(self, arr):
		self.res.add(tuple(arr)) # add current partitioning to result
		if len(arr)<=1: # Base case when there is nothing to merge
			return
		for i in range(1,len(arr)):
			if arr[i-1]==arr[i][::-1]: # When two adjacent such that one is reverse of another
				brr = arr[:i-1] + [arr[i-1]+arr[i]] + arr[i+1:]
				self.solve(brr)
			if i+1<len(arr) and arr[i-1]==arr[i+1][::-1]: # All are individually palindrome,
			# when one left and one right of i are reverse of each other then we can merge
			# the three of them to form a new partitioning way
				brr = arr[:i-1] + [arr[i-1]+arr[i]+arr[i+1]] + arr[i+2:]
				self.solve(brr)
	def getGray(self, S):
		self.res = set() # result is a set of tuples to avoid same partition multiple times
		self.solve(list(S)) # Call recursive function to solve for S
		return sorted(list(self.res))
# Driver Code
if __name__ == '__main__':
	ob = GFG()
	allPart = ob.getGray("geeks")
	for i in range(len(allPart)):
		for j in range(len(allPart[i])):
			print(allPart[i][j], end = " ")
		print()
```
Output<br />
<pre>
g e e k s 
g ee k s
</pre>
<pre>
Time complexity: O(n*2^n)
Auxiliary Space: O(n^2)
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
