# Competitive-Programming-Essentials-Master-Algorithms-2022
## Coding Exercise 1:
**First Unique Character in a String**<br />
Given a string `s`, find the first non-repeating character in it and return its index. If it does not exist, return `-1`.<br />
* Constraints:<br />`1 <= s.length <= 10^5`<br /> 
`s` consists of only lowercase English letters.<br />
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
 `-10^4 <= nums[i] <= 10^4`<br />
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
## Coding Exercise 4:
**Maximum Score From Removing Stones**<br />
You are playing a solitaire game with three piles of stones of sizes `a`, `b`, and `c` respectively. Each turn you choose two different non-empty piles, take one stone from each, and add 1 point to your score. The game stops when there are fewer than two non-empty piles (meaning there are no more available moves).<br />
Given three integers `a`, `b`, and `c`, return the maximum score you can get.<br />
* Constraints:<br />`1 <= a, b, c <= 10^5` <br />
>Example:<br />
>Input: a = 2, b = 4, c = 6 <br />
>Output: 6 <br />
>Explanation: The starting state is (2, 4, 6). One optimal set of moves is: <br />
>- Take from `1st` and `3rd` piles, state is now `(1, 4, 5)` <br />
>- Take from `1st` and `3rd` piles, state is now `(0, 4, 4)` <br />
>- Take from `2nd` and `3rd` piles, state is now `(0, 3, 3)` <br />
>- Take from `2nd` and `3rd` piles, state is now `(0, 2, 2)` <br />
>- Take from `2nd` and `3rd` piles, state is now `(0, 1, 1)` <br />
>- Take from `2nd` and `3rd` piles, state is now `(0, 0, 0)` <br />
>There are fewer than two non-empty piles, so the game ends. Total: `6` points. <br />
```cpp
#include<bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c) {
    priority_queue<int>q;
    q.push(a);
    q.push(b);
    q.push(c);
    int ans = 0;
    while(q.size()>1){
        int x = q.top(); q.pop();
        int y = q.top(); q.pop();
        x--; y--;
        if(x) q.push(x);
        if(y) q.push(y);
        ans++;
    }
    return ans;
}
```
## Coding Exercise 5:
**Find K Closest Elements**<br />
Given a sorted integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.<br />
An integer `a` is closer to `x` than an integer `b` if: <br />
* `|a - x| < |b - x|`, or <br />
* `|a - x| == |b - x|` and `a < b` <br />
* Constraints: <br />
`1 <= k <= arr.length` <br />
`1 <= arr.length <= 10^4` <br />
`arr` is sorted in ascending order. <br />
`-10^4 <= arr[i], x <= 10^4` <br />
>Example :<br />
>Input: arr = [1,2,3,4,5], k = 4, x = 3 <br />
>Output: [1,2,3,4] <br />
```cpp
#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b){return a<b;}

vector<int> findClosestElements(vector<int> arr, int k, int x) {
    vector<int>ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        int diff = abs(arr[i]-x);
        q.push({diff, arr[i]});
    }
    while(k--){
        ans.push_back(q.top().second);
        q.pop();
    }
    sort(ans.begin(), ans.end(), compare);
    return ans;
}
```



     
