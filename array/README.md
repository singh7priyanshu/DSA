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

* Time Complexity : O(n)<br />




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
* Auxiliary Space: O(1) as no extra space was needed.<br />
