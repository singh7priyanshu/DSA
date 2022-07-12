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
**[]()**<br />

<br /><br /><br />
## Problem 8:
**[]()**<br />

<br /><br /><br />
## Problem 9:
**[]()**<br />

<br /><br /><br />
## Problem 10:
**[]()**<br />
