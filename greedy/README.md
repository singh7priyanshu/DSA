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
**[Greedy Algorithm to find Minimum number of Coins](https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1)**<br />
You are given a string `s` of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character. Your aim is to find _the lexicographically smallest string that can be obtained by doing this operation at most once_.<br />

>Example 1:<br />
Input:<br />
A = "ccad"<br />
Output: "aacd"<br />
Explanation:<br />
In ccad, we choose a and c and after doing the replacement operation once we get,<br /> 
aacd and this is the lexicographically smallest string possible. <br />
 
>Example 2:<br />
Input:<br />
A = "abba"<br />
Output: "abba"<br />
Explanation:<br />
In abba, we can get baab after doing the replacement operation once for a and b <br />
but that is not lexicographically smaller than abba. So, the answer is abba. <br />

**Your Task:**<br />  
You don't need to read input or print anything. Your task is to complete the function `chooseandswap()` which takes the string `A` as input parameters and returns the _lexicographically smallest string that is possible after doing the operation at most once_.<br />

<pre>
Expected Time Complexity: O(|A|) length of the string A
Expected Auxiliary Space: O(1)
</pre>
 
* Constraints: `1<= |A| <=10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

int left_most[26];
class Solution{
public:
    string chooseandswap(string a){
        int n = a.size();
        string ans = "";
        for(int i = 0; i<=25; i++)left_most[i] = -1;
        for(int i = 0; i<=n-1; i++){
            if(left_most[a[i]-97]==-1)left_most[a[i]-97] = i;
        }
        int j = -1, mark = -1;
        for(int i = 0; i<=n-2; i++){
                j = i;
                for(int k = 0; k<=25; k++){
                    if(left_most[k] > left_most[a[j]-97] && k < (int)(a[j]-97)){
                        mark = k;
                        break;
                    }
                }
            if(mark!=-1)
            break;
        }
        if(mark!=-1){   
            for(int i = 0; i<=n-1; i++){
                if(a[i]==(char)(mark+97))ans += a[j];
                else if(a[i]==a[j])ans += ((char)(mark+97));
                else ans += a[i];
            }
        }
        else{
            for(int i = 0; i<=n-1; i++)ans += a[i];
        }
        return ans;
    }
    
};

int main(){
    Solution ob;
    int t; cin>>t;
    while(t--){
         string a; cin>>a;
         cout<<ob.chooseandswap(a)<<endl;   
    }
    return 0;
}
```









<br /><br /><br />
## Problem 7:
**[Maximum trains for which stoppage can be provided](https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/)**<br />
We are given `n-platform` and two main running railway track for both direction. Trains which needs to stop at your station must occupy one platform for their `stoppage` and the trains which need not to stop at your station will run away through either of main track without stopping. Now, each train has `three` value `first arrival time`, `second departure time` and `third required platform number`. We are given m such trains you have to tell maximum number of train for which you can provide stoppage at your station.<br />

Examples:<br />
<pre>
Input : n = 3, m = 6 
Train no.|  Arrival Time |Dept. Time | Platform No.
    1    |   10:00       |  10:30    |    1
    2    |   10:10       |  10:30    |    1
    3    |   10:00       |  10:20    |    2
    4    |   10:30       |  12:30    |    2
    5    |   12:00       |  12:30    |    3
    6    |   09:00       |  10:05    |    1
Output : Maximum Stopped Trains = 5
Explanation : If train no. 1 will left 
to go without stoppage then 2 and 6 can 
easily be accommodated on platform 1. 
And 3 and 4 on platform 2 and 5 on platform 3.

Input : n = 1, m = 3
Train no.|Arrival Time|Dept. Time | Platform No.
    1    | 10:00      |  10:30    |    1
    2    | 11:10      |  11:30    |    1
    3    | 12:00      |  12:20    |    1
           
Output : Maximum Stopped Trains = 3
Explanation : All three trains can be easily
stopped at platform 1.
</pre>
If we start with a single platform only then we have `1` platform and some trains with their `arrival time` and `departure time` and we have to `maximize` the number of trains on that platform. This task is similar as `Activity Selection Problem`. So, for `n` platforms we will simply make `n-vectors` and put the respective trains in those vectors according to platform number. After that by applying greedy approach we easily solve this problem.<br />
**Note :** We will take input in form of `4-digit integer` for `arrival` and `departure time` as `1030` will represent `10:30` so that we may handle the data type easily.<br />
Also, we will choose a `2-D array` for input as `arr[m][3]` where `arr[i][0]` denotes `arrival time`, `arr[i][1]` denotes `departure time` and `arr[i][2]` denotes the platform for ith train.<br />
```cpp
// CPP to design platform for maximum stoppage
#include <bits/stdc++.h>
using namespace std;

// number of platforms and trains
#define n 2
#define m 5

// function to calculate maximum trains stoppage
int maxStop(int arr[][3])
{
    // declaring vector of pairs for platform
    vector<pair<int, int> > vect[n + 1];

    // Entering values in vector of pairs
    // as per platform number
    // make departure time first element
    // of pair
    for (int i = 0; i < m; i++)
        vect[arr[i][2]].push_back(
            make_pair(arr[i][1], arr[i][0]));

    // sort trains for each platform as per
    // dept. time
    for (int i = 0; i <= n; i++)
        sort(vect[i].begin(), vect[i].end());
    
    // perform activity selection approach
    int count = 0;
    for (int i = 0; i <= n; i++) {
        if (vect[i].size() == 0)
            continue;

        // first train for each platform will
        // also be selected
        int x = 0;
        count++;
        for (int j = 1; j < vect[i].size(); j++) {
            if (vect[i][j].second >= vect[i][x].first) {
                x = j;
                count++;
            }
        }
    }
    return count;
}

// driver function
int main()
{
    int arr[m][3] = { 1000, 1030, 1, 
              1010, 1020, 1,
              1025, 1040, 1,
              1130, 1145, 2,
              1130, 1140, 2 };
    cout << "Maximum Stopped Trains = " << maxStop(arr);
    return 0;
}
```






<br /><br /><br />
## Problem 8:
**[Minimum Platforms Problem](https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1)**<br />
Given `arrival` and `departure` times of all trains that reach a railway station. Find the `minimum` number of platforms required for the railway station so that no train is kept waiting.<br />
Consider that all the trains arrive on the same day and leave on the same day. `Arrival` and `departure` time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform `can not` be used for both departure of a train and arrival of another train. In such cases, we need different platforms.<br />

>Example 1:<br />
Input: n = 6 <br />
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}<br />
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}<br />
Output: 3<br />
Explanation: <br />
Minimum 3 platforms are required to safely arrive and depart all trains.<br />

>Example 2:<br />
Input: n = 3<br />
arr[] = {0900, 1100, 1235}<br />
dep[] = {1000, 1200, 1240}<br />
Output: 1<br />
Explanation: Only 1 platform is required to safely manage the arrival and departure of all trains. <br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `findPlatform()` which takes the array `arr[]` (denoting the arrival times), array `dep[]` (denoting the departure times) and the size of the array as `inputs` and returns _the minimum number of platforms required at the railway station such that no train waits_.<br />
**Note:** Time intervals are in the `24-hour format(HHMM)` , where the first two characters represent hour `(between 00 to 23 )` and the last two characters represent minutes (`this may be > 59`).<br />

<pre>
Expected Time Complexity: O(nLogn)
Expected Auxiliary Space: O(n)
</pre>

* Constraints: `1 ≤ n ≤ 50000`<br />
`0000 ≤ A[i] ≤ D[i] ≤ 2359`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool customsort(const pair<int,char> &a,const pair<int,char> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    int findPlatform(int arr[], int dep[], int n) {
        vector< pair<int,char> > order;
        for (int i = 0; i < n; i++) {
            order.push_back(make_pair(arr[i], 'a'));
            order.push_back(make_pair(dep[i], 'd'));
        }
        sort(order.begin(),order.end(),customsort);
        int result = 1;
        int plat_needed = 0;
        vector< pair<int,char> >::iterator it = order.begin();
        for (; it != order.end(); it++) {
            if ((*it).second == 'a') plat_needed++;
            else plat_needed--;
            if (plat_needed>result)result = plat_needed;
        }
        return result;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n], dep[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        for(int j = 0;j<n;j++)cin>>dep[j];
        Solution ob;
        cout<<ob.findPlatform(arr, dep, n)<<endl;
    }
    return 0;
}
```







<br /><br /><br />
## Problem 9:
**[Buy Maximum Stocks if i stocks can be bought on i-th day](https://www.geeksforgeeks.org/buy-maximum-stocks-stocks-can-bought-th-day/)**<br />
In a stock market, there is a product with its `infinite` stocks. The stock prices are given for `N` days, where `arr[i]` denotes the price of the stock on the `ith` day. There is a rule that a customer can buy at most `i` stock on the `ith` day. If the customer has an amount of `k` amount of money initially, find out the maximum number of stocks a customer can buy.<br />
For example, for `3` days the price of a stock is given as `7`, `10`, `4`. You can buy `1` stock worth `7` rs on day `1`, `2` stocks worth `10` rs each on day `2` and `3` stock worth `4` rs each on day `3`.<br />

Examples:<br />
<pre>
Input : price[] = { 10, 7, 19 }, 
              k = 45.
Output : 4
A customer purchases 1 stock on day 1 for 10 rs, 
2 stocks on day 2 for 7 rs each and 1 stock on day 3 for 19 rs.Therefore total of
10, 7 * 2 = 14 and 19 respectively. Hence, 
total amount is 10 + 14 + 19 = 43 and number 
of stocks purchased is 4.

Input  : price[] = { 7, 10, 4 }, 
               k = 100.
Output : 6
</pre>
The idea is to use `greedy approach`, where we should start buying product from the day when the stock price is least and so on.<br /> 
So, we will sort the pair of two values i.e { `stock price, day` } according to the stock price, and if stock prices are same, then we sort according to the day.<br /> 
Now, we will traverse along the sorted list of pairs, and start buying as follows:<br /> 
Let say, we have `R rs` remaining till now, and the cost of product on this day be `C`, and we can buy atmost `L` products on this day then, total purchase on this day `(P) = min(L, R/C)`.<br /> 
Now, add this value to the answer `total_purchase = total_purchase + P`, `where P =min(L, R/C)`<br /> 
Now, subtract the cost of buying `P` items from remaining money, `R = R – P*C`.<br /> 
Total number of products that we can buy is equal to `total_purchase`.<br />
Below is the implementation of this approach:<br />
```cpp
// C++ program to find maximum number of stocks that
// can be bought with given constraints.
#include <bits/stdc++.h>
using namespace std;

// Return the maximum stocks
int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int> > v;

    // Making pair of product cost and number
    // of day..
    for (int i = 0; i < n; ++i)
        v.push_back(make_pair(price[i], i + 1));

    // Sorting the vector pair.
    sort(v.begin(), v.end());

    // Calculating the maximum number of stock
    // count.
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += min(v[i].second, k / v[i].first);
        k -= v[i].first * min(v[i].second, (k / v[i].first));
    }
    return ans;
}

// Driven Program
int main()
{
    int price[] = { 10, 7, 19 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;
    cout << buyMaximumProducts(n, k, price) << endl;
    return 0;
}
```
Output:<br />
<pre>
4
</pre>
<pre>
Time Complexity :O(nlogn).
</pre>








<br /><br /><br />
## Problem 10:
**[Find the minimum and maximum amount to buy all N candies](https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1)**<br />
In a candy store, there are `N` different types of candies available and the prices of all the `N` different types of candies are provided to you.<br />
You are now provided with an attractive offer.<br />
You can buy a single candy from the store and get at most `K` other candies ( all are different types ) for free.<br />
Now you have to answer two questions. **Firstly**, you have to find what is the `minimum amount` of money you have to spend to buy all the `N` different candies.<br /> **Secondly**, you have to find what is the **maximum** amount of money you have to spend to buy all the `N` different candies.<br />
In both the cases you must utilize the offer i.e. you buy one candy and get `K` other candies for free.<br />

>Example 1:<br />
Input:<br />
N = 4<br />
K = 2<br />
candies[] = {3 2 1 4}<br />
Output:<br />
3 7<br />
Explanation:<br />
As according to the offer if you buy one candy you can take at most two <br />
more for free. So in the first case, you buy the candy which costs 1 and <br />
takes candies worth 3 and 4 for free, also you buy candy worth 2 as well.<br />
So min cost : 1+2 =3.<br />
In the second case, you can buy the candy which costs 4 and takes candies<br /> 
worth 1 and 2 for free, also you need to buy candy worth 3 as well. <br />
So max cost : 3+4 =7.<br />

>Example 2:<br />
Input: <br />
N = 5<br />
K = 4<br />
candies[] = {3 2 1 4 5}<br />
Output: <br />
1 5<br />
Explanation:<br />
For minimimum cost buy the candy with the cost 1 and get all the other candies for free.<br />
For maximum cost buy the candy with the cost 5 and get all other candies for free.<br />

**Your Task:**<br />  
You don't need to read input or print anything. Your task is to complete the function `candyStore()` which takes the array `candies[]`, its size `N` and an integer `K` as input parameters and returns _the minimum amount and maximum amount of money to buy all candies according to the offer_.<br />

<pre>
Expected Time Complexity: O(NLogN)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 <= N <= 100000`<br />
`0 <= K <= N-1`<br />
`1 <= candies[i] <= 10000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> candyStore(int candies[], int N, int K){
        sort(candies, candies + N);
        int groups = N / (K + 1), minCost = 0, maxCost = 0;
        if (N % (K + 1) != 0)groups += 1;
        for (int i = 0; i < groups; ++i)minCost += candies[i];
        for (int i = N - 1; i >= (N - groups); --i)maxCost += candies[i];
        return {minCost, maxCost};  
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        int candies[N];
        for(int i = 0;i<N;i++)cin>>candies[i];
        Solution ob;
        vector<int>cost = ob.candyStore(candies, N, K);
        cout<<cost[0]<<" "<<cost[1]<<endl;
    }
    return 0;
}
```







<br /><br /><br />
## Problem 11:
**[Minimize Cash Flow among a given set of friends who have borrowed money from each other](https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/)**<br />
Given a number of friends who have to give or take some amount of money from one another. Design an `algorithm` by which the total cash flow among all the friends is minimized.<br /> 
Example:<br /> 
Following diagram shows input debts to be settled.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/cashFlow.png"><br />
Above debts can be settled in following optimized way<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/cashFlow1.png"><br />
The idea is to use `Greedy algorithm` where at every step, settle all amounts of one person and recur for remaining `n-1` persons.<br /> 
**How to pick the first person?**<br />
To pick the `first person`, calculate the net amount for every person where net amount is obtained by subtracting all debts (`amounts to pay`) from all credits (`amounts to be paid`). Once net amount for every person is evaluated, find `two persons` with `maximum` and `minimum` net amounts. These two persons are the most `creditors` and `debtors`. The person with `minimum` of `two` is `our first person` to be settled and `removed from list`. Let the `minimum` of two amounts be `x`. We pay `‘x’` amount from the `maximum debtor` to `maximum creditor` and settle one person. If `x` is equal to the `maximum debit`, then `maximum debtor` is settled, else `maximum creditor` is settled.<br />
The following is detailed algorithm.<br />
Do following for every person `Pi` where `i` is from `0` to `n-1`.<br />

 1. Compute the `net` amount for every person. The net amount for person `‘i’` can be computed by `subtracting` sum of all debts from `sum` of all credits.<br />
 2. Find the `two` persons that are `maximum creditor` and `maximum debtor`. Let the `maximum amount` to be `credited` `maximum creditor` be `maxCredit` and `maximum     amount` to be debited from `maximum debtor` be `maxDebit`. Let the `maximum debtor` be `Pd` and maximum creditor be `Pc`.<br />
 3. Find the `minimum` of `maxDebit` and `maxCredit`. Let `minimum` of two be `x`. Debit `‘x’` from `Pd` and `credit` this amount to `Pc`.<br />
 4. If `x` is equal to `maxCredit`, then remove `Pc` from set of persons and `recur` for `remaining (n-1)` persons.<br />
 5. If `x` is equal to `maxDebit`, then remove `Pd` from set of persons and `recur` for `remaining (n-1)` persons.<br />

The following is the implementation of the above algorithm.<br />

```cpp
// C++ program to find maximum cash flow among a set of persons
#include<iostream>
using namespace std;

// Number of persons (or vertices in the graph)
#define N 3

// A utility function that returns index of minimum value in arr[]
int getMin(int arr[])
{
    int minInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}

// A utility function that returns index of maximum value in arr[]
int getMax(int arr[])
{
    int maxInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}

// A utility function to return minimum of 2 values
int minOf2(int x, int y)
{
    return (x<y)? x: y;
}

// amount[p] indicates the net amount to be credited/debited
// to/from person 'p'
// If amount[p] is positive, then i'th person will amount[i]
// If amount[p] is negative, then i'th person will give -amount[i]
void minCashFlowRec(int amount[])
{
    // Find the indexes of minimum and maximum values in amount[]
    // amount[mxCredit] indicates the maximum amount to be given
    //               (or credited) to any person .
    // And amount[mxDebit] indicates the maximum amount to be taken
    //               (or debited) from any person.
    // So if there is a positive value in amount[], then there must
    // be a negative value
    int mxCredit = getMax(amount), mxDebit = getMin(amount);

    // If both amounts are 0, then all amounts are settled
    if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
        return;

    // Find the minimum of two amounts
    int min = minOf2(-amount[mxDebit], amount[mxCredit]);
    amount[mxCredit] -= min;
    amount[mxDebit] += min;

    // If minimum is the maximum amount to be
    cout << "Person " << mxDebit << " pays " << min << " to " << "Person " << mxCredit << endl;

    // Recur for the amount array. Note that it is guaranteed that
    // the recursion would terminate as either amount[mxCredit]
    // or amount[mxDebit] becomes 0
    minCashFlowRec(amount);
}

// Given a set of persons as graph[] where graph[i][j] indicates
// the amount that person i needs to pay person j, this function
// finds and prints the minimum cash flow to settle all debts.
void minCashFlow(int graph[][N])
{
    // Create an array amount[], initialize all value in it as 0.
    int amount[N] = {0};

    // Calculate the net amount to be paid to person 'p', and
    // stores it in amount[p]. The value of amount[p] can be
    // calculated by subtracting debts of 'p' from credits of 'p'
    for (int p=0; p<N; p++)
        for (int i=0; i<N; i++)
            amount[p] += (graph[i][p] - graph[p][i]);
    minCashFlowRec(amount);
}

// Driver program to test above function
int main()
{
    // graph[i][j] indicates the amount that person i needs to
    // pay person j
    int graph[N][N] = { {0, 1000, 2000},
                {0, 0, 5000},
                {0, 0, 0},};

    // Print the solution
    minCashFlow(graph);
    return 0;
}
```
Output:<br />
<pre>
Person 1 pays 4000 to Person 2
Person 0 pays 3000 to Person 2
</pre>
<pre>
Algorithmic Paradigm: Greedy 
</pre>
<pre>
Time Complexity: O(N^2) where N is the number of persons.
</pre>







<br /><br /><br />
## Problem 12:
**[Minimum Cost to cut a board into squares](https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/)**<br />
A board of length `m` and width `n` is given, we need to break this board into `m*n` squares such that cost of breaking is `minimum`. cutting `cost` for each edge will be given for the board. In short, we need to choose such a sequence of cutting such that cost is minimized.<br />
Examples:<br /> 
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/board.png"><br />
<pre>
For above board optimal way to cut into square is:
Total minimum cost in above case is 42. It is 
evaluated using following steps.

Initial Value : Total_cost = 0
Total_cost = Total_cost + edge_cost * total_pieces

Cost 4 Horizontal cut         Cost = 0 + 4*1 = 4
Cost 4 Vertical cut        Cost = 4 + 4*2 = 12
Cost 3 Vertical cut        Cost = 12 + 3*2 = 18
Cost 2 Horizontal cut        Cost = 18 + 2*3 = 24
Cost 2 Vertical cut        Cost = 24 + 2*3 = 30
Cost 1 Horizontal cut        Cost = 30 + 1*4 = 34
Cost 1 Vertical cut        Cost = 34 + 1*4 = 38
Cost 1 Vertical cut        Cost = 38 + 1*4 = 42
</pre>
This problem can be solved using `greedy approach`, If total cost is denoted by `S`, then `S = a1w1 + a2w2 … + akwk`, where `wi` is a cost of certain edge cutting and `ai` is corresponding coefficient, The coefficient `ai` is determined by the total number of cuts we have competed using edge `wi` at the end of the cutting process.<br />
Notice that `sum of the coefficients` is always `constant`, hence we want to find a `distribution` of `ai` obtainable such that `S` is `minimum`. To do so we perform cuts on highest cost edge as early as possible, which will reach to optimal `S`. If we encounter several edges having the `same cost`, we can cut any one of them first.<br /> 
Below is the solution using above approach, `first` we sorted the edge cutting costs in `reverse order`, then we loop in them from `higher-cost` to `lower-cost` building our solution. Each time we choose an edge, counterpart count is incremented by `1`, which is to be multiplied each time with corresponding edge cutting cost. 
Notice below used sort method, sending `greater()` as `3rd argument` to sort method sorts number in non-increasing order, it is predefined function of the library.<br />
```cpp
// C++ program to divide a board into m*n squares
#include <bits/stdc++.h>
using namespace std;

// method returns minimum cost to break board into
// m*n squares
int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
    int res = 0;

    // sort the horizontal cost in reverse order
    sort(X, X + m, greater<int>());

    // sort the vertical cost in reverse order
    sort(Y, Y + n, greater<int>());

    // initialize current width as 1
    int hzntl = 1, vert = 1;

    // loop until one or both cost array are processed
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (X[i] > Y[j])
        {
            res += X[i] * vert;

            // increase current horizontal part count by 1
            hzntl++;
            i++;
        }
        else
        {
            res += Y[j] * hzntl;

            // increase current vertical part count by 1
            vert++;
            j++;
        }
    }

    // loop for horizontal array, if remains
    int total = 0;
    while (i < m)
        total += X[i++];
    res += total * vert;

    // loop for vertical array, if remains
    total = 0;
    while (j < n)
        total += Y[j++];
    res += total * hzntl;

    return res;
}

// Driver code to test above methods
int main()
{
    int m = 6, n = 4;
    int X[m-1] = {2, 1, 3, 1, 4};
    int Y[n-1] = {4, 1, 2};
    cout << minimumCostOfBreaking(X, Y, m-1, n-1);
    return 0;
}
```
Output:<br />  
<pre>
42
</pre>






<br /><br /><br />
## Problem 13:
**[Check if it is possible to survive on Island](https://www.geeksforgeeks.org/survival/)**<br />
You are a poor person in an island. There is only one shop in this island, this shop is open on all days of the week except for Sunday. Consider following constraints:<br /> 

 * N – Maximum unit of food you can buy each day.<br />
 * S – Number of days you are required to survive.<br />
 * M – Unit of food required each day to survive.<br />

Currently, it’s Monday, and you need to survive for the next `S` days.<br /> 
**Find the minimum number of days on which you need to buy food from the shop so that you can survive the next S days**, or determine that it isn’t possible to survive.<br /> 
Examples:<br />
<pre>
Input : S = 10 N = 16 M = 2 
Output : Yes 2 
Explanation 1: One possible solution is to buy a box on the first day (Monday), it’s sufficient to eat from this box up to 8th day (Monday) inclusive. Now, on the 9th day (Tuesday), you buy another box and use the chocolates in it to survive the 9th and 10th day.
Input : 10 20 30 
Output : No 
Explanation 2: You can’t survive even if you buy food because the maximum number of units you can buy in one day is less the required food for one day.
</pre>
**Approach:**<br />
In this problem, the `greedy approach` of buying the food for some consecutive early days is the `right direction`.<br /> 
If we can survive for the first `7` days then we can survive any number of days for that we need to check two things<br /> 

 -> Check whether we can survive one day or not.<br /> 
 -> `(S >= 7)` If we buy food in the first `6` days of the week and we can survive for the week i.e. total food we can buy in a week `(6*N)` is **greater then or equal to** total food we require to survive in a week `(7*M)` then we can survive.<br /> 
 
**Note : We are buying the food in the first 6 days because we are counting from Monday and the shop will remain close on Sunday.**<br />
If any of the above conditions are not `true` then we can’t survive else the equation can be derived as :<br />
the **amount of food that we buy should >= the amount of food required to survive**.—-> equation 1<br />
the **amount of food that we buy =  number of times we buy (days) * amount of food that we get for one time buy (N)**<br />
the **amount of food required to survive = the number of days we need to survive(S) * amount of food required on each day(M)**.<br />
now from our equation 1:<br />
`days * N >= S * M`<br />
hence, `days = ceil (S * M) / N`<br />

```cpp
// C++ program to find the minimum days on which
// you need to buy food from the shop so that you
// can survive the next S days
#include <bits/stdc++.h>
using namespace std;

// function to find the minimum days
void survival(int S, int N, int M)
{

	// If we can not buy at least a week
	// supply of food during the first week
	// OR We can not buy a day supply of food
	// on the first day then we can't survive.
	if (((N * 6) < (M * 7) && S > 6) || M > N)
		cout << "No\n";
	else {
		// If we can survive then we can
		// buy ceil(A/N) times where A is
		// total units of food required.
		int days = (M * S) / N;
		if (((M * S) % N) != 0)
			days++;
		cout << "Yes " << days << endl;
	}
}

// Driver code
int main()
{
	int S = 10, N = 16, M = 2;
	survival(S, N, M);
	return 0;
}
```
Output:<br />
<pre>
Yes 2
</pre>
<pre>
Time Complexity: O(1) 
Space Complexity: O(1) 
</pre>
<br /><br />**Another Approach:**<br />
Check whether the food required for `S` days can be bought or not by excluding the Sundays by taking all other days to buy. If can be bought then greedily buy from the initial day until food acquired is greater than or equal to food required for `S` days.<br />
```cpp
// C++ program to find the minimum days on which
// you need to buy food from the shop so that you
// can survive the next S days
#include <bits/stdc++.h>
using namespace std;

// function to find the minimum days
int minimumDays(int S, int N, int M)
{

	// Food required to survive S days
	double req = S * M;

	// If buying all possible days except sundays, but can't
	// provide the sufficient food. If total can't provide
	// then each week also can't provide.
	if ((S - S / 7) * N < req) {
		return -1;
	} // If possible get the number of days.
	else {
		return ceil(req / N);
	}

	// Or Simply one line code:
	// return ((S-S/7)*N<S*M) ? -1 : ceil(static_cast<double>(S*M)/N);
}

// Driver code
int main()
{
	int S = 10, N = 16, M = 2;

	int days = minimumDays(S, N, M);
	if (days != -1) {
		cout << "Yes " << days << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
```
Output:<br />
<pre>
Yes 2
</pre>
<pre>
Time Complexity: O(1) 
Space Complexity: O(1)
</pre>





<br /><br /><br />
## Problem 14:
**[Find maximum meetings in one room](https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/)**<br />
There is one meeting room in a firm. There are `N` meetings in the form of `(S[i], F[i])` where `S[i]` is the start time of meeting `i` and `F[i]` is the finish time of meeting `i`. The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers.<br />
Examples:<br /> 
<pre>
Input : s[] = {1, 3, 0, 5, 8, 5}, f[] = {2, 4, 6, 7, 9, 9} 
Output : 1 2 4 5 
First meeting [1, 2] 
Second meeting [3, 4] 
Fourth meeting [5, 7] 
Fifth meeting [8, 9]

Input : s[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924}, 
f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 } 
Output : 6 7 1 
</pre>
<br /><br />**Approach:**<br /> 
Idea is to solve the problem using the greedy approach which is the same as `Activity Selection Problem`.<br />

 * Sort all `pairs(Meetings)` in `increasing order` of second number(Finish time) of each pair.<br />
 * Select first meeting of sorted pair as the first Meeting in the room and push it into result vector and set a variable `time_limit(say)` with the second `value(Finishing time)` of the first selected meeting.<br />
 * Iterate from the `second pair` to last pair of the array and if the value of the `first element(Starting time of meeting)` of the **current pair is greater then previously selected pair finish time** `(time_limit)` then select the current pair and update the **result vector (push selected meeting number into vector)** and `variable time_limit`.<br />
 * Print the **Order** of meeting from vector.<br />
 
Below is the implementation of the above approach.<br />
```cpp
// C++ program to find maximum number of meetings
#include <bits/stdc++.h>
using namespace std;

// Function for finding maximum meeting in one room
void maxMeetings(int s[], int f[], int n)
{
	pair<int, int> a[n + 1];
	int i;
	for (i = 0; i < n; i++) {
		a[i].first = f[i];
		a[i].second = i;
	}
	// Sorting of meeting according to their finish time.
	sort(a, a + n);

	// Time_limit to check whether new
	// meeting can be conducted or not.
	int time_limit = a[0].first;

	// Vector for storing selected meeting.
	vector<int> m;

	// Initially select first meeting.
	m.push_back(a[0].second + 1);

	// Check for all meeting whether it
	// can be selected or not.
	for (i = 1; i < n; i++) {
		if (s[a[i].second] > time_limit) {
			// Push selected meeting to vector
			m.push_back(a[i].second + 1);

			// update time limit
			time_limit = a[i].first;
		}
	}

	// Print final selected meetings.
	for (int i = 0; i < m.size(); i++) {
		cout << m[i] << " ";
	}
}

// Driver code
int main()
{
	// Starting time
	int s[] = { 1, 3, 0, 5, 8, 5 };

	// Finish time
	int f[] = { 2, 4, 6, 7, 9, 9 };

	// Number of meetings.
	int n = sizeof(s) / sizeof(s[0]);

	// Function call
	maxMeetings(s, f, n);

	return 0;
}
```
Output:<br />
<pre>
1 2 4 5
</pre>
<pre>
Time Complexity: O(N log(N)) 
Auxiliary Space: O(N) for creating a vector of pairs that is approximately equal to O(n)
</pre>





<br /><br /><br />
## Problem 15:
**[Maximum product subset of an array](https://www.geeksforgeeks.org/maximum-product-subset-array/)**<br />
Given an array `a`, we have to find `maximum product` possible with the subset of elements present in the array. The maximum product can be single element also.<br />
Examples:<br />
<pre>
Input: a[] = { -1, -1, -2, 4, 3 }
Output: 24
Explanation : Maximum product will be ( -2 * -1 * 4 * 3 ) = 24

Input: a[] = { -1, 0 }
Output: 0
Explanation: 0(single element) is maximum product possible
 
Input: a[] = { 0, 0, 0 }
Output: 0
</pre>
A **simple solution** is to generate all subsets, find product of every subset and return maximum product.<br />
A **better solution** is to use the below facts.<br />

 1. If there are `even number` of `negative numbers` and `no zeros`, result is `simply product of all`<br />
 2. If there are `odd number` of `negative numbers` and `no zeros`, result is `product of all` **except** the `negative integer` with the least absolute value.<br />
 3. If there are `zeros`, result is `product of all` **except** `these zeros with one exceptional case`. The exceptional case is when there is `one negative number` and `all other elements are 0`. In this case, result is `0`.<br />

Below is the implementation of the above approach:<br />
```cpp
// CPP program to find maximum product of
// a subset.
#include <bits/stdc++.h>
using namespace std;

int maxProductSubset(int a[], int n)
{
	if (n == 1)
		return a[0];

	// Find count of negative numbers, count
	// of zeros, negative number
	// with least absolute value
	// and product of non-zero numbers
	int max_neg = INT_MIN;
	int count_neg = 0, count_zero = 0;
	int prod = 1;
	for (int i = 0; i < n; i++) {

		// If number is 0, we don't
		// multiply it with product.
		if (a[i] == 0) {
			count_zero++;
			continue;
		}

		// Count negatives and keep
		// track of negative number
		// with least absolute value
		if (a[i] < 0) {
			count_neg++;
			max_neg = max(max_neg, a[i]);
		}

		prod = prod * a[i];
	}

	// If there are all zeros
	if (count_zero == n)
		return 0;

	// If there are odd number of
	// negative numbers
	if (count_neg & 1) {

		// Exceptional case: There is only
		// negative and all other are zeros
		if (count_neg == 1 &&
			count_zero > 0 &&
			count_zero + count_neg == n)
			return 0;

		// Otherwise result is product of
		// all non-zeros divided by
		//negative number with
		// least absolute value
		prod = prod / max_neg;
	}

	return prod;
}

// Driver Code
int main()
{
	int a[] = { -1, -1, -2, 4, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << maxProductSubset(a, n);
	return 0;
}
```
Output<br />
<pre>
24
</pre>
<pre>
Time Complexity: O(n) 
Auxiliary Space: O(1) 
</pre>






<br /><br /><br />
## Problem 16:
**[Maximize array sum after K negations](https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1)**<br />
Given an `array` of integers of size `N` and a number `K`., Your must modify array `arr[]` exactly `K` number of times. Here modify array means in each operation you can replace any array element **either** `arr[i]` by `-arr[i]` or `-arr[i]` by `arr[i]`. You need to perform this operation in such a way that after `K` operations, the sum of the array must be maximum.<br />

>Example 1:<br />
Input:<br />
N = 5, K = 1<br />
arr[] = {1, 2, -3, 4, 5}<br />
Output:<br />
15<br />
Explanation:<br />
We have k=1 so we can change -3 to 3 and sum all the elements to produce 15 as output.<br />

>Example 2:<br />
Input:<br />
N = 10, K = 5<br />
arr[] = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20}<br />
Output:<br />
68<br />
Explanation:<br />
Here  we have k=5 so we turn -2, -4, -12 to 2, 4, and 12 respectively. Since we have<br />
performed 3 operations so k is now 2. To get maximum sum of array we can turn positive<br />
turned 2 into negative and then positive again so k is 0. Now sum is 5+5+4+5+12+5+5+5+20+2 = 68<br />

**Your Task:**<br />
You don't have to print anything, print ting is done by the driver code itself. You have to complete the function `maximizeSum()` which takes the array `A[]`, its size `N`, and an integer `K` as inputs and returns _the maximum possible sum_.<br />

<pre>
Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ N,K ≤ 10^5`<br />
`-10^9 ≤ Ai ≤ 10^9`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k){
        sort(a,a+n);
        long long int sum=0, i;
        for(i=0;i<n;i++){
            if(a[i]<0 and k>0){
                a[i]*=-1;
                k--;
            }
        }
        sort(a,a+n);
        for(i=0;i<n;i++)sum+=a[i];
        if(k&1)sum-=2*a[0];
        return sum;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        long long int a[n+5];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.maximizeSum(a, n, k)<<endl;
    }
    return 0;
}
```







<br /><br /><br />
## Problem 17:
**[Maximize the sum of arr[i]*i](https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1)**<br />
Given an array `A` of `N` integers. Your task is to write a program to find the `maximum value` of `∑arr[i]*i`, where `i = 0, 1, 2,., n 1`.<br />
You are allowed to **rearrange** the elements of the array.<br />
**Note:** Since output could be large, hence module `10^9+7` and then print answer.<br />

>Example 1:<br />
Input : Arr[] = {5, 3, 2, 4, 1}<br />
Output : 40<br />
Explanation:<br />
If we arrange the array as 1 2 3 4 5 then we can see that the minimum index will multiply<br />
with minimum number and maximum index will multiply with maximum number.<br /> 
So 1*0+2*1+3*2+4*3+5*4=0+2+6+12+20 = 40 mod(109+7) = 40<br />

>Example 2:<br />
Input : Arr[] = {1, 2, 3}<br />
Output : 8<br />

**Your Task:**<br />
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function `Maximize()` that takes an array `(arr)`, `sizeOfArray (n)`, and return _the maximum value of an array_. The driver code takes care of the printing.<br />

<pre>
Expected Time Complexity: O(nlog(n)).
Expected Auxiliary Space: O(1).
</pre>

* Constraints: `1 ≤ N ≤ 10^7`<br />
`1 ≤ Ai ≤ N`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int Maximize(int a[],int n){
        sort(a, a+n);
        long long int mod = 1000000007;
        long long int product = 0;
        for(int i = 0;i<n;i++){
            product = (product + ((long long int)a[i] * (i))%mod)%mod;
        }
        return product%mod;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n]; 
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a, n)<<endl;
    }
    return 0;
}
```




<br /><br /><br />
## Problem 18:
**[Maximum sum of absolute difference of any permutation](https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/)**<br />
Given an `array`, we need to find the `maximum sum` of **absolute difference of any permutation** of the given array.<br />
Examples:<br /> 
<pre>
Input : { 1, 2, 4, 8 }
Output : 18
Explanation : For the given array there are 
several sequence possible
like : {2, 1, 4, 8}
       {4, 2, 1, 8} and some more.
Now, the absolute difference of an array sequence will be
like for this array sequence {1, 2, 4, 8}, the absolute
difference sum is 
= |1-2| + |2-4| + |4-8| + |8-1|
= 14
For the given array, we get the maximum value for
the sequence {1, 8, 2, 4}
= |1-8| + |8-2| + |2-4| + |4-1|
= 18
</pre>
To solve this problem, we have to think `greedily` that how can we `maximize` the difference value of the elements so that we can have a `maximum sum`. This is possible only if we calculate the `difference` between some very high values and some very low values like **(highest – smallest)**. This is the idea which we have to use to solve this problem.<br />
Let us see the above example, we will have `maximum difference` possible for sequence `{1, 8, 2, 4}` because in this sequence we will get some `high difference` values, `( |1-8| = 7, |8-2| = 6 .. )`. Here, by placing `8``(highest element)` in place of `1` and `2` we get `two high difference values`. Similarly, for the other values, we will place next **highest values in between other**, as we have only one left i.e `4` which is placed at `last`.<br /> 
<br /><br />**Algorithm:** _To get the maximum sum, we should have a sequence in which small and large elements comes alternate. This is done to get maximum difference_.<br />
**For the implementation of the above algorithm ->**<br />

 1. We will `sort` the array.<br />
 2. Calculate the final sequence by taking `one smallest element` and `largest element` from the `sorted array` and make one vector array of this final sequence.<br /> 
 3. Finally, calculate the `sum` of `absolute` **difference between the elements of the array**.<br />

**Below is the implementation of above idea :**<br /> 
```cpp
// CPP implementation of
// above algorithm
#include <bits/stdc++.h>
using namespace std;

int MaxSumDifference(int a[], int n)
{
	// final sequence stored in the vector
	vector<int> finalSequence;

	// sort the original array
	// so that we can retrieve
	// the large elements from
	// the end of array elements
	sort(a, a + n);

	// In this loop first we will insert
	// one smallest element not entered
	// till that time in final sequence
	// and then enter a highest element
	// (not entered till that time) in
	// final sequence so that we
	// have large difference value. This
	// process is repeated till all array
	// has completely entered in sequence.
	// Here, we have loop till n/2 because
	// we are inserting two elements at a
	// time in loop.
	for (int i = 0; i < n / 2; ++i) {
		finalSequence.push_back(a[i]);
		finalSequence.push_back(a[n - i - 1]);
	}

	// If there are odd elements, push the
	// middle element at the end.
	if (n % 2 != 0)
		finalSequence.push_back(a[n/2]);

	// variable to store the
	// maximum sum of absolute
	// difference
	int MaximumSum = 0;

	// In this loop absolute difference
	// of elements for the final sequence
	// is calculated.
	for (int i = 0; i < n - 1; ++i) {
		MaximumSum = MaximumSum + abs(finalSequence[i] - finalSequence[i + 1]);
	}

	// absolute difference of last element
	// and 1st element
	MaximumSum = MaximumSum + abs(finalSequence[n - 1] - finalSequence[0]);

	// return the value
	return MaximumSum;
}

// Driver function
int main()
{
	int a[] = { 1, 2, 4, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << MaxSumDifference(a, n) << endl;
}
```
Output<br />
<pre>
18
</pre>
<pre>
Time Complexity: O(nlogn), required to sort the array
Auxiliary Space: O(n), as extra space of size n is used
</pre>
<br /><br />**Optimization:**<br />
The space can be optimized to `O(1)`, since we are constructing new array by putting **alternate** term one behind the other, instead to constructing **new array** we can just pick the alternates from the array using `2 pointer technique` and calculate the answer:<br />
<br />**Algorithm:**<br />

 1. sort the `array`<br />
 2. initialize `2` variable `i=0`, `j = size – 1`<br />
 3. set a `flag` (true if we will increment `i` and false if we will decrement `j`) in order to track which variable needs to be changed. since after first move we will **select next min** value i.e. increment `i`, it will be initialised as true;<br />
 4. run the `while loop` and calculate sum for every `i` and `j`, and change `i` and `j` accordingly<br />
 5. after the loop we need to **calculate the difference** of **middle element** and **first**. this will be done separately.<br />

```cpp
// CPP implementation of
// above algorithm
#include <bits/stdc++.h>
using namespace std;

long long int maxSum(int arr[], int n)
{
	sort(arr, arr + n);
	int i = 0, j = n - 1;
	bool off = true;
	long long int sum = 0;
	while (i < j) {
		sum += abs(arr[i] - arr[j]);
		if (!off) {
			j--;
		}
		else {
			i++;
		}
		off = !off;
	}
	sum += abs(arr[i] - arr[0]);
	return sum;
}
// Driver function
int main()
{
	int a[] = { 1, 2, 4, 8 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << maxSum(a, n) << endl;
}
```
Output<br />
<pre>
18
</pre>





<br /><br /><br />
## Problem 19:
**[Maximize sum of consecutive differences in a circular array](https://www.geeksforgeeks.org/maximize-sum-consecutive-differences-circular-array/)**<br />
Given an array of `n` elements. Consider array as `circular array` i.e element after an is `a1`. The task is to find `maximum sum` of the `difference` between `consecutive elements` with `rearrangement` of array element allowed i.e after rearrangement of element find `|a1 – a2| + |a2 – a3| + …… + |an – 1 – an| + |an – a1|`.<br />
Examples:<br />
<pre>
Input : arr[] = { 4, 2, 1, 8 }
Output : 18
Rearrange given array as : { 1, 8, 2, 4 }
Sum of difference between consecutive element
= |1 - 8| + |8 - 2| + |2 - 4| + |4 - 1|
= 7 + 6 + 2 + 3
= 18.

Input : arr[] = { 10, 12, 15 }
Output : 10
</pre>
The idea is to use `Greedy Approach` and try to bring elements having greater difference closer.<br /> 
Consider the sorted permutation of the given array `a1, a1, a2,…., an – 1`, an such that `a1 < a2 < a3…. < an – 1 < an`.<br /> 
Now, to obtain the answer having maximum sum of difference between consecutive element, arrange element in following manner:<br /> 
`a1, an, a2, an-1,…., an/2, a(n/2) + 1`<br /> 
We can observe that the arrangement produces the optimal answer, as all `a1, a2, a3,….., a(n/2)-1, an/2` are `subtracted twice` while `a(n/2)+1 , a(n/2)+2, a(n/2)+3,….., an – 1`, an are added twice.<br /> 
**Note:**  `a(n/2)+1` This term is considered only for even `n` because for odd `n`, it is added once and subtracted once and hence cancels out.<br /> 
**Implementation:**<br />
```cpp
// C++ program to maximize the sum of difference
// between consecutive elements in circular array
#include <bits/stdc++.h>
using namespace std;

// Return the maximum Sum of difference between
// consecutive elements.
int maxSum(int arr[], int n)
{
	int sum = 0;

	// Sorting the array.
	sort(arr, arr + n);

	// Subtracting a1, a2, a3,....., a(n/2)-1, an/2
	// twice and adding a(n/2)+1, a(n/2)+2, a(n/2)+3,.
	// ...., an - 1, an twice.
	for (int i = 0; i < n/2; i++)
	{
		sum -= (2 * arr[i]);
		sum += (2 * arr[n - i - 1]);
	}

	return sum;
}

// Driver Program
int main()
{
	int arr[] = { 4, 2, 1, 8 };
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << maxSum(arr, n) << endl;
	return 0;
}
```
Output<br />
<pre>
18
</pre>
<pre>
Time Complexity: O(nlogn). 
Auxiliary Space : O(1)
</pre>





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
