# Love Babbar Sheet 450 - Array
## Problem 1:
**[Write a program to reverse an array or string](https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/)**<br />
Given an array (or string), the task is to reverse the array/string.<br />
Examples : <br />
<pre>
Input  : arr[] = {1, 2, 3}
Output : arr[] = {3, 2, 1}

Input :  arr[] = {4, 5, 1, 2}
Output : arr[] = {2, 1, 5, 4}
</pre><br />
Iterative way :<br />
<pre>
1) Initialize start and end indexes as start = 0, end = n-1 
2) In a loop, swap arr[start] with arr[end] and change start and end as follows : 
start = start +1, end = end – 1
</pre><br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/arra34.jpg"><br />
Another example to reverse a string:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/ARAIRA.jpg"><br />
Below is the implementation of the above approach : <br />
```cpp
// Iterative C++ program to reverse an array
#include <bits/stdc++.h>
using namespace std;

/* Function to reverse arr[] from start to end*/
void rvereseArray(int arr[], int start, int end)
{
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}	

/* Utility function to print an array */
void printArray(int arr[], int size)
{
for (int i = 0; i < size; i++)
cout << arr[i] << " ";

cout << endl;
}

/* Driver function to test above functions */
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	
	int n = sizeof(arr) / sizeof(arr[0]);

	// To print original array
	printArray(arr, n);
	
	// Function calling
	rvereseArray(arr, 0, n-1);
	
	cout << "Reversed array is" << endl;
	
	// To print the Reversed array
	printArray(arr, n);
	
	return 0;
}
```
<br />

Output :<br /> 
<pre>
1 2 3 4 5 6 
Reversed array is 
6 5 4 3 2 1 
</pre><br />

* Time Complexity : O(n)<br />
Recursive Way :<br />
<pre>
1) Initialize start and end indexes as start = 0, end = n-1 
2) Swap arr[start] with arr[end] 
3) Recursively call reverse for rest of the array.
</pre><br />
Below is the implementation of the above approach : <br />
```cpp
// Recursive C++ program to reverse an array
#include <bits/stdc++.h>
using namespace std;

/* Function to reverse arr[] from start to end*/
void rvereseArray(int arr[], int start, int end)
{
	if (start >= end)
	return;
	
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
	
	// Recursive Function calling
	rvereseArray(arr, start + 1, end - 1);
}	


/* Utility function to print an array */
void printArray(int arr[], int size)
{
for (int i = 0; i < size; i++)
cout << arr[i] << " ";

cout << endl;
}

/* Driver function to test above functions */
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	
	// To print original array
	printArray(arr, 6);
	
	// Function calling
	rvereseArray(arr, 0, 5);
	
	cout << "Reversed array is" << endl;
	
	// To print the Reversed array
	printArray(arr, 6);
	
	return 0;
}
```
<br />

Output : <br />
<pre>
1 2 3 4 5 6 
Reversed array is 
6 5 4 3 2 1 
</pre><br />

* Time Complexity : O(n)<br /><br /><br /><br />




## Problem 2:
**[Maximum and minimum of an array using minimum number of comparisons](https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/)**<br />
Write a C function to return minimum and maximum in an array. Your program should make the minimum number of comparisons. <br />
### METHOD 1 (Simple Linear Search) :<br />
```cpp
// C++ program of above implementation
#include<iostream>
using namespace std;

// Pair struct is used to return
// two values from getMinMax()
struct Pair
{
	int min;
	int max;
};

Pair getMinMax(int arr[], int n)
{
	struct Pair minmax;	
	int i;
	
	// If there is only one element
	// then return it as min and max both
	if (n == 1)
	{
		minmax.max = arr[0];
		minmax.min = arr[0];	
		return minmax;
	}
	
	// If there are more than one elements,
	// then initialize min and max
	if (arr[0] > arr[1])
	{
		minmax.max = arr[0];
		minmax.min = arr[1];
	}
	else
	{
		minmax.max = arr[1];
		minmax.min = arr[0];
	}
	
	for(i = 2; i < n; i++)
	{
		if (arr[i] > minmax.max)	
			minmax.max = arr[i];
			
		else if (arr[i] < minmax.min)	
			minmax.min = arr[i];
	}
	return minmax;
}

// Driver code
int main()
{
	int arr[] = { 1000, 11, 445, 1, 330, 3000 };
	int arr_size = 6;
	
	struct Pair minmax = getMinMax(arr, arr_size);
	
	cout << "Minimum element is "
		<< minmax.min << endl;
	cout << "Maximum element is "
		<< minmax.max;
		
	return 0;
}

```
Output:<br /> 
<pre>
Minimum element is 1
Maximum element is 3000
</pre><br />
* Time Complexity: O(n)<br />
* Auxiliary Space: O(1) as no extra space was needed.<br />

### METHOD 2 (Tournament Method):<br />
Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.<br />
<pre>
Pair MaxMin(array, array_size)
   if array_size = 1
      return element as both max and min
   else if arry_size = 2
      one comparison to determine max and min
      return that pair
   else    /* array_size  > 2 */
      recur for max and min of left half
      recur for max and min of right half
      one comparison determines true max of the two candidates
      one comparison determines true min of the two candidates
      return the pair of max and min
</pre><br />
Implementation :<br />
```cpp
// C++ program of above implementation
#include<iostream>
using namespace std;

// structure is used to return
// two values from minMax()
struct Pair
{
	int min;
	int max;
};

struct Pair getMinMax(int arr[], int low, int high)
{
	struct Pair minmax, mml, mmr;	
	int mid;
	
	// If there is only one element
	if (low == high)
	{
		minmax.max = arr[low];
		minmax.min = arr[low];	
		return minmax;
	}
	
	// If there are two elements
	if (high == low + 1)
	{
		if (arr[low] > arr[high])
		{
			minmax.max = arr[low];
			minmax.min = arr[high];
		}
		else
		{
			minmax.max = arr[high];
			minmax.min = arr[low];
		}
		return minmax;
	}
	
	// If there are more than 2 elements
	mid = (low + high) / 2;
	mml = getMinMax(arr, low, mid);
	mmr = getMinMax(arr, mid + 1, high);
	
	// Compare minimums of two parts
	if (mml.min < mmr.min)
		minmax.min = mml.min;
	else
		minmax.min = mmr.min;	
	
	// Compare maximums of two parts
	if (mml.max > mmr.max)
		minmax.max = mml.max;
	else
		minmax.max = mmr.max;	
	
	return minmax;
}

// Driver code
int main()
{
	int arr[] = { 1000, 11, 445, 1, 330, 3000 };
	int arr_size = 6;
	
	struct Pair minmax = getMinMax(arr, 0, arr_size - 1);
							
	cout << "Minimum element is "
		<< minmax.min << endl;
	cout << "Maximum element is "
		<< minmax.max;
		
	return 0;
}

```

Output: <br />
<pre>
Minimum element is 1
Maximum element is 3000
</pre><br />
* Time Complexity: O(n)<br />
* Auxiliary Space: O(log n) as the stack space will be filled for the maximum height of the tree formed during recursive calls same as a binary tree.<br />

### METHOD 3 (Compare in Pairs) :<br />
If n is odd then initialize min and max as first element.<br /> 
If n is even then initialize min and max as minimum and maximum of the first two elements respectively. <br />
For rest of the elements, pick them in pairs and compare their 
maximum and minimum with max and min respectively. <br />
```cpp
// C++ program of above implementation
#include<iostream>
using namespace std;

// Structure is used to return
// two values from minMax()
struct Pair
{
	int min;
	int max;
};

struct Pair getMinMax(int arr[], int n)
{
	struct Pair minmax;	
	int i;
	
	// If array has even number of elements
	// then initialize the first two elements
	// as minimum and maximum
	if (n % 2 == 0)
	{
		if (arr[0] > arr[1])	
		{
			minmax.max = arr[0];
			minmax.min = arr[1];
		}
		else
		{
			minmax.min = arr[0];
			minmax.max = arr[1];
		}
		
		// Set the starting index for loop
		i = 2;
	}
	
	// If array has odd number of elements
	// then initialize the first element as
	// minimum and maximum
	else
	{
		minmax.min = arr[0];
		minmax.max = arr[0];
		
		// Set the starting index for loop
		i = 1;
	}
	
	// In the while loop, pick elements in
	// pair and compare the pair with max
	// and min so far
	while (i < n - 1)
	{		
		if (arr[i] > arr[i + 1])		
		{
			if(arr[i] > minmax.max)	
				minmax.max = arr[i];
				
			if(arr[i + 1] < minmax.min)		
				minmax.min = arr[i + 1];	
		}
		else	
		{
			if (arr[i + 1] > minmax.max)	
				minmax.max = arr[i + 1];
				
			if (arr[i] < minmax.min)		
				minmax.min = arr[i];	
		}
		
		// Increment the index by 2 as
		// two elements are processed in loop
		i += 2;
	}		
	return minmax;
}

// Driver code
int main()
{
	int arr[] = { 1000, 11, 445, 1, 330, 3000 };
	int arr_size = 6;
	Pair minmax = getMinMax(arr, arr_size);
	
	cout << "nMinimum element is "
		<< minmax.min << endl;
	cout << "nMaximum element is "
		<< minmax.max;
		
	return 0;
}
```
Output: <br />
<pre>
Minimum element is 1
Maximum element is 3000
</pre><br />
* Time Complexity: O(n)<br />
* Auxiliary Space: O(1) as no extra space was needed.<br /><br /><br /><br />


## Problem 3:
**[Kth smallest element](https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1)**<br />
Given an array `arr[]` and an integer `K` where K is smaller than size of array, the task is to find the `Kth smallest` element in the given array. It is given that all array elements are distinct.<br />

>Example 1:<br />
Input:<br />
N = 6<br />
arr[] = 7 10 4 3 20 15<br />
K = 3<br />
Output : 7<br />
Explanation :<br />
3rd smallest element in the given <br />
array is 7.<br />

>Example 2:<br />
Input:<br />
N = 5<br />
arr[] = 7 10 4 20 15<br />
K = 4<br />
Output : 15<br />
Explanation :<br />
4th smallest element in the given 
array is 15.<br />

Your Task:<br />
You don't have to read input or print anything. Your task is to complete the function `kthSmallest()` which takes the array `arr[]`, integers `l` and `r` denoting the `starting` and `ending` index of the array and an integer `K` as input and returns the `Kth` smallest element.<br />
 
<pre>
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(log(n))
</pre><br />
* Constraints: `1 <= N <= 10^5`<br />
`1 <= arr[i] <= 10^5`<br />
`1 <= K <= N`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    int randomPartition(int arr[], int l, int r){
        int n = r-l+1;
        int pivot = rand()%n;
        swap(&arr[l+pivot],&arr[r]);
        return partition(arr,l,r);
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        if(k>0 && k<=r-l+1){
            int pos = randomPartition(arr,l,r);
            if(pos-l == k-1){
                return arr[pos];
            }
            if(pos-l>k-1){
                return kthSmallest(arr,l,pos-1,k);
            }
            return kthSmallest(arr,pos+1,r,k-pos+l-1);
        }
        return INT_MAX;
    }
    int partition(int arr[],int l, int r){
        int x = arr[r],i=l;
        for (int j=l;j<=r-1;j++){
            if(arr[j]<=x){
                swap(&arr[i], &arr[j]);
                i++;
            }
        }
        swap(&arr[i],&arr[r]);
        return i;
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
```

<br /><br /><br />
## Problem 4:
**[Sort an array of 0s, 1s and 2s](https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1)**<br />
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.<br />

>Example 1:<br />
Input:<br /> 
N = 5<br />
arr[]= {0 2 1 2 0}<br />
Output:<br />
0 0 1 2 2<br />
Explanation:<br />
0s 1s and 2s are segregated into ascending order.<br />

>Example 2:<br />
Input: <br />
N = 3<br />
arr[] = {0 1 0}<br />
Output:<br />
0 0 1<br />
Explanation:<br />
0s 1s and 2s are segregated into ascending order.<br />

Your Task:<br />
You don't need to read input or print anything. Your task is to complete the function `sort012()` that takes an array arr and N as input parameters and `sorts the array in-place`.<br />
<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 <= N <= 10^6`<br />
`0 <= A[i] <= 2`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int low = 0, high = n-1, mid = 0;
    
        while(mid <= high){
    
            if(a[mid]==0)
                swap(a[mid++], a[low++]);
           
            else if(a[mid]==1)
                 mid++;
    
            else
                swap(a[mid], a[high--]);
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}
```


<br /><br /><br />
## Problem 5:
**[Move all negative numbers to beginning and positive to end with constant extra space](https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/)**<br />
An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.<br />
Examples : <br />
<pre>
Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
</pre><br />

Note: Order of elements is not important here.<br />

### Efficient Approach 1:<br />
The idea is to simply apply the partition process of quicksort. <br />
```cpp
// A C++ program to put all negative
// numbers before positive numbers
#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (i != j)
				swap(arr[i], arr[j]);
			j++;
		}
	}
}

// A utility function to print an array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

// Driver code
int main()
{
	int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	rearrange(arr, n);
	printArray(arr, n);
	return 0;
}
```
Output: <br />
<pre>
-1 -3 -7 4 5 6 2 8 9 
</pre>
* Time complexity: O(N) <br />
* Auxiliary Space: O(1)<br />

### Two Pointer Approach: 
The idea is to solve this problem with constant space and linear time is by using a two-pointer or two-variable approach where we simply take two variables like left and right which hold the 0 and N-1 indexes. Just need to check that :<br />

Check If the left and right pointer elements are negative then simply increment the left pointer.<br />
Otherwise, if the left element is positive and the right element is negative then simply swap the elements, and simultaneously increment and decrement the left and right pointers.<br />
Else if the left element is positive and the right element is also positive then simply decrement the right pointer.<br />
Repeat the above 3 steps until the left pointer ≤ right pointer.<br />

Below is the implementation of the above approach:<br />

```cpp
// C++ program of the above
// approach

#include <iostream>
using namespace std;

// Function to shift all the
// negative elements on left side
void shiftall(int arr[], int left,
			int right)
{

// Loop to iterate over the
// array from left to the right
while (left<=right)
{
	// Condition to check if the left
	// and the right elements are
	// negative
	if (arr[left] < 0 && arr[right] < 0)
	left+=1;
	
	// Condition to check if the left
	// pointer element is positive and
	// the right pointer element is negative
	else if (arr[left]>0 && arr[right]<0)
	{
	int temp=arr[left];
	arr[left]=arr[right];
	arr[right]=temp;
	left+=1;
	right-=1;
	}
	
	// Condition to check if both the
	// elements are positive
	else if (arr[left]>0 && arr[right] >0)
	right-=1;
	else{
	left += 1;
	right -= 1;
	}
}
}

// Function to print the array
void display(int arr[], int right){

// Loop to iterate over the element
// of the given array
for (int i=0;i<=right;++i){
	cout<<arr[i]<<" ";
}
cout<<endl;
}

// Driver Code
int main()
{
int arr[] = {-12, 11, -13, -5,
			6, -7, 5, -3, 11};
int arr_size = sizeof(arr) /
				sizeof(arr[0]);

// Function Call
shiftall(arr,0,arr_size-1);
display(arr,arr_size-1);
return 0;
}

```
Output : <br />
<pre>
-12 -3 -13 -5 -7 6 5 11 11 
</pre>
This is an in-place rearranging algorithm for arranging the positive and negative numbers where the order of elements is not maintained.<br />

* Time Complexity: O(N)<br />
* Auxiliary Space: O(1)<br />

### Approach 3:<br />
Here, we will use the famous Dutch National Flag Algorithm for two “colors”. The first color will be for all negative integers and the second color will be for all positive integers. We will divide the array into three partitions with the help of two pointers, low and high. <br />

1. ar[1…low-1] negative integers<br />
2. ar[low…high] unknown<br />
3. ar[high+1…N] positive integers<br />
Now, we explore the array with the help of low pointer, shrinking the unknown partition, and moving elements to their correct partition in the process. We do this until we have explored all the elements, and size of the unknown partition shrinks to zero.<br />

Below is the implementation of the above approach:<br />
```cpp
#include <iostream>
using namespace std;

// Swap Function.
void swap(int &a,int &b){
int temp =a;
a=b;
b=temp;
}

// Using Dutch National Flag Algorithm.
void reArrange(int arr[],int n){
	int low =0,high = n-1;
	while(low<high){
	if(arr[low]<0){
		low++;
	}else if(arr[high]>0){
		high--;
	}else{
		swap(arr[low],arr[high]);
	}
	}
}
void displayArray(int arr[],int n){
for(int i=0;i<n;i++){
	cout<<arr[i]<<" ";
}
cout<<endl;
}
int main() {
	// Data
	int arr[] = {1, 2, -4, -5, 2, -7, 3, 2, -6, -8, -9, 3, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	reArrange(arr,n);
	displayArray(arr,n);
	return 0;
}
```
Output: <br />
<pre>
-9 -8 -4 -5 -6 -7 3 2 2 2 1 3 2 1 
</pre>
* Time complexity: O(N) <br />
* Auxiliary Space: O(1)<br />

The order of elements does not matter here.<br />

<br /><br /><br />
## Problem 6:
**[Union of two arrays](https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1)**<br />
Given two arrays `a[]` and `b[]` of size `n` and `m` respectively. The task is to find union between these two arrays.<br />
Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in the union.<br />

>Example 1:<br />
Input:<br />
5 3<br />
1 2 3 4 5<br />
1 2 3<br />
Output: <br />
5<br />
Explanation: <br />
1, 2, 3, 4 and 5 are the elements which comes in the union set of both arrays. So count is 5.<br />

>Example 2:<br />
Input:<br />
6 2 <br />
85 25 1 32 54 6<br />
85 2 <br />
Output: <br />
7<br />
Explanation: <br />
85, 25, 1, 32, 54, 6, and 2 are the elements which comes in the union set of both arrays. So count is 7.<br />

Your Task:<br />
Complete `doUnion` funciton that takes `a`, `n`, `b`, `m` `as parameters and returns` the count of union elements of the two arrays. The `printing` is done by the `driver` code.<br />

* Constraints: `1 ≤ n, m ≤ 10^5`<br />
`0 ≤ a[i], b[i] < 10^5`<br />

<pre>
Expected Time Complexity : O((n+m)log(n+m))
Expected Auxilliary Space : O(n+m)
</pre><br />

```cpp
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        //using set to store the elements.
        unordered_set<int> s;
    	    
    	//we insert all the elements of first array in set.
    	for(int i = 0;i<n;i++)
    	   s.insert(a[i]);
    	    
    	 //we insert all the elements of second array in set.
    	 //Set does not contain duplicates.
    	 for(int i = 0;i<m;i++)
    	    s.insert(b[i]);
    	    
    	  //returning the size of set which is total number of elements in set.
    	  return s.size() ;
    	    
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
} 
```

<br /><br /><br />
## Problem 7:
**[Cyclically rotate an array by one](https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1)**<br />
Given an array, rotate the array by one position in clock-wise direction.<br />
 
>Example 1:<br />
Input:<br />
N = 5<br />
A[] = {1, 2, 3, 4, 5}<br />
Output:<br />
5 1 2 3 4<br />
 
>Example 2:<br />
Input:<br />
N = 8<br />
A[] = {9, 8, 7, 6, 4, 2, 1, 3}<br />
Output:<br />
3 9 8 7 6 4 2 1<br />
 
Your Task:  <br />
You don't need to read input or print anything. Your task is to complete the function `rotate()` which takes the array `A[]` and its size `N` as inputs and modify the array.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
</pre><br />

* Constraints: `1<=N<=10^5`<br />
`0<=a[i]<=10^5`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}
// } Driver Code Ends


//User function Template for C++

void rotate(int arr[], int n)
{
int x = arr[n-1], i;
   for (i = n-1; i > 0; i--)arr[i] = arr[i-1];
   arr[0] = x;
}
```


<br /><br /><br />
## Problem 8:
**[Kadane's Algorithm](https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1)**<br />
Given an array `Arr[]` of `N` integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.<br />

>Example 1:<br />
Input:<br />
N = 5<br />
Arr[] = {1,2,3,-2,5}<br />
Output:<br />
9<br />
Explanation:<br />
Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.<br />

>Example 2:<br />
Input:<br />
N = 4<br />
Arr[] = {-1,-2,-3,-4}<br />
Output:<br />
-1<br />
Explanation:<br />
Max subarray sum is -1 of element (-1)<br />

Your Task:<br />
You don't need to read input or print anything. The task is to complete the function `maxSubarraySum()` which takes Arr[] and N as input parameters and returns the sum of subarray with maximum sum.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
</pre><br />

* Constraints: `1 ≤ N ≤ 10^6`<br />
`-10^7 ≤ A[i] ≤ 10^7`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        long long maxh = 0, maxf = arr[0];
        for(int i=0;i<n;i++){
                maxh+=arr[i];
                if(maxf<maxh)maxf=maxh; 
                if(maxh<0)maxh=0;
        }
        return maxf;
    }
};
        

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
```

<br /><br /><br />
## Problem 9:
**[Minimise the maximum difference between heights [V.IMP]](https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1)**<br />
Given an array `arr[]` denoting heights of `N` towers and a positive integer `K`, you `have to` modify the height of each tower either by increasing or decreasing them by `K` only `once`. After modifying, height should be a `non-negative` integer. <br />
Find out the minimum possible difference of the height of shortest and longest towers after you have modified each tower.<br />

Note: It is compulsory to increase or decrease by K to each tower.<br />

>Example 1:<br />
Input:<br />
K = 2, N = 4<br />
Arr[] = {1, 5, 8, 10}<br />
Output:<br />
5<br />
Explanation:<br />
The array can be modified as {3, 3, 6, 8}. The difference between the largest and the smallest is 8-3 = 5.<br />

>Example 2:<br />
Input:<br />
K = 3, N = 5<br />
Arr[] = {3, 9, 12, 16, 20}<br />
Output:<br />
11<br />
Explanation:<br />
The array can be modified as {6, 12, 9, 13, 17}. The difference between the largest and the smallest is 17-6 = 11. <br />

Your Task:<br />
You don't need to read input or print anything. Your task is to complete the function `getMinDiff()` which takes the `arr[]`, `n` and `k` as input parameters and returns an integer denoting the minimum difference.<br />

<pre>
Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N)
</pre>

* Constraints : `1 ≤ K ≤ 10^4`<br />
`1 ≤ N ≤ 10^5`<br />
`1 ≤ Arr[i] ≤ 10^5`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        vector<pair<int, int>> v;
        vector<int> taken(n);

        // we will store all possible heights in a vector
        for (int i = 0; i < n; i++) {
            if (arr[i] - k >= 0) {
                v.push_back({arr[i] - k, i});
            }
            v.push_back({arr[i] + k, i});
        }
        sort(v.begin(), v.end());
        int elements_in_range = 0;
        int left = 0;
        int right = 0;

        // By two pointer we will traverse v and whenever we will get a range
        // in which all towers are included, we will update the answer.
        while (elements_in_range < n && right < v.size()) {
            if (taken[v[right].second] == 0) {
                elements_in_range++;
            }
            taken[v[right].second]++;
            right++;
        }
        int ans = v[right - 1].first - v[left].first;
        while (right < v.size()) {
            if (taken[v[left].second] == 1) {
                elements_in_range--;
            }
            taken[v[left].second]--;
            left++;

            while (elements_in_range < n && right < v.size()) {
                if (taken[v[right].second] == 0) {
                    elements_in_range++;
                }
                taken[v[right].second]++;
                right++;
            }

            if (elements_in_range == n) {
                ans = min(ans, v[right - 1].first - v[left].first);
            } else {
                break;
            }
        }
        return ans;
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  
```



<br /><br /><br />
## Problem n:
**[]()**<br />


<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />
<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />


<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />

<br /><br /><br />
## Problem n:
**[]()**<br />
<br /><br /><br />
## Problem n:
**[]()**<br />
