# Love Babbar Sheet 450 - Bit Manipulation
## Problem 1:
**[Count set bits in an integer](https://practice.geeksforgeeks.org/problems/set-bits0143/1)**<br />
Given a positive integer `N`, print `count of set bits in it`.<br /> 

>Example 1:<br />
Input:<br />
N = 6<br />
Output:<br />
2<br />
Explanation:<br />
Binary representation is '110' So the count of the set bit is 2.<br />

>Example 2:<br />
Input:<br />
8<br />
Output:<br />
1<br />
Explanation:<br />
Binary representation is '1000' So the count of the set bit is 1.<br />

**Your Task:**<br />  
You don't need to read input or print anything. Your task is to complete the function `setBits()` which takes an Integer `N` and returns _the count of number of set bits_.<br />

<pre>
Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ N ≤ 10^9`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setBits(int N) {
        int count = 0;
        while (N) {
            N &= (N - 1);
            count++;
        }
        return count;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Solution ob;
        int cnt = ob.setBits(n);
        cout << cnt << endl;
    }
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
