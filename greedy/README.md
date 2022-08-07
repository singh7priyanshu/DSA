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
**[Job Sequencing Problem](https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1)**<br />
Given a set of `N` jobs where each `jobi` has a deadline and profit associated with it.<br />
Each job takes `1` unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.<br />
Find the number of jobs done and the `maximum profit`.<br />
**Note:** Jobs will be given in the form (`Jobid`, `Deadline`, `Profit`) associated with that Job.<br />

>Example 1:<br />
Input:<br />
N = 4<br />
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}<br />
Output:<br />
2 60<br />
Explanation:<br />
Job1 and Job3 can be done with maximum profit of 60 (20+40).<br />

>Example 2:<br />
Input:<br />
N = 5<br />
Jobs = {(1,2,100),(2,1,19),(3,2,27), (4,1,25),(5,1,15)}<br />
Output:<br />
2 127<br />
Explanation:<br />
2 jobs can be done with maximum profit of 127 (100+27).<br />

**Your Task :**<br />
You don't need to read input or print anything. Your task is to complete the function `JobScheduling()` which takes an integer `N` and an array of `Jobs(Job id, Deadline, Profit)` as input and returns _the count of jobs and maximum profit_.<br />

<pre>
Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)
</pre>

* Constraints: `1 <= N <= 10^5`<br />
`1 <= Deadline <= 100`<br />
`1 <= Profit <= 500`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id, dead, profit;
};


class Solution {
    public:
    static bool comparison(Job a, Job b) { 
        return (a.profit > b.profit); 
    } 

    vector<int> JobScheduling(Job arr[], int n){ 
        int res = 0, count = 0;
        sort(arr, arr+n, comparison); 
        int result[n];
        bool slot[n]; 
        for (int i=0; i<n; i++)slot[i] = false;  
        for (int i=0; i<n; i++){ 
            for (int j=min(n, arr[i].dead)-1; j>=0; j--) { 
                if (slot[j]==false){ 
                    result[j] = i;  
                    slot[j] = true; 
                    break; 
                } 
            } 
        } 
        for (int i=0; i<n; i++){ 
            if (slot[i]){
                count++;
                res += arr[result[i]].profit;
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(res);
        return ans; 
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Job arr[n];
        for(int i = 0;i<n;i++){
            int x, y, z; cin>>x>>y>>z;
            arr[i].id = x;
            arr[i].dead  = y;
            arr[i].profit = z;
        }
        Solution ob;
        vector<int>ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
```





<br /><br /><br />
## Problem 3:
**[Huffman Coding](https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1)**<br />
Given a string `S` of distinct character of size `N` and their corresponding frequency `f[ ]` i.e. character `S[i]` has `f[i]` frequency. Your task is to build the Huffman tree print all the huffman codes in `preorder traversal` of the tree.<br />
**Note:** While merging if two nodes have the same value, then the node which occurs at first will be taken on the `left of Binary Tree` and the other one to the `right`, otherwise Node with less value will be taken on the `left` of the subtree and other one to the `right`.<br />

>Example 1:<br />
S = "abcdef"<br />
f[] = {5, 9, 12, 13, 16, 45}<br />
Output: <br />
0 100 101 1100 1101 111<br />
Explanation:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/fig-6-300x167.jpg"><br />
HuffmanCodes will be:<br />
f : 0<br />
c : 100<br />
d : 101<br />
a : 1100<br />
b : 1101<br />
e : 111<br />
Hence printing them in the PreOrder of Binary Tree.<br />

**Your Task:**<br />
You don't need to read or print anything. Your task is to complete the function `huffmanCodes()` which takes the given string `S`, frequency array `f[ ]` and number of characters `N` as input parameters and returns _a vector of strings containing all huffman codes in order of preorder traversal of the tree_.<br />

<pre>
Expected Time complexity: O(N * LogN) 
Expected Space complexity: O(N) 
</pre>

* Constraints: `1 ≤ N ≤ 26`

```cpp
#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare{
    bool operator()(MinHeapNode* l, MinHeapNode* r){
        return (l->freq > r->freq);
    }
};

class Solution{
    public:
        void getCodes(struct MinHeapNode* root, string str,vector<string> &res){
            if (!root)return;
            if (root->data != '$')res.push_back(str);
            getCodes(root->left, str + "0",res);
            getCodes(root->right, str + "1",res);
        }       
        
        vector<string> huffmanCodes(string S,vector<int> f,int N){
            struct MinHeapNode *left, *right, *top;
            priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
            for (int i = 0; i < N; ++i)minHeap.push(new MinHeapNode(S[i], f[i]));
            while (minHeap.size() != 1){
                left = minHeap.top();
                minHeap.pop();
                right = minHeap.top();
                minHeap.pop();
                top = new MinHeapNode('$', left->freq + right->freq);
                top->left = left;
                top->right = right;
                minHeap.push(top);
            }
            vector<string> res;
            getCodes(minHeap.top(), "",res);
            return res;
        }
};

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.length();
        vector<int>f(n);
        for(int i = 0;i<n;i++)cin>>f[i];
        Solution ob;
        vector<string>ans = ob.huffmanCodes(s, f, n);
        for(auto i : ans)cout<<i<<endl;
        cout<<endl;
    }
    return 0;
}
```








<br /><br /><br />
## Problem 4:
**[Water Connection Problem](https://practice.geeksforgeeks.org/problems/water-connection-problem5822/1)**<br />
There are `n` houses and `p` water pipes in Geek Colony. Every house has at most one pipe going into it and at most one pipe going out of it. Geek needs to install pairs of tanks and taps in the colony according to the following guidelines.<br />

 1. Every house with one outgoing pipe but no incoming pipe gets a tank on its roof.<br />
 2. Every house with only one incoming and no outgoing pipe gets a tap.<br />

The Geek council has proposed a network of pipes where connections are denoted by three input values: `ai`, `bi`, `di` denoting the pipe of diameter `di` from house `ai` to house `bi`.<br />
Find a more efficient way for the construction of this network of pipes. Minimize the diameter of pipes wherever possible.<br />
**Note:** The generated output will have the following format. The first line will contain `t`, denoting the total number of pairs of tanks and taps installed. The next `t` lines contain three integers each: `house number of tank`, `house number of tap`, and `the minimum diameter of pipe between them`.<br />

>Example 1:<br />
Input:<br />
n = 9, p = 6<br />
a[] = {7,5,4,2,9,3}<br />
b[] = {4,9,6,8,7,1}<br />
d[] = {98,72,10,22,17,66}<br /> 
Output:<br /> 
3<br />
2 8 22<br />
3 1 66<br />
5 6 10<br />
Explanation:<br />
Connected components are 3->1, 5->9->7->4->6 and 2->8.<br />
Therefore, our answer is 3 followed by 2 8 22, 3 1 66, 5 6 10.<br />
 
**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `solve()` which takes an integer `n`(the number of houses), `p`(the number of pipes),the array `a[]` , `b[]` and `d[]` (where `d[i]` denoting the diameter of the `ith` pipe from the house `a[i]` to house `b[i]`) as input parameter and returns the array of pairs of tanks and taps installed i.e `ith` element of the array contains three integers: `house number of tank`, `house number of tap` and `the minimum diameter of pipe between them`.<br />  

<pre>
Expected Time Complexity: O(n+p)
Expected Auxiliary Space: O(n+p)
</pre>
 
* Constraints: `1<=n<=20`<br />
`1<=p<=50`<br />
`1<=a[i],b[i]<=20`<br />
`1<=d[i]<=100`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int n, p;
    vector<int> rd;
    vector<int> wt;
    vector<int> cd;
    int ans;
    int dfs(int w){
        if (cd[w] == 0)return w;
        if (wt[w] < ans)ans = wt[w];
        return dfs(cd[w]);
    }

    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d){
        this->n=n;
        this->p=p;
        rd=vector<int>(n+1);
        wt=vector<int>(n+1);
        cd=vector<int>(n+1);
        vector<vector<int>> res;
        int i = 0;
        while (i < p) {
            int q = a[i], h = b[i],
            t = d[i];
            cd[q] = h;
            wt[q] = t;
            rd[h] = q;
            i++;
        }
        for (int j = 1; j <= n; ++j)
            if (rd[j] == 0 && cd[j]) {
                ans = 1000000000;
                int w = dfs(j);
                res.push_back({j,w,ans});
        }
        return res;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, p;
        cin>>n>>p;
        vector<int>a(p), b(p), d(p);
        for(int i = 0;i<p;i++)cin>>a[i]>>b[i]>>d[i];
        Solution ob;
        vector<vector<int>>answer = ob.solve(n, p, a, b, d);
        cout<<answer.size()<<endl;
        for(auto i : answer)cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
    }
    return 0;
}
```







<br /><br /><br />
## Problem 5:
**[Fractional Knapsack Problem](https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)**<br />
Given _weights and values_ of `N` items, we need to put these items in a `knapsack` of capacity `W` to get the `maximum` total value in the knapsack.<br />
**Note:** Unlike 0/1 knapsack, you are allowed to break the item.<br /> 

>Example 1:<br />
Input:<br />
N = 3, W = 50<br />
values[] = {60,100,120}<br />
weight[] = {10,20,30}<br />
Output:<br />
240.00<br />
Explanation:Total maximum value of item we can have is 240.00 from the given capacity of sack.<br />

>Example 2:<br />
Input:<br />
N = 2, W = 50<br />
values[] = {60,100}<br />
weight[] = {10,20}<br />
Output:<br />
160.00<br />
Explanation:<br />
Total maximum value of item we can have is 160.00 from the given capacity of sack.<br />
 
**Your Task :**<br />
Complete the function `fractionalKnapsack()` that receives maximum capacity , `array` of structure/class and size `n` and returns a `double value` representing the maximum value in knapsack.<br />
**Note:** The details of structure/class is defined in the comments above the given function.<br />

<pre>
Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)
</pre>

* Constraints: `1 <= N <= 10^5`<br />
`1 <= W <= 10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution{
    public: 
    static bool cmp(Item a, Item b)
    {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }
    
    
    public:
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr, arr + n, cmp);
        int curWeight = 0;
        double finalvalue = 0.0;
        for (int i = 0; i < n; i++){
            if (curWeight + arr[i].weight <= W){
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            else{
                int remain = W - curWeight;
                finalvalue += arr[i].value * ((double) remain / arr[i].weight);
                break;
            }
        }
        return finalvalue;
    }
};

int main(){
    int t; cin>>t;
    cout<<setprecision(2)<<fixed;
    while(t--){
        int n, W;
        cin>>n>>W;
        Item arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i].value>>arr[i].weight;
        Solution ob;
        cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
    }
    return 0;
}
```







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
