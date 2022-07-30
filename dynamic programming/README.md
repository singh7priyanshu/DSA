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
  **[]()**<br />

  <br /><br /><br />
  ## Problem 6:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 7:
  **[]()**<br />

  <br /><br /><br />
  ## Problem 8:
  **[]()**<br />

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
