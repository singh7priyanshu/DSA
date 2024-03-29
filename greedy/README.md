# Table of Content 
* [Activity Selection Problem/N meetings in one room](#Problem-1)
* [Job Sequencing Problem](#Problem-2)
* [Huffman Coding](#Problem-3)
* [Water Connection Problem](#Problem-4)
* [Fractional Knapsack Problem](#Problem-5)
* [Greedy Algorithm to find Minimum number of Coins](#Problem-6)
* [Maximum trains for which stoppage can be provided](#Problem-7)
* [Minimum Platforms Problem](#Problem-8)
* [Buy Maximum Stocks if i stocks can be bought on i-th day](#Problem-9)
* [Find the minimum and maximum amount to buy all N candies](#Problem-10)
* [Minimize Cash Flow among a given set of friends who have borrowed money from each other](#Problem-11)
* [Minimum Cost to cut a board into squares](#Problem-12)
* [Check if it is possible to survive on Island](#Problem-13)
* [Find maximum meetings in one room](#Problem-14)
* [Maximum product subset of an array](#Problem-15)
* [Maximize array sum after K negations](#Problem-16)
* [Maximize the sum of arr[i]*i](#Problem-17)
* [Maximum sum of absolute difference of any permutation](#Problem-18)
* [Maximize sum of consecutive differences in a circular array](#Problem-19)
* [Minimum sum of absolute difference of pairs of two arrays](#Problem-20)
* [Program for Shortest Job First (or SJF) CPU Scheduling](#Problem-21)
* [Program for Least Recently Used (LRU) Page Replacement algorithm](#Problem-22)
* [Smallest subset with sum greater than all other elements](#Problem-23)
* [Chocolate Distribution Problem](#Problem-24)
* [DEFKIN - Defense of a Kingdom](#Problem-25)
* [DIEHARD - DIE HARD dynamic-programming](#Problem-26)
* [GERGOVIA - Wine trading in Gergovia greedy](#Problem-27)
* [Picking Up Chicks](#Problem-28)
* [CHOCOLA –Chocolate](#Problem-29)
* [ARRANGE -Arranging Amplifiers sorting](#Problem-30)
* [K Centers Problem](#Problem-31)
* [Minimum Cost of ropes](#Problem-32)
* [Find smallest number with given number of digits and sum of digits](#Problem-33)
* [Rearrange characters in a string such that no two adjacent are same](#Problem-34)
* [Find maximum equal sum of every three stacks](#Problem-35)


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
* [To top](#Table-of-Content)








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
* [To top](#Table-of-Content)




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
* [To top](#Table-of-Content)







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
* [To top](#Table-of-Content)






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
* [To top](#Table-of-Content)






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
* [To top](#Table-of-Content)








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
* [To top](#Table-of-Content)





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
* [To top](#Table-of-Content)






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
* [To top](#Table-of-Content)







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
* [To top](#Table-of-Content)






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
* [To top](#Table-of-Content)






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
* [To top](#Table-of-Content)





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
* [To top](#Table-of-Content)




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
* [To top](#Table-of-Content)




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
* [To top](#Table-of-Content)





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
* [To top](#Table-of-Content)






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
* [To top](#Table-of-Content)



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
* [To top](#Table-of-Content)




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
* [To top](#Table-of-Content)




<br /><br /><br />
## Problem 20:
**[Minimum sum of absolute difference of pairs of two arrays](https://www.geeksforgeeks.org/minimum-sum-absolute-difference-pairs-two-arrays/)**<br />
Given two arrays `a[]` and `b[]` of equal length `n`. The task is to pair each element of array `a` to an element in array `b`, such that sum `S` of absolute differences of all the pairs is minimum.<br />
Suppose, two elements `a[i]` and `a[j]` `(i != j)` of `a` are paired with elements `b[p]` and `b[q]` of `b` respectively, then `p` should not be equal to `q`.<br />
Examples:<br />
<pre>
Input :  a[] = {3, 2, 1}
         b[] = {2, 1, 3}
Output : 0
Explanation :
 1st pairing: |3 - 2| + |2 - 1| + |1 - 3|
         = 1 + 1 + 2 = 4
 2nd pairing: |3 - 2| + |1 - 1| + |2 - 3|
         = 1 + 0 + 1 = 2
 3rd pairing: |2 - 2| + |3 - 1| + |1 - 3|
         = 0 + 2 + 2 = 4
 4th pairing: |1 - 2| + |2 - 1| + |3 - 3|
         = 1 + 1 + 0 = 2
 5th pairing: |2 - 2| + |1 - 1| + |3 - 3|
         = 0 + 0 + 0 = 0
 6th pairing: |1 - 2| + |3 - 1| + |2 - 3|
         = 1 + 2 + 1 = 4
 Therefore, 5th pairing has minimum sum of
 absolute difference.

Input :  n = 4
         a[] = {4, 1, 8, 7}
         b[] = {2, 3, 6, 5}
Output : 6
</pre>
The solution to the problem is a simple **greedy approach**. It consists of two steps.<br />

 * **Step 1 :** Sort both the arrays in **O (n log n)** time.<br /> 
 * **Step 2 :** Find absolute difference of each pair of **corresponding elements** _(elements at same index)_ of both arrays and add the result to the sum `S`. The time complexity of this step is `O(n)`.<br />

Hence, the overall time complexity of the program is `O(n log n)`.<br />
```cpp
// C++ program to find minimum sum of absolute
// differences of two arrays.
#include <bits/stdc++.h>
using namespace std;

// Returns minimum possible pairwise absolute
// difference of two arrays.
long long int findMinSum(long long int a[],long long int b[], int n)
{
	// Sort both arrays
	sort(a, a+n);
	sort(b, b+n);

	// Find sum of absolute differences
	long long int sum= 0 ;
	for (int i=0; i<n; i++)
		sum = sum + abs(a[i]-b[i]);

	return sum;
}

// Driver code
int main()
{
	// Both a[] and b[] must be of same size.
	long long int a[] = {4, 1, 8, 7};
	long long int b[] = {2, 3, 6, 5};
	int n = sizeof(a)/sizeof(a[0]);
	printf("%lld\n", findMinSum(a, b, n));
	return 0;
}
```
Output<br />
<pre>
6
</pre>
<pre>
Time Complexity: O(n * logn)
Auxiliary Space: O(1)
</pre>
* [To top](#Table-of-Content)





<br /><br /><br />
## Problem 21:
**[Program for Shortest Job First (or SJF) CPU Scheduling](https://github.com/singh7priyanshu/love_babbar_450_solutions/blob/main/greedy/Program%20for%20Shortest%20Job%20First%20(or%20SJF)%20CPU%20Scheduling/sol.cpp)**<br />
`Shortest job first (SJF)` or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next.<br /> 
`SJN`, also known as `Shortest Job Next (SJN)`, is a `non-preemptive algorithm`.<br /> 
`Shortest Job first` has the advantage of having a minimum average waiting time among all scheduling algorithms.<br />
It is a `Greedy Algorithm`. It may cause starvation if shorter processes keep coming.<br /> 
This problem can be solved using the concept of ageing. It is practically infeasible as Operating System may not know burst time and therefore may not sort them. 
While it is not possible to predict execution time, several methods can be used to estimate the execution time for a job, such as a weighted average of previous 
execution times.<br /> 
`SJF` can be used in specialized environments where accurate estimates of running time are available.<br />
<br />**Algorithm:**<br />

 1. Sort all the process according to the arrival time.<br /> 
 2. Then select that process which has `minimum arrival time` and `minimum Burst time`.<br /> 
 3. After completion of process make a pool of process which after till the completion of previous process and select that process among the pool which is having `minimum Burst time`.<br />
 
**How to compute below times in SJF using a program?**<br /> 
**Completion Time:** Time at which process completes its execution.<br />
**Turn Around Time:** Time Difference between completion time and arrival time.<br />
<pre>
        Turn Around Time = Completion Time – Arrival Time
</pre>
**Waiting Time(W.T):** Time Difference between turn around time and burst time.<br />
<pre>
	Waiting Time = Turn Around Time – Burst Time
</pre>

In this post, we have assumed arrival times as `0`, so turn around and completion times are same.<br />
<pre>
Output
Enter number of Process: ...Enter the process ID...
Before Arrange...
Process ID    Arrival Time    Burst Time
Final Result...
Process ID    Arrival Time    Burst Time    Waiting Time    Turnaround Time


Output:
Process ID      Arrival Time    Burst Time
1               2               3
2               0               4
3               4               2
4               5               4
Final Result...
Process ID      Arrival Time    Burst Time      Waiting Time    Turnaround Time
2               0               4               0               4
3               4               2               0               2
1               2               3               4               7
4               5               4               4               8
</pre>
```cpp
#include <iostream>
using namespace std;
int mat[10][6];

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void arrangeArrival(int num, int mat[][6])
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (mat[j][1] > mat[j + 1][1]) {
				for (int k = 0; k < 5; k++) {
					swap(mat[j][k], mat[j + 1][k]);
				}
			}
		}
	}
}

void completionTime(int num, int mat[][6])
{
	int temp, val;
	mat[0][3] = mat[0][1] + mat[0][2];
	mat[0][5] = mat[0][3] - mat[0][1];
	mat[0][4] = mat[0][5] - mat[0][2];

	for (int i = 1; i < num; i++) {
		temp = mat[i - 1][3];
		int low = mat[i][2];
		for (int j = i; j < num; j++) {
			if (temp >= mat[j][1] && low >= mat[j][2]) {
				low = mat[j][2];
				val = j;
			}
		}
		mat[val][3] = temp + mat[val][2];
		mat[val][5] = mat[val][3] - mat[val][1];
		mat[val][4] = mat[val][5] - mat[val][2];
		for (int k = 0; k < 6; k++) {
			swap(mat[val][k], mat[i][k]);
		}
	}
}

int main()
{
	int num, temp;

	cout << "Enter number of Process: ";
	cin >> num;

	cout << "...Enter the process ID...\n";
	for (int i = 0; i < num; i++) {
		cout << "...Process " << i + 1 << "...\n";
		cout << "Enter Process Id: ";
		cin >> mat[i][0];
		cout << "Enter Arrival Time: ";
		cin >> mat[i][1];
		cout << "Enter Burst Time: ";
		cin >> mat[i][2];
	}

	cout << "Before Arrange...\n";
	cout << "Process ID\tArrival Time\tBurst Time\n";
	for (int i = 0; i < num; i++) {
		cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t"
			<< mat[i][2] << "\n";
	}

	arrangeArrival(num, mat);
	completionTime(num, mat);
	cout << "Final Result...\n";
	cout << "Process ID\tArrival Time\tBurst Time\tWaiting "
			"Time\tTurnaround Time\n";
	for (int i = 0; i < num; i++) {
		cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t"
			<< mat[i][2] << "\t\t" << mat[i][4] << "\t\t"
			<< mat[i][5] << "\n";
	}
}
```
<br /><br /><br />**[Program for Shortest Job First (or SJF) CPU Scheduling | Set 1 (Non- preemptive)](https://www.geeksforgeeks.org/program-for-shortest-job-first-or-sjf-cpu-scheduling-set-1-non-preemptive/)**<br />
The `shortest job first (SJF)` or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next. `SJN`, also known as `Shortest Job Next (SJN)`, can be `preemptive` or `non-preemptive`.<br />  
**Characteristics of SJF Scheduling:**<br />

 * `Shortest Job first` has the advantage of having a `minimum` average waiting time among all scheduling algorithms.<br />
 * It is a `Greedy Algorithm`.<br />
 * It may cause starvation if shorter processes keep coming. This problem can be solved using the concept of ageing.<br />
 * It is practically infeasible as `Operating System` may not know `burst times` and therefore may not sort them. While it is not possible to predict `execution time`, several methods can be used to estimate the execution time for a job, such as a `weighted average` of previous execution times.<br /> 
 * `SJF` can be used in specialized environments where accurate estimates of running time are available.<br />

**Algorithm:**<br />

 * Sort all the processes according to the `arrival time`.<br /> 
 * Then select that process that has `minimum arrival time` and `minimum Burst time`.<br /> 
 * After completion of the process make a pool of processes that arrives afterward till the completion of the previous process and select that process among the pool which is having `minimum Burst time`.<br /> 

<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/20200303163658/SJF.jpg"><br />
<br />**How to compute below times in SJF using a program?**<br /> 

 * **Completion Time:** Time at which process completes its execution.<br />
 * **Turn Around Time:** Time Difference between completion time and arrival time.<br /> 
   `Turn Around Time = Completion Time – Arrival Time`<br />
 * **Waiting Time(W.T):** Time Difference between turn around time and burst time.<br /> 
   `Waiting Time = Turn Around Time – Burst Time`<br />

`Non-Preemptive Shortest` Job First algorithm can be implemented using `Segment Trees` data structure.<br />
**In this post, we have assumed arrival times as 0, so turn around and completion times are same.**<br />

<br />`Example-1:` Consider the following table of **arrival time** and **burst time** for five processes `P1`, `P2`, `P3`, `P4` and `P5`.<br />
<img src = "https://user-images.githubusercontent.com/71781982/183306103-172c414f-0a4e-46a1-b5b6-cf369ad8904c.png"><br />
The **Shortest Job First CPU Scheduling Algorithm** will work on the basis of steps as mentioned below:<br />
**At time = 0,**<br />

 * Process **P4** arrives and starts executing<br />
 
<img src = "https://user-images.githubusercontent.com/71781982/183306105-95f756ac-aabd-454e-b07f-b774bf70ab86.png"><br />
**At time= 1,**<br /> 

 * Process P3 arrives.<br /> 
 * But, as P4 still needs 2 execution units to complete.<br /> 
 * Thus, P3 will wait till P4 gets executed.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306106-96e30638-ce34-4e2b-abb7-be0eb47bafaa.png"><br />
**At time =2,**<br /> 

 * Process P1 arrives and is added to the waiting table<br /> 
 * P4 will continue its execution.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306109-00cb6d1e-9c2b-4285-b122-a59396ff9533.png"><br />
**At time = 3,**<br /> 

 * Process P4 will finish its execution.<br /> 
 * Then, the burst time of P3 and P1 is compared.<br /> 
 * Process P1 is executed because its burst time is less as compared to P3.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306110-6eec851f-6797-43f8-8249-118dbb3673ab.png"><br />
**At time = 4,**<br /> 

 * Process P5 arrives and is added to the waiting Table.<br />
 * P1 will continue execution.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306112-56edebc9-bf37-4d59-b876-f98bee262015.png"><br />
**At time = 5,**<br /> 

 * Process P2 arrives and is added to the waiting Table. 
 * P1 will continue execution.

<img src = "https://user-images.githubusercontent.com/71781982/183306115-57a24888-7944-413b-afcd-53ab9c52b990.png"><br />
**At time = 6,**<br /> 

 * Process P1 will finish its execution.<br /> 
 * The burst time of P3, P5, and P2 is compared.<br /> 
 * Process P2 is executed because its burst time is the lowest among all.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306116-e54ba7f3-fd58-4c4a-8a5a-972ad49eda7d.png"><br />
**At time=9,**<br /> 

 * Process P2 is executing and P3 and P5 are in the waiting Table.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306117-53e0aee1-768f-4b8c-a381-4acb460041fe.png"><br />
**At time = 11,**<br /> 

 * The execution of Process P2 will be done.<br /> 
 * The burst time of P3 and P5 is compared. <br />
 * Process P5 is executed because its burst time is lower than P3.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306118-1d7a5c72-5f82-4c8a-918e-6dc517fe5061.png"><br />
**At time = 15,**<br />

 * Process P5 will finish its execution.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306099-05ddaa20-a108-4fb9-8861-ad6d5bf5b701.png"><br />
**At time = 23,**<br /> 

 * Process P3 will finish its execution.<br />
 * The overall execution of the processes will be as shown below:<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306085-479bfcec-c3bb-4d63-81e6-cb1526a335ae.png"><br />
**Gantt chart for above execution:**<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20220425161949/UntitledDiagram1-300x78.jpg"><br />
Now, let’s calculate the average waiting time for above example:<br />
<pre>
P4 = 0 – 0 = 0

P1 = 3 – 2 = 1

P2 = 9 – 5 = 4

P5 = 11 – 4 = 7

P3 = 15 – 1 = 14

Average Waiting Time = 0 + 1 + 4 + 7 + 14/5 = 26/5 = 5.2
</pre>
**Advantages of SJF:**<br />

 * SJF is better than the First come first serve(FCFS) algorithm as it reduces the average waiting time.<br />
 * SJF is generally used for long term scheduling<br />
 * It is suitable for the jobs running in batches, where run times are already known.<br />
 * SJF is probably optimal in terms of average turnaround time.<br />

**Disadvantages of SJF:**<br /> 

 * SJF may cause very long turn-around times or starvation.<br />
 * In SJF job completion time must be known earlier, but sometimes it is hard to predict.<br />
 * Sometimes, it is complicated to predict the length of the upcoming CPU request.<br />
 * It leads to the starvation that does not reduce average turnaround time.<br />

**Implementation of SJF Algorithm in C**<br />
```cpp
#include <stdio.h>
int main()
{
	int A[100][4]; // Matrix for storing Process Id, Burst
				// Time, Average Waiting Time & Average
				// Turn Around Time.
	int i, j, n, total = 0, index, temp;
	float avg_wt, avg_tat;
	printf("Enter number of process: ");
	scanf("%d", &n);
	printf("Enter Burst Time:\n");
	// User Input Burst Time and alloting Process Id.
	for (i = 0; i < n; i++) {
		printf("P%d: ", i + 1);
		scanf("%d", &A[i][1]);
		A[i][0] = i + 1;
	}
	// Sorting process according to their Burst Time.
	for (i = 0; i < n; i++) {
		index = i;
		for (j = i + 1; j < n; j++)
			if (A[j][1] < A[index][1])
				index = j;
		temp = A[i][1];
		A[i][1] = A[index][1];
		A[index][1] = temp;

		temp = A[i][0];
		A[i][0] = A[index][0];
		A[index][0] = temp;
	}
	A[0][2] = 0;
	// Calculation of Waiting Times
	for (i = 1; i < n; i++) {
		A[i][2] = 0;
		for (j = 0; j < i; j++)
			A[i][2] += A[j][1];
		total += A[i][2];
	}
	avg_wt = (float)total / n;
	total = 0;
	printf("P	 BT	 WT	 TAT\n");
	// Calculation of Turn Around Time and printing the
	// data.
	for (i = 0; i < n; i++) {
		A[i][3] = A[i][1] + A[i][2];
		total += A[i][3];
		printf("P%d	 %d	 %d	 %d\n", A[i][0],
			A[i][1], A[i][2], A[i][3]);
	}
	avg_tat = (float)total / n;
	printf("Average Waiting Time= %f", avg_wt);
	printf("\nAverage Turnaround Time= %f", avg_tat);
}
```
**Note: In this post, we have assumed arrival times as 0, so turn around and completion times are same.**<br />
<br /><br /><br />**[Shortest Job First (or SJF) CPU Scheduling Non-preemptive algorithm using Segment Tree](https://www.geeksforgeeks.org/shortest-job-first-or-sjf-cpu-scheduling-non-preemptive-algorithm-using-segment-tree/)**<br />
`Shortest job first (SJF)` or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next. `SJN` is a `non-preemptive algorithm`.<br />

 * `Shortest Job first` has the advantage of having a **minimum average waiting time** among all scheduling algorithms.<br />
 * It is a `Greedy Algorithm`.<br />
 * It may cause starvation if shorter processes keep coming. This problem can be solved using the concept of `ageing`.<br />
 * It is practically infeasible as Operating System may not know burst time and therefore may not sort them. While it is not possible to predict execution time, several methods can be used to estimate the execution time for a job, such as a **weighted average of previous execution times**. `SJF` can be used in specialized environments where accurate estimates of running time are available.<br />

**For example:**<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20200303163453/ShortestJobFirstAlgorithm-1024x630.jpg"><br />
In the above example, since the `arrival time` of all the processes is `0`, the execution order of the process is the ascending order of the `burst time` of the processes. The `burst time` is given by the `column duration`. Therefore, the execution order of the processes is given by:<br />
<pre>
P4 -> P1 -> P3 -> P2
</pre>
The algorithm is implemented by using the concept of a `segment tree`.<br />
**Approach:** The following is the approach used for the implementation of the shortest job first:<br /> 

 1. As the name suggests, the `shortest job first algorithm` is an algorithm which executes the process whose `burst time` is least and has arrived before the current time. Therefore, in order to find the process which needs to be executed, sort all the processes from the given set of processes according to their arrival time. This ensures that the process with the **shortest burst time which has arrived first is executed first**.<br />
 2. Instead of finding the `minimum burst time` process among all the arrived processes by iterating the whole struct array, the range minimum of the `burst time` of all the arrived processes upto the current time is calculated using `segment tree`.<br />
 3. After selecting a process which needs to be executed, the completion time, turn around time and waiting time is calculated by using **arrival time and burst time** of the process. The formulae to calculate the respective times are:<br /> 
 * **Completion Time:** Time at which process completes its execution.<br />

<pre>
	Completion Time = Start Time + Burst Time
</pre>
**Turn Around Time:** Time Difference between `completion time` and `arrival time`.<br />
<pre>
	Turn Around Time = Completion Time – Arrival Time
</pre>
**Waiting Time(W.T):** Time Difference between `turn around time` and `burst time`.<br />
<pre>
	Waiting Time = Turn Around Time – Burst Time
</pre>

 1. After calculating, the respective times are updated in the array and the `burst time` of the executed process is set to infinity in the `segment tree base array` so that it is not considered as the `minimum burst time` in the further queries.<br />
 
Below is the implementation of the `shortest job first` using the `concept of segment tree`:<br />
```cpp
// C++ implementation of shortest job first
// using the concept of segment tree

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define z 1000000007
#define sh 100000
#define pb push_back
#define pr(x) printf("%d ", x)

struct util {

	// Process ID
	int id;
	// Arrival time
	int at;
	// Burst time
	int bt;
	// Completion time
	int ct;
	// Turnaround time
	int tat;
	// Waiting time
	int wt;
}

// Array to store all the process information
// by implementing the above struct util
ar[sh + 1];

struct util1 {

	// Process id
	int p_id;
	// burst time
	int bt1;
};

util1 range;

// Segment tree array to
// process the queries in nlogn
util1 tr[4 * sh + 5];

// To keep an account of where
// a particular process_id is
// in the segment tree base array
int mp[sh + 1];

// Comparator function to sort the
// struct array according to arrival time
bool cmp(util a, util b)
{
	if (a.at == b.at)
		return a.id < b.id;
	return a.at < b.at;
}

// Function to update the burst time and process id
// in the segment tree
void update(int node, int st, int end,
			int ind, int id1, int b_t)
{
	if (st == end) {
		tr[node].p_id = id1;
		tr[node].bt1 = b_t;
		return;
	}
	int mid = (st + end) / 2;
	if (ind <= mid)
		update(2 * node, st, mid, ind, id1, b_t);
	else
		update(2 * node + 1, mid + 1, end, ind, id1, b_t);
	if (tr[2 * node].bt1 < tr[2 * node + 1].bt1) {
		tr[node].bt1 = tr[2 * node].bt1;
		tr[node].p_id = tr[2 * node].p_id;
	}
	else {
		tr[node].bt1 = tr[2 * node + 1].bt1;
		tr[node].p_id = tr[2 * node + 1].p_id;
	}
}

// Function to return the range minimum of the burst time
// of all the arrived processes using segment tree
util1 query(int node, int st, int end, int lt, int rt)
{
	if (end < lt || st > rt)
		return range;
	if (st >= lt && end <= rt)
		return tr[node];
	int mid = (st + end) / 2;
	util1 lm = query(2 * node, st, mid, lt, rt);
	util1 rm = query(2 * node + 1, mid + 1, end, lt, rt);
	if (lm.bt1 < rm.bt1)
		return lm;
	return rm;
}

// Function to perform non_preemptive
// shortest job first and return the
// completion time, turn around time and
// waiting time for the given processes
void non_preemptive_sjf(int n)
{

	// To store the number of processes
	// that have been completed
	int counter = n;

	// To keep an account of the number
	// of processes that have been arrived
	int upper_range = 0;

	// Current running time
	int tm = min(INT_MAX, ar[upper_range + 1].at);

	// To find the list of processes whose arrival time
	// is less than or equal to the current time
	while (counter) {
		for (; upper_range <= n;) {
			upper_range++;
			if (ar[upper_range].at > tm || upper_range > n) {
				upper_range--;
				break;
			}

			update(1, 1, n, upper_range,
				ar[upper_range].id, ar[upper_range].bt);
		}

		// To find the minimum of all the running times
		// from the set of processes whose arrival time is
		// less than or equal to the current time
		util1 res = query(1, 1, n, 1, upper_range);

		// Checking if the process has already been executed
		if (res.bt1 != INT_MAX) {
			counter--;
			int index = mp[res.p_id];
			tm += (res.bt1);

			// Calculating and updating the array with
			// the current time, turn around time and waiting time
			ar[index].ct = tm;
			ar[index].tat = ar[index].ct - ar[index].at;
			ar[index].wt = ar[index].tat - ar[index].bt;

			// Update the process burst time with
			// infinity when the process is executed
			update(1, 1, n, index, INT_MAX, INT_MAX);
		}
		else {
			tm = ar[upper_range + 1].at;
		}
	}
}

// Function to call the functions and perform
// shortest job first operation
void execute(int n)
{

	// Sort the array based on the arrival times
	sort(ar + 1, ar + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		mp[ar[i].id] = i;

	// Calling the function to perform
	// non-preemptive-sjf
	non_preemptive_sjf(n);
}

// Function to print the required values after
// performing shortest job first
void print(int n)
{

	cout << "ProcessId "
		<< "Arrival Time "
		<< "Burst Time "
		<< "Completion Time "
		<< "Turn Around Time "
		<< "Waiting Time\n";
	for (int i = 1; i <= n; i++) {
		cout << ar[i].id << " \t\t "
			<< ar[i].at << " \t\t "
			<< ar[i].bt << " \t\t "
			<< ar[i].ct << " \t\t "
			<< ar[i].tat << " \t\t "
			<< ar[i].wt << " \n";
	}
}

// Driver code
int main()
{
	// Number of processes
	int n = 5;

	// Initializing the process id
	// and burst time
	range.p_id = INT_MAX;
	range.bt1 = INT_MAX;

	for (int i = 1; i <= 4 * sh + 1; i++) {
		tr[i].p_id = INT_MAX;
		tr[i].bt1 = INT_MAX;
	}

	// Arrival time, Burst time and ID
	// of the processes on which SJF needs
	// to be performed
	ar[1].at = 1;
	ar[1].bt = 7;
	ar[1].id = 1;

	ar[2].at = 2;
	ar[2].bt = 5;
	ar[2].id = 2;

	ar[3].at = 3;
	ar[3].bt = 1;
	ar[3].id = 3;

	ar[4].at = 4;
	ar[4].bt = 2;
	ar[4].id = 4;

	ar[5].at = 5;
	ar[5].bt = 8;
	ar[5].id = 5;

	execute(n);

	// Print the calculated time
	print(n);
}
```
Output:<br />
<pre>
ProcessId  Arrival Time  Burst Time  Completion Time  Turn Around Time  Waiting Time
1          1             7           8                7                 0 
2          2             5           16               14                9 
3          3             1           9                6                 5  
4          4             2           11               7                 5 
5          5             8           24               19                11
</pre>
**Time Complexity:** In order to analyze the running time of the above algorithm, the following running times needs to be understood first:<br />

 * The time complexity to construct a `segment tree` for `N` processes is `O(N)`.<br />
 * The time complexity to update a node in a `segment tree` is given by `O(log(N))`.<br />
 * The time complexity to perform a range minimum query in a `segment tree` is given by `O(log(N))`.<br />
 * Since the update operation and queries are performed for given `N` processes, the total time complexity of the algorithm is `O(N*log(N))` where `N` is the number of processes.<br />
 * This algorithm performs better than the approach mentioned in this article because it takes `O(N^2)` for execution.<br />

<br /><br /><br />**[Shortest Remaining Time First (Preemptive SJF) Scheduling Algorithm](https://www.geeksforgeeks.org/shortest-remaining-time-first-preemptive-sjf-scheduling-algorithm/)**<br />
The `preemptive version` of `SJF` known as `Shortest Remaining Time First (SRTF)`.<br />
In the `Shortest Remaining Time First (SRTF)` scheduling algorithm, the process with the smallest amount of time remaining until completion is selected to execute. Since the currently executing process is the one with the shortest amount of time remaining by definition, and since that time should only reduce as execution progresses, processes will always run until they complete or a new process is added that requires **a smaller amount of time**.<br />
**Examples to show working of Preemptive Shortest Job First CPU Scheduling Algorithm:**<br />
`Example-1:` Consider the following table of **arrival time** and **burst time** for five processes `P1`, `P2`, `P3`, `P4` and `P5`.<br />
<img src = "https://user-images.githubusercontent.com/71781982/183306103-172c414f-0a4e-46a1-b5b6-cf369ad8904c.png"><br />
The `Shortest Job First CPU Scheduling Algorithm` will work on the basis of steps as mentioned below:<br />
**At time = 0,**<br />

 * Process P4 arrives and starts executing<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306105-95f756ac-aabd-454e-b07f-b774bf70ab86.png"><br />
**At time= 1,**<br /> 

 * Process P3 arrives.<br /> 
 * But, as P4 has a shorter burst time. It will continue execution.<br />
 * Thus, P3 will wait till P4 gets executed.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306087-95a90016-4cbc-4a45-90ab-9e9daf495abc.png"><br />
**At time =2,**<br /> 

 * Process P1 arrives with burst time = 6<br />
 * As the burst time of P1 is more than that of P4<br /> 
 * Thus, P4 will continue its execution.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306088-874cb97b-11e9-4c8b-89c3-d72d30dfa627.png"><br />
**At time = 3,**<br /> 

 * Process P4 will finish its execution.<br /> 
 * Then, the burst time of P3 and P1 is compared.<br /> 
 * Process P1 is executed because its burst time is less as compared to P3.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306089-4170ca06-0f97-4584-b2a0-7f0804cfaa46.png"><br />
**At time = 4,**<br /> 

 * Process P5 arrives.<br />
 * Then the burst time of P3, P5, and P1 is compared.<br /> 
 * Process P5 gets executed first among them because its burst time is lowest, and process P1 is preempted.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306092-0898ce29-1892-4d89-9d5f-a19d39f28fef.png"><br />
**At time = 5,**<br /> 

 * Process P2 arrives.<br />
 * The burst time of all processes are compared,<br /> 
 * Process P2 gets executed as its burst time is lowest among all.<br /> 
 * Process P5 is preempted.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306094-ddc79a2a-ae57-44c6-9378-3e9ac7621bff.png"><br />
**At time = 6,**<br /> 

 * Process P2 will keep executing.<br />
 * It will execute till time = 8 as the burst time of P2 is 2ms<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306096-fe86c2b9-649a-4be4-b37d-db55fa8ae187.png"><br />
**At time=7,**<br /> 

 * The process P2 finishes its execution.<br />
 * Then again the burst time of all remaining processes is compared. <br />
 * The Process P5 gets executed because its burst time is lesser than the others.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306097-feeeb468-b16b-4a71-9a19-6e285852e932.png"><br />
**At time = 10,**<br /> 

 * The process P5 will finish its execution.<br />
 * Then the burst time of the remaining processes P1 and P3 is compared.<br /> 
 * Thus, process P1 is executed as its burst time is less than P3<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306098-2c15a53c-967e-4db1-8cf3-d300b8de4872.png"><br />
**At time = 15,**<br />

 * The process P1 finishes its execution and P3 is the only process left.<br />
 * P3 will start executing.<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306099-05ddaa20-a108-4fb9-8861-ad6d5bf5b701.png"><br />
**At time = 23,**<br /> 

 * Process P3 will finish its execution.<br />
 * The overall execution of the processes will be as shown below:<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306100-c1562521-fa28-4c33-9da9-d8315e5784bf.png"><br />
**Gantt chart for above execution:**<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20220427173554/UntitledDiagram3.jpg"><br />
Now, lets calculate `average waiting time` and turn around time:<br />
As we know,<br />

 * **Turn Around time** = Completion time – arrival time<br />
 * **Waiting Time** = Turn around time – burst time<br />

<img src = "https://user-images.githubusercontent.com/71781982/183306101-2dcfec80-8bdc-44b9-9784-548e1d65881d.png"><br />
Now,<br /> 

 * **Average Turn around time** = (13 + 2 + 22 + 3 + 6)/5 = 9.2<br />
 * **Average waiting time** = (7 + 0 + 14 + 0 + 2)/5 = 23/5 = 4.6<br />

<br /><br />**Implementation of SRTF Algorithm:**<br />
**Approach:**<br />

 * Traverse until all process gets completely executed.<br />
	* Find process with minimum remaining time at every single time lap.<br />
	* Reduce its time by 1.<br />
	* Check if its remaining time becomes 0<br /> 
	* Increment the counter of process completion.<br />
	* Completion time of current process = current_time + 1;<br />
	* Calculate waiting time for each completed process.<br />
  	  	* **wt[i]= Completion time – arrival_time-burst_time**<br />
	* Increment time lap by one.<br />
 * Find turnaround time **(waiting_time + burst_time)**.<br />
 
 Program to implement Shortest Remaining Time First:<br />
 ```cpp
 // C++ program to implement Shortest Remaining Time First
// Shortest Remaining Time First (SRTF)

#include <bits/stdc++.h>
using namespace std;

struct Process {
	int pid; // Process ID
	int bt; // Burst Time
	int art; // Arrival Time
};

// Function to find the waiting time for all
// processes
void findWaitingTime(Process proc[], int n, int wt[])
{
	int rt[n];

	// Copy the burst time into rt[]
	for (int i = 0; i < n; i++)
		rt[i] = proc[i].bt;

	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;

	// Process until all processes gets
	// completed
	while (complete != n) {

		// Find process with minimum
		// remaining time among the
		// processes that arrives till the
		// current time`
		for (int j = 0; j < n; j++) {
			if ((proc[j].art <= t) &&
			(rt[j] < minm) && rt[j] > 0) {
				minm = rt[j];
				shortest = j;
				check = true;
			}
		}

		if (check == false) {
			t++;
			continue;
		}

		// Reduce remaining time by one
		rt[shortest]--;

		// Update minimum
		minm = rt[shortest];
		if (minm == 0)
			minm = INT_MAX;

		// If a process gets completely
		// executed
		if (rt[shortest] == 0) {

			// Increment complete
			complete++;
			check = false;

			// Find finish time of current
			// process
			finish_time = t + 1;

			// Calculate waiting time
			wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;

			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}
		// Increment time
		t++;
	}
}

// Function to calculate turn around time
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n; i++)
		tat[i] = proc[i].bt + wt[i];
}

// Function to calculate average time
void findavgTime(Process proc[], int n)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	// Function to find waiting time of all
	// processes
	findWaitingTime(proc, n, wt);

	// Function to find turn around time for
	// all processes
	findTurnAroundTime(proc, n, wt, tat);

	// Display processes along with all
	// details
	cout << " P\t\t"
		<< "BT\t\t"
		<< "WT\t\t"
		<< "TAT\t\t\n";

	// Calculate total waiting time and
	// total turnaround time
	for (int i = 0; i < n; i++) {
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << proc[i].pid << "\t\t" << proc[i].bt << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
	}

	cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
	cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}

// Driver code
int main()
{
	Process proc[] = { { 1, 6, 2 }, { 2, 2, 5 }, { 3, 8, 1 }, { 4, 3, 0}, {5, 4, 4} };
	int n = sizeof(proc) / sizeof(proc[0]);
	findavgTime(proc, n);
	return 0;
}
```
Output<br />
<pre>
 P        BT        WT        TAT        
 1        6         7         13
 2        2         0         2
 3        8         14         22
 4        3         0         3
 5        4         2         6

Average waiting time = 4.6
Average turn around time = 9.2
</pre>
<pre>
Time Complexity: O(N)
Auxiliary Space: O(1)
</pre>
<br /><br />**Advantages:**<br />

 * Short processes are handled very quickly.<br /> 
 * The system also requires very little overhead since it only makes a decision when a process completes or a new process is added.<br /> 
 * When a new process is added the algorithm only needs to compare the currently executing process with the new process, ignoring all other processes currently waiting to execute.<br />

<br /><br />**Disadvantages:**<br />

 * Like shortest job first, it has the potential for process starvation.<br /> 
 * Long processes may be held off indefinitely if short processes are continually added.<br /> 

* [To top](#Table-of-Content)	



<br /><br /><br />
## Problem 22:
**[Program for Least Recently Used (LRU) Page Replacement algorithm](https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1)**<br />
In operating systems that use paging for memory management, `page replacement algorithm` is needed to decide **which page needs to be replaced when the new page comes in**. Whenever a new page is referred and is not present in **memory**, the **page fault occurs and Operating System replaces one of the existing pages with a newly needed page**.<br />
Given a sequence of pages in an array `pages[]` of length `N` and memory capacity `C`, find the number of page faults using `Least Recently Used (LRU) Algorithm`. <br />

>Example 1:<br />
Input: N = 9, C = 4<br />
pages = {5, 0, 1, 3, 2, 4, 1, 0, 5}<br />
Output: 8<br />
Explaination: memory allocated with 4 pages 5, 0, 1, 3: page fault = 4<br />
page number 2 is required, replaces LRU 5:<br /> 
page fault = 4+1 = 5<br />
page number 4 is required, replaces LRU 0:<br /> 
page fault = 5 + 1 = 6<br />
page number 1 is required which is already present:<br /> 
page fault = 6 + 0 = 6<br />
page number 0 is required which replaces LRU 3:<br /> 
page fault = 6 + 1 = 7<br />
page number 5 is required which replaces LRU 2:<br /> 
page fault = 7 + 1  = 8.<br />

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `pageFaults()` which takes `N`, `C` and `pages[]` as input parameters and returns _the number of page faults_.<br />

<pre>
Expected Time Complexity: O(N*C)
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1 ≤ N ≤ 1000`<br />
`1 ≤ C ≤ 100`<br />
`1 ≤ pages[i] ≤ 1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        unordered_set<int> s;
    	unordered_map<int, int> indexes;
    
    	int page_faults = 0;
    	for (int i = 0;i < N; i++){
    		if (s.size() < C){
    			if (s.find(pages[i]) == s.end()){
    				s.insert(pages[i]);
    				page_faults++;
    			}
    			indexes[pages[i]] = i;
    		}
    		else{
    			if (s.find(pages[i]) == s.end()){
    				int lru = INT_MAX, val;
    				for (auto it = s.begin();it != s.end(); it++){
    					if (indexes[*it] < lru){
    						lru = indexes[*it];
    						val = *it;
    					}
    				}
    				s.erase(val);
    				s.insert(pages[i]);
    				page_faults++;
    			}
    			indexes[pages[i]] = i;
    		}
    	}
    	return page_faults;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, c;
        cin>>n;
        int pages[n];
        for(int i = 0;i<n;i++)cin>>pages[i];
        cin>>c;
        Solution ob;
        cout<<ob.pageFaults(n, c, pages)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)




<br /><br /><br />
## Problem 23:
**[Smallest subset with sum greater than all other elements](https://www.geeksforgeeks.org/smallest-subset-sum-greater-elements/)**<br />
Given an array of `non-negative integers`. Our task is to find `minimum` number of elements such that their sum should be greater than the sum of rest of the elements of the array.<br />
**Examples :**<br />
<pre>
Input : arr[] = {3, 1, 7, 1}
Output : 1
Smallest subset is {7}. Sum of this subset is greater than all other elements {3, 1, 1}

Input : arr[] = {2, 1, 2}
Output : 2
In this example one element is not enough. 
We can pick elements with values 1, 2 or 2, 2. In any case, the minimum count is 2.
</pre>
The **Brute force approach** is to find the sum of all the possible subsets and then compare sum with the sum of remaining elements.<br />
The **Efficient Approach** is to take the largest elements. We sort values in descending order, then take elements from the largest, until we get strictly more than half of total sum of the given array.<br />
```cpp
// CPP program to find minimum number of
// elements such that their sum is greater
// than sum of remaining elements of the array.
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

// function to find minimum elements needed.
int minElements(int arr[], int n)
{
	// calculating HALF of array sum
	int halfSum = 0;
	for (int i = 0; i < n; i++)
		halfSum = halfSum + arr[i];
	halfSum = halfSum / 2;

	// sort the array in descending order.
	sort(arr, arr + n, greater<int>());

	int res = 0, curr_sum = 0;
	for (int i = 0; i < n; i++) {

		curr_sum += arr[i];
		res++;

		// current sum greater than sum
		if (curr_sum > halfSum)		
			return res;
	}
	return res;
}

// Driver function
int main()
{
	int arr[] = {3, 1, 7, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << minElements(arr, n) << endl;
	return 0;
}
```
Output:<br />
<pre>
1
</pre>
<pre>
Time Complexity : O(n Log n)
</pre>
* [To top](#Table-of-Content)




<br /><br /><br />
## Problem 24:
**[Chocolate Distribution Problem](https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1)**<br />
Given an array `A[ ]` of positive integers of size `N`, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are `M` students, the task is _to distribute chocolate packets among `M` students such that_ :<br />

 1. Each student gets **exactly** one packet.<br />
 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is **minimum**.<br />

>Example 1:<br />
Input:<br />
N = 8, M = 5<br />
A = {3, 4, 1, 9, 56, 7, 9, 12}<br />
Output: 6<br />
Explanation: The minimum difference between maximum chocolates and minimum chocolates<br /> 
is 9 - 3 = 6 by choosing following M packets : {3, 4, 9, 7, 9}.<br />

>Example 2:<br />
Input:<br />
N = 7, M = 3<br />
A = {7, 3, 2, 4, 9, 12, 56}<br />
Output: 2<br />
Explanation: The minimum difference between maximum chocolates and minimum chocolates<br />
is 4 - 2 = 2 by choosing following M packets : {3, 2, 4}.<br />

**Your Task:**<br />
You don't need to take any input or print anything. Your task is to complete the function `findMinDiff()` which takes array `A[ ]`, `N` and `M` as input parameters and returns _the minimum possible difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student_.<br />

<pre>
Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ T ≤ 100`<br />
`1 ≤ N ≤ 10^5`<br />
`1 ≤ Ai ≤ 10^9`<br />
`1 ≤ M ≤ N`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long start = 0, end = 0;
        long long mind = LONG_LONG_MAX;
        for(long long i = 0;i+m-1<n;i++){
            long long diff = a[i+m-1]-a[i];
            if(mind>diff){
                mind = diff;
                start = i;
                end = i+m-1;
            }
        }
        return a[end]-a[start];
    }   
};

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>a;
        long long x;
        for(long long i=0;i<n;i++){
            cin>>x;
            a.push_back(x);
        }
        long long m;
        cin>>m;
        Solution ob;
        cout<<ob.findMinDiff(a,n,m)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)






<br /><br /><br />
## Problem 25:
**[DEFKIN - Defense of a Kingdom](https://www.spoj.com/problems/DEFKIN/)**<br />
Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.<br />
The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.<br />
<img src = "https://user-images.githubusercontent.com/71781982/184014931-c7237dee-31ff-4601-bf97-7ea26fdfbcc9.png"><br />
Help Theodore write a program that calculates the penalty of the given position.<br />
<pre>
Input
The first line of the input file contains the number of test cases.
Each test case consists of a line with three integer numbers: w — width of the grid, 
                                                              h — height of the grid and 
							      n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).
Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).
</pre>
<pre>
Output
For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.
</pre>
**Example**<br />
<pre>
Input:
1
15 8 3
3 8
11 2
8 6
</pre>
<pre>
Output:
12
</pre>
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> x, y;
 
int main() {
    int t;
    cin >> t;
    
    int n, m, q;
    while(t--) {
        cin >> n >> m >> q;
        
        x.clear();
        x.resize(q + 2);
        y.clear();
        y.resize(q + 2);
        
        x[0] = 0;
        y[0] = 0;
        
        for(int i = 1; i <= q; i++)
            cin >> x[i] >> y[i];
        
        x[x.size() - 1] = n + 1;
        y[y.size() - 1] = m + 1;
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        int mxx = 0, mxy = 0;
        
        for(int i = 0; i < x.size() - 1; i++) {
            mxx = max(mxx, x[i+1] - x[i] - 1);
            mxy = max(mxy, y[i+1] - y[i] - 1);
        }
        
        cout << mxx * mxy << endl;
    }
    
    return 0;
}
```
* [To top](#Table-of-Content)





<br /><br /><br />
## Problem 26:
**[DIEHARD - DIE HARD dynamic-programming](https://www.spoj.com/problems/DIEHARD/)**<br />
**Problem Statement:**<br />
<img src = "https://user-images.githubusercontent.com/71781982/184014925-3d1033d4-9738-4772-a05c-673792b4b88e.png"><br />
The game is simple. You initially have `‘H’` amount of health and `‘A’` amount of armor. At any instant you can live in any of the three places - `fire`, `water` and `air`.<br /> 
After every unit time, you have to change your place of living. For example if you are currently living at `fire`, you can either step into `water` or `air`.<br />

 * If you step into `air`, your health increases by `3` and your armor increases by `2`<br />
 * If you step into `water`, your health decreases by `5` and your armor decreases by `10`<br />
 * If you step into `fire`, your health decreases by `20` and your armor increases by `5`<br />
 * If your `health` or `armor` becomes <=0, you will die instantly<br />

Find the maximum time you can survive.<br />
>**Input:**<br />
The first line consists of an integer `t`, the number of test cases. <br />
For each test case there will be two positive integers representing the initial health `H` and initial armor `A`.<br />

>**Output:**<br />
For each test case find the maximum time you can survive.<br />
**Note:** You can choose any of the `3` places during your first move.<br />

* Input Constraints: `1 <= t <= 10`<br />
`1 <= H, A <= 1000`<br />

**Example:**<br />
<pre>
Sample Input:
3
2 10
4 4
20 8
</pre>
<pre>
Sample Output:
1
1
5
</pre>
```cpp
#include<bits/stdc++.h>
using namespace std;

int dp[1010][1010];

int solve(int h, int a, int cnt,bool f)
{
    if( h<=0 || a<=0) return cnt;

    if(dp[h][a] != -1) return dp[h][a];
    if(f) dp[h][a] = max(dp[h][a], solve(h+3,a+2,cnt+1,!f));

    return dp[h][a] = max(dp[h][a], max(solve(h-5,a-10,cnt+1,!f),solve(h-20,a+5,cnt+1,!f)));
}

int main()
{   int tc;
    cin >> tc;
    int h,a;

    while(tc--){
    bool f=true;
    memset(dp,-1,sizeof dp);
    cin >> h >> a;

    cout << solve(h,a,-1,f) << endl;
}
   return 0;

}
```
* [To top](#Table-of-Content)






<br /><br /><br />
## Problem 27:
**[GERGOVIA - Wine trading in Gergovia greedy](https://www.spoj.com/problems/GERGOVIA/)**<br />
Gergovia consists of one street, and every inhabitant of the city is a wine salesman. Everyone buys wine from other inhabitants of the city. Every day each inhabitant decides how much wine he wants to buy or sell. Interestingly, **demand and supply is always the same**, so that each inhabitant gets what he wants.<br />
There is one problem, however: Transporting wine from one house to another results in work. Since all wines are equally good, the inhabitants of Gergovia don't care which persons they are doing trade with, they are only interested in selling or buying a specific amount of wine.<br />
In this problem you are asked to reconstruct the trading during one day in Gergovia. For simplicity we will assume that the houses are **built along a straight line with equal distance between adjacent houses**. Transporting one bottle of wine from one house to an adjacent house results in `one unit of work`.<br />

>**Input**<br />
The input consists of several test cases.<br />
Each test case starts with the number of inhabitants `N` `(2 ≤ N ≤ 100000)`.<br />
The following line contains `n` integers `ai` `(-1000 ≤ ai ≤ 1000)`.<br />
If `ai ≥ 0`, it means that the inhabitant living in the `ith` house wants to buy `ai` bottles of wine. If `ai < 0`, he wants to sell `-ai` bottles of wine.<br />
You may assume that the numbers `ai` sum up to `0`.<br />
The last test case is followed by a line containing `0`.<br />

>**Output**<br />
For each test case print _the minimum amount of work units needed so that every inhabitant has his demand fulfilled_.<br />

**Example**<br />
<pre>
Input:
5
5 -4 1 -3 1
6
-1000 -1000 -1000 1000 1000 1000
0
</pre>
<pre>
Output:
9
9000
</pre>
```cpp
#include<bits/stdc++.h>
using namespace std;

#define MAX 100007
#define EPS 1e-9
#define FOR(i, b, e) for(int i = b; i <= e; i++)

typedef  long long ll;

ll a[MAX];

int main(){
    int T,n,b,d,f;
    while(1){
        cin>>n;
        if(n==0)break;
        FOR(i,0,n-1)cin>>a[i];
        ll ans=0,sum=0;
        FOR(i,0,n-1){
            sum+=a[i];
            ans+=abs(sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)





<br /><br /><br />
## Problem 28:
**[Picking Up Chicks](https://www.spoj.com/problems/GCJ101BB/)**<br />
A flock of chickens are running east along a straight, narrow road. Each one is running with its own constant speed. Whenever a chick catches up to the one in front of it, it has to slow down and follow at the speed of the other chick. You are in a mobile crane behind the flock, chasing the chicks towards the barn at the end of the road. The arm of the crane allows you to pick up any chick momentarily, let the chick behind it pass underneath and place the picked up chick back down. This operation takes no time and can only be performed on a pair of chicks that are immediately next to each other, even if `3` or more chicks are in a row, one after the other.<br />
Given the initial locations `(Xi)` at time `0` and natural speeds `(Vi)` of the chicks, as well as the location of the barn `(B)`, what _is the minimum number of swaps you need to perform with your crane in order to have `at least` `K` of the `N` chicks arrive at the barn no later than time `T`_?<br />
You may think of the chicks as points moving along a line. Even if `3` or more chicks are at the same location, next to each other, picking up one of them will only let one of the other two pass through. Any swap is instantaneous, which means that you may perform multiple swaps at the same time, but each one will count as a separate swap.<br />

>**Input**<br />
The first line of the input gives the number of test cases, `C`. `C` test cases follow. Each test case starts with `4 integers` on a line -- `N`, `K`, `B` and `T`. The next line contains the `N` different integers `Xi`, in increasing order. The line after that contains the `N` integers `Vi`. All distances are in meters; all speeds are in meters per second; all times are in seconds.<br />

>**Output**<br />
For each test case, output one line containing "`Case #x: S`", where `x` is the case number (starting from 1) and `S` is the smallest number of required swaps, or the word `"IMPOSSIBLE"`.<br />

* Limits : `1 ≤ C ≤ 100`<br />
`1 ≤ B ≤ 1,000,000,000`<br />
`1 ≤ T ≤ 1,000`<br />
`0 ≤ Xi < B`<br />
`1 ≤ Vi ≤ 100`<br />
`1 ≤ N ≤ 50`<br />
`0 ≤ K ≤ N`<br />

All the `Xi's` will be **distinct** and in **increasing order**.<br />

**Example**<br />
<pre>
Input:
3
5 3 10 5
0 2 5 6 7
1 1 1 1 4
5 3 10 5
0 2 3 5 7
2 1 1 1 4
5 3 10 5
0 2 3 4 7
2 1 1 1 4
</pre>
<pre>
Output:
Case #1: 0
Case #2: 2
Case #3: IMPOSSIBLE
</pre>
```cpp
#include <iostream>
using namespace std;
int main() {  
  int t,c=0;
  cin>>t;
  while(t--){
    int n,k,b,t;
    cin>>n>>k>>b>>t;
    int x[50],v[50];
    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=0;i<n;i++)cin>>v[i];
    int positives=0,negatives=0,ans=0;
    for(int i=n-1;i>=0;i--){
      int dist=b-x[i];
      int time=(dist+v[i]-1)/v[i];
      if(time<=t)positives++,ans+=negatives;
      else negatives++;
      if(positives==k)break;
    }
    cout<<"Case #"<<++c<<": ";
    if(positives==k)cout<<ans<<'\n';
    else cout<<"IMPOSSIBLE"<<'\n';
  }
  return 0;
}
```
* [To top](#Table-of-Content)




<br /><br /><br />
## Problem 29:
**[CHOCOLA –Chocolate](https://www.spoj.com/problems/CHOCOLA/)**<br />
We are given a bar of chocolate composed of `m*n` square pieces. One should break the chocolate into single squares. Parts of the chocolate may be broken along the **vertical** and **horizontal** lines as indicated by the broken lines in the picture.<br />
A single break of a part of the chocolate along a chosen **vertical** or **horizontal** line divides that part into two smaller ones. Each break of a part of the chocolate is charged a cost expressed by a `positive` integer. This cost does not depend on the size of the part that is being broken but only depends on the line the break goes along. Let us denote the costs of breaking along consecutive `vertical lines` with `x1, x2, ..., xm-1` and along `horizontal lines` with `y1, y2, ..., yn-1`.<br />
The cost of breaking the whole bar into single squares is the `sum` of the successive breaks. One should compute the `minimal` cost of breaking the whole chocolate into single squares.<br />
<img src = "https://user-images.githubusercontent.com/71781982/184197143-30a6b9b0-06fc-4eda-b4a8-7989011a8a50.jpg"><br />
For example, if we break the chocolate presented in the picture first along the **horizontal lines**, and next each obtained part along **vertical lines** then the cost of that breaking will be `y1+y2+y3+4*(x1+x2+x3+x4+x5)`.<br />
**Task**<br />
Write a program that for each test case:<br />
Reads the numbers `x1, x2, ..., xm-1` and `y1, y2, ..., yn-1`<br />
Computes the `minimal` cost of breaking the whole chocolate into single squares, writes the result.<br />

>Input<br />
One integer in the `first` line, stating the number of test cases, followed by a blank line. There will be not more than `20` tests.<br />
For each test case, at the `first` line there are `two positive integers` `m` and `n` separated by a single space, `2 <= m,n <= 1000`. In the successive `m-1` lines there are numbers `x1, x2, ..., xm-1`, one per line, `1 <= xi <= 1000`. In the successive `n-1` lines there are numbers `y1, y2, ..., yn-1`, one per line, `1 <= yi <= 1000`.<br />
The test cases will be separated by a single blank line.<br />

>Output<br />
**For each test case :** write one integer - the **minimal** cost of breaking the whole chocolate into single squares.<br />

**Example**<br />
<pre>
Input:
1
6 4
2
1
3
1
4
4
1
2
</pre>
<pre>
Output:
42
</pre>
```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define min(a,b) (((a)<(b))?(a):(b))
typedef long long LL;
bool comp(LL a, LL b){ return a>b;}
 
LL x[1001],y[1001],dp[1001][1001];
 
int main() {
    LL i,j,m,n,t; cin>>t;
    while(t--){
        cin>>m>>n;
        m--;
        n--;
        for(i=1;i<=m;i++)cin>>x[i];
            //scanf("%lld",x+i);
        for(i=1;i<=n;i++)cin>>y[i];
            //scanf("%lld",y+i);
        sort(x+1,x+1+m,comp);
        sort(y+1,y+n+1,comp);
        dp[0][0] = 0;
        for(i=1;i<=m;i++) dp[i][0] = x[i] + dp[i-1][0];
        for(i=1;i<=n;i++) dp[0][i] = y[i] + dp[0][i-1];
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                LL t1 = dp[i-1][j] + x[i]*(j+1);
                LL t2 = dp[i][j-1] + y[j]*(i+1);
                dp[i][j] = min(t1,t2);
            }
        }
        printf("%lld\n",dp[m][n]);
    }
    return 0;
} 
```
* [To top](#Table-of-Content)






<br /><br /><br />
## Problem 30:
**[ARRANGE -Arranging Amplifiers sorting](https://www.spoj.com/problems/ARRANGE/)**<br />
Scientists at the TIFR, Mumbai, are doing some cutting edge research on the Propagation of Signals. A young researcher comes up with a method of progressively amplifying signals, as they progress along a path. The method involves the placing of Amplifiers at regular distances along the line. Each amplifier is loaded with a number `a(i)`, which is called its amplification factor. The method of amplification is simple: an amplifier which recieves a signal of strength `X`, and has `Y` loaded in it, results in a signal of strength `Y^X` `[ Y to the power X]`. In course of his research, the young scientist tries to find out, that given a set of `n` amplifiers loaded with `a(0)`, `a(1)`, `a(2)`, ...., `a(n-1)`, which particular permutation of these amplifiers, when placed at successive nodes, with the initial node given a signal of strength `1`, produces the strongest output signal.<br />
this is better illustrated by the following example : `5 6 4`<br />
`4^(5^(6^1))` is the strength of the strongest signal, which is generated by putting amplifier loaded with `6` in `first` place, `5` in `second` place and `4` in `third` place.<br />
Given a list of integers specifying the set of amplifiers at hand, you must find out the order in which they must be placed, to get the highest signal strength. In case their exist multiple permutations with same output, you should print the one which has bigger amplifiers first.<br />

>**Input**<br />
First line of input contains `T`, the number of test cases. For each test case first line contains a number `ni`, which is equal to the number of amplifiers available. Next line contains `n` integers, separated by spaces which denote the values with which the amplifiers are loaded.<br />

>**Output**<br />
Output contains `T` lines, one for each test case. Each line contains `ni` integers, denoting the order in which the amplifiers should be kept such that the result is strongest.<br />

**Example**<br />
<pre>
Input:
2
3
5 6 4
2
2 3
</pre>
<pre>
Output:
6 5 4
2 3
</pre>
* Constraints and Limits : `T ≤ 20`<br />
`Ni ≤ 10^5`<br />
Each amplifier will be loaded with a positive integer `p`, `0 < p ≤ 10^9.`<br />
No two `amplifier > 1` shall be loaded with the **same** integer.<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[100000], n, t; cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a, a+n);
        int j = 0;
        while(a[j] == 1){
            cout<<"1 ";
            j++;
        }
        if(j == n-2 && a[j] == 2 && a[j+1] == 3)cout<<"2 3"<<endl;
        else{
            for(int k=n-1;k>=j;k--)cout<<a[k]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)







<br /><br /><br />
## Problem 31:
**[K Centers Problem](https://www.geeksforgeeks.org/k-centers-problem-set-1-greedy-approximate-algorithm/)**<br />
Given `n` cities and distances between every pair of cities, select `k` cities to place warehouses (or ATMs or Cloud Server) such that the maximum distance of a city to a warehouse (or ATM or Cloud Server) is `minimized`. <br />
For example consider the following four cities, `0`, `1`, `2`, and `3`, and the distances between them, how to place `2 ATMs` among these `4 cities` so that the maximum distance of a city to an ATM is `minimized`.<br /> 
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/kcenters11.png"><br />
There is no polynomial-time solution available for this problem as the problem is a known `NP-Hard problem`. There is a polynomial-time Greedy approximate algorithm, the **greedy algorithm provides a solution that is never worse than twice the optimal solution**. The **greedy solution works only if the distances between cities follow Triangular Inequality** (`The distance between two points is always smaller than the sum of distances through a third point`).<br /> 
<pre>
The 2-Approximate Greedy Algorithm: 
	1. Choose the first center arbitrarily. 
	2. Choose remaining k-1 centers using the following criteria. 
		* Let c1, c2, c3, … ci be the already chosen centers. Choose 
		  (i+1)’th center by picking the city which is farthest from already 
		  selected centers,  
           i.e, the point p which has following value as maximum Min[dist(p, c1), dist(p, c2), dist(p, c3), …. dist(p, ci)] 
</pre>
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/KCenters.png"><br />
**Example (k = 3 in the above-shown Graph):**<br />
<pre>
1. Let the first arbitrarily picked vertex be 0. 
2. The next vertex is 1 because 1 is the farthest vertex from 0. 
3. Remaining cities are 2 and 3. Calculate their distances from already selected centers (0 and 1). 
   The greedy algorithm basically calculates the following values. 
	* Minimum of all distanced from 2 to already considered centers 
	* Min[dist(2, 0), dist(2, 1)] = Min[7, 8] = 7 
	* Minimum of all distanced from 3 to already considered centers 
	* Min[dist(3, 0), dist(3, 1)] = Min[6, 5] = 5 
	* After computing the above values, city 2 is picked as the value corresponding to 2 is maximum. 
</pre>
**Note** that the greedy algorithm doesn’t give the best solution for k = 2 as this is just an approximate algorithm with a `bound as twice optimal`.<br />
**Proof that the above greedy algorithm is 2 approximate.**<br />
<pre>
Let OPT be the maximum distance of a city from a center in the Optimal solution. 
We need to show that the maximum distance obtained from the Greedy algorithm is 2*OPT. 
The proof can be done using contradiction. 
	1. Assume that the distance from the furthest point to all centers is > 2·OPT. 
	2. This means that distances between all centers are also > 2·OPT. 
	3. We have k + 1 points with distances > 2·OPT between every pair. 
	4. Each point has a center of the optimal solution with distance <= OPT to it. 
</pre>

	1. There exists a pair of points with the same center `X` in the optimal solution (`pigeonhole principle: k optimal centers, k+1 points`) <br />
	2. The distance between them is at most `2·OPT` (`triangle inequality`) which is a contradiction. <br />
	
**Implementation:**<br />
```cpp
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

int maxindex(int* dist, int n)
{
	int mi = 0;
	for (int i = 0; i < n; i++) {
		if (dist[i] > dist[mi])
			mi = i;
	}
	return mi;
}

void selectKcities(int n, int weights[4][4], int k)
{
	int* dist = new int[n];
	vector<int> centers;
	for (int i = 0; i < n; i++) {
		dist[i] = INT_MAX;
	}

	// index of city having the
	// maximum distance to it's
	// closest center
	int max = 0;
	for (int i = 0; i < k; i++) {
		centers.push_back(max);
		for (int j = 0; j < n; j++) {
			// updating the distance
			// of the cities to their
			// closest centers
			dist[j] = min(dist[j], weights[max][j]);
		}

		// updating the index of the
		// city with the maximum
		// distance to it's closest center
		max = maxindex(dist, n);
	}

	// Printing the maximum distance
	// of a city to a center
	// that is our answer
	cout << endl << dist[max] << endl;

	// Printing the cities that
	// were chosen to be made
	// centers
	for (int i = 0; i < centers.size(); i++) {
		cout << centers[i] << " ";
	}
	cout << endl;
}

// Driver Code
int main()
{
	int n = 4;
	int weights[4][4] = { { 0, 4, 8, 5 },
			      { 4, 0, 10, 7 },
			      { 8, 10, 0, 9 },
	       		      { 5, 7, 9, 0 } };
	int k = 2;
	// Function Call
	selectKcities(n, weights, k);
}
```
Output<br />
<pre>
5
0 2 
</pre>
<pre>
Time Complexity: O(n*k), as we are using nested loops to traverse n*k times.
Auxiliary Space: O(k), as we are using extra space for the array center.
</pre>
* [To top](#Table-of-Content)






<br /><br /><br />
## Problem 32:
**[Minimum Cost of ropes](https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1)**<br />
There are given `N` ropes of different lengths, we need to connect these ropes into `one` rope. The cost to connect two ropes is equal to `sum of their lengths`. The task _is to connect the ropes with `minimum` cost_.<br />

>Example 1:<br />
Input:<br />
n = 4<br />
arr[] = {4, 3, 2, 6}<br />
Output:<br /> 
29<br />
**Explanation:**<br />
<pre>
For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can
connect the ropes in following ways. 
1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all ropes have connected. Total cost for connecting all ropes is 5 + 9 + 15 = 29. 
   This is the optimized cost for connecting ropes. Other ways of connecting ropes would always have same or more cost. 
   For example, if we connect 4 and 6 first (we get three strings of 3, 2 and 10), then connect 10 and 3 (we get two strings of 13 and 2). 
   Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.
</pre>

>Example 2:<br />
Input:<br />
n = 5<br />
arr[] = {4, 2, 7, 6, 9}<br />
Output:<br /> 
62 <br />
**Explanation:**<br />
<pre>
First, connect ropes 4 and 2, which makes the array {6,7,6,9}. Next, add ropes 6 and
6, which results in {12,7,9}. Then, add 7 and 9, which makes the array {12,16}. And
finally add these two which gives {28}.
Hence, the total cost is 6 + 12 + 16 + 28 = 62.
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Your task isto complete the function `minCost()` which takes `2` arguments and returns _the minimum cost_.<br />

<pre>
Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
</pre>

* Constraints: `1 ≤ N ≤ 100000`<br />
`1 ≤ arr[i] ≤ 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long> > pq(arr, arr + n);
        long long res = 0;
        while (pq.size() > 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            res += first + second;
            pq.push(first + second);
        }
        return res;
    }
};

int main(){
    long long t; cin>>t;
    while(t--){
        long long n; cin>>n;
        long long i, a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.minCost(a, n)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)



<br /><br /><br />
## Problem 33:
**[Find smallest number with given number of digits and sum of digits](https://practice.geeksforgeeks.org/problems/smallest-number5829/1)**<br />
The task is to find the **smallest** number with given sum of digits as `S` and number of digits as `D`.<br />

>Example 1:<br />
Input:<br />
S = 9 <br />
D = 2<br />
Output:<br />
18<br />
Explanation:<br />
18 is the smallest number possible with sum = 9 and total digits = 2.<br />
 
>Example 2:<br />
Input:<br />
S = 20<br />
D = 3<br />
Output:<br />
299<br />
Explanation:<br />
299 is the smallest number possible with sum = 20 and total digits = 3.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `smallestNumber()` which takes the two integers `S` and `D` and returns _a string which is the `smallest number` if possible, else return `"-1"`_.<br />
 
<pre>
Expected Time Complexity: O(D)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ S ≤ 100`<br />
`1 ≤ D ≤ 6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    string smallestNumber(int S, int D){
        if(S==0){
    		if(D==1) return "0";
    		else return "-1";
    	}
    	if(S>9*D)return "-1";
    	int res[D];
    	S-=1;
    	string ans="";
    	for(int i=D-1;i>0;i--){
    		if(S>9){
    			res[i]=9;
    			S-=9;
    		}
    		else {
    			res[i]=S;
    			S=0;
    		}
    	}
    	res[0]=S+1;
    	for(int i=0;i<D;i++)ans+=('0'+res[i]);
    	return ans; 
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int S, D;
        cin>>S>>D;
        Solution ob;
        cout<<ob.smallestNumber(S, D)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)






<br /><br /><br />
## Problem 34:
**[Rearrange characters in a string such that no two adjacent are same](https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1)**<br />
Given a string `S` with repeated characters. The task is to rearrange characters in a string such that **no two adjacent characters are the same**.<br />
**Note:** The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.<br />

>Example 1:<br />
Input : str = "geeksforgeeks"<br />
Output: 1<br />
Explanation: All the repeated characters of the given string can be rearranged so that no <br />
adjacent characters in the string is equal. Any correct rearrangement will show a output of 1.<br />

>Example 2:<br />
Input : str = "bbbbb"<br />
Output: 0<br />
Explanation: Repeated characters in the string cannot be rearranged such that there should not<br />
be any adjacent repeated character.<br />

**Your task :**<br />
You don't have to read input or print anything. Your task is to complete the `functionrearrangeString()` which takes the string as input and returns the modified string. If the string cannot be modified return `"-1"`.<br />
**Note:**The generatedoutput is `1` if the string is successfully rearranged and is `0` if rearranging is not possible.<br />

<pre> 
Expected Time Complexity : O(NlogN), N = length of String
Expected Auxiliary Space : O(number of english alphabets)
</pre>

* Constraints : `1 <= length of string <= 10^4`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

class Solution{
    public:
    struct Key{
        int freq;
        char ch;
        bool operator<(const Key &k) const{
            return freq < k.freq;
        }
    };
    
    string rearrangeString(string str){
        int n = str.length();
        int count[MAX_CHAR] = {0};
        for(int i = 0;i<n;i++)count[str[i]-'a']++;
        priority_queue<Key>pq;
        for(char c = 'a' ; c<='z';c++){
            if(count[c-'a'])pq.push(Key{count[c-'a'], c});
        }
        str = "";
        Key prev {-1, '#'};
        while(!pq.empty()){
            Key k = pq.top();
            pq.pop();
            str = str + k.ch;
            if(prev.freq>0)pq.push(prev);
            (k.freq)--;
            prev = k;
        }
        if(n != str.length())return "-1";
        else return str;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string str; cin>>str;
        Solution ob;
        string str1 = ob.rearrangeString(str);
        int flag = 1;
        int c[26] = {0};
        for(int i = 0;i<str.length();i++)c[str[i]-'a']+=1;
        int f = 0;
        int x = (str.length()+1)/2;
        for(int i = 0;i<26;i++){
            if(c[i]>x)f=1;
        }
        if(f){
            if(str1=="-1")cout<<0<<endl;
            else cout<<1<<endl;
        }
        else{
            int a[26] = {0};
            int b[26] = {0};
            for(int i = 0;i<str.length();i++)a[str[i]-'a']+=1;
            for(int i = 0;i<str1.length();i++)b[str1[i]-'a']+=1;
            for(int i = 0;i<26;i++){
                if(a[i]!=b[i])flag = 0;
            }
            for(int i = 0;i<str1.length();i++){
                if(i>0){
                    if(str1[i-1]==str1[i])flag = 0;
                }
            }
            if(flag == 1)cout<<"1\n";
            else cout<<"0\n";
        }
    }
    return 0;
}
```
* [To top](#Table-of-Content)



<br /><br /><br />
## Problem 35:
**[Find maximum equal sum of every three stacks](https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/)**<br />
Given `three stacks` of the positive numbers, the task is to find the possible `equal maximum sum` of the stacks with the removal of top elements allowed. Stacks are represented as an array, and the first index of the array represent the `top element` of the stack.<br />
**Examples:**<br />
<pre>
Input : stack1[] = { 3, 10}
  stack2[] = { 4, 5 }
  stack3[] = { 2, 1 }
Output : 0
Sum can only be equal after removing all elements 
from all stacks.
</pre>
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Find-maximum-sum-possible-equal-sum-of-three-stacks-2.png"><br />
The idea is to **compare** the `sum` of each stack, if they are not same, `remove` the `top` element of the stack having the `maximum` sum.<br />
Algorithm for solving this problem:<br /> 

 1. Find the `sum` of all elements of in individual stacks.<br />
 2. If the `sum` of all three stacks is the same, then this is the `maximum sum`.<br />
 3. Else `remove` the top element of the stack having the `maximum sum among three of stacks`. Repeat step 1 and step 2.<br />

The approach works `because elements are positive`. To make sum equal, we must remove some element from stack having more sum, and we can only remove from the top.<br />
Below is the implementation of this approach:<br /> 
```cpp
// C++ program to calculate maximum sum with equal
// stack sum.
#include <bits/stdc++.h>
using namespace std;

// Returns maximum possible equal sum of three stacks
// with removal of top elements allowed
int maxSum(int stack1[], int stack2[], int stack3[], int n1,
		int n2, int n3)
{
	int sum1 = 0, sum2 = 0, sum3 = 0;

	// Finding the initial sum of stack1.
	for (int i = 0; i < n1; i++)
		sum1 += stack1[i];

	// Finding the initial sum of stack2.
	for (int i = 0; i < n2; i++)
		sum2 += stack2[i];

	// Finding the initial sum of stack3.
	for (int i = 0; i < n3; i++)
		sum3 += stack3[i];

	// As given in question, first element is top
	// of stack..
	int top1 = 0, top2 = 0, top3 = 0;
	while (1) {
		// If any stack is empty
		if (top1 == n1 || top2 == n2 || top3 == n3)
			return 0;

		// If sum of all three stack are equal.
		if (sum1 == sum2 && sum2 == sum3)
			return sum1;

		// Finding the stack with maximum sum and
		// removing its top element.
		if (sum1 >= sum2 && sum1 >= sum3)
			sum1 -= stack1[top1++];
		else if (sum2 >= sum1 && sum2 >= sum3)
			sum2 -= stack2[top2++];
		else if (sum3 >= sum2 && sum3 >= sum1)
			sum3 -= stack3[top3++];
	}
}

// Driven Program
int main()
{
	int stack1[] = { 3, 2, 1, 1, 1 };
	int stack2[] = { 4, 3, 2 };
	int stack3[] = { 1, 1, 4, 1 };

	int n1 = sizeof(stack1) / sizeof(stack1[0]);
	int n2 = sizeof(stack2) / sizeof(stack2[0]);
	int n3 = sizeof(stack3) / sizeof(stack3[0]);

	cout << maxSum(stack1, stack2, stack3, n1, n2, n3) << endl;
	return 0;
}
```
Output<br />
<pre>
5
</pre>
<pre>
Time Complexity : O(n1 + n2 + n3) where n1, n2 and n3 are sizes of three stacks.
</pre>
* [To top](#Table-of-Content)
