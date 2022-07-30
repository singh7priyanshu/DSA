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
**[Subset Sum Problem / Partition Equal Subset Sum](https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1)**<br />
Given an array `arr[]` of size `N`, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.<br />

>Example 1:<br />
Input: N = 4<br />
arr = {1, 5, 11, 5}<br />
Output: YES<br />
Explanation: The two parts are {1, 5, 5} and {11}.<br />

>Example 2:<br />
Input: N = 3<br />
arr = {1, 3, 5}<br />
Output: NO<br />
Explanation: This array can never be partitioned into two such parts.<br />

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `equalPartition()` which takes the value `N` and the `array` as input parameters and returns `1` if the partition is possible. Otherwise, returns `0`.<br />

<pre>
Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)
</pre>

* Constraints: `1 ≤ N ≤ 100`<br />
`1 ≤ arr[i] ≤ 1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int N, int arr[]){
      int sum =0;
        for(int i=0;i<N;i++)
        sum = sum+arr[i];
       
        return (sum%2==0) && solve(arr, sum/2, N);
        
    }
private:
    int sum = 0;
    
    bool solve(int arr[], int sum, int n){
        bool dp[n+1][sum + 1];
        
        for(int i=0;i<=n;i++) dp[i][0] = true; //subset with 0 sum
        
        for(int j=1;j<=sum;j++) dp[0][j] = false; //non-zero sum with 0 elements
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1] > j) dp[i][j] = dp[i-1][j]; //don't include ith element if it's greater then the rem sum
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
               
            }
        }
        
        return dp[n][sum];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        if(ob.equalPartition(n, arr))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
```







<br /><br /><br />
## Problem 9:
**[The Knight’s tour problem](https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/)**<br />
Backtracking is an algorithmic paradigm that tries different solutions until finds a solution that “works”. Problems that are typically solved using the backtracking technique have the following property in common. These problems can only be solved by trying every possible configuration and each configuration is tried only once. A Naive solution for these problems is to try all configurations and output a configuration that follows given problem constraints. Backtracking works incrementally and is an optimization over the Naive solution where all possible configurations are generated and tried.<br />
**Problem Statement:**<br />
Given a `N*N` board with the Knight placed on the first block of an empty board. Moving according to the rules of chess knight must visit each square exactly once. Print the order of each cell in which they are visited.<br />
**Example:**<br />
<pre>
Input : 
N = 8
Output:
0  59  38  33  30  17   8  63
37  34  31  60   9  62  29  16
58   1  36  39  32  27  18   7
35  48  41  26  61  10  15  28
42  57   2  49  40  23   6  19
47  50  45  54  25  20  11  14
56  43  52   3  22  13  24   5
51  46  55  44  53   4  21  12
</pre>
**The path followed by Knight to cover all the cells**<br />
Following is a chessboard with `8 x 8` cells. Numbers in cells indicate the move number of Knight.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/knight-tour-problem1.png"><br />
Let us first discuss the Naive algorithm for this problem and then the Backtracking algorithm.<br /><br />
**Naive Algorithm for Knight’s tour**<br />
The Naive Algorithm is to generate all tours one by one and check if the generated tour satisfies the constraints.<br />
<pre>
while there are untried tours
{ 
   generate the next tour 
   if this tour covers all squares 
   { 
      print this path;
   }
}
</pre>
**Backtracking** works in an incremental way to attack problems. Typically, we start from an empty solution vector and one by one add items (Meaning of item varies from problem to problem. In the context of Knight’s tour problem, an item is a Knight’s move). When we add an item, we check if adding the current item violates the problem constraint, if it does then we remove the item and try other alternatives. If none of the alternatives works out then we go to the previous stage and remove the item added in the previous stage. If we reach the initial stage back then we say that no solution exists. If adding an item doesn’t violate constraints then we recursively add items one by one. If the solution vector becomes complete then we print the solution.<br />
**Backtracking Algorithm for Knight’s tour**<br />
Following is the Backtracking algorithm for Knight’s tour problem.<br />
<pre>
If all squares are visited 
    print the solution
Else
   a) Add one of the next moves to solution vector and recursively 
   check if this move leads to a solution. (A Knight can make maximum 
   eight moves. We choose one of the 8 moves in this step).
   b) If the move chosen in the above step doesn't lead to a solution
   then remove this move from the solution vector and try other 
   alternative moves.
   c) If none of the alternatives work then return false (Returning false 
   will remove the previously added item in recursion and if false is 
   returned by the initial call of recursion then "no solution exists" )
</pre>
Following are implementations for Knight’s tour problem. It prints one of the possible solutions in `2D matrix` form. Basically, the output is a `2D 8*8` matrix with numbers from `0 to 63` and these numbers show steps made by Knight.<br />
```cpp
// C++ program for Knight Tour problem
#include <bits/stdc++.h>
using namespace std;

#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]);

/* A utility function to check if i,j are
valid indexes for N*N chessboard */
int isSafe(int x, int y, int sol[N][N])
{
	return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			cout << " " << setw(2) << sol[x][y] << " ";
		cout << endl;
	}
}

/* This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */
int solveKT()
{
	int sol[N][N];

	/* Initialization of solution matrix */
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y] = -1;

	/* xMove[] and yMove[] define next move of Knight.
	xMove[] is for next value of x coordinate
	yMove[] is for next value of y coordinate */
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	// Since the Knight is initially at the first block
	sol[0][0] = 0;

	/* Start from 0,0 and explore all tours using
	solveKTUtil() */
	if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
		cout << "Solution does not exist";
		return 0;
	}
	else
		printSolution(sol);

	return 1;
}

/* A recursive utility function to solve Knight Tour
problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[8], int yMove[8])
{
	int k, next_x, next_y;
	if (movei == N * N)
		return 1;

	/* Try all next moves from
	the current coordinate x, y */
	for (k = 0; k < 8; k++) {
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol)) {
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove) == 1)
				return 1;
			else
				
			// backtracking
				sol[next_x][next_y] = -1;
		}
	}
	return 0;
}

// Driver Code
int main()
{
	// Function Call
	solveKT();
	return 0;
}
```
Output<br />
<pre>
  0  59  38  33  30  17   8  63 
 37  34  31  60   9  62  29  16 
 58   1  36  39  32  27  18   7 
 35  48  41  26  61  10  15  28 
 42  57   2  49  40  23   6  19 
 47  50  45  54  25  20  11  14 
 56  43  52   3  22  13  24   5 
 51  46  55  44  53   4  21  12 
</pre>
<pre>
Time Complexity : There are N2 Cells and for each, we have a maximum of 8 possible moves to choose from, 
                  so the worst running time is O(8^N^2).
Auxiliary Space: O(N^2)
</pre>
**Important Note:**<br />
No order of the `xMove`, `yMove` is wrong, but they will affect the running time of the algorithm drastically. For example, think of the case where the `8th` choice of the move is the correct one, and before that our code ran `7` different wrong paths. It’s always a good idea a have a `heuristic` than to try backtracking randomly. Like, in this case, we know the next step would probably be in the south or east direction, then checking the paths which lead their first is a better strategy.<br />







<br /><br /><br />
## Problem 10:
**[Tug of War](https://www.geeksforgeeks.org/tug-of-war/)**<br />
Given a set of `n` integers, divide the set in two subsets of `n/2` sizes each such that the difference of the sum of two subsets is as minimum as possible. If `n` is even, then sizes of two subsets must be strictly `n/2` and if `n` is `odd`, then size of one subset must be `(n-1)/2` and size of other subset must be `(n+1)/2`.<br />
For example, let given set be `{3, 4, 5, -3, 100, 1, 89, 54, 23, 20}`, the size of set is `10`. Output for this set should be `{4, 100, 1, 23, 20}` and `{3, 5, -3, 89, 54}`. Both output subsets are of size `5` and sum of elements in both subsets is same `(148 and 148)`.<br />
Let us consider another example where `n` is odd. Let given set be `{23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}`. The output subsets should be `{45, -34, 12, 98, -1}` and `{23, 0, -99, 4, 189, 4}`. The sums of elements in two subsets are `120` and `121` respectively.<br />
The following solution tries every possible subset of half size. If one subset of half size is formed, the remaining elements form the other subset. We initialize current set as empty and one by one build it. There are two possibilities for every element, either it is part of current set, or it is part of the remaining elements (other subset). We consider both possibilities for every element. When the size of current set becomes `n/2`, we check whether this solutions is better than the best solution available so far. If it is, then we update the best solution.<br />
Following is the implementation for Tug of War problem. It prints the required arrays.<br />
```cpp
#include <bits/stdc++.h>
using namespace std;

// function that tries every possible solution by calling itself recursively
void TOWUtil(int* arr, int n, bool* curr_elements, int no_of_selected_elements, bool* soln, int* min_diff, int sum, int curr_sum, int curr_position)
{
	// checks whether the it is going out of bound
	if (curr_position == n)
		return;

	// checks that the numbers of elements left are not less than the
	// number of elements required to form the solution
	if ((n/2 - no_of_selected_elements) > (n - curr_position))
		return;

	// consider the cases when current element is not included in the solution
	TOWUtil(arr, n, curr_elements, no_of_selected_elements, soln, min_diff, sum, curr_sum, curr_position+1);

	// add the current element to the solution
	no_of_selected_elements++;
	curr_sum = curr_sum + arr[curr_position];
	curr_elements[curr_position] = true;

	// checks if a solution is formed
	if (no_of_selected_elements == n/2)
	{
		// checks if the solution formed is better than the best solution so far
		if (abs(sum/2 - curr_sum) < *min_diff)
		{
			*min_diff = abs(sum/2 - curr_sum);
			for (int i = 0; i<n; i++)
				soln[i] = curr_elements[i];
		}
	}
	else
	{
		// consider the cases where current element is included in the solution
		TOWUtil(arr, n, curr_elements, no_of_selected_elements, soln, min_diff, sum, curr_sum, curr_position+1);
	}

	// removes current element before returning to the caller of this function
	curr_elements[curr_position] = false;
}

// main function that generate an arr
void tugOfWar(int *arr, int n)
{
	// the boolean array that contains the inclusion and exclusion of an element
	// in current set. The number excluded automatically form the other set
	bool* curr_elements = new bool[n];

	// The inclusion/exclusion array for final solution
	bool* soln = new bool[n];

	int min_diff = INT_MAX;

	int sum = 0;
	for (int i=0; i<n; i++)
	{
		sum += arr[i];
		curr_elements[i] = soln[i] = false;
	}

	// Find the solution using recursive function TOWUtil()
	TOWUtil(arr, n, curr_elements, 0, soln, &min_diff, sum, 0, 0);

	// Print the solution
	cout << "The first subset is: ";
	for (int i=0; i<n; i++)
	{
		if (soln[i] == true)
			cout << arr[i] << " ";
	}
	cout << "\nThe second subset is: ";
	for (int i=0; i<n; i++)
	{
		if (soln[i] == false)
			cout << arr[i] << " ";
	}
}

// Driver program to test above functions
int main()
{
	int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	tugOfWar(arr, n);
	return 0;
}
```
Output:<br /> 
<pre>
The first subset is: 45 -34 12 98 -1
The second subset is: 23 0 -99 4 189 4
</pre>
<pre>
Time Complexity: O(2^n)
</pre>











<br /><br /><br />
## Problem 11:
**[Find shortest safe route in a path with landmines](https://www.geeksforgeeks.org/find-shortest-safe-route-in-a-path-with-landmines/)**<br />
Given a path in the form of a rectangular matrix having few landmines arbitrarily placed (marked as `0`), calculate length of the shortest safe route possible from any cell in the first column to any cell in the last column of the matrix. We have to avoid landmines and their four adjacent cells (`left`, `right`, `above` and `below`) as they are also unsafe. We are allowed to move to only adjacent cells which are not landmines. i.e. the route cannot contains any diagonal moves.<br />
**Examples:**<br />
<pre>
Input: 
A 12 x 10 matrix with landmines marked as 0

[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  0  1  1  1  1  1  1  1  1 ]
[ 1  1  1  0  1  1  1  1  1  1 ]
[ 1  1  1  1  0  1  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  1  1  1  1  0  1  1  1  1 ]
[ 1  0  1  1  1  1  1  1  0  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 0  1  1  1  1  0  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  1  1  0  1  1  1  1  1  1 ]

Output:  
Length of shortest safe route is 13 (Highlighted in Bold)
</pre>
The idea is to use Backtracking. We first mark all adjacent cells of the landmines as unsafe. Then for each safe cell of first column of the matrix, we move forward in all allowed directions and recursively checks if they leads to the destination or not. If destination is found, we update the value of shortest path else if none of the above solutions work we return `false` from our function.<br />
Below is the implementation of above idea:<br />
```cpp
// C++ program to find shortest safe Route in
// the matrix with landmines
#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

// A function to check if a given cell (x, y)
// can be visited or not
bool isSafe(int mat[R][C], int visited[R][C], int x, int y)
{
	if (mat[x][y] == 0 || visited[x][y])
		return false;

	return true;
}

// A function to check if a given cell (x, y) is
// a valid cell or not
bool isValid(int x, int y)
{
	if (x < R && y < C && x >= 0 && y >= 0)
		return true;

	return false;
}

// A function to mark all adjacent cells of
// landmines as unsafe. Landmines are shown with
// number 0
void markUnsafeCells(int mat[R][C])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			// if a landmines is found
			if (mat[i][j] == 0)
			{
			// mark all adjacent cells
			for (int k = 0; k < 4; k++)
				if (isValid(i + rowNum[k], j + colNum[k]))
					mat[i + rowNum[k]][j + colNum[k]] = -1;
			}
		}
	}

	// mark all found adjacent cells as unsafe
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (mat[i][j] == -1)
				mat[i][j] = 0;
		}
	}

	// Uncomment below lines to print the path
	/*for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << std::setw(3) << mat[i][j];
		}
		cout << endl;
	}*/
}

// Function to find shortest safe Route in the
// matrix with landmines
// mat[][] - binary input matrix with safe cells marked as 1
// visited[][] - store info about cells already visited in
// current route
// (i, j) are coordinates of the current cell
// min_dist --> stores minimum cost of shortest path so far
// dist --> stores current path cost
void findShortestPathUtil(int mat[R][C], int visited[R][C], int i, int j, int &min_dist, int dist)
{
	// if destination is reached
	if (j == C-1)
	{
		// update shortest path found so far
		min_dist = min(dist, min_dist);
		return;
	}

	// if current path cost exceeds minimum so far
	if (dist > min_dist)
		return;

	// include (i, j) in current path
	visited[i][j] = 1;

	// Recurse for all safe adjacent neighbours
	for (int k = 0; k < 4; k++)
	{
		if (isValid(i + rowNum[k], j + colNum[k]) && isSafe(mat, visited, i + rowNum[k], j + colNum[k]))
		{
			findShortestPathUtil(mat, visited, i + rowNum[k], j + colNum[k], min_dist, dist + 1);
		}
	}

	// Backtrack
	visited[i][j] = 0;
}

// A wrapper function over findshortestPathUtil()
void findShortestPath(int mat[R][C])
{
	// stores minimum cost of shortest path so far
	int min_dist = INT_MAX;

	// create a boolean matrix to store info about
	// cells already visited in current route
	int visited[R][C];

	// mark adjacent cells of landmines as unsafe
	markUnsafeCells(mat);

	// start from first column and take minimum
	for (int i = 0; i < R; i++)
	{
		// if path is safe from current cell
		if (mat[i][0] == 1)
		{
			// initialize visited to false
			memset(visited, 0, sizeof visited);

			// find shortest route from (i, 0) to any
			// cell of last column (x, C - 1) where
			// 0 <= x < R
			findShortestPathUtil(mat, visited, i, 0, min_dist, 0);

			// if min distance is already found
			if(min_dist == C - 1)
				break;
		}
	}

	// if destination can be reached
	if (min_dist != INT_MAX)
		cout << "Length of shortest safe route is " << min_dist;

	else // if the destination is not reachable
		cout << "Destination not reachable from " << "given source";
}

// Driver code
int main()
{
	// input matrix with landmines shown with number 0
	int mat[R][C] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
	};

	// find shortest path
	findShortestPath(mat);

	return 0;
}
```
Output<br />
<pre>
Length of shortest safe route is 13
</pre>
**Another method:**<br />
It can be solved in polynomial time with the help of `Breadth First Search`. Enqueue the cells with `1` value in the queue with the distance as `0`. As the `BFS` proceeds, shortest path to each cell from the first column is computed. Finally for the reachable cells in the last column, output the minimum distance.<br />
The implementation in C++ is as follows:<br />
```cpp
// C++ program to find shortest safe Route in
// the matrix with landmines
#include <bits/stdc++.h>
using namespace std;

#define R 12
#define C 10

struct Key{
	int x,y;
	Key(int i,int j){ x=i;y=j;};
};

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

// A function to check if a given cell (x, y) is
// a valid cell or not
bool isValid(int x, int y)
{
	if (x < R && y < C && x >= 0 && y >= 0)
		return true;

	return false;
}

// A function to mark all adjacent cells of
// landmines as unsafe. Landmines are shown with
// number 0
void findShortestPath(int mat[R][C]){
	int i,j;

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			// if a landmines is found
			if (mat[i][j] == 0)
			{
			// mark all adjacent cells
			for (int k = 0; k < 4; k++)
				if (isValid(i + rowNum[k], j + colNum[k]))
					mat[i + rowNum[k]][j + colNum[k]] = -1;
			}
		}
	}
// mark all found adjacent cells as unsafe
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (mat[i][j] == -1)
				mat[i][j] = 0;
		}
	}

	int dist[R][C];

	for(i=0;i<R;i++){
		for(j=0;j<C;j++)
			dist[i][j] = -1;
	}
	queue<Key> q;

	for(i=0;i<R;i++){
		if(mat[i][0] == 1){
			q.push(Key(i,0));
			dist[i][0] = 0;
		}
	}

	while(!q.empty()){
		Key k = q.front();
		q.pop();

		int d = dist[k.x][k.y];

		int x = k.x;
		int y = k.y;

		for (int k = 0; k < 4; k++) {
			int xp = x + rowNum[k];
			int yp = y + colNum[k];
			if(isValid(xp,yp) && dist[xp][yp] == -1 && mat[xp][yp] == 1){
				dist[xp][yp] = d+1;
				q.push(Key(xp,yp));
			}
		}
	}
	// stores minimum cost of shortest path so far
	int ans = INT_MAX;
	// start from first column and take minimum
	for(i=0;i<R;i++){
		if(mat[i][C-1] == 1 && dist[i][C-1] != -1){
			ans = min(ans,dist[i][C-1]);
		}
	}
	
	// if destination can be reached
	if(ans == INT_MAX)
		cout << "NOT POSSIBLE\n";
		
	else// if the destination is not reachable
		cout << "Length of shortest safe route is " << ans << endl;
}

// Driver code
int main(){
	
	// input matrix with landmines shown with number 0
	int mat[R][C] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
	};
	
	// find shortest path
	findShortestPath(mat);
}
```
Output<br />
<pre>
Length of shortest safe route is 13
</pre>





<br /><br /><br />
## Problem 12:
**[Combinational Sum](https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1)**<br />
Given an array of integers and a sum `B`, find all unique combinations in the array where the sum is equal to `B`. The same number may be chosen from the array any number of times to make `B`.<br />
**Note:**<br />
<pre>
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.
</pre>

>Example 1:<br />
Input:<br />
N = 4<br />
arr[] = {7,2,6,5}<br />
B = 16<br />
Output:<br />
(2 2 2 2 2 2 2 2)<br />
(2 2 2 2 2 6)<br />
(2 2 2 5 5)<br />
(2 2 5 7)<br />
(2 2 6 6)<br />
(2 7 7)<br />
(5 5 6)<br />

>Example 2:<br />
Input:<br />
N = 11<br />
arr[] = {6,5,7,1,8,2,9,9,7,7,9}<br />
B = 6<br />
Output:<br />
(1 1 1 1 1 1)<br />
(1 1 1 1 2)<br />
(1 1 2 2)<br />
(1 5)<br />
(2 2 2)<br />
(6)<br />

**Your Task:**<br />
Your task is to complete the function `combinationSum()` which takes the array `A` and a sum `B` as inputs and returns a list of list denoting the required combinations in the order specified in the problem description. The printing is done by the driver's code. If no set can be formed with the given set, then  "Empty" (without quotes) is printed.<br />

<pre>
Expected Time Complexity: O(X^2 * 2^N), where X is average of summation B/arri for every number in the array.
Expected Auxiliary Space: O(X * 2^N)
</pre>

* Constraints: `1 <= N <= 30`<br />
`1 <= A[i] <= 20`<br />
`1 <= B <= 100`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution  {
  public:
    void combinationSumUtil(vector<int> &A, int sum, 
        vector<vector<int>>&result, vector<int>current, int pos){
        if(sum==0){ 
            result.push_back(current);
            return;
        }
        if(sum<0 || pos>=A.size()) return; 
        current.push_back(A[pos]); 
        combinationSumUtil(A, sum-A[pos], result,  current, pos );
        current.pop_back(); 
        combinationSumUtil(A, sum, result,  current, pos+1 ); 
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B){
        sort(A.begin(),A.end());
        vector<vector<int> > result;
        vector<int> current, C;
        int i,j;
        for(i=0;i<A.size();i++){
            j=i+1;
            while(j<A.size()&&A[i]==A[j])j++;
            C.push_back(A[i]);
            i=j-1;
        }
        combinationSumUtil(C, B, result, current,0);
        return result;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>A;
        for(int i = 0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>>result = ob.combinationSum(A, sum);
        if(result.size() == 0)cout<<"Empty";
        for(int i = 0;i<result.size();i++){
            cout<<'(';
            for(int j = 0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)cout<<" ";
            }
            cout<<")";
        }
        cout<<endl;
    }
}
```






<br /><br /><br />
## Problem 13:
**[Find Maximum number possible by doing at-most K swaps](https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1)**<br />
Given a number `K` and string `str` of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of `str` at most `K` times.<br />

>Example 1:<br />
Input:<br />
K = 4<br />
str = "1234567"<br />
Output:<br />
7654321<br />
Explanation:<br />
Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5<br />

>Example 2:<br />
Input:<br />
K = 3<br />
str = "3435335"<br />
Output:<br />
5543333<br />
Explanation:<br />
Three swaps can make the input 3435335 to 5543333, swapping 3 with 5, 4 with 5 and finally 3 with 4 <br />

**Your task:**<br />
You don't have to read input or print anything. Your task is to complete the function `findMaximumNum()` which takes the `string` and an `integer` as input and returns a `string` containing the largest number formed by perfoming the swap operation at most `k` times.<br />

<pre>
Expected Time Complexity: O(n!/(n-k)!) , where n = length of input string
Expected Auxiliary Space: O(n)
</pre>

* Constraints: `1 ≤ |str| ≤ 30`<br />
`1 ≤ K ≤ 10`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void match(string& str, string& res){
        for(int i=0; i<str.size(); i++){
            if( res[i] > str[i] )return;
            if( res[i] < str[i] ){
                res = str;
                return;
            }
        }
    }
    public:
    void setDigit(string& str, int index, string& res, int k){
        if(k==0 || index==str.size()-1){
            match(str,res);
            return;
        }
        int maxDigit = 0;
        for(int i=index; i<str.size(); i++)
            maxDigit = max( maxDigit, str[i]-'0' );
        if( str[index]-'0' == maxDigit ){
            setDigit(str, index+1, res, k);
            return;
        }
        for(int i=index+1; i<str.size(); i++){
            if( str[i]-'0' == maxDigit ){
                swap( str[index] , str[i] );
                setDigit(str, index+1, res, k-1);
                swap( str[index] , str[i] );
            }
        }
    }

    public:
    string findMaximumNum(string str, int k){
        string res = str;
        setDigit(str, 0, res, k);
        return res;
    }

};

int main(){
    int t, k;
    string str;
    cin>>t;
    while(t--){
        cin>>k>>str;
        Solution ob;
        cout<<ob.findMaximumNum(str, k)<<endl;
    }
    return 0;
}
```






<br /><br /><br />
## Problem 14:
**[Print all permutations of a string](https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1)**<br />
Given a string `S`. The task is to print all permutations of a given string in lexicographically sorted order.<br />

>Example 1:<br />
Input: ABC<br />
Output:<br />
ABC ACB BAC BCA CAB CBA<br />
Explanation:<br />
Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .<br />

>Example 2:<br />
Input: ABSG<br />
Output:<br />
ABGS ABSG AGBS AGSB ASBG ASGB BAGS <br />
BASG BGAS BGSA BSAG BSGA GABS GASB <br />
GBAS GBSA GSAB GSBA SABG SAGB SBAG<br /> 
SBGA SGAB SGBA<br />
Explanation:<br />
Given string ABSG has 24 permutations.<br />
 

**Your Task:**<br />  
You don't need to read input or print anything. Your task is to complete the function `find_permutaion()` which takes the string `S` as input parameter and returns a `vector of string` in lexicographical order.<br />

 
<pre>
Expected Time Complexity: O(n! * n)
Expected Space Complexity: O(n)
</pre>

* Constraints: `1 <= length of string <= 5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		vector<string>find_permutation(string S){
		    vector<string>res;
		    sort(S.begin(), S.end());
		    do{
		        res.push_back(S);
		    }while(next_permutation(S.begin(), S.end()));
		    return res;
		}
};

int main(){
    int t; cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        vector<string>ans = ob.find_permutation(S);
        for(auto i: ans)cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
```







<br /><br /><br />
## Problem 15:
**[Find if there is a path of more than k length from a source](https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/)**<br />
Given a graph, a source vertex in the graph and a number `k`, find if there is a simple path (without any cycle) starting from given source and ending at any other vertex such that the distance from source to that vertex is atleast `‘k’` length.<br />
**Example**<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20220710161400/UndirecteGraph-300x144.png"><br />
<pre>
Input  : Source s = 0, k = 58
Output : True
There exists a simple path 0 -> 7 -> 1
-> 2 -> 8 -> 6 -> 5 -> 3 -> 4
Which has a total distance of 60 km which
is more than 58.

Input  : Source s = 0, k = 62
Output : False

In the above graph, the longest simple
path has distance 61 (0 -> 7 -> 1-> 2
 -> 3 -> 4 -> 5-> 6 -> 8, so output 
should be false for any input greater 
than 61.
</pre>
**We strongly recommend you to minimize your browser and try this yourself first.**<br />
One important thing to note is, simply doing `BFS` or `DFS` and picking the longest edge at every step would not work. The reason is, a shorter edge can produce longer path due to higher weight edges connected through it.<br />
The idea is to use `Backtracking`. We start from given source, explore all paths from current vertex. We keep track of current distance from source. If distance becomes more than `k`, we return `true`. If a path doesn’t produces more than `k` distance, we backtrack.<br />
How do we make sure that the path is simple and we don’t loop in a cycle? The idea is to keep track of current path vertices in an array. Whenever we add a vertex to path, we check if it already exists or not in current path. If it exists, we ignore the edge.<br />
Below is implementation of above idea.<br />
```cpp
// Program to find if there is a simple path with
// weight more than k
#include<bits/stdc++.h>
using namespace std;

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a dipathted graph using
// adjacency list representation
class Graph
{
	int V; // No. of vertices

	// In a weighted graph, we need to store vertex
	// and weight pair for every edge
	list< pair<int, int> > *adj;
	bool pathMoreThanKUtil(int src, int k, vector<bool> &path);

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);
	bool pathMoreThanK(int src, int k);
};

// Returns true if graph has path more than k length
bool Graph::pathMoreThanK(int src, int k)
{
	// Create a path array with nothing included
	// in path
	vector<bool> path(V, false);

	// Add source vertex to path
	path[src] = 1;

	return pathMoreThanKUtil(src, k, path);
}

// Prints shortest paths from src to all other vertices
bool Graph::pathMoreThanKUtil(int src, int k, vector<bool> &path)
{
	// If k is 0 or negative, return true;
	if (k <= 0)
		return true;

	// Get all adjacent vertices of source vertex src and
	// recursively explore all paths from src.
	list<iPair>::iterator i;
	for (i = adj[src].begin(); i != adj[src].end(); ++i)
	{
		// Get adjacent vertex and weight of edge
		int v = (*i).first;
		int w = (*i).second;

		// If vertex v is already there in path, then
		// there is a cycle (we ignore this edge)
		if (path[v] == true)
			continue;

		// If weight of is more than k, return true
		if (w >= k)
			return true;

		// Else add this vertex to path
		path[v] = true;

		// If this adjacent can provide a path longer
		// than k, return true.
		if (pathMoreThanKUtil(v, k-w, path))
			return true;

		// Backtrack
		path[v] = false;
	}

	// If no adjacent could produce longer path, return
	// false
	return false;
}

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair> [V];
}

// Utility function to an edge (u, v) of weight w
void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Driver program to test methods of graph class
int main()
{
	// create the graph given in above figure
	int V = 9;
	Graph g(V);

	// making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	int src = 0;
	int k = 62;
	g.pathMoreThanK(src, k)? cout << "Yes\n" : cout << "No\n";
	k = 60;
	g.pathMoreThanK(src, k)? cout << "Yes\n" : cout << "No\n";
	return 0;
}
```
Output:<br />
<pre>
No
Yes
</pre>
<pre>
Time Complexity: O(n!) 
</pre>
**Explanation:**<br />
From the source node, we one-by-one visit all the paths and check if the total weight is greater than `k` for each path. So, the worst case will be when the number of possible paths is maximum. This is the case when every node is connected to every other node.<br />
Beginning from the source node we have n-1 adjacent nodes. The time needed for a path to connect any two nodes is `2`. One for joining the source and the next adjacent vertex. One for breaking the connection between the source and the old adjacent vertex.<br />
After selecting a node out of `n-1` adjacent nodes, we are left with `n-2` adjacent nodes (as the source node is already included in the path) and so on at every step of selecting a node our problem reduces by `1` node.<br />
<pre>
We can write this in the form of a recurrence relation as: F(n) = n*(2+F(n-1))  
This expands to: 2n + 2n*(n-1) + 2n*(n-1)*(n-2) + ……. + 2n(n-1)(n-2)(n-3)…..1  
As n times 2n(n-1)(n-2)(n-3)….1 is greater than the given expression so we can safely say 
time complexity is: n*2*n!  Here in the question the first node is defined so time complexity becomes  
F(n-1) = 2(n-1)*(n-1)! = 2*n*(n-1)! – 2*1*(n-1)! = 2*n!-2*(n-1)! = O(n!)
</pre>








<br /><br /><br />
## Problem 16:
**[Longest Possible Route in a Matrix with Hurdles](https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/)**<br />
Given an `M x N` matrix, with a few hurdles arbitrarily placed, calculate the length of the longest possible route possible from source to a destination within the matrix. We are allowed to move to only adjacent cells which are not hurdles. The route cannot contain any diagonal moves and a location once visited in a particular path cannot be visited again.<br />
For example, the longest path with no hurdles from source to destination is highlighted below. The length of the path is `24`.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/matrix_highlight.png"><br />
The idea is to use `Backtracking`. We start from the source cell of the matrix, move forward in all four allowed directions, and recursively checks if they lead to the solution or not. If the destination is found, we update the value of the longest path else if none of the above solutions work we return `false` from our function.<br />
Below is the implementation of the above idea<br />
```cpp
// C++ program to find Longest Possible Route in a
// matrix with hurdles
#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 10

// A Pair to store status of a cell. found is set to
// true of destination is reachable and value stores
// distance of longest path
struct Pair {
	// true if destination is found
	bool found;

	// stores cost of longest path from current cell to
	// destination cell
	int value;
};

// Function to find Longest Possible Route in the
// matrix with hurdles. If the destination is not reachable
// the function returns false with cost INT_MAX.
// (i, j) is source cell and (x, y) is destination cell.
Pair findLongestPathUtil(int mat[R][C], int i, int j, int x, int y, bool visited[R][C])
{

	// if (i, j) itself is destination, return true
	if (i == x && j == y) {
		Pair p = { true, 0 };
		return p;
	}

	// if not a valid cell, return false
	if (i < 0 || i >= R || j < 0 || j >= C || mat[i][j] == 0 || visited[i][j]) {
		Pair p = { false, INT_MAX };
		return p;
	}

	// include (i, j) in current path i.e.
	// set visited(i, j) to true
	visited[i][j] = true;

	// res stores longest path from current cell (i, j) to
	// destination cell (x, y)
	int res = INT_MIN;

	// go left from current cell
	Pair sol = findLongestPathUtil(mat, i, j - 1, x, y, visited);

	// if destination can be reached on going left from
	// current cell, update res
	if (sol.found)
		res = max(res, sol.value);

	// go right from current cell
	sol = findLongestPathUtil(mat, i, j + 1, x, y, visited);

	// if destination can be reached on going right from
	// current cell, update res
	if (sol.found)
		res = max(res, sol.value);

	// go up from current cell
	sol = findLongestPathUtil(mat, i - 1, j, x, y, visited);

	// if destination can be reached on going up from
	// current cell, update res
	if (sol.found)
		res = max(res, sol.value);

	// go down from current cell
	sol = findLongestPathUtil(mat, i + 1, j, x, y, visited);

	// if destination can be reached on going down from
	// current cell, update res
	if (sol.found)
		res = max(res, sol.value);

	// Backtrack
	visited[i][j] = false;

	// if destination can be reached from current cell,
	// return true
	if (res != INT_MIN) {
		Pair p = { true, 1 + res };
		return p;
	}

	// if destination can't be reached from current cell,
	// return false
	else {
		Pair p = { false, INT_MAX };
		return p;
	}
}

// A wrapper function over findLongestPathUtil()
void findLongestPath(int mat[R][C], int i, int j, int x, int y)
{
	// create a boolean matrix to store info about
	// cells already visited in current route
	bool visited[R][C];

	// initialize visited to false
	memset(visited, false, sizeof visited);

	// find longest route from (i, j) to (x, y) and
	// print its maximum cost
	Pair p = findLongestPathUtil(mat, i, j, x, y, visited);
	if (p.found)
		cout << "Length of longest possible route is " << p.value;

	// If the destination is not reachable
	else
		cout << "Destination not reachable from given " "source";
}

// Driver code
int main()
{
	// input matrix with hurdles shown with number 0
	int mat[R][C] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			  { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
	    		  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

	// find longest path with source (0, 0) and
	// destination (1, 7)
	findLongestPath(mat, 0, 0, 1, 7);

	return 0;
}
```
Output<br />
<pre>
Length of longest possible route is 24
</pre>
<pre>
Time Complexity: 4^(R*C) : Here R and C are the numbers of rows and columns respectively. 
	For every index we have four options, so our overall time complexity will become 4^(R*C).
Auxiliary Space: O(R*C)  : The extra space is used in storing the elements of the visited matrix.
</pre>








<br /><br /><br />
## Problem 17:
**[Print all possible paths from top left to bottom right of a mXn matrix](https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/)**<br />
The problem is to print all the possible paths from `top left` to `bottom right` of a `mXn` matrix with the constraints that from each cell you can either move only to right or down.<br />
**Examples :**<br />
<pre>
Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4
</pre>
The algorithm is a `simple recursive algorithm`, from each cell first print all paths by going down and then print all paths by going right. Do this recursively for each cell encountered.<br />
Following are implementation of the above algorithm.<br />
```cpp
// C++ program to Print all possible paths from
// top left to bottom right of a mXn matrix
#include<iostream>

using namespace std;

/* mat: Pointer to the starting of mXn matrix
i, j: Current position of the robot (For the first call use 0,0)
m, n: Dimensions of given the matrix
pi: Next index to be filed in path array
*path[0..pi-1]: The path traversed by robot till now (Array to hold the
				path need to have space for at least m+n elements) */
void printAllPathsUtil(int *mat, int i, int j, int m, int n, int *path, int pi)
{
	// Reached the bottom of the matrix so we are left with
	// only option to move right
	if (i == m - 1)
	{
		for (int k = j; k < n; k++)
			path[pi + k - j] = *((mat + i*n) + k);
		for (int l = 0; l < pi + n - j; l++)
			cout << path[l] << " ";
		cout << endl;
		return;
	}

	// Reached the right corner of the matrix we are left with
	// only the downward movement.
	if (j == n - 1)
	{
		for (int k = i; k < m; k++)
			path[pi + k - i] = *((mat + k*n) + j);
		for (int l = 0; l < pi + m - i; l++)
			cout << path[l] << " ";
		cout << endl;
		return;
	}

	// Add the current cell to the path being generated
	path[pi] = *((mat + i*n) + j);

	// Print all the paths that are possible after moving down
	printAllPathsUtil(mat, i+1, j, m, n, path, pi + 1);

	// Print all the paths that are possible after moving right
	printAllPathsUtil(mat, i, j+1, m, n, path, pi + 1);

	// Print all the paths that are possible after moving diagonal
	// printAllPathsUtil(mat, i+1, j+1, m, n, path, pi + 1);
}

// The main function that prints all paths from
// top left to bottom right in a matrix 'mat' of size mXn
void printAllPaths(int *mat, int m, int n)
{
	int *path = new int[m+n];
	printAllPathsUtil(mat, 0, 0, m, n, path, 0);
}

// Driver program to test above functions
int main()
{
	int mat[2][3] = { {1, 2, 3}, {4, 5, 6} };
	printAllPaths(*mat, 2, 3);
	return 0;
}
```
Output<br />
<pre>
1 4 5 6 
1 2 5 6 
1 2 3 6 
</pre>





<br /><br /><br />
## Problem 18:
**[]()**<br />

<br /><br /><br />
## Problem 19:
**[]()**<br />
