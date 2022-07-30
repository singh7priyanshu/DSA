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

  <br /><br /><br />
  ## Problem 36:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 37:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 38:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 39:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 40:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 41:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 42:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 43:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 44:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 45:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 46:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 47:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 48:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 49:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 50:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 51:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 52:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 53:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 54:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 55:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 56:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 57:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 58:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 59:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 60:
  **[]()**<br />
  
  
