# Love Babbar Sheet 450 - Dynamic Programming
## Problem 1:
**[Coin ChangeProblem](https://practice.geeksforgeeks.org/problems/coin-change2448/1)**<br />
Given a value `N`, find the number of ways to make change for `N` cents, if we have infinite supply of each of `S = { S1, S2, .. , SM }` valued coins.<br />

>Example 1:<br />
Input:<br />
n = 4 , m = 3<br />
S[] = {1,2,3}<br />
Output: 4<br />
Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.<br />

>Example 2:<br />
Input:<br />
n = 10 , m = 4<br />
S[] ={2,5,3,6}<br />
Output: 5<br />
Explanation: Five Possible ways are: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `count()` which accepts an array `S[]` its size `m` and `n` as input parameter and returns the number of ways to make change for `N` cents.<br />

<pre>
Expected Time Complexity: O(m*n).
Expected Auxiliary Space: O(n).
</pre>

* Constraints: `1 <= n,m <= 10^3`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int count(int S[], int m, int n) {
        long long int table[n + 1];
        memset(table, 0, sizeof(table));
        table[0] = 1;
        for (int i = 0; i < m; i++)
            for (int j = S[i]; j <= n; j++) table[j] += table[j - S[i]];

        return table[n];

    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[m];
        for(int i=0;i<m;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.count(arr,m,n)<<endl;
    }
    return 0;
}
```





<br /><br /><br />
## Problem 2:
**[]()**<br />

<br /><br /><br />
## Problem 3:
**[]()**<br />

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

<br /><br /><br />
## Problem 20:
**[]()**<br />

<br /><br /><br />
## Problem 21:
**[]()**<br />

<br /><br /><br />
## Problem 22:
**[]()**<br />

<br /><br /><br />
## Problem 23:
**[]()**<br />

<br /><br /><br />
## Problem 24:
**[]()**<br />

<br /><br /><br />
## Problem 25:
**[]()**<br />

<br /><br /><br />
## Problem 26:
**[]()**<br />

<br /><br /><br />
## Problem 27:
**[]()**<br />

<br /><br /><br />
## Problem 28:
**[]()**<br />

<br /><br /><br />
## Problem 29:
**[]()**<br />

<br /><br /><br />
## Problem 30:
**[]()**<br />

<br /><br /><br />
## Problem 31:
**[]()**<br />

<br /><br /><br />
## Problem 32:
**[]()**<br />

<br /><br /><br />
## Problem 33:
**[]()**<br />

<br /><br /><br />
## Problem 34:
**[]()**<br />

<br /><br /><br />
## Problem 35:
**[]()**<br />

<br /><br /><br />
## Problem 36:
**[]()**<br />

<br /><br /><br />
## Problem 37:
**[]()**<br />

<br /><br /><br />
## Problem 38:
**[]()**<br />

<br /><br /><br />
## Problem 39:
**[]()**<br />

<br /><br /><br />
## Problem 40:
**[]()**<br />

<br /><br /><br />
## Problem 41:
**[]()**<br />

<br /><br /><br />
## Problem 42:
**[]()**<br />

<br /><br /><br />
## Problem 43:
**[]()**<br />

<br /><br /><br />
## Problem 44:
**[]()**<br />

<br /><br /><br />
## Problem 45:
**[]()**<br />

<br /><br /><br />
## Problem 46:
**[]()**<br />

<br /><br /><br />
## Problem 47:
**[]()**<br />

<br /><br /><br />
## Problem 48:
**[]()**<br />

<br /><br /><br />
## Problem 49:
**[]()**<br />

<br /><br /><br />
## Problem 50:
**[]()**<br />

<br /><br /><br />
## Problem 51:
**[]()**<br />

<br /><br /><br />
## Problem 52:
**[]()**<br />

<br /><br /><br />
## Problem 53:
**[]()**<br />

<br /><br /><br />
## Problem 54:
**[]()**<br />

<br /><br /><br />
## Problem 55:
**[]()**<br />

<br /><br /><br />
## Problem 56:
**[]()**<br />

<br /><br /><br />
## Problem 57:
**[]()**<br />

<br /><br /><br />
## Problem 58:
**[]()**<br />

<br /><br /><br />
## Problem 59:
**[]()**<br />

<br /><br /><br />
## Problem 60:
**[]()**<br />
