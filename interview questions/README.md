# Interview Questions from Algorithm, data structure & Programming Skills
**[1523. Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/)**<br />
Given two non-negative integers `low` and `high`. Return the count of odd numbers between `low` and `high` _(inclusive)_.<br />

>Example 1:<br />
>Input: low = 3, high = 7<br />
>Output: 3<br />
>Explanation: The odd numbers between 3 and 7 are [3,5,7].<br />

>Example 2:<br />
>Input: low = 8, high = 10<br />
>Output: 1<br />
>Explanation: The odd numbers between 8 and 10 are [9].<br />
 
* Constraints:`0 <= low <= high <= 10^9`<br />

```cpp
class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low) / 2 + ((high & 1) | (low & 1));
    }
};
```



<br /> <br /> <br />**[1491. Average Salary Excluding the Minimum and Maximum Salary](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/)**<br />
You are given an array of **unique** integers `salary` where `salary[i]` is the salary of the `ith` employee.<br />
Return the _average salary of employees excluding the minimum and maximum salary_. Answers within `10^-5` of the actual answer will be accepted.<br />

>Example 1:<br />
>Input: salary = [4000,3000,1000,2000]<br />
>Output: 2500.00000<br />
>Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.<br />
>Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500<br />

>Example 2:<br />
>Input: salary = [1000,2000,3000]<br />
>Output: 2000.00000<br />
>Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.<br />
>Average salary excluding minimum and maximum salary is (2000) / 1 = 2000<br />
 
* Constraints:`3 <= salary.length <= 100`<br />
`1000 <= salary[i] <= 10^6`<br />
All the integers of `salary` are **unique**.<br />

```cpp
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin() ,salary.end()) ;
        int sum = 0, i;
        for(i =1 ; i<salary.size()-1 ; i++)sum+=salary[i];
        return double(sum/((i-1)*1.0));
    }
};
```




<br /> <br /> <br />**[191. Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)**<br />
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the `Hamming weight`).<br />
* Note:<br />
  * Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.<br />
  * In Java, the compiler represents the signed integers using `2's complement notation`. Therefore, in **Example 3**, the input represents the signed integer. `-3`.<br />
 
>Example 1:<br />
>Input: n = 00000000000000000000000000001011<br />
>Output: 3<br />
>Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.<br />

>Example 2:<br />
>Input: n = 00000000000000000000000010000000<br />
>Output: 1<br />
>Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.<br />

>Example 3:<br />
>Input: n = 11111111111111111111111111111101<br />
>Output: 31<br />
>Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.<br />
 
* Constraints: The input must be a **binary string** of length `32`.<br />

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0){
            if(n&1)count++;
            n= n>>1;
        } 
        return count;
    }
};
```



<br /> <br /> <br />**[1281. Subtract the Product and Sum of Digits of an Integer](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)**<br />
Given an integer number `n`, return the difference between the product of its digits and the sum of its digits.<br />
 
>Example 1:<br />
>Input: n = 234<br />
>Output: 15 <br />
>Explanation: <br />
>Product of digits = 2 * 3 * 4 = 24 <br />
>Sum of digits = 2 + 3 + 4 = 9 <br />
>Result = 24 - 9 = 15<br />

>Example 2:<br />
>Input: n = 4421<br />
>Output: 21<br />
>Explanation: <br />
>Product of digits = 4 * 4 * 2 * 1 = 32 <br />
>Sum of digits = 4 + 4 + 2 + 1 = 11 <br />
>Result = 32 - 11 = 21<br />

* Constraints: `1 <= n <= 10^5`<br />

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0, pro=1,rem;
        while(n>0){
            rem=n%10;
            sum+=rem;
            pro*=rem;
            n=n/10;
        }
        return pro-sum;
    }
};
```



<br /> <br /> <br />**[217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)**<br />
Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.<br />

>Example 1:<br />
>Input: nums = [1,2,3,1]<br />
>Output: true<br />

>Example 2:<br />
>Input: nums = [1,2,3,4]<br />
>Output: false<br />

>Example 3:<br />
>Input: nums = [1,1,1,3,3,4,3,2,4,2]<br />
>Output: true<br />
 
* Constraints: `1 <= nums.length <= 10^5`<br />
`-10^9 <= nums[i] <= 10^9`<br />
     
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        sort(begin(nums), end(nums));
        return adjacent_find(begin(nums), end(nums)) != end(nums);  
        */
        set<int> s;
        s.insert(nums.begin(),nums.end()); 
        bool ans = nums.size()!=s.size();  
        return ans;
    }
};
```



<br /> <br /> <br />**[53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)**<br />
Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return _its sum_.<br />
A **subarray** is a **contiguous** part of an array.<br />

>Example 1:<br />
>Input: nums = [-2,1,-3,4,-1,2,1,-5,4]<br />
>Output: 6<br />
>Explanation: [4,-1,2,1] has the largest sum = 6.<br />

>Example 2:<br />
>Input: nums = [1]<br />
>Output: 1<br />

>Example 3:<br />
>Input: nums = [5,4,-1,7,8]<br />
>Output: 23<br />
 
* Constraints: `1 <= nums.length <= 10^5`.<br />
`-10^4 <= nums[i] <= 10^4`<br />

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxh = 0, maxf = nums[0];
        for(int i=0;i<nums.size();i++){
            maxh+=nums[i];
            if(maxf<maxh) maxf = maxh;
            if(maxh<0) maxh = 0;
        }
        return maxf;
    }
};
```



<br /> <br /> <br />**[1. Two Sum](https://leetcode.com/problems/two-sum/)**<br />
Given an array of integers `nums` and an integer `target`, return _indices of the two numbers such that they add up to `target`_.<br />
You may assume that each input would have **exactly one solution**, and you may not use the _same_ element twice.<br />
You can return the answer in any order.<br />

>Example 1:<br />
>Input: nums = [2,7,11,15], target = 9<br />
>Output: [0,1]<br />
>Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].<br />

>Example 2:<br />
>Input: nums = [3,2,4], target = 6<br />
>Output: [1,2]<br />

>Example 3:<br />
>Input: nums = [3,3], target = 6<br />
>Output: [0,1]<br />

* Constraints: `2 <= nums.length <= 10^4`<br />
`-10^9 <= nums[i] <= 10^9`<br />
`-10^9 <= target <= 10^9`<br />
**Only one valid answer exists**.<br />

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;
        for (int i = 0;; ++i) {
            auto it = imap.find(target - nums[i]);
            if (it != imap.end()) return vector<int> {i, it->second};
            imap[nums[i]] = i;
        }
    }
};
```



<br /> <br /> <br />**[88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)**<br />
You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.<br />
**Merge** `nums1` and `nums2` into a single array sorted in **non-decreasing order**.<br />
The final sorted array should not be returned by the function, but instead be stored inside the array `nums1`. To accommodate this, e has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.<br />

>Example 1:<br />
>Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3<br />
>Output: [1,2,2,3,5,6]<br />
>Explanation: The arrays we are merging are [1,2,3] and [2,5,6].<br />
>The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.<br />

>Example 2:<br />
>Input: nums1 = [1], m = 1, nums2 = [], n = 0<br />
>Output: [1]<br />
>Explanation: The arrays we are merging are [1] and [].<br />
>The result of the merge is [1].<br />

>Example 3:<br />
>Input: nums1 = [0], m = 0, nums2 = [1], n = 1<br />
>Output: [1]<br />
>Explanation: The arrays we are merging are [] and [1].<br />
>The result of the merge is [1].<br />
>Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.<br />
 
* Constraints: `nums1.length == m + n`<br />
`nums2.length == n`<br />
`0 <= m, n <= 200`<br />
`1 <= m + n <= 200`<br />
`-10^9 <= nums1[i], nums2[j] <= 10^9`<br />

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        n --;m --;
        while(m >= 0 && n >= 0){
            if(nums1[m] > nums2[n]){
                nums1[m + n + 1] = nums1[m];
                m --;
            }
            else{
                nums1[m + n + 1] = nums2[n];
                n --;
            }
        }
        while(n >= 0){
            nums1[m + n + 1] = nums2[n];
            n --;
        }
    }
};
```



<br /> <br /> <br />**[704. Binary Search](https://leetcode.com/problems/binary-search/)**<br />
Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.<br />
You must write an algorithm with `O(log n)` runtime complexity.<br />

>Example 1:<br />
>Input: nums = [-1,0,3,5,9,12], target = 9<br />
>Output: 4<br />
>Explanation: 9 exists in nums and its index is 4<br />

>Example 2:<br />
>Input: nums = [-1,0,3,5,9,12], target = 2<br />
>Output: -1<br />
>Explanation: 2 does not exist in nums so return -1<br />
 
* Constraints: `1 <= nums.length <= 10^4`<br />
`-10^4 < nums[i], target < 10^4`<br />
All the integers in `nums` are **unique**.<br />
`nums` is sorted in ascending order.<br />

```cpp
class Solution{
public:
    int search(vector<int>& nums, int target){
        int last = nums.size()-1;
        int start = 0;
        while(start<=last){
            int mid = start + (last-start)/2; 
            if(nums[mid] == target)return mid;
            else if(nums[mid]>target)last = mid-1;
            else start = mid+1;
        }
        return -1;
    }
};
```


<br /> <br /> <br />**[278. First Bad Version](https://leetcode.com/problems/first-bad-version/)**<br />
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.<br />
Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.<br />
You are given an API `bool isBadVersion(version)` which returns whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.<br />

>Example 1:<br />
>Input: n = 5, bad = 4<br />
>Output: 4<br />
>Explanation:<br />
>call isBadVersion(3) -> false<br />
>call isBadVersion(5) -> true<br />
>call isBadVersion(4) -> true<br />
>Then 4 is the first bad version.<br />

>Example 2:<br />
>Input: n = 1, bad = 1<br />
>Output: 1<br />

* Constraints: `1 <= bad <= n <= 2^31 - 1`.<br />

```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int begin = 1;
        long int end = n;
        long int mid = (begin+end)/2;
        while (begin < end){
            if (isBadVersion(mid))
                end = mid-1;
            else
                begin = mid+1;
            mid = (begin+end)/2;
        }
        if (isBadVersion(mid))return mid;
        else return mid+1; 
    }
};
```



<br /> <br /> <br />**[35. Search Insert Position](https://leetcode.com/problems/search-insert-position/)**<br />
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.<br />
You must write an algorithm with `O(log n)` runtime complexity.<br />

>Example 1:<br />
>Input: nums = [1,3,5,6], target = 5<br />
>Output: 2<br />

>Example 2:<br />
>Input: nums = [1,3,5,6], target = 2<br />
>Output: 1<br />

>Example 3:<br />
>Input: nums = [1,3,5,6], target = 7<br />
>Output: 4<br />

* Constraints: `1 <= nums.length <= 10^4`.<br />
`-10^4 <= nums[i] <= 10^4`.<br />
`nums` contains **distinct** values sorted in **ascending** order.<br />
`-10^4 <= target <= 10^4`.<br />

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid,ans=-1;
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]<target){
                left = mid+1;
                ans = mid + 1;
            }
            else{
                ans = mid;
                right = mid-1;
            }
        }
        return ans;
    }
};
```




<br /> <br /> <br />**[977. Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)**<br />
Given an integer array `nums` sorted in **non-decreasing** order, return _an array of **the squares of each number** sorted in non-decreasing order_.<br />

>Example 1:<br />
>Input: nums = [-4,-1,0,3,10]<br />
>Output: [0,1,9,16,100]<br />
>Explanation: After squaring, the array becomes [16,1,0,9,100].<br />
>After sorting, it becomes [0,1,9,16,100].<br />

>Example 2:<br />
>Input: nums = [-7,-3,2,3,11]<br />
>Output: [4,9,9,49,121]<br />

* Constraints: `1 <= nums.length <= 10^4`. <br />
`-10^4 <= nums[i] <= 10^4`. <br />
`nums` is sorted in **non-decreasing** order.<br />

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++)nums[i] *= nums[i];
        sort(nums.begin(),nums.end());
        return nums;
    }
};
```




<br /> <br /> <br />**[189. Rotate Array](https://leetcode.com/problems/rotate-array/)**<br />
Given an array, rotate the array to the right by `k` steps, where `k` is non-negative.<br />

>Example 1:<br />
>Input: nums = [1,2,3,4,5,6,7], k = 3<br />
>Output: [5,6,7,1,2,3,4]<br />
>Explanation:<br />
>rotate 1 steps to the right: [7,1,2,3,4,5,6]<br />
>rotate 2 steps to the right: [6,7,1,2,3,4,5]<br />
>rotate 3 steps to the right: [5,6,7,1,2,3,4]<br />

>Example 2:<br />
>Input: nums = [-1,-100,3,99], k = 2<br />
>Output: [3,99,-1,-100]<br />
>Explanation: <br />
>rotate 1 steps to the right: [99,-1,-100,3]<br />
>rotate 2 steps to the right: [3,99,-1,-100]<br />
 

* Constraints: `1 <= nums.length <= 10^5`.<br />
`-2^31 <= nums[i] <= 2^31 - 1`.<br />
`0 <= k <= 10^5`.<br />

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
```




<br /> <br /> <br />**[1827. Minimum Operations to Make the Array Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/)**<br />
You are given an integer array `nums` **(0-indexed)**. In one operation, you can choose an element of the array and increment it by `1`.<br />
For example, if `nums = [1,2,3]`, you can choose to increment `nums[1]` to make `nums = [1,3,3]`.<br />
Return _the **minimum** number of operations needed to make `nums` **strictly increasing**_.<br />
An array `nums` is **strictly increasing** if `nums[i] < nums[i+1]` for all `0 <= i < nums.length - 1`. An array of length `1` is trivially strictly increasing.<br />

>Example 1:<br />
>Input: nums = [1,1,1]<br />
>Output: 3<br />
>Explanation: You can do the following operations:<br />
>1) Increment nums[2], so nums becomes [1,1,2].<br />
>2) Increment nums[1], so nums becomes [1,2,2].<br />
>3) Increment nums[2], so nums becomes [1,2,3].<br />

>Example 2:<br />
>Input: nums = [1,5,2,4,1]<br />
>Output: 14<br />

>Example 3:<br />
>Input: nums = [8]<br />
>Output: 0<br />
 

* Constraints: `1 <= nums.length <= 5000`.<br />
`1 <= nums[i] <= 10^4`.<br />

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int step = 0;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] <= nums[i - 1]){
                int diff = (nums[i - 1] + 1) - nums[i];
                nums[i] += diff;
                step += diff;
            }
        }
        return step; 
    }
};
```




<br /> <br /> <br />**[1828. Queries on Number of Points Inside a Circle](https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/)**<br />
You are given an array `points` where `points[i] = [xi, yi]` is the coordinates of the `ith` point on a 2D plane. Multiple points can have the **same** coordinates.<br />
You are also given an array `queries` where `queries[j] = [xj, yj, rj]` describes a circle centered at `(xj, yj)` with a radius of `rj`.<br />
For each query` queries[j]`, compute the number of points **inside** the `jth` circle. Points **on the border** of the circle are considered **inside**.<br />
Return _an array `answer`, where `answer[j]` is the answer to the `jth` query_.<br />

>Example 1: <br /> 
><div align="left">
><img src="https://raw.githubusercontent.com/singh7priyanshu/Competitive-Programming-Essentials-Master-Algorithms-2022/master/interview%20questions/source%20images/iq1.png"><br />
>Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]<br /> 
>Output: [3,2,2]<br /> 
>Explanation: The points and circles are shown above.<br /> 
>queries[0] is the green circle, queries[1] is the red circle, and queries[2] is the blue circle.<br /> 
 
>Example 1: <br /> 
><div align="left">
><img src="https://raw.githubusercontent.com/singh7priyanshu/Competitive-Programming-Essentials-Master-Algorithms-2022/master/interview%20questions/source%20images/iq2.png"><br />
>Input: points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]<br /> 
>Output: [2,3,2,4]<br /> 
>Explanation: The points and circles are shown above.<br /> 
>queries[0] is green, queries[1] is red, queries[2] is blue, and queries[3] is purple.<br /> 
 
* Constraints: `1 <= points.length <= 500`. <br />
`points[i].length == 2`. <br />
`0 <= xi, yi <= 500`. <br />
`1 <= queries.length <= 500`. <br />
`queries[j].length == 3`. <br />
 `0 <= xj, yj <= 500`. <br />
`1 <= rj <= 500`. <br />
All coordinates are integers.<br />
 
```cpp
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        for(int i = 0; i < queries.size(); i++){ 
            //for each query, add +1 for each point that lies within radius distance of query center
            for(int j = 0; j < points.size(); j++)
                    if(inCircle(queries[i], points[j])) ans[i]++;
        }
        return ans; 
    }
    
private:
    bool inCircle(vector<int>& circle, vector<int>& point){ 
        //passing by reference (&) improves speed -- actually, TLE without it
        double distance = sqrt((point[0] - circle[0]) * (point[0] - circle[0]) + (point[1] - circle[1]) * (point[1] - circle[1]));
        return (distance <= circle[2]+0.0001); //fudge factor due to comparison w/ double
    }
};
```
                                             
                                             
                                         
<br /> <br /> <br />**[1829. Maximum XOR for Each Query](https://leetcode.com/problems/maximum-xor-for-each-query/)**<br />
You are given a **sorted** array `nums` of `n` non-negative integers and an integer `maximumBit`. You want to perform the following query `n` **times**:<br />
 1. Find a non-negative integer `k < 2^maximumBit` such that `nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k` is **maximized**. `k` is the answer to the `ith` query.<br />
 2. Remove the **last** element from the current array `nums`.<br />
Return _an array `answer`, where `answer[i]` is the answer to the `ith` query_. <br />

>Example 1:<br />
>Input: nums = [0,1,1,3], maximumBit = 2<br />
>Output: [0,3,2,3]<br />
>Explanation: The queries are answered as follows:<br />
>1st query: nums = [0,1,1,3], k = 0 since 0 XOR 1 XOR 1 XOR 3 XOR 0 = 3.<br />
>2nd query: nums = [0,1,1], k = 3 since 0 XOR 1 XOR 1 XOR 3 = 3.<br />
>3rd query: nums = [0,1], k = 2 since 0 XOR 1 XOR 2 = 3.<br />
>4th query: nums = [0], k = 3 since 0 XOR 3 = 3.<br />
                                           
>Example 2:<br />
>Input: nums = [2,3,4,7], maximumBit = 3<br />
>Output: [5,2,6,5]<br />
>Explanation: The queries are answered as follows:<br />
>1st query: nums = [2,3,4,7], k = 5 since 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7.<br />
>2nd query: nums = [2,3,4], k = 2 since 2 XOR 3 XOR 4 XOR 2 = 7.<br />
>3rd query: nums = [2,3], k = 6 since 2 XOR 3 XOR 6 = 7.<br />
>4th query: nums = [2], k = 5 since 2 XOR 5 = 7.<br />
                                           
>Example 3:<br />
>Input: nums = [0,1,2,2,5,7], maximumBit = 3<br />
>Output: [4,3,6,4,6,7]<br />
 
* Constraints: `nums.length == n`. <br />
`1 <= n <= 10^5`. <br />
`1 <= maximumBit <= 20`. <br />
`0 <= nums[i] < 2^maximumBit`. <br />
`nums` is sorted in **ascending** order.<br />
 
 ```cpp
 class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxi = (1<<maximumBit);
        int x = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            x ^= nums[i];
        }
        // cout << "x= " << x << "\n";
        vector<int> ans;
        for(int j = n-1; j >= 0; j--){
            ans.push_back(x^(maxi-1));
            x ^= nums[j];
        }
        return ans;
    }
};
```
 
 

<br /> <br /> <br />**[1830. Minimum Number of Operations to Make String Sorted](https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/)**<br />
You are given a string `s` (**0-indexed**). You are asked to perform the following operation on `s` until you get a sorted string:<br />
 1. Find **the largest index** `i` such that `1 <= i < s.length` and `s[i] < s[i - 1]`.<br />
 2. Find **the largest index** `j` such that `i <= j < s.length` and `s[k] < s[i - 1]` for all the possible values of `k` in the range `[i, j]` inclusive.<br />
 3. Swap the two characters at indices `i - 1` and `j`.<br />
 4. Reverse the suffix starting at index `i`.<br />
Return_ the number of operations needed to make the string sorted_. Since the answer can be too large, return it **modulo** `10^9 + 7`.<br />

>Example 1:<br />
>Input: s = "cba"<br />
>Output: 5<br />
>Explanation: The simulation goes as follows:<br />
>Operation 1: i=2, j=2. Swap s[1] and s[2] to get s="cab", then reverse the suffix starting at 2. Now, s="cab".<br />
>Operation 2: i=1, j=2. Swap s[0] and s[2] to get s="bac", then reverse the suffix starting at 1. Now, s="bca".<br />
>Operation 3: i=2, j=2. Swap s[1] and s[2] to get s="bac", then reverse the suffix starting at 2. Now, s="bac".<br />
>Operation 4: i=1, j=1. Swap s[0] and s[1] to get s="abc", then reverse the suffix starting at 1. Now, s="acb".<br />
>Operation 5: i=2, j=2. Swap s[1] and s[2] to get s="abc", then reverse the suffix starting at 2. Now, s="abc".<br />
 
>Example 2:<br />
>Input: s = "aabaa"<br />
>Output: 2<br />
>Explanation: The simulation goes as follows:<br />
>Operation 1: i=3, j=4. Swap s[2] and s[4] to get s="aaaab", then reverse the substring starting at 3. Now, s="aaaba".<br />
>Operation 2: i=4, j=4. Swap s[3] and s[4] to get s="aaaab", then reverse the substring starting at 4. Now, s="aaaab".<br />
 

* Constraints: `1 <= s.length <= 3000`<br />
`s` consists only of lowercase English letters.<br />
 
```cpp
class Solution {
public:
    const int mod = 1e9 + 7;
    long long modpow(long long b, long long p){
        long long ans = 1;
        for (; p; p>>=1){
            if (p&1)
                ans = ans * b%mod;
            b = b * b % mod;
        }
        return ans;
    }
    int makeStringSorted(string s) {
        long long ans = 0;
        map<int, long long> freq; 
        for (char& c: s)freq[c - 'a']++;
        vector<long long> fact(s.size() + 1, 1ll);
        for (int i = 1; i <= s.size(); i++)fact[i] = (fact[i - 1] * i)%mod;
        int l = s.size();
        for (char c: s){
            l--;
            long long t = 0, rev = 1;
            for (int i = 0; i < 26; i++){
                if (i < c - 'a')t += freq[i];
                rev = (rev * fact[freq[i]])%mod;
            }
            ans += (t*fact[l]%mod) * modpow(rev, mod - 2);
            ans %= mod;
            freq[c - 'a']--;
        }
        return ans;
    }
};
```
                         
                         
                        
    
<br /> <br /> <br />**[976. Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle/)**<br />
Given an integer array `nums`, return _the largest perimeter of a triangle with a non-zero area, formed from three of these lengths_. If it is impossible to form any triangle of a non-zero area, return `0`.<br />

>Example 1:<br />
>Input: nums = [2,1,2]<br />
>Output: 5<br />
 
>Example 2:<br />
>Input: nums = [1,2,1]<br />
>Output: 0<br />
 
* Constraints: 3 <= nums.length <= 10^4<br />
1 <= nums[i] <= 10^6<br />
 
```cpp
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]<nums[i+1]+nums[i+2]){
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }
        return 0;
    }
};
```
 
 
 


<br /> <br /> <br />**[1779. Find Nearest Point That Has the Same X or Y Coordinate](https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/)**<br />
You are given two integers, `x` and `y`, which represent your current location on a Cartesian grid: `(x, y)`. You are also given an array `points` where each `points[i] = [ai, bi]` represents that a point exists at `(ai, bi)`. A point is **valid** if it shares the same x-coordinate or the same y-coordinate as your location.<br />
Return the index **(0-indexed)** of the **valid** point with the smallest **Manhattan distance** from your current location. If there are multiple, return _the valid point with the **smallest** index_. If there are no valid points, return -1.<br />
The **Manhattan distance** between two points `(x1, y1)` and `(x2, y2)` is `abs(x1 - x2) + abs(y1 - y2)`.<br />

>Example 1:<br />
>Input: x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]<br />
>Output: 2<br />
>Explanation: Of all the points, only [3,1], [2,4] and [4,4] are valid. Of the valid points, [2,4] and [4,4] have the smallest Manhattan distance from your current location, with a distance of 1. [2,4] has the smallest index, so return 2.<br />
 
>Example 2:<br />
>Input: x = 3, y = 4, points = [[3,4]]<br />
>Output: 0<br />
>Explanation: The answer is allowed to be on the same location as your current location.<br />
 
>Example 3:<br />
>Input: x = 3, y = 4, points = [[2,3]]<br />
>Output: -1<br />
>Explanation: There are no valid points.<br />
 
* Constraints: `1 <= points.length <= 10^4`<br />
`points[i].length == 2`<br />
`1 <= x, y, ai, bi <= 10^4`<br />
 
```cpp
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int smallest_dist = INT_MAX;
        
        for(int i = 0; i<points.size(); i++){
            if(points[i][0] == x or points[i][1] == y){
                if(abs(x - points[i][0]) + abs(y - points[i][1]) < smallest_dist){
                    ans = i;
                    smallest_dist = abs(x - points[i][0]) + abs(y - points[i][1]);
                }
            }
        }
        return ans;
    }
};
```
 

 
 
<br /> <br /> <br />**[349. Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)**<br />
Given two integer arrays `nums1` and `nums2`, return _an array of their intersection_. Each element in the result must be **unique** and you may return the result in **any order**.<br />

>Example 1:<br />
>Input: nums1 = [1,2,2,1], nums2 = [2,2]<br />
>Output: [2]<br />
 
>Example 2:<br />
>Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]<br />
>Output: [9,4]<br />
>Explanation: [4,9] is also accepted<br />

* Constraints: `1 <= nums1.length, nums2.length <= 1000`<br />
`0 <= nums1[i], nums2[i] <= 1000`<br />
 
```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};
```
 
 
 
<br /> <br /> <br />**[350. Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)**<br />
Given two integer arrays `nums1` and `nums2`, return _an array of their intersection_. Each element in the result must appear as many times as it shows in both arrays and you may return the result in **any order**.<br />

>Example 1:<br />
>Input: nums1 = [1,2,2,1], nums2 = [2,2]<br />
>Output: [2,2]<br />
 
>Example 2:<br />
>Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]<br />
>Output: [4,9]<br />
>Explanation: [9,4] is also accepted.<br />

* Constraints: `1 <= nums1.length, nums2.length <= 1000`<br />
`0 <= nums1[i], nums2[i] <= 1000`<br />
 
```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> map;
        for(int i = 0 ; i < nums1.size() ; i++){
            map[nums1[i]]++;
        }
        
        vector<int> v;
        
        for(int i = 0 ; i < nums2.size() ; i++){
            if(map.count(nums2[i]) && map[nums2[i]] > 0){
                v.push_back(nums2[i]);
                map[nums2[i]]--;
            }
        }
        return v;
    }
};
```
 
 
 

<br /> <br /> <br />**[121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)**<br />
You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.<br />
You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.<br />
Return the _maximum profit you can achieve from this transaction_. If you cannot achieve any profit, return `0`.<br />
 
>Example 1:<br />
>Input: prices = [7,1,5,3,6,4]<br />
>Output: 5<br />
>Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.<br />
>Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.<br />
 
>Example 2:<br />
>Input: prices = [7,6,4,3,1]<br />
>Output: 0<br />
>Explanation: In this case, no transactions are done and the max profit = 0.<br />

* Constraints: `1 <= prices.length <= 10^5`<br />
`0 <= prices[i] <= 10^4`<br />

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minPrice = INT_MAX;
        for(int i = 0;i<prices.size();i++){
            if(prices[i]<minPrice)minPrice = prices[i];
            else if(prices[i]-minPrice > profit)profit = prices[i]-minPrice;
        }
        return profit;
    }
};
```

 
 

<br /> <br /> <br />**[122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)**<br />
You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day.<br />
On each day, you may decide to buy and/or sell the stock. You can only hold **at most one** share of the stock at any time. However, you can buy it then immediately sell it on the **same day**.<br />
Find and return _the **maximum** profit you can achieve_.<br />

>Example 1:<br />
>Input: prices = [7,1,5,3,6,4]<br />
>Output: 7<br />
>Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.<br />
>Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.<br />
>Total profit is 4 + 3 = 7.<br />
 
>Example 2:<br />
>Input: prices = [1,2,3,4,5]<br />
>Output: 4<br />
>Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.<br />
>Total profit is 4.<br />
 
>Example 3:<br />
>Iput: prices = [7,6,4,3,1]<br />
>Output: 0<br />
>Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.<br />

* Constraints: `1 <= prices.length <= 3 * 10^4`<br />
`0 <= prices[i] <= 10^4`<br />
 
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        if(n==1) return 0;
        int buy=0,profit=0;
        for(int i=0;i<n-1;i++){
            if(prices[i]<prices[i+1]){
                buy=prices[i];
                i++;
                while( i<n-1  && prices[i]<prices[i+1])i++;
                profit+=(prices[i]-buy);
            }   
        }  
        return profit; 
    }
};
```
 
 

 
<br /> <br /> <br />**[123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)**<br />
You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.<br />
Find the maximum profit you can achieve. You may complete **at most two transactions**.<br />
**Note**: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).<br />

>Example 1:<br />
>Input: prices = [3,3,5,0,0,3,1,4]<br />
>Output: 6<br />
>Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.<br />
>Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.<br />
 
>Example 2:<br />
>Input: prices = [1,2,3,4,5]<br />
>Output: 4<br />
>Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.<br />
>Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.<br />

>Example 3:<br />
>Input: prices = [7,6,4,3,1]<br />
>Output: 0<br />
>Explanation: In this case, no transaction is done, i.e. max profit = 0.<br />
 
* Constraints: `1 <= prices.length <= 10^5`<br />
`0 <= prices[i] <= 10^5`<br />
 
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int* profit = new int[n];
        for (int i = 0; i < n; i++)profit[i] = 0;
        int max_price = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (prices[i] > max_price)max_price = prices[i];

            profit[i]
                = max(profit[i + 1], max_price - prices[i]);
        }
        int min_price = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] < min_price)
                min_price = prices[i];
            profit[i] = max(profit[i - 1],
                            profit[i] + (prices[i] - min_price));
        }
        int result = profit[n - 1];
        delete[] profit;
        return result;
    }
};
```
 
 
 
 
 
<br /> <br /> <br />**[188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)**<br />
You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `k`.<br />
Find the maximum profit you can achieve. You may complete at most `k` transactions.<br />
**Note**: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).<br />

>Example 1:<br />
>Input: k = 2, prices = [2,4,1]<br />
>Output: 2<br />
>Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.<br />
 
>Example 2:<br />
>Input: k = 2, prices = [3,2,6,5,0,3]<br />
>Output: 7<br />
>Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.<br />
 
* Constraints: `0 <= k <= 100`<br />
`0 <= prices.length <= 1000`<br />
`0 <= prices[i] <= 1000`<br />
 
```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int n = k * 2 + 1;
        vector<int> dp(n, 0);
        for (int i = 0; i < k; i++) {
            dp[1 + i * 2] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            dp[0] = dp[0];
            for (int j = 0; j < k; j++) {
                dp[1 + j * 2] = max(dp[1 + j * 2], dp[j * 2] - prices[i]);
                dp[2 + j * 2] = max(dp[2 + j * 2], dp[1 + j * 2] + prices[i]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < k; i++) ans = max(ans, dp[2 + i * 2]);
        return ans;
    }
};
```

 


<br /> <br /> <br />**[309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)**<br />
You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.<br />
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:<br />
  * After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).<br />
**Note**: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).<br />

>Example 1:<br />
>Input: prices = [1,2,3,0,2]<br />
>Output: 3<br />
>Explanation: transactions = [buy, sell, cooldown, buy, sell]<br />
 
>Example 2:<br />
>Input: prices = [1]<br />
>Output: 0<br />

* Constraints: `1 <= prices.length <= 5000`<br />
`0 <= prices[i] <= 1000`<br />
 
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> p = {0,0}, pp = {0,0}, cur = {0,0};
        for(int i=n-1;i>=0;i--){
            cur[1] = max(-prices[i] + p[0], p[1]);
            cur[0] = max(prices[i] + pp[1], p[0]);
            pp = p;
            p = cur;
        }
        return p[1];
    }
};
```
 
 
 
<br /> <br /> <br />**[283. Move Zeroes](https://leetcode.com/problems/move-zeroes/)**<br />
Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.<br />
**Note** that you must do this in-place without making a copy of the array.<br />

>Example 1:<br />
>Input: nums = [0,1,0,3,12]<br />
>Output: [1,3,12,0,0]<br />
 
>Example 2:<br />
>Input: nums = [0]<br />
>Output: [0]<br />

* Constraints: `1 <= nums.length <= 10^4`<br />
`-2^31 <= nums[i] <= 2^31 - 1`<br />
 
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int low=0;
        int mid=0;
        while(mid<nums.size()){
            if(nums[mid]!=0){                                 
                swap(nums[mid],nums[low]);
                low++; 
                mid++;
            }
            else mid++;
        }
    }
};
```
                                
                                
                                

<br /> <br /> <br />**[167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)**<br />
Given a **1-indexed** array of integers `numbers` that is already **sorted in non-decreasing order**, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.<br />
Return _the indices of the two numbers, `index1` and `index2`, **added by one** as an integer array `[index1, index2]` of length 2_.<br />
The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.<br />
Your solution must use only constant extra space.<br />

>Example 1:<br />
>Input: numbers = [2,7,11,15], target = 9<br />
>Output: [1,2]<br />
>Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].<br />

>Example 2:<br />
>Input: numbers = [2,3,4], target = 6<br />
>Output: [1,3]<br />
>Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].<br />

>Example 3:<br />
>Input: numbers = [-1,0], target = -1<br />
>Output: [1,2]<br />
>Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].<br />

* Constraints: `2 <= numbers.length <= 3 * 10^4`<br />
`-1000 <= numbers[i] <= 1000`<br />
`numbers` is sorted in **non-decreasing order**.<br />
`-1000 <= target <= 1000`<br />
The tests are generated such that there is exactly one solution.<br />
 
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, r = numbers.size()-1;
        while(l<r){
            if(numbers[l] + numbers[r] == target) return {l+1, r+1};
            if(numbers[l] + numbers[r] < target)l++;
            else r--;
        }
        return {};
    }
};
```
