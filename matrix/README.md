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
**[]()**<br />

<br /><br /><br />
## Problem 5:
**[]()**<br />

<br /><br /><br />
## Problem 6:
**[]()**<br />

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
