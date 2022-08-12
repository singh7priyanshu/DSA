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
**[Find the two non-repeating elements in an array of repeating elements](https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1)**<br />
Given an array `A` containing `2*N+2` positive numbers, out of which `2*N` numbers exist in pairs whereas the other two number occur exactly once and are distinct.<br /> Find the other two numbers. Return in increasing order.<br />

>Example 1:<br />
Input: <br />
N = 2<br />
arr[] = {1, 2, 3, 2, 1, 4}<br />
Output:<br />
3 4 <br />
Explanation: 3 and 4 occur exactly once.<br />

>Example 2:<br />
Input:<br />
N = 1<br />
arr[] = {2, 1, 3, 2}<br />
Output:<br />
1 3<br />
Explanation: 1 3 occur exactly once.<br />

**Your Task:**<br />
You do not need to read or print anything. Your task is to complete the function `singleNumber()` which takes the array as input parameter and returns _a list of two numbers which occur exactly once in the array_. The list must be in **ascending order**.<br />

<pre>
Expected Time Complexity: O(N)
Expected Space Complexity: O(1)
</pre>

* Constraints: `1 <= length of array <= 10^6` <br />
`1 <= Elements in array <= 5 * 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        long long int diff = 0;
        for(auto i: nums)
            diff = i ^ diff;
        // Get its last set bit
        diff &= -diff;
        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            }
            else // the bit is set
            {
                rets[1] ^= num;
            }
        }
        if(rets[0] > rets[1])
            swap(rets[0], rets[1]);
        return rets;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(2 * n+2);
        for(int i = 0;i<2*n + 2;i++)cin>>v[i];
        Solution ob;
        vector<int>ans = ob.singleNumber(v);
        for(auto i : ans){
            cout << i << " ";
        }
        cout << endl;
    }
}
```




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
