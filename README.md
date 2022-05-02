# Competitive-Programming-Essentials-Master-Algorithms-2022
## Coding Exercise 1:
**First Unique Character in a String**
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
     
