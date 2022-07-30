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
  **[]()**<br />

  <br /><br /><br />
  ## Problem 10:
  **[]()**<br />

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
