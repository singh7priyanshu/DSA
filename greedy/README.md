# Love Babbar Sheet 450 - Greedy
## Problem 1:
**[Activity Selection Problem/N meetings in one room](https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1)**<br />
There is one meeting room in a firm. There are `N` meetings in the form of `(start[i], end[i])` where `start[i]` is start time of meeting `i` and `end[i]` is finish time of meeting `i`.<br />
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?<br />
**Note:** Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.<br />

>Example 1:<br />
Input:<br />
N = 6<br />
start[] = {1,3,0,5,8,5}<br />
end[] =  {2,4,6,7,9,9}<br />
Output: <br />
4<br />
Explanation:<br />
Maximum four meetings can be held with given start and end timings.<br />
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)<br />

>Example 2:<br />
Input:<br />
N = 3<br />
start[] = {10, 12, 20}<br />
end[] = {20, 25, 30}<br />
Output: <br />
1<br />
Explanation:<br />
Only one meetings can be held with given start and end timings.<br />

**Your Task :**<br />
You don't need to read inputs or print anything. Complete the function `maxMeetings()` that takes two arrays `start[]` and `end[]` along with their size `N` as input parameters and returns the maximum number of meetings that can be held in the meeting room.<br />

<pre>
Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)
</pre>

* Constraints: `1 ≤ N ≤ 10^5`<br />
`0 ≤ start[i] < end[i] ≤ 10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool pairCompare(const pair<pair<int, int>, int> &a,
                     const pair<pair<int, int>, int> &b){
        if (a.first.second != b.first.second)return a.first.second < b.first.second;
        return a.second < b.second;
    }
   
    int maxMeetings(int start[], int end[], int n){
        vector<pair<pair<int, int>, int>> x;
        for (int i = 0; i < n; i++) 
        x.push_back({{start[i], end[i]}, i + 1});
        sort(x.begin(), x.end(), pairCompare);
        int last = 0, res = 0;
        for (int i = 0; i < n; i++){
            if (x[i].first.first > last){
                res++;
                last = x[i].first.second;
            }
        }
        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int start[n], end[n];
        for(int i=0;i<n;i++)cin>>start[i];
        for(int i=0;i<n;i++)cin>>end[i];
        Solution ob;
        int ans = ob.maxMeetings(start,end,n);
        cout<<ans<<endl;
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
