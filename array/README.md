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
python :

```python
    def reverseList(A, start, end):
        while start < end:
            A[start], A[end] = A[end], A[start]
            start += 1
            end -= 1

  
    A = [1, 2, 3, 4, 5, 6]
    print(A)
    reverseList(A, 0, 5)
    print("Reversed list is")
    print(A)
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
python : 

```python

    def reverseList(A, start, end):
        if start >= end:
            return
        A[start], A[end] = A[end], A[start]
        reverseList(A, start+1, end-1)

    A = [1, 2, 3, 4, 5, 6]
    print(A)
    reverseList(A, 0, 5)
    print("Reversed list is")
    print(A)
```

<br />
Output : <br />
<pre>
1 2 3 4 5 6 
Reversed array is 
6 5 4 3 2 1 
</pre><br />

* Time Complexity : O(n)<br />


     
