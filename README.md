# Competitive-Programming-Essentials-Master-Algorithms-2022
## Coding Exercise 1:
**First Unique Character in a String**<br />
Given a string `s`, find the first non-repeating character in it and return its index. If it does not exist, return `-1`.<br />
* Constraints:<br />`1 <= s.length <= 10^5`<br /> 
* `s` consists of only lowercase English letters.<br />
>Example 1: <br /> Input: s = "codingminutes" <br /> 
>Output: 0 <br /> <br />
>Example 2: <br /> Input: s = "aabb"<br /> 
>Output: -1 <br />
```cpp
#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int>count;
    int n = s.size();
    for(int i = 0;i<n;i++)count[s[i]]++;
    for(int i = 0;i<n;i++)if(count[s[i]]==1)return i;
    return -1;
}
```
## Coding Exercise 2:
**Kth Largest Element**<br />
Given an integer array `nums` and an integer `k`, return the `kth` largest element in the array. Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.<br />
* Constraints:<br />`1 <= k <= nums.length <= 10^4`<br />
* `-10^4 <= nums[i] <= 10^4`<br />
>Input: nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4 <br />
>Output: 4<br />
```cpp
#include<bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int> nums, int k) {
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int num: nums){
        pq.push(num);
        if(pq.size()>k)pq.pop();
    }
    return pq.top();
}
```
## Coding Exercise 3:
**One Integer**<br />
You are given a list of integers `nums`. You can reduce the length of `nums` by taking any two integers, removing them, and appending their sum to the end. The cost of doing this is the sum of the two integers you removed.<br />
Return the minimum total cost of reducing `nums` to one integer.<br />
>Note : Cost can be negative also.<br />
* Constraints: <br /> `n <= 100,000` where `n` is length of `nums`.<br />
>Example 1 <br />
>Input: nums : [1, 2, 3, 4, 5]<br />
>Output: 33<br />
>Explanation<br />
> * We take `1` and `2` out to get `[3, 4, 5, 3]`<br />
> * We take `3` and `3` out to get `[4, 5, 6]`<br />
> * We take `4` and `5` out to get `[6, 9]`<br />
> * We take `6` and `9` out to get `[15]`<br />
> * The sum is `33 = 1 + 2 + 3 + 3 + 4 + 5 + 6 + 9`<br />
```cpp
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> nums) {
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i = 0;i<nums.size();i++)pq.push(nums[i]);
    int a, b, sum, ans=0;
    while(pq.size() > 1){
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        sum = a+b; 
        ans += sum;
        pq.push(sum);
    }
    return ans;
}
```

     
