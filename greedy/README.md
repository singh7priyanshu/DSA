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
