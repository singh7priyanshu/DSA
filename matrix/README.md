# Love Babbar Sheet 450 - Matrix
## Problem 1:
**[Spirally traversing a matrix](https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1)**<br />
Given a matrix of size `r*c`. Traverse the matrix in spiral form.<br />

>Example 1:<br />
>Input:<br />
>r = 4, c = 4<br />
<pre>
matrix[][] = {{1, 2, 3, 4},
             {5, 6, 7, 8},
             {9, 10, 11, 12},
             {13, 14, 15,16}}
           </pre>
>Output: <br />
>1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10<br />
>Explanation:<br />
><img src = "https://www.geeksforgeeks.org/wp-content/uploads/spiral-matrix.png"><br />

>Example 2:<br />
Input:<br />
r = 3, c = 4<br />  
<pre>
matrix[][] = {{1, 2, 3, 4},
              {5, 6, 7, 8},
             {9, 10, 11, 12}}
</pre>
Output: <br />
1 2 3 4 8 12 11 10 9 5 6 7<br />
Explanation:<br />
Applying same technique as shown above, output for the 2nd testcase will be<br /> 
1 2 3 4 8 12 11 10 9 5 6 7.<br />

Your Task:<br />
You dont need to read input or print anything. Complete the function `spirallyTraverse()` that takes matrix, `r` and `c` as input parameters and returns a `list` of integers denoting the spiral traversal of matrix. <br />

<pre>
Expected Time Complexity: O(r*c)
Expected Auxiliary Space: O(r*c), for returning the answer only.
</pre>

* Constraints: `1 <= r, c <= 100`<br />
`0 <= matrixi <= 100` <br />

```cpp
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int row = 0;
        int col = 0;
        vector<int> output;
        
        while(row<r && col<c)
        {
           //storing the elements of 1st row from the remaining rows, in a list.
           for(int i=col; i<c; i++)
               output.push_back(matrix[row][i]);
           row++;
           
           //storing elements of last column from remaining columns, in list.
           for(int i=row; i<r; i++)
               output.push_back(matrix[i][c-1]);
           c--;
           
           //storing the elements of last row from remaining rows, in a list.
            if(row<r)
            {
                for(int i=c-1; i>=col; --i)
                    output.push_back( matrix[r-1][i]);
                r--;
            }
           //storing elements of 1st column from the remaining columns, in list.
            if(col<c)
            {
                for(int i=r-1; i>=row; --i)
                    output.push_back( matrix[i][col]);
                col++;    
            }   
           
        }
        //returning the list.
        return output;
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
```




<br /><br /><br />
## Problem 2:
**[74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)**<br /> 
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:<br />
Integers in each row are sorted from left to right.<br />
The first integer of each row is greater than the last integer of the previous row.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2020/10/05/mat.jpg"><br />
>Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3<br />
>Output: true<br />
 
>Example 2:<br />
><img src = "https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg"><br />
>Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13<br />
>Output: false<br />

* Constraints: `m == matrix.length`<br />
`n == matrix[i].length`<br />
`1 <= m, n <= 100`<br />
`-10^4 <= matrix[i][j], target <= 10^4`<br />
 
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lx = 0, rx = matrix.size();
        int midx = (lx + rx) / 2;
        while (lx < rx) { // Searching vector that may include our target
            if (matrix[midx].back() >= target && matrix[midx][0] <= target) {
                int ly = 0, ry = matrix[midx].size();
                int midy = (ly + ry) / 2;
                while (ly < ry) { // Searching our target
                    if (matrix[midx][midy] == target) return true;
                    if (matrix[midx][midy] < target) {
                        ly = midy + 1;
                    } else {
                        ry = midy;
                    }
                    midy = (ly + ry) / 2;
                }
                return false; // If there is no number equals to target, 
				              // than it can't be anywhere else so returning false
            }
            if (matrix[midx].back() < target) {
                lx = midx + 1;
            } else if (matrix[midx][0] > target) {
                rx = midx;
            }
            midx = (lx + rx) / 2;
        }
        return false;
        
    }
};
```






<br /><br /><br />
## Problem 3:
**[Median in a row-wise sorted Matrix ](https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1)**<br />
Given a row wise sorted matrix of size `RxC` where `R` and `C` are always `odd`, find the median of the matrix.<br />

>Example 1:<br />
<pre>
Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
</pre>

>Example 2:<br />
<pre>
Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `median()` which takes the integers `R` and `C` along with the 2D matrix as input parameters and returns the median of the matrix.<br />

<pre>
Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1<= R,C <=150`<br />
`1<= matrix[i][j] <=2000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < r; i++){
            if (matrix[i][0] < min)min = matrix[i][0];
            if (matrix[i][c-1] > max)max = matrix[i][c-1];
        }
        int desired = (r * c + 1) / 2;
        while (min < max){
            int mid = min + (max - min) / 2;
            int place = 0;
            for (int i = 0; i < r; ++i)place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if (place < desired)min = mid + 1;
            else max = mid;
        }
        return min;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int r, c;
        cin>>r>>c;
        vector<vector<int>>matrix(r, vector<int>(c));
        for(int i = 0;i<r;i++)
            for(int j = 0;j<c;j++)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;
    }
    return 0;
}
```









<br /><br /><br />
## Problem 4:
**[Find row with maximum no. of 1's](https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1)**<br />
Given a boolean 2D array of `n x m` dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.<br />

>Example 1:<br />
<pre>
Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).
</pre>
>Example 2:<br />
<pre>
Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing).
</pre>

**Your Task:**  
You don't need to read input or print anything. Your task is to complete the function **rowWithMax1s()** which takes the array of booleans `arr[][]`, `n` and `m` as input parameters and returns the 0-based index of the first row that has the most number of 1s. If no such row exists, return `-1`.
 
<pre>
Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ N, M ≤ 10^3`<br />
`0 ≤ Arr[i][j] ≤ 1`<br /> 

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int r = 0;
        int c = m-1;
        int max_row_index = -1;
        while(r<n && c>=0){
            if(arr[r][c] == 1){
                max_row_index = r;
                c--;
            }
            else r++;
        }
        return max_row_index;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<vector<int>>arr(n, vector<int>(m));
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin>>arr[i][j];
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout<<ans<<endl;
    }   
    return 0;
}
```








<br /><br /><br />
## Problem 5:
**[Print elements in sorted order using row-column wise sorted matrix](https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1)**<br />
Given an NxN matrix Mat. Sort all elements of the matrix.<br />
>Example 1:<br />
<pre>
Input:
N=4
Mat=[[10,20,30,40],
[15,25,35,45] 
[27,29,37,48] 
[32,33,39,50]]

Output:
10 15 20 25 
27 29 30 32
33 35 37 39
40 45 48 50

Explanation:
Sorting the matrix gives this result.
</pre>

>Example 2:<br />
<pre>
Input:
N=3
Mat=[[1,5,3],[2,8,7],[4,6,9]]
Output:
1 2 3 
4 5 6
7 8 9
Explanation:
Sorting the matrix gives this result.
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `sortedMatrix()` which takes the integer `N` and the matrix `Mat` as input parameters and returns the sorted matrix.

<pre>
Expected Time Complexity:O(N^2LogN)
Expected Auxillary Space:O(N^2)
</pre>

Constraints: `1<=N<=1000`<br />
`1<=Mat[i][j]<=10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int>v;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++)v.push_back(Mat[i][j]);
        }
        sort(v.begin(),v.end());
        int c = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++)Mat[i][j] = v[c++];
        }
        return Mat;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>>v(n, vector<int>(n));
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                cin>>v[i][j];
        Solution ob;
        v = ob.sortedMatrix(n, v);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }   
    return 0;
}
```




<br /><br /><br />
## Problem 6:
**[Maximum size rectangle](https://practice.geeksforgeeks.org/problems/max-rectangle/1)**<br />
Given a binary matrix `M` of size `n X m`. Find the maximum area of a rectangle formed only of `1s` in the given matrix.<br />

>Example 1:<br />
<pre>
Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
	 
Output: 8

Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
</pre>

**Your Task:**<br /> 
Your task is to complete the function `maxArea` which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix `M[ ] [ ]` and the next two are two integers `n` and `m` which denotes the size of the matrix `M`.<br /> 

<pre>
Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)
</pre>

* Constraints: `1<=n,m<=1000`<br />
`0<=M[][]<=1`<br />

**Note:**<br />
The **Input/Ouput** format and **Example** given are used for system's internal purpose, and should be used by a user for **Expected Output** only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
  public:
    int mhist(int row[], int m1) {
        stack<int> result;
        int top_val, max_area = 0, area = 0, i = 0;
        for (i = 0; i < m1;) {
            if (result.empty() || row[result.top()] <= row[i])result.push(i++);
            else {
                top_val = row[result.top()];
                result.pop();
                area = top_val * i;
                if (!result.empty()) area = top_val * (i - result.top() - 1);
                max_area = max(area, max_area);
            }
        }
        while (!result.empty()) {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
            if (!result.empty()) area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
        return max_area;
    }
    int kewl(int M[MAX][MAX], int n, int m) {
        int res = mhist(M[0], m);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j]) M[i][j] += M[i - 1][j];
            }
            res = max(res, mhist(M[i], m));
        }
        return res;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        return kewl(M, n, m);
    }
};

int main(){
    int t; cin>>t;
    int M[MAX][MAX];
    while(t--){
        int n, m; cin>>n>>m;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin>>M[i][j];
        Solution ob;
        cout<<ob.maxArea(M, n, m)<<endl;
    }   
    return 0;
}
```







<br /><br /><br />
## Problem 7:
**[Find a specific pair in Matrix](https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/)**<br />
Given an `n x n` matrix mat[n][n] of integers, find the maximum value of `mat(c, d) – mat(a, b)` over all choices of indexes such that both `c > a` and `d > b`.<br />
>Example:<br /> 
<pre>
Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 }, 
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
Output: 18
The maximum value is 18 as mat[4][2] 
- mat[1][0] = 18 has maximum difference.
</pre>
The program should do only **ONE traversal of the matrix**. i.e. expected time complexity is `O(n^2)`<br />
A **simple solution** would be to apply **Brute-Force**. For all values **mat(a, b)** in the matrix, we find **mat(c, d)** that has maximum value such that **c > a** and **d > b** and keeps on updating maximum value found so far. We finally return the maximum value.<br />
Below is its implementation.<br />

```cpp
// A Naive method to find maximum value of mat[d][e]
// - ma[a][b] such that d > a and e > b
#include <bits/stdc++.h>
using namespace std;
#define N 5

// The function returns maximum value A(d,e) - A(a,b)
// over all choices of indexes such that both d > a
// and e > b.
int findMaxValue(int mat[][N])
{
	// stores maximum value
	int maxValue = INT_MIN;

	// Consider all possible pairs mat[a][b] and
	// mat[d][e]
	for (int a = 0; a < N - 1; a++)
	for (int b = 0; b < N - 1; b++)
		for (int d = a + 1; d < N; d++)
		for (int e = b + 1; e < N; e++)
			if (maxValue < (mat[d][e] - mat[a][b]))
				maxValue = mat[d][e] - mat[a][b];

	return maxValue;
}

// Driver program to test above function
int main()
{
int mat[N][N] = {
				{ 1, 2, -1, -4, -20 },
				{ -8, -3, 4, 2, 1 },
				{ 3, 8, 6, 1, 3 },
				{ -4, -1, 1, 7, -6 },
				{ 0, -4, 10, -5, 1 }
			};
	cout << "Maximum Value is "
		<< findMaxValue(mat);

	return 0;
}
```
**Output**<br />
<pre>
Maximum Value is 18
</pre>
<pre>
Time complexity: O(N^4).
Auxiliary Space: O(1)
</pre>
The above program runs in **O(n^4)** time which is nowhere close to expected time complexity of **O(n^2)**<br />
An **efficient solution** uses extra space. We pre-process the matrix such that **index(i, j)** stores max of elements in matrix from **(i, j)** to **(N-1, N-1)** and in the process keeps on updating maximum value found so far. We finally return the maximum value.<br />
**Implementation:**<br />

```cpp
// An efficient method to find maximum value of mat[d]
// - ma[a][b] such that c > a and d > b
#include <bits/stdc++.h>
using namespace std;
#define N 5

// The function returns maximum value A(c,d) - A(a,b)
// over all choices of indexes such that both c > a
// and d > b.
int findMaxValue(int mat[][N]){
	//stores maximum value
	int maxValue = INT_MIN;

	// maxArr[i][j] stores max of elements in matrix
	// from (i, j) to (N-1, N-1)
	int maxArr[N][N];

	// last element of maxArr will be same's as of
	// the input matrix
	maxArr[N-1][N-1] = mat[N-1][N-1];

	// preprocess last row
	int maxv = mat[N-1][N-1]; // Initialize max
	for (int j = N - 2; j >= 0; j--){
		if (mat[N-1][j] > maxv)maxv = mat[N - 1][j];
		maxArr[N-1][j] = maxv;
	}

	// preprocess last column
	maxv = mat[N - 1][N - 1]; // Initialize max
	for (int i = N - 2; i >= 0; i--){
		if (mat[i][N - 1] > maxv)maxv = mat[i][N - 1];
		maxArr[i][N - 1] = maxv;
	}

	// preprocess rest of the matrix from bottom
	for (int i = N-2; i >= 0; i--){
		for (int j = N-2; j >= 0; j--){
			// Update maxValue
			if (maxArr[i+1][j+1] - mat[i][j] > maxValue)
				maxValue = maxArr[i + 1][j + 1] - mat[i][j];

			// set maxArr (i, j)
			maxArr[i][j] = max(mat[i][j], max(maxArr[i][j + 1], maxArr[i + 1][j]) );
		}
	}
	return maxValue;
}

// Driver program to test above function
int main(){
	int mat[N][N] = {
			{ 1, 2, -1, -4, -20 },
			{ -8, -3, 4, 2, 1 },
			{ 3, 8, 6, 1, 3 },
			{ -4, -1, 1, 7, -6 },
			{ 0, -4, 10, -5, 1 }
			};
	cout << "Maximum Value is "<< findMaxValue(mat);
	return 0;
}
```
**Output**<br />
<pre>
Maximum Value is 18
</pre>
<pre>
Time complexity: O(N^2).
Auxiliary Space: O(N^2)
</pre>
If we are allowed to modify of the matrix, we can avoid using **extra space** and use input matrix instead.<br />














<br /><br /><br />
## Problem 8:
**[Rotate matrix by 90 degrees](https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/)**<br />
Given a square matrix, turn it by **90** degrees in a **clockwise direction** without using any extra space.<br />
>Examples:<br />
<pre>
Input:
1 2 3 
4 5 6
7 8 9  
Output:
7 4 1 
8 5 2
9 6 3

Input:
1 2
3 4
Output:
3 1
4 2 
</pre>
`1. Method 1`<br />
**Approach:** The approach is similar to **Inplace rotate square matrix** by 90 degrees | Set 1. The only thing that is different is to print the elements of the cycle in a clockwise direction i.e. An **N x N** matrix will have **floor(N/2)** square cycles.<br /> 
For example, a **3 X 3** matrix will have **1** cycle. The cycle is formed by its **1st** row, last column, last row, and 1st column.<br /> 
For each square cycle, we swap the elements involved with the corresponding cell in the matrix in the **clockwise direction**. We just need a temporary variable for this.<br />
**Explanation:**<br />
<pre>
Let size of row and column be 3. 
During first iteration – 
a[i][j] = Element at first index (leftmost corner top)= 1.
a[j][n-1-i]= Rightmost corner top Element = 3.
a[n-1-i][n-1-j] = Rightmost corner bottom element = 9.
a[n-1-j][i] = Leftmost corner bottom element = 7.
Move these elements in the clockwise direction. 
During second iteration – 
a[i][j] = 2.
a[j][n-1-i] = 6.
a[n-1-i][n-1-j] = 8.
a[n-1-j][i] = 4. 
Similarly, move these elements in the clockwise direction. 
</pre>
Below is the implementation of the above approach:<br />

```cpp
// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

#define N 4

// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(int a[N][N])
{

	// Traverse each cycle
	for (int i = 0; i < N / 2; i++) {
		for (int j = i; j < N - i - 1; j++) {

			// Swap elements of each cycle
			// in clockwise direction
			int temp = a[i][j];
			a[i][j] = a[N - 1 - j][i];
			a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
			a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
			a[j][N - 1 - i] = temp;
		}
	}
}

// Function for print matrix
void printMatrix(int arr[N][N]){
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
}

// Driver code
int main(){
	int arr[N][N] = { { 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 11, 12 },
			{ 13, 14, 15, 16 } };
	rotate90Clockwise(arr);
	printMatrix(arr);
	return 0;
}
```
**Output**<br />
<pre>
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4 
</pre>
**Complexity Analysis:**<br />
<pre>
Time Complexity – O(n*n)
Auxiliary Space – O(1)
</pre><br />
`2. Method 2:`<br />
**Approach:** The approach is based on the pattern made by indices after rotating the matrix. Consider the following illustration to have a clear insight into it.<br />
Consider a **3 x 3** matrix having indices **(i, j)** as follows.<br />
00 01 02 <br />
10 11 12 <br />
20 21 22 <br />

After rotating the matrix by 90 degrees in clockwise direction, indices transform into <br />
20 10 00  current_row_index = 0, i = 2, 1, 0 <br />
21 11 01 current_row_index = 1, i = 2, 1, 0 <br />
22 12 02  current_row_index = 2, i = 2, 1, 0<br />

**Observation:** In any row, for every decreasing row index i, there exists a constant column index `j`, such that **j = current_row_index**.<br /> 

This pattern can be printed using **2** nested loops.<br />
(This pattern of writing indices is achieved by writing the exact indices of the desired elements of 
where they actually existed in the original array.)<br />
Below is the implementation of the above approach:<br />

```cpp
// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

#define N 4

// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(int arr[N][N]){
	// printing the matrix on the basis of
	// observations made on indices.
	for (int j = 0; j < N; j++){
		for (int i = N - 1; i >= 0; i--)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
}

// Driver code
int main()
{
	int arr[N][N] = { { 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 11, 12 },
			{ 13, 14, 15, 16 } };
	rotate90Clockwise(arr);
	return 0;
}
```
**Output**<br />
<pre>
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4 
</pre>
**Complexity Analysis:**<br />
<pre>
Time Complexity – O(n*n)
Auxiliary Space – O(1)
</pre><br />
`3. Method 3:`<br />
**Approach:** The Approach is to rotate the given matrix two times, first time with respect to the Main diagonal, next time rotate the resultant matrix with respect to the middle column, Consider the following illustration to have a clear insight into it.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210413195604/Untitled-300x150.png"><br />
Below is the implementation of the above approach:<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

#define N 4

void print(int arr[N][N]){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j)
			cout << arr[i][j] << " ";
			
		cout << '\n';
	}
}

void rotate(int arr[N][N]){
	
	// First rotation
	// with respect to main diagonal
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < i; ++j){
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
	
	// Second rotation
	// with respect to middle column
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N / 2; ++j){
			int temp = arr[i][j];
			arr[i][j] = arr[i][N - j - 1];
			arr[i][N - j - 1] = temp;
		}
	}
}

// Driver code
int main(){
	int arr[N][N] = { { 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 11, 12 },
			{ 13, 14, 15, 16 } };
	rotate(arr);
	print(arr);
	return 0;
}
```
**Output**<br />
<pre>
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4
</pre>
**Complexity Analysis:**<br />
<pre>
Time Complexity – O(n*n)
Auxiliary Space – O(1)
</pre><br />
`4. Method 4:`<br />
**Approach:** This approach is similar to method 3 the only difference is that in first rotation we rotate about the **Secondary Diagonal** and after that about the Middle row.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210413192535/Untitled-300x150.png"><br />
Below is the implementation of the above approach:<br />
```cpp
#include <bits/stdc++.h>
using namespace std;

#define N 4

void print(int arr[N][N]){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j)
			cout << arr[i][j] << " ";
			
		cout << '\n';
	}
}

void rotate(int arr[N][N]){
	
	// First rotation
	// with respect to Secondary diagonal
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N - i; j++){
			int temp = arr[i][j];
			arr[i][j] = arr[N - 1 - j][N - 1 - i];
			arr[N - 1 - j][N - 1 - i] = temp;
		}
	}
	
	// Second rotation
	// with respect to middle row
	for(int i = 0; i < N / 2; i++){
		for(int j = 0; j < N; j++){
			int temp = arr[i][j];
			arr[i][j] = arr[N - 1 - i][j];
			arr[N - 1 - i][j] = temp;
		}
	}
}

// Driver code
int main(){
	int arr[N][N] = { { 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 11, 12 },
			{ 13, 14, 15, 16 } };
	rotate(arr);
	print(arr);
	return 0;
}
```
**Output**<br />
<pre>
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4
</pre>
**Complexity Analysis:**<br />
<pre>
Time Complexity – O(n*n)
Auxiliary Space – O(1)
</pre><br />
`5. Method 5:`<br /> 
**Approach:** We first transpose the given matrix, and then reverse the content of individual rows to get the resultant **90 degree** clockwise rotated matrix.<br />
<pre>
1  2  3                                                1  4  7                                                                 7  4  1

4  5  6        ——Transpose——>    2  5  8         —-Reverse individual rows—->    8  5  2     (Resultant matrix)

7  8  9                                                3  6  9                                                                 9  6  3
</pre>
Below is the implementation of the above approach:<br />
```cpp
#include <iostream>
using namespace std;
const int n = 4;
void print(int mat[n][n]){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}
void rotate90clockwise(int mat[n][n]){
	// Transpose of matrix
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			swap(mat[i][j], mat[j][i]);
	// Reverse individual rows
	for (int i = 0; i < n; i++) {
		int low = 0, high = n - 1;
		while (low < high) {
			swap(mat[i][low], mat[i][high]);
			low++;
			high--;
		}
	}
}
int main()
{
	int mat[n][n]
		= { { 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 } };
	rotate90clockwise(mat);
	print(mat);
}
```
**Output**<br />
<pre>
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4
</pre>
**Complexity Analysis:**<br />
<pre>
Time Complexity – O(n*n)
Auxiliary Space – O(1)
</pre>





<br /><br /><br />
## Problem 9:
**[Kth smallest element in a row-column wise sorted matrix](https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1)**<br />
Given a `N x N` matrix, where every row and column is sorted in non-decreasing order. Find the `kth` smallest element in the matrix.<br />

>**Example 1:**<br />
<pre>
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
               {22, 41, 63, 91},
               {27, 50, 87, 93},
               {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
</pre>
>**Example 2:**<br />
<pre>
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
               {15, 25, 35, 45}
               {24, 29, 37, 48}
               {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.
</pre>
**Your Task:**<br />
You don't need to read input or print anything. Complete the function `kthsmallest()` which takes the `mat`, `N` and `K` as input parameters and returns _the kth smallest element in the matrix_.<br />
<pre>
Expected Time Complexity: O(K*Log(N))
Expected Auxiliary Space: O(N)
</pre>
* Constraints: `1 <= N <= 50`<br />
`1 <= mat[][] <= 10000`<br />
`1 <= K <= N*N`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                cin>>mat[i][j];
        int r; cin>>r;
        cout<<kthSmallest(mat, n, r)<<endl;
    }
    return 0;
}


// A structure to store an entry of heap.  The entry contains
// a value from 2D array, row and column numbers of the value
struct HeapNode {
    int val;  // value to be stored
    int r;    // Row number of value in 2D array
    int c;    // Column number of value in 2D array
};

// A utility function to swap two HeapNode items.
void swap(HeapNode *x, HeapNode *y) {
    HeapNode z = *x;
    *x = *y;
    *y = z;
}

// A utility function to minheapify the node harr[i] of a heap
// stored in harr[]
void minHeapify(HeapNode harr[], int i, int heap_size)
{
    int l = i*2 + 1;
    int r = i*2 + 2;
    int smallest = i;
    if (l < heap_size && harr[l].val < harr[i].val)
        smallest = l;
    if (r < heap_size && harr[r].val < harr[smallest].val)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        minHeapify(harr, smallest, heap_size);
    }
}

// A utility function to convert harr[] to a min heap
void buildHeap(HeapNode harr[], int n)
{
    int i = (n - 1)/2;
    while (i >= 0)
    {
        minHeapify(harr, i, n);
        i--;
    }
}



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // k must be greater than 0 and smaller than n*n
    if (k <= 0 || k > n*n)
       return INT_MAX;

    // Create a min heap of elements from first row of 2D array
    HeapNode harr[n];
    for (int i = 0; i < n; i++)
        harr[i] =  {mat[0][i], 0, i};
    buildHeap(harr, n);

    HeapNode hr;
    for (int i = 0; i < k; i++)
    {
       // Get current heap root
       hr = harr[0];

       // Get next value from column of root's value. If the
       // value stored at root was last value in its column,
       // then assign INFINITE as next value
       int nextval = (hr.r < (n-1))? mat[hr.r + 1][hr.c]: INT_MAX;

       // Update heap root with next value
       harr[0] =  {nextval, (hr.r) + 1, hr.c};

       // Heapify root
       minHeapify(harr, 0, n);
    }

    // Return the value at last extracted root
    return hr.val;
}
```










<br /><br /><br />
## Problem 10:
**[Common elements in all rows of a given matrix](https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/)**<br />
Given an `m x n` matrix, find all common elements present in all rows in `O(mn)` time and `one traversal` of matrix.

>**Example:**<br /> 
<pre>
Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

Output: 
1 8 or 8 1
8 and 1 are present in all rows.
</pre>
A **simple solution** is to consider every element and check if it is present in all rows. If present, then print it.<br /> 
A **better solution** is to sort all rows in the matrix and use similar approach.<br /> 
Sorting will take `O(mnlogn)` time and finding common elements will take `O(mn)` time. So overall time complexity of this solution is `O(mnlogn)`.<br /><br />
**Can we do better than O(mnlogn)?**<br /> 
The idea is to use **maps**. We initially insert all elements of the first row in an map. For every other element in remaining rows, we check if it is present in the map. If it is present in the map and is not duplicated in current row, we increment count of the element in map by 1, else we ignore the element. If the currently traversed row is the last row, we print the element if it has appeared `m-1` times before.<br />
Below is the implementation of the idea:<br />

```cpp
// A Program to prints common element in all
// rows of matrix
#include <bits/stdc++.h>
using namespace std;

// Specify number of rows and columns
#define M 4
#define N 5

// prints common element in all rows of matrix
void printCommonElements(int mat[M][N])
{
	unordered_map<int, int> mp;

	// initialize 1st row elements with value 1
	for (int j = 0; j < N; j++)
		mp[mat[0][j]] = 1;

	// traverse the matrix
	for (int i = 1; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// If element is present in the map and
			// is not duplicated in current row.
			if (mp[mat[i][j]] == i)
			{
			// we increment count of the element
			// in map by 1
				mp[mat[i][j]] = i + 1;

				// If this is last row
				if (i==M-1 && mp[mat[i][j]]==M)
				cout << mat[i][j] << " ";
			}
		}
	}
}

// driver program to test above function
int main()
{
	int mat[M][N] =
	{
		{1, 2, 1, 4, 8},
		{3, 7, 8, 5, 1},
		{8, 7, 7, 3, 1},
		{8, 1, 2, 7, 9},
	};

	printCommonElements(mat);

	return 0;
}
```
<pre>
Output
8 1 
</pre>
<pre>
The time complexity of this solution is O(m * n) and we are doing only one traversal of the matrix.
Auxiliary Space: O(N)
</pre>
