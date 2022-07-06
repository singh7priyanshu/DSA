# Leetcode daily easy question 
**[509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)**<br />
The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,<br />
<pre>
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
</pre>
Given `n`, calculate `F(n)`.<br />

>Example 1:<br />
Input: n = 2<br />
Output: 1<br />
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.<br />

>Example 2:<br />
Input: n = 3<br />
Output: 2<br />
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.<br />

>Example 3:<br />
Input: n = 4<br />
Output: 3<br />
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.<br />
 
* Constraints: `0 <= n <= 30`<br />

```cpp
class Solution {
public:
    int fib(int n) {
        if(n <= 1)return n;
        return fib(n-1) + fib(n-2);
    }
};
```
