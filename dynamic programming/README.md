# Table of Content 
* [Coin ChangeProblem](#Problem-1)
* [Knapsack Problem](#Problem-2)
* [Binomial CoefficientProblem](#Problem-3)
* [Permutation CoefficientProblem](#Problem-4)
* [Program for nth Catalan Number](#Problem-5)
* [Matrix Chain Multiplication](#Problem-6)
* [Edit Distance](#Problem-7)
* [Partition Equal Subset Sum / Subset Sum Problem](#Problem-8)
* [Friends Pairing Problem](#Problem-9)
* [Gold Mine Problem](#Problem-10)
* [Assembly Line SchedulingProblem](#Problem-11)
* [Painting the Fence](#Problem-12)
* [Maximize The Cut Segments](#Problem-13)
* [Longest Common Subsequence](#Problem-14)
* [Longest Repeated Subsequence](#Problem-15)
* [Longest Increasing Subsequence](#Problem-16)
* [Space Optimized Solution of LCS](#Problem-17)
* [LCS (Longest Common Subsequence) of three strings](#Problem-18)
* [Maximum Sum Increasing Subsequence](#Problem-19)
* [Count all subsequences having product less than K](#Problem-20)
* [Longest subsequence such that difference between adjacent is one](#Problem-21)
* [Maximum subsequence sum such that no three are consecutive](#Problem-22)
* [Egg Dropping Puzzle](#Problem-23)
* [Maximum Length Chain of Pairs](#Problem-24)
* [Maximum size square sub-matrix with all 1s](#Problem-25)
* [Maximum sum of pairs with specific difference](#Problem-26)
* [Maximum path sum in matrix](#Problem-27)
* [Maximum difference of zeros and ones in binary string](#Problem-28)
* [Minimum number of jumps to reach end](#Problem-29)
* [Minimum cost to fill given weight in a bag](#Problem-30)
* [Minimum removals from array to make max –min <= K](#Problem-31)
* [Longest Common Substring](#Problem-32)
* [Reach a given score](#Problem-33)
* [Count Balanced Binary Trees of Height h](#Problem-34)
* [LargestSum Contiguous Subarray [V>V>V>V IMP ]](#Problem-35)
* [Smallest sum contiguous subarray](#Problem-36)
* [Unbounded Knapsack (Repetition of items allowed)](#Problem-37)
* [Word Break Problem](#Problem-38)
* [Largest Independent Set Problem](#Problem-39)
* [Partition Equal Subset Sum](#Problem-40)
* [Longest Palindromic Subsequence](#Problem-41)
* [Count All Palindromic Subsequence in a given String](#Problem-42)
* [5. Longest Palindromic Substring](#Problem-43)
* [Longest alternating subsequence](#Problem-44)
* [Weighted Job Scheduling](#Problem-45)
* [Coin game winner where every player has three choices](#Problem-46)
* [Count Derangements (Permutation such that no element appears in its original position) [ IMPORTANT ]](#Problem-47)
* [Maximum profit by buying and selling a share at most twice [ IMP ]](#Problem-48)
* [Optimal Strategy For A Game](#Problem-49)
* [Optimal Binary Search Tree](#Problem-50)
* [Palindrome PartitioningProblem](#Problem-51)
* [Word Wrap Problem](#Problem-52)
* [Mobile Numeric Keypad Problem [ IMP ]](#Problem-53)
* [Boolean Parenthesization Problem](#Problem-54)
* [Largest rectangular sub-matrix whose sum is 0](#Problem-55)
* [Largest area rectangular sub-matrix with equal number of 1’s and 0’s [ IMP ]](#Problem-56)
* [Maximum sum rectangle in a 2D matrix](#Problem-57)
* [Maximum profit by buying and selling a share at most k times](#Problem-58)
* [Find if a string is interleaved of two other strings](#Problem-59)
* [646. Maximum Length of Pair Chain](#Problem-60)
  
  
  
  
  # Love Babbar Sheet 450 - Dynamic Programming
  ## Problem 1:
  **[Coin ChangeProblem](https://practice.geeksforgeeks.org/problems/coin-change2448/1)**<br />
  Given a value `N`, find the number of ways to make change for `N` cents, if we have infinite supply of each of `S = { S1, S2, .. , SM }` valued coins.<br />

  >Example 1:<br />
  Input:<br />
  n = 4 , m = 3<br />
  S[] = {1,2,3}<br />
  Output: 4<br />
  Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.<br />

  >Example 2:<br />
  Input:<br />
  n = 10 , m = 4<br />
  S[] ={2,5,3,6}<br />
  Output: 5<br />
  Explanation: Five Possible ways are: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.<br />

  **Your Task:**<br />
  You don't need to read input or print anything. Your task is to complete the function `count()` which accepts an array `S[]` its size `m` and `n` as input parameter and returns the number of ways to make change for `N` cents.<br />

  <pre>
  Expected Time Complexity: O(m*n).
  Expected Auxiliary Space: O(n).
  </pre>

  * Constraints: `1 <= n,m <= 10^3`<br />

  ```cpp
  #include<bits/stdc++.h>
  using namespace std;

  class Solution {
    public:
      long long int count(int S[], int m, int n) {
          long long int table[n + 1];
          memset(table, 0, sizeof(table));
          table[0] = 1;
          for (int i = 0; i < m; i++)
              for (int j = S[i]; j <= n; j++) table[j] += table[j - S[i]];

          return table[n];

      }
  };

  int main(){
      int t;
      cin>>t;
      while(t--){
          int n,m;
          cin>>n>>m;
          int arr[m];
          for(int i=0;i<m;i++)cin>>arr[i];
          Solution ob;
          cout<<ob.count(arr,m,n)<<endl;
      }
      return 0;
  }
  ```
* [To top](#Table-of-Content)




  <br /><br /><br />
  ## Problem 2:
  **[Knapsack Problem](https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)**<br />
  You are given weights and values of `N` items, put these items in a knapsack of capacity `W` to get the maximum total value in the knapsack. Note that we have only one quantity of each item.<br />
  In other words, given two integer arrays `val[0..N-1]` and `wt[0..N-1]` which represent values and weights associated with `N` items respectively. Also given an integer `W` which represents knapsack capacity, find out the maximum value subset of `val[]` such that sum of the weights of this subset is smaller than or equal to `W`. You cannot break an item, either pick the complete item or dont pick it (0-1 property).<br />

  >Example 1:<br />
  Input:<br />
  N = 3<br />
  W = 4<br />
  values[] = {1,2,3}<br />
  weight[] = {4,5,1}<br />
  Output: 3<br />

  >Example 2:<br />
  Input:<br />
  N = 3<br />
  W = 3<br />
  values[] = {1,2,3}<br />
  weight[] = {4,5,6}<br />
  Output: 0<br />

  **Your Task:**<br />
  Complete the function `knapSack()` which takes maximum capacity `W`, weight array `wt[]`, value array `val[]`, and the number of items `n` as a parameter and returns the maximum possible value you can get.<br />

  <pre>
  Expected Time Complexity: O(N*W).
  Expected Auxiliary Space: O(N*W)
  </pre>

  * Constraints: `1 ≤ N ≤ 1000`<br />
  `1 ≤ W ≤ 1000`<br />
  `1 ≤ wt[i] ≤ 1000`<br />
  `1 ≤ v[i] ≤ 1000`<br />

  ```cpp
  #include<bits/stdc++.h>
  using namespace std;

  class Solution
  {
      public:
      int knapSack(int W, int wt[], int val[], int n) 
      { 
         // Your code here
         int grid[n+1][W+1];
         for(int i=0;i<=n;i++){
             for(int j=0;j<=W;j++){
                 if(i==0 || j==0)grid[i][j] = 0;
                 else if(wt[i-1]<=j)grid[i][j] = max(val[i-1]+grid[i-1][j-wt[i-1]],grid[i-1][j]);
                 else grid[i][j] = grid[i-1][j];
             }
         }
         return grid[n][W];
      }
  };

  int main(){
      int t;
      cin>>t;
      while(t--){
          int n, w;
          cin>>n>>w;
          int val[n];
          int wt[n];
          for(int i=0;i<n;i++)cin>>val[i];
          for(int i=0;i<n;i++)cin>>wt[i];
          Solution ob;
          cout<<ob.knapSack(w,wt,val,n)<<endl;
      }
      return 0;
  }
  ```
* [To top](#Table-of-Content)




  <br /><br /><br />
  ## Problem 3:
  **[Binomial CoefficientProblem](https://practice.geeksforgeeks.org/problems/ncr1019/1)**<br />
  Given two integers `n` and `r`, find `nCr`. Since the answer may be very large, calculate the answer modulo `10^9+7`.<br />

  >Example 1:<br />
  Input: n = 3, r = 2<br />
  Output: 3<br />
  Explaination: 3C2 = 3. <br />

  >Example 2:<br />
  Input: n = 2, r = 4<br />
  Output: 0<br />
  Explaination: r is greater than n.<br />

  **Your Task:**<br />
  You do not need to take input or print anything. Your task is to complete the function `nCr()` which takes `n` and `r` as input parameters and returns `nCr` modulo 10^9+7..<br />

  <pre>
  Expected Time Complexity: O(n*r)
  Expected Auxiliary Space: O(r)
  </pre>

  * Constraints: `1 ≤ n ≤ 1000`<br />
  `1 ≤ r ≤ 800`<br />

  ```cpp
  #include<bits/stdc++.h>
  using namespace std;

  class Solution{
  public:
      int nCr(int n, int r){
          int mod = 1000000007;
          int c[r+1];
          memset(c, 0, sizeof(c));
          c[0] = 1;
          for(int i = 1;i<=n;i++){
              for(int j = min(i, r); j>0;j--)c[j]=(c[j]+c[j-1])%mod;
          }
          return c[r]%mod;
      }
  };

  int main(){
      int t; cin>>t;
      while(t--){
          int n, r;
          cin>>n>>r;
          Solution ob;
          cout<<ob.nCr(n, r)<<endl;
      }
      return 0;
  }
  ```
* [To top](#Table-of-Content)




  <br /><br /><br />
  ## Problem 4:
  **[Permutation CoefficientProblem](https://www.geeksforgeeks.org/permutation-coefficient/)**<br />
  Permutation refers to the process of arranging all the members of a given set to form a sequence. The number of permutations on a set of `n` elements is given by `n!` , where `“!”` represents factorial.<br /> 
  The **Permutation Coefficient** represented by `P(n, k)` is used to represent the number of ways to obtain an ordered subset having `k` elements from a set of `n` elements.<br />
  Mathematically it’s given as:<br />
  <img src = "https://www.geeksforgeeks.org/wp-content/uploads/Permutation_coefficient.png"><br />
  **Examples :**<br />
  <pre>
  P(10, 2) = 90
  P(10, 3) = 720
  P(10, 0) = 1
  P(10, 1) = 10
  </pre>
  The coefficient can also be computed `recursively` using the below recursive formula:<br />
  <pre>
  P(n, k) = P(n-1, k) + k* P(n-1, k-1)
  </pre>
  If we observe closely, we can analyze that the problem has overlapping substructure, hence we can apply dynamic programming here. Below is a program implementing the same idea.<br />
  ```cpp
  // C++ program of the above approach
  #include <bits/stdc++.h>
  using namespace std;

  // A Dynamic Programming based
  // solution that uses table P[][]
  // to calculate the Permutation
  // Coefficient
  #include<bits/stdc++.h>

  // Returns value of Permutation
  // Coefficient P(n, k)
  int permutationCoeff(int n, int k)
  {
    int P[n + 1][k + 1];

    // Calculate value of Permutation
    // Coefficient in bottom up manner
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= std::min(i, k); j++)
      {
        // Base Cases
        if (j == 0)
          P[i][j] = 1;

        // Calculate value using
        // previously stored values
        else
          P[i][j] = P[i - 1][j] + (j * P[i - 1][j - 1]);

        // This step is important
        // as P(i,j)=0 for j>i
        P[i][j + 1] = 0;
      }
    }
    return P[n][k];
  }


  // Driver Code
  int main()
  {
    int n = 10, k = 2;
    cout << "Value of P(" << n <<" " << k<< ") is " << permutationCoeff(n, k);
    return 0;
  }
  ```
  Output :<br />
  <pre>
  Value of P(10, 2) is 90 
  </pre>
  <pre>
  time complexity is O(n*k)
  space complexity is O(n*k) as the program uses an auxiliary matrix to store the result.
  </pre>
  <br />**Can we do it in O(n) time ?**<br />
  Let us suppose we maintain a single `1D` array to compute the factorials up to `n`. We can use computed factorial value and apply the formula `P(n, k) = n! / (n-k)!`. Below is a program illustrating the same concept.<br />
  ```cpp
  // A O(n) solution that uses
  // table fact[] to calculate
  // the Permutation Coefficient
  #include<bits/stdc++.h>
  using namespace std;

  // Returns value of Permutation
  // Coefficient P(n, k)
  int permutationCoeff(int n, int k)
  {
    int fact[n + 1];

    // Base case
    fact[0] = 1;

    // Calculate value
    // factorials up to n
    for(int i = 1; i <= n; i++)
    fact[i] = i * fact[i - 1];

    // P(n,k) = n! / (n - k)!
    return fact[n] / fact[n - k];
  }

  // Driver Code
  int main()
  {
    int n = 10, k = 2;

    cout << "Value of P(" << n << ", " 	<< k << ") is " << permutationCoeff(n, k);

    return 0;
  }
  ```
  Output :<br />
  <pre>
  Value of P(10, 2) is 90 
  </pre>
  **A O(n) time and O(1) Extra Space Solution**<br />
  ```cpp
  // A O(n) time and O(1) extra
  // space solution to calculate
  // the Permutation Coefficient
  #include <iostream>
  using namespace std;

  int PermutationCoeff(int n, int k)
  {
    int P = 1;
    // Compute n*(n-1)*(n-2)....(n-k+1)
    for (int i = 0; i < k; i++)
      P *= (n-i) ;

    return P;
  }

  // Driver Code
  int main()
  {
    int n = 10, k = 2;
    cout << "Value of P(" << n << ", " << k << ") is " << PermutationCoeff(n, k);

    return 0;
  }
  ```
  Output :<br />
  <pre>
  Value of P(10, 2) is 90 
  </pre>
* [To top](#Table-of-Content)









  <br /><br /><br />
  ## Problem 5:
  **[Program for nth Catalan Number](https://www.geeksforgeeks.org/program-nth-catalan-number/)**<br />
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.<br />

 1. Count the number of expressions containing `n` pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).<br />
 2. Count the number of possible Binary Search Trees with `n` keys (See this)<br />
 3. Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with `n+1` leaves.<br />
 4. Given a number `n`, return the number of ways you can draw `n` chords in a circle with `2 x n` points such that no `2` chords intersect.<br />

The first few **Catalan** **numbers** for n = **0**, **1**, **2**, **3**, … are **1**, **1**, **2**, **5**, **14**, **42**, **132**, **429**, **1430**, **4862**, …<br />
**Recursive Solution**<br />
Catalan numbers satisfy the following recursive formula.<br />
<img src ="https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-6e37684751c57a980ebaca5148b4736a_l3.svg"><br />
Following is the implementation of above recursive formula.<br />
```cpp
#include <iostream>
using namespace std;

// A recursive function to find nth catalan number
unsigned long int catalan(unsigned int n)
{
	// Base case
	if (n <= 1)
		return 1;

	// catalan(n) is sum of
	// catalan(i)*catalan(n-i-1)
	unsigned long int res = 0;
	for (int i = 0; i < n; i++)
		res += catalan(i)
			* catalan(n - i - 1);

	return res;
}

// Driver code
int main()
{
	for (int i = 0; i < 10; i++)
		cout << catalan(i) << " ";
	return 0;
}
```
Output<br />
<pre>
1 1 2 5 14 42 132 429 1430 4862
</pre>
**Time complexity** of above implementation is equivalent to nth catalan number.<br />
<img src = "https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-467610e1e86e6ec3692f997c58edc674_l3.svg"><br />
The value of `nth` catalan number is exponential that makes the `time complexity exponential`.<br /><br />
**Dynamic Programming Solution :** We can observe that the above `recursive implementation` does a lot of repeated work (we can the same by drawing recursion tree). Since there are overlapping subproblems, we can use dynamic programming for this. Following is a Dynamic programming based implementation .<br />
```cpp
#include <iostream>
using namespace std;

// A dynamic programming based function to find nth
// Catalan number
unsigned long int catalanDP(unsigned int n)
{
	// Table to store results of subproblems
	unsigned long int catalan[n + 1];

	// Initialize first two values in table
	catalan[0] = catalan[1] = 1;

	// Fill entries in catalan[] using recursive formula
	for (int i = 2; i <= n; i++) {
		catalan[i] = 0;
		for (int j = 0; j < i; j++)
			catalan[i] += catalan[j] * catalan[i - j - 1];
	}

	// Return last entry
	return catalan[n];
}

int main()
{
	for (int i = 0; i < 10; i++)
		cout << catalanDP(i) << " ";
	return 0;
}
```
Output<br />
<pre>
1 1 2 5 14 42 132 429 1430 4862 
</pre>
<pre>
Time Complexity: Time complexity of above implementation is O(n^2)
</pre>
<br /><br />**Using Binomial Coefficient**<br />
We can also use the below formula to find `nth` `Catalan number` in `O(n)` time.<br />
<img src = "https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-e9e29f26617b6b4aef67b50ee86a58e5_l3.svg"><br />
```cpp
// C++ program for nth Catalan Number
#include <iostream>
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
	unsigned long int res = 1;

	// Since C(n, k) = C(n, n-k)
	if (k > n - k)
		k = n - k;

	// Calculate value of [n*(n-1)*---*(n-k+1)] /
	// [k*(k-1)*---*1]
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}

// A Binomial coefficient based function to find nth catalan
// number in O(n) time
unsigned long int catalan(unsigned int n)
{
	// Calculate value of 2nCn
	unsigned long int c = binomialCoeff(2 * n, n);

	// return 2nCn/(n+1)
	return c / (n + 1);
}

// Driver code
int main()
{
	for (int i = 0; i < 10; i++)
		cout << catalan(i) << " ";
	return 0;
}
```
Output<br />
<pre>
1 1 2 5 14 42 132 429 1430 4862 
</pre>
<pre>
Time Complexity: Time complexity of above implementation is O(n).
</pre>
We can also use below formulas to find nth catalan number in `O(n)` time.<br /> 
<img src = "https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-20b153005f07a02278f1302f9bf5bfe8_l3.svg"><br />
<br /><br />**Use multi-precision library:**<br />
In this method, we have used boost `multi-precision library`, and the motive behind its use is just only to have precision meanwhile finding the large CATALAN’s number and a generalized technique using for loop to calculate Catalan numbers .<br />
<pre>
For example: N = 5

Initially set cat_=1 then, print cat_  ,

then, iterate from i = 1 to i < 5

for i = 1; cat_ = cat_ * (4*1-2)=1*2=2
cat_ = cat_ / (i+1)=2/2 = 1      

For i = 2; cat_ = cat_ * (4*2-2)=1*6=6
cat_ = cat_ / (i+1)=6/3=2  

For i = 3 :-      cat_ = cat_ * (4*3-2)=2*10=20
cat_ = cat_ / (i+1)=20/4=5   

For i = 4 :-      cat_ = cat_ * (4*4-2)=5*14=70
 cat_ = cat_ / (i+1)=70/5=14     
</pre>
**Pseudocode:**<br />
<pre>
a) initially set cat_=1 and print it
b) run a for loop i=1 to i<=n
            cat_ *= (4*i-2)
            cat_ /= (i+1)
            print cat_
c) end loop and exit   
</pre>
```cpp
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;

// Function to print the number
void catalan(int n)
{
	cpp_int cat_ = 1;

	// For the first number
	cout << cat_ << " "; // C(0)

	// Iterate till N
	for (cpp_int i = 1; i <=n; i++)
	{
		// Calculate the number
		// and print it
		cat_ *= (4 * i - 2);
		cat_ /= (i + 1);
		cout << cat_ << " ";
	}
}

// Driver code
int main()
{
	int n = 5;

	// Function call
	catalan(n);
	return 0;
}
```
Output<br />
<pre>
1 1 2 5 14
</pre>
<pre>
Time Complexity: O(n)
Auxiliary Space: O(1), since no extra space has been taken.
</pre>
<br /><br />**Another solution using BigInteger in java:**<br />

 * Finding values of catalan numbers for `N>80` is not possible even by using long in java, so we use BigInteger<br />
 * Here we find solution using Binomial Coefficient method as discussed above<br />

```java
import java.io.*;
import java.util.*;
import java.math.*;

class GFG
{
	public static BigInteger findCatalan(int n)
	{
		// using BigInteger to calculate large factorials
		BigInteger b = new BigInteger("1");

		// calculating n!
		for (int i = 1; i <= n; i++) {
			b = b.multiply(BigInteger.valueOf(i));
		}

		// calculating n! * n!
		b = b.multiply(b);

		BigInteger d = new BigInteger("1");

		// calculating (2n)!
		for (int i = 1; i <= 2 * n; i++) {
			d = d.multiply(BigInteger.valueOf(i));
		}

		// calculating (2n)! / (n! * n!)
		BigInteger ans = d.divide(b);

		// calculating (2n)! / ((n! * n!) * (n+1))
		ans = ans.divide(BigInteger.valueOf(n + 1));
		return ans;
	}

	// Driver Code
	public static void main(String[] args)
	{
		int n = 5;
		System.out.println(findCatalan(n));
	}
}
```
Output<br />
<pre>
42
</pre>
<pre>
Time Complexity: O(n)
Auxiliary Space: O(1), since no extra space has been taken.
</pre>
* [To top](#Table-of-Content)











<br /><br /><br />
  ## Problem 6:
  **[Matrix Chain Multiplication](https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/)**<br />
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.<br />
We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have:<br />
<pre>
(ABC)D = (AB)(CD) = A(BCD) = ....
</pre>
However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, suppose `A is a 10 × 30` matrix, `B is a 30 × 5` matrix, and `C is a 5 × 60` matrix. Then,<br />
<pre>
(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
</pre>
Clearly the first parenthesization requires less number of operations.<br />
_Given an array `p[]` which represents the chain of matrices such that the ith matrix `Ai` is of dimension `p[i-1] x p[i]`. We need to write a function `MatrixChainOrder()` that should return the minimum number of multiplications needed to multiply the chain._<br />
<pre>
Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000  
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

Input: p[] = {10, 20, 30, 40, 30} 
Output: 30000 
There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

Input: p[] = {10, 20, 30}  
Output: 6000  
There are only two matrices of dimensions 10x20 and 20x30. So there 
is only one way to multiply the matrices, cost of which is 10*20*30
</pre>
<br /><br />**1) Optimal Substructure:**<br />
A simple solution is to place parenthesis at all possible places, calculate the cost for each placement and return the minimum value. In a chain of matrices of size `n`, we can place the first set of parenthesis in `n-1` ways. For example, if the given chain is of `4` matrices. let the chain be `ABCD`, then there are `3` ways to place first set of parenthesis outer side: `(A)(BCD), (AB)(CD) and (ABC)(D)`. So when we place a set of parenthesis, we divide the problem into subproblems of smaller size. Therefore, the problem has optimal substructure property and can be easily solved using recursion.<br />
Minimum number of multiplication needed to multiply a chain of size `n = Minimum of all n-1 placements` (these placements create subproblems of smaller size)<br />
<br /><br />**2) Overlapping Subproblems**<br />
Following is a `recursive implementation` that simply follows the above optimal substructure property.<br />
Below is the implementation of the above idea:<br />
```cpp
/* A naive recursive implementation that simply
follows the above optimal substructure property */
#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	// place parenthesis at different places
	// between first and last matrix, recursively
	// calculate count of multiplications for
	// each parenthesis placement and return the
	// minimum count
	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	// Return minimum count
	return min;
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, 1, n - 1);
}
```
Output<br />
<pre>
Minimum number of multiplications is 30
</pre>
The time complexity of the above naive `recursive approach` is `exponential`. It should be noted that the above function computes the same subproblems again and again. See the following `recursion tree` for a matrix chain of size `4`. The function `MatrixChainOrder(p, 3, 4)` is called two times. We can see that there are many subproblems being called more than once.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/matrixchainmultiplication.png"><br />
Since same subproblems are called again, this problem has `Overlapping Subproblems` property. So Matrix Chain Multiplication problem has both properties (see this and this) of a `dynamic programming problem`. Like other typical `Dynamic Programming(DP)` problems, recomputations of same subproblems can be avoided by constructing a temporary array m[][] in bottom up manner.<br />
<br /><br />**Dynamic Programming Solution**<br />
Following is the implementation of the Matrix Chain Multiplication problem using `Dynamic Programming (Tabulation vs Memoization)`<br />
**Using Memoization –**<br />
```cpp
// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

// Function for matrix chain multiplication
int matrixChainMemoised(int* p, int i, int j)
{
	if (i == j)
	{
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	dp[i][j] = INT_MAX;
	for (int k = i; k < j; k++)
	{
		dp[i][j] = min(
			dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
	}
	return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
	int i = 1, j = n - 1;
	return matrixChainMemoised(p, i, j);
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(dp, -1, sizeof dp);
	cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, n);
}
```
Output<br />
<pre>
Minimum number of multiplications is 18
</pre>
<pre>
Time Complexity: O(n^3)
Auxiliary Space: O(n^2) ignoring recursion stack space
</pre>
<br /><br />**Using Tabulation –**<br />
```cpp
// See the Cormen book for details of the
// following algorithm
#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
int MatrixChainOrder(int p[], int n)
{

	/* For simplicity of the program, one
	extra row and one extra column are
	allocated in m[][]. 0th row and 0th
	column of m[][] are not used */
	int m[n][n];

	int i, j, k, L, q;

	/* m[i, j] = Minimum number of scalar
	multiplications needed to compute the
	matrix A[i]A[i+1]...A[j] = A[i..j] where
	dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying
	// one matrix.
	for (i = 1; i < n; i++)
		m[i][i] = 0;

	// L is chain length.
	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				// q = cost/scalar multiplications
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1];
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, size);
	getchar();
	return 0;
}
```
Output<br />
<pre>
Minimum number of multiplications is 18
</pre>
<pre>
Time Complexity: O(n^3)
Auxiliary Space: O(n^2)
</pre>
* [To top](#Table-of-Content)



  <br /><br /><br />
  ## Problem 7:
  **[Edit Distance](https://practice.geeksforgeeks.org/problems/edit-distance3702/1)**<br />
Given two strings `s` and `t`. Return the minimum number of operations required to convert `s` to `t`.<br />
The possible operations are permitted:<br />

 1. Insert a character at any position of the string.<br />
 2. Remove any character from the string.<br />
 3. Replace any character from the string with any other character.<br />
 
>Example 1:<br />
Input: <br />
s = "geek", t = "gesek"<br />
Output: 1<br />
Explanation: One operation is required inserting 's' between two 'e's of str1.<br />

>Example 2:<br />
Input : <br />
s = "gfg", t = "gfg"<br />
Output: <br />
0<br />
Explanation: Both strings are same.<br />
 
**Your Task:**<br />
You don't need to read or print anything. Your task is to complete the function `editDistance()` which takes strings `s` and `t` as input parameters and returns the minimum number of operation to convert the string `s` to string `t`. <br />

<pre>
Expected Time Complexity: O(|s|*|t|)
Expected Space Complexity: O(|s|*|t|)
</pre>

* Constraints: `1 ≤ Length of both strings ≤ 100`<br />
Both the strings are in lowercase.<br />
  
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dp[102][102];
    int fun(string s, string t, int pos1, int pos2){
        if(pos1 == 0)return pos2;
        if(pos2 == 0)return pos1;
        int &ans = dp[pos1][pos2];
        if(ans != -1)return ans;
        if(s[pos1 - 1] == t[pos2-1])return ans = fun(s,t,pos1-1,pos2-1);
        return ans = min({1+fun(s, t, pos1, pos2-1),
                          1+fun(s, t, pos1-1, pos2),
                          1+fun(s, t, pos1-1, pos2-1)
        });
    }
    int editDistance(string s, string t){
        memset(dp, -1, sizeof(dp));
        int ans = fun(s, t, s.size(), t.size());
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s, t;
        cin>>s>>t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout<<ans<<endl;
    }
    return 0;
}
```
  * [To top](#Table-of-Content)
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  <br /><br /><br />
  ## Problem 8:
  **[Partition Equal Subset Sum / Subset Sum Problem](https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1)**<br />
Given an array `arr[]` of size `N`, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.<br />

>Example 1:<br />
Input: N = 4<br />
arr = {1, 5, 11, 5}<br />
Output: YES<br />
Explanation: The two parts are {1, 5, 5} and {11}.<br />

>Example 2:<br />
Input: N = 3<br />
arr = {1, 3, 5}<br />
Output: NO<br />
Explanation: This array can never be partitioned into two such parts.<br />

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `equalPartition()` which takes the value `N` and the `array` as input parameters and returns `1` if the partition is possible. Otherwise, returns `0`.<br />

<pre>
Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)
</pre>

* Constraints: `1 ≤ N ≤ 100`<br />
`1 ≤ arr[i] ≤ 1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int N, int arr[]){
      int sum =0;
        for(int i=0;i<N;i++)
        sum = sum+arr[i];
       
        return (sum%2==0) && solve(arr, sum/2, N);
        
    }
private:
    int sum = 0;
    
    bool solve(int arr[], int sum, int n){
        bool dp[n+1][sum + 1];
        
        for(int i=0;i<=n;i++) dp[i][0] = true; //subset with 0 sum
        
        for(int j=1;j<=sum;j++) dp[0][j] = false; //non-zero sum with 0 elements
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1] > j) dp[i][j] = dp[i-1][j]; //don't include ith element if it's greater then the rem sum
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
               
            }
        }
        
        return dp[n][sum];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        if(ob.equalPartition(n, arr))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)









  <br /><br /><br />
  ## Problem 9:
  **[Friends Pairing Problem](https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1)**<br />
Given `N` friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.<br />
**Note:** Since answer can be very large, return your answer mod `10^9+7`.<br />

>Example 1:<br />
Input:N = 3<br />
Output: 4<br />
Explanation:<br />
{1}, {2}, {3} : All single<br />
{1}, {2,3} : 2 and 3 paired but 1 is single.<br />
{1,2}, {3} : 1 and 2 are paired but 3 is single.<br />
{1,3}, {2} : 1 and 3 are paired but 2 is single.<br />
Note that {1,2} and {2,1} are considered same.<br />

>Example 2: <br />
Input: N = 2<br />
Output: 2<br />
Explanation:<br />
{1} , {2} : All single.<br />
{1,2} : 1 and 2 are paired.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `countFriendsPairings()` which accepts an integer `n` and return number of ways in which friends can remain single or can be paired up.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ N ≤ 10^4`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countFriendsPairings(int n){ 
        long long m = 1000000007;
        long long a = 1, b = 2, c = 0;
        if(n<=2)return n;
        for(int i = 3;i<=n;i++){
            c = (b%m +(((i-1)%m * a%m) %m) %m) %m;
            a = b;
            b = c;
        }
        return c;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Solution ob;
        cout<<ob.countFriendsPairings(n)<<endl;
    }
}
```
* [To top](#Table-of-Content)









  <br /><br /><br />
  ## Problem 10:
  **[Gold Mine Problem](https://www.geeksforgeeks.org/gold-mine-problem/)**<br />
Given a gold mine of `n*m` dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only `(right->,right up /,right down\)` that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect.<br /> 
**Examples:**<br />
<pre>
Input : mat[][] = {{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
Output : 12 
{(1,0)->(2,1)->(1,2)}

Input: mat[][] = { {1, 3, 1, 5},
                   {2, 2, 4, 1},
                   {5, 0, 2, 3},
                   {0, 6, 1, 2}};
Output : 16
(2,0) -> (1,1) -> (1,2) -> (0,3) OR
(2,0) -> (3,1) -> (2,2) -> (2,3)

Input : mat[][] = {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
Output : 83
</pre>
<br /><br />`Method 1: Recursion`<br />
A simple method that is a `direct recursive` implementation<br />
```cpp
// C++ program to solve Gold Mine problem
#include<bits/stdc++.h>
using namespace std;

int collectGold(vector<vector<int>> gold, int x, int y, int n, int m) {

	// Base condition.
	if ((x < 0) || (x == n) || (y == m)) {
		return 0;
	}


	// Right upper diagonal
	int rightUpperDiagonal = collectGold(gold, x - 1, y + 1, n, m);

	// right
	int right = collectGold(gold, x, y + 1, n, m);

	// Lower right diagonal
	int rightLowerDiagonal = collectGold(gold, x + 1, y + 1, n, m);

	// Return the maximum and store the value
	return gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right);
}

int getMaxGold(vector<vector<int>> gold, int n, int m)
{
	int maxGold = 0;

	for (int i = 0; i < n; i++) {

		// Recursive function call for ith row.
		int goldCollected = collectGold(gold, i, 0, n, m);
		maxGold = max(maxGold, goldCollected);
	}

	return maxGold;
}

// Driver Code
int main()
{
	vector<vector<int>> gold { {1, 3, 1, 5},
		                   {2, 2, 4, 1},
		                   {5, 0, 2, 3},
				   {0, 6, 1, 2}
	};
	int m = 4, n = 4;
	cout << getMaxGold(gold, n, m);
	return 0;
}
```
Output<br />
<pre>
16
</pre>
<pre>
Time complexity: O(3^N*M)
Auxiliary Space: O(N*M)
</pre>
<br /><br />**Method 2: Memoization**<br />
**Bottom-Up Approach:** The second way is to take an extra space of size `m*n` and start computing values of states of `right`, `right upper diagonal`, and `right bottom diagonal` and store it in the `2d array`.<br />
```cpp
// C++ program to solve Gold Mine problem
#include<bits/stdc++.h>
using namespace std;

int collectGold(vector<vector<int>> gold, int x, int y, int n, int m, vector<vector<int>> &dp) {

	// Base condition.
	if ((x < 0) || (x == n) || (y == m)) {
		return 0;
	}

	if(dp[x][y] != -1){
		return dp[x][y] ;
	}

	// Right upper diagonal
	int rightUpperDiagonal = collectGold(gold, x - 1, y + 1, n, m, dp);

	// right
	int right = collectGold(gold, x, y + 1, n, m, dp);

	// Lower right diagonal
	int rightLowerDiagonal = collectGold(gold, x + 1, y + 1, n, m, dp);

	// Return the maximum and store the value
	return dp[x][y] = gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right);
}

int getMaxGold(vector<vector<int>> gold, int n, int m)
{
	int maxGold = 0;
	// Initialize the dp vector
	vector<vector<int>> dp(n, vector<int>(m, -1)) ;
	for (int i = 0; i < n; i++) {

		// Recursive function call for ith row.
		int goldCollected = collectGold(gold, i, 0, n, m, dp);
		maxGold = max(maxGold, goldCollected);
	}

	return maxGold;
}

// Driver Code
int main()
{
	vector<vector<int>> gold { {1, 3, 1, 5},
				   {2, 2, 4, 1},
				   {5, 0, 2, 3},
			       	   {0, 6, 1, 2}
	};
	int m = 4, n = 4;
	cout << getMaxGold(gold, n, m);
	return 0;
}
```
Output<br />
<pre>
16
</pre>
<pre>
Time Complexity :O(m*n)
Space Complexity :O(m*n)
</pre>
<br /><br />**Method 3: Using Dp, Tabulation**<br />
Create a `2-D` matrix `goldTable[][]`) of the same as given matrix `mat[][]`. If we observe the question closely, we can notice following.<br />

 1. Amount of gold is positive, so we would like to cover maximum cells of maximum values under given constraints.<br />
 2. In every move, we move one step toward right side. So we always end up in last column. If we are at the last column, then we are unable to move right<br />

If we are at the `first` row or last column, then we are unable to move `right-up` so just assign `0` otherwise assign the value of `goldTable[row-1][col+1]` to `right_up`. If we are at the `last row` or `last column`, then we are unable to move `right down` so just assign `0` otherwise assign the value of `goldTable[row+1][col+1]` to `right up`.<br /> 
Now find the maximum of `right`, `right_up`, and `right_down` and then add it with that `mat[row][col]`. At last, find the maximum of all rows and first column and return it.<br />
```cpp
// C++ program to solve Gold Mine problem
#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

// Returns maximum amount of gold that can be collected
// when journey started from first column and moves
// allowed are right, right-up and right-down
int getMaxGold(int gold[][MAX], int m, int n)
{
	// Create a table for storing intermediate results
	// and initialize all cells to 0. The first row of
	// goldMineTable gives the maximum gold that the miner
	// can collect when starts that row
	int goldTable[m][n];
	memset(goldTable, 0, sizeof(goldTable));

	for (int col=n-1; col>=0; col--)
	{
		for (int row=0; row<m; row++)
		{
			// Gold collected on going to the cell on the right(->)
			int right = (col==n-1)? 0: goldTable[row][col+1];

			// Gold collected on going to the cell to right up (/)
			int right_up = (row==0 || col==n-1)? 0: goldTable[row-1][col+1];

			// Gold collected on going to the cell to right down (\)
			int right_down = (row==m-1 || col==n-1)? 0: goldTable[row+1][col+1];

			// Max gold collected from taking either of the
			// above 3 paths
			goldTable[row][col] = gold[row][col] + max(right, max(right_up, right_down));
													
		}
	}

	// The max amount of gold collected will be the max
	// value in first column of all rows
	int res = goldTable[0][0];
	for (int i=1; i<m; i++)
		res = max(res, goldTable[i][0]);
	return res;
}

// Driver Code
int main()
{
	int gold[MAX][MAX]= { {1, 3, 1, 5},
			      {2, 2, 4, 1},
			      {5, 0, 2, 3},
			      {0, 6, 1, 2}
	};
	int m = 4, n = 4;
	cout << getMaxGold(gold, m, n);
	return 0;
}
```
Output<br />
<pre>
16
</pre>
<pre>
Time Complexity :O(m*n) 
Space Complexity :O(m*n)
</pre>
* [To top](#Table-of-Content)








  <br /><br /><br />
  ## Problem 11:
  **[Assembly Line SchedulingProblem](https://www.geeksforgeeks.org/assembly-line-scheduling-dp-34/)**<br />
A car factory has two assembly lines, each with `n` stations. A station is denoted by `Si,j` where `i` is either `1` or `2` and indicates the assembly line the station is on, and `j` indicates the number of the station. The time taken per station is denoted by `ai,j`. Each station is dedicated to some sort of work like engine fitting, body fitting, painting, and so on. So, a car chassis must pass through each of the `n` stations in order before exiting the factory. The parallel stations of the two assembly lines perform the same task. After it passes through station `Si,j`, it will continue to station `Si,j+1` unless it decides to transfer to the other line. Continuing on the same line incurs no extra cost, but transferring from line `i` at station `j – 1` to station `j` on the other line takes time `ti,j`. Each assembly line takes an entry time `ei` and exit time `xi` which may be different for the two lines. Give an algorithm for computing the minimum time it will take to build a car chassis.<br />
The below figure presents the problem in a clear picture:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/AssembleScheduling1.png"><br />
The following information can be extracted from the problem statement to make it simpler:<br />

 * Two assembly lines, `1` and `2`, each with stations from `1` to `n`.<br />
 * A car chassis must pass through all stations from `1` to `n` in order(in any of the two assembly lines). i.e. it cannot jump from station `i` to station `j` if they are not at one move distance.<br />
 * The car chassis can move one station forward in the same line, or one station diagonally in the other line. It incurs an extra cost `ti, j` to move to station `j` from line `i`. No cost is incurred for movement in same line.<br />
 * The time taken in station `j` on line `i` is `ai, j`.<br />
 * `Si, j` represents a station `j` on line `i`.<br />
 
 Breaking the problem into smaller sub-problems:<br />
We can easily find the `ith` factorial if `(i-1)th` factorial is known. Can we apply the similar funda here?<br /> 
If the minimum time taken by the chassis to leave station `Si, j-1` is known, the minimum time taken to leave station `Si, j` can be calculated quickly by combining `ai, j` and `ti, j`.<br />
<pre>
T1(j) indicates the minimum time taken by the car chassis to leave station j on assembly line 1.
T2(j) indicates the minimum time taken by the car chassis to leave station j on assembly line 2.
</pre>
**Base cases:**<br /> 
The entry time `ei` comes into picture only when the car chassis enters the car factory.<br />
Time taken to leave the first station in line `1` is given by:<br />
<pre>
T1(1) = Entry time in Line 1 + Time spent in station S1,1 
T1(1) = e1 + a1,1 
Similarly, time taken to leave the first station in line 2 is given by: 
T2(1) = e2 + a2,1
</pre>
<br /><br />**Recursive Relations:**<br />
If we look at the problem statement, it quickly boils down to the below observations:<br />
The car chassis at station `S1,j` can come either from station `S1, j-1` or station `S2, j-1`.<br />
<pre>
Case #1: Its previous station is S1, j-1 
The minimum time to leave station S1,j is given by: 
T1(j) = Minimum time taken to leave station S1, j-1 + Time spent in station S1, j 
T1(j) = T1(j-1) + a1, j
</pre>
<pre>
Case #2: Its previous station is S2, j-1 
The minimum time to leave station S1, j is given by: 
T1(j) = Minimum time taken to leave station S2, j-1 + Extra cost incurred to change the assembly line + Time spent in station S1, j 
T1(j) = T2(j-1) + t2, j + a1, j
</pre>
<pre>
The minimum time T1(j) is given by the minimum of the two obtained in cases #1 and #2. 
T1(j) = min((T1(j-1) + a1, j), (T2(j-1) + t2, j + a1, j)) 

Similarly, the minimum time to reach station S2, j is given by: 
T2(j) = min((T2(j-1) + a2, j), (T1(j-1) + t1, j + a2, j))
</pre>
<pre>
The total minimum time taken by the car chassis to come out of the factory is given by: 
Tmin = min(Time taken to leave station Si,n + Time taken to exit the car factory) 
Tmin = min(T1(n) + x1, T2(n) + x2)
</pre>
<br /><br />Why dynamic programming?<br />
The above recursion exhibits overlapping sub-problems. There are two ways to reach station `S1, j`:<br />

 1. From station `S1, j-1`<br />
 2. From station `S2, j-1`<br />
 
So, to find the minimum time to leave station `S1, j` the minimum time to leave the previous two stations must be calculated(as explained in above recursion).<br />
Similarly, there are two ways to reach station `S2, j:`<br />

 1. From station `S2, j-1`<br />
 2. From station `S1, j-1`<br />
 
Please note that the minimum times to leave stations `S1, j-1` and `S2, j-1` have already been calculated.<br />
So, we need two tables to store the partial results calculated for each station in an assembly line. The table will be filled in a bottom-up fashion.<br />
**Note:**<br /> 
In this post, the word `“leave”` has been used in place of `“reach”` to avoid confusion. Since the car chassis must spend a fixed time in each station, the word leave suits better.<br />
**Implementation:**<br />
```cpp
// A C++ program to find minimum possible
// time by the car chassis to complete
#include <bits/stdc++.h>
using namespace std;
#define NUM_LINE 2
#define NUM_STATION 4

// Utility function to find a minimum of two numbers
int min(int a, int b)
{
	return a < b ? a : b;
}

int carAssembly(int a[][NUM_STATION], int t[][NUM_STATION], int *e, int *x)
{
	int T1[NUM_STATION], T2[NUM_STATION], i;

	// time taken to leave first station in line 1
	T1[0] = e[0] + a[0][0];
	
	// time taken to leave first station in line 2
	T2[0] = e[1] + a[1][0];

	// Fill tables T1[] and T2[] using the
	// above given recursive relations
	for (i = 1; i < NUM_STATION; ++i)
	{
		T1[i] = min(T1[i - 1] + a[0][i], T2[i - 1] + t[1][i] + a[0][i]);
		T2[i] = min(T2[i - 1] + a[1][i], T1[i - 1] + t[0][i] + a[1][i]);
	}

	// Consider exit times and return minimum
	return min(T1[NUM_STATION - 1] + x[0], T2[NUM_STATION - 1] + x[1]);
}

// Driver Code
int main()
{
	int a[][NUM_STATION] = {{4, 5, 3, 2}, {2, 10, 1, 4}};
	int t[][NUM_STATION] = {{0, 7, 4, 5}, {0, 9, 2, 8}};
	int e[] = {10, 12}, x[] = {18, 7};
	cout << carAssembly(a, t, e, x);

	return 0;
}
```
Output:<br />
<pre>
35
</pre>
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/AssembleScheduling.png"><br />
The bold line shows the path covered by the car chassis for given input values. We need only the last two values in the auxiliary arrays. So instead of creating two arrays, we can use two variables.<br />
```cpp
// A space optimized solution for
// assembly line scheduling
#include <bits/stdc++.h>
using namespace std;

int carAssembly(int a[][4], int t[][4], int *e, int *x)
{
	int first, second, i;

	// Time taken to leave first
	// station in line 1
	first = e[0] + a[0][0];
	
	// Time taken to leave first
	// station in line 2
	second = e[1] + a[1][0];

	// Fill tables T1[] and T2[] using the
	// above given recursive relations
	for(i = 1; i < 4; ++i)
	{
		int up = min(first + a[0][i], second + t[1][i] + a[0][i]);
		int down = min(second + a[1][i], first + t[0][i] + a[1][i]);
		first = up;
		second = down;
	}

	// Consider exit times and
	// return minimum
	return min(first + x[0], second + x[1]);
}

// Driver Code
int main()
{
	int a[][4] = { { 4, 5, 3, 2 }, { 2, 10, 1, 4 } };
	int t[][4] = { { 0, 7, 4, 5 }, { 0, 9, 2, 8 } };
	int e[] = { 10, 12 }, x[] = { 18, 7 };
	cout << carAssembly(a, t, e, x);

	return 0;
}
```
Output:<br />
<pre>
35
</pre>
* [To top](#Table-of-Content)










  <br /><br /><br />
  ## Problem 12:
  **[Painting the Fence](https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1)**<br />
Given a fence with `n` posts and `k` colors, find out the number of ways of painting the fence so that not more than two consecutive fences have the same colors.<br />Since the answer can be large return it modulo `10^9 + 7`.<br />

>Example 1:<br />
Input:<br />
N=3,  K=2 <br />
Output: 6<br />
Explanation: <br />
We have following possible combinations:<br />
<img src = "http://cdncontribute.geeksforgeeks.org/wp-content/uploads/paintFence.png"><br />

>Example 2:<br />
Input:<br />
N=2,  K=4<br />
Output: 16<br />

**Your Task:**<br />
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function `countWays()` that takes `n` and `k` as parameters and returns the number of ways in which the fence can be painted.(`modulo 10^9 + 7`)<br />

<pre.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
</pre.
 
* Constraints: `1 ≤ N ≤ 5000`<br />
`1 ≤ K ≤ 100`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long countWays(int n, int k){
        long long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = k;
        long long same = 0, diff = k;
        for (int i = 2; i <= n; i++)
        {
            same = diff;
            diff = dp[i-1] * (k-1);
            diff%=1000000007;
            dp[i] = (same + diff);
            dp[i]%=1000000007;
        }
        return dp[n];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        Solution ob;
        cout<<ob.countWays(n, k)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)







  <br /><br /><br />
  ## Problem 13:
  **[Maximize The Cut Segments](https://practice.geeksforgeeks.org/problems/cutted-segments1642/1)**<br />
Given an integer `N` denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either `x` , `y` or `z`. Here `x`, `y`, and `z` are integers.<br />
After performing all the cut operations, your total number of cut segments must be maximum.<br />

>Example 1:<br />
Input:<br />
N = 4<br />
x = 2, y = 1, z = 1<br />
Output: 4<br />
Explanation:Total length is 4, and the cut lengths are 2, 1 and 1.  We can make<br /> 
maximum 4 segments each of length 1.<br />

>Example 2:<br />
Input:<br />
N = 5<br />
x = 5, y = 3, z = 2<br />
Output: 2<br />
Explanation: Here total length is 5, and the cut lengths are 5, 3 and 2. We can<br />
make two segments of lengths 3 and 2.<br />

**Your Task:**<br />
You only need to complete the function `maximizeTheCuts()` that takes `n`, `x`, `y`, `z` as parameters and returns max number cuts.<br />

<pre>
Expected Time Complexity : O(N)
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1 <= N, x, y, z <= 10^4`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maximizeTheCuts(int n, int x, int y, int z){
        int arr[3];
        arr[0]=x;
        arr[1]=y;
        arr[2]=z;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int j=0;j<3;j++){
            for(int i=1;i<=n;i++){
                if(i==arr[j] or (i>arr[j] and dp[i-arr[j]]>0))dp[i]=max(dp[i-arr[j]]+1,dp[i]);
            }
        }
        return dp[n];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int x, y, z; cin>>x>>y>>z;
        Solution ob;
        cout<<ob.maximizeTheCuts(n, x, y, z)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)






  <br /><br /><br />
  ## Problem 14:
  **[Longest Common Subsequence](https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1)**<br />
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.<br />

>Example 1:<br />
Input:<br />
A = 6, B = 6<br />
str1 = ABCDGH<br />
str2 = AEDFHR<br />
Output: 3<br />
Explanation: LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.<br />

>Example 2:<br />
Input:<br />
A = 3, B = 2<br />
str1 = ABC<br />
str2 = AC<br />
Output: 2<br />
Explanation: LCS of "ABC" and "AC" is "AC" of length 2.<br />

**Your Task:**<br />
Complete the function `lcs()` which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.<br />

<pre>
Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)
</pre>

* Constraints: `1<=size(str1),size(str2)<=10^3`<br />

```cpp
#include<bits/stdc++.h>
const int mod = 1e9+7;
using namespace std;

class Solution
{
    public:
    int lcs(int x, int y, string s1, string s2){
        int dp[1001][1001];
        for(int i = 0;i<=x;i++){
            for(int j = 0;j<=y;j++){
                if(i==0 || j==0)dp[i][j] = 0;
                else if (s1[i-1] == s2[j-1])dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
};

int main(){
    int n, k, x, y;
    int t; cin>>t;
    while(t--){
        cin>>x>>y;
        string s1, s2;
        Solution ob;
        cout<<ob.lcs(x, y, s1, s2)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)







  <br /><br /><br />
  ## Problem 15:
  **[Longest Repeated Subsequence](https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1)**<br />
  
Given string `str`, find the length of the longest repeating subsequence such that it can be found `twice` in the given string.<br />
The two identified subsequences `A` and `B` can use the same `ith` character from string `str` if and only if that ith character has different indices in `A` and `B`. For example, `A` = `"xax"` and `B` = `"xax"` then the index of first `"x"` must be different in the original string for `A` and `B`.<br />

>Example 1:<br />
<pre>
Input:
str = "axxzxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
</pre>

>Example 2:<br />
<pre>
Input:
str = "axxxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x x y 
0 1 2 3 4

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 3  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
</pre>

**Your Task:**<br />
You don't need to read or print anything. Your task is to complete the **LongestRepeatingSubsequence()** which takes str as input parameter and returns the length of the longest repeating subsequnece.<br />

<pre>
Expected Time Complexity: O(n^2)
Expected Space Complexity: O(n^2)
</pre>

* Constraints: `1 <= |str| <= 10^3`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int LongestRepeatingSubsequence(string str){
            int n = str.length();
            int dp[n+1][n+1];
            for(int i = 0;i<=n;i++){
                for(int j = 0;j<=n;j++)dp[i][j] = 0;
            }
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    if(str[i-1] == str[j-1] && i!=j)dp[i][j] = 1 + dp[i-1][j-1];
                    else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
            return dp[n][n];
        }

};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
}
```
* [To top](#Table-of-Content)


  
  
  
  

  <br /><br /><br />
  ## Problem 16:
  **[Longest Increasing Subsequence](https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1)**<br />
Given an `array` of integers, find the length of the longest (strictly) increasing subsequence from the given array.<br />

>Example 1:<br />
Input:<br />
N = 16<br />
A[]={0,8,4,12,2,10,6,14,1,9,5<br />
     13,3,11,7,15}<br />
Output: 6<br />
Explanation:Longest increasing subsequence 0 2 6 9 13 15, which has length 6<br />

>Example 2:<br />
Input:<br />
N = 6<br />
A[] = {5,8,3,7,9,1}<br />
Output: 3<br />
Explanation:Longest increasing subsequence 5 7 9, with length 3<br />

**Your Task:**
Complete the function `longestSubsequence()` which takes the input `array` and its `size` as input parameters and returns the length of the longest increasing subsequence.<br />

<pre>
Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1 ≤ N ≤ 10^5`<br />
`0 ≤ A[i] ≤ 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int h, int value){
    if(value>arr[h])return h+1;
    while(h>l){
        int middle = (h+l)/2;
        if(arr[middle] == value)return middle;
        if(arr[middle] > value)h = middle;
        else l = middle+1;
    }
    return h;
}

class Solution{
    public:
    int longestSubsequence(int n, int a[]){
       int  lastIndex = 0, tail[n];
       tail[0] = a[0];
       for(int i = 1;i<n;i++){
           int index = binarySearch(tail, 0, lastIndex, a[i]);
           tail[index] = a[i];
           lastIndex = max(lastIndex, index);
       }
       return lastIndex+1;
    }
};

int main(){
    int t, n; cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.longestSubsequence(n, a)<<endl;
    }
}
```
* [To top](#Table-of-Content)




  <br /><br /><br />
  ## Problem 17:
  **[Space Optimized Solution of LCS](https://www.geeksforgeeks.org/space-optimized-solution-lcs/)**<br />
Given two `strings`, find the length of the longest subsequence present in both of them.<br /> 
**Examples:**<br /> 
<pre>
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
</pre>
We have discussed a [typical dynamic programming-based solution for LCS](https://github.com/singh7priyanshu/DSA/blob/main/dynamic%20programming/Longest%20Common%20Subsequence/README.md). We can optimize the space used by `LCS problem`. We know the recurrence relationship of the LCS problem is<br />
```cpp
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(string &X, string &Y)
{
	int m = X.length(), n = Y.length();
	int L[m+1][n+1];

	/* Following steps build L[m+1][n+1] in bottom up
	fashion. Note that L[i][j] contains length of
	LCS of X[0..i-1] and Y[0..j-1] */
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;

			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}

	/* L[m][n] contains length of LCS for X[0..n-1] and
	Y[0..m-1] */
	return L[m][n];
}
```
<br /><br />**How to find the length of LCS is O(n) auxiliary space?**<br />
One important observation in the above simple implementation is, in each iteration of the outer loop we only need values from all columns of the previous row. So there is no need to store all rows in our `DP matrix`, we can just store two rows at a time and use them. In that way, used space will be reduced from `L[m+1][n+1]` to `L[2][n+1]`. Below is the implementation of the above idea.<br />
```cpp
// Space optimized C++ implementation
// of LCS problem
#include<bits/stdc++.h>
using namespace std;

// Returns length of LCS
// for X[0..m-1], Y[0..n-1]
int lcs(string &X, string &Y)
{
	
	// Find lengths of two strings
	int m = X.length(), n = Y.length();

	int L[2][n + 1];

	// Binary index, used to
	// index current row and
	// previous row.
	bool bi;

	for (int i = 0; i <= m; i++)
	{
		
		// Compute current
		// binary index
		bi = i & 1;

		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[bi][j] = 0;

			else if (X[i-1] == Y[j-1])
				L[bi][j] = L[1 - bi][j - 1] + 1;

			else
				L[bi][j] = max(L[1 - bi][j], L[bi][j - 1]);
		}
	}

	// Last filled entry contains
	// length of LCS
	// for X[0..n-1] and Y[0..m-1]
	return L[bi][n];
}

// Driver code
int main()
{
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	printf("Length of LCS is %d\n", lcs(X, Y));
	return 0;
}
```
Output<br />
<pre>
Length of LCS is 4
</pre>
<pre>
Time Complexity : O(m*n) 
Auxiliary Space : O(n)
</pre>
**We can further improve the space complexity of above program**<br />
```python
def lcs(text1, text2):
	m, n = len(text1), len(text2)
	if m > n : text1, text2 = text2, text1
	dp = [0] * (n + 1)
	for c in text1:
		prev = 0
		for i, d in enumerate(text2):
			prev, dp[i + 1] = dp[i + 1], prev + 1 if c == d else max(dp[i], dp[i + 1])
	return dp[-1]
X = "AGGTAB"
Y = "GXTXAYB"

print("Length of LCS is", lcs(X, Y))
```
Output<br />
<pre>
Length of LCS is 4
</pre>
* [To top](#Table-of-Content)









  <br /><br /><br />
  ## Problem 18:
  **[LCS (Longest Common Subsequence) of three strings](https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1)**<br />
Given 3 strings `A`, `B` and `C`, the task is to find the longest common sub-sequence in all three given sequences.<br />

>Example 1:<br />
Input:<br />
A = "geeks", B = "geeksfor",<br /> 
C = "geeksforgeeks"<br />
Output: 5<br />
Explanation: "geeks"is the longest common subsequence with length 5.<br />

>Example 2:<br />
Input: <br />
A = "abcd", B = "efgh", C = "ijkl"<br />
Output: 0<br />
Explanation: There's no common subsequence in all the strings.<br />

**Your Task:**
You don't need to read input or print anything. Your task is to complete the function `LCSof3()` which takes the strings `A`, `B`, `C` and their lengths `n1`, `n2`, `n3` as input and returns the length of the longest common subsequence in all the 3 strings.<br />

<pre>
Expected Time Complexity: O(n1*n2*n3).
Expected Auxiliary Space: O(n1*n2*n3).
</pre>

* Constraints: `1<=n1, n2, n3<=20`<br />
 
```cpp
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main(){
    int t; cin>>t;
    while(t--){
        int n1, n2, n3; cin>>n1>>n2>>n3;
        string A, B, C; cin>>A>>B>>C;
        cout<<LCSof3(A, B, C, n1, n2, n3)<<endl;
    }
}

int memo[101][101][101];

int solve(string &A, string &B, string &C, int i, int j, int k, int n1, int n2, int n3){
    if(i == n1 || j == n2 || k == n3)return 0;
    if(memo[i][j][k] != -1)return memo[i][j][k];
    if(A[i] == B[j] && A[i] == C[k])return memo[i][j][k] = 1+solve(A, B, C, i+1, j+1, k+1, n1, n2, n3);
    return memo[i][j][k] = max({solve(A, B, C, i+1, j, k, n1, n2, n3),
                                solve(A, B, C, i, j+1, k, n1, n2, n3),
                                solve(A, B, C, i, j, k+1, n1, n2, n3),
                                solve(A, B, C, i+1, j+1, k, n1, n2, n3),
                                solve(A, B, C, i+1, j, k+1, n1, n2, n3),
                                solve(A, B, C, i, j+1, k+1, n1, n2, n3),
                            });
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3){
    for(int i = 0;i<n1;i++){
        for(int j = 0;j<n2;j++){
            for(int k = 0;k<n3;k++)memo[i][j][k] = -1;
        }
    }
    return solve(A, B, C, 0, 0, 0, n1, n2, n3);
}
```
  * [To top](#Table-of-Content)
  
  
  
  
  
  
  
  
  

  <br /><br /><br />
  ## Problem 19:
  **[Maximum Sum Increasing Subsequence](https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1)**<br />
Given an array of `n` positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence.<br /> 

>Example 1:<br />
Input: N = 5, arr[] = {1, 101, 2, 3, 100} <br />
Output: 106<br />
Explanation:The maximum sum of a increasing sequence is obtained from {1, 2, 3, 100}<br />

>Example 2:<br />
Input: N = 3, arr[] = {1, 2, 3}<br />
Output: 6<br />
Explanation:The maximum sum of a increasing sequence is obtained from {1, 2, 3}<br />

**Your Task:**  <br />
You don't need to read input or print anything. Complete the function `maxSumIS()` which takes `N` and array `arr` as input parameters and returns the maximum value.<br />

<pre>
Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1 ≤ N ≤ 10^3`<br />
`1 ≤ arr[i] ≤ 10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int maxSumIS(int arr[], int n)  {  
	    int i, j, max = 0, a[n];
	    for( i = 0;i<n;i++)a[i] = arr[i];
	    for( i = 1;i<n;i++){
	        for( j = 0;j<i;j++){
	            if(arr[i] > arr[j] && a[i] < (a[j]+arr[i]))a[i] = a[j]+arr[i];
	        }
	    }
	    for( i = 0;i<n;i++){
	        if(max<a[i])max = a[i];
	    }
	    return max;
	}  
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.maxSumIS(a, n)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)








  <br /><br /><br />
  ## Problem 20:
  **[Count all subsequences having product less than K](https://www.geeksforgeeks.org/count-subsequences-product-less-k/)**<br />
Given a positive array, find the number of subsequences having product smaller than or equal to K.<br />
**Examples:**<br />
<pre>
Input : [1, 2, 3, 4] 
        k = 10
Output :11 
Explanation: The subsequences are {1}, {2}, {3}, {4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {1, 2, 3}, {1, 2, 4}

Input  : [4, 8, 7, 2] 
         k = 50
Output : 9
</pre>
This problem can be solved using dynamic programming where `dp[i][j]` = number of subsequences having product less than `i` using first `j` terms of the array. Which can be obtained by : number of subsequences using `first j-1 terms +` number of subsequences that can be formed using `j-th term`.<br /> 
Below is the implementation of the above approach:<br />
```cpp
// CPP program to find number of subarrays having
// product less than k.
#include <bits/stdc++.h>
using namespace std;

// Function to count numbers of such subsequences
// having product less than k.
int productSubSeqCount(vector<int> &arr, int k)
{
	int n = arr.size();
	int dp[k + 1][n + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
	
			// number of subsequence using j-1 terms
			dp[i][j] = dp[i][j - 1];

			// if arr[j-1] > i it will surely make product greater
			// thus it won't contribute then
			if (arr[j - 1] <= i)

				// number of subsequence using 1 to j-1 terms
				// and j-th term
				dp[i][j] += dp[i/arr[j-1]][j-1] + 1;
		}
	}
	return dp[k][n];
}

// Driver code
int main()
{
	vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	int k = 10;
	cout << productSubSeqCount(A, k) << endl;
}
```
Output<br />
<pre>
11
</pre>
<pre>
Time Complexity: O(K*N)
Auxiliary Space: O(K*N)
</pre>
* [To top](#Table-of-Content)











  <br /><br /><br />
  ## Problem 21:
  **[Longest subsequence such that difference between adjacent is one](https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1)**<br />
Given an array `A[]` of size `N`, find the longest subsequence such that difference between adjacent elements is one.<br />

>Example 1:<br />
Input: N = 7<br />
A[] = {10, 9, 4, 5, 4, 8, 6}<br />
Output: 3<br />
Explaination: The three possible subsequences {10, 9, 8} , {4, 5, 4} and {4, 5, 6}.<br />

>Example 2:<br />
Input: N = 5<br />
A[] = {1, 2, 3, 4, 5}<br />
Output: 5<br />
Explaination: All the elements can be included in the subsequence.<br />

`Your Task:`<br />
You do not need to read input. Your task is to complete the function `longestSubseq()` which takes `N` and `A[]` as input parameters and returns the length of the longest such subsequence.<br />

<pre>
Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1 ≤ N ≤ 10^3`<br />
`1 ≤ A[i] ≤ 10^3`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestSubsequence(int N, int A[]){
        int dp[N];
        for(int i = 0;i<N;i++)dp[i] = 1;
        for(int i = 1;i<N;i++){
            for(int j = 0;j<i;j++){
                if(abs(A[i]-A[j])==1)dp[i]=max(dp[i], dp[j]+1);
            }
        }
        int ans = 1;
        for(int i = 0;i<N;i++)ans=max(ans, dp[i]);
        return ans;
    }
};


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.longestSubsequence(n, arr)<<endl;
    }
}
```
* [To top](#Table-of-Content)






  <br /><br /><br />
  ## Problem 22:
  **[Maximum subsequence sum such that no three are consecutive](https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/)**<br />
Given a sequence of `positive numbers`, find the maximum `sum` that can be formed which has `no three` consecutive elements present.<br />
**Examples :**<br /> 
<pre>
Input: arr[] = {1, 2, 3}
Output: 5
We can't take three of them, so answer is
2 + 3 = 5

Input: arr[] = {3000, 2000, 1000, 3, 10}
Output: 5013 
3000 + 2000 + 3 + 10 = 5013

Input: arr[] = {100, 1000, 100, 1000, 1}
Output: 2101
100 + 1000 + 1000 + 1 = 2101

Input: arr[] = {1, 1, 1, 1, 1}
Output: 4

Input: arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
Output: 27
</pre>
This problem is mainly an extension of below problem.<br />
[Maximum sum such that no two elements are adjacent](https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/)<br />
We maintain an auxiliary `array sum[]` (of same size as input array) to find the result.<br />
<pre>
sum[i] : Stores result for subarray arr[0..i], i.e.,
         maximum possible sum in subarray arr[0..i]
         such that no three elements are consecutive.

sum[0] = arr[0]

// Note : All elements are positive
sum[1] = arr[0] + arr[1]

// We have three cases
// 1) Exclude arr[2], i.e., sum[2] = sum[1]
// 2) Exclude arr[1], i.e., sum[2] = sum[0] + arr[2]
// 3) Exclude arr[0], i.e., sum[2] = arr[1] + arr[2] 
sum[2] = max(sum[1], arr[0] + arr[2], arr[1] + arr[2])

In general,
// We have three cases
// 1) Exclude arr[i],  i.e.,  sum[i] = sum[i-1]
// 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
// 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1] 
sum[i] = max(sum[i-1], sum[i-2] + arr[i],
             sum[i-3] + arr[i] + arr[i-1])
</pre>
Below is implementation of above idea.<br />
```cpp
// C++ program to find the maximum sum such that
// no three are consecutive
#include <bits/stdc++.h>
using namespace std;

// Returns maximum subsequence sum such that no three
// elements are consecutive
int maxSumWO3Consec(int arr[], int n)
{
	// Stores result for subarray arr[0..i], i.e.,
	// maximum possible sum in subarray arr[0..i]
	// such that no three elements are consecutive.
	int sum[n];

	// Base cases (process first three elements)
	if (n >= 1)
		sum[0] = arr[0];

	if (n >= 2)
		sum[1] = arr[0] + arr[1];

	if (n > 2)
		sum[2] = max(sum[1], max(arr[1] + arr[2], arr[0] + arr[2]));

	// Process rest of the elements
	// We have three cases
	// 1) Exclude arr[i], i.e., sum[i] = sum[i-1]
	// 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
	// 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]
	for (int i = 3; i < n; i++)
		sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]), arr[i] + arr[i - 1] + sum[i - 3]);

	return sum[n - 1];
}

int main()
{
	int arr[] = { 100, 1000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxSumWO3Consec(arr, n);
	return 0;
}
```
Output:<br />
<pre>
1100
</pre>
<pre>
Time Complexity: O(n) 
Auxiliary Space: O(n)
</pre>
<br /><br />**Another approach: (Using recursion)**<br />
```cpp
// C++ program to find the maximum sum such that
// no three are consecutive using recursion.
#include<bits/stdc++.h>
using namespace std;

// Returns maximum subsequence sum such that no three
// elements are consecutive
int maxSum(int arr[], int i, vector<int> &dp)
{
	// base case
	if (i < 0)
		return 0;

	// this condition check is necessary to avoid segmentation fault at line 21
	if (i == 0)
		return arr[i];

	// returning maxSum for already processed indexes of array
	if (dp[i] != -1)
		return dp[i];

	// including current element and the next consecutive element in subsequence
	int a = arr[i] + arr[i - 1] + maxSum(arr, i - 3, dp);

	// not including the current element in subsequence
	int b = maxSum(arr, i - 1, dp);

	// including current element but skipping next consecutive element
	int c = arr[i] + maxSum(arr, i - 2, dp);

	// returning the max of above 3 cases
	return dp[i] = max(a, max(b, c));
}

// Driver code
int main()
{
	int arr[] = {100, 1000, 100, 1000, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> dp(n, -1); // declaring and initializing dp vector
	cout << maxSum(arr, n - 1, dp) << endl;
	return 0;
}
```
Output:<br />
<pre>
2101
</pre>
<pre>
Time Complexity: O(n) 
Auxiliary Space: O(n)
</pre>
* [To top](#Table-of-Content)






  <br /><br /><br />
  ## Problem 23:
  **[Egg Dropping Puzzle](https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1)**<br />
You are given `N` identical eggs and you have access to a `K-floored` building from `1` to `K`.<br />
There exists a floor `f` where `0 <= f <= K` such that any egg dropped at a floor higher than `f` will break, and any egg dropped `at or below` floor `f` will `not break`. There are few rules given below.<br />

 * An egg that survives a fall can be used again.<br />
 * A broken egg must be discarded.<br />
 * The effect of a fall is the same for all eggs.<br />
 * If the egg doesn't break at a certain floor, it will not break at any floor below.<br />
 * If the eggs breaks at a certain floor, it will break at any floor above.<br />
 
Return the minimum number of moves that you need to determine with certainty what the value of `f` is.<br />

>Example 1:<br />
Input:<br />
N = 1, K = 2<br />
Output: 2<br />
Explanation: <br />
1. Drop the egg from floor 1. If it <br />
   breaks, we know that f = 0.<br />
2. Otherwise, drop the egg from floor 2.<br />
   If it breaks, we know that f = 1.<br />
3. If it does not break, then we know f = 2.<br />
4. Hence, we need at minimum 2 moves to<br />
   determine with certainty what the value of f is.<br />

>Example 2:<br />
Input:<br />
N = 2, K = 10<br />
Output: 4<br />

**Your Task:**<br />
Complete the function `eggDrop()` which takes two positive integer `N` and `K` as input parameters and returns the minimum number of attempts you need in order to find the critical floor.<br />

<pre>
Expected Time Complexity : O(N*(K^2))
Expected Auxiliary Space: O(N*K)
</pre>

* Constraints: `1<=N<=200`<br />
`1<=K<=200`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int eggDrop(int n, int k){
        int eggFloor[n+1][k+1], res, i, j, x;
        for(i = 1;i<=n;i++){
            eggFloor[i][1] = 1;
            eggFloor[i][0] = 0;
        }
        for(j = 1;j<=k;j++)eggFloor[1][j] = j;
        for(i = 2;i<=n;i++){
            for(j = 2;j<=k;j++){
                eggFloor[i][j] = INT_MAX;
                for(x = 1;x<=j;x++){
                    res = 1+max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
                    if(res<eggFloor[i][j])eggFloor[i][j] = res;
                }
            }
        }
        return eggFloor[n][k];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        Solution ob;
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)





  <br /><br /><br />
  ## Problem 24:
  **[Maximum Length Chain of Pairs](https://practice.geeksforgeeks.org/problems/max-length-chain/1)**<br />
You are given `N` pairs of numbers. In every pair, the first number is always smaller than the second number. A pair `(c, d)` can follow another pair `(a, b)` if `b < c`. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs. <br />
 
>Example 1:<br />
Input:<br />
N = 5<br />
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}<br />
Output: 3<br />
Explanation: The given pairs are { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },the longest chain that<br />
can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}<br />

>Example 2:<br />
Input:<br />
N = 2<br />
P[] = {5 10 , 1 11}<br />
Output: 1<br />
Explanation:The max length chain possible is only of length one.<br />
 
**Your Task:**<br />
You don't need to read input or print anything. Your task is to Complete the function `maxChainLen()` which takes a structure `p[]` denoting the pairs and `n` as the number of pairs and returns the length of the longest chain formed.<br />

<pre>
Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1<=N<=100`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

struct val{
    int first;
    int second;
};

int maxChainLen(struct val p[], int n);

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        val p[n];
        for(int i = 0;i<n;i++)cin>>p[i].first>>p[i].second;
        cout<<maxChainLen(p, n)<<endl;
    }
    return 0;
}

bool cmp(struct val p1, struct val p2){
    if(p1.first<p2.first)return 1;
    else if (p1.first == p2.first && p1.second<p2.second)return 1;
    return 0;
}

int dp[10001];

int maxChainLen(struct val p[], int n){
    sort(p, p+n, cmp);
    for(int i = 0;i<10001;i++)dp[i] = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(p[i].first>p[j].second && dp[i]<dp[j]+1)dp[i] = dp[j]+1;
        }
    }
    int m = INT_MIN;
    for(int i = 0;i<n;i++) m = max(dp[i], m);
    return m;
}
```
* [To top](#Table-of-Content)








  <br /><br /><br />
  ## Problem 25:
  **[Maximum size square sub-matrix with all 1s](https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1)**<br />
Given a binary matrix `mat` of size `n * m`, find out the maximum size square sub-matrix with all `1s`.<br />

>Example 1:<br />
Input: n = 2, m = 2<br />
mat = {{1, 1}, <br />
       {1, 1}}<br />
Output: 2<br />
Explaination: The maximum size of the square sub-matrix is 2. The matrix itself is the<br /> 
maximum sized sub-matrix in this case.<br />

>Example 2:<br />
Input: n = 2, m = 2<br />
mat = {{0, 0}, <br />
       {0, 0}}<br />
Output: 0<br />
Explaination: There is no 1 in the matrix.<br />

**Your Task:**
You do not need to read input or print anything. Your task is to complete the function `maxSquare()` which takes `n`, `m` and `mat` as input parameters and returns the `size` of the maximum square sub-matrix of given matrix.<br />

<pre>
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
</pre>

* Constraints: `1 ≤ n, m ≤ 50`<br />
`0 ≤ mat[i][j] ≤ 1` <br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int sub[n][m], maxsize = 0;
        for(int i = 0;i < m;i++){
            sub[0][i] = mat[0][i];
            maxsize = max(maxsize, sub[0][i]);
        }
        for(int i = 0;i < n;i++){
            sub[i][0] = mat[i][0];
            maxsize = max(maxsize, sub[i][0]);
        }
        for(int i = 1;i < n;i++){
    		for(int j = 1;j < m;j++){
    			if(mat[i][j] == 1)
    				sub[i][j] = min(sub[i-1][j-1], min(sub[i][j-1], sub[i-1][j])) + 1;
    			else
    				sub[i][j]=0;
				maxsize = max(maxsize, sub[i][j]);
    		}
    	}
    	return maxsize;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>>mat(n, vector<int>(m, 0));
        for(int i = 0;i<n*m;i++)cin>>mat[i/m][i%m];
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<endl;
    }
}
```
* [To top](#Table-of-Content)










  <br /><br /><br />
  ## Problem 26:
  **[Maximum sum of pairs with specific difference](https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1)**<br />
Given an array of integers, `arr[]` and a number, `K`.You can pair two numbers of the array if the difference between them is `strictly less than K`. The task is to find the maximum possible sum of such `disjoint pairs` (i.e., each element of the array can be used `at most` once). The Sum of `P` pairs is the sum of all `2P` elements of pairs.<br />

>Example 1:<br />
Input  : <br />
arr[] = {3, 5, 10, 15, 17, 12, 9}<br />
K = 4<br />
Output : <br />
62<br />
Explanation :<br />
Then disjoint pairs with difference less than K are, (3, 5), (10, 12), (15, 17)<br />
max sum which we can get is 3 + 5 + 10 + 12 + 15 + 17 = 62<br />
Note that an alternate way to form disjoint pairs is,(3, 5), (9, 12), (15, 17)<br />
but this pairing produces less sum. <br />

>Example 2:<br />
Input  : <br />
arr[] = {5, 15, 10, 300}<br />
K = 12<br />
Output : <br />
25<br />
 
**Your Task:**<br />
You don't need to read, input, or print anything. Your task is to complete the function `maxSumPairWithDifferenceLessThanK()` which takes the array `arr[]`, its size `N`, and an integer `K` as inputs and returns the maximum possible sum of disjoint pairs.<br />

<pre>
Expected Time Complexity: O(N. log(N))
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1 ≤ N ≤ 10^5`<br />
`0 ≤ K ≤ 10^5`<br />
`1 ≤ arr[i] ≤ 10^4`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K){
        sort(arr, arr + N);
        int ans = 0;
        for (int i = N - 1; i > 0; i--) if (arr[i] - arr[i - 1] < K) ans += (arr[i] + arr[i - 1]), i--;
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        int k; cin>>k;
        Solution ob;
        cout<<ob.maxSumPairWithDifferenceLessThanK(arr, n, k)<<endl;
    }
}
```
* [To top](#Table-of-Content)






  <br /><br /><br />
  ## Problem 27:
  **[Maximum path sum in matrix](https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1)**<br />
Given a `NxN` matrix of positive integers. There are only `three` possible moves from a cell `Matrix[r][c]`.<br />

 1. Matrix [r+1] [c]<br />
 2. Matrix [r+1] [c-1]<br />
 3. Matrix [r+1] [c+1]<br />
 
Starting from any column in row `0` return the largest sum of any of the paths up to row `N-1`.<br />

>Example 1:<br />
Input: N = 2<br />
Matrix = {{348, 391},<br />
          {618, 193}}<br />
Output: 1009<br />
Explaination: The best path is 391 -> 618. It gives the sum = 1009.<br />

>Example 2:<br />
Input: N = 2<br />
Matrix = {{2, 2},<br />
          {2, 2}}<br />
Output: 4<br />
Explaination: No matter which path is chosen, the output is 4.<br />

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `maximumPath()` which takes the size `N` and the `Matrix` as input parameters and returns the highest maximum path sum.<br />

<pre>
Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)
</pre>

* Constraints: `1 ≤ N ≤ 500`<br />
`1 ≤ Matrix[i][j] ≤ 1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix){
        int dp[N][N];
        for(int i = 0;i < N;i++)dp[0][i] = Matrix[0][i];
        for(int i = 1;i < N;i++){
            for(int j = 0;j < N;j++){
                if(j == 0 && j+1 < N)
                    dp[i][j] = Matrix[i][j] + max(dp[i-1][j],dp[i-1][j+1]);
                else if(j-1>=0 && j == N-1)
                    dp[i][j] = Matrix[i][j] + max(dp[i-1][j],dp[i-1][j-1]);
                else if(j > 0 && j+1 < N)
                    dp[i][j] = Matrix[i][j] + max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
                else
                    dp[i][j] = Matrix[i][j] + dp[i-1][j];
            }
        }
        int maxi = 0;
        for(int i = 0;i < N;i++)
            maxi = max(maxi, dp[N-1][i]);
        return maxi;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>>matrix(n, vector<int>(n, 0));
        for(int i = 0;i<n*n;i++)cin>>matrix[(i/n)][i%n];
        Solution ob;
        cout<<ob.maximumPath(n, matrix)<<endl;
    }
}
```
* [To top](#Table-of-Content)






  <br /><br /><br />
  ## Problem 28:
  **[Maximum difference of zeros and ones in binary string](https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1)**<br />
Given a binary string `S` consisting of `0s` and `1s`. The task is to find the maximum difference of the number of `0s` and the number of `1s` (number of 0s – number of 1s) in the substrings of a string.<br />
**Note:** In the case of all `1s`, the answer will be `-1`.<br />

>Example 1:<br />
Input : S = "11000010001" <br />
Output : 6 <br />
Explanatio: From index 2 to index 9, there are 7 0s and 1 1s, so number<br /> 
of 0s - number of 1s is 6. <br />

>Example 2:<br />
Input: S = "111111"<br />
Output: -1<br />
Explanation: S contains 1s only <br />

**Your task:**<br />
You do not need to read any input or print anything. The task is to complete the function `maxSubstring()`, which takes a `string` as input and returns an `integer`.<br />

<pre>
Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)
</pre>

* Constraints: `1 ≤ |S| ≤ 10^5`<br />
`S` contains `0s` and `1s` only<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int maxSubstring(string S){
	    //Kadane algorithm
	    int n = S.size();
	    int arr[n];
	    for(int i = 0;i<n;i++)arr[i] = (S[i] == '0')?1: -1;
	    int cur = arr[0], ans = arr[0];
	    for(int i = 1;i<n;i++){
	        cur = max(arr[i], cur+arr[i]);
	        ans = max(ans, cur);
	    }
	    return ans;
	}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        Solution ob;
        cout<<ob.maxSubstring(s)<<endl;
    }
}
```
* [To top](#Table-of-Content)







  <br /><br /><br />
  ## Problem 29:
  **[Minimum number of jumps to reach end](https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1)**<br />
Given an array of `N` integers `arr[]` where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is `0`, then you cannot move through that element.<br />
**Note**: Return -1 if you can't reach the end of the array.<br />

>Example 1:<br />
Input:<br />
N = 11 <br />
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} <br />
Output: 3 <br />
Explanation: <br />
First jump from 1st element to 2nd element with value 3. Now, from here we jump to 5th element with value 9, and from here we will jump to last. <br />

>Example 2:<br />
Input :<br />
N = 6<br />
arr = {1, 4, 3, 2, 6, 7}<br />
Output: 2 <br />
Explanation: First we jump from the 1st to 2nd element and then jump to the last element.<br />

Your task:<br />
You don't need to read input or print anything. Your task is to complete function `minJumps()` which takes the array `arr` and it's size `N` as input parameters and returns the minimum number of jumps. If not possible returns -1.<br />

<pre>
Expected Time Complexity: O(N)
Expected Space Complexity: O(1)
</pre><br />

* Constraints: `1 ≤ N ≤ 10^7`<br />
`0 ≤ arri ≤ 10^7`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;



class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n<=1)return 0;
        if(arr[0]==0)return -1;
        int maxreach = arr[0];
        int step = arr[0];
        int jump = 1;
        for(int i=1;i<n;i++){
            if(i==n-1)return jump;
            maxreach = max(maxreach,i+arr[i]);
            step--;
            if(step==0){
                jump++;
                if(i>=maxreach)return -1;
                step = maxreach -i ;
            }
        }
        return -1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)






  <br /><br /><br />
  ## Problem 30:
  **[Minimum cost to fill given weight in a bag](https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1)**<br />
Given an array `cost[]` of positive integers of size `N` and an integer `W`, `cost[i]` represents the cost of `‘i’` kg packet of oranges, the task is to find the minimum cost to buy `W` kgs of oranges. If it is not possible to buy exactly `W` kg oranges then the output will be `-1`.<br />
**Note:**<br />

 1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable<br />
 2. It may be assumed that there is infinite supply of all available packet types.<br />

>Example 1:<br />
Input: N = 5, arr[] = {20, 10, 4, 50, 100}<br />
W = 5<br />
Output: 14<br />
Explanation: choose two oranges to minimize cost. First orange of 2Kg and cost 10.<br /> 
Second orange of 3Kg and cost 4. <br />

>Example 2:<br />
Input: N = 5, arr[] = {-1, -1, 4, 3, -1}<br />
W = 5<br />
Output: -1<br />
Explanation: It is not possible to buy 5 kgs of oranges<br />

**Your Task:**  <br />
You don't need to read input or print anything. Complete the function `minimumCost()` which takes `N`, `W`, and `array cost` as input parameters and returns the minimum value.<br />

<pre>
Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(N*W)
</pre>

* Constraints: `1 ≤ N, W ≤ 2*10^2`<br />
`-1 ≤ cost[i] ≤ 10^5`<br />
`cost[i] ≠ 0`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int minimumCost(int cost[], int N, int W){ 
        int INF = 999999999;
        vector<int>val, wt;
        int size = 0;
        for(int i = 0;i<N;i++){
            if(cost[i] != -1){
                val.push_back(cost[i]);
                wt.push_back(i+1);
                size++;
            }
        }
        N = size;
        int min_cost[N+1][W+1];
        for(int i = 0;i<=W;i++)min_cost[0][i] = INF;
        for(int i = 1;i<=N;i++)min_cost[i][0] = 0;
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=W;j++){
                if(wt[i-1]>j)min_cost[i][j] = min_cost[i-1][j];
                else min_cost[i][j] = min(min_cost[i-1][j], min_cost[i][j-wt[i-1]]+val[i-1]);
            }
        }
        return (min_cost[N][W] == INF)? -1: min_cost[N][W];
	} 
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, w;
        cin>>n>>w;
        int a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.minimumCost(a, n, w)<<endl;
    }
}
```
* [To top](#Table-of-Content)  
  
  
  
  
  
  
  
  
  

  <br /><br /><br />
  ## Problem 31:
  **[Minimum removals from array to make max –min <= K](https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/)**<br />
Given `N` integers and `K`, find the minimum number of elements that should be removed, such that `Amax-Amin<=K`. After the removal of elements, `Amax` and `Amin` is considered among the remaining elements.<br />

**Examples:**<br /> 
<pre>
Input : a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20} 
          k = 4 
Output : 5 
Explanation: Remove 1, 3, 4 from beginning 
and 17, 20 from the end.

Input : a[] = {1, 5, 6, 2, 8}  K=2
Output : 3
Explanation: There are multiple ways to 
remove elements in this case.
One among them is to remove 5, 6, 8.
The other is to remove 1, 2, 5
</pre>
**Approach:**<br />
Sort the given elements. Using the `greedy approach`, the best way is to remove the minimum element or the maximum element and then check if `Amax-Amin <= K`. There are various combinations of removals that have to be considered. We write a `recurrence` relation to try every possible combination. There will be `two` possible ways of removal, either we remove the `minimum` or we remove the `maximum`. Let`(i…j)` be the index of elements left after removal of elements. Initially, we start with `i=0` and `j=n-1` and the number of elements removed is `0` at the beginning. We only remove an element if `a[j]-a[i]>k`, the two possible ways of removal are `(i+1…j)` or `(i…j-1)`. The minimum of the two is considered.<br /> 
Let `DPi, j` be the number of elements that need to be removed so that after removal `a[j]-a[i]<=k`.<br />
**Recurrence relation for sorted array:**<br />
<pre>
DPi, j = 1+ (min(countRemovals(i+1, j), countRemovals(i, j-1))
</pre>
Below is the implementation of the above idea:<br />
```cpp
// CPP program to find minimum removals
// to make max-min <= K
#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int dp[MAX][MAX];

// function to check all possible combinations
// of removal and return the minimum one
int countRemovals(int a[], int i, int j, int k)
{
	// base case when all elements are removed
	if (i >= j)
		return 0;

	// if condition is satisfied, no more
	// removals are required
	else if ((a[j] - a[i]) <= k)
		return 0;

	// if the state has already been visited
	else if (dp[i][j] != -1)
		return dp[i][j];

	// when Amax-Amin>d
	else if ((a[j] - a[i]) > k) {

		// minimum is taken of the removal
		// of minimum element or removal
		// of the maximum element
		dp[i][j] = 1 + min(countRemovals(a, i + 1, j, k), countRemovals(a, i, j - 1, k));
	}
	return dp[i][j];
}

// To sort the array and return the answer
int removals(int a[], int n, int k)
{
	// sort the array
	sort(a, a + n);

	// fill all stated with -1
	// when only one element
	memset(dp, -1, sizeof(dp));
	if (n == 1)
		return 0;
	else
		return countRemovals(a, 0, n - 1, k);
}

// Driver Code
int main()
{
	int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 4;
	cout << removals(a, n, k);
	return 0;
}
```
Output<br />
<pre>
5
</pre>
<pre>
Time Complexity :O(n^2) 
Auxiliary Space: O(n^2)
</pre>
The solution could be further optimized. The idea is to `sort` the array in increasing order and traverse through all the elements (let’s say index i) and find the maximum element on its right (index `j`) such that `arr[j] – arr[i] <= k`. Thus, the number of elements to be removed becomes `n-(j-i+1)`. The minimum number of elements can be found by taking the minimum of `n-(j-i-1)` overall `i`. The value of index `j` can be found through a binary search between `start = i+1` and `end = n-1`;<br />
```cpp
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find
// rightmost index
// which satisfies the condition
// arr[j] - arr[i] <= k
int findInd(int key, int i,
			int n, int k, int arr[])
{
	int start, end, mid, ind = -1;
	
	// Initialising start to i + 1
	start = i + 1;
	
	// Initialising end to n - 1
	end = n - 1;
	
	// Binary search implementation
	// to find the rightmost element
	// that satisfy the condition
	while (start < end)
	{
		mid = start + (end - start) / 2;
		
		// Check if the condition satisfies
		if (arr[mid] - key <= k)
		{
			
			// Store the position
			ind = mid;
			
			// Make start = mid + 1
			start = mid + 1;
		}
		else
		{
			// Make end = mid
			end = mid;
		}
	}
	
	// Return the rightmost position
	return ind;
}

// Function to calculate
// minimum number of elements
// to be removed
int removals(int arr[], int n, int k)
{
	int i, j, ans = n - 1;
	
	// Sort the given array
	sort(arr, arr + n);
	
	// Iterate from 0 to n-1
	for (i = 0; i < n; i++)
	{
		
		// Find j such that
		// arr[j] - arr[i] <= k
		j = findInd(arr[i], i, n, k, arr);
		
		// If there exist such j
		// that satisfies the condition
		if (j != -1)
		{
			// Number of elements
			// to be removed for this
			// particular case is
			// (j - i + 1)
			ans = min(ans, n - (j - i + 1));
		}
	}
	
	// Return answer
	return ans;
}

// Driver Code
int main()
{
	int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
	int n = sizeof(a) / sizeof(a[0]);
	int k = 4;
	cout << removals(a, n, k);
	return 0;
}
```
Output<br />
<pre>
5
</pre>
<pre>
Time Complexity :O(nlogn) 
Auxiliary Space: O(n)
</pre>
**Approach:**<br />

 1. The solution could be further optimized. The idea is to sort the array in increasing order and traverse through all the elements (let’s say index j) and find the minimum element on its left (index i) such that `arr[j] – arr[i] <= k` and store it in `dp[j]`.<br />
 2. Thus, the number of elements to be removed becomes `n-(j-i+1)`. The minimum number of elements can be found by taking the minimum of `n-(j-i-1)` overall `j`. The value of index `i` can be found through its previous dp array element value.<br />
 
Below is the implementation of the approach:<br />
```cpp
// C++ program for the above approach
#include<bits/stdc++.h>
using namespace std;

// To sort the array and return the answer
int removals(int arr[], int n, int k)
{

// sort the array
sort(arr, arr + n);
int dp[n];

// fill all stated with -1
// when only one element
for(int i = 0; i < n; i++)
	dp[i] = -1;

// as dp[0] = 0 (base case) so min
// no of elements to be removed are
// n-1 elements
int ans = n - 1;
dp[0] = 0;
for (int i = 1; i < n; i++)
{
	dp[i] = i;
	int j = dp[i - 1];
	while (j != i && arr[i] - arr[j] > k)
	{
	j++;
	}
	dp[i] = min(dp[i], j);
	ans = min(ans, (n - (i - j + 1)));
}
return ans;
}

// Driver code
int main()
{
int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
int n = sizeof(a) / sizeof(a[0]);
int k = 4;
cout<<removals(a, n, k);
return 0;
}
```
Output<br />
<pre>
5
</pre>
<pre>
Time Complexity: O(nlog n). 
</pre>
As outer loop is going to make `n` iterations. And the inner loop iterates at max `n` times for all outer iterations. Because we start value of `j` from `dp[i-1]` and loops it until it reaches `i` and then for the next element we again start from the previous `dp[i]` value. So the total time complexity is `O(n)` if we don’t consider the complexity of the sorting as it is not considered in the above solution as well.<br />
<pre>
Auxiliary Space: O(n)
</pre>
<br /><br />**Space Optimised Approach**<br />
The solution could be further optimized. It can be done in `Auxiliary Space: O(1)`. The idea is to first sort the array in ascending order. The keep `2` pointers, say `i` and `j`, where `j` iterates from index `1` to index `n-1` and keeps track of ending subarray with the difference in `max` and `min` less than `k`, and `i` keeps the track of starting index of the subarray. If we find that `a[j] – a[i[ <=k` (means the `i` to `j` subarray is valid) we update the length from `i` to `j` in a variable to track of max length so far. Else, we update the starting index `i` with `i+1`.<br />
At first it seems that subarrays from `i` to `j` are ignored, but obviously their lengths are less than `i` to `j` subarray, so we don’t care about them.<br />
```cpp
// C++ program for the above approach
#include<bits/stdc++.h>
using namespace std;

int removal(int a[], int n, int k)
{
	// Sort the Array; Time complexity:O(nlogn)
	sort(a, a + n);

	// to store the max length of
	// array with difference <= k
	int maxLen = INT_MIN;
	int i = 0;
	// J goes from 1 to n-1 in n-2 iterations
	// Thus time complexity of below loop is O(n)
	for (int j = i + 1; j < n && i < n; j++) {
		// if the subarray from i to j index is valid
		// the store its length
		if (a[j] - a[i] <= k) {
			maxLen = max(maxLen, j - i + 1);
		}
		// if subarray difference exceeds k
		// change starting position, i.e. i
		else {
			i++;
		}
	}
	// no. of elements need to be removed is
	// Length of array - max subarray with diff <= k
	int removed = n - maxLen;
	return removed;
}

//Driver Code
int main()
{
	int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 4;
	cout << removal(a, n, k);
	return 0;
}
```
Output<br />
<pre>
5
</pre>
<pre>
Time Complexity: O(nlogn) For sorting the array, we require O(nlogn) time, and no extra space. 
	         And for calculating we only traverse the loop once, thus it has O(n) time complexity. 
		 So, overall time complexity is O(nlogn).
Auxiliary Space: O(1)
</pre>
**Approach:**<br />
Here we are applying sliding window, our will maintain `a[max]-a[min]<=k`. First, ascending order should be used to sort the array. The maintain two pointers, let’s call them `I` and `j`, `j` iterating from index `1` to index `n-1` and keeping track of the ending subarray with the difference in max and min smaller than `k`, and `I` keeping track of the initial index of the subarray. We update the length from `I` to `j` in a variable to track the maximum length thus far if we discover that `a[j] – a[i]=k` (meaning the `I` to `j` subarray is legitimate). If not, we add `i+1` to the beginning index `i`.<br />
```cpp
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

int removal(int a[], int n, int k)
{
	// Code here
	// Sort the Array; Time complexity:O(nlogn)
	sort(a, a + n);
	int diff= 0; // to store difference of max(a) and min(a)
	int ans = 0; // to store maximum length of array with length <=k

	// use sliding window to iterate array, maintaing two
	// pointers for desired subarray
	// which starting from index j and ending with index i
	for (int i = 0, j = 0; i < n; i++) {
		int diff = a[i] - a[j];
		// as array is already sorted, if difference exceeds
		// k we will move starting pointer forward
		while (i >= j && diff > k) {
			diff = a[i] - a[++j];
		}
		ans = max(ans, i - j + 1);
	}
	return n - ans;
}
// Driver Code
int main()
{
	int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
	int n = sizeof(a) / sizeof(a[0]);
	int k = 4;
	cout << removal(a, n, k);
	return 0;
}
```
Output<br />
<pre>
5
</pre>
<pre>
Time complexity: O(nlogn)
Auxiliary Space: O(1)		
</pre>
* [To top](#Table-of-Content)







  <br /><br /><br />
  ## Problem 32:
  **[Longest Common Substring](https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1)**<br />
Given two strings. The task is to find the length of the longest common substring.<br />

>Example 1:<br />
Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6<br />
Output: 4<br />
Explanation: The longest common substring is "CDGH" which has length 4.<br />

>Example 2:<br />
Input: S1 = "ABC", S2 "ACB", n = 3, m = 3<br />
Output: 1<br />
Explanation: The longest common substrings are "A", "B", "C" all having length 1.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `longestCommonSubstr()` which takes the string `S1`, string `S2` and their length `n` and `m` as inputs and returns the length of the longest common substring in `S1` and `S2`.<br />

<pre>
Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).
</pre>

* Constraints: `1<=n, m<=1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m){
        int arr[1000][1000], result=0;
        for(int i=0;i<n;i++)arr[i][0]=0;
        for(int j=0;j<m;j++)arr[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1; j<=m;j++){
                if(S1[i-1]==S2[j-1])arr[i][j]= 1+arr[i-1][j-1];
                else arr[i][j]=0;
                result=max(result, arr[i][j]);
            }
        }
        return result;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        string s1, s2; cin>>s1>>s2;
        Solution ob;
        cout<<ob.longestCommonSubstr(s1, s2, n, m)<<endl;
    }
}
```
* [To top](#Table-of-Content)







  <br /><br /><br />
  ## Problem 33:
  **[Reach a given score](https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1)**<br />
Consider a game where a player can score `3` or `5` or `10` points in a move. Given a total score `n`, find number of distinct combinations to reach the given score.<br />

>Example:<br />
Input<br />
3<br />
8<br />
20<br />
13<br />
Output<br />
1<br />
4<br />
2<br />
Explanation<br />
For 1st example when n = 8 { 3, 5 } and {5, 3} are the <br />
two possible permutations but these represent the same<br /> 
cobmination. Hence output is 1.<br />

**Your Task:**  <br />
You don't need to read input or print anything. Your task is to complete the function `count( )` which takes `N` as input parameter and returns the answer to the problem.<br />

* Constraints: `1 ≤ T ≤ 100`<br />
`1 ≤ n ≤ 1000`<br />

```cpp
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll count(ll n){
	ll table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 
	for(i = 3;i<=n;i++)table[i] += table[i-3];
	for(i = 5;i<=n;i++)table[i] += table[i-5];
	for(i = 10;i<=n;i++)table[i] += table[i-10];
	return table[n];
}

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        cout<<count(n)<<endl;
    }
}
```
* [To top](#Table-of-Content)








  <br /><br /><br />
  ## Problem 34:
  **[Count Balanced Binary Trees of Height h](https://practice.geeksforgeeks.org/problems/bbt-counter4914/1)**<br />
Given a height `h`, count the maximum number of balanced binary trees possible with height `h`. Print the result modulo `10^9 + 7`.<br />
**Note :** A balanced binary tree is one in which for every node, the difference between heights of left and right subtree is not more than `1`.<br />

>Example 1:<br />
Input: h = 2<br />
Output: 3 <br />
Explanation: The maximum number of balanced <br />
binary trees possible with height 2 is 3. <br />

>Example 2:<br />
Input: h = 3<br />
Output: 15<br />
Explanation: The maximum number of balanced<br />
binary trees possible with height 3 is 15. <br />

**Your Task:**  <br />
You dont need to read input or print anything. Complete the function `countBT()` which takes `h` as input parameter and returns the maximum number of balanced binary trees possible with height `h`. <br />

<pre>
Expected Time Complexity: O(h)
Expected Auxiliary Space: O(h)
</pre>

* Constraints: `1<= n <=10^3`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int countBT(int h){ 
        long long int dp[h + 1];
        dp[0] = dp[1] = 1; 
        long long int mod = 1000000007;   
        for(int i = 2; i <= h; i++)dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod; 
        return dp[h]; 
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int h; cin>>h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;
    }
}
```
* [To top](#Table-of-Content)







  <br /><br /><br />
  ## Problem 35:
  **[LargestSum Contiguous Subarray [V>V>V>V IMP ]](https://practice.geeksforgeeks.org/problems/kadanes-algorithm/1)**<br />
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

**Your Task:**<br />
You don't need to read input or print anything. The task is to complete the function `maxSubarraySum()` which takes `Arr[]` and `N` as input parameters and returns the sum of subarray with maximum sum.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ N ≤ 10^6`<br />
`-10^7 ≤ A[i] ≤ 10^7`<br />
  
```cpp
#include<bits/stdc++.h>
	using namespace std;

	class Solution{	
    		public:
   	 	// arr: input array
    		// n: size of array
    		//Function to find the sum of contiguous subarray with maximum sum.
    		long long maxSubarraySum(int arr[], int n){
        		
			// Your code here
        		long long maxh = 0, maxf = arr[0];
        
        		//Iterating over the array.
        		for(int i=0;i<n;i++){
			
                		//Updating max sum till current index.
                		maxh+=arr[i];
               		 	//Storing max sum so far by choosing maximum between max 
                		//sum so far and max till current index.
                		if(maxf<maxh)
                		maxf=maxh; 
                
                		//If max sum at current index is negative, we do not need to add
                		//it to result so we update it to zero.
                		if(maxh<0)
                    			maxh=0;
    		       	}
            		//returning the result.
            		return maxf;
    		}
	};

	int main(){
    		int t,n;
    		cin>>t;
    		while(t--){
        		cin>>n  ;
        		int a[n];
        		for(int i=0;i<n;i++){
            		cin>>a[i];
			}
        	Solution ob;
        	cout<<ob.maxSubarraySum(a,n)<<endl;
    		}
	}
```
  * [To top](#Table-of-Content)
  
  
  

  <br /><br /><br />
  ## Problem 36:
  **[Smallest sum contiguous subarray](https://www.geeksforgeeks.org/smallest-sum-contiguous-subarray/)**<br />
Given an `array` containing `n` integers. The problem is to find the sum of the elements of the contiguous subarray having the smallest(minimum) sum.<br />
**Examples:**<br />
<pre>
Input : arr[] = {3, -4, 2, -3, -1, 7, -5}
Output : -6
Subarray is {-4, 2, -3, -1} = -6

Input : arr = {2, 6, 8, 1, 4}
Output : 1
</pre>
**Naive Approach:** Consider all the contiguous subarrays of different sizes and find their sum. The subarray having the smallest(minimum) sum is the required answer.<br />
**Efficient Approach:** It is a variation to the problem of finding the largest sum contiguous subarray based on the idea of `Kadane’s algorithm`.<br /> 
**Algorithm:**<br />
<pre>
smallestSumSubarr(arr, n)
    Initialize min_ending_here = INT_MAX
    Initialize min_so_far = INT_MAX
    
    for i = 0 to n-1
        if min_ending_here > 0
            min_ending_here = arr[i]        
        else
            min_ending_here += arr[i]
        min_so_far = min(min_so_far, min_ending_here)

    return min_so_far
</pre>
**Implementation:**<br />
```cpp
// C++ implementation to find the smallest sum
// contiguous subarray
#include <bits/stdc++.h>

using namespace std;

// function to find the smallest sum contiguous subarray
int smallestSumSubarr(int arr[], int n)
{
	// to store the minimum value that is ending
	// up to the current index
	int min_ending_here = INT_MAX;
	
	// to store the minimum value encountered so far
	int min_so_far = INT_MAX;
	
	// traverse the array elements
	for (int i=0; i<n; i++)
	{
		// if min_ending_here > 0, then it could not possibly
		// contribute to the minimum sum further
		if (min_ending_here > 0)
			min_ending_here = arr[i];
		
		// else add the value arr[i] to min_ending_here
		else
			min_ending_here += arr[i];
		
		// update min_so_far
		min_so_far = min(min_so_far, min_ending_here);		
	}
	
	// required smallest sum contiguous subarray value
	return min_so_far;
}


// Driver program to test above
int main()
{
	int arr[] = {3, -4, 2, -3, -1, 7, -5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Smallest sum: " << smallestSumSubarr(arr, n);
	return 0;	
}
```
Output<br />
<pre>
Smallest sum: -6
</pre>
<pre>
Time Complexity: O(n)
</pre>
* [To top](#Table-of-Content)









  <br /><br /><br />
  ## Problem 37:
  **[Unbounded Knapsack (Repetition of items allowed)](https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1)**<br />
Given a set of `N` items, each with a `weight` and a `value`, represented by the array `w[]` and `val[]` respectively. Also, a knapsack with weight limit `W`.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.<br />
**Note:** Each item can be taken any number of times.<br />

>Example 1:<br />
Input: N = 2, W = 3<br />
val[] = {1, 1}<br />
wt[] = {2, 1}<br />
Output: 3<br />
Explanation: <br />
1.Pick the 2nd element thrice.<br />
2.Total profit = 1 + 1 + 1 = 3. Also the total<br /> 
  weight = 1 + 1 + 1  = 3 which is <= W.<br />
 
>Example 2:<br />
Input: N = 4, W = 8<br />
val[] = {1, 4, 5, 7}<br />
wt[] = {1, 3, 4, 5}<br />
Output: 11<br />
Explanation: The optimal choice is to pick the 2nd and 4th element.<br />

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `knapSack()` which takes the values `N`, `W` and the arrays `val[]` and `wt[]` as input parameters and returns the maximum possible value.<br />

<pre>
Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(W)
</pre>

* Constraints: `1 ≤ N, W ≤ 1000`<br />
`1 ≤ val[i], wt[i] ≤ 100`<br />
  
 ```cpp
 #include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int knapSack(int N, int W, int val[], int wt[]){
        vector<int>dp(W+1, 0);
        int ans = 0;
        for(int i = 0;i<W+1;i++)
            for(int j = 0;j<N;j++)
                if(wt[j]<=i)dp[i] = max(dp[i], dp[i-wt[j]]+val[j]);
        return dp[W];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, w; cin>>n>>w;
        int val[n], wt[n];
        for(int i = 0;i<n;i++)cin>>val[i];
        for(int i = 0;i<n;i++)cin>>wt[i];
        Solution ob;
        cout<<ob.knapSack(n, w, val, wt)<<endl;
    }
}
```
  * [To top](#Table-of-Content)
  
  
  
  
  
  
  

  <br /><br /><br />
  ## Problem 38:
  **[Word Break Problem](https://practice.geeksforgeeks.org/problems/word-break1352/1)**<br />
Given a string `A` and a dictionary of `n` words `B`, find out if `A` can be segmented into a space-separated sequence of dictionary words.<br />
**Note:** From the dictionary `B` each word can be taken any number of times and in any order.<br />

>Example 1:<br />
Input:<br />
n = 12<br />
B = { "i", "like", "sam", "sung", "samsung", "mobile",<br />
"ice","cream", "icecream", "man", "go", "mango" }<br />
A = "ilike"<br />
Output:<br />
1<br />
Explanation:<br />
The string can be segmented as "i like".<br />

>Example 2:<br />
Input:<br />
n = 12<br />
B = { "i", "like", "sam", "sung", "samsung", "mobile",<br />
"ice","cream", "icecream", "man", "go", "mango" }<br />
A = "ilikesamsung"<br />
Output:<br />
1<br />
Explanation:<br />
The string can be segmented as "i like samsung" or "i like sam sung".<br />
 
**Your Task:**<br />
Complete `wordBreak()` function which takes a `string` and `list of strings` as a parameter and returns `1` if it is possible to break words, else return `0`. You don't need to read any input or print any output, it is done by driver code.<br />

<pre>
Expected time complexity: O(s2)
Expected auxiliary space: O(s) , where s = length of string A
</pre>

* Constraints: `1 ≤ N ≤ 12`<br />
`1 ≤ s ≤ 1100` , where s = length of string A<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        int i, j, n = B.size();
        set<string>mp;
        for(i = 0;i<n;i++)mp.insert(B[i]);
        int len = A.size();
        vector<bool>dp(len+1, false);
        dp[0] = true;
        for(int i = 1;i<=len;i++){
            for(int j = i-1;j>=0;j--){
                if(dp[j] && mp.find(A.substr(j, i-j)) != mp.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string>dict;
        for(int i = 0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<endl;
    }
}
```
* [To top](#Table-of-Content)









  <br /><br /><br />
  ## Problem 39:
  **[Largest Independent Set Problem](https://www.geeksforgeeks.org/largest-independent-set-problem-dp-26/)**<br />
Given a Binary Tree, find size of the `Largest Independent Set(LIS)` in it. A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset.<br />
For example, consider the following binary tree. The **largest independent set(LIS)** is `{10, 40, 60, 70, 80}` and size of the LIS is `5`.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/LargestIndependentSet1.png"><br />
A Dynamic Programming solution solves a given problem using solutions of subproblems in `bottom up` manner. Can the given problem be solved using solutions to subproblems? If yes, then what are the subproblems? Can we find `largest independent set size (LISS)` for a node `X` if we know `LISS` for all descendants of `X`? If a node is considered as part of `LIS`, then its children `cannot` be part of LIS, but its grandchildren can be. Following is optimal substructure property.<br />
<br /><br />**1) Optimal Substructure:**<br />
Let `LISS(X)` indicates size of largest independent set of a tree with root X.<br /> 
<pre>
   LISS(X) = MAX { (1 + sum of LISS for all grandchildren of X),
                     (sum of LISS for all children of X) }
</pre>
The idea is simple, there are two possibilities for every node `X`, either `X` is a member of the set or not a member. If `X` is a member, then the value of `LISS(X)` is `1` plus `LISS` of all grandchildren. If `X` is not a member, then the value is sum of `LISS` of all children.<br />
<br /><br />
Following is recursive implementation that simply follows the `recursive` structure mentioned above.<br />
```cpp
// A naive recursive implementation of
// Largest Independent Set problem
#include <bits/stdc++.h>
using namespace std;

// A utility function to find
// max of two integers
int max(int x, int y)
{
	return (x > y) ? x : y;
}

/* A binary tree node has data,
pointer to left child and a
pointer to right child */
class node
{
	public:
	int data;
	node *left, *right;
};

// The function returns size of the
// largest independent set in a given
// binary tree
int LISS(node *root)
{
	if (root == NULL)
	return 0;

	// Calculate size excluding the current node
	int size_excl = LISS(root->left) + LISS(root->right);

	// Calculate size including the current node
	int size_incl = 1;
	if (root->left)
		size_incl += LISS(root->left->left) + LISS(root->left->right);
	if (root->right)
		size_incl += LISS(root->right->left) + LISS(root->right->right);

	// Return the maximum of two sizes
	return max(size_incl, size_excl);
}

// A utility function to create a node
node* newNode( int data )
{
	node* temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver Code
int main()
{
	// Let us construct the tree
	// given in the above diagram
	node *root = newNode(20);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	root->right->right = newNode(25);

	cout << "Size of the Largest"
		<< " Independent Set is "
		<< LISS(root);

	return 0;
}
```
Output:<br />
<pre>
Size of the Largest Independent Set is 5
</pre>
<pre>
Time complexity of the above naive recursive approach is exponential.
</pre>
It should be noted that the above function computes the same subproblems again and again. For example, `LISS` of node with value `50` is evaluated for node with values `10` and `20` as `50` is grandchild of `10` and child of `20`.<br />
Since same subproblems are called again, this problem has `Overlapping Subproblems` property. So `LISS` problem has both properties (see this and this) of a dynamic programming problem. Like other typical Dynamic Programming(DP) problems, `recomputations` of same subproblems can be avoided by storing the solutions to subproblems and solving problems in `bottom up manner`.<br />
Following are implementation of Dynamic Programming based solution. In the following solution, an additional field `‘liss’` is added to tree nodes. The initial value of `‘liss’` is set as `0` for all nodes. The recursive function `LISS()` calculates `‘liss’` for a node only if it is not already set.<br />
```cpp
/* Dynamic programming based program
for Largest Independent Set problem */
#include <bits/stdc++.h>
using namespace std;

// A utility function to find max of two integers
int max(int x, int y) { return (x > y)? x: y; }

/* A binary tree node has data, pointer
to left child and a pointer to
right child */
class node
{
	public:
	int data;
	int liss;
	node *left, *right;
};

// A memoization function returns size
// of the largest independent set in
// a given binary tree
int LISS(node *root)
{
	if (root == NULL)
		return 0;

	if (root->liss)
		return root->liss;

	if (root->left == NULL && root->right == NULL)
		return (root->liss = 1);

	// Calculate size excluding the current node
	int liss_excl = LISS(root->left) + LISS(root->right);

	// Calculate size including the current node
	int liss_incl = 1;
	if (root->left)
		liss_incl += LISS(root->left->left) + LISS(root->left->right);
	if (root->right)
		liss_incl += LISS(root->right->left) + LISS(root->right->right);

	// Maximum of two sizes is LISS, store it for future uses.
	root->liss = max(liss_incl, liss_excl);

	return root->liss;
}

// A utility function to create a node
node* newNode(int data)
{
	node* temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	temp->liss = 0;
	return temp;
}

// Driver code
int main()
{
	// Let us construct the tree
	// given in the above diagram
	node *root	 = newNode(20);
	root->left		 = newNode(8);
	root->left->left	 = newNode(4);
	root->left->right	 = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right		 = newNode(22);
	root->right->right	 = newNode(25);

	cout << "Size of the Largest Independent Set is " << LISS(root);

	return 0;
}
```
Output:<br />
<pre>
Size of the Largest Independent Set is 5
</pre>
<pre>
Time Complexity: O(n) where n is the number of nodes in given Binary tree. 
</pre>
* [To top](#Table-of-Content)





  <br /><br /><br />
  ## Problem 40:
  **[Partition Equal Subset Sum](https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1)**<br />
Given an array `arr[]` of size `N`, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.<br />

>Example 1:<br />
Input: N = 4<br />
arr = {1, 5, 11, 5}<br />
Output: YES<br />
Explanation: <br />
The two parts are {1, 5, 5} and {11}.<br />

>Example 2:<br />
Input: N = 3<br />
arr = {1, 3, 5}<br />
Output: NO<br />
Explanation: This array can never be partitioned into two such parts.<br />

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `equalPartition()` which takes the value `N` and the `array` as input parameters and returns `1` if the partition is possible. Otherwise, returns `0`.<br />

<pre>
Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)
</pre>

* Constraints: `1 ≤ N ≤ 100`<br />
`1 ≤ arr[i] ≤ 1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int N, int arr[]){
      int sum =0;
        for(int i=0;i<N;i++)
        sum = sum+arr[i];
       
        return (sum%2==0) && solve(arr, sum/2, N);
        
    }
private:
    int sum = 0;
    
    bool solve(int arr[], int sum, int n){
        bool dp[n+1][sum + 1];
        
        for(int i=0;i<=n;i++) dp[i][0] = true; //subset with 0 sum
        
        for(int j=1;j<=sum;j++) dp[0][j] = false; //non-zero sum with 0 elements
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1] > j) dp[i][j] = dp[i-1][j]; //don't include ith element if it's greater then the rem sum
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
               
            }
        }
        
        return dp[n][sum];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        Solution ob;
        if(ob.equalPartition(n, arr))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)







  <br /><br /><br />
  ## Problem 41:
  **[Longest Palindromic Subsequence](https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/)**<br />
Given a sequence, find the length of the longest palindromic subsequence in it.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/longest-palindromic-subsequence.png"><br />
As another example, if the given sequence is `“BBABCBCAB”`, then the output should be `7` as `“BABCBAB”` is the longest palindromic subsequence in it. `“BBBBB”` and `“BBCBB”` are also palindromic subsequences of the given sequence, but not the longest ones.<br />
The naive solution for this problem is to generate all subsequences of the given sequence and find the longest palindromic subsequence. This solution is `exponential` in terms of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem and can efficiently be solved using Dynamic Programming.<br />
<br /><br />**1) Optimal Substructure:**<br />
Let `X[0..n-1]` be the input sequence of length `n` and `L(0, n-1)` be the length of the longest palindromic subsequence of `X[0..n-1]`.<br /> 
If last and first characters of `X` are same, then `L(0, n-1) = L(1, n-2) + 2`.<br />
Else `L(0, n-1) = MAX (L(1, n-1), L(0, n-2))`.<br />
Following is a general recursive solution with all cases handled.<br />
<pre>
// Every single character is a palindrome of length 1
L(i, i) = 1 for all indexes i in given sequence

// IF first and last characters are not same
If (X[i] != X[j])  L(i, j) =  max{L(i + 1, j),L(i, j - 1)} 

// If there are only 2 characters and both are same
Else if (j == i + 1) L(i, j) = 2  

// If there are more than two characters, and first and last 
// characters are same
Else L(i, j) =  L(i + 1, j - 1) + 2 
</pre>
<br /><br />**2) Overlapping Subproblems:**<br />
Following is a simple `recursive` implementation of the `LPS` problem. The implementation simply follows the recursive structure mentioned above.<br />
```cpp
// C++ program of above approach
#include<bits/stdc++.h>
using namespace std;

// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(char *seq, int i, int j)
{
// Base Case 1: If there is only 1 character
if (i == j)
	return 1;

// Base Case 2: If there are only 2
// characters and both are same
if (seq[i] == seq[j] && i + 1 == j)
	return 2;

// If the first and last characters match
if (seq[i] == seq[j])
	return lps (seq, i+1, j-1) + 2;

// If the first and last characters do not match
return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}

/* Driver program to test above functions */
int main()
{
	char seq[] = "GEEKSFORGEEKS";
	int n = strlen(seq);
	cout << "The length of the LPS is " << lps(seq, 0, n-1);
	return 0;
}
```
Output<br />
<pre>
The length of the LPS is 5
</pre>
Considering the above implementation, the following is a `partial recursion tree` for a sequence of length `6` with all different characters.<br /> 
<pre>
               L(0, 5)
             /        \ 
            /          \  
        L(1,5)          L(0,4)
       /    \            /    \
      /      \          /      \
  L(2,5)    L(1,4)  L(1,4)  L(0,3)
  </pre>
In the above partial recursion tree, `L(1, 4)` is being solved twice. If we draw the complete `recursion tree`, then we can see that there are many subproblems that are solved again and again. Since the same subproblems are called again, this problem has the `Overlapping Subproblems property`. So `LPS` problem has both properties (see this and this) of a dynamic programming problem. Like other typical Dynamic Programming(DP) problems, recomputations of the same subproblems can be avoided by constructing a `temporary array L[][] in a bottom-up manner`.<br />
<br /><br />**3) Dynamic Programming Solution:**<br />
```cpp
// A Dynamic Programming based C++ program for LPS problem
// Returns the length of the longest palindromic subsequence in seq
#include<stdio.h>
#include<string.h>

// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(char *str)
{
int n = strlen(str);
int i, j, cl;
int L[n][n]; // Create a table to store results of subproblems


// Strings of length 1 are palindrome of length 1
for (i = 0; i < n; i++)
	L[i][i] = 1;

	// Build the table. Note that the lower diagonal values of table are
	// useless and not filled in the process. The values are filled in a
	// manner similar to Matrix Chain Multiplication DP solution (See
	// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/). cl is length of
	// substring
	for (cl=2; cl<=n; cl++)
	{
		for (i=0; i<n-cl+1; i++)
		{
			j = i+cl-1;
			if (str[i] == str[j] && cl == 2)
			L[i][j] = 2;
			else if (str[i] == str[j])
			L[i][j] = L[i+1][j-1] + 2;
			else
			L[i][j] = max(L[i][j-1], L[i+1][j]);
		}
	}

	return L[0][n-1];
}

/* Driver program to test above functions */
int main()
{
	char seq[] = "GEEKSFORGEEKS";
	int n = strlen(seq);
	printf ("The length of the LPS is %d", lps(seq));
	getchar();
	return 0;
}
```
Output<br />
<pre>
The length of the LPS is 5
</pre>
<pre>
Time Complexity: O(n^2), which is much better than the worst-case time complexity of Naive Recursive implementation.
</pre>
<br /><br />**Using Memoization Technique of Dynamic programming:**<br />
The idea used here is to reverse the given input string and check the length of the longest common subsequence. That would be the answer for the longest palindromic subsequence.<br />
```cpp
// A Dynamic Programming based C++ program for LPS problem
// Returns the length of the longest palindromic subsequence
// in seq
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

// Returns the length of the longest palindromic subsequence
// in seq
int lps(string& s1, string& s2, int n1, int n2)
{
	if (n1 == 0 || n2 == 0) {
		return 0;
	}
	if (dp[n1][n2] != -1) {
		return dp[n1][n2];
	}
	if (s1[n1 - 1] == s2[n2 - 1]) {
		return dp[n1][n2] = 1 + lps(s1, s2, n1 - 1, n2 - 1);
	}
	else {
		return dp[n1][n2] = max(lps(s1, s2, n1 - 1, n2), lps(s1, s2, n1, n2 - 1));
	}
}

/* Driver program to test above functions */
int main()
{
	string seq = "GEEKSFORGEEKS";
	int n = seq.size();
	dp[n][n];
	memset(dp, -1, sizeof(dp));
	string s2 = seq;
	reverse(s2.begin(), s2.end());
	cout << "The length of the LPS is " << lps(s2, seq, n, n) << endl;
	return 0;
}
```
Output<br />
<pre>
The length of the LPS is 5
</pre>
<pre>
Time Complexity: O(n^2)
Auxiliary Space: (n^2)
</pre>
* [To top](#Table-of-Content)









  <br /><br /><br />
  ## Problem 42:
  **[Count All Palindromic Subsequence in a given String](https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1)**<br />
Given a string `str` of length `N`, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string `str`.<br />
Note: You have to return the answer module `10^9+7`;<br />
 
>Example 1:<br />
Input: <br />
Str = "abcd"<br />
Output: <br />
4<br />
Explanation:<br />
palindromic subsequence are : "a" ,"b", "c" ,"d"<br />
 

>Example 2:<br />
Input: <br />
Str = "aab"<br />
Output: <br />
4<br />
Explanation:<br />
palindromic subsequence are :"a", "a", "b", "aa"<br />
 

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `countPs()` which takes a string `str` as input parameter and returns the number of palindromic subsequence.<br />
 
<pre>
Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)
</pre>

* Constraints: `1<=length of string str <=1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    const long long int mod = 1000000007;
    long long int  countPS(string str){
        long long int N = str.length();
        long long int cps[N+1][N+1];
        memset(cps, 0, sizeof(cps));
        for(long long int i = 0;i<N;i++)cps[i][i] = 1;
        for(long long int L = 2;L<=N;L++){
            for(long long int i = 0;i<=N-L;i++){
                long long int k = L+i-1;
                if(str[i]==str[k])cps[i][k] = add(cps[i][k-1], add(cps[i+1][k], 1LL))%mod;
                else cps[i][k] = add(cps[i][k-1], sub(cps[i+1][k], cps[i+1][k-1]))%mod;
           }
       }
       return cps[0][N-1]%mod;
    }
    long long int add(long long int x, long long int y){
        return ((x%mod)+(y%mod))%mod;
    }
    long long int sub(long long int x, long long int y){
        return ((x%mod)-(y%mod)+mod)%mod;
    }
     
};

int main(){
    int t; cin>>t;
    while(t--){
        string str; cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    }
}
```
* [To top](#Table-of-Content)








  <br /><br /><br />
  ## Problem 43:
  **[5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)**<br />
Given a string `s`, return _the longest palindromic substring in_ `s`.<br />

>Example 1:<br />
Input: s = "babad"<br />
Output: "bab"<br />
Explanation: "aba" is also a valid answer.<br />

>Example 2:<br />
Input: s = "cbbd"<br />
Output: "bb"<br />
	
* Constraints: `1 <= s.length <= 1000`<br />
`s` consist of only digits and English letters.<br />
	
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();        
        if(n<=1) return s;
        
        // table[i][j] represents whether string i to j is a palindrome or NOT
        
        bool table[n][n];
        memset(table,false,sizeof(table));
        // Base condition => Single letter is always a palindrome
        for(int i=0;i<n;i++)table[i][i]=true;       
        // ex. str => Asome_palindromeA
        //              i................j
        //  if str[i]==str[j] and string i+1 to j-1 is
        //    pallindrome then str i to j is palindrome  
        
        // if len of str is 2 then
        // str[i+1]==[i] is condition for str to be pall...
        // Example  str=> C.C 
        //                i.i+1
        
        int start =0;
        int maxLen=1;
        
        for(int i=0;i<n;i++){
            if(s[i]==s[i+1]){
                start=i;
                maxLen=2;
                table[i][i+1]=true;
            }
        }
        
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(s[i]==s[j] && table[i+1][j-1]==true){
                    table[i][j]=true;
                    start=i;
                    if(maxLen<j-i+1)
                        maxLen=j-i+1;
                }
            }
        }
               
        return s.substr(start,maxLen);
        
    }
};
```
* [To top](#Table-of-Content)
	
	
	











  <br /><br /><br />
  ## Problem 44:
  **[Longest alternating subsequence](https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1)**<br />
A sequence `{x1, x2, .. xn}` is alternating sequence if its elements satisfy one of the following relations :<br />
`x1 < x2 > x3 < x4 > x5.....` or  `x1 >x2 < x3 > x4 < x5.....`<br />
Your task is to find the longest such sequence.<br />

>Example 1:<br />
Input: nums = {1,5,4}<br />
Output: 3<br />
Explanation: The entire sequenece is a alternating sequence.<br />

>Example 2:<br />
Input: nums = {1,17,5,10,13,15,10,5,16,8}<br />
Output: 7<br />
Explanation: There are several subsequences that achieve this length.<br /> 
One is {1,17,10,13,10,16,8}.<br />
 
**Your Task:**<br />
You dont need to read or print anything. Your task is to complete the function `AlternatingaMaxLength()` which takes the sequence  `nums` as input parameter and returns the maximum length of alternating sequence.<br />

<pre>
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
</pre>
	
* Constraints: `1 <= n <= 10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int AlternatingaMaxLength(vector<int>&nums){
	    if(nums.size() < 2)return nums.size();
		int up = 1, down = 1;
		for(int i = 1; i < nums.size(); i++){
			if(nums[i] > nums[i-1])up = down + 1;
			else if(nums[i] < nums[i-1])down  = up + 1;
		}
		return max(up, down);
	}
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>nums;
        for(int i = 0;i<n;i++)cin>>nums[i];
        Solution ob;
        int ans = ob.AlternatingaMaxLength(nums);
        cout<<ans<<endl;
    }
}
```
* [To top](#Table-of-Content)










  <br /><br /><br />
  ## Problem 45:
  **[Weighted Job Scheduling](https://www.geeksforgeeks.org/weighted-job-scheduling/)**<br />
Given `N` jobs where every job is represented by following three elements of it.<br />

 1. Start Time<br />
 2. Finish Time<br />
 3. Profit or Value Associated (>= 0)<br />
  
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
The following is the implementation of the above `naive recursive method`.<br />
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

// Find the latest job (in sorted array) that doesnt
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
The optimal profit is 250
</pre>
The above solution may contain many overlapping subproblems. For example, if `lastNonConflicting()` always returns the previous job, then `findMaxProfitRec(arr, n-1)` is called `twice` and the time complexity becomes `O(n*2^n)`. As another example when `lastNonConflicting()` returns previous to the previous job, there are two recursive calls, for `n-2` and `n-1`. In this example case, recursion becomes the same as Fibonacci Numbers.<br />
Like other Dynamic Programming Problems, we can solve this problem by making a table that stores solutions of subproblems.<br />
Below is an implementation based on Dynamic Programming.<br />
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

// Find the latest job (in sorted array) that doesnt
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
Time Complexity of the above Dynamic Programming Solution is O(n^2). 
	Note that the above solution can be optimized to O(nLogn) using 
	Binary Search in latestNonConflict() instead of linear search.
</pre>
* [To top](#Table-of-Content)







  

  <br /><br /><br />
  ## Problem 46:
  **[Coin game winner where every player has three choices](https://www.geeksforgeeks.org/coin-game-winner-every-player-three-choices/)**<br />
`A` and `B` are playing a game. At the beginning there are `n` coins. Given two more numbers `x` and `y`. In each move a player can pick `x` or `y` or `1` coins. A always starts the game. The player who picks the last coin wins the game or the person who is not able to pick any coin loses the game. For a given value of `n`, find whether `A` will win the game or not if both are playing optimally.<br />
**Examples:**<br />
<pre>
Input :  n = 5, x = 3, y = 4
Output : A
There are 5 coins, every player can pick 1 or
3 or 4 coins on his/her turn.
A can win by picking 3 coins in first chance.
Now 2 coins will be left so B will pick one 
coin and now A can win by picking the last coin.

Input : 2 3 4
Output : B
</pre>
Let us take few example values of `n` for `x = 3`, `y = 4`.<br /> 
`n = 0` `A` can not pick any coin so he losses <br />
`n = 1` `A` can pick `1` coin and win the game <br />
`n = 2` `A` can pick only `1` coin. Now `B` will pick `1` coin and win the game<br /> 
`n = 3` `4` `A` will win the game by picking `3` or `4` coins <br />
`n = 5`, `6` `A` will choose `3` or `4` coins. Now `B` will have to choose from `2` coins so `A` will win.<br />
We can observe that `A` wins game for `n` coins only when `B` loses for coins `n-1` or `n-x` or `n-y`. <br />
```cpp
// C++ program to find winner of game
// if player can pick 1, x, y coins
#include <bits/stdc++.h>
using namespace std;

// To find winner of game
bool findWinner(int x, int y, int n)
{
	// To store results
	int dp[n + 1];

	// Initial values
	dp[0] = false;
	dp[1] = true;

	// Computing other values.
	for (int i = 2; i <= n; i++) {

		// If A losses any of i-1 or i-x
		// or i-y game then he will
		// definitely win game i
		if (i - 1 >= 0 and !dp[i - 1])
			dp[i] = true;
		else if (i - x >= 0 and !dp[i - x])
			dp[i] = true;
		else if (i - y >= 0 and !dp[i - y])
			dp[i] = true;

		// Else A loses game.
		else
			dp[i] = false;
	}

	// If dp[n] is true then A will
	// game otherwise he losses
	return dp[n];
}

// Driver program to test findWinner();
int main()
{
	int x = 3, y = 4, n = 5;
	if (findWinner(x, y, n))
		cout << 'A';
	else
		cout << 'B';

	return 0;
}
```
Output:<br /> 
<pre>
A
</pre>
* [To top](#Table-of-Content)







  <br /><br /><br />
  ## Problem 47:
  **[Count Derangements (Permutation such that no element appears in its original position) [ IMPORTANT ]](https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/)**<br />
A `Derangement` is a `permutation` of `n` elements, such that no element appears in its original position. For example, a derangement of `{0, 1, 2, 3}` is `{2, 3, 1, 0}`.<br />
Given a number `n`, find the total number of Derangements of a set of `n` elements.<br />
**Examples :**<br />
<pre>
Input: n = 2
Output: 1
For two elements say {0, 1}, there is only one 
possible derangement {1, 0}

Input: n = 3
Output: 2
For three elements say {0, 1, 2}, there are two 
possible derangements {2, 0, 1} and {1, 2, 0}

Input: n = 4
Output: 9
For four elements say {0, 1, 2, 3}, there are 9
possible derangements {1, 0, 3, 2} {1, 2, 3, 0}
{1, 3, 0, 2}, {2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3,
1, 0}, {3, 0, 1, 2}, {3, 2, 0, 1} and {3, 2, 1, 0}
</pre>
Let `countDer(n)` be count of derangements for `n` elements. Below is the recursive relation to it.<br />
<pre>
countDer(n) = (n - 1) * [countDer(n - 1) + countDer(n - 2)]
</pre>
**How does above recursive relation work?**<br />
There are `n – 1` way for element `0` (this explains multiplication with `n – 1`).<br /> 
Let `0` be placed at index `i`. There are now `two` possibilities, depending on whether or not element `i` is placed at `0` in return.<br />

 1. **i is placed at 0:** This case is equivalent to solving the problem for `n-2` elements as two elements have just swapped their positions.<br />
 2. **i is not placed at 0:** This case is equivalent to solving the problem for `n-1` elements as now there are `n-1` elements, `n-1` positions and every element has `n-2` choices<br />
 
 Below is the simple solution based on the above `recursive` formula:<br />
 ```cpp
 // A Naive Recursive C++ program
// to count derangements
#include <bits/stdc++.h>
using namespace std;

int countDer(int n)
{
// Base cases
if (n == 1) return 0;
if (n == 2) return 1;

// countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
return (n - 1) * (countDer(n - 1) + countDer(n - 2));
}

// Driver Code
int main()
{
	int n = 4;
	cout << "Count of Derangements is " << countDer(n);
	return 0;
}
```
Output<br />
<pre>
Count of Derangements is 9
</pre>
<pre>
Time Complexity: O(2^n) since T(n) = T(n-1) + T(n-2) which is exponential.
Auxiliary Space: O(h) where h= log n is the maximum height of the tree.
</pre>
We can observe that this implementation does repetitive work. For example, see recursion tree for `countDer(5)`, `countDer(3)` is being evaluated twice.<br />
<pre>
              cdr() ==> countDer()

                    cdr(5)   
                 /         \     
             cdr(4)          cdr(3)   
           /      \         /     \
       cdr(3)     cdr(2)  cdr(2)   cdr(1)
</pre>
An **Efficient Solution** is to use Dynamic Programming to store results of subproblems in an array and build the array in bottom-up manner.<br />
```cpp
// A Dynamic programming based C++
// program to count derangements
#include <bits/stdc++.h>
using namespace std;

int countDer(int n)
{
	// Create an array to store
	// counts for subproblems
	int der[n + 1] = {0};

	// Base cases
	der[1] = 0;
	der[2] = 1;

	// Fill der[0..n] in bottom up manner
	// using above recursive formula
	for (int i = 3; i <= n; ++i)
		der[i] = (i - 1) * (der[i - 1] + der[i - 2]);

	// Return result for n
	return der[n];
}

// Driver code
int main()
{
	int n = 4;
	cout << "Count of Derangements is " << countDer(n);
	return 0;
}
```
Output<br />
<pre>
Count of Derangements is 9
</pre>
<pre>
Time Complexity : O(n) 
Auxiliary Space : O(n)
</pre>
A `More Efficient` Solution Without using **Extra Space**.
As we only need to remember only two previous values So, instead of Storing the values in an array two variables can be used to just store the required previous only.<br />
Below is the implementation of the above approach:<br />
```cpp
// C++ implementation of the above
// approach

#include <iostream>
using namespace std;

int countDer(int n)
{

	// base case
	if (n == 1 or n == 2) {
		return n - 1;
	}

	// Variable for just storing
	// previous values
	int a = 0;
	int b = 1;

	// using above recursive formula
	for (int i = 3; i <= n; ++i) {
		int cur = (i - 1) * (a + b);
		a = b;
		b = cur;
	}

	// Return result for n
	return b;
}

// Driver Code
int main()
{
	cout << "Count of Derangements is " << countDer(4);
	return 0;
}
```
Output<br />
<pre>
Count of Derangements is 9
</pre>
<pre>
Time Complexity: O(n) 
Auxiliary Space: O(1), since no extra space has been taken.
</pre>  
* [To top](#Table-of-Content)








  <br /><br /><br />
  ## Problem 48:
  **[Maximum profit by buying and selling a share at most twice [ IMP ]](https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/)**<br />
In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make `at most 2` transactions in a day, whereas the second transaction can only start after the first one is complete `(Buy->sell->Buy->sell)`. Given stock prices throughout the day, find out the maximum profit that a share trader could have made.<br />
**Examples:**<br />  
<pre>
Input:   price[] = {10, 22, 5, 75, 65, 80}
Output:  87
Trader earns 87 as sum of 12, 75 
Buy at 10, sell at 22, 
Buy at 5 and sell at 80
Input:   price[] = {2, 30, 15, 10, 8, 25, 80}
Output:  100
Trader earns 100 as sum of 28 and 72
Buy at price 2, sell at 30, buy at 8 and sell at 80
Input:   price[] = {100, 30, 15, 10, 8, 25, 80};
Output:  72
Buy at price 8 and sell at 80.
Input:   price[] = {90, 80, 70, 60, 50}
Output:  0
Not possible to earn.
</pre>
A **Simple Solution** is to consider every index `‘i’` and do the following<br />
<pre>
Max profit with at most two transactions = 
MAX {max profit with one transaction and subarray price[0..i] + 
max profit with one transaction and subarray price[i+1..n-1] } 
i varies from 0 to n-1.
</pre>
Maximum possible using one transaction can be calculated using the following `O(n)` algorithm<br />
The time complexity of the above simple solution is `O(n^2)`.<br />
We can do this `O(n)` using the following Efficient Solution. The idea is to store the maximum possible profit of every subarray and solve the problem in the following two phases.<br />

 1) Create a table `profit[0..n-1]` and initialize all values in it `0`.<br />
 2) Traverse `price[]` from right to left and update `profit[i]` such that `profit[i]` stores maximum profit achievable from one transaction in subarray `price[i..n-1]`<br />
 3) Traverse `price[]` from left to right and update `profit[i]` such that `profit[i]` stores maximum profit such that `profit[i]` contains maximum achievable profit from two transactions in subarray `price[0..i]`.<br />
 4) Return `profit[n-1]`<br />

To do step 2, we need to keep track of the maximum price from right to left side, and to do step 3, we need to keep track of the minimum price from left to right.<br />
**Why we traverse in reverse directions?**<br />
The idea is to save space, in the third step, we use the same array for both purposes, maximum with `1` transaction and maximum with `2` transactions. After iteration `i`, the array `profit[0..i]` contains the maximum profit with `2` transactions, and `profit[i+1..n-1]` contains profit with two transactions.<br />
Below are the implementations of the above idea.<br />
```cpp
// C++ program to find maximum
// possible profit with at most
// two transactions
#include <bits/stdc++.h>
using namespace std;

// Returns maximum profit with
// two transactions on a given
// list of stock prices, price[0..n-1]
int maxProfit(int price[], int n)
{
	// Create profit array and
	// initialize it as 0
	int* profit = new int[n];
	for (int i = 0; i < n; i++)
		profit[i] = 0;

	/* Get the maximum profit with
	only one transaction
	allowed. After this loop,
	profit[i] contains maximum
	profit from price[i..n-1]
	using at most one trans. */
	int max_price = price[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		// max_price has maximum
		// of price[i..n-1]
		if (price[i] > max_price)
			max_price = price[i];

		// we can get profit[i] by taking maximum of:
		// a) previous maximum, i.e., profit[i+1]
		// b) profit by buying at price[i] and selling at
		// max_price
		profit[i] = max(profit[i + 1], max_price - price[i]);
	}

	/* Get the maximum profit with two transactions allowed
	After this loop, profit[n-1] contains the result */
	int min_price = price[0];
	for (int i = 1; i < n; i++) {
		// min_price is minimum price in price[0..i]
		if (price[i] < min_price)
			min_price = price[i];

		// Maximum profit is maximum of:
		// a) previous maximum, i.e., profit[i-1]
		// b) (Buy, Sell) at (min_price, price[i]) and add
		// profit of other trans. stored in profit[i]
		profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
	}
	int result = profit[n - 1];

	delete[] profit; // To avoid memory leak

	return result;
}

// Driver code
int main()
{
	int price[] = { 2, 30, 15, 10, 8, 25, 80 };
	int n = sizeof(price) / sizeof(price[0]);
	cout << "Maximum Profit = " << maxProfit(price, n);
	return 0;
}
```
Output<br />
<pre>
Maximum Profit = 100
</pre>
<pre>
The time complexity of the above solution is O(n). 
Algorithmic Paradigm: Dynamic Programming   
</pre>
<br /><br />**Another approach:**<br />
Initialize four variables for taking care of the `first buy`, `first sell`, `second buy`, `second sell`. Set first buy and second buy as `INT_MIN` and first and second sell as `0`. This is to ensure to get profit from transactions. Iterate through the array and return the second sell as it will store maximum profit.<br />
```cpp
#include <iostream>
#include<climits>
using namespace std;

int maxtwobuysell(int arr[],int size) {
	int first_buy = INT_MIN;
	int first_sell = 0;
	int second_buy = INT_MIN;
	int second_sell = 0;
	
	for(int i=0;i<size;i++) {
		
		first_buy = max(first_buy,-arr[i]);//we set prices to negative, so the calculation of profit will be convenient
		first_sell = max(first_sell,first_buy+arr[i]);
		second_buy = max(second_buy,first_sell-arr[i]);//we can buy the second only after first is sold
		second_sell = max(second_sell,second_buy+arr[i]);
	
	}
	return second_sell;
}

int main() {

	int arr[] = {2, 30, 15, 10, 8, 25, 80};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<maxtwobuysell(arr,size);
	return 0;
}
```
Output<br />
<pre>
100
</pre>
<pre>
Time Complexity: O(N)
Auxiliary Space: O(1)  
</pre>
* [To top](#Table-of-Content)




  
  

  <br /><br /><br />
  ## Problem 49:
  **[Optimal Strategy For A Game](https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1)**<br />
You are given an array `A` of size `N`. The array contains integers and is of `even length`. The elements of the array represent `N` coin of values `V1, V2, ....Vn`. You play against an opponent in an alternating way.<br />
In each turn, a player selects `either` the `first` or `last` coin from the row, removes it from the row permanently, and receives the value of the coin.<br />
You need to determine the maximum possible amount of money you can win if you go first.<br />
**Note:** Both the players are playing optimally.<br />

>Example 1:<br />
Input:<br />
N = 4<br />
A[] = {5,3,7,10}<br />
Output: 15<br />
Explanation: The user collects maximum value as 15(10 + 5)<br />

>Example 2:<br />
Input:<br />
N = 4<br />
A[] = {8,15,3,7}<br />
Output: 22<br />
Explanation: The user collects maximum value as 22(7 + 15)<br />

**Your Task:**<br />
Complete the function `maximumAmount()` which takes an array `arr[]` (represent values of `N` coins) and `N` as number of coins as a parameter and returns the maximum possible amount of money you can win if you go first.<br />

<pre>
Expected Time Complexity : O(N*N)
Expected Auxiliary Space: O(N*N)
</pre>

* Constraints: `2 <= N <= 10^3`<br />
`1 <= Ai <= 10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long maximumAmount(int arr[], int n){
        int table[n][n];
        for(int gap = 0;gap<n;++gap){
            for(int i = 0, j = gap; j<n; i++, j++){
                int x = ((i+2) <= j)? table[i+2][j] : 0;
                int y = ((i+1) <= (j-1))? table[i+1][j-1] : 0;
                int z = (i <= (j-2))?table[i][j-2] : 0;
                table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
            }
        }
        return table[0][n-1];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)cin>>a[i];
        Solution ob;
        cout<<ob.maximumAmount(a, n)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)









  <br /><br /><br />
  ## Problem 50:
  **[Optimal Binary Search Tree](https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/)**<br />
Given a sorted array `key [0.. n-1]` of search keys and an array `freq[0.. n-1]` of frequency counts, where `freq[i]` is the number of searches for `keys[i]`. Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.<br />
Let us first define the cost of a `BST`. The cost of a `BST` node is the level of that node multiplied by its frequency. The level of the root is `1`.<br />
Examples:<br />  
<pre>
Input:  keys[] = {10, 12}, freq[] = {34, 50}
There can be following two possible BSTs 
        10                       12
          \                     / 
           12                 10
          I                     II
Frequency of searches of 10 and 12 are 34 and 50 respectively.
The cost of tree I is 34*1 + 50*2 = 134
The cost of tree II is 50*1 + 34*2 = 118 


Input:  keys[] = {10, 12, 20}, freq[] = {34, 8, 50}
There can be following possible BSTs
    10                12                 20         10              20
      \             /    \              /             \            /
      12          10     20           12               20         10  
        \                            /                 /           \
         20                        10                12             12  
     I               II             III             IV             V
Among all possible BSTs, cost of the fifth BST is minimum.  
Cost of the fifth BST is 1*50 + 2*34 + 3*8 = 142 
</pre>
<br /><br />**1) Optimal Substructure:**<br />
The optimal cost for `freq[i..j]` can be `recursively` calculated using the following formula.<br /> 
<img src = "https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-e4743c2643482de74b0d72a870910016_l3.svg"><br />
We need to calculate `optCost(0, n-1)` to find the result.<br /> 
The idea of above formula is simple, we one by one try all nodes as root (`r` varies from `i` to `j` in second term). When we make `rth` node as root, we recursively calculate optimal cost from `i` to `r-1` and `r+1` to `j`.<br /> 
We add sum of frequencies from `i` to `j` (see first term in the above formula)<br />
<br /><br />**The reason for adding the sum of frequencies from i to j:**<br />
This can be divided into `2` parts one is the `freq[r]+sum of frequencies of all elements from i to j except r`. The term `freq[r]` is added because it is going to be root and that means level of `1`, so `freq[r]*1=freq[r]`. Now the actual part comes, we are adding the frequencies of remaining elements because as we take `r` as root then all the elements other than that are going `1` level down than that is calculated in the subproblem. Let me put it in a more clear way, for calculating `optcost(i,j)` we assume that the `r` is taken as root and calculate `min` of `opt(i,r-1)+opt(r+1,j)` for all `i<=r<=j`.<br /> 
Here for every subproblem we are  choosing one node as a root. But in reality the level of subproblem root and all its descendant nodes will be `1` greater than the level of the parent problem root. Therefore the frequency of all the nodes except `r` should be added which accounts to the descend in their level compared to level assumed in subproblem.<br />
<br /><br />**2) Overlapping Subproblems**<br />
Following is recursive implementation that simply follows the recursive structure mentioned above.<br />
```cpp
// A naive recursive implementation of
// optimal binary search tree problem
#include <bits/stdc++.h>
using namespace std;

// A utility function to get sum of
// array elements freq[i] to freq[j]
int sum(int freq[], int i, int j);

// A recursive function to calculate
// cost of optimal binary search tree
int optCost(int freq[], int i, int j)
{
	// Base cases
	if (j < i) // no elements in this subarray
		return 0;
	if (j == i) // one element in this subarray
		return freq[i];
	
	// Get sum of freq[i], freq[i+1], ... freq[j]
	int fsum = sum(freq, i, j);
	
	// Initialize minimum value
	int min = INT_MAX;
	
	// One by one consider all elements
	// as root and recursively find cost
	// of the BST, compare the cost with
	// min and update min if needed
	for (int r = i; r <= j; ++r)
	{
		int cost = optCost(freq, i, r - 1) +
				optCost(freq, r + 1, j);
		if (cost < min)
			min = cost;
	}
	
	// Return minimum value
	return min + fsum;
}

// The main function that calculates
// minimum cost of a Binary Search Tree.
// It mainly uses optCost() to find
// the optimal cost.
int optimalSearchTree(int keys[], int freq[], int n)
{
	// Here array keys[] is assumed to be
	// sorted in increasing order. If keys[]
	// is not sorted, then add code to sort
	// keys, and rearrange freq[] accordingly.
	return optCost(freq, 0, n - 1);
}

// A utility function to get sum of
// array elements freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
	s += freq[k];
	return s;
}

// Driver Code
int main()
{
	int keys[] = {10, 12, 20};
	int freq[] = {34, 8, 50};
	int n = sizeof(keys) / sizeof(keys[0]);
	cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n);
	return 0;
}
```
Output:<br />
<pre>
Cost of Optimal BST is 142
</pre>
<pre>
Time complexity of the above naive recursive approach is exponential.
</pre>
It should be noted that the above function computes the same subproblems again and again. We can see many subproblems being repeated in the following recursion tree for `freq[1..4]`.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/matrixchainmultiplication.png"><br />
Since same subproblems are called again, this problem has `Overlapping Subproblems property`. So `optimal BST` problem has both properties (`Overlapping Subproblems` and `Optimal Substructure`) of a dynamic programming problem. Like other typical Dynamic Programming(DP) problems, recomputations of same subproblems can be avoided by constructing a `temporary array cost[][] in bottom up` manner.<br />
<br /><br />**Dynamic Programming Solution**<br />
Following is C/C++ implementation for `optimal BST problem` using Dynamic Programming. We use an `auxiliary array cost[n][n]` to store the solutions of subproblems. `cost[0][n-1]` will hold the final result. The challenge in implementation is, all diagonal values must be filled first, then the values which lie on the line just above the diagonal. In other words, we must first fill all `cost[i][i]` values, then all `cost[i][i+1]` values, then all `cost[i][i+2]` values. 
**So how to fill the 2D array in such manner ?**<br /> 
The idea used in the implementation is same as Matrix Chain Multiplication problem, we use a variable `‘L’` for chain length and increment `‘L’`, one by one. We calculate column number `‘j’` using the values of `‘i’` and `‘L’`.<br />
```cpp
// Dynamic Programming code for Optimal Binary Search
// Tree Problem
#include <bits/stdc++.h>
using namespace std;

// A utility function to get sum of array elements
// freq[i] to freq[j]
int sum(int freq[], int i, int j);

/* A Dynamic Programming based function that calculates
minimum cost of a Binary Search Tree. */
int optimalSearchTree(int keys[], int freq[], int n)
{
	/* Create an auxiliary 2D matrix to store results
	of subproblems */
	int cost[n][n];

	/* cost[i][j] = Optimal cost of binary search tree
	that can be formed from keys[i] to keys[j].
	cost[0][n-1] will store the resultant cost */

	// For a single key, cost is equal to frequency of the key
	for (int i = 0; i < n; i++)
		cost[i][i] = freq[i];

	// Now we need to consider chains of length 2, 3, ... .
	// L is chain length.
	for (int L = 2; L <= n; L++)
	{
		// i is row number in cost[][]
		for (int i = 0; i <= n-L+1; i++)
		{
			// Get column number j from row number i and
			// chain length L
			int j = i+L-1;
			cost[i][j] = INT_MAX;

			// Try making all keys in interval keys[i..j] as root
			for (int r = i; r <= j; r++)
			{
			// c = cost when keys[r] becomes root of this subtree
			int c = ((r > i)? cost[i][r-1]:0) + ((r < j)? cost[r+1][j]:0) + sum(freq, i, j);
			if (c < cost[i][j])
				cost[i][j] = c;
			}
		}
	}
	return cost[0][n-1];
}

// A utility function to get sum of array elements
// freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
	s += freq[k];
	return s;
}

// Driver code
int main()
{
	int keys[] = {10, 12, 20};
	int freq[] = {34, 8, 50};
	int n = sizeof(keys)/sizeof(keys[0]);
	cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n);
	return 0;
}
```
Output:<br />
<pre>
Cost of Optimal BST is 142
</pre>
**Notes**<br />
 1) The time complexity of the above solution is `O(n^4)`. The time complexity can be easily reduced to `O(n^3)` by pre-calculating sum of frequencies instead of calling `sum()` again and again.<br />
 2) In the above solutions, we have computed optimal cost only. The solutions can be easily modified to store the structure of `BSTs` also. We can create another auxiliary array of size `n` to store the structure of tree. All we need to do is, store the chosen `‘r’` in the innermost loop.<br />
* [To top](#Table-of-Content) 
 










  <br /><br /><br />
  ## Problem 51:
  **[Palindrome PartitioningProblem](https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1)**<br />
Given a string `str`, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.<br />

>Example 1:<br />
Input: str = "ababbbabbababa"<br />
Output: 3<br />
Explaination: After 3 partitioning substrings are "a", "babbbab", "b", "ababa".<br />

>Example 2:<br />
Input: str = "aaabba"<br />
Output: 1<br />
Explaination: The substrings after 1 partitioning are "aa" and "abba".<br />

**Your Task:**<br />
You do not need to read input or print anything, Your task is to complete the function `palindromicPartition()` which takes the string `str` as the input parameter and returns the minimum number of partitions required.<br />

<pre>
Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)
</pre>

* Constraints: `1 ≤ length of str ≤ 500`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int palindromicPartition(string str){
        int n = str.size();
        int c[n], i, j, k, l;
        bool p[n][n];
        for(i = 0;i<n;i++)p[i][i] = true;
        for(l = 2;l<=n;l++){
            for(i = 0;i<n-l+1;i++){
                j = i+l-1;
                if(l == 2)p[i][j] = (str[i] == str[j]);
                else p[i][j] = ((str[i] == str[j]) & p[i+1][j-1]);
            }
        }
        for(i = 0;i<n;i++){
            if(p[0][i])c[i] = 0;
            else {
                c[i] = INT_MAX;
                for(j = 0;j<i;j++){
                    if(p[j+1][i] == true & c[j]+1<c[i])c[i] = c[j]+1;
                }
            }
        }
        return c[n-1];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string str; cin>>str;
        Solution ob;
        cout<<ob.palindromicPartition(str)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)









  <br /><br /><br />
  ## Problem 52:
  **[Word Wrap Problem](https://practice.geeksforgeeks.org/problems/word-wrap1646/1)**<br />
Given an array `nums[]` of size `n`, where `nums[i]` denotes the number of characters in one word. Let `K` be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.<br />
Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line **except the last one**.<br /> 
You have to **minimize** the following total cost where **total cost** = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)^2.<br />

>Example 1:<br />
<pre>
Input: nums = {3,2,2,5}, k = 6
Output: 10
Explanation: Given a line can have 6
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4
So total cost = (6-3)2 + (6-2-2-1)2 = 32+12 = 10.
As in the first line word length = 3 thus
extra spaces = 6 - 3 = 3 and in the second line
there are two word of length 2 and there already
1 space between two word thus extra spaces
= 6 - 2 -2 -1 = 1. As mentioned in the problem
description there will be no extra spaces in
the last line. Placing first and second word
in first line and third word on second line
would take a cost of 02 + 42 = 16 (zero spaces
on first line and 6-2 = 4 spaces on second),
which isn't the minimum possible cost.
</pre>
>Example 2:<br />
<pre>
Input: nums = {3,2,2}, k = 4
Output: 5
Explanation: Given a line can have 4 
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 2
Line number 3: From word no. 3 to 3
Same explaination as above total cost
= (4 - 3)2 + (4 - 2)2 = 5.
</pre>
Your Task:<br />
You dont need to read or print anyhting. Your task is to complete the function `solveWordWrap()` which takes nums and k as input paramater and returns the minimized total cost.<br />
 
<pre>
Expected Time Complexity: O(n^2)
Expected Space Complexity: O(n)
</pre>
 
* Constraints: `1 ≤ n ≤ 500`<br />
`1 ≤ nums[i] ≤ 1000`<br />
`max(nums[i]) ≤ k ≤ 2000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k){ 
        int n = nums.size();
        int i, j, currlen, cost;
        vector<int>dp(n,0);
        vector<int>ans(n,0);
        dp[n-1] = 0;
        ans[n-1] = n-1;
        for(i = n-2;i>=0;i--){
            currlen = -1;
            dp[i] = INT_MAX;
            for(j = i;j<n;j++){
                currlen += (nums[j]+1);
                if(currlen>k)break;
                if(j == n-1)cost = 0;
                else cost = (k-currlen)*(k-currlen)+dp[j+1];
                if(cost<dp[i]){
                    dp[i] = cost;
                    ans[i] = j;
                }
            }
        }
        int res = 0;
        i = 0;
        while (i<n){
            int pos = 0;
            for(int j = i;j<ans[i]+1;j++)pos += nums[j];
            int x = ans[i]-i;
            if(ans[i]+1 != nums.size())res += (k-x-pos)*(k-x-pos);
            i = ans[i]+1;
        }
        return res;
    } 
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
    }
    return 0;
} 
```
* [To top](#Table-of-Content)








  <br /><br /><br />
  ## Problem 53:
  **[Mobile Numeric Keypad Problem [ IMP ]](https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1)**<br />
Given the mobile numeric keypad. You can only press buttons that are `up`, `left`, `right`, or `down` to the current button. You are not allowed to press bottom row corner buttons (i.e. `*` and `#` ). Given a number `N`, the task is to find out the number of possible numbers of the given length.<br />

>Example 1:<br />
Input: 1<br />
Output: 10<br />
Explanation: Number of possible numbers would be 10 (0, 1, 2, 3, …., 9)<br />

>Example 2:<br />
Input: N = 2<br />
Output: 36<br />
Explanation: Possible numbers: 00, 08, 11, 12, 14, 22, 21, 23, 25 and so on.<br />
If we start with 0, valid numbers will be 00, 08 (count: 2)<br />
If we start with 1, valid numbers will be 11, 12, 14 (count: 3)<br />
If we start with 2, valid numbers will be 22, 21, 23,25 (count: 4)<br />
If we start with 3, valid numbers will be 33, 32, 36 (count: 3)<br />
If we start with 4, valid numbers will be 44,41,45,47 (count: 4)<br />
If we start with 5, valid numbers will be 55,54,52,56,58 (count: 5) <br />
and so on..<br />

**Your Task:**<br />  
You don't need to read input or print anything. Complete the function `getCount()` which takes `N` as input parameter and returns the integer value.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
</pre>

* Constraints: `1 ≤ N ≤ 25`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	long long getCount(int N){
		char keypad[4][3] = {{'1', '2', '3'},
		                     {'4', '5', '6'},
		                     {'7', '8', '9'},
		                     {'*', '0', '#'}};
		return getCountUtil(keypad, N);
	}
	
	long long getCountUtil(char keypad[][3], int n){
	    if(keypad == NULL || n <= 0)return 0;
	    if(n==1)return 10;
	    int row[] = {0, 0, -1, 0, 1};
	    int col[] = {0, -1, 0, 1, 0};
	    long long count[10][n+1];
	    int i = 0, j = 0, k = 0, move = 0, ro = 0, co = 0, num = 0;
	    long long nextNum = 0, totalCount = 0;
	    for(i = 0;i<=9;i++){
	        count[i][0] = 0;
	        count[i][1] = 1;
	    }
	    for(k = 2; k<=n;k++){
	        for(i = 0;i<4;i++){
	            for(j = 0;j<3;j++){
	                if(keypad[i][j] != '*' && keypad[i][j] != '#'){
	                    num = keypad[i][j]-'0';
	                    count[num][k] = 0;
	                    for(move = 0;move<5;move++){
	                        ro = i+row[move];
	                        co = j+col[move];
	                        if(ro>=0 && ro<=3 && co>=0 && co<=2 && keypad[ro][co] != '*' && keypad[ro][co] != '#'){
	                            nextNum = keypad[ro][co]-'0';
	                            count[num][k]+=count[nextNum][k-1];
	                        }
	                    }
	                }
	            }
	        }
	    }
	    totalCount = 0;
	    for(i = 0;i<=9;i++)totalCount += count[i][n];
	    return totalCount;
	}
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Solution ob;
        cout<<ob.getCount(n)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)







  <br /><br /><br />
  ## Problem 54:
  **[Boolean Parenthesization Problem](https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1)**<br />
Given a boolean expression `S` of length `N` with following symbols.<br />
<pre>
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
</pre>
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to `true`.<br />
 
>Example 1:<br />
Input: N = 7<br />
S = T|T&F^T<br />
Output: 4<br />
Explaination: The expression evaluates to true in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).<br />

>Example 2:<br />
Input: N = 5<br />
S = T^F|F<br />
Output: 2<br />
Explaination: ((T^F)|F) and (T^(F|F)) are the only ways.<br />
 
**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `countWays()` which takes `N` and `S` as input parameters and returns number of possible ways modulo `1003`.<br />

<pre>
Expected Time Complexity: O(N^3)
Expected Auxiliary Space: O(N^2)
</pre>
 
* Constraints: `1 ≤ N ≤ 200`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countWays(int N, string S){
        int i, j, len;
        int dpTrue[N][N], dpFalse[N][N];
        for(i = 0;i<N;i+=2){
            if(S[i]== 'T'){
                dpTrue[i][i] = 1;
                dpFalse[i][i] = 0;
            }
            else {
                dpTrue[i][i] = 0;
                dpFalse[i][i] = 1;
            }
        }
        int x = 2;
        while(x<N){
            for(i = 0;(i+x)<N;i+=2){
                dpTrue[i][i+x] = dpFalse[i][i+x] = 0;
                for(j = i+1;j<(i+x);j+=2){
                    if(S[j] == '|'){
                        dpTrue[i][i+x] = (dpTrue[i][i+x] + dpTrue[i][j-1]*dpTrue[j+1][i+x] + dpTrue[i][j-1]*dpFalse[j+1][i+x] + dpFalse[i][j-1]*dpTrue[j+1][i+x])%1003;                              
                        dpFalse[i][i+x] = (dpFalse[i][i+x] + dpFalse[i][j-1]*dpFalse[j+1][i+x])%1003;
                    }else if(S[j] == '&'){
                        dpFalse[i][i+x] = (dpFalse[i][i+x] + dpFalse[i][j-1]*dpFalse[j+1][i+x] + dpTrue[i][j-1]*dpFalse[j+1][i+x] + dpFalse[i][j-1]*dpTrue[j+1][i+x])%1003;
                        dpTrue[i][i+x] = (dpTrue[i][i+x] + dpTrue[i][j-1]*dpTrue[j+1][i+x])%1003;
                    }else{
                        dpTrue[i][i+x] = (dpTrue[i][i+x] + dpFalse[i][j-1]*dpTrue[j+1][i+x] + dpTrue[i][j-1]*dpFalse[j+1][i+x])%1003;
                        dpFalse[i][i+x] = (dpFalse[i][i+x] + dpFalse[i][j-1]*dpFalse[j+1][i+x] + dpTrue[i][j-1]*dpTrue[j+1][i+x])%1003;
                    }
                }
            }
            x += 2;
        }
        return dpTrue[0][N-1]%1003;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int N; cin>>N;
        string s; cin>>s;
        Solution ob;
        cout<<ob.countWays(N, s)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)




  <br /><br /><br />
  ## Problem 55:
  **[Largest rectangular sub-matrix whose sum is 0](https://www.geeksforgeeks.org/largest-rectangular-sub-matrix-whose-sum-0/)**<br />
Given a `2D matrix`, find the largest rectangular sub-matrix whose sum is `0`. for example consider the following `N x M` input matrix<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/matrix-sum-0.png"><br />
**Examples:**<br />
<pre>
Input :  1,  2,  3
        -3, -2, -1          
         1,  7,  5

Output : 1,  2,  3          
        -3, -2, -1

Input :  9,  7, 16,  5
         1, -6, -7,  3          
         1,  8,  7,  9          
         7, -2,  0, 10

Output :-6, -7
          8,  7          
         -2,  0 
</pre>
The naive solution for this problem is to check every possible rectangle in given 2D array. This solution requires `4 nested loops` and time complexity of this solution would be `O(n^4)`.<br />
The solution is based on Maximum sum rectangle in a `2D matrix`. The idea is to reduce the problem to `1 D array`. We can use Hashing to find maximum length of sub-array in `1-D array` in `O(n)` time. We fix the left and right columns one by one and find the largest sub-array with `0` sum contiguous rows for every left and right column pair. We basically find top and bottom row numbers (which have sum is zero) for every fixed left and right column pair.<br />
To find the `top` and `bottom` row numbers, calculate sum of elements in every row from `left` to `right` and store these sums in an array say `temp[]`. So `temp[i]` indicates sum of elements from `left` to `right` in row `i`. If we find largest subarray with `0` sum on `temp`, and no. of elements is greater than previous no. of elements then update the values of `final row_up`, `final row_down`, `final col_left`, `final col_right`.<br />
**Implementation:**<br />
```cpp
// A C++ program to find Largest rectangular
// sub-matrix whose sum is 0
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// This function basically finds largest 0
// sum subarray in temp[0..n-1]. If 0 sum
// does't exist, then it returns false. Else
// it returns true and sets starting and
// ending indexes as starti and endj.
bool sumZero(int temp[], int* starti,
			int* endj, int n)
{
	// Map to store the previous sums
	map<int, int> presum;
	int sum = 0; // Initialize sum of elements

	// Initialize length of sub-array with sum 0
	int max_length = 0;

	// Traverse through the given array
	for (int i = 0; i < n; i++)
	{
		// Add current element to sum
		sum += temp[i];

		if (temp[i] == 0 && max_length == 0)
		{
			*starti = i;
			*endj = i;
			max_length = 1;
		}
		if (sum == 0)
		{
			if (max_length < i + 1)
			{
				*starti = 0;
				*endj = i;
			}
			max_length = i + 1;
		}

		// Look for this sum in Hash table
		if (presum.find(sum) != presum.end())
		{
			// store previous max_length so
			// that we can check max_length
			// is updated or not
			int old = max_length;

			// If this sum is seen before,
			// then update max_len
			max_length = max(max_length, i - presum[sum]);

			if (old < max_length)
			{
				// If max_length is updated then
				// enter and update start and end
				// point of array
				*endj = i;
				*starti = presum[sum] + 1;
			}
		}
		else

			// Else insert this sum with
			// index in hash table
			presum[sum] = i;
	}

	// Return true if max_length is non-zero
	return (max_length != 0);
}

// The main function that finds Largest rectangle
// sub-matrix in a[][] whose sum is 0.
void sumZeroMatrix(int a[][MAX], int row, int col)
{
	int temp[row];

	// Variables to store the final output
	int fup = 0, fdown = 0, fleft = 0, fright = 0;
	int sum;
	int up, down;
	int maxl = INT_MIN;

	// Set the left column
	for (int left = 0; left < col; left++)
	{
		// Initialize all elements of temp as 0
		memset(temp, 0, sizeof(temp));

		// Set the right column for the left column
		// set by outer loop
		for (int right = left; right < col; right++)
		{
			// Calculate sum between current left
			// and right for every row 'i'
			for (int i = 0; i < row; i++)
				temp[i] += a[i][right];

			// Find largest subarray with 0 sum in
			// temp[]. The sumZero() function also
			// sets values of start and finish. So
			// 'sum' is sum of rectangle between (start,
			// left) and (finish, right) which is
			// boundary columns strictly as left and right.
			bool sum = sumZero(temp, &up, &down, row);
			int ele = (down - up + 1) * (right - left + 1);

			// Compare no. of elements with previous
			// no. of elements in sub-Matrix.
			// If new sub-matrix has more elements
			// then update maxl and final boundaries
			// like fup, fdown, fleft, fright
			if (sum && ele > maxl)
			{
				fup = up;
				fdown = down;
				fleft = left;
				fright = right;
				maxl = ele;
			}
		}
	}

	// If there is no change in boundaries
	// than check if a[0][0] is 0
	// If it not zero then print
	// that no such zero-sum sub-matrix exists
	if (fup == 0 && fdown == 0 && fleft == 0 && fright == 0 && a[0][0] != 0) {
		cout << "No zero-sum sub-matrix exists";
		return;
	}

	// Print final values
	for (int j = fup; j <= fdown; j++)
	{
		for (int i = fleft; i <= fright; i++)
			cout << a[j][i] << " ";
		cout << endl;
	}
}

// Driver program to test above functions
int main()
{
	int a[][MAX] = { { 9,  7, 16, 5 }, 
	                 { 1, -6, -7, 3 },
			 { 1,  8,  7, 9 }, 
			 { 7, -2,  0, 10 } };

	int row = 4, col = 4;
	sumZeroMatrix(a, row, col);
	return 0;
}
```
Output<br />
<pre>
-6 -7 
8 7 
-2 0 
</pre>
* [To top](#Table-of-Content)




  <br /><br /><br />
  ## Problem 56:
  **[Largest area rectangular sub-matrix with equal number of 1’s and 0’s [ IMP ]](https://www.geeksforgeeks.org/largest-area-rectangular-sub-matrix-equal-number-1s-0s/)**<br />
Given a `binary matrix`. The problem is to find the largest area rectangular sub-matrix with equal number of `1’s` and `0’s`. Examples:<br />
<pre>
Input : mat[][] = { {0, 0, 1, 1},
                    {0, 1, 1, 0},
                    {1, 1, 1, 0},
                    {1, 0, 0, 1} }
Output : 8 sq. units
(Top, left): (0, 0)
(Bottom, right): (3, 1)

Input : mat[][] = { {0, 0, 1, 1},
                    {0, 1, 1, 1} }            
Output : 6 sq. units
</pre>
The naive solution for this problem is to check every possible rectangle in given `2D array` by counting the total number of `1’s` and `0’s` in that rectangle. This solution requires `4 nested loops` and time complexity of this solution would be `O(n^4)`. <br />
An efficient solution is based on Largest rectangular sub-matrix whose sum is `0` which reduces the time complexity to `O(n^3)`. First of all consider every `‘0’` in the matrix as `‘-1’`. Now, the idea is to reduce the problem to `1-D array`. We fix the `left` and `right` columns one by one and find the largest sub-array with `0` sum contiguous rows for every `left` and `right` column pair. We basically find `top` and `bottom` row numbers (which have sum zero) for every fixed `left` and `right` column pair. To find the `top` and `bottom` row numbers, calculate sum of elements in every row from `left` to `right` and store these sums in an array say `temp[]`. <br />
So `temp[i]` indicates sum of elements from `left` to `right` in row `i`. If we find largest subarray with `0` sum in `temp[]`, we can get the index positions of rectangular sub-matrix with sum equal to `0` (i.e. having equal number of `1’s` and `0’s`). With this process we can find the largest area rectangular sub-matrix with sum equal to `0` (i.e. having equal number of `1’s` and `0’s`). We can use Hashing technique to find maximum length sub-array with sum equal to `0` in `1-D array` in `O(n)` time. <br />
**Implementation:**<br />
```cpp
// C++ implementation to find largest area rectangular
// submatrix with equal number of 1's and 0's
#include <bits/stdc++.h>

using namespace std;

#define MAX_ROW 10
#define MAX_COL 10

// This function basically finds largest 0
// sum subarray in arr[0..n-1]. If 0 sum
// does't exist, then it returns false. Else
// it returns true and sets starting and
// ending indexes as start and end.
bool subArrWithSumZero(int arr[], int &start, int &end, int n)
{
	// to store cumulative sum
	int sum[n];
	
	// Initialize all elements of sum[] to 0
	memset(sum, 0, sizeof(sum));
	
	// map to store the indexes of sum
	unordered_map<int, int> um;
	
	// build up the cumulative sum[] array
	sum[0] = arr[0];
	for (int i=1; i<n; i++)
		sum[i] = sum[i-1] + arr[i];
	
	// to store the maximum length subarray
	// with sum equal to 0
	int maxLen = 0;
	
	// traverse to the sum[] array
	for (int i=0; i<n; i++)
	{
		// if true, then there is a subarray
		// with sum equal to 0 from the
		// beginning up to index 'i'
		if (sum[i] == 0)
		{
			// update the required variables
			start = 0;
			end = i;
			maxLen = (i+1);
		}
		
		// else if true, then sum[i] has not
		// seen before in 'um'
		else if (um.find(sum[i]) == um.end())
			um[sum[i]] = i;
		
		// sum[i] has been seen before in the
		// unordered_map 'um'
		else
		{
			// if previous subarray length is smaller
			// than the current subarray length, then
			// update the required variables
			if (maxLen < (i-um[sum[i]]))
			{
				maxLen = (i-um[sum[i]]);
				start = um[sum[i]] + 1;
				end = i;
			}
		}
	}
	
	// if true, then there is no
	// subarray with sum equal to 0
	if (maxLen == 0)
		return false;
		
	// else return true
	return true;
}

// function to find largest area rectangular
// submatrix with equal number of 1's and 0's
void maxAreaRectWithSumZero(int mat[MAX_ROW][MAX_COL], int row, int col)
{
	// to store intermediate values
	int temp[row], startRow, endRow;
	
	// to store the final outputs
	int finalLeft, finalRight, finalTop, finalBottom;
	finalLeft = finalRight = finalTop = finalBottom = -1;
	int maxArea = 0;
	
	// Set the left column
	for (int left = 0; left < col; left++)
	{
		// Initialize all elements of temp as 0
		memset(temp, 0, sizeof(temp));
		
		// Set the right column for the left column
		// set by outer loop
		for (int right = left; right < col; right++)
		{
			// Calculate sum between current left
			// and right for every row 'i'
			// consider value '1' as '1' and
			// value '0' as '-1'
			for (int i=0; i<row; i++)
				temp[i] += mat[i][right] ? 1 : -1;
				
			// Find largest subarray with 0 sum in
			// temp[]. The subArrWithSumZero() function
			// also sets values of finalTop, finalBottom,
			// finalLeft and finalRight if there exists
			// a subarray with sum 0 in temp
			if (subArrWithSumZero(temp, startRow, endRow, row))
			{
				int area = (right - left + 1) * (endRow - startRow + 1);

				// Compare current 'area' with previous area
				// and accordingly update final values
				if (maxArea < area)
				{
					finalTop = startRow;
					finalBottom = endRow;
					finalLeft = left;
					finalRight = right;			
					maxArea = area;
				}
			}
		}
	}
	
	// if true then there is no rectangular submatrix
	// with equal number of 1's and 0's
	if (maxArea == 0)
		cout << "No such rectangular submatrix exists:";
	
	// displaying the top left and bottom right boundaries
	// with the area of the rectangular submatrix
	else
	{
		cout << "(Top, Left): " << "(" << finalTop << ", " << finalLeft << ")" << endl;
		cout << "(Bottom, Right): " << "(" << finalBottom << ", " << finalRight << ")" << endl;
		cout << "Area: " << maxArea << " sq.units";
	}
}

// Driver program to test above
int main()
{
	int mat[MAX_ROW][MAX_COL] = { {0, 0, 1, 1},
		    		      {0, 1, 1, 0},
 				      {1, 1, 1, 0},
				      {1, 0, 0, 1} };
	int row = 4, col = 4;
	maxAreaRectWithSumZero(mat, row, col);
	return 0;				
					
}
```
Output<br />
<pre>
(Top, Left): (0, 0)
(Bottom, Right): (3, 1)
Area: 8 sq.units
</pre>
<pre>
Time Complexity: O(n^3) 
Auxiliary Space: O(n)
</pre>
* [To top](#Table-of-Content)








  <br /><br /><br />
  ## Problem 57:
  **[Maximum sum rectangle in a 2D matrix](https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1)**<br />
Given a `2D matrix M` of dimensions `RxC`. Find the maximum sum submatrix in it.<br />

>Example 1:<br />
Input:<br />
R=4<br />
C=5<br />
M=[[1,2,-1,-4,-20],<br />
[-8,-3,4,2,1],<br />
[3,8,10,1,3],<br />
[-4,-1,1,7,-6]]<br />
Output:<br />
29<br />
Explanation: The matrix is as follows and the<br />
blue rectangle denotes the maximum sum rectangle.<br />
<img src = "https://a.disquscdn.com/get?url=http%3A%2F%2Fwww.geeksforgeeks.org%2Fwp-content%2Fuploads%2Frectangle-11.png&key=6UHjdHyGWQGo6f_kdpoBIQ&w=320&h=247"><br />

>Example 2:<br />
Input:<br />
R=2<br />
C=2<br />
M=[[-1,-2],[-3,-4]]<br />
Output:<br />
-1<br />
Explanation: Taking only the first cell is the optimal choice.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `maximumSumRectangle()` which takes the number `R`, `C`, and the `2D matrix M` as input parameters and returns the maximum sum submatrix.<br />

<pre>
Expected Time Complexity:O(R*R*C)
Expected Auxillary Space:O(R*C)
</pre>

* Constraints: `1<=R,C<=500`<br />
`-1000<=M[i][j]<=1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Implementation of Kadane's algorithm for
    // 1D array. The function returns the maximum
    // sum and stores starting and ending indexes
    // of the maximum sum subarray at addresses
    // pointed by start and finish pointers
    // respectively.
    int kadane(int* arr, int* start, int* finish, int n) {
        // initialize sum, maxSum and
        int sum = 0, maxSum = INT_MIN, i;

        // Just some initial value to check
        // for all negative values case
        *finish = -1;

        // local variable
        int local_start = 0;

        for (i = 0; i < n; ++i) {
            sum += arr[i];
            if (sum < 0) {
                sum = 0;
                local_start = i + 1;
            } else if (sum > maxSum) {
                maxSum = sum;
                *start = local_start;
                *finish = i;
            }
        }

        // There is at-least one
        // non-negative number
        if (*finish != -1) return maxSum;

        // Special Case: When all numbers
        // in arr[] are negative
        maxSum = arr[0];
        *start = *finish = 0;

        // Find the maximum element in array
        for (i = 1; i < n; i++) {
            if (arr[i] > maxSum) {
                maxSum = arr[i];
                *start = *finish = i;
            }
        }
        return maxSum;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
        int left, right, i;
        int temp[R], sum, start, finish;
        for (left = 0; left < C; ++left) {
            memset(temp, 0, sizeof(temp));
            for (right = left; right < C; ++right) {
                for (i = 0; i < R; ++i) temp[i] += M[i][right];
                sum = kadane(temp, &start, &finish, R);
                if (sum > maxSum) {
                    maxSum = sum;
                    finalLeft = left;
                    finalRight = right;
                    finalTop = start;
                    finalBottom = finish;
                }
            }
        }
        return maxSum;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>>v (n, vector<int>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++) cin>>v[i][j]; 
        }
        Solution ob;
        cout<<ob.maximumSumRectangle(n, m, v)<<endl;
    }
}
```
* [To top](#Table-of-Content)










  <br /><br /><br />
  ## Problem 58:
  **[Maximum profit by buying and selling a share at most k times](https://practice.geeksforgeeks.org/problems/maximum-profit4657/1)**<br />
In the stock market, a person buys a stock and sells it on some future date. Given the stock prices of `N` days in an array `A[ ]` and a positive integer `K`, find out the maximum profit a person can make in `at-most K transactions`. A transaction is equivalent to `(buying + selling)` of a stock and new transaction can start only when the previous transaction has been completed.<br />

>Example 1:<br />
Input: K = 2, N = 6<br />
A = {10, 22, 5, 75, 65, 80}<br />
Output: 87<br />
Explaination: <br />
1st transaction: buy at 10 and sell at 22. <br />
2nd transaction : buy at 5 and sell at 80.<br />

>Example 2:<br />
Input: K = 3, N = 4<br />
A = {20, 580, 420, 900}<br />
Output: 1040<br />
Explaination: The trader can make at most 2 transactions and giving him a profit of 1040.<br />

>Example 3:<br />
Input: K = 1, N = 5<br />
A = {100, 90, 80, 50, 25}<br />
Output: 0<br />
Explaination: Selling price is decreasing daily. So seller cannot have profit.<br />

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `maxProfit()` which takes the values `K`, `N` and the `array A[]` as input parameters and returns the maximum profit.<br />

<pre>
Expected Time Complexity: O(N*K)
Expected Auxiliary Space: O(N*K)
</pre>

* Constraints: `1 ≤ N ≤ 500`<br />
`1 ≤ K ≤ 200`<br />
`1 ≤ A[ i ] ≤ 1000`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        if(N == 0) return 0;
        int n = K * 2 + 1;
        vector<int> dp(n, 0);
        for (int i = 0; i < K; i++) {
            dp[1 + i * 2] = -A[0];
        }
        for (int i = 1; i < N; i++) {
            dp[0] = dp[0];
            for (int j = 0; j < K; j++) {
                dp[1 + j * 2] = max(dp[1 + j * 2], dp[j * 2] - A[i]);
                dp[2 + j * 2] = max(dp[2 + j * 2], dp[1 + j * 2] + A[i]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < K; i++) ans = max(ans, dp[2 + i * 2]);
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int N, K;
        cin>>K>>N;
        int A[N];
        for(int i = 0;i<N;i++)cin>>A[i];
        Solution ob;
        cout<<ob.maxProfit(K, N, A)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)





  <br /><br /><br />
  ## Problem 59:
  **[Find if a string is interleaved of two other strings](https://practice.geeksforgeeks.org/problems/interleaved-strings/1)**<br />
Given strings `A`, `B`, and `C`, find whether `C` is formed by an interleaving of `A` and `B`.<br />
An interleaving of two strings `S` and `T` is a configuration such that it creates a new string `Y` from the concatenation substrings of `A` and `B` and `|Y| = |A + B| = |C|`<br />
For example:<br />
`A = "XYZ"`<br />
`B = "ABC"`<br />
so we can make multiple interleaving string `Y` like, `XYZABC`, `XAYBCZ`, `AXBYZC`, `XYAZBC` and many more so here your task is to check whether you can create a string `Y` which can be equal to `C`.<br />
Specifically, you just need to create substrings of string `A` and create substrings `B` and concatenate them and check whether it is equal to `C` or not.<br />
**Note:** `a + b` is the concatenation of strings `a` and `b`.<br />
Return `true` if `C` is formed by an interleaving of `A` and `B`, else return `false`.<br />

>Example 1:<br />
Input:<br />
A = YX, B = X, C = XXY<br />
Output: 0<br />
Explanation: XXY is not interleaving of YX and X<br />

>Example 2:<br />
Input:<br />
A = XY, B = X, C = XXY<br />
Output: 1<br />
Explanation: XXY is interleaving of XY and X.<br />

**Your Task:**<br />
Complete the function `isInterleave()` which takes three strings `A`, `B` and `C` as input and returns `true` if `C` is an interleaving of `A` and `B` else returns `false`. (`1` is printed by the driver code if the returned value is `true`, otherwise `0`.)<br />

<pre>
Expected Time Complexity: O(N * M)
Expected Auxiliary Space: O(N * M)
here, N = length of A, and M = length of B
</pre>

* Constraints: `1 ≤ length of A, B ≤ 100`<br />
`1 ≤ length of C ≤ 200`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    bool isInterleave(string A, string B, string C) {
        int m=A.size();
        int n=B.size();
        if(m==0 && n==0 && C.size()==0)return true;
        if(m+n !=C.size())return false;
        if(m==0 && n==0)return false;
        vector<vector<bool>> dp(m+1 , vector<bool>(n+1 , false));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            if(A[i-1]==C[i-1] && dp[i-1][0]==true)dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            if(B[i-1]==C[i-1] && dp[0][i-1]==true)dp[0][i]=true;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int k=i+j-1;
                if(A[i-1]==C[k] && dp[i-1][j]==true) dp[i][j]=true;
                if(B[j-1]==C[k] && dp[i][j-1]==true)dp[i][j]=true;
            }
        }
        return dp[m][n];
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string a, b, c;
        cin>>a>>b>>c;
        Solution ob;
        cout<<ob.isInterleave(a, b, c)<<endl;
    }
    return 0;
}
```
* [To top](#Table-of-Content)





  <br /><br /><br />
  ## Problem 60:
  **[646. Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/)**<br />
You are given an array of `n` pairs `pairs` where `pairs[i] = [lefti, righti]` and `lefti < righti`.<br />
A pair `p2 = [c, d]` **follows** a pair `p1 = [a, b]` if `b < c`. A **chain** of pairs can be formed in this fashion.<br />
Return _the length longest chain which can be formed_.<br />
You do not need to use up all the given intervals. You can select pairs in any order.<br />

>Example 1:<br />
Input: pairs = [[1,2],[2,3],[3,4]]<br />
Output: 2<br />
Explanation: The longest chain is [1,2] -> [3,4].<br />

>Example 2:<br />
Input: pairs = [[1,2],[7,8],[4,5]]<br />
Output: 3<br />
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].<br />
 
* Constraints: `n == pairs.length`<br />
`1 <= n <= 1000`<br />
`-1000 <= lefti < righti <= 1000`<br />
  
```cpp
class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), compare);
        int count = 1;
        int last = pairs[0][1];
        for(int i = 1; i < n; i++){
            if(pairs[i][0] > last){
                count++;
                last = pairs[i][1];
            }
        }
        return count;
    }
};
```
* [To top](#Table-of-Content)
