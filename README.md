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
     
