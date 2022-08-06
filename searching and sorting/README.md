# Love Babbar Sheet 450 - Searching & Sorting
## Problem 1:
**[Find first and last positions of an element in a sorted array](https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1)**<br />
Given a sorted array `arr` containing `n` elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element `x` in the given array.<br />

>Example 1:<br />
Input:<br />
n=9, x=5<br />
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }<br />
Output:  2 5<br />
Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. <br />
 
>Example 2:<br />
Input:<br />
n=9, x=7<br />
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }<br />
Output:  6 6 <br />

**Your Task:**<br />
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function `find()` that takes array `arr`, integer `n` and integer `x` as parameters and returns the required answer.<br />
**Note:** If the number `x` is not found in the array just return both index as `-1`.<br />

<pre>
Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).
</pre>

* Constraints: `1 ≤ N ≤ 10^7`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
vector<int>find(int a[], int n, int x);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
vector<int> find(int arr[], int n , int x )
{
    int a1=-1;
    int a2=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            a1=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]==x){
            a2=i;
            break;
        }
    }
    return {a1,a2};
}
```





<br /><br /><br />
## Problem 2:
**[Find a Fixed Point (Value equal to index) in a given array](https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1)**<br />
Given an array `Arr` of `N` positive integers. Your task is to find the elements whose value is equal to that of its index value ( Consider 1-based indexing ).<br />

>Example 1:<br />
Input: <br />
N = 5<br />
Arr[] = {15, 2, 45, 12, 7}<br />
Output: 2<br />
Explanation: Only Arr[2] = 2 exists here.<br />

>Example 2:<br />
Input: <br />
N = 1<br />
Arr[] = {1}<br />
Output: 1<br />
Explanation: Here Arr[1] = 1 exists.<br />

**Your Task:**  <br />
You don't need to read input or print anything. Your task is to complete the function `valueEqualToIndex()` which takes the array of integers `arr[]` and `n` as parameters and returns an `array of indices` where the given conditions are satified. When there is not such element exists then return an empty array of length `0`.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
</pre>

**Note:** There can be more than one element in the array which have same value as their index. You need to include every such element's index. Follows `1-based indexing` of the array.<br />

* Constraints: `1 ≤ N ≤ 10^5`<br />
`1 ≤ Arr[i] ≤ 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

	vector<int> valueEqualToIndex(int arr[], int n) {
	    // code here
	    vector<int>sol;
	    for(int i=0;i<n;i++){
	        if(arr[i] == i+1){
	            sol.push_back(i+1);
	        }
	    }
	    return sol;
	}
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        int arr[n];
        for(i =0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        auto ans = ob.valueEqualToIndex(arr,n);
        if(ans.empty()){
            cout<<"Not Found";
        }else{
            for(int x:ans){
                cout<<x<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
```





<br /><br /><br />
## Problem 3:
**[Search in a rotated sorted array](https://leetcode.com/problems/search-in-rotated-sorted-array/)**<br />
There is an integer array `nums` sorted in ascending order (with **distinct** values).<br />
Prior to being passed to your function, `nums` is **possibly rotated** at an unknown pivot index `k (1 <= k < nums.length)` such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.<br />
Given the array `nums` **after** the possible rotation and an integer `target`, return _the index of `target` if it is in `nums`, or `-1` if it is not in `nums`_.<br />
You must write an algorithm with `O(log n)` runtime complexity.<br />

>Example 1:<br />
Input: nums = [4,5,6,7,0,1,2], target = 0<br />
Output: 4<br />

>Example 2:<br />
Input: nums = [4,5,6,7,0,1,2], target = 3<br />
Output: -1<br />

>Example 3:<br />
Input: nums = [1], target = 0<br />
Output: -1<br />
 
* Constraints: `1 <= nums.length <= 5000`<br />
`-10^4 <= nums[i] <= 10^4`<br />
All values of `nums` are **unique**.<br />
`nums` is an ascending array that is possibly rotated.<br />
`-10^4 <= target <= 10^4`<br />

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n  = nums.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]== target){
                return mid;
            }
            else if(nums[low]<=nums[mid]){
                if(target>=nums[low] && target<nums[mid])high=mid-1;
                else low = mid+1;
            }else{
                if(target>nums[mid] && target <=nums[high])low= mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};
```







<br /><br /><br />
## Problem 4:
**[square root of an integer](https://practice.geeksforgeeks.org/problems/count-squares3649/1)**<br />
Consider a sample space `S` consisting of all perfect squares starting from `1`, `4`, `9` and so on. You are given a number `N`, you have to output the number of integers less than `N` in the sample space `S`.<br />

>Example 1:<br />
Input :<br />
N = 9<br />
Output:<br />
2<br />
Explanation:<br />
1 and 4 are the only Perfect Squares less than 9. So, the Output is 2.<br />

>Example 2:<br />
Input :<br />
N = 3<br />
Output:<br />
1<br />
Explanation:<br /> 
1 is the only Perfect Square less than 3. So, the Output is 1.<br />
 
**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `countSquares()` which takes an Integer `N` as input and returns the answer.<br />

<pre>
Expected Time Complexity: O(sqrt(N))
Expected Auxiliary Space: O(1)
</pre>
 
* Constraints: `1 <= N <= 10^8`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSquares(int N) {
        return sqrt(N-1);
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int N; cin>>N;
        Solution ob;
        cout<<ob.countSquares(N)<<endl;
    }
    return 0;
}
```




<br /><br /><br />
## Problem 5:
**[Maximum and minimum of an array using minimum number of comparisons](https://practice.geeksforgeeks.org/problems/middle-of-three2926/1)**<br />
Given three distinct numbers `A`, `B` and `C`. Find the number with value in middle (Try to do it with minimum comparisons).<br />

>Example 1:<br />
Input:<br />
A = 978, B = 518, C = 300<br />
Output:<br />
518<br />
Explanation:<br />
Since 518>300 and 518<978, so 518 is the middle element.<br />

>Example 2:<br />
Input:<br />
A = 162, B = 934, C = 200<br />
Output:<br />
200<br />
Exaplanation:<br />
Since 200>162 && 200<934, So, 200 is the middle element.<br />

**Your Task:**<br />
You don't need to read input or print anything.Your task is to complete the function `middle()` which takes three integers `A`,`B` and `C` as input parameters and returns the number which has middle value.<br />

<pre>
Expected Time Complexity:O(1)
Expected Auxillary Space:O(1)
</pre>

* Constraints: `1<=A,B,C<=10^9`<br />
`A`,`B`,`C` are distinct.<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int middle(int A, int B, int C){
        if(A<B)return (B<C)? B : max(A, C);
        return (A<C)? A : max(B, C);
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A, B, C)<<endl;
    }
    return 0;
}
```





<br /><br /><br />
## Problem 6:
**[Optimum location of point to minimize total distance](https://www.geeksforgeeks.org/optimum-location-point-minimize-total-distance/)**<br />
Given a set of points as and a line as `ax+by+c = 0`. We need to find a point on given line for which sum of distances from given set of points is minimum.<br /> 
**Example:**<br /> 
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/Optimum-location-of-point-to-minimize-total-distance.jpg"><br />
<pre>
In above figure optimum location of point of x - y - 3 = 0 line 
is (2, -1), whose total distance with other points is 20.77, 
which is minimum obtainable total distance.
</pre>
If we take one point on given line at infinite distance then total distance cost will be infinite, now when we move this point on line towards given points the total distance cost starts decreasing and after some time, it again starts increasing which reached to infinite on the other infinite end of line so distance cost curve looks like a `U-curve` and we have to find the bottom value of this `U-curve`.<br />
As `U-curve` is not monotonically increasing or decreasing we can’t use `binary search` for finding bottom most point, here we will use ternary search for finding bottom most point, ternary search skips one third of search space at each iteration.<br />
So solution proceeds as follows, we start with low and high initialized as some smallest and largest values respectively, then we start iteration, in each iteration we calculate two `mids`, `mid1` and `mid2`, which represent `1/3rd` and `2/3rd` position in search space, we calculate total distance of all points with `mid1` and `mid2` and update low or high by comparing these distance cost, this iteration continues until `low` and `high` become approximately equal.<br />
```cpp
// C/C++ program to find optimum location and total cost
#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x) * (x))
#define EPS 1e-6
#define N 5

// structure defining a point
struct point {
	int x, y;
	point() {}
	point(int x, int y)
		: x(x)
		, y(y)
	{	}
};

// structure defining a line of ax + by + c = 0 form
struct line {
	int a, b, c;
	line(int a, int b, int c)
		: a(a)
		, b(b)
		, c(c)
	{
	}
};

// method to get distance of point (x, y) from point p
double dist(double x, double y, point p)
{
	return sqrt(sq(x - p.x) + sq(y - p.y));
}

/* Utility method to compute total distance all points
	when choose point on given line has x-coordinate
	value as X */
double compute(point p[], int n, line l, double X)
{
	double res = 0;

	// calculating Y of chosen point by line equation
	double Y = -1 * (l.c + l.a * X) / l.b;
	for (int i = 0; i < n; i++)
		res += dist(X, Y, p[i]);

	return res;
}

// Utility method to find minimum total distance
double findOptimumCostUtil(point p[], int n, line l)
{
	double low = -1e6;
	double high = 1e6;

	// loop until difference between low and high
	// become less than EPS
	while ((high - low) > EPS) {
		// mid1 and mid2 are representative x co-ordiantes
		// of search space
		double mid1 = low + (high - low) / 3;
		double mid2 = high - (high - low) / 3;

		//
		double dist1 = compute(p, n, l, mid1);
		double dist2 = compute(p, n, l, mid2);

		// if mid2 point gives more total distance,
		// skip third part
		if (dist1 < dist2)
			high = mid2;

		// if mid1 point gives more total distance,
		// skip first part
		else
			low = mid1;
	}

	// compute optimum distance cost by sending average
	// of low and high as X
	return compute(p, n, l, (low + high) / 2);
}

// method to find optimum cost
double findOptimumCost(int points[N][2], line l)
{
	point p[N];

	// converting 2D array input to point array
	for (int i = 0; i < N; i++)
		p[i] = point(points[i][0], points[i][1]);

	return findOptimumCostUtil(p, N, l);
}

// Driver code to test above method
int main()
{
	line l(1, -1, -3);
	int points[N][2] = {
		{ -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }
	};
	cout << findOptimumCost(points, l) << endl;
	return 0;
}
```
Output<br />
<pre>
20.7652
</pre>
<pre>
Time Complexity: O(n^2) 
Auxiliary Space: O(n)
</pre>








<br /><br /><br />
## Problem 7:
**[Find the repeating and the missing](https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1)**<br />
Given an unsorted array `Arr` of size `N` of positive integers. One number `'A'` from `set {1, 2, …N}` is missing and one number `'B'` occurs twice in array. Find these two numbers.<br />

>Example 1:<br />
Input:<br />
N = 2<br />
Arr[] = {2, 2}<br />
Output: 2 1<br />
Explanation: Repeating number is 2 and smallest positive missing number is 1.<br />

>Example 2:<br />
Input:<br />
N = 3<br />
Arr[] = {1, 3, 3}<br />
Output: 3 2<br />
Explanation: Repeating number is 3 and smallest positive missing number is 2.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `findTwoElement()` which takes the array of integers `arr` and `n` as parameters and returns an `array of integers` of size `2` denoting the answer ( The first index contains `B` and second index contains `A`.)<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ N ≤ 10^5`<br />
`1 ≤ Arr[i] ≤ N`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *ans = new int[2];
        for(int i = 0;i<n;i++){
            if(arr[abs(arr[i])-1]>0)arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
            else ans[0] = abs(arr[i]);
        }
        for(int i = 0;i<n;i++){
            if(arr[i]>0)ans[1] = i+1;
        }
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
```






<br /><br /><br />
## Problem 8:
**[Majority Element](https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1)**<br />
Given an array `A` of `N` elements. Find the majority element in the array. A majority element in an array `A` of size `N` is an element that appears `more than N/2` times in the array.<br />
 
>Example 1:<br />
Input:<br />
N = 3 <br />
A[] = {1,2,3}<br /> 
Output:<br />
-1<br />
Explanation:<br />
Since, each element in {1,2,3} appears only once so there is no majority element.<br />

>Example 2:<br />
Input:<br />
N = 5 <br />
A[] = {3,1,3,3,2} <br />
Output:<br />
3<br />
Explanation:<br />
Since, 3 is present more than N/2 times, so it is the majority element.<br />

**Your Task:**<br />
The task is to complete the function `majorityElement()` which returns the majority element in the `array`. If no majority exists, return `-1`.<br />
 
<pre>
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
</pre>

* Constraints: `1 ≤ N ≤ 10^7`<br />
`0 ≤ Ai ≤ 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int majorityElement(int a[], int size){
        int cand = findCandidate(a, size);
        if(isMajority(a, size, cand))return cand;
        else return -1;
    }
    
    bool isMajority(int a[], int size, int cand){
        int count = 0;
        for(int i = 0;i<size;i++){
            if(a[i]==cand)count++;
        }
        if(count>size/2)return 1;
        else return 0;
    }
    
    int findCandidate(int a[], int size){
        int maj_index = 0, count = 1;
        for(int i = 0;i<size;i++){
            if(a[maj_index]==a[i])count++;
            else count--;
            if(count == 0){
                maj_index = i;
                count = 1;
            }
        }
        return a[maj_index];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.majorityElement(arr, n)<<endl;
    }
    return 0;
}
```





<br /><br /><br />
## Problem 9:
**[Searching in an array where adjacent differ by at most k](https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/)**<br />
A step array is an `array of integers` where each element has a difference of at most `k` with its neighbor. Given a key `x`, we need to find the index value of `x` if multiple-element exist to return the first occurrence of the key.<br />
**Examples:**<br />
<pre>
Input : arr[] = {4, 5, 6, 7, 6}
           k = 1
           x = 6
Output : 2
The first index of 6 is 2.

Input : arr[] = {20, 40, 50, 70, 70, 60}  
          k = 20
          x = 60
Output : 5
The index of 60 is 5
</pre>
A Simple Approach is to traverse the given array one by one and compare every element with the given element `‘x’`. If matches, then return `index`.<br />
The above solution can be Optimized using the fact that the difference between all adjacent elements is at most `k`. The idea is to start comparing from the `leftmost element` and find the `difference` between the `current array element` and `x`. Let this difference be `‘diff’`. From the given property of the array, we always know that `x` must be at least `‘diff/k’` away, so instead of searching one by one, we jump `‘diff/k’`.<br /> 
Below is the implementation of the above idea.<br />
```cpp
// C++ program to search an element in an array
// where difference between adjacent elements is atmost k
#include<bits/stdc++.h>
using namespace std;

// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
	// Traverse the given array starting from
	// leftmost element
	int i = 0;
	while (i < n)
	{
		// If x is found at index i
		if (arr[i] == x)
			return i;

		// Jump the difference between current
		// array element and x divided by k
		// We use max here to make sure that i
		// moves at-least one step ahead.
		i = i + max(1, abs(arr[i]-x)/k);
	}

	cout << "number is not present!";
	return -1;
}

// Driver program to test above function
int main()
{
	int arr[] = {2, 4, 5, 7, 7, 6};
	int x = 6;
	int k = 2;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Element " << x << " is present at index " << search(arr, n, x, k);
	return 0;
}
```
Output:<br />
<pre>
Element 6 is present at index 5
</pre>
<pre>
Time Complexity: O(n)
Auxiliary Space: O(1)
</pre>












<br /><br /><br />
## Problem 10:
**[find a pair with a given difference](https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1)**<br />
Given an array `Arr[]` of size `L` and a number `N`, you need to write a program to find if there exists a pair of elements in the array whose difference is `N`.<br />

>Example 1:<br />
Input:<br />
L = 6, N = 78<br />
arr[] = {5, 20, 3, 2, 5, 80}<br />
Output: 1<br />
Explanation: (2, 80) have difference of 78.<br />

>Example 2:<br />
Input:<br />
L = 5, N = 45<br />
arr[] = {90, 70, 20, 80, 50}<br />
Output: -1<br />
Explanation: There is no pair with difference of 45.<br />

**Your Task:**<br />
You need not take input or print anything. Your task is to complete the function `findPair()` which takes array `arr`, size of the array `L` and `N` as input parameters and returns `True` if required pair exists, else return `False`.<br />

<pre>
Expected Time Complexity: O(L* Log(L)).
Expected Auxiliary Space: O(1).
</pre>

* Constraints: `1<=L<=10^4` <br />
`1<=Arr[i]<=10^5` <br />
`0<=N<=10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n);
int main(){
    int t; cin>>t;
    while(t--){
        int l, n;
        cin>>l>>n;
        int arr[l];
        for(int i = 0;i<l;l++)cin>>arr[i];
        if(findPair(arr, l, n))cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}

bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    int i = 0, j = 1;
    while(i<size && j<size){
        if(i != j && arr[j]-arr[i] == n)return true;
        else if(arr[j]-arr[i] < n)j++;
        else i++;
    }
    return false;
}
```





<br /><br /><br />
## Problem 11:
**[find four elements that sum to a given value](https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1)**<br />
Given an array of `integers` and another `number`. Find all the unique quadruple from the given array that sums up to the given number.<br />

>Example 1:<br />
Input:<br />
N = 5, K = 3<br />
A[] = {0,0,2,1,1}<br />
Output: 0 0 1 2 $<br />
Explanation: Sum of 0, 0, 1, 2 is equal to K.<br />

>Example 2:<br />
Input:<br />
N = 7, K = 23<br />
A[] = {10,2,3,4,5,7,8}<br />
Output: 2 3 8 10 $2 4 7 10 $3 5 7 8 $<br />
Explanation: Sum of 2, 3, 8, 10 = 23, sum of 2, 4, 7, 10 = 23 and sum of 3, 5, 7, 8 = 23.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `fourSum()` which takes the array `arr[]` and the integer `k` as its input and returns an array containing all the quadruples in a `lexicographical manner`. Also note that all the quadruples should be internally sorted, ie for any quadruple `[q1, q2, q3, q4]` the following should follow: `q1 <= q2 <= q3 <= q4`.  (In the output each quadruple is separate by `$`. The printing is done by the driver's code)<br />

<pre>
Expected Time Complexity: O(N^3).
Expected Auxiliary Space: O(N^2).
</pre>

* Constraints: `1 <= N <= 100`<br />
`-1000 <= K <= 1000`<br />
`-100 <= A[] <= 100`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        if(arr.size() < 4)return{};
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        for(int i = 0;i<arr.size()-3; i++){
            if(arr[i] > 0 && arr[i]>k)break;
            if(i>0 && arr[i] == arr[i-1])continue;
            for(int j = i+1;j<arr.size()-2;j++){
                if(j>i+1 && arr[j] == arr[j-1])continue;
                int left = j+1;
                int right = arr.size()-1;
                while(left<right){
                    int old_l = left;
                    int old_r = right;
                    int sum = arr[i]+arr[j]+arr[left]+arr[right];
                    if(sum == k){
                        ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                        while(left<right && arr[left] == arr[old_l])left++;
                        while(left<right && arr[right] == arr[old_r])right--;
                    }
                    else if(sum > k)right--;
                    else left++;
                }
            }
        }
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, k, i;
        cin>>n>>k;
        vector<int>a(n);
        for(i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        vector<vector<int>>ans = ob.fourSum(a, k);
        for(auto &v : ans){
            for(int &u : v)cout<<u<<" ";
            cout<<"$"<<endl;
        }
        if(ans.empty())cout<<"-1"<<endl;
    }
    return 0;
}
```




<br /><br /><br />
## Problem 12:
**[maximum sum such that no 2 elements are adjacent](https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1)**<br />
Stickler the thief wants to loot money from a society having `n` houses in a single line. He is a weird person and follows a certain rule when looting the houses.<br /> 
According to the rule, he will never loot `two consecutive` houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has `a[i]` amount of money present in it.<br />

>Example 1:<br />
Input:<br />
n = 6<br />
a[] = {5,5,10,100,10,5}<br />
Output: 110<br />
Explanation: 5+100+5=110<br />

>Example 2:<br />
Input:<br />
n = 3<br />
a[] = {1,2,3}<br />
Output: 4<br />
Explanation: 1+3=4<br />

**Your Task:**<br />
Complete the `functionFindMaxSum()` which takes an array `arr[]` and `n` as input which returns the maximum money he can get following the rules.<br />

<pre>
Expected Time Complexity:O(N).
Expected Space Complexity:O(N).
</pre>

* Constraints: `1 ≤ n ≤ 10^4`<br />
`1 ≤ a[i] ≤ 10^4`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution{
    public:
    int FindMaxSum(int arr[], int n){
        int incl_curr = arr[0], excl_curr = 0, incl_prev = incl_curr, excl_prev =excl_curr;
        for(int i = 1;i<n;i++){
            excl_curr = max(incl_prev, excl_prev);
            incl_curr = excl_prev + arr[i];
            excl_prev = excl_curr;
            incl_prev = incl_curr;
        }
        return max(excl_curr, incl_curr);
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.FindMaxSum(a, n)<<endl;
    }
    return 0;
}
```




<br /><br /><br />
## Problem 13:
**[Count triplet with sum smaller than a given value](https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1)**<br />
Given an array `arr[]` of distinct integers of size `N` and a value `sum`, the task is to find the count of triplets `(i, j, k)`, having `(i<j<k)` with the sum of `(arr[i] + arr[j] + arr[k])` smaller than the given value `sum`.<br />

>Example 1:<br />
Input: N = 4, sum = 2<br />
arr[] = {-2, 0, 1, 3}<br />
Output:  2<br />
Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3).<br /> 
 
>Example 2:<br />
Input: N = 5, sum = 12<br />
arr[] = {5, 1, 3, 4, 7}<br />
Output: 4<br />
Explanation: Below are triplets with sum less than 12 (1, 3, 4), (1, 3, 5), (1, 3, 7) and (1, 4, 5).<br />

**Your Task:**<br />
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function `countTriplets()` that take array `arr[]`, integer `N`  and integer `sum` as parameters and returns the count of triplets.<br />

<pre>
Expected Time Complexity: O(N^2).
Expected Auxiliary Space: O(1).
</pre>

* Constraints: `3 ≤ N ≤ 10^3`<br />
`-10^3 ≤ arr[i] ≤ 10^3`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
	long long countTriplets(long long arr[], int n, long long sum){
	    sort(arr,arr+n);
	    long long ans = 0;
	    for(int i = 0;i<n-2;i++){
	        int j = i+1, k=n-1;
	        while(j<k){
	            if(arr[i]+arr[j]+arr[k] >= sum)k--;
	            else {
	                ans += (k-j);
	                j++;
	            }
	        }
	    }
	    return ans;
	}
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; long long sum;
        long long arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.countTriplets(arr, n, sum);
        cout<<endl;
    }
    return 0;
}
```






<br /><br /><br />
## Problem 14:
**[merge 2 sorted arrays without using extra space](https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1)**<br />
Given two sorted arrays `arr1[]` and `arr2[]` of sizes `n` and `m` in non-decreasing order. Merge them in sorted order `without` using any `extra space`. Modify `arr1` so that it contains the first `N` elements and modify `arr2` so that it contains the last `M` elements.<br />
 
>Example 1:<br />
Input: <br />
n = 4, arr1[] = [1 3 5 7]<br /> 
m = 5, arr2[] = [0 2 6 8 9]<br />
Output: <br />
arr1[] = [0 1 2 3]<br />
arr2[] = [5 6 7 8 9]<br />
Explanation: <br />
After merging the two non-decreasing arrays, we get, 0 1 2 3 5 6 7 8 9.<br />

>Example 2:<br />
Input: <br />
n = 2, arr1[] = [10, 12]<br /> 
m = 3, arr2[] = [5 18 20]<br />
Output: <br />
arr1[] = [5 10]<br />
arr2[] = [12 18 20]<br />
Explanation:<br />
After merging two sorted arrays we get 5 10 12 18 20.<br />

**Your Task:**<br />
You don't need to read input or print anything. You only need to complete the function `merge()` that takes `arr1`, `arr2`, `n` and `m` as input parameters and modifies them in-place so that they look like the sorted merged array when concatenated.<br />
 
<pre>
Expected Time Complexity:  O((n+m) log(n+m))
Expected Auxilliary Space: O(1)
</pre> 

* Constraints: `1 <= n, m <= 5*10^4`<br />
`0 <= arr1i, arr2i <= 10^7`<br />

```cpp
#include<bits/stdc++.h>
	using namespace std;
	
	class Solution{
	public:
	int nextGap(int gap){
		if(gap<=1)
			return 0;
		return (gap/2)+(gap%2);
	}
	void merge(int arr1[], int arr2[], int n, int m){
		int i, j, gap = n+m;
		for(gap = nextGap(gap); gap>0; gap=nextGap(gap)){
			// comparing elements in the first array itself with difference in
			// index equal to the value of the gap.
			for(i = 0; i + gap < n; i++)
				// if element at ith index is greater than element at
				// (i+gap)th index, we swap them.
				if(arr1[i]>arr1[i+gap])
					swap(arr1[i],arr1[i+gap]);
			// now comparing elements in both arrays with help of two pointers.
			// the loop stops whenever any pointer exceeds the size of its array.
			for(j = gap > n? gap-n : 0 ; i < n&&j < m; i++, j++)
				// if element in the first array is greater than element in
				// second array, we swap them.
				if(arr1[i] > arr2[j])
					swap(arr1[i], arr2[j]);
			if(j<m){
				// at last, comparing elements in the second array itself with 
				// difference in index equal to the value of the gap.
				for(j = 0 ; j+gap < m ; j++)
					// if element at jth index is greater than element at
					// (j+gap)th index, we swap them.
					if(arr2[j]>arr2[j+gap])
						swap(arr2[j],arr2[j+gap]);
				}
			}
		}
	};
	
	int main(){
		int t;
		cin>>t;
		while(t--){
			int n, m, i;
			cin>>n>>m;
			int arr1[n], arr2[m];
			for(int i=0;i<n;i++){
				cin>>arr1[i];
			}
			for(int j=0;j<m;j++){
				cin>>arr2[j];
			}
			Solution ob;
			ob.merge(arr1, arr2, n, m);
			for(i=0;i<n;i++){
				cout<<arr1[i]<<" ";
			}
			for(i=0;i<m;i++){
				cout<<arr2[i]<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
  ```






<br /><br /><br />
## Problem 15:
**[print all subarrays with 0 sum](https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1)**<br />
You are given an array `arr[]` of size `n`. Find the total count of sub-arrays having their sum equal to `0`.<br />

>Example 1:<br />
Input:<br />
n = 6<br />
arr[] = {0,0,5,5,0,0}<br />
Output: 6<br />
Explanation: The 6 subarrays are [0], [0], [0], [0], [0,0], and [0,0].<br />

>Example 2:<br />
Input:<br />
n = 10<br />
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}<br />
Output: 4<br />
Explanation: The 4 subarrays are [-1 -3 4] [-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]<br />

**Your Task:**<br />
You don't need to read input or print anything. Complete the function `findSubarray()` that takes the array `arr` and its size `n` as input parameters and returns the total number of sub-arrays with 0 sum.<br />
 
<pre>
Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)
</pre>

* Constraints: `1<= n <= 10^7`<br />
`-10^10 <= arri <= 10^10`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

class Solution{
    public:
    ll findSubarray(vector<ll> arr, int n ) {
        ll sum = 0, counter = 0;
        unordered_map<ll, ll>mp;
        for(int i = 0;i<n;i++){
            sum+=arr[i];
            if(sum==0)counter++;
            if(mp.count(sum)!= 0)counter+=mp[sum];
            mp[sum]++;
        }
        return counter;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll>arr(n, 0);
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.findSubarray(arr, n)<<endl;
    }
    return 0;
}
/*
map_name.count(key k)
Parameters: The function accepts a mandatory parameter k which specifies the key 
to be searched in the map container.
Return Value: The function returns the number of times the key K is present in 
the map container. It returns 1 if the key is present in the container as the map 
only contains a unique key. It returns 0 if the key is not present in the map container.
*/
```





<br /><br /><br />
## Problem 16:
**[Product array Puzzle](https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1)**<br />
Given an array `nums[]` of size `n`, construct a `Product Array P` (of same size `n`) such that `P[i]` is equal to the product of all the elements of nums except `nums[i]`.<br />

>Example 1:<br />
Input:<br />
n = 5<br />
nums[] = {10, 3, 5, 6, 2}<br />
Output:<br />
180 600 360 300 900<br />
Explanation: <br />
For i=0, P[i] = 3*5*6*2 = 180.<br />
For i=1, P[i] = 10*5*6*2 = 600.<br />
For i=2, P[i] = 10*3*6*2 = 360.<br />
For i=3, P[i] = 10*3*5*2 = 300.<br />
For i=4, P[i] = 10*3*5*6 = 900.<br />

>Example 2:<br />
Input:<br />
n = 2<br />
nums[] = {12,0}<br />
Output:<br />
0 12<br />

**Your Task:**<br />
You do not have to read input. Your task is to complete the function `productExceptSelf()` that takes array `nums[]` and `n` as input parameters and returns a `list` of `n` integers denoting the product array `P`. If the array has only one element the returned list should should contains one value i.e `{1}`<br />
Note: Try to solve this problem without using the division operation.<br />
 
<pre>
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
</pre> 

* Constraints: `1 <= n <= 1000`<br />
`0 <= numsi <= 200`<br />
`Array` may contain duplicates.<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        //location of memory for product array and intialise it by 1;
        vector<long long int>vec(n, 1ll);
        if(n==1)return vec;
        long long temp = 1ll;
        for(int i = 0;i<n;i++){
            vec[i]*=temp;
            temp*=nums[i];
        }
        temp = 1ll;
        for(int i = n-1;i>=0;i--){
            vec[i]*=temp;
            temp*=nums[i];
        }
        return vec;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long int>arr(n),vec(n);
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        vec = ob.productExceptSelf(arr, n);
        for(int i = 0;i<n;i++)cout<<vec[i]<<" ";
        cout<<endl;
    }
    return 0;
}
```






<br /><br /><br />
## Problem 17:
**[Sort array according to count of set bits](https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1)**<br />
Given an `array` of integers, sort the `array` (in descending order) according to count of `set bits` in binary representation of array elements.<br />
**Note:** For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a `stable sort`.<br />
 
>Example 1:<br />
Input: <br />
arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};<br />
Output:<br />
15 7 5 3 9 6 2 4 32<br />
Explanation:<br />
The integers in their binary representation are:<br />
15 - 1111<br />
7  - 0111<br />
5  - 0101<br />
3  - 0011<br />
9  - 1001<br />
6  - 0110<br />
2  - 0010<br />
4  - 0100<br />
32 - 10000<br />
hence the non-increasing sorted order is: {15}, {7}, {5, 3, 9, 6}, {2, 4, 32}<br />
 
>Example 2:<br />
Input: <br />
arr[] = {1, 2, 3, 4, 5, 6};<br />
Output: <br />
3 5 6 1 2 4<br />
Explanation:<br />
3  - 0011<br />
5  - 0101<br />
6  - 0110<br />
1  - 0001<br />
2  - 0010<br />
4  - 0100<br />
hence the non-increasing sorted order is {3, 5, 6}, {1, 2, 4}<br />

**Your Task:**<br />
You don't need to print anything, printing is done by the driver code itself. You just need to complete the function `sortBySetBitCount()` which takes the array `arr[]` and its size `N` as inputs and sort the array `arr[]` inplace. Use of `extra space` is prohibited.<br />
 
<pre>
Expected Time Complexity: O(N.log(N))
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ N ≤ 10^5`<br />
`1 ≤ A[i] ≤ 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void sortBySetBitCount(int arr[], int n){
        stable_sort(arr, arr+n, cmp);
    }
    static int cmp(int a, int b){
        int count1 = __builtin_popcount(a);
        int count2 = __builtin_popcount(b);
        if(count1<=count2)return false;
        return true;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for(int i = 0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}

stable_sort() is used to sort the elements in the range [first, last) 
in ascending order. It is like std::sort, but stable_sort() keeps the 
relative order of elements with equivalent values. It comes under the 
<algorithm> header file.
It is O(n*log^2(n)). 
If additional memory linearly proportional to length is not 
available. If its available then O(n*log(n)).
Syntax:
template< class RandomIterator>
void stable_sort( RandomIterator first, RandomIterator last );
or
template< class RandomIterator, class Compare>
void stable_sort( RandomIterator first, RandomIterator last, Compare comp );
Parameters:
first:  iterator pointing to the first element in the range.
last:  iterator pointing to the past last element in the range.
comp: predicate function that accepts two arguments and returns true if the 
 two arguments are in order and false otherwise.
 
 
Like sort(), stable_sort() takes a third parameter that is used to specify 
the order in which elements are to be sorted. We can pass “greater()” function 
to sort in decreasing order. This function does comparison in a way that puts 
greater element before. 
Syntax:
// arr is the array and n is the size
stable_sort(arr, arr + n, greater<int>());  
```






<br /><br /><br />
## Problem 18:
**[minimum no. of swaps required to sort the array](https://practice.geeksforgeeks.org/problems/minimum-swaps/1)**<br />
Given an array of `n` distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.<br />

>Example 1:<br />
Input:<br />
nums = {2, 8, 5, 4}<br />
Output:<br />
1<br />
Explaination: swap 8 with 4.<br />

>Example 2:<br />
Input:<br />
nums = {10, 19, 6, 3, 5}<br />
Output:<br />
2<br />
Explaination: swap 10 with 3 and swap 19 with 5.<br />

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `minSwaps()` which takes the `nums` as input parameter and returns an `integer` denoting the **minimum** number of swaps required to sort the array. If the array is already sorted, return `0`. <br />

<pre>
Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)
</pre>

* Constraints: `1 ≤ n ≤ 10^5`<br />
`1 ≤ numsi ≤ 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
	int minSwaps(vector<int>&nums){
	    int n = nums.size();
	    vector<pair<int, int>>cur(n);
	    for(int i = 0;i<n;i++){
	        cur[i].first = nums[i];
	        cur[i].second = i;
	    }
	    sort(cur.begin(), cur.end());
	    vector<bool>vis(n, false);
	    int ans = 0;
	    for(int i = 0;i<n;i++){
	        if(vis[i] || cur[i].second == i)continue;
	        int cycle_size = 0;
	        int j = i;
	        while(!vis[j]){
	            vis[j] = true;
	            j = cur[j].second;
	            cycle_size++;
	        }
	        ans += (cycle_size>1)? cycle_size-1 : 0;
	    }
	    return ans;
	}
};

int main(){
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int>nums(n);
        for(int i = 0;i<n;i++)cin>>nums[i];
        Solution ob;
        int ans = ob.minSwaps(nums);
        cout<<ans<<endl;
    }
    return 0;
}

// C++ program to demonstrate sorting in
// vector of pair according to 1st element
// of pair
#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}
  
int main(){
	vector< pair <int,int> > vect;
	int arr[] = {10, 20, 5, 40 };
	int arr1[] = {30, 60, 20, 50};
	int n = sizeof(arr)/sizeof(arr[0]);
	for (int i=0; i<n; i++)vect.push_back( make_pair(arr[i],arr1[i]) );
	cout << "The vector before sort operation is:\n" ;
	for (int i=0; i<n; i++)cout << vect[i].first << " "<< vect[i].second << endl;
		OUTPUT
		The vector before applying sort operation is:
			10 30
			20 60
			5 20
			40 50
	sort(vect.begin(), vect.end());
	cout << "The vector after sort operation is:\n" ;
	for (int i=0; i<n; i++)cout << vect[i].first << " "<< vect[i].second << endl;
		OUTPUT
		The vector after applying sort operation is:
			5 20
			10 30
			20 60	
			40 50
	sort(vect.begin(), vect.end(), sortbysec);
	cout << "The vector after sort operation is:\n" ;
    	for (int i=0; i<n; i++)cout << vect[i].first << " "<< vect[i].second << endl;
    		OUTPUT
		The vector after applying sort operation is:
			5 20
			10 30
			40 50	
			20 60
	return 0;
}
```







<br /><br /><br />
## Problem 19:
**[Bishu and Soldiers](https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/)**<br />
Bishu went to fight for Coding Club. There were `N` soldiers with various powers. 
There will be `Q` rounds to fight and in each round, Bishu's power will be varied. 
With power `M`, Bishu can kill all the soldiers whose power is less than or equal to `M(<=M)`. 
After each round, All the soldiers who are dead in the previous round will reborn. 
Such that in each round there will be `N` soldiers to fight. As Bishu is weak 
in mathematics, help him to count the number of soldiers that he can kill in 
each round and the total sum of their powers.<br />
**INPUT:**<br />
The first line of the input contains `N`, the number of soldiers.<br />
The second line contains an array of `N` numbers denoting the power of each soldier<br />
This third line contains `Q`, which denotes the number of rounds.<br />
`Q` lines follow, each line having one number denoting the power of Bishu.<br />
**OUTPUT:**<br />
For each round, the output should be an array of `two` numbers. 
The first number should be the number of soldiers that Bishu can beat, 
and the second number denotes the cumulative strength of all the soldiers that Bishu can beat.<br />

* CONSTRAINTS: `1<=N<=10000`<br />
`1<=power of each soldier<=100`<br />
`1<=Q<=10000`<br />
`1<=power of bishu<=100`<br />
<pre>
Sample Input
7
1 2 3 4 5 6 7
3
3
10
2
</pre>
<pre>
Sample Output
3 6
7 28
2 3
</pre>
<pre>
Time Limit: 1
Memory Limit: 256
Source Limit:
</pre>
**Explanation**<br />
There are 7 soldiers, each with the indicated power.<br />
There are 3 rounds.<br />
In the first round, Bishu's power is 3, which is greater than 3 soldiers, with the cumulative power of 6. Hence, the answer is 3 6<br />
Similarly for the next round.<br />

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vc vector<char>
#define xag ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int p; int q;cin>>q;
    while(q--){
        int cs=0;
        cin>>p;
        int x=upper_bound(a,a+n,p)-a;
        for(int i=0;i<x;i++)cs+=a[i];
        cout<<x<<" "<<cs<<endl;
    }
    return 0;
}

/*
mechanism of upper_bound function.
Vector contains : 10 20 30 40 50
upper_bound for element 35(here as p) is at position : 3
upper_bound for element 45(here as p) is at position : 4
*/
```



<br /><br /><br />
## Problem 20:
**[Rasta and Kheshtak](https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/rasta-and-kheshtak/)**<br />
Rasta is a big fan of Kheshtaks. A Kheshtak is a rectangle that in each of 
it cells there is an integer.
Today rasta came up with an interesting problem, `Biggest Common Subsquare (BCS)`. 
A Kheshtak is called a Square if the number of its `columns` is equal to the number 
of its `rows`. A Square `S` is called a subsqaue of a Kheshtak `A` if and only if we 
can turn `A` to `S` by deleting some of its rows and some of its columns (maybe none).
He gives you two Kheshtaks, `A` and `B` (`A` one is `n × m` and `B` is `x × y`).<br />

**Input format**<br />
The first line of input contains `n` and `m`.<br />
Then you are given `A` (`n` lines, in each line there are `m` space separated integers).<br />
After that you are given `x` and `y`.<br />
Then you are given `B` (`x` lines, in each line there are `y` space separated integers).<br />
`1 ≤ n, m, x, y ≤ 700` and all numbers in `A` and `B` are integers in the interval `[1, 1000]`.<br />

**Output format**<br />
Print the size of `BCS` of `A` and `B` in a single line (size of a Square is number of its rows).<br />
<pre>
Sample Input
3 3
1 2 0
1 2 1
1 2 3
3 3
0 1 2
1 1 2
3 1 2
</pre>
<pre>
Sample Output
2
</pre>
<pre>
Time Limit: 2
Memory Limit: 256
</pre>
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define double long double
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;
template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
const int maxn = 710;
int a[2][maxn][maxn];
int n[2], m[2];
int h[2][maxn][maxn], H[2][maxn][maxn];
int p = 29 * 91, pw[maxn];
int p2 = 701, pw2[maxn];
inline void init(int x){
    For(i,0,n[x]){
        int cur = 0;
        For(j,0,m[x]){
            cur = (cur * 1LL * p);
            cur = (cur + a[x][i][j]);
            h[x][i][j] = cur;
        }
    }
}
inline int hashrow(int x,int row,int l,int r){
    int ans = h[x][row][r];
    if(l){
        int X = (1LL * pw[r - l + 1] * h[x][row][l-1]);
        ans = (ans - X);
    }
    return ans;
}
inline int hashcol(int x,int col,int l,int r){
    int ans = H[x][col][r];
    if(l){
        int X = (1LL * pw2[r - l + 1] * H[x][col][l-1]);
        ans = (ans - X);
    }
    return ans;
}
inline bool check(int s){
    if(!s)  return true;
    if(s > min(min(m[0], m[1]), min(n[0], n[1])))   return false;
    memset(H, 0, sizeof H);
    For(x,0,2)
        For(j,0,m[x]){
            int l = max(0LL, j - s + 1);
            int cur = 0;
            For(i, 0, n[x]){
                int w = hashrow(x, i, l, j);
                cur = (cur * 1LL * p2);
                cur = (cur + w);
                H[x][j][i] = cur;
                //if(j)
                //Error(cur, w);
            }
        }
    vi mp;
    For(x,0,2){
        For(j,s-1,m[x])
        For(i,s-1,n[x]){
            int h = hashcol(x, j, i - s + 1, i);
            //error(x);
            //Error(i, j);
            //error(H[x][j][i]);
            //error(h);
            if(!x)
                mp.pb(h);
            else{
                int x = lower_bound(all(mp), h) - mp.begin();
                if(x >= 0 && x < (int)mp.size() && mp[x] == h)
                    return true;
            }
        }
        if(!x){
            sort(all(mp));
            mp.resize(unique(all(mp)) - mp.begin());
        }
    }
    return false;
}
int ans = 1e9;
main(){
    iOS;
    pw[0] = pw2[0] = 1;
    For(i,1,maxn)
        pw[i] = (pw[i-1] * p), pw2[i] = (pw2[i-1] * p2);
        For(x,0,2){
            cin >> n[x] >> m[x];
            For(i,0,n[x])
                For(j,0,m[x])
                {cin >> a[x][i][j]; a[x][i][j] += 16;}
            init(x);
        }
        int l = 0, r = min(min(n[0], n[1]), min(m[0], m[1])) + 1;
        while(r - l > 1){
            int mid = (l+r)/2;
            if(check(mid))
                l = mid;
            else
                r = mid;
        }
        smin(ans, l);
    cout << ans << endl;

}
```





<br /><br /><br />
## Problem 21:
**[Kth smallest number again](https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/)**<br />
Dexter was good in finding the `K th` smallest number from a set of numbers. 
He thought he could solve any problem related to `K th` smallest number. 
His friend Pipi challenged him with a problem.
He gave him various ranges of number, These numbers were arranged in 
increasing order(only distinct numbers to be taken into account). 
Now he asked him to find the `K th` smallest number in the sequence, again and again.<br />

**Input Format**<br />
The first line contains `T`, the number of test cases.<br />
For each test case, there will be two integers `N` and `Q`.<br />
Then `N` lines follow each line containing two integers `A` and `B` (denoting the range `A-B`)<br />
Then `Q` lines follow each line containing a non-negative integer `K` .<br />

**Output Format**<br />
For each query output the `K th` smallest number.<br />

* Constraints `1 <= T <= 100`<br />
`1 <= N <= 100`<br />
`1 <= Q <= 1000`<br />
`-10^18 <= A <= B <= 10^18`<br />
`K >= 1`<br />
N.B. If `Kth smallest number` is not present in the series, print `-1`<br />
<pre>
Sample Input
1
1 3
1 5
1
3
6
</pre>
<pre>
Sample Output
1
3
-1
</pre>
<pre>
Time Limit: 5
Memory Limit: 256
Source Limit:
</pre>
**Explanation**<br />
The numbers are `"1 2 3 4 5"`. The `1st` smallest number is `1`<br />
The `3rd` smallest number is `3` The `6th` smallest number is not present. Hence answer is `-1`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;  cin>> t;
    while (t--){
        long long int n, q; cin >> n >> q;
        vector< pair < long long int, long long int > >v;
        for (long long int i=0; i< n; i++){
            long long int x,y; cin >> x >> y;
            v.push_back ({x,y});
        }
        sort (v.begin(), v.end()); 
        long long int idx=0;
        for (long long int i=1; i< v.size(); i++){
             if (v[idx].second >= v[i].first)v[idx].second= max (v[idx].second, v[i].second);
             else{
                idx++;
                v[idx]= v[i];
            }
        }
        while (q--){
            long long int k; cin >> k;
            long long int ans=-1;
            for (long long int i=0; i<= idx; i++){
                if ((v[i].second - v[i].first + 1) >= k){
                    ans= v[i].first + k -1;
                    break; 
                }     
                else k= k - (v[i].second - v[i].first + 1);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
```







<br /><br /><br />
## Problem 22:
**[Find pivot element in a sorted array](http://theoryofprogramming.com/2017/12/16/find-pivot-element-sorted-rotated-array/)**<br />
`Problem Statement` – Suppose we have a `sorted array`, and now we rotate it `N` times, 
find the pivot element. The pivot element would be the largest element. <br />

`Clues` –
Solution should be `O(log N)` in time and `O(1)` in space.<br />

Can you think of  a `binary search` based solution where you keep comparing the 
middle element with the last element?<br />

`Solution` – The pivot element is basically, the `largest` element in an array. 
For a sorted and rotated array, it might be somewhere in between.<br />
We can solve this in `O(log N)` time, through a `divide-and-conquer` 
approach, which is similar to peak finding algorithm. We will have 
the lower limit `(low)` and the upper limit `(high)` from which we will 
calculate the `‘mid’`. Now, we must address a few cases –<br />

 `arr[mid] > arr[high]` – If the mid element is greater than the last element, 
    then the pivot should be in the second half of the array. Why is this so? 
    This is actually because it is a sorted and rotated array. 
    You may not understand this at first, but think of the values 
    of the elements in the array as a histogram.<br />
 `arr[mid] < arr[high]` – If the mid element is less than the last element, 
    then the pivot should be in the first half of the range.<br />
 `If mid element is a peak` – If the mid element satisfies the property of the 
    peak element (not lesser than its neighbors), then, it is the pivot.<br />
 `If we can put these conditions`, and handle the trivial cases, we can compute the 
    pivot element. The number of times the array is rotated would 
    be `(IndexOfPivotReturned + 1)`.<br />
    
```cpp
// A Divide-and-Conquer approach to find the pivot (highest) element in
// a sorted rotated array - returns the index of the pivot -> O(log N)
int peakElement(int arr[], int low, int high, int lowerBound, int upperBound)
{
    int mid = low + (high - low) / 2;
     
    if (mid == lowerBound) {
        if (mid == upperBound) {
            // Only 1 element
            return mid;
        } else if (arr[mid] >= arr[mid + 1]) {
            // Pivot is the greater element
            return mid;
        }
    } else if (mid == upperBound) {
        if (arr[mid] >= arr[mid - 1]) {
            // Pivot is the greater element
            return mid;
        }
    } else {
        if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1]) {
            // Mid value is the pivot
            return mid;
        } else if (arr[mid] > arr[high]) {
            // The Pivot is in the second half
            return peakElement(arr, mid + 1, high, lowerBound, upperBound);
        } else if (arr[mid] < arr[high]) {
            // The Pivot is in the first half
            return peakElement(arr, low, mid - 1, lowerBound, upperBound);
        }
    }
     
    return -1;
}
```







<br /><br /><br />
## Problem 23:
**[K-th Element of Two Sorted Arrays](https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1)**<br />
Given two sorted arrays `arr1` and `arr2` of size `N` and `M` respectively and an element `K`. The task is to find the element that would be at the `k’th` position of the final sorted array.<br />
 
>Example 1:<br />
Input:<br />
arr1[] = {2, 3, 6, 7, 9}<br />
arr2[] = {1, 4, 8, 10}<br />
k = 5<br />
Output:<br />
6<br />
Explanation:<br />
The final sorted array would be - 1, 2, 3, 4, 6, 7, 8, 9, 10<br />
The 5th element of this array is 6.<br />

>Example 2:<br />
Input:<br />
arr1[] = {100, 112, 256, 349, 770}<br />
arr2[] = {72, 86, 113, 119, 265, 445, 892}<br />
k = 7<br />
Output:<br />
256<br />
Explanation:<br />
Final sorted array is - 72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892<br />
7th element of this array is 256.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `kthElement()` which takes the arrays `arr1[]`, `arr2[]`, its size `N` and `M` respectively and an integer `K` as inputs and returns the element at the `Kth` position.<br />

<pre>
Expected Time Complexity: O(Log(N) + Log(M))
Expected Auxiliary Space: O(Log (N))
</pre>

* Constraints: `1 <= N, M <= 10^6`<br />
`1 <= arr1i, arr2i < INT_MAX`<br />
`1 <= K <= N+M`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int kth(int *arr1, int *arr2, int *end1, int *end2, int k){
        if(arr1 == end1)return arr2[k];
        if(arr2 == end2)return arr1[k];
        int mid1 = (end1-arr1)/2;
        int mid2 = (end2-arr2)/2;
        if(mid1+mid2 < k){
            if(arr1[mid1]>arr2[mid2])return kth(arr1, arr2+mid2+1, end1, end2, k-mid2-1);
            else return kth(arr1+mid1+1, arr2, end1, end2, k-mid1-1);
        }
        else{
            if(arr1[mid1]>arr2[mid2])return kth(arr1, arr2, arr1+mid1, end2, k);
            else return kth(arr1, arr2, end1, arr2+mid2, k);
        }
    }
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        return kth(arr1, arr2, arr1+n, arr2+m, k-1);
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int arr1[n],arr2[m];
        for(int i=0;i<n;i++)
            cin>>arr1[i];
        for(int i=0;i<m;i++)
            cin>>arr2[i];
        
        Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
    }
    return 0;
}
```












<br /><br /><br />
## Problem 24:
**[Aggressive cows](https://www.spoj.com/problems/AGGRCOW/)**<br />
Farmer John has built a new long barn, with `N` `(2 <= N <= 100,000)` stalls. The stalls are located along a straight line at positions `x1,...,xN` `(0 <= xi <= 1,000,000,000)`.<br />
His `C` `(2 <= C <= N)` cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, Farmer John wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What _is the largest minimum distance?_<br />
<pre>
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
</pre>
<pre>
Output
For each test case output one integer: the largest minimum distance.
</pre>
<pre>
Example
Input:
1
5 3
1
2
8
4
9
</pre>
<pre>
Output:
3
Output details:
Farmer John can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.
</pre>

```cpp
#include <bits/stdc++.h>
using namespace std;
int n,c;
int func(int num,int array[])
{
    int cows=1,pos=array[0];
    for (int i=1; i<n; i++)
    {
        if (array[i]-pos>=num)
        {
            pos=array[i];
            cows++;
            if (cows==c)
                return 1;
        }
    }
    return 0;
}
int bs(int array[])
{
    int ini=0,last=array[n-1],max=-1;
    while (last>ini)
    {
        //cout<<last<<" "<<ini<<endl;
        int mid=(ini+last)/2;
        if (func(mid,array)==1)
        {
            //cout<<mid<<endl;
            if (mid>max)
                max=mid;
            ini=mid+1;
        }
        else
            last=mid;
    }
    return max;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d %d",&n,&c);
        int array[n];
        for (int i=0; i<n; i++)
            scanf("%d",&array[i]);
        sort(array,array+n);
        //cout<<" dfsa \n";
        int k=bs(array);
        printf("%d\n",k);
    }
    return 0;
}
```










<br /><br /><br />
## Problem 25:
**[Book Allocation Problem](https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)**<br />
You are given `N` number of books. Every `ith` book has `Ai` number of pages. The books are arranged in ascending order.<br />
You have to allocate contiguous books to `M` number of students. There can be many ways or permutations to do so. In each permutation, one of the `M` students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.<br />
Each book will be allocated to exactly one student. Each student has to be allocated **at least** one book.<br />
**Note:** Return `-1` if a valid assignment is not possible, and allotment should be in `contiguous order` (see the explanation for better understanding).<br />

>Example 1:<br />
Input:<br />
N = 4<br />
A[] = {12,34,67,90}<br />
M = 2<br />
Output:113<br />
Explanation:Allocation can be done in following ways:{12} and {34, 67, 90}<br /> 
Maximum Pages = 191{12, 34} and {67, 90} <br />
Maximum Pages = 157{12, 34, 67} and {90} <br />
Maximum Pages = 113. <br />
Therefore, the minimum of these cases is 113, which is selected as the output.<br />

>Example 2:<br />
Input:<br />
N = 3<br />
A[] = {15,17,20}<br />
M = 2<br />
Output:32<br />
Explanation: Allocation is done as {15,17} and {20}<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `findPages()` which takes `2` Integers `N`, and `m` and an array `A[]` of length `N` as input and returns the expected answer.<br />

<pre>
Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(1)
</pre>

* Constraints: `1 <= N <= 10^5`<br />
`1 <= A [ i ] <= 10^6`<br />
`1 <= M <= 10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int findPages(int A[], int N, int M) {
        long long sum = 0;
        if(N<M)return -1;
        for(int i = 0;i<N;i++)sum+=A[i];
        long long start = 0;
        long long end = sum, mid;
        long long int ans = int(1e15);
        while(start<=end){
            mid = (start+end)/2;
            if(isPossible(A, N, M, mid)){
                ans = ans<mid? ans:mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
    
    bool isPossible(int arr[], int n, int m, long long int curMin){
        int studentsRequired = 1;
        int curSum = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]>curMin)return false;
            if(curSum + arr[i] > curMin){
                studentsRequired++;
                curSum = arr[i];
                if(studentsRequired>m)return false;
            }
            else curSum += arr[i];
        }
        return true;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int A[n];
        for(int i = 0;i<n;i++)cin>>A[i];
        int m; cin>>m;
        Solution ob;
        cout<<ob.findPages(A, n, m)<<endl;
    }
    return 0;
}
```





<br /><br /><br />
## Problem 26:
**[EKO - Eko binary-search](https://www.spoj.com/problems/EKO/)**<br />
Lumberjack Mirko needs to chop down `M` metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.<br />
Mirko‟s machine works as follows: Mirko sets a height parameter `H` (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than `H` (of course, trees not higher than `H` meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of `20`, `15`, `10`, and `17` metres, and Mirko raises his sawblade to `15` metres, the remaining tree heights after cutting will be `15`, `15`, `10`, and `15` metres, respectively, while Mirko will take `5` metres off the first tree and `2` metres off the fourth tree (`7` metres of wood in total).<br />
Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least `M` metres of wood.<br />
<pre>
Input
The first line of input contains two space-separated positive integers, N (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).
The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres). The sum of all heights will exceed M, thus Mirko will always be able to obtain the required amount of wood.
</pre>
<pre>
Output
The first and only line of output must contain the required height setting.
</pre>
<pre>
Example
</pre>
<pre>
Input:
4 7
20 15 10 17

Output:
15
</pre>
<pre>
Input:
5 20
4 42 40 26 46

Output:
36
</pre>
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[1000001];
ll m;
bool f(ll mid,ll n)
{
    ll i;
    ll diff=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>mid)
        {
            diff+=arr[i]-mid;
        }
        if(diff>=m)
            return true;
    }
    return false;
}
int main()
{
    ll n;
    cin>>n>>m;
    ll i,max=INT_MIN;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>max)
            max=arr[i];
    }
    ll low=0;
    ll high=max;
    while(low<high)
    {
        ll mid=low+(high-low+1)/2;
        if(f(mid,n))
            low=mid;
        else
            high=mid-1;
    }
    cout<<high;
    return 0;
} 
```








<br /><br /><br />
## Problem 27:
**[Weighted Job Scheduling in O(n Log n) time](https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/)**<br />
Given `N` jobs where every job is represented by following three elements of it.<br />

 1. Start Time<br />
 2. Finish Time<br />
 3. Profit or Value Associated<br />

Find the maximum profit subset of jobs such that no two jobs in the subset overlap.<br />
**Example:**<br />
<pre>
Input: Number of Jobs n = 4
       Job Details {Start Time, Finish Time, Profit}
       Job 1:  {1, 2, 50} 
       Job 2:  {3, 5, 20}
       Job 3:  {6, 19, 100}
       Job 4:  {2, 100, 200}
Output: The maximum profit is 250.
We can get the maximum profit by scheduling jobs 1 and 4.
Note that there is longer schedules possible Jobs 1, 2 and 3 
but the profit with this schedule is 20+50+100 which is less than 250.  
</pre>
The above problem can be solved using following `recursive` solution.<br />
<pre>
1) First sort jobs according to finish time.
2) Now apply following recursive process. 
   // Here arr[] is array of n jobs
   findMaximumProfit(arr[], n)
   {
     a) if (n == 1) return arr[0];
     b) Return the maximum of following two profits.
         (i) Maximum profit by excluding current job, i.e., 
             findMaximumProfit(arr, n-1)
         (ii) Maximum profit by including the current job            
   }

How to find the profit including current job?
The idea is to find the latest job before the current job (in 
sorted array) that doesn't conflict with current job 'arr[n-1]'. 
Once we find such a job, we recur for all jobs till that job and
add profit of current job to result.
In the above example, "job 1" is the latest non-conflicting
for "job 4" and "job 2" is the latest non-conflicting for "job 3".
</pre>
The time complexity of Binary Search based solution is O(n Log n).<br />
The algorithm is:<br />

 1. Sort the jobs by non-decreasing finish times.<br />
 2. For each `i` from `1` to `n`, determine the maximum value of the schedule from the subsequence of jobs`[0..i]`. Do this by comparing the inclusion of `job[i]` to the schedule to the exclusion of `job[i]` to the schedule, and then taking the `max`.<br />
 
To find the profit with inclusion of `job[i]`. we need to find the latest job that doesn’t conflict with `job[i]`. The idea is to use `Binary Search` to find the latest non-conflicting job.<br />

```cpp
// C++ program for weighted job scheduling using Dynamic
// Programming and Binary Search
#include <iostream>
#include <algorithm>
using namespace std;

// A job has start time, finish time and profit.
struct Job
{
	int start, finish, profit;
};

// A utility function that is used for sorting events
// according to finish time
bool myfunction(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}

// A Binary Search based function to find the latest job
// (before current job) that doesn't conflict with current
// job. "index" is index of the current job. This function
// returns -1 if all jobs before index conflict with it.
// The array jobs[] is sorted in increasing order of finish
// time.
int binarySearch(Job jobs[], int index)
{
	// Initialize 'lo' and 'hi' for Binary Search
	int lo = 0, hi = index - 1;

	// Perform binary Search iteratively
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (jobs[mid].finish <= jobs[index].start)
		{
			if (jobs[mid + 1].finish <= jobs[index].start)
				lo = mid + 1;
			else
				return mid;
		}
		else
			hi = mid - 1;
	}

	return -1;
}

// The main function that returns the maximum possible
// profit from given array of jobs
int findMaxProfit(Job arr[], int n)
{
	// Sort jobs according to finish time
	sort(arr, arr+n, myfunction);

	// Create an array to store solutions of subproblems. table[i]
	// stores the profit for jobs till arr[i] (including arr[i])
	int *table = new int[n];
	table[0] = arr[0].profit;

	// Fill entries in table[] using recursive property
	for (int i=1; i<n; i++)
	{
		// Find profit including the current job
		int inclProf = arr[i].profit;
		int l = binarySearch(arr, i);
		if (l != -1)
			inclProf += table[l];

		// Store maximum of including and excluding
		table[i] = max(inclProf, table[i-1]);
	}

	// Store result and free dynamic memory allocated for table[]
	int result = table[n-1];
	delete[] table;
	
	return result;
}

int main()
{
	Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Optimal profit is " << findMaxProfit(arr, n);
	return 0;
}
```
Output:<br />
<pre>
Optimal profit is 250
</pre>
The above problem can be solved using the following `recursive` solution.<br />
<pre>
1) First sort jobs according to finish time.
2) Now apply following recursive process. 
   // Here arr[] is array of n jobs
   findMaximumProfit(arr[], n)
   {
     a) if (n == 1) return arr[0];
     b) Return the maximum of following two profits.
         (i) Maximum profit by excluding current job, i.e., 
             findMaximumProfit(arr, n-1)
         (ii) Maximum profit by including the current job            
   }

How to find the profit including current job?
The idea is to find the latest job before the current job (in 
sorted array) that doesn't conflict with current job 'arr[n-1]'. 
Once we find such a job, we recur for all jobs till that job and
add profit of current job to result.
In the above example, "job 1" is the latest non-conflicting
for "job 4" and "job 2" is the latest non-conflicting for "job 3".
</pre>
The following is the implementation of the above naive `recursive` method.<br />
```cpp
// C++ program for weighted job scheduling using Naive Recursive Method
#include <iostream>
#include <algorithm>
using namespace std;

// A job has start time, finish time and profit.
struct Job
{
	int start, finish, profit;
};

// A utility function that is used for sorting events
// according to finish time
bool jobComparator(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}

// Find the latest job (in sorted array) that doesn't
// conflict with the job[i]. If there is no compatible job,
// then it returns -1.
int latestNonConflict(Job arr[], int i)
{
	for (int j=i-1; j>=0; j--)
	{
		if (arr[j].finish <= arr[i-1].start)
			return j;
	}
	return -1;
}

// A recursive function that returns the maximum possible
// profit from given array of jobs. The array of jobs must
// be sorted according to finish time.
int findMaxProfitRec(Job arr[], int n)
{
	// Base case
	if (n == 1) return arr[n-1].profit;

	// Find profit when current job is included
	int inclProf = arr[n-1].profit;
	int i = latestNonConflict(arr, n);
	if (i != -1)
	inclProf += findMaxProfitRec(arr, i+1);

	// Find profit when current job is excluded
	int exclProf = findMaxProfitRec(arr, n-1);

	return max(inclProf, exclProf);
}

// The main function that returns the maximum possible
// profit from given array of jobs
int findMaxProfit(Job arr[], int n)
{
	// Sort jobs according to finish time
	sort(arr, arr+n, jobComparator);

	return findMaxProfitRec(arr, n);
}

// Driver program
int main()
{
	Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "The optimal profit is " << findMaxProfit(arr, n);
	return 0;
}
```
Output:<br />
<pre>
Optimal profit is 250
</pre>
The above solution may contain many overlapping subproblems. For example, if lastNonConflicting() always returns the previous job, then `findMaxProfitRec(arr, n-1)` is called `twice` and the time complexity becomes `O(n*2^n)`.<br /> 
As another example when `lastNonConflicting()` returns previous to the previous job, there are two `recursive` calls, for `n-2` and `n-1`. In this example case, `recursion` becomes the same as `Fibonacci Numbers`.<br />
Below is an implementation based on `Dynamic Programming`.<br />
```cpp
// C++ program for weighted job scheduling using Dynamic
// Programming.
#include <algorithm>
#include <iostream>
using namespace std;

// A job has start time, finish time and profit.
struct Job {
	int start, finish, profit;
};

// A utility function that is used for sorting events
// according to finish time
bool jobComparator(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}

// Find the latest job (in sorted array) that doesn't
// conflict with the job[i]
int latestNonConflict(Job arr[], int i)
{
	for (int j = i - 1; j >= 0; j--) {
		if (arr[j].finish <= arr[i].start)
			return j;
	}
	return -1;
}

// The main function that returns the maximum possible
// profit from given array of jobs
int findMaxProfit(Job arr[], int n)
{
	// Sort jobs according to finish time
	sort(arr, arr + n, jobComparator);

	// Create an array to store solutions of subproblems.
	// table[i] stores the profit for jobs till arr[i]
	// (including arr[i])
	int* table = new int[n];
	table[0] = arr[0].profit;

	// Fill entries in M[] using recursive property
	for (int i = 1; i < n; i++) {
		// Find profit including the current job
		int inclProf = arr[i].profit;
		int l = latestNonConflict(arr, i);
		if (l != -1)
			inclProf += table[l];

		// Store maximum of including and excluding
		table[i] = max(inclProf, table[i - 1]);
	}

	// Store result and free dynamic memory allocated for
	// table[]
	int result = table[n - 1];
	delete[] table;

	return result;
}

// Driver program
int main()
{
	Job arr[] = { { 3, 10, 20 },
				{ 1, 2, 50 },
				{ 6, 19, 100 },
				{ 2, 100, 200 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The optimal profit is " << findMaxProfit(arr, n);
	return 0;
}
```
Output:<br />
<pre>
The optimal profit is 250
</pre>
<pre>
Time Complexity of the above Dynamic Programming Solution is O(n^2)
</pre>









<br /><br /><br />
## Problem 28:
**[Missing Number in AP](https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1)**<br />
Given three integers  `'A'` denoting the first term of an arithmetic sequence , `'C'` denoting the common difference of an arithmetic sequence and an integer `'B'`. you need to tell whether `'B'` exists in the arithmetic sequence or not.<br />

>Example 1:<br />
Input: A = 1, B = 3, C = 2<br />
Output: 1<br />
Explaination: 3 is the second term of the sequence starting with 1 and having a common difference 2.<br />

>Example 2:<br />
Input: A = 1, B = 2, C = 3<br />
Output: 0<br />
Explaination: 2 is not present in the sequence.<br />

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `inSequence()` which takes `A`, `B` and `C` and returns `1` if `B` is present in the sequence. Otherwise, returns `0`.<br />

<pre>
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `-10^9 ≤ A, B, C ≤ 10^9` 

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int inSequence(int A, int B, int C){
        int d = (B-A);
        if(d==0)return 1;
        if(d<0){
            if(C>=0)return 0;
            if(d%C == 0)return 1;
            return 0;
        }
        else{
            if(C<=0)return 0;
            if(d%C == 0)return 1;
            return 0;
        }
        return 0;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
```










<br /><br /><br />
## Problem 29:
**[Smallest number with atleast n trailing zeroes infactorial](https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1)**<br />
Given a number `n`. The task is to find the smallest number whose factorial contains at least `n` trailing zeroes.<br />

>Example 1:<br />
Input:<br />
n = 1<br />
Output: 5<br />
Explanation : 5! = 120 which has at least 1 trailing 0.<br />

>Example 2:<br />
Input:<br />
n = 6<br />
Output: 25<br />
Explanation : 25! has at least 6 trailing 0.<br />

**Your Task:**<br />
Complete the function `findNum()` which takes an integer `N` as input parameters, and returns the `answer`.<br />

<pre>
Expected Time Complexity: O(log2 N * log5 N).
Expected Auxiliary Space: O(1).
</pre>

* Constraints: `1 <= n <= 10^4`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int findNum(int n){
            if(n==1)return (5);
            int s = 0, e = 5*n;
            int ans = -1;
            while(s<=e){
                int mid = (s+e)/2;
                if(check(mid, n)){
                    ans = mid;
                    e = mid-1;
                }
                else s = mid+1;
            }
            return ans;
        }
        
        bool check(int mid, int n){
            int cnt = 0, f = 5;
            while(f<=mid){
                cnt += mid/f;
                f*=5;
            }
            return (cnt >= n);
        }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Solution ob;
        cout<<ob.findNum(n)<<endl;
    }
    return 0;
}
```









<br /><br /><br />
## Problem 30:
**[Painters Partition Problem](https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1)**<br />
Dilpreet wants to paint his dog's home that has `n` boards with different lengths. The length of `ith` board is given by `arr[i]` where `arr[]` is an array of `n` integers. He hired `k` painters for this work and each painter takes **1 unit time to paint 1 unit of the board**.<br />
The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous 
boards, say boards numbered **{2,3,4}** or only board **{1}** or nothing but not boards **{2,4,5}**.<br />

>Example 1:<br />
Input:<br />
n = 5<br />
k = 3<br />
arr[] = {5,10,30,20,15}<br />
Output: 35<br />
Explanation: The most optimal way will be:<br />
Painter 1 allocation : {5,10}<br />
Painter 2 allocation : {30}<br />
Painter 3 allocation : {20,15}<br />
Job will be done when all painters finish i.e. at time = max(5+10, 30, 20+15) = 35<br />

>Example 2:<br />
Input:<br />
n = 4<br />
k = 2<br />
arr[] = {10,20,30,40}<br />
Output: 60<br />
Explanation: The most optimal way to paint:<br />
Painter 1 allocation : {10,20,30}<br />
Painter 2 allocation : {40}<br />
Job will be complete at time = 60<br />

**Your task:**<br />
Your task is to complete the function `minTime()` which takes the integers `n` and `k` and the array `arr[]` as input and returns _the minimum time required to paint all partitions_.<br />

<pre>
Expected Time Complexity: O(n log m) , m = sum of all boards' length
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ n ≤ 10^5`<br />
`1 ≤ k ≤ 10^5`<br />
`1 ≤ arr[i] ≤ 10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int getMax(int arr[], int n){
    	int max = INT_MIN;
    	for (int i = 0; i < n; i++)
    		if (arr[i] > max)
    			max = arr[i];
    	return max;
    }
    
    long long getSum(int arr[], int n){
    	long long total = 0;
    	for (int i = 0; i < n; i++)
    		total += arr[i];
    	return total;
    }
    
    int numberOfPainters(int arr[], int n, long long maxLen){
    	long long total = 0, numPainters = 1;
    	for (int i = 0; i < n; i++) {
    		total += arr[i];
    		if (total > maxLen) {
    			total = arr[i];
    			numPainters++;
    		}
    	}
        return numPainters;
    }
    
    long long minTime(int arr[], int n, int k){
    	long long lo = getMax(arr, n);
    	long long hi = getSum(arr, n);
        while (lo < hi) {
    		long long mid = lo + (hi - lo) / 2;
    		long long requiredPainters = numberOfPainters(arr, n, mid);
            if (requiredPainters <= k)hi = mid;
    		else lo = mid + 1;
    	}
    	return lo;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int k, n;
        cin>>k>>n;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.minTime(arr, n, k)<<endl;
    }
    return 0;
}
```








<br /><br /><br />
## Problem 31:
**[PRATA - Roti Prata](https://www.spoj.com/problems/PRATA/)**<br />
IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get `P (P<=1000)` pratas packed for the function. The stall has `L` cooks `(L<=50)` and each cook has a rank `R (1<=R<=8)`. A cook with a rank `R` can cook 1 prata in the first `R` minutes 1 more prata in the next `2R` minutes, 1 more prata in `3R` minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked **2**.. he will cook one prata in **2** minutes one more prata in the next **4** mins an one more in the next **6** minutes hence in total **12** minutes he cooks **3** pratas in **13** minutes also he can cook only **3** pratas as he does not have enough time for the **4th** prata). The webmaster wants to know the _minimum time to get the order done_. Please write a program to help him out.<br />
<pre>
Input
The first line tells the number of test cases. Each test case consist of `2` lines. In the first line of the test case we have `P` the number of prata ordered. In the next line the first integer denotes the number of cooks `L` and `L` integers follow in the same line each denoting the rank of a cook.
</pre>
<pre>
Output
Print an integer which tells the number of minutes needed to get the order done.
</pre>
<pre>
Example
</pre>
<pre>
Input:
3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1
</pre>
<pre>
Output:
12
36
1
</pre>
```cpp
/*
    This problem uses binary search approach , as answer is monotonic function. 
    ( of true and false on time ).
    By applying binary search on time , we get the answer.
*/

#include <iostream>
using namespace std;

bool isPossible(int p,int cook[],int n,int mid){

    int cnt = 0;
    for(int i=0;i<n;i++){
        //for each cook count the pratas
        int c = 0;
        int time = mid;
        int perpratas = cook[i]; // time taken to cook each pratas by ith cook
        while(time > 0){
            time = time - perpratas;
            if( time >= 0){
                c += 1;
                perpratas  += cook[i];
            }
        }
        cnt += c;
        if(cnt >= p)
            return true;
    }

    return false;
}

int minTime(int p,int cook[],int n){
    int s = 0, e = 10000007;
    int mid,ans=-1;

    while(s<=e){
        mid = (s+e)/2;
        if(isPossible(p,cook,n,mid)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int p;
        cin>>p;
        int n;
        cin>>n;
        int cook[n];
        for(int i=0;i<n;i++)
            cin>>cook[i];

        cout<<minTime(p,cook,n)<<endl;
    }

    return 0;
}
```







<br /><br /><br />
## Problem 32:
**[The Double HeLiX](https://www.spoj.com/problems/ANARC05B/)**<br />
Two ﬁnite, strictly increasing, integer sequences are given. Any common integer between the two sequences constitute an intersection point. Take for example the following two sequences where intersection points are printed in bold:<br />

 * First= 3 5 **7** 9 20 **25** 30 40 **55** 56 **57** 60 62<br />
 * Second= 1 4 **7** 11 14 **25** 44 47 **55** **57** 100
 
You can `‘walk”` over these two sequences in the following way:<br />

 1. You may `start` at the beginning of any of the `two` sequences. Now start moving forward.<br />
 2. At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, or switching to the other sequence.<br />

The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the above example, the largest possible sum is `450`, which is the result of adding `3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62`.<br />
<pre>
Input
Your program will be tested on a number of test cases. Each test case will be speciﬁed on two separate lines. 
Each line denotes a sequence and is speciﬁed using the following format:
</pre>
<pre>
n v1 v2 ... vn
</pre>
Where `n` is the length of the sequence and `vi` is the `ith` element in that sequence. Each sequence will have at least one element but no more than `10,000`. All elements are between `-10,000` and `10,000` (inclusive).<br />
The last line of the input includes a single zero, which is not part of the test cases.<br />
<pre>
Output
For each test case, write on a separate line, the largest possible sum that can be produced.
</pre>
<pre>
Sample
</pre>
<pre>
Input:
13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100
4 -5 100 1000 1005
3 -12 1000 1001
0
</pre>
<pre>
Output:
450
2100
</pre>
```cpp
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define DEBUG 0

int a[11000], b[11000];

int max(int c, int d) {
    return c > d ? c : d;
}

int main(int argc, char * argv[]) {

    int n, m;
    scanf("%d" , &n);

    while (n != 0) {

        for (int i = 0; i < n; i++)
            scanf("%d" , &a[i]);

        scanf("%d" , &m);
        for (int i = 0; i < m; i++)
            scanf("%d" , &b[i]);

        int suma = 0, sumb = 0, result = 0;
        int i = 0, j = 0;

        while (1) {

            if (i < n && j < m && a[i] < b[j]) {
                suma += a[i];
                //cout << "suma = " << suma << endl;
                i++;
            } else if (i < n && j < m && b[j] < a[i]) {
                sumb += b[j];
                //cout << "sumb = " << sumb << endl;
                j++;
            } else if (i < n && j < m && a[i] == b[j]) {
                result += max(suma + a[i], sumb + b[j]);
                //cout << "result = " << result << endl;
                suma = sumb = 0;
                i++;
                j++;
            }

            if ( i >= n && j >= m )
                break;

            if ( i >= n ) {
                //cout << "adding remaining b" << endl;
                while ( j < m ) {
                    sumb += b[j];
                    j++;
                }
                result += max(suma , sumb);
                break;
            }

            if ( j >= m ) {
                //cout << "adding remaining a" << endl;
                while ( i < n ) {
                    suma += a[i];
                    //cout << "suma = " << suma << endl;
                    i++;
                }
                //cout << " max of : " << suma << " and " << sumb << endl;
                result += max(suma, sumb);
                //cout << "result = " << result << endl;
                break;
            }

        }

        cout << result << endl;

        scanf("%d" , &n);
    }

    return 0;
}
```









<br /><br /><br />
## Problem 33:
**[Subset Sums](https://www.spoj.com/problems/SUBSUMS/)**<br />
Given a sequence of `N (1 ≤ N ≤ 34)` numbers `S1, ..., SN` `(-20,000,000 ≤ Si ≤ 20,000,000)`, determine how many subsets of `S` (including the empty one) have a sum between `A` and `B` `(-500,000,000 ≤ A ≤ B ≤ 500,000,000)`, inclusive.<br />
<pre>
Input
The first line of standard input contains the three integers N, A, and B. The following N lines contain S1 through SN, in order.
</pre>
<pre>
Output
Print a single integer to standard output representing the number of subsets satisfying the above property. Note that the answer may overflow a 32-bit integer.
</pre>
<pre>
Example
</pre>
<pre>
Input:
3 -1 2
1
-2
3
</pre>
<pre>
Output:
5
</pre>

The following `5` subsets have a sum between `-1` and `2`:<br />
 * 0 = 0 (the empty subset)<br />
 * 1 = 1<br />
 * 1 + (-2) = -1<br />
 * -2 + 3 = 1<br />
 * 1 + (-2) + 3 = 2<br />

```cpp
#include<bits/stdc++.h>
using namespace std;
void subset(int s[],vector<int> &v,int n,int start)
{
    int i, j, sum;
    for(i = 0; i < pow(2,n); i++) {
        sum = 0;
        for(j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sum = sum + s[j+start];
            }
        }
        v.push_back(sum);
    }
}
int main()
{
    int n, a, b, i, j, s[40], hi, lo;
    vector<int> left,right;
    long long int sum;
    sum = 0;
    scanf("%d%d%d",&n,&a,&b);

    for(i = 0;i < n; i++) {
        scanf("%d",&s[i]);
    }

    subset(s,left,n/2,0);
    subset(s,right,(n&1)?n/2+1:n/2,n/2);

    sort(right.begin(),right.end());

    for(i = 0; i < left.size();i++) {
        lo = lower_bound(right.begin(),right.end(),a-left[i])-right.begin();
        hi = upper_bound(right.begin(),right.end(),b-left[i])-right.begin();
        sum = sum + (hi-lo);
    }
    printf("%lld\n",sum);
}
```









<br /><br /><br />
## Problem 34:
**[]()**<br />

<br /><br /><br />
## Problem 35:
**[]()**<br />

<br /><br /><br />
## Problem 36:
**[]()**<br />
