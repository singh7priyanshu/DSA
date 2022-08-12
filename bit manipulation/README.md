# Love Babbar Sheet 450 - Bit Manipulation
## Problem 1:
**[Count set bits in an integer](https://practice.geeksforgeeks.org/problems/set-bits0143/1)**<br />
Given a positive integer `N`, print `count of set bits in it`.<br /> 

>Example 1:<br />
Input:<br />
N = 6<br />
Output:<br />
2<br />
Explanation:<br />
Binary representation is '110' So the count of the set bit is 2.<br />

>Example 2:<br />
Input:<br />
8<br />
Output:<br />
1<br />
Explanation:<br />
Binary representation is '1000' So the count of the set bit is 1.<br />

**Your Task:**<br />  
You don't need to read input or print anything. Your task is to complete the function `setBits()` which takes an Integer `N` and returns _the count of number of set bits_.<br />

<pre>
Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ N ≤ 10^9`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setBits(int N) {
        int count = 0;
        while (N) {
            N &= (N - 1);
            count++;
        }
        return count;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Solution ob;
        int cnt = ob.setBits(n);
        cout << cnt << endl;
    }
}
```





<br /><br /><br />
## Problem 2:
**[Find the two non-repeating elements in an array of repeating elements](https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1)**<br />
Given an array `A` containing `2*N+2` positive numbers, out of which `2*N` numbers exist in pairs whereas the other two number occur exactly once and are distinct.<br /> Find the other two numbers. Return in increasing order.<br />

>Example 1:<br />
Input: <br />
N = 2<br />
arr[] = {1, 2, 3, 2, 1, 4}<br />
Output:<br />
3 4 <br />
Explanation: 3 and 4 occur exactly once.<br />

>Example 2:<br />
Input:<br />
N = 1<br />
arr[] = {2, 1, 3, 2}<br />
Output:<br />
1 3<br />
Explanation: 1 3 occur exactly once.<br />

**Your Task:**<br />
You do not need to read or print anything. Your task is to complete the function `singleNumber()` which takes the array as input parameter and returns _a list of two numbers which occur exactly once in the array_. The list must be in **ascending order**.<br />

<pre>
Expected Time Complexity: O(N)
Expected Space Complexity: O(1)
</pre>

* Constraints: `1 <= length of array <= 10^6` <br />
`1 <= Elements in array <= 5 * 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        long long int diff = 0;
        for(auto i: nums)
            diff = i ^ diff;
        // Get its last set bit
        diff &= -diff;
        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            }
            else // the bit is set
            {
                rets[1] ^= num;
            }
        }
        if(rets[0] > rets[1])
            swap(rets[0], rets[1]);
        return rets;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(2 * n+2);
        for(int i = 0;i<2*n + 2;i++)cin>>v[i];
        Solution ob;
        vector<int>ans = ob.singleNumber(v);
        for(auto i : ans){
            cout << i << " ";
        }
        cout << endl;
    }
}
```




<br /><br /><br />
## Problem 3:
**[Count number of bits to be flipped to convert A to B](https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1)**<br />
You are given two numbers `A` and `B`. The task is _to count the number of bits needed to be flipped to convert A to B_.<br />

>Example 1:<br />
Input: A = 10, B = 20<br />
Output: 4<br />
Explanation:<br />
A  = 01010<br />
B  = 10100<br />
As we can see, the bits of A that need to be flipped are `0101`0. If we flip these bits, we get 10100, which is B.<br />

>Example 2:<br />
Input: A = 20, B = 25<br />
Output: 3<br />
Explanation:<br />
A  = 10100<br />
B  = 11001<br />
As we can see, the bits of A that need to be flipped are 1`01`0`0`. If we flip these bits, we get 11001, which is B.<br />

**Your Task:** The task is to complete the function `countBitsFlip()` that takes `A` and `B` as parameters and returns _the count of the number of bits to be flipped to convert A to B_.<br />

<pre>
Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).
</pre>

* Constraints: `1 ≤ A, B ≤ 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countSetBits(unsigned int n){
        unsigned int count = 0;
        while(n)
        {
        //AND operation of n and 1 gives us the rightmost bit. 
        //counter variable is increased if we get 1 as the rightmost bit.
        count += n & 1;
        //Right Shift n by 1 to remove the rightmost bit.
        n >>= 1;
      }
      return count;
    }
    
    int countBitsFlip(int a, int b){
        
        int ans = 0;
        //XOR operation gives set bits only when there are dissimilar bits.
        //We store the value of XOR operation of a and b.
        ans = a^b;
        
        //returning the number of set bits in resultant.
        return countSetBits(ans);
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int a, b; cin>>a>>b;
        Solution ob;
        cout<<ob.countBitsFlip(a, b)<<endl;
    }
}
```







<br /><br /><br />
## Problem 4:
**[Count total set bits in all numbers from 1 to n](https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1)**<br />
You are given a number `N`. Find the _**total count of set bits** for all numbers from 1 to N(both inclusive)_.<br />

>Example 1:<br />
Input: N = 4<br />
Output: 5<br />
Explanation:<br />
For numbers from 1 to 4.<br />
For 1: 0 0 1 = 1 set bits<br />
For 2: 0 1 0 = 1 set bits<br />
For 3: 0 1 1 = 2 set bits<br />
For 4: 1 0 0 = 1 set bits<br />
Therefore, the total set bits is 5.<br />

>Example 2:<br />
Input: N = 17<br />
Output: 35<br />
Explanation: From numbers 1 to 17(both inclusive), the total number of set bits is 35.<br />

**Your Task:** The task is to complete the function `countSetBits()` that takes `n` as a parameter and returns _the count of all bits_.<br />

<pre>
Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).
</pre>

* Constraints: `1 ≤ N ≤ 10^8`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countSetBits(int n)
    {
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    //Ignoring 0 as all the bits are unset. 
        n++;
        int count=0;
        
        //Counting set bits from 1 to n.
        for( int x=2 ; x/2<n ; x=x*2 )
        {
            //Total count of pairs of 0s and 1s.
            int quotient = n/x;
            //quotient gives the complete count of pairs of 1s.
            //Multiplying it with the (current power of 2)/2 will 
            //give the count of 1s in the current bit.
            count += quotient * x / 2;
            
            int remainder = n%x;
            //If the count of pairs is odd then we add the remaining 1s 
            //which could not be grouped together. 
            if(remainder > x/2)
                count += remainder - x/2;
        }
        
        //returning count of set bits.
        return count;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Solution ob;
        cout<<ob.countSetBits(n)<<endl;
    }
}
```









<br /><br /><br />
## Problem 5:
**[Program to find whether a no is power of two](https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1)**<br />
Given a non-negative integer `N`. The task is to check if `N` is a power of `2`. More formally, _check if `N` can be expressed as `2x` for some `x`_.<br />

>Example 1:<br />
Input: N = 1<br />
Output: YES<br />
Explanation:1 is equal to 2 raised to 0 (20 = 1).<br />

>Example 2:<br />
Input: N = 98<br />
Output: NO<br />
Explanation: 98 cannot be obtained by any power of 2.<br />

**Your Task:** <br />
Your task is to complete the function `isPowerofTwo()` which takes `n` as a parameter and returns _`true` or `false` by checking if the given number can be represented as a power of two or not_.<br />

<pre>
Expected Time Complexity:O(log N).
Expected Auxiliary Space:O(1).
</pre>

* Constraints: `0 ≤N ≤10^18`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        if(n==0){
            return false;
        }
    
        //We use a counter variable to count number of set bits.
        int count = 0;
        while(n>0)
        {
            //Increment of counter variable if we get 1 as the rightmost bit.
            count+=(n&1);
            //Right Shift n to remove the rightmost bit.
            n>>=1;
        }
        //returning true if number of set bits is 1 otherwise false.
        return count==1;
        
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        Solution ob;
        if(ob.isPowerofTwo(n))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
```






<br /><br /><br />
## Problem 6:
**[Find position of the only set bit](https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1)**<br />
Given a number `N` having only one `‘1’` and all other `’0’s` in its binary representation, _find position of the only set bit_. If there are `0` or more than 1 set bit the answer should be `-1`. Position of  set bit `'1'` should be counted starting with `1` from LSB side in binary representation of the number.<br />

>Example 1:<br />
Input:<br />
N = 2<br />
Output:<br />
2<br />
Explanation:<br />
2 is represented as "10" in Binary. As we see there's only one set bit and it's in Position 2 and thus the Output 2.<br />

>Example 2:<br />
Input:<br />
N = 5<br />
Output:<br />
-1<br />
Explanation:<br />
5 is represented as "101" in Binary. As we see there's two set bits and thus the Output -1.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `findPosition()` which takes an integer `N` as input and returns the answer.<br />

<pre>
Expected Time Complexity: O(log(N))
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `0 <= N <= 10^8`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // A helper method which returns 1 if n is a power of 2 else returns 0.
    int isPowerOfTwo(int n) 
    {
        if (n && (!(n & (n - 1))))
            return 1;
        else
            return 0;
    }
        
    int findPosition(int N) {
        
        if (!isPowerOfTwo(N)) 
            return -1; 
      
        int i = 1, pos = 1; 
      
        // Iterate through bits of n till we find a set bit 
        // i&n will be non-zero only when 'i' and 'n' have a set bit 
        // at same position 
        while (!(i & N)) { 
            // Unset current bit and set the next bit in 'i' 
            i = i << 1; 
      
            // increment position 
            ++pos; 
        } 
      
        return pos; 
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Solution ob;
        cout<<ob.findPosition(n)<<endl;
    }
}
```





<br /><br /><br />
## Problem 7:
**[Copy set bits in a range](https://www.geeksforgeeks.org/copy-set-bits-in-a-range/)**<br />
Given two numbers `x` and `y`, and a range `[l, r]` where `1 <= l, r <= 32`. The task is consider set bits of `y` in range `[l, r]` and set these bits in `x` also.<br />
Examples : <br />
<pre>
Input  : x = 10, y = 13, l = 2, r = 3
Output : x = 14
Binary representation of 10 is 1010 and 
that of y is 1101. There is one set bit
in y at 3'rd position (in given range). 
After we copy this bit to x, x becomes 1110
which is binary representation of 14.

Input  : x = 8, y = 7, l = 1, r = 2
Output : x = 11
</pre>
**Method 1 (One by one copy bits)**<br /> 
We can one by one find set bits of `y` by traversing given range. For every set bit, we _OR it to existing bit of x_, so that the becomes set in `x`, if it was not set. Below is C++ implementation.<br />
```cpp
// C++ program to rearrange array in alternating
// C++ program to copy set bits in a given
// range [l, r] from y to x.
#include <bits/stdc++.h>
using namespace std;

// Copy set bits in range [l, r] from y to x.
// Note that x is passed by reference and modified
// by this function.
void copySetBits(unsigned &x, unsigned y, unsigned l, unsigned r)
{
// l and r must be between 1 to 32
// (assuming ints are stored using
// 32 bits)
if (l < 1 || r > 32)
	return ;

// Traverse in given range
for (int i=l; i<=r; i++)
{
	// Find a mask (A number whose
	// only set bit is at i'th position)
	int mask = 1 << (i-1);

	// If i'th bit is set in y, set i'th
	// bit in x also.
	if (y & mask)
		x = x | mask;
}
}

// Driver code
int main()
{
unsigned x = 10, y = 13, l = 1, r = 32;
copySetBits(x, y, l, r);
cout << "Modified x is " << x;
return 0;
}
```
Output<br />
<pre>
Modified x is 15
</pre>
<pre>
Time Complexity: O(r)
Auxiliary Space: O(1)
</pre>
**Method 2 (Copy all bits using one bit mask)**<br />
```cpp
// C++ program to copy set bits in a given
// range [l, r] from y to x.
#include <bits/stdc++.h>
using namespace std;

// Copy set bits in range [l, r] from y to x.
// Note that x is passed by reference and modified
// by this function.
void copySetBits(unsigned &x, unsigned y, unsigned l, unsigned r)
{
	// l and r must be between 1 to 32
	if (l < 1 || r > 32)
		return ;

	// get the length of the mask
	int maskLength = (1ll<<(r-l+1)) - 1;

	// Shift the mask to the required position
	// "&" with y to get the set bits at between
	// l ad r in y
	int mask = ((maskLength)<<(l-1)) & y ;
	x = x | mask;
}

// Driver code
int main()
{
unsigned x = 10, y = 13, l = 2, r = 3;
copySetBits(x, y, l, r);
cout << "Modified x is " << x;
return 0;
}
```
Output<br />
<pre>
Modified x is 14
</pre>
<pre>
Time Complexity: O(1)
Auxiliary Space: O(1)
</pre>




<br /><br /><br />
## Problem 8:
**[Divide two integers without using multiplication, division and mod operator](https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/)**<br />
Given two integers say `a` and `b`. Find the quotient after dividing `a` by `b` without using _multiplication_, _division_, and _mod operator_.<br />
Example: <br />
<pre>
Input : a = 10, b = 3
Output : 3

Input : a = 43, b = -8
Output :  -5 
</pre>
**Approach:** Keep subtracting the `divisor` from the `dividend` until the `dividend` becomes **less than** the `divisor`. The `dividend` becomes the `remainder`, and the number of times subtraction is done becomes the `quotient`. Below is the implementation of the above approach : <br />
```cpp
// C++ implementation to Divide two
// integers without using multiplication,
// division and mod operator
#include <bits/stdc++.h>
using namespace std;

// Function to divide a by b and
// return floor value of the result
long long divide(long long dividend, long long int divisor)
{

	// Calculate sign of divisor i.e.,
	// sign will be negative only if
	// either one of them is negative
	// otherwise it will be positive
	long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

	// Update both divisor and
	// dividend positive
	dividend = abs(dividend);
	divisor = abs(divisor);

	// Initialize the quotient
	long long quotient = 0;
	while (dividend >= divisor) {
		dividend -= divisor;
		++quotient;
	}

	// Return the value of quotient with the appropriate
	// sign.
	return quotient * sign;
}

// Driver code
int main()
{
	int a = -2147483648, b = -1;
	cout << divide(a, b) << "\n";

	a = 43, b = -8;
	cout << divide(a, b);

	return 0;
}
```
Output<br />
<pre>
3
-5
</pre>
<pre>
Time complexity : O(a/b) 
Auxiliary space : O(1)
</pre>
**Efficient Approach:** Use bit manipulation in order to find the `quotient`. The `divisor` and `dividend` can be written as <br />
<pre>
dividend = quotient * divisor + remainder
</pre>
As every number can be represented in base `2(0 or 1)`, represent the quotient in binary form by using the shift operator as given below:<br />

 1. Determine the most significant bit in the divisor. This can easily be calculated by iterating on the bit position i from `31` to `1`.<br />
 2. Find the first bit for which _**divisor << i**_ is less than dividend and keep updating the **_ith_** bit position for which it is true.<br />
 3. Add the result in the temp variable for checking the next position such that **_(temp + (divisor << i) )_** is less than the **dividend**.<br />
 4. Return the final answer of the quotient after updating with a corresponding sign.<br />

Below is the implementation of the above approach : <br />
```cpp
// C++ implementation to Divide two
// integers without using multiplication,
// division and mod operator
#include <bits/stdc++.h>
using namespace std;

// Function to divide a by b and
// return floor value it
long long divide(long long dividend, long long divisor) {

// Calculate sign of divisor i.e.,
// sign will be negative only if
// either one of them is negative
// otherwise it will be positive
int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

// remove sign of operands
dividend = abs(dividend);
divisor = abs(divisor);

// Initialize the quotient
long long quotient = 0, temp = 0;

// test down from the highest bit and
// accumulate the tentative value for
// valid bit
for (int i = 31; i >= 0; --i) {

	if (temp + (divisor << i) <= dividend) {
	temp += divisor << i;
	quotient |= 1LL << i;
	}
}
//if the sign value computed earlier is -1 then negate the value of quotient
if(sign==-1) quotient=-quotient;

return quotient;
}

// Driver code
int main() {
int a = -2147483648, b = -1;
cout << divide(a, b) << "\n";

a = 43, b = -8;
cout << divide(a, b);

return 0;
}
```
Output<br />
<pre>
3
-5
</pre>
<pre>
Time complexity : O(log(a)) 
Auxiliary space : O(1)
</pre>



<br /><br /><br />
## Problem 9:
**[Calculate square of a number without using *, / and pow()](https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/)**<br />
Given an integer `n`, calculate the square of a number without using *, / and pow().<br /> 
**Examples :**<br />
<pre>
Input: n = 5
Output: 25

Input: 7
Output: 49

Input: n = 12
Output: 144
</pre>
A **Simple Solution** is to repeatedly add `n` to result.<br /> 
Below is the implementation of this idea. <br />
```cpp
// Simple solution to calculate square without
// using * and pow()
#include <iostream>
using namespace std;

int square(int n)
{
	// handle negative input
	if (n < 0)
		n = -n;

	// Initialize result
	int res = n;

	// Add n to res n-1 times
	for (int i = 1; i < n; i++)
		res += n;

	return res;
}

// Driver code
int main()
{
	for (int n = 1; n <= 5; n++)
		cout << "n = " << n << ", n^2 = " << square(n) << endl;
	return 0;
}
```
Output<br />
<pre>
n = 1, n^2 = 1
n = 2, n^2 = 4
n = 3, n^2 = 9
n = 4, n^2 = 16
n = 5, n^2 = 25
</pre>
<pre>
Time Complexity: O(n)
Auxiliary Space: O(1)
</pre>
**Approach 2:**<br />
We can do it in **O(Logn)** **time using bitwise operators**. The idea is based on the following fact.<br />
<pre>
  square(n) = 0 if n == 0
  if n is even 
     square(n) = 4*square(n/2) 
  if n is odd
     square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1 

Examples
  square(6) = 4*square(3)
  square(3) = 4*(square(1)) + 4*1 + 1 = 9
  square(7) = 4*square(3) + 4*3 + 1 = 4*9 + 4*3 + 1 = 49
</pre>
**How does this work?**<br />
<pre>
If n is even, it can be written as
  n = 2*x 
  n2 = (2*x)2 = 4*x2
If n is odd, it can be written as 
  n = 2*x + 1
  n2 = (2*x + 1)2 = 4*x2 + 4*x + 1
</pre>
**floor(n/2)** can be calculated using a bitwise right shift operator. **2*x** and **4*x** can be calculated <br />
Below is the implementation based on the above idea.<br />
```cpp
// Square of a number using bitwise operators
#include <bits/stdc++.h>
using namespace std;

int square(int n)
{
	// Base case
	if (n == 0)
		return 0;

	// Handle negative number
	if (n < 0)
		n = -n;

	// Get floor(n/2) using right shift
	int x = n >> 1;

	// If n is odd
	if (n & 1)
		return ((square(x) << 2) + (x << 2) + 1);
	else // If n is even
		return (square(x) << 2);
}

// Driver Code
int main()
{
	// Function calls
	for (int n = 1; n <= 5; n++)
		cout << "n = " << n << ", n^2 = " << square(n) 	<< endl;
	return 0;
}
```
Output<br />
<pre>
n = 1, n^2 = 1
n = 2, n^2 = 4
n = 3, n^2 = 9
n = 4, n^2 = 16
n = 5, n^2 = 25
</pre>
<pre>
Time Complexity: O(logn)
Auxiliary Space: O(1)
</pre>
**Approach 3:**<br />
<pre>
For a given number `num` we get square of it by multiplying number as `num * num`. 
Now write one of `num` in square `num * num` in terms of power of `2`. Check below examples.

Eg: num = 10, square(num) = 10 * 10 
                          = 10 * (8 + 2) = (10 * 8) + (10 * 2)
    num = 15, square(num) = 15 * 15 
                          = 15 * (8 + 4 + 2 + 1) = (15 * 8) + (15 * 4) + (15 * 2) + (15 * 1)

Multiplication with power of 2's can be done by left shift bitwise operator.
</pre>
Below is the implementation based on the above idea. <br />
```cpp
// Simple solution to calculate square without
// using * and pow()
#include <iostream>
using namespace std;

int square(int num)
{
	// handle negative input
	if (num < 0) num = -num;

	// Initialize result
	int result = 0, times = num;

	while (times > 0)
	{
		int possibleShifts = 0, currTimes = 1;

		while ((currTimes << 1) <= times)
		{
			currTimes = currTimes << 1;
			++possibleShifts;
		}

		result = result + (num << possibleShifts);
		times = times - currTimes;
	}

	return result;
}

// Driver code
int main()
{
	// Function calls
	for (int n = 10; n <= 15; ++n)
		cout << "n = " << n << ", n^2 = " << square(n) << endl;
	return 0;
}
```
Output<br />
<pre>
n = 10, n^2 = 100
n = 11, n^2 = 121
n = 12, n^2 = 144
n = 13, n^2 = 169
n = 14, n^2 = 196
n = 15, n^2 = 225
</pre>
<pre>
Time Complexity: O(logn)
Auxiliary Space: O(1)
</pre>
```cpp
// Simple solution to calculate square without
// using * and pow()
#include <iostream>
using namespace std;

int square(int num)
{
	// handle negative input
	if (num < 0)
		num = -num;

	// Initialize power of 2 and result
	int power = 0, result = 0;
	int temp = num;

	while (temp) {
		if (temp & 1) {
			// result=result+(num*(2^power))
			result += (num << power);
		}
		power++;

		// temp=temp/2
		temp = temp >> 1;
	}

	return result;
}

// Driver code
int main()
{
	// Function calls
	for (int n = 10; n <= 15; ++n)
		cout << "n = " << n << ", n^2 = " << square(n) 	<< endl;
	return 0;
}
```
Output<br />
<pre>
n = 10, n^2 = 100
n = 11, n^2 = 121
n = 12, n^2 = 144
n = 13, n^2 = 169
n = 14, n^2 = 196
n = 15, n^2 = 225
</pre>
<pre>
Time Complexity: O(logn)
Auxiliary Space: O(1)
</pre>





<br /><br /><br />
## Problem 10:
**[]()**<br />
