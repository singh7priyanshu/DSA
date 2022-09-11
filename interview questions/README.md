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
><img src="https://assets.leetcode.com/uploads/2021/03/25/chrome_2021-03-25_22-34-16.png"><br />
>Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]<br /> 
>Output: [3,2,2]<br /> 
>Explanation: The points and circles are shown above.<br /> 
>queries[0] is the green circle, queries[1] is the red circle, and queries[2] is the blue circle.<br /> 
 
>Example 1: <br /> 
><div align="left">
><img src="https://assets.leetcode.com/uploads/2021/03/25/chrome_2021-03-25_22-42-07.png"><br />
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

 
 
 
<br /> <br /> <br />**[1822. Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array/)**<br />
There is a function `signFunc(x)` that returns:<br />

* `1` if `x` is positive.<br />
* `-1` if `x` is negative.<br />
* `0` if `x` is equal to `0`.<br />
You are given an integer array `nums`. Let `product` be the product of all values in the array `nums`.<br />

Return `signFunc(product)`.<br />


>Example 1:<br />
Input: nums = [-1,-2,-3,-4,3,2,1]<br />
Output: 1<br />
Explanation: The product of all values in the array is 144, and signFunc(144) = 1<br />
 
>Example 2:<br />
Input: nums = [1,5,0,2,-3]<br />
Output: 0<br />
Explanation: The product of all values in the array is 0, and signFunc(0) = 0<br />
 
>Example 3:<br />
Input: nums = [-1,1,-1,1,-1]<br />
Output: -1<br />
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1<br />
 

* Constraints: `1 <= nums.length <= 1000`<br />
`-100 <= nums[i] <= 100`<br />
 
```cpp
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            if((nums[i])==0)return 0;
            if(nums[i]<0)count++;
        }
        return count%2 == 0? 1 : -1;
    }
};
```

 
 
 
<br /> <br /> <br />**[1502. Can Make Arithmetic Progression From Sequence](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)**<br />
A sequence of numbers is called an **arithmetic progression** if the difference between any two consecutive elements is the same.<br />
Given an array of numbers `arr`, return `true` _if the array can be rearranged to form an **arithmetic progression**. Otherwise, return `false`_.<br />
 
>Example 1:<br />
Input: arr = [3,5,1]<br />
Output: true<br />
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.<br />
 
>Example 2:<br />
Input: arr = [1,2,4]<br />
Output: false<br />
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.<br />
 
* Constraints: 2 <= arr.length <= 1000<br />
-10^6 <= arr[i] <= 10^6<br />
 
```cpp
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1]-arr[0];
        for(int i = 0;i<arr.size()-1;i++){
            if((arr[i+1]-arr[i]) != diff)return false;
        }
        return true;
    }
};
```
                                           
                                           
                                           
                                           
                                         
<br /> <br /> <br />**[202. Happy Number](https://leetcode.com/problems/happy-number/)**<br />
Write an algorithm to determine if a number `n` is happy.<br />
A **happy number** is a number defined by the following process:<br />
* Starting with any positive integer, replace the number by the sum of the squares of its digits.<br />
* Repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle** which does not include 1.<br />
* Those numbers for which this process **ends in 1** are happy.<br />
 
Return `true` if `n` is a happy number, and `false` if not.<br />

>Example 1:<br />
Input: n = 19<br />
Output: true<br />
Explanation:<br />
12 + 92 = 82<br />
82 + 22 = 68<br />
62 + 82 = 100<br />
12 + 02 + 02 = 1<br />
 
>Example 2:<br />
Input: n = 2<br />
Output: false<br />
 
* Constraints: `1 <= n <= 2^31 - 1`<br />
 
```cpp
class Solution {
public:
    bool isHappy(int n) {
        while(n/10>0){
            int sum=0;
            while(n>0){
                int rem=n%10;
                sum=rem*rem+sum;
                n=n/10;
            }
        n=sum;
        }
        //when you will split 07, add squares of 0 and 7. This will become 49, 
        //and after following the same steps you'll certainly reach 1. 
        if(n==1 || n==7)return true;
        else return false;
    }
};
```
 
 
 


<br /> <br /> <br />**[1790. Check if One String Swap Can Make Strings Equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)**<br />
You are given two strings `s1` and `s2` of equal length. A **string swap** is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.<br />
Return `true` _if it is possible to make both strings equal by performing **at most one string swap** on **exactly one** of the strings_. Otherwise, return `false`.<br />

>Example 1:<br />
Input: s1 = "bank", s2 = "kanb"<br />
Output: true<br />
Explanation: For example, swap the first character with the last character of s2 to make "bank".<br />
 
>Example 2:<br />
Input: s1 = "attack", s2 = "defend"<br />
Output: false<br />
Explanation: It is impossible to make them equal with one string swap.<br />
 
>Example 3:<br />
Input: s1 = "kelb", s2 = "kelb"<br />
Output: true<br />
Explanation: The two strings are already equal, so no string swap operation is required.<br />

* Constraints: `1 <= s1.length, s2.length <= 100`<br />
`s1.length == s2.length`<br />
`s1` and `s2` consist of only lowercase English letters.<br />
 
```cpp
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int diff=0;
            vector<int> v;
            for(int i=0;i<s1.length();i++){
                if(s1[i] != s2[i]){
                    diff++;
                    v.push_back(i);
                }
            }
            if(diff != 2) return false;
            swap(s1[v[0]],s1[v[1]]);
            if(s1==s2)return true;
        return false;
    }
};
```
 
                                            
                                            
<br /> <br /> <br />**[566. Reshape the Matrix](https://leetcode.com/problems/reshape-the-matrix/)**<br />  
In MATLAB, there is a handy function called `reshape` which can reshape an `m x n` matrix into a new one with a different size `r x c` keeping its original data.<br /> 
You are given an `m x n` matrix `mat` and two integers `r` and `c` representing the number of rows and the number of columns of the wanted reshaped matrix.<br /> 
The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.<br /> 
If the `reshape` operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.<br /> 

>Example 1:<br /> 
<img src = "https://assets.leetcode.com/uploads/2021/04/24/reshape1-grid.jpg"><br /> 
Input: mat = [[1,2],[3,4]], r = 1, c = 4<br /> 
Output: [[1,2,3,4]]<br /> 
 
>Example 2:<br /> 
<img src = "https://assets.leetcode.com/uploads/2021/04/24/reshape2-grid.jpg"><br /> 
Input: mat = [[1,2],[3,4]], r = 2, c = 4<br /> 
Output: [[1,2],[3,4]]<br /> 
 
* Constraints: `m == mat.length`<br /> 
`n == mat[i].length`<br /> 
`1 <= m, n <= 100`<br /> 
`-1000 <= mat[i][j] <= 1000`<br /> 
`1 <= r, c <= 300`<br /> 

```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(r * c != m * n) return mat;
        vector<int> temp;
        for(int i = 0 ; i < mat.size() ; i++){
            for(int j = 0 ; j < mat[i].size() ; j++){
                temp.push_back(mat[i][j]);
            }
        }
        vector<vector<int>> output;
        for(int i = 0 ; i < r ; i++){
            vector<int> v;
            for(int j = 0 ; j < c ; j++){
                v.push_back(temp[i * c + j]);
            }
            output.push_back(v);
        }
        return output;
    }
};
```
                                 
                                 
                                           


<br /> <br /> <br />**[118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)**<br />   
Given an integer `numRows`, return the first numRows of **Pascal's triangle**.<br /> 
In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:<br /> 
<img src = "https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif"><br /> 

>Example 1:<br /> 
Input: numRows = 5<br /> 
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]<br /> 
 
>Example 2:<br /> 
Input: numRows = 1<br /> 
Output: [[1]]<br /> 
 
* Constraints: `1 <= numRows <= 30`<br /> 
 
```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows <= 0)return res;
        for(int i = 0; i<= numRows; ++i){
            vector<int> row;
            for(int j = 0; j < i; ++j){
                if(j ==0 || j == i-1)row.push_back(1);
                else row.push_back(res.at(i-1).at(j-1) +  res.at(i-1).at(j));              
            }
        res.push_back(row);
        }
    res.erase(res.begin());
    return res;
    }
};
```
                                 
                                 
                                 
                                       
                                      

<br /> <br /> <br />**[541. Reverse String II](https://leetcode.com/problems/reverse-string-ii/)**<br />          
Given a string `s` and an integer `k`, reverse the first `k` characters for every `2k` characters counting from the start of the string.<br />
If there are fewer than `k` characters left, reverse all of them. If there are less than `2k` but greater than or equal to `k` characters, then reverse the first `k` characters and leave the other as original.<br />
 
>Example 1:<br />
Input: s = "abcdefg", k = 2<br />
Output: "bacdfeg"<br />
 
>Example 2:<br />
Input: s = "abcd", k = 2<br />
Output: "bacd"<br />

* Constraints: `1 <= s.length <= 10^4`<br />
`s` consists of only lowercase English letters.<br />
`1 <= k <= 10^4`<br />
 
```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        int n =s.size(),i=0;
        while(i<n){
            reverse(s.begin()+i,s.begin()+min(i+k,n));
            i=i+2*k;
        }
        return s;
    }
};
```
                    
                    
                    
<br /> <br /> <br />**[557. Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/)**<br />      
Given a string `s`, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.<br />

>Example 1:<br />
Input: s = "Let's take LeetCode contest"<br />
Output: "s'teL ekat edoCteeL tsetnoc"<br />
 
>Example 2:<br />
Input: s = "God Ding"<br />
Output: "doG gniD"<br />

* Constraints: `1 <= s.length <= 5 * 10^4`<br />
`s` contains printable **ASCII** characters.<br />
`s` does not contain any leading or trailing spaces.<br />
There is `at least one` word in `s`.<br />
All the words in `s` are separated by a single space.<br />
 
```cpp
class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        for(int i=0;i<=s.size();i++){
            if(s[i]==' ' || i==s.size()){
                reverse(s.begin()+k,s.begin()+i);
                k=i+1;
            }
        }
    return s;
    }
};
```

                                     
                                   
<br /> <br /> <br />**[589. N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)**<br />  
Given the `root` of an n-ary tree, return _the preorder traversal of its nodes' values_.<br />
Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)<br />
 
>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png"><br />
>Input: root = [1,null,3,2,4,null,5,6]<br />
>Output: [1,3,5,6,2,4]<br />
 
>Example 2:<br />
><img src = "https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png"><br />
>Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]<br />
>Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]<br />
 
* Constraints: The number of nodes in the tree is in the range `[0, 10^4]`.<br />
`0 <= Node.val <= 10^4`<br />
The height of the n-ary tree is less than or equal to `1000`.<br />
 
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void preOrder(Node* root, vector<int>& v){
        if(!root) return;
        v.push_back(root->val);
        for(Node* rt: root->children) preOrder(rt,v);
    }
    
    vector<int> preorder(Node* root) {
        vector<int> v;
        preOrder(root,v);
        return v;
    }
};
```
 

 
 

<br /> <br /> <br />**[496. Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)**<br />  
The **next greater element** of some element `x` in an array is the **first greater** element that is **to the right** of `x` in the same array.<br />
You are given **two distinct 0-indexed** integer arrays `nums1` and `nums2`, where nums1 is a subset of `nums2`.<br />
For each `0 <= i < nums1.length`, find the index `j` such that `nums1[i] == nums2[j]` and determine the **next greater element** of `nums2[j]` in `nums2`. If there is no next greater element, then the answer for this query is `-1`.<br />
Return _an array `ans` of length `nums1.length` such that `ans[i]` is the **next greater element** as described above_.<br />

>Example 1:<br />
>Input: nums1 = [4,1,2], nums2 = [1,3,4,2]<br />
>Output: [-1,3,-1]<br />
>Explanation: The next greater element for each value of nums1 is as follows:<br />
>- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.<br />
>- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.<br />
>- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.<br />
 
>Example 2:<br />
>Input: nums1 = [2,4], nums2 = [1,2,3,4]<br />
>Output: [3,-1]<br />
>Explanation: The next greater element for each value of nums1 is as follows:<br />
>- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.<br />
>- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.<br />
 
* Constraints: `1 <= nums1.length <= nums2.length <= 1000`<br />
`0 <= nums1[i], nums2[i] <= 10^4`<br />
All integers in `nums1` and `nums2` are **unique**.<br />
All the integers of `nums1` also appear in `nums2`.<br />
                                
```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int>st;
        unordered_map<int,int> mp;
        for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= nums2[i])st.pop(); 
        if(st.empty())mp[nums2[i]] = -1;    
        else mp[nums2[i]] = st.top();
        st.push(nums2[i]);    
    }
    
    vector<int> ans;
    for(int i = 0; i < nums1.size(); i++)ans.push_back(mp[nums1[i]]);
    return ans;
    }
};
```                               
                                

                                    
                                    
<br /> <br /> <br />**[1232. Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/)**<br /> 
 You are given an array `coordinates, coordinates[i] = [x, y]`, where `[x, y]` represents the coordinate of a point. Check if these points make a straight line in the XY plane.<br />
 
>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2019/10/15/untitled-diagram-2.jpg"><br />
>Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]<br />
>Output: true<br />
 
>Example 2:<br />
><img src = "https://assets.leetcode.com/uploads/2019/10/09/untitled-diagram-1.jpg"><br />
>Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]<br />
>Output: false<br />
 
* Constraints: `2 <= coordinates.length <= 1000`<br />
`coordinates[i].length == 2`<br />
`-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4`<br />
`coordinates` contains no duplicate point.<br />
                                    
 ```cpp
 class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2)  return true;
        for (int i = 2; i < coordinates.size(); i++){
            if (!helper(coordinates[i - 2], coordinates[i - 1], coordinates[i]))
                return false;
        }
        return true;
    }
private:
    bool helper(vector<int> a, vector<int> b, vector<int> c){
        int xab = b[0] - a[0];
        int yab = b[1] - a[1];
        int xac = c[0] - a[0];
        int yac = c[1] - a[1];
        return (yac) * (xab) == (yab) * (xac);
    }
};
/*
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& points) {
        auto &a = points[0];
        auto &b = points[1];
        auto tangent = tan(a,b);
        for(int i=2;i<points.size();i++){
            auto cur = tan(points[i-1], points[i]);
            if(cur != tangent) return false;
        }
        return true;
    }
    double tan(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return INT_MAX;
        return (double)(a[1] - b[1])/(a[0]-b[0]);
    }
};
*/
```
 

 
 
<br /> <br /> <br />**[36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)**<br /> 
Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:<br />
Each row must contain the digits `1-9` without repetition.<br />
Each column must contain the digits `1-9` without repetition.<br />
Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.<br />
Note:<br />
A Sudoku board (partially filled) could be valid but is not necessarily solvable.<br />
Only the filled cells need to be validated according to the mentioned rules.<br />
 
>Example 1:<br />
><img src = "https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png"><br />
<pre>
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
</pre><br />
 
>Example 2:<br />
<pre>
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
</pre><br />
>Explanation: Same as Example 1, except with the 5 in the top left corner being modified to `8`. Since there are two 8's in the top left 3x3 sub-box, it is invalid.<br />

* Constraints: `board.length == 9`<br />
`board[i].length == 9`<br />
`board[i][j]` is a digit `1-9` or `'.'`.<br />
 
```cpp
class Solution {
public:
    //function to check if number repeats in vector
	bool comparer(vector<char>& in){
        sort(in.begin(), in.end());
        if(adjacent_find(in.begin(), in.end()) != in.end()){
                return false;
            }
            
        else{
            return true;
        }
}


    bool isValidSudoku(vector<std::vector<char>>& board) {
        const unsigned char size = 9;
        unsigned char mut = 0;
        unsigned char cont = 0;
        vector<char> comparelines;
        vector<char> comparecols;
        vector<char> comparesquares;
        // loop that pushes line in comparelines
	    for(int i = 0; i != size; i++){
            for(int f = 0; f != size; f++){
                if(board[i][f] != '.'){
                    comparelines.push_back(board[i][f]);
                }
            }
            // loop that pushes columns in comparecols
		    for(int c = 0; c != size; c++){
                if(board[c][i] != '.'){
                    comparecols.push_back(board[c][i]);
                }
            }
        
            //loop that pushes 3x3 squares into comparesquares
		    for(int d = mut; d != mut + 3; d++){
                for(int c = cont; c != cont + 3; c++){
                    if(board[d][c] != '.'){
                        comparesquares.push_back(board[d][c]);

                    }
                }
            }

            // checking
		    if(comparer(comparelines) && comparer(comparecols) && comparer(comparesquares)){
                comparecols.clear();
                comparelines.clear();
                comparesquares.clear();
            }
            else{
                return false;
            }
        
            // math needed to compare 3x3 squares
		    cont += 3;
            if(i == 2 || i == 5 || i == 8){
                mut += 3;
                cont = 0;
            }
        
        }
    
        return true;
        
    }
};
```
 
 
 
 
 
<br /> <br /> <br />**[74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)**<br /> 
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:<br />
Integers in each row are sorted from left to right.<br />
The first integer of each row is greater than the last integer of the previous row.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2020/10/05/mat.jpg"><br />
>Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3<br />
>Output: true<br />
 
>Example 2:<br />
><img src = "https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg"><br />
>Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13<br />
>Output: false<br />

* Constraints: `m == matrix.length`<br />
`n == matrix[i].length`<br />
`1 <= m, n <= 100`<br />
`-10^4 <= matrix[i][j], target <= 10^4`<br />
 
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lx = 0, rx = matrix.size();
        int midx = (lx + rx) / 2;
        while (lx < rx) { // Searching vector that may include our target
            if (matrix[midx].back() >= target && matrix[midx][0] <= target) {
                int ly = 0, ry = matrix[midx].size();
                int midy = (ly + ry) / 2;
                while (ly < ry) { // Searching our target
                    if (matrix[midx][midy] == target) return true;
                    if (matrix[midx][midy] < target) {
                        ly = midy + 1;
                    } else {
                        ry = midy;
                    }
                    midy = (ly + ry) / 2;
                }
                return false; // If there is no number equals to target, 
				              // than it can't be anywhere else so returning false
            }
            if (matrix[midx].back() < target) {
                lx = midx + 1;
            } else if (matrix[midx][0] > target) {
                rx = midx;
            }
            midx = (lx + rx) / 2;
        }
        return false;
        
    }
};
```
                     
                     
                     
                        
 
                     
                     
                     
                     
<br /> <br /> <br />**[19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)**<br />    
Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.<br />
>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg"><br />
>Input: head = [1,2,3,4,5], n = 2<br />
>Output: [1,2,3,5]<br />
                     
>Example 2:<br />
Input: head = [1], n = 1<br />
Output: []<br />
                     
>Example 3:<br />
Input: head = [1,2], n = 1<br />
Output: [1]<br />
 

* Constraints: The number of nodes in the list is `sz`.<br />
`1 <= sz <= 30`<br />
`0 <= Node.val <= 100`<br />
`1 <= n <= sz`<br />

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode** t1 = &head, *t2 = head;
        for(int i = 1; i < n; ++i)t2 = t2->next;
        while(t2->next != NULL){
            t1 = &((*t1)->next);
            t2 = t2->next;
        }
        *t1 = (*t1)->next;
        return head;
    }
};
```                     
                    
 
			    
			    
			    
<br /> <br /> <br />**[1588. Sum of All Odd Length Subarrays](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/)**<br />    	
Given an array of positive integers `arr`, calculate the sum of all possible odd-length subarrays.<br />
A subarray is a contiguous subsequence of the array.<br />
Return _the sum of all odd-length subarrays of `arr`_.<br />
 
>Example 1:<br />
Input: arr = [1,4,2,5,3]<br />
Output: 58<br />
Explanation: The odd-length subarrays of arr and their sums are:<br />
[1] = 1<br />
[4] = 4<br />
[2] = 2<br />
[5] = 5<br />
[3] = 3<br />
[1,4,2] = 7<br />
[4,2,5] = 11<br />
[2,5,3] = 10<br />
[1,4,2,5,3] = 15<br />
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58<br />
			    
>Example 2:<br />
Input: arr = [1,2]<br />
Output: 3<br />
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.<br />
			    
>Example 3:<br />
Input: arr = [10,11,12]<br />
Output: 66<br />
			    
* Constraints: 1 <= arr.length <= 100<br />
1 <= arr[i] <= 1000<br />	
			    
```cpp
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        arr.insert(arr.begin(), 0);
        for (int i = 1; i < arr.size(); i++)arr[i] += arr[i - 1];
        int res = 0;
        for (int left = 1; left < arr.size(); left++){
            for (int right = left; right < arr.size(); right += 2){
                res += (arr[right] - arr[left - 1]);
            }
        }
        return res;
    }
};
/*
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int result = 0;
            for(int i = 0; i < arr.size(); i++){
                for (int j = i; j < arr.size(); j += 2){ 
                    for(int k = i; k <= j; k++)result += arr[k];
                }
            }
            return result;
        }
    };
*/
```

			    
			    
<br /> <br /> <br />**[1672. Richest Customer Wealth](https://leetcode.com/problems/richest-customer-wealth/)**<br /> 	
You are given an `m x n` integer grid `accounts` where `accounts[i][j]` is the amount of money the `ith` customer has in the `jth` bank. Return _the **wealth** that the richest customer has_.<br />
A customer's **wealth** is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum **wealth**.<br />

>Example 1:<br />
Input: accounts = [[1,2,3],[3,2,1]]<br />
Output: 6<br />
Explanation:<br />
1st customer has wealth = 1 + 2 + 3 = 6<br />
2nd customer has wealth = 3 + 2 + 1 = 6<br />
Both customers are considered the richest with a wealth of 6 each, so return 6.<br />
						    
>Example 2:<br />
Input: accounts = [[1,5],[7,3],[3,5]]<br />
Output: 10<br />
Explanation: <br />
1st customer has wealth = 6<br />
2nd customer has wealth = 10 <br />
3rd customer has wealth = 8<br />
The 2nd customer is the richest with a wealth of 10.<br />
						    
>Example 3:<br />
Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]<br />
Output: 17<br />

* Constraints: `m == accounts.length`<br />
`n == accounts[i].length`<br />
`1 <= m, n <= 50`<br />
`1 <= accounts[i][j] <= 100`<br />
	
```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sol = INT_MIN; 
        for(int i = 0;i<accounts.size();i++){
            int temp = 0;
            for(int j = 0;j<accounts[0].size();j++){
              temp += accounts[i][j];  
            }
            sol = max(temp,sol);
        }
        return sol;
    }
};
```
	
	
	

<br /> <br /> <br />**[387. First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/)**<br />
Given a string `s`, _find the first non-repeating character in it and return its index_. If it does not exist, return `-1`.<br />
 
>Example 1:<br />
Input: s = "leetcode"<br />
Output: 0<br />
	
>Example 2:<br />
Input: s = "loveleetcode"<br />
Output: 2<br />
	
>Example 3:<br />
Input: s = "aabb"<br />
Output: -1<br />
 
* Constraints: `1 <= s.length <= 10^5`<br />
`s` consists of only lowercase English letters.<br />
	
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
      unordered_map<char,int>map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(map[s[i]]==1)
                return i;
        }
        return -1;
    }
};
```
	
	
	
<br /> <br /> <br />**[383. Ransom Note](https://leetcode.com/problems/ransom-note/)**<br />
Given two strings `ransomNote` and `magazine`, return `true` _if `ransomNote` can be constructed from `magazine` and `false` otherwise_.<br />
Each letter in `magazine` can only be used once in `ransomNote`.<br />

>Example 1:<br />
Input: ransomNote = "a", magazine = "b"<br />
Output: false<br />
	
>Example 2:<br />
Input: ransomNote = "aa", magazine = "ab"<br />
Output: false<br />
	
>Example 3:<br />
Input: ransomNote = "aa", magazine = "aab"<br />
Output: true<br />

* Constraints: `1 <= ransomNote.length, magazine.length <= 10^5`<br />
`ransomNote` and `magazine` consist of lowercase English letters.<br />
	
```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(char c : magazine)m[c]++;
        for(char c : ransomNote) {
            if(m[c] == 0) return false;
            m[c]--;
        }
        return true;
    }
};
```
	
	
	
<br /> <br /> <br />**[242. Valid Anagram](https://leetcode.com/problems/valid-anagram/)**<br />
Given two strings `s` and `t`, return `true` _if `t` is an anagram of `s`, and `false` otherwise_.<br />
An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.<br />

>Example 1:<br />
Input: s = "anagram", t = "nagaram"<br />
Output: true<br />
	
>Example 2:<br />
Input: s = "rat", t = "car"<br />
Output: false<br />

* Constraints: `1 <= s.length, t.length <= 5 * 10^4`<br />
`s` and `t` consist of lowercase English letters.<br />
	
```cpp
class Solution {
public:
    bool isAnagram(string s, string t){
        sort(t.begin() ,t.end()) ;
        sort(s.begin() ,s.end()) ; 
        return s==t ;
    }
};
/*
unordered_map<char,int> mp ;
    for(char x:s) mp[x]++;
    
    for(int x:t) {
        mp[x]--;
        if(mp[x]<0) return false; 
    }
    for(int x:mp) {   
        if(x.second!=0) return false; 
    }

    return true;
*/
```
		    
		    
<br /> <br /> <br />**[3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)**<br />
Given a string `s`, find the length of the **longest substring** without repeating characters.<br />
 
>Example 1:<br />
Input: s = "abcabcbb"<br />
Output: 3<br />
Explanation: The answer is "abc", with the length of 3.<br />
	
>Example 2:<br />
Input: s = "bbbbb"<br />
Output: 1<br />
Explanation: The answer is "b", with the length of 1.<br />
	
>Example 3:<br />
Input: s = "pwwkew"<br />
Output: 3<br />
Explanation: The answer is "wke", with the length of 3.<br />
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.<br />

* Constraints: `0 <= s.length <= 5 * 10^4`<br />
`s` consists of English letters, digits, symbols and spaces.<br />
	
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int max_len = 0;
        int i = 0;
        int j = 0;
        int n = s.length();
        unordered_map<char, int> char_map;
        while ((i < n) && (j < n)){
            char c = s[j];
            unordered_map<char, int>::iterator it = char_map.find(c);
            if (it == char_map.end()){
                char_map[c] = j;
                j++;
                if (char_map.size() > max_len)
                    max_len = char_map.size();
            }
            else{
                i = it->second + 1;
                char_map.clear();
                j = i;
            }
        }
        return max_len;
    }
        
    
};
```
	
	
	
<br /> <br /> <br />**[567. Permutation in String](https://leetcode.com/problems/permutation-in-string/)**<br />
Given two strings `s1` and `s2`, return `true` _if `s2` contains a permutation of `s1`, or `false` otherwise_.<br />
In other words, return `true` if one of `s1's` permutations is the substring of `s2`.<br />

>Example 1:<br />
Input: s1 = "ab", s2 = "eidbaooo"<br />
Output: true<br />
Explanation: s2 contains one permutation of s1 ("ba").<br />
	
>Example 2:<br />
Input: s1 = "ab", s2 = "eidboaoo"<br />
Output: false<br />

* Constraints: `1 <= s1.length, s2.length <= 10^4`<br />
`s1` and `s2` consist of lowercase English letters.<br />
	
```cpp
class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> map_s1(26), map_s2(26);
		for(char& i1 : s1) 
			map_s1[i1 - 'a']++;
		for(int i = 0; i < s2.size(); i++) {
			map_s2[s2[i] - 'a']++;
			if(i >= s1.size() - 1) {
				if(map_s2 == map_s1)  // Time: O(26)
					return true;
				map_s2[s2[i - s1.size() + 1] - 'a']--;
			}
		}
		return false;
	}
};
// Time complexity: O(n * 26) = O(n)
// Time space: O(26 * 2) = O(1)
```

	
<br /> <br /> <br />**[1572. Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)**<br />
Given a square matrix `mat`, return the sum of the matrix diagonals.<br />
Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png"><br />
<pre>
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
</pre>
>Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25<br />
>Notice that element mat[1][1] = 5 is counted only once.<br /><br />
	
>Example 2:<br />
<pre>
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
</pre><br />
	
>Example 3:<br />
>Input: mat = [[5]]<br />
>Output: 5<br />
 
* Constraints: `n == mat.length == mat[i].length`<br />
`1 <= n <= 100`<br />
`1 <= mat[i][j] <= 100`<br />
	
```cpp
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0, dub = 0;
        if(n&1)dub = mat[n/2][n/2]; 
        for(int i = 0; i<n ; i++){
            sum += mat[i][n-i-1];
            sum += mat[i][i];
        }
        return sum - dub;
    }
};
```
			   
			   
			   
<br /> <br /> <br />**[141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)**<br />	
Given `head`, the head of a linked list, determine if the linked list has a cycle in it.<br />
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that `pos` is not passed as a parameter**.<br />
Return `true` _if there is a cycle in the linked list_. Otherwise, return `false`.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png"><br />
>Input: head = [3,2,0,-4], pos = 1<br />
>Output: true<br />
>Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).<br />
	
>Example 2:<br />
><img src = "https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png"><br />
>Input: head = [1,2], pos = 0<br />
>Output: true<br />
>Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.<br />

>Example 3:<br />
><img src = "https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png"><br />
>Input: head = [1], pos = -1<br />
>Output: false<br />
>Explanation: There is no cycle in the linked list.<br />
	
* Constraints: The number of the nodes in the list is in the range `[0, 10^4]`.<br />
`-10^5 <= Node.val <= 10^5`<br />
`pos` is `-1` or a **valid index** in the linked-list.<br />
	
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast ->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
```

	

	
	
<br /> <br /> <br />**[21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)**<br />
You are given the heads of two sorted linked lists `list1` and `list2`.<br />
Merge the two lists in a one **sorted** list. The list should be made by splicing together the nodes of the first two lists.<br />
Return _the head of the merged linked list_.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg"><br />
>Input: list1 = [1,2,4], list2 = [1,3,4]<br />
>Output: [1,1,2,3,4,4]<br />
	
>Example 2:<br />
>Input: list1 = [], list2 = []<br />
>Output: []<br />
	
>Example 3:<br />
>Input: list1 = [], list2 = [0]<br />
>Output: [0]<br />

* Constraints: The number of nodes in both lists is in the range `[0, 50]`.<br />
`-100 <= Node.val <= 100`<br />
Both `list1` and `list2` are sorted in **non-decreasing** order.<br />
	
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode * insert(ListNode * head, int val){
        if(head == nullptr)return new ListNode(val);
        else{
            head -> next = insert(head->next,val);
            return head;
        }
    }
    int listSize(ListNode* head){
        if(!head)return 0;
        else return listSize(head->next)+1;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr;
        int l1s = listSize(list1);
        int l2s = listSize(list2);
        while (l1s > 0 && l2s > 0){
            int v1 = list1 -> val;
            int v2 = list2 -> val;
            if(v1<=v2){
                l1s--;
                head  = insert(head,v1);
                list1 = list1 -> next;
            }else{
                l2s--;
                head = insert(head,v2);
                list2 = list2 -> next;
            }
        }
        while(l1s>0){
            int val1 = list1 -> val;
            l1s--;
            head = insert(head,val1);
            list1 = list1 -> next;
        }
        while(l2s>0){
            int val2 = list2 -> val;
            l2s--;
            head = insert(head,val2);
            list2 = list2 -> next;
        }
        return head;          
    }
};
```
	
	
	
	
<br /> <br /> <br />**[203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)**<br />
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.<br />
 
>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg"><br />
>Input: head = [1,2,6,3,4,5,6], val = 6<br />
>Output: [1,2,3,4,5]<br />
	
>Example 2:<br />
>Input: head = [], val = 1<br />
>Output: []<br />
	
>Example 3:<br />
>Input: head = [7,7,7,7], val = 7<br />
>Output: []<br />

* Constraints: The number of nodes in the list is in the range `[0, 10^4]`.<br />
`1 <= Node.val <= 50`<br />
`0 <= val <= 50`<br />
	
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        ListNode** node = &head;
        while (*node)
            if ((*node)->val == val) *node = (*node)->next;
            else if (*node) node = &(*node)->next;
        return head;
    }
};
```
	
	
	
	

	
	
	
	
<br /> <br /> <br />**[695. Max Area of Island](https://leetcode.com/problems/max-area-of-island/)**<br />
You are given an `m x n` binary matrix `grid`. An island is a group of `1`'s (representing land) connected **4-directionally** (horizontal or vertical.) You may assume all >our edges of the grid are surrounded by water.<br />
The **area** of an island is the number of cells with a value `1` in the island.<br />
Return _the maximum **area** of an island in `grid`_. If there is no island, return `0`.<br />
 
>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg">
<pre>
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
	       [0,0,0,0,0,0,0,1,1,1,0,0,0],
	       [0,1,1,0,1,0,0,0,0,0,0,0,0],
	       [0,1,0,0,1,1,0,0,1,0,1,0,0],
	       [0,1,0,0,1,1,0,0,1,1,1,0,0],
	       [0,0,0,0,0,0,0,0,0,0,1,0,0],
	       [0,0,0,0,0,0,0,1,1,1,0,0,0],
	       [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
</pre>
>Explanation: The answer is not 11, because the island must be connected 4-directionally.<br />
	
>Example 2:<br />
>Input: grid = [[0,0,0,0,0,0,0,0]]<br />
>Output: 0<br />
 
* Constraints: `m == grid.length`<br />
`n == grid[i].length`<br />
`1 <= m, n <= 50`<br />
`grid[i][j]` is either `0` or `1`.<br />

```cpp
class Solution{
    public:
    int dfs(vector<vector < int>> &grid, int i, int j,int &temp){
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j]){
            temp++;
            grid[i][j] = 0;
            dfs(grid, i - 1, j,temp);
            dfs(grid, i + 1, j,temp);
            dfs(grid, i, j - 1,temp);
            dfs(grid, i, j + 1,temp);
        }
       return temp;   
    }
    
    int maxAreaOfIsland(vector<vector < int>> &grid){
        int n = grid.size();
        int m = grid[0].size(); 
        int ans = 0;
		for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                {   int temp = 0;
                    int area = dfs(grid, i, j,temp);
                    ans = max(area, ans);
                }
        return ans;
    }
};
```

	
	
<br /> <br /> <br />**[1768. Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/)**<br />
You are given two strings `word1` and `word2`. Merge the strings by adding letters in alternating order, starting with `word1`. If a string is longer than the other, append the additional letters onto the end of the merged string.<br />
Return _the merged string_.<br />

>Example 1:<br />
Input: word1 = "abc", word2 = "pqr"<br />
Output: "apbqcr"<br />
Explanation: The merged string will be merged as so:<br />
<pre>
word1:  a   b   c
word2:    p   q   r
</pre>
merged: a p b q c r<br />
	
>Example 2:<br />
Input: word1 = "ab", word2 = "pqrs"<br />
Output: "apbqrs"<br />
Explanation: Notice that as word2 is longer, "rs" is appended to the end.<br />
<pre>
word1:  a   b 
word2:    p   q   r   s
</pre>
merged: a p b q   r   s<br />
	
>Example 3:<br />
Input: word1 = "abcd", word2 = "pq"<br />
Output: "apbqcd"<br />
Explanation: Notice that as word1 is longer, "cd" is appended to the end.<br />
<pre>
word1:  a   b   c   d
word2:    p   q 
</pre>
merged: a p b q c   d<br />

* Constraints: `1 <= word1.length, word2.length <= 100`<br />
`word1` and `word2` consist of lowercase English letters.<br />
	
```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int len1 = word1.size();
        int len2 = word2.size();
        if(word1.size()==word2.size()){
            for(int i = 0;i<word1.size();i++)res = res + word1[i] + word2[i];
            return res;
        }
        else if(len1>len2){ 
            for(int i = 0;i<len2;i++)res = res + word1[i] + word2[i];
            for(int i = len2;i<len1;i++)res = res + word1[i];
            return res;   
        }
        else if(len1<len2){ 
            for(int i = 0;i<len1;i++)res = res + word1[i] + word2[i];
            for(int i = len1;i<len2;i++)res = res + word2[i];
            return res;  
        }
        return res;
    }
};
```

					    
					    
					   
<br /> <br /> <br />**[1678. Goal Parser Interpretation](https://leetcode.com/problems/goal-parser-interpretation/)**<br />
You own a **Goal Parser** that can interpret a string `command`. The `command` consists of an alphabet of `"G"`, `"()"` and/or `"(al)"` in some order. The Goal Parser will interpret `"G"` as the string `"G"`, `"()"` as the string `"o"`, and `"(al)"` as the string `"al"`. The interpreted strings are then concatenated in the original order.<br />
Given the string `command`, return _the **Goal Parser's** interpretation of `command`_.<br />
	
>Example 1:<br />
Input: command = "G()(al)"<br />
Output: "Goal"<br />
Explanation: The Goal Parser interprets the command as follows:<br />
G -> G<br />
() -> o<br />
(al) -> al<br />
The final concatenated result is "Goal".<br />
	
>Example 2:<br />
Input: command = "G()()()()(al)"<br />
Output: "Gooooal"<br />
	
>Example 3:<br />
Input: command = "(al)G(al)()()G"<br />
Output: "alGalooG"<br />
 

* Constraints: `1 <= command.length <= 100`<br />
`command` consists of `"G"`, `"()"`, and/or `"(al)"` in some order.<br />
	
```cpp
class Solution {
public:
    string interpret(string command) {
        string res;
        for(int i=0;i<command.size();){
            if(command[i]=='G'){
                res+='G';
                i++;
            }else if(command[i]=='(' && command[i+1]==')'){
                res+='o';
                i=i+2;
            }else{
               res+="al";
                i=i+4;
            }
        }
        return res;
    }
};
```

					
					
<br /> <br /> <br />**[389. Find the Difference](https://leetcode.com/problems/find-the-difference/)**<br />
You are given two strings `s` and `t`.<br />
String `t` is generated by random shuffling string `s` and then add one more letter at a random position.<br />
Return the letter that was added to `t`.<br />
 
>Example 1:<br />
Input: s = "abcd", t = "abcde"<br />
Output: "e"<br />
Explanation: 'e' is the letter that was added.<br />
	
>Example 2:<br />
Input: s = "", t = "y"<br />
Output: "y"<br />
	
* Constraints: `0 <= s.length <= 1000`<br />
`t.length == s.length + 1`<br />
`s` and `t` consist of lowercase English letters.<br />
	
```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans-=s[i];
            ans+=t[i];
        }
        ans+=t[s.size()];  
        return ans;
    }
};
```

				     
				     
				     
<br /> <br /> <br />**[206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)**<br />
Given the `head` of a singly linked list, reverse the list, and return _the reversed list_.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg"><br />
>Input: head = [1,2,3,4,5]<br />
>Output: [5,4,3,2,1]<br />

>Example 2:<br />
><img src = "https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg"><br />
>Input: head = [1,2]<br />
>Output: [2,1]<br />
	
>Example 3:<br />
>Input: head = []<br />
>Output: []<br />
	
* Constraints: The number of nodes in the list is the range `[0, 5000]`.<br />
`-5000 <= Node.val <= 5000`<br />
	
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*forward=NULL;
    
        while(curr !=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;  
        }
        return prev; 
    }
};
```
	
	

<br /> <br /> <br />**[83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)**<br />
Given the `head` of a sorted linked list, delete _all duplicates such that each element appears only once_. Return _the linked list **sorted** as well_.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/01/04/list1.jpg"><br />
>Input: head = [1,1,2]<br />
>Output: [1,2]<br />
	
>Example 2:<br />
><img src = "https://assets.leetcode.com/uploads/2021/01/04/list2.jpg"><br />
>Input: head = [1,1,2,3,3]<br />
>Output: [1,2,3]<br />

* Constraints: The number of nodes in the list is in the range `[0, 300]`.<br />
`-100 <= Node.val <= 100`<br />
The list is guaranteed to be **sorted** in ascending order.<br />
	
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        while(curr && curr->next) {
            if(curr->val == curr->next->val)curr->next = curr->next->next;
            else curr = curr->next;
        }
        return head;
    }
};
```
	
	
	
<br /> <br /> <br />**[617. Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/)**<br />
You are given two binary trees `root1` and `root2`.<br />
Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.<br />
Return _the merged tree_.<br />
**Note**: The merging process must start from the root nodes of both trees.<br />
 
>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/02/05/merge.jpg"><br />
>Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]<br />
>Output: [3,4,5,5,4,null,7]<br />
	
>Example 2:<br />
>Input: root1 = [1], root2 = [1,2]<br />
>Output: [2,2]<br />

* Constraints: The number of nodes in both trees is in the range `[0, 2000]`.<br />
`-10^4 <= Node.val <= 10^4`<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return NULL;
        if(root1!=NULL && root2!=NULL){
            root1->val += root2->val;
            root1->left= mergeTrees(root1->left,root2->left);
            root1->right= mergeTrees(root1->right,root2->right);
        }
        if(root1==NULL && root2!=NULL)return root2;
        if(root1!=NULL && root2==NULL)return root1;
        return root1;
    }
};
```
	
	
	
<br /> <br /> <br />**[116. Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)**<br />
You are given a **perfect binary tree** where all leaves are on the same level, and every parent has two children.<br />
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.<br />
Initially, all next pointers are set to `NULL`.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2019/02/14/116_sample.png"><br />
>Input: root = [1,2,3,4,5,6,7]<br />
>Output: [1,#,2,3,#,4,5,6,7,#]<br />
>Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.<br />
	
>Example 2:<br />
>Input: root = []<br />
>Output: []<br />
 
* Constraints: The number of nodes in the tree is in the range `[0, 2^12 - 1]`.<br />
`-1000 <= Node.val <= 1000`<br />
	
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i ++){
                Node* node = q.front();
                q.pop();
				// in case of last node in every level 
                if(i == size - 1)  node->next = NULL;
				// else it points to to its next node in the same level
                else node->next = q.front();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
        }
        return root;
    }
};
```

	
	
	
<br /> <br /> <br />**[709. To Lower Case](https://leetcode.com/problems/to-lower-case/)**<br />
Given a string `s`, return _the string after replacing every uppercase letter with the same lowercase letter_.<br /> 

>Example 1:<br />
>Input: s = "Hello"<br />
>Output: "hello"<br />
	
>Example 2:<br />
>Input: s = "here"<br />
>Output: "here"<br />
	
>Example 3:<br />
>Input: s = "LOVELY"<br />
>Output: "lovely"<br />
 
* Constraints: `1 <= s.length <= 100`<br />
`s` consists of printable ASCII characters.<br />

```cpp
class Solution {
public:
    string toLowerCase(string s) {
        for(auto &i:s){
            if(i>='A' && i<='Z')i=i+32;
        }
        return s;
    }
};
/*
class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0; i<s.size(); i++){
            if(s[i]>=65 && s[i]<=90)s[i]=s[i]+32;
            else continue;    
        }
        return s;
    }
};
*/
```
					
					
					
<br /> <br /> <br />**[1309. Decrypt String from Alphabet to Integer Mapping](https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/)**<br />
You are given a string `s` formed by digits and `'#'`. We want to map `s` to English lowercase characters as follows:<br />
 * Characters (`'a'` to `'i'`) are represented by (`'1'` to `'9'`) respectively.<br />
 * Characters (`'j'` to `'z'`) are represented by (`'10#'` to `'26#'`) respectively.<br />
	
Return _the string formed after mapping_.<br />
The test cases are generated so that a unique mapping will always exist. <br />

>Example 1:<br />
>Input: s = "10#11#12"<br />
>Output: "jkab"<br />
>Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".<br />
	
>Example 2:<br />
>Input: s = "1326#"<br />
>Output: "acz"<br />

* Constraints: `1 <= s.length <= 1000`<br />
`s` consists of digits and the `'#'` letter.<br />
`s` will be a valid string such that mapping is always possible.<br />
	
```cpp
class Solution {
public:
    string freqAlphabets(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            if(i+2<s.length()){
                if(s[i+2]=='#'){
                    int x=stoi(s.substr(i,i+2));
                    x--;
                    ans+=char('a'+x);
                    i+=2;
                continue;
                }
            }
            int x=s[i]-'0';
            x--;
            ans+=char('a'+x);
        }
        return ans;
    }
};
```

	
	
	
	
<br /> <br /> <br />**[953. Verifying an Alien Dictionary](https://leetcode.com/problems/verifying-an-alien-dictionary/)**<br />
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different `order`. The `order` of the alphabet is some permutation of lowercase letters.<br />
Given a sequence of `words` written in the alien language, and the `order` of the alphabet, return `true` if and only if the given `words` are sorted lexicographically in this alien language.<br />

>Example 1:<br />
>Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"<br />
>Output: true<br />
>Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.<br />
	
>Example 2:<br />
>Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"<br />
>Output: false<br />
>Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.<br />
	
>Example 3:<br />
>Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"<br />
>Output: false<br />
>Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).<br />
 
* Constraints: `1 <= words.length <= 100`<br />
`1 <= words[i].length <= 20`<br />
`order.length == 26`<br />
All characters in `words[i]` and `order` are English lowercase letters.<br />
	
```cpp
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int si=words.size(), sio=order.size();
        vector<char>ele;
        map<char,int>mp;
        for(int i=0;i<sio;i++)mp[order[i]]=i;
        for (string &wp : words)
            for (char &c : wp)
                c = mp[c];
        return is_sorted(words.begin(), words.end());
    }
};
```

					   
					  
<br /> <br /> <br />**[20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)**<br />
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.
An input string is valid if:<br />
 1. Open brackets must be closed by the same type of brackets.<br />
 2. Open brackets must be closed in the correct order.<br />
 
>Example 1:<br />
>Input: s = "()"<br />
>Output: true<br />
	
>Example 2:<br />
>Input: s = "()[]{}"<br />
>Output: true<br />
	
>Example 3:<br />
>Input: s = "(]"<br />
>Output: false<br />
 
* Constraints: `1 <= s.length <= 10^4`<br />
`s` consists of parentheses only `'()[]{}'`.<br />
	
```cpp
class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> ss;
        for(int i=0;i<n;i++) {
            if(ss.empty()) {
                if(s[i]=='(' || s[i]=='{' || s[i]=='[') ss.push(s[i]);
                else return false;
            }
            else if(s[i]=='(' || s[i]=='{' || s[i]=='[') ss.push(s[i]);
            else {
                if(ss.top()=='(' && s[i]==')') ss.pop();
                else if(ss.top()=='[' && s[i]==']') ss.pop();
                else if(ss.top()=='{' && s[i]=='}') ss.pop();
                else return false;
            }
        }
        if(ss.size()==0) return true;
        return false;
    }
};
```

			     
			     
			     
<br /> <br /> <br />**[232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)**<br />
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `peek`, `pop`, and `empty`).<br />
Implement the `MyQueue` class:<br />
	
 * `void push(int x)` Pushes element x to the back of the queue.<br />
 * `int pop()` Removes the element from the front of the queue and returns it.<br />
 * `int peek()` Returns the element at the front of the queue.<br />
 * `boolean empty()` Returns `true` if the queue is empty, `false` otherwise.<br />
	
Notes:<br />
 * You must use **only** standard operations of a stack, which means only `push to top`, `peek/pop from top`, `size`, and `is empty` operations are valid.<br />
 * Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.<br />
 
>Example 1:<br />
>Input<br />
>["MyQueue", "push", "push", "peek", "pop", "empty"]<br />
>[[], [1], [2], [], [], []]<br />
>Output<br />
>[null, null, null, 1, 1, false]<br /><br />
>Explanation<br />
>MyQueue myQueue = new MyQueue();<br />
>myQueue.push(1); // queue is: [1]<br />
>myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)<br />
>myQueue.peek(); // return 1<br />
>myQueue.pop(); // return 1, queue is [2]<br />
>myQueue.empty(); // return false<br />
 
* Constraints: `1 <= x <= 9`<br />
At most `100` calls will be made to `push`, `pop`, `peek`, and `empty`.<br />
All the calls to `pop` and `peek` are valid.<br />

```cpp
class MyQueue {
public:
    stack<int> s, s1;
    MyQueue() { 
    }
    
    void push(int x) {
        while(!s.empty()) {
            s1.push(s.top()); s.pop();
        }
        s.push(x);
        
        while(!s1.empty()) {
            s.push(s1.top()); s1.pop();
        }
    }
    
    int pop() {
        int a = s.top();
        s.pop();
        return a;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```
	
	
	
	
<br /> <br /> <br />**[542. 01 Matrix](https://leetcode.com/problems/01-matrix/)**<br />
Given an `m x n` binary matrix `mat`, return _the distance of the nearest `0` for each cell_.<br />
The distance between two adjacent cells is `1`.<br />
 
>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg"><br />
>Input: mat = [[0,0,0],[0,1,0],[0,0,0]]<br />
>Output: [[0,0,0],[0,1,0],[0,0,0]]<br />
	
>Example 2:<br />
><img src = "https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg"><br />
>Input: mat = [[0,0,0],[0,1,0],[1,1,1]]<br />
>Output: [[0,0,0],[0,1,0],[1,2,1]]<br />
 
* Constraints: `m == mat.length`<br />
`n == mat[i].length`<br />
`1 <= m, n <= 10^4`<br />
`1 <= m * n <= 10^4`<br />
`mat[i][j]` is either `0` or `1`.
There is at least one `0` in `mat`.

```cpp
class Solution {
public:
    
    int dirX[8] = {0, 0, 1, -1};
    int dirY[8] = {1, -1, 0, 0};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    ans[i][j] = 0;
                    q.push({i, j});  
                }
            }
        }
        
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int dX = temp.first + dirX[i];
                int dY = temp.second + dirY[i];
                if(dX>=0 and dX<m and dY>=0 and dY<n){ /* check for valid boundary */
                    if(ans[dX][dY]==0)   /* if ans[dX][dY]=0, distance = 0, no modification */
                        continue;
                    if(ans[dX][dY]==INT_MAX){  /* if ans[dX][dY]=INT_MAX, the node has not been visited, update its distance by adding its                                                  neighbors value +1 */ 
                        ans[dX][dY] = ans[temp.first][temp.second] + 1;
                        q.push({dX, dY}); /* push the index, so that its neighbors take updated value at the index*/
                    }
                }
            }
        }
        return ans;
    }
};
```

						       
						       

<br /> <br /> <br />**[994. Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)**<br />
You are given an `m x n` grid where each cell can have one of three values:<br />
	 
 * `0` representing an empty cell,<br />
 * `1` representing a fresh orange, or<br />
 * `2` representing a rotten orange.<br />
	
Every minute, any fresh orange that is `4-directionally adjacent` to a rotten orange becomes rotten.<br />
Return the _minimum number of minutes that must elapse until no cell has a fresh orange_. If _this is impossible, return `-1`_.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2019/02/16/oranges.png"><br />
>Input: grid = [[2,1,1],[1,1,0],[0,1,1]]<br />
>Output: 4<br />
	
>Example 2:<br />
>Input: grid = [[2,1,1],[0,1,1],[1,0,1]]<br />
>Output: -1<br />
>Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.<br />
	
>Example 3:<br />
>Input: grid = [[0,2]]<br />
>Output: 0<br />
>Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.<br />

* Constraints: `m == grid.length`<br />
`n == grid[i].length`<br />
`1 <= m, n <= 10`<br />
`grid[i][j]` is `0`, `1`, or `2`.<br />

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dis[n][m];
        queue<pair<int,int>> Q;
       
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                dis[i][j] = INT_MAX;
                if(grid[i][j]==2){
                    Q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int xx = x+dx[i];
                int yy = y+dy[i];
                
                if(xx>=0 and xx<n and yy>=0 and yy<m and dis[xx][yy] == INT_MAX and grid[xx][yy]==1){
                    Q.push({xx,yy});
                    grid[xx][yy]=2;
                    dis[xx][yy] = dis[x][y]+1;
                }
            }
        }
        int time = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
			// we dont need to take care of 0 element and if dis of some orange is 
			// INT_MAX i.e its is not visited so return -1
                if(grid[i][j]!=0 and dis[i][j]==INT_MAX) return -1;
				
			// else the time is max of all dis calc
                else if(grid[i][j]==2) time = max(time,dis[i][j]);
            }
        }
        return time;    
    }
};
```
				 
				
				 
				 

<br /> <br /> <br />**[117. Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)**<br />
Given a binary tree<br />
<pre>
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
</pre><br />
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.<br />
Initially, all next pointers are set to `NULL`.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2019/02/15/117_sample.png"><br />
>Input: root = [1,2,3,4,5,null,7]<br />
>Output: [1,#,2,3,#,4,5,7,#]<br />
>Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.<br />
	
>Example 2:<br />
>Input: root = []<br />
>Output: []<br />
 
* Constraints: The number of nodes in the tree is in the range `[0, 6000]`.<br />
`-100 <= Node.val <= 100`<br />
	
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    { 
        // just created a queue because we are going to follow level order traversal and push our root into that initially
        queue<Node*> q;
        if(root)
            q.push(root);
        
        // BFS(Level) Traversal
        while(!q.empty())
        {
            // extracting the current queue size and make a next pointer with value NULL
            // because we pushing the elments in our queue -> right then left (and right next will always be NULL)
            int size = q.size();
            Node* nxt = nullptr;
            
            // do the traversal over current queue size
            for(int i=0;i<size;i++)
            {
                // extractong the queue front and pop that from our queue
                auto top = q.front();
                q.pop();
                
                // now according to need assign top next NULL
                // and make current top as next for the left element
                top->next = nxt;
                nxt = top;
                
                // push left and right nodes if they are available
                if(top->right)
                    q.push(top->right);
                if(top->left)
                    q.push(top->left);
            }
        }
        return root;
    }
};
```
	
	
	
<br /> <br /> <br />**[1290. Convert Binary Number in a Linked List to Integer](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)**<br />
Given `head` which is a reference node to a singly-linked list. The value of each node in the linked list is either `0` or `1`. The linked list holds the binary representation of a number.<br />
Return the _decimal value_ of the number in the linked list.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2019/12/05/graph-1.png"><br />
>Input: head = [1,0,1]<br />
>Output: 5<br />
>Explanation: (101) in base 2 = (5) in base 10<br />
	
>Example 2:<br />
>Input: head = [0]<br />
>Output: 0<br />
 
* Constraints: The Linked List is not empty.<br />
Number of nodes will not exceed `30`.<br />
Each node's value is either `0` or `1`.<br />
	
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int len=0;
        ListNode *temp1=head;
        while(temp1!=NULL){
            len++;
            temp1=temp1->next;
        }
        ListNode *temp2=head;
        int k=1;
        int res=0;
        while(temp2){
            res+=temp2->val*pow(2,len-k);
            k++;
            temp2=temp2->next;
        }
        return res;
    }
};
```
	
	
	
	
<br /> <br /> <br />**[104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)**<br />
Given the `root` of a binary tree, return its _maximum depth_.<br />
A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg"><br />
>Input: root = [3,9,20,null,null,15,7]<br />
>Output: 3<br />
	
>Example 2:<br />
>Input: root = [1,null,2]<br />
>Output: 2<br />
 
* Constraints: The number of nodes in the tree is in the range `[0, 10^4]`.<br />
`-100 <= Node.val <= 100`<br />

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
    }
};
```
	
	
	
	
<br /> <br /> <br />**[404. Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/)**<br />
Given the `root` of a binary tree, return _the sum of all left leaves_.<br />
A **leaf** is a node with no children. A **left leaf** is a leaf that is the left child of another node.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg"><br />
>Input: root = [3,9,20,null,null,15,7]<br />
>Output: 24<br />
>Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.<br />
	
>Example 2:<br />
>Input: root = [1]<br />
>Output: 0<br />
 
* Constraints: The number of nodes in the tree is in the range `[1, 1000]`.<br />
`-1000 <= Node.val <= 1000`<br />

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findLeftSum(TreeNode *root, int flag) {
        // flag will tell us whether the current node is the left one or right
        if(!root)
            return 0;
        // base case: left leaf node
        if(!root->left && !root->right)
            return flag == 1 ? root->val : 0;
        // recursive calls
        return findLeftSum(root->left, 1) + findLeftSum(root->right, 0);
    }
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        return findLeftSum(root, -1);
    }
};
```
	
	
	
	
	
<br /> <br /> <br />**[144. Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)**<br />
Given the `root` of a binary tree, return _the preorder traversal of its nodes' values_. <br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg"><br />
>Input: root = [1,null,2,3]<br />
>Output: [1,2,3]<br />
	
>Example 2:<br />
>Input: root = []<br />
>Output: []<br />
	
>Example 3:<br />
>Input: root = [1]<br />
>Output: [1]<br />

* Constraints: The number of nodes in the tree is in the range `[0, 100]`.<br />
`-100 <= Node.val <= 100`<br />

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorderTraversal(TreeNode *root, vector<int> &ar){
    if (root == NULL)return;
    ar.push_back(root->val);
    preorderTraversal(root->left, ar);
    preorderTraversal(root->right, ar);
}

vector<int> preorderTraversal(TreeNode *root){
    vector<int> ans;
    preorderTraversal(root, ans);
    return ans;
    }
};
```
	
	
	
	

<br /> <br /> <br />**[94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)**<br />
Given the `root` of a binary tree, return _the inorder traversal of its nodes' values_.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg"><br />
>Input: root = [1,null,2,3]<br />
>Output: [1,3,2]<br />
	
>Example 2:<br />
>Input: root = []<br />
>Output: []<br />
	
>Example 3:<br />
>Input: root = [1]<br />
>Output: [1]<br />
	
* Constraints: The number of nodes in the tree is in the range `[0, 100]`.<br />
`-100 <= Node.val <= 100`<br />

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
    
    void inorder(TreeNode* root, vector<int>&ans){
        if(root){
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
    }
};
```
	
	
	
	
	
	
<br /> <br /> <br />**[145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)**<br />
Given the `root` of a binary tree, return _the postorder traversal of its nodes' values_.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg"><br />
>Input: root = [1,null,2,3]<br />
>Output: [3,2,1]<br />
	
>Example 2:<br />
>Input: root = []<br />
>Output: []<br />
	
>Example 3:<br />
>Input: root = [1]<br />
>Output: [1]<br />
 
* Constraints: The number of the nodes in the tree is in the range `[0, 100]`.<br />
`-100 <= Node.val <= 100`<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void postorderTraversal(TreeNode *root, vector<int> &ans){
    if (root == NULL)return;
    postorderTraversal(root->left, ans);
    postorderTraversal(root->right, ans);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root){
    vector<int> ans;
    postorderTraversal(root, ans);
    return ans;
    }
};
```
	
	
	
	
	
<br /> <br /> <br />**[46. Permutations](https://leetcode.com/problems/permutations/)**<br />
Given an array `nums` of distinct integers, return _all the possible permutations_. You can return the answer in **any order**.<br />
	
>Example 1:<br />
Input: nums = [1,2,3]<br />
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]<br />
	
>Example 2:<br />
Input: nums = [0,1]<br />
Output: [[0,1],[1,0]]<br />
	
>Example 3:<br />
Input: nums = [1]<br />
Output: [[1]]<br />
 
* Constraints: `1 <= nums.length <= 6`<br />
`-10 <= nums[i] <= 10`<br />
All the integers of `nums` are **unique**.<br />

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        permuteRecursive(nums,0,result);
        return result;
    }
    
    void permuteRecursive(vector<int>&nums,int begin,vector<vector<int>>&result){
        if(begin>=nums.size()){
            result.push_back(nums);
            return;
        }
        for(int  i=begin;i<nums.size();i++){
            swap(nums[begin],nums[i]);
            permuteRecursive(nums,begin+1,result);
            swap(nums[begin],nums[i]);
        }
    }
};
```

					     
					     
					     
					     
<br /> <br /> <br />**[77. Combinations](https://leetcode.com/problems/combinations/)**<br />
Given two integers `n` and `k`, return _all possible combinations of k numbers out of the range_ `[1, n]`.<br />
You may return the answer in **any order**.<br />

>Example 1:<br />
>Input: n = 4, k = 2<br />
>Output:<br />
<pre>
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
</pre><br />
	
>Example 2:<br />
>Input: n = 1, k = 1<br />
>Output: [[1]]<br />

* Constraints: `1 <= n <= 20`<br />
`1 <= k <= n`<br />
	
```cpp
class Solution {
public:
    void Solve(int number,int n,int k,vector<vector<int>> &ans,vector<int> temp){
        if(k==0){                   // if no more numbers are needed --> add combination to answer
            ans.push_back(temp);
            return ;                // return from function once added 
        }
        if(number>n || (n-number+1 < k) ) return ;  // number not in range : [1,n] or 
        //k numbers can't be taken from left our numbers 
        Solve(number+1,n,k,ans,temp);               //Solving without taking number n 
        temp.push_back(number);                     // adding the number to temp (combination)
        Solve(number+1,n,k-1,ans,temp);             // Solving with number taken 
}   

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;                //ans --> stores all accepted combinations
        Solve(1,n,k,ans,{});                    //Solve() called with initial number =1 , ans and temp as empty vectors
        return ans;
    }
};
```
		
		
	
<br /> <br /> <br />**[784. Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/)**<br />
Given a string `s`, you can transform every letter individually to be lowercase or uppercase to create another string.<br />
Return _a list of all possible strings we could create_. Return the output in **any order**.<br />

>Example 1:<br />
>Input: s = "a1b2"<br />
>Output: ["a1b2","a1B2","A1b2","A1B2"]<br />
		
>Example 2:<br />
>Input: s = "3z4"<br />
>Output: ["3z4","3Z4"]<br />
 
* Constraints: `1 <= s.length <= 12`<br />
`s` consists of lowercase English letters, uppercase English letters, and digits.<br />

```cpp
class Solution {
    vector<string>v;
public:
    void solve(string ip, string &op) {
    if(ip.length() == 0) {
        v.push_back(op);
        return;
    }
    
    string op1 = op;
    string op2 = op;
    char c = ip[0];
    if(isalpha(c)) {
        op1.push_back(tolower(c));
        op2.push_back(toupper(c));
        ip.erase(ip.begin()+0);
        solve(ip, op1);
        solve(ip, op2);
    } else {
        string op1=op;
        op1.push_back(c);
        ip.erase(ip.begin()+0);
        solve(ip, op1);
    }
}

    vector<string> letterCasePermutation(string s) {
        string op="";
        solve(s, op);
        return v;
    }
};
```
		
		
		
		
<br /> <br /> <br />**[102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)**<br />
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg"><br />
>Input: root = [3,9,20,null,null,15,7]<br />
>Output: [[3],[9,20],[15,7]]<br />
	
>Example 2:<br />
>Input: root = [1]<br />
>Output: [[1]]<br />
	
>Example 3:<br />
>Input: root = []<br />
>Output: []<br />
 
* Constraints: The number of nodes in the tree is in the range `[0, 2000]`.<br />
`-1000 <= Node.val <= 1000`<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // it is storing our final ans
        vector<vector<int>> ans;
        // initializing queue for doing the BFS traversal
        queue<TreeNode*> q;
        // if our root is not null only then we will going to do BFS traversal
        if(root!=NULL) q.push(root);
        // BFS
        while(!q.empty()){
            // just extracting the size of current level (size of queue)
            // and initialize a 1D vector for storing each level individually
            int size = q.size();
            vector<int> tmp;
            // this part of code is storing the level elements into tmp vector
            for(int i=0;i<size;i++){
                // take out the front element from the queue and push it into our tmp
                auto top = q.front();
                q.pop();
                tmp.push_back(top->val);
                // if there is left and right exist for current value then push them into queue
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
            // after storing the level in our tmp vector , we need to give it our final 2D vector ans
            ans.push_back(tmp);
        }
        return ans;
    }
};
```
	
	
	
	
<br /> <br /> <br />**[101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)**<br />
Given the `root` of a binary tree,_ check whether it is a mirror of itself_ (i.e., symmetric around its center).<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg"><br />
>Input: root = [1,2,2,3,4,4,3]<br />
>Output: true<br />
	
>Example 2:<br />
><img src = "https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg"><br />
>Input: root = [1,2,2,null,3,null,3]<br />
>Output: false<br />
 
* Constraints: The number of nodes in the tree is in the range `[1, 1000]`.<br />
`-100 <= Node.val <= 100`<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      bool isMirror(TreeNode* root1, TreeNode* root2){
          if (root1 == NULL && root2 == NULL)return true;
			    //For two trees to be mirror images, the following three conditions must be true :
			    // 1.) Their root node's key must be same
			   // 2.) left subtree of left tree and right subtree of right tree have to be mirror images
			  // 3.) right subtree of left tree and left subtree of right tree have to be mirror images
          if (root1 && root2 && root1->val == root2->val)
              return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
          return false;
      }
      bool isSymmetric(TreeNode* root){
        return isMirror(root, root);
      }
};
```
	
	
	
	
<br /> <br /> <br />**[1356. Sort Integers by The Number of 1 Bits](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/)**<br />
You are given an integer array `arr`. Sort the integers in the array in ascending order by the number of `1`'s in their binary representation and in case of two or more integers have the same number of `1`'s you have to sort them in ascending order.<br />
Return _the array after sorting it_.<br />

>Example 1:<br />
>Input: arr = [0,1,2,3,4,5,6,7,8]<br />
>Output: [0,1,2,4,8,3,5,6,7]<br />
>Explantion: [0] is the only integer with 0 bits.<br />
>[1,2,4,8] all have 1 bit.<br />
>[3,5,6] have 2 bits.<br />
>[7] has 3 bits.<br />
>The sorted array by bits is [0,1,2,4,8,3,5,6,7]<br />
	
>Example 2:<br />
>Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]<br />
>Output: [1,2,4,8,16,32,64,128,256,512,1024]<br />
>Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.<br />
	
* Constraints: `1 <= arr.length <= 500`<br />
`0 <= arr[i] <= 10^4`<br />
	
```cpp
class Solution {
public:
    static bool comp(int a,int b){
        if(__builtin_popcount(a) < __builtin_popcount(b))
            return true;
        if(__builtin_popcount(a) == __builtin_popcount(b))
            return a<b;
        return false;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        stable_sort(arr.begin(),arr.end(),comp);
        return arr; 
    }
};
```
	
	
	
	
<br /> <br /> <br />**[1603. Design Parking System](https://leetcode.com/problems/design-parking-system/)**<br />
Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.
Implement the `ParkingSystem` class:<br />
 * `ParkingSystem(int big, int medium, int small)` Initializes object of the `ParkingSystem` class. The number of slots for each parking space are given as part of the constructor.<br />
 * `bool addCar(int carType)` Checks whether there is a parking space of `carType` for the car that wants to get into the parking lot. `carType` can be of three kinds: big, medium, or small, which are represented by `1`, `2`, and `3` respectively. **A car can only park in a parking space of its** `carType`. If there is no space available, return `false`, else park the car in that size space and return `true`.<br /><br />
 
>Example 1:<br />
>Input<br />
>["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]<br />
>[[1, 1, 0], [1], [2], [3], [1]]<br />
>Output<br />
>[null, true, true, false, false]<br />
>Explanation<br />
>ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);<br />
>parkingSystem.addCar(1); // return true because there is 1 available slot for a big car<br />
>parkingSystem.addCar(2); // return true because there is 1 available slot for a medium car<br />
>parkingSystem.addCar(3); // return false because there is no available slot for a small car<br />
>parkingSystem.addCar(1); // return false because there is no available slot for a big car. It is already occupied.<br />
 
* Constraints: `0 <= big, medium, small <= 1000`<br />
`carType` is `1`, `2`, or `3`<br />
At most `1000` calls will be made to `addCar`<br />
	
```cpp
class ParkingSystem {
public:
    int s[3];
    ParkingSystem(int big, int medium, int small) {
        s[0]=big;
        s[1]=medium;
        s[2]=small;
    }
    
    bool addCar(int carType) {
        carType--;
        if(s[carType]==0)
            return false;
        s[carType]--;
        return true;
        
    }
};
/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
```

	
	
	
	
	
<br /> <br /> <br />**[303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)**<br />
Given an integer array `nums`, handle multiple queries of the following type:<br />
 1. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.<br />
Implement the `NumArray` class:<br />
 * `NumArray(int[] nums)` Initializes the object with the integer array `nums`.<br />
 * `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).<br />
 
>Example 1:<br />
>Input<br />
>["NumArray", "sumRange", "sumRange", "sumRange"]<br />
>[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]<br />
>Output<br />
>[null, 1, -1, -3]<br />
>Explanation<br />
>NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);<br />
>numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1<br />
>numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1<br />
>numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3<br />
 
* Constraints: `1 <= nums.length <= 10^4`<br />
`-10^5 <= nums[i] <= 10^5`<br />
`0 <= left <= right < nums.length`<br />
At most `10^4` calls will be made to `sumRange`.<br />

```cpp
class NumArray {
public:
    vector<int>nums2;
    NumArray(vector<int>& nums) {
        for(auto i : nums)nums2.push_back(i);
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left ; i <= right ; i++)sum += nums2[i];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```
	
	
	
	
	
<br /> <br /> <br />**[226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)**<br />
Given the root of a binary tree, invert the tree, and return its root.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg"><br />
>Input: root = [4,2,7,1,3,6,9]<br />
>Output: [4,7,2,9,6,3,1]<br />
	
>Example 2:<br />
><img src = "https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg"><br />
>Input: root = [2,1,3]<br />
>Output: [2,3,1]<br />
	
>Example 3:<br />
>Input: root = []<br />
>Output: []<br />

* Constraints:<br />
The number of nodes in the tree is in the range `[0, 100]`.<br />
`-100 <= Node.val <= 100`<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* tmp;
        if (! root) return NULL;
        tmp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmp;
        return root;
    }
};
```
	
	
	
	
<br /> <br /> <br />**[112. Path Sum](https://leetcode.com/problems/path-sum/)**<br />
Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.<br />
A **leaf** is a node with no children.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg"><br />
>Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22<br />
>Output: true<br />
>Explanation: The root-to-leaf path with the target sum is shown.<br />
	
>Example 2:<br />
><img src = "https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg"><br />
>Input: root = [1,2,3], targetSum = 5<br />
>Output: false<br />
>Explanation: There two root-to-leaf paths in the tree:<br />
>(1 --> 2): The sum is 3.<br />
>(1 --> 3): The sum is 4.<br />
>There is no root-to-leaf path with sum = 5.<br />
	
>Example 3:<br />
>Input: root = [], targetSum = 0<br />
>Output: false<br />
>Explanation: Since the tree is empty, there are no root-to-leaf paths.<br />
 
* Constraints: The number of nodes in the tree is in the range `[0, 5000]`.<br />
`-1000 <= Node.val <= 1000`<br />
`-1000 <= targetSum <= 1000`<br />

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        if(root->left ==  NULL && root->right == NULL && root->val - targetSum == 0)return true;
       return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};
```
	
	
	
	
	
<br /> <br /> <br />**[70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)**<br />
You are climbing a staircase. It takes `n` steps to reach the top.<br />
Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?<br />

>Example 1:<br />
>Input: n = 2<br />
>Output: 2<br />
>Explanation: There are two ways to climb to the top.<br />
>1. 1 step + 1 step<br />
>2. 2 steps<br />
	
>Example 2:<br />
>Input: n = 3<br />
>Output: 3<br />
>Explanation: There are three ways to climb to the top.<br />
>1. 1 step + 1 step + 1 step<br />
>2. 1 step + 2 steps<br />
>3. 2 steps + 1 step<br />
 
* Constraints:` 1 <= n <= 45`<br />

```cpp
class Solution {
public:
    int helper(int ind, vector<int> &dp){
        if(ind==0)return dp[ind]+=1;
        if(dp[ind]!=0)return  dp[ind];
        if(ind>2)return dp[ind]=helper(ind-1,dp)+helper(ind-2,dp);
        return 0;
    }
    
    int climbStairs(int n) {
        if(n<=2)return n;
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        helper(n,dp);
        return dp[n];
    }
};
```
	
	
	
	
	
<br /> <br /> <br />**[198. House Robber](https://leetcode.com/problems/house-robber/)**<br />
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.<br />
Given an integer array `nums` representing _the amount of money of each house, return the maximum amount of money you can rob tonight **without alerting the police**_.<br />
	
>Example 1:<br />
>Input: nums = [1,2,3,1]<br />
>Output: 4<br />
>Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).<br />
>Total amount you can rob = 1 + 3 = 4.<br />
	
>Example 2:<br />
>Input: nums = [2,7,9,3,1]<br />
>Output: 12<br />
>Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).<br />
>Total amount you can rob = 2 + 9 + 1 = 12.<br />
 
* Constraints: `1 <= nums.length <= 100`<br />
`0 <= nums[i] <= 400`<br />

```cpp
class Solution {
    public:
    const static int N = 110;
    int dp[N];
    int helper(vector<int>& nums, int ind) {
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = max(nums[ind] + helper(nums, ind - 2), helper(nums, ind - 1));
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, nums.size() - 1);
    }      
};
```
	
	
	
	
<br /> <br /> <br />**[120. Triangle](https://leetcode.com/problems/triangle/)**<br />
Given a `triangle` array, return _the minimum path sum from top to bottom_.<br />
For each step, you may move to an adjacent number of the row below. More formally, if you are on index `i` on the current row, you may move to either index `i` or index `i + 1` on the next row.<br />

>Example 1:<br />
>Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]<br />
>Output: 11<br />
>Explanation: The triangle looks like:<br />
<pre>
   2
  3 4
 6 5 7
4 1 8 3
</pre>
>The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).<br />
	
>Example 2:<br />
>Input: triangle = [[-10]]<br />
>Output: -10<br />

* Constraints: `1 <= triangle.length <= 200`<br />
`triangle[0].length == 1`<br />
`triangle[i].length == triangle[i - 1].length + 1`<br />
`-10^4 <= triangle[i][j] <= 10^4`<br />

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2;i>=0;i--)
            for(int j=0;j<=i;j++)
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
        return triangle[0][0];
    }
};
```
				 
				 
				 
<br /> <br /> <br />**[231. Power of Two](https://leetcode.com/problems/power-of-two/)**<br />
Given an integer `n`, return `true` _if it is a power of two. Otherwise, return `false`_.<br />
An integer `n` is a power of two, if there exists an integer `x` such that `n == 2^x`.<br />

>Example 1:<br />
Input: n = 1<br />
Output: true<br />
Explanation: 20 = 1<br />
	
>Example 2:<br />
Input: n = 16<br />
Output: true<br />
Explanation: 24 = 16<br />

>Example 3:<br />
Input: n = 3<br />
Output: false<br />
 
* Constraints: `-2^31 <= n <= 2^31 - 1`<br />
	
```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return ((n&(n-1))==0);
    }
};
```

		

<br /> <br /> <br />**[190. Reverse Bits](https://leetcode.com/problems/reverse-bits/)**<br />
Reverse bits of a given 32 bits unsigned integer.<br />
**Note:**<br />
 * Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.<br />
 * In Java, the compiler represents the signed integers using `2's complement notation`. Therefore, in **Example 2** above, the input represents the signed integer `-3` and the output represents the signed integer `-1073741825`.<br />
 
>Example 1:<br />
Input: n = 00000010100101000001111010011100<br />
Output:    964176192 (00111001011110000010100101000000)<br />
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.<br />
	
>Example 2:<br />
Input: n = 11111111111111111111111111111101<br />
Output:   3221225471 (10111111111111111111111111111111)<br />
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.<br />

* Constraints: The input must be a **binary string** of length `32`<br />
	
```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int res = 0;
        for(int i=0; i<32; i++){
            res = res*2 + n%2;
            n /= 2;
        }
        return res;
    }
};
```
			   
			   
			   
			   
			   
			   
<br /> <br /> <br />**[136. Single Number](https://leetcode.com/problems/single-number/)**<br />
Given a **non-empty** array of integers `nums`, every element appears _twice_ except for one. Find that single one.<br />
You must implement a solution with a linear runtime complexity and use only constant extra space.<br />

>Example 1:<br />
Input: nums = [2,2,1]<br />
Output: 1<br />
	
>Example 2:<br />
Input: nums = [4,1,2,1,2]<br />
Output: 4<br />
	
>Example 3:<br />
Input: nums = [1]<br />
Output: 1<br />

* Constraints: `1 <= nums.length <= 3 * 10^4`<br />
`-3 * 10^4 <= nums[i] <= 3 * 10^4`<br />
Each element in the array appears twice except for one element which appears only once.<br />
	
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
	    for(auto x:nums)
	    ans^=x;
	    return ans;
    }
};
```

	
	

<br /> <br /> <br />**[701. Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/)**<br />
You are given the `root` node of a binary search tree (BST) and a `value` to insert into the tree. Return _the root node of the BST after the insertion._ It is **guaranteed** that the new value does not exist in the original BST.<br />
**Notice** that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return **any of them**.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/10/05/insertbst.jpg"><br />
Input: root = [4,2,7,1,3], val = 5<br />
Output: [4,2,7,1,3,5]<br />
Explanation: Another accepted tree is:<br />
<img src = "https://assets.leetcode.com/uploads/2020/10/05/bst.jpg"><br />
	
>Example 2:<br />
Input: root = [40,20,60,10,30,50,70], val = 25<br />
Output: [40,20,60,10,30,50,70,null,null,25]<br />
	
>Example 3:<br />
Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5<br />
Output: [4,2,7,1,3,5]<br />
 
* Constraints: The number of nodes in the tree will be in the range `[0, 10^4]`.<br />
`-10^8 <= Node.val <= 10^8`<br />
All the values `Node.val` are **unique**.<br />
`-10^8 <= val <= 10^8`<br />
It's **guaranteed** that `val` does not exist in the original BST.<br />

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * lol= new TreeNode(val);
        if(root ==NULL)return lol;
        
        else if(root->val >val )
            root->left = insertIntoBST(root->left,val);
        else
            root->right = insertIntoBST(root->right,val);
        
        return root;
    }
};
```

	
	
	
<br /> <br /> <br />**[98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)**<br />
Given the `root` of a binary tree, _determine if it is a valid binary search tree (BST)._<br />
A **valid BST** is defined as follows:<br />
	
 * The left subtree of a node contains only nodes with keys **less than** the node's key.<br />
 * The right subtree of a node contains only nodes with keys **greater than** the node's key.<br />
 * Both the left and right subtrees must also be binary search trees.<br />
 

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg"><br />
Input: root = [2,1,3]<br />
Output: true<br />
	
>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg"><br />
Input: root = [5,1,4,null,null,3,6]<br />
Output: false<br />
Explanation: The root node's value is 5 but its right child's value is 4.<br />
	
* Constraints: The number of nodes in the tree is in the range `[1, 10^4]`.<br />
`-2^31 <= Node.val <= 2^31 - 1`<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>v;
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        
    }
    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i=0;i<v.size()-1;i++) 
            if(v[i]>=v[i+1]) 
               return false;
        return true;
    }
};
```
	
	
	
<br /> <br /> <br />**[653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)**<br />
Given the `root` of a Binary Search Tree and a target number `k`, return _`true` if there exist two elements in the BST such that their sum is equal to the given target._<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/09/21/sum_tree_1.jpg"><br />
Input: root = [5,3,6,2,4,null,7], k = 9<br />
Output: true<br />
	
>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2020/09/21/sum_tree_2.jpg"><br />
Input: root = [5,3,6,2,4,null,7], k = 28<br />
Output: false<br />
 
* Constraints: The number of nodes in the tree is in the range `[1, 10^4]`.<br />
`-10^4 <= Node.val <= 10^4`<br />
root is guaranteed to be a **valid** binary search tree.<br />
`-10^5 <= k <= 10^5`<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isPair(TreeNode* root,int k,unordered_set<int> &s){
        if(root==NULL)
            return false;
        if(s.find(k-root->val)!=s.end())
            return true;
        else
            s.insert(root->val);
        return isPair(root->left,k,s)||isPair(root->right,k,s);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return isPair(root,k,s);
    }
};
```

	
	
	
<br /> <br /> <br />**[235. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)**<br />
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.<br />
According to the `definition of LCA on Wikipedia`: “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).” <br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png"><br />
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8<br />
Output: 6<br />
Explanation: The LCA of nodes 2 and 8 is 6.<br />
	
>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png"><br />
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4<br />
Output: 2<br />
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.<br />
	
>Example 3:<br />
Input: root = [2,1], p = 2, q = 1<br />
Output: 2<br />
 
* Constraints: The number of nodes in the tree is in the range `[2, 10^5]`.<br />
`-10^9 <= Node.val <= 10^9`<br />
All `Node.val` are **unique**.<br />
`p != q`<br />
`p` and `q` will exist in the BST.<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        
        if(root->val == p->val or root->val == q->val) return root;
        
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        
        if(l and r) return root;
        if(l) return l;
        else return r;
    }
};
```
	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)**<br />
Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return _the binary tree_.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/02/19/tree.jpg"><br />
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]<br />
Output: [3,9,20,null,null,15,7]<br />
	
>Example 2:<br />
Input: preorder = [-1], inorder = [-1]<br />
Output: [-1]<br />

* Constraints:<br />
`1 <= preorder.length <= 3000`<br />
`inorder.length == preorder.length`<br />
`-3000 <= preorder[i], inorder[i] <= 3000`<br />
`preorder` and `inorder` consist of **unique** values.<br />
Each value of `inorder` also appears in `preorder`.<br />
`preorder` is **guaranteed** to be the preorder traversal of the tree.<br />
`inorder` is **guaranteed** to be the inorder traversal of the tree.<br />
	
<pre>
Inorder Traversal -> LEFT -> ROOT ->RIGHT
PreOrder Traversal -> ROOT -> LEFT -> RIGHT
</pre>
	
We have two observations :<br />
 * The first element in `preorder` is the root of the tree. Let it be `x`<br />
 * Elements left to `x` in `inorder` form the **LEFT** subtree.<br />
 * Elements right to `x` in `inorder` forms the **RIGHT** subtree.<br />
	
<img src = "https://assets.leetcode.com/users/images/81b4c4aa-69bd-4fdc-a6a2-a9b34f73b8ac_1657767778.6491113.png"><br />
**Recursive Approach**<br />
**BASE CASE** -> If the array `inorder` is empty. -> RETURN<br />
**SELF WORK** -> Create a new node with the value `preorder[ start_pre ]` as first element is the root of the tree.<br />
**Recursion** -><br />
 * Let the `index` of `preorder[ start_pre ]` in `inorder` be `INDEX`.<br />
 * Recursivly create **left** subtree by passing -> `preorder with first element removed` and the part of `inorder` array that lies to the left of `INDEX`. ->`inorder[:INDEX]`<br />
_To be memory efficient, pass the vector by refernce and pass `start_in` and `end_in` as starting index and ending index for `inorder` array_.<br />
 * Recursivly create **right** subtree by passing -> the part of `inorder` array that lies to the right of `INDEX`. ->`inorder[:INDEX]`<br />
_To be memory efficient, pass the vector by refernce and pass `start_in` and `end_in` as starting index and ending index for `inorder` array._<br /><br />

**start_pre** ->starting index of `preorder`<br />
**start_in** ->starting index of `inorder`<br />
**end_in** ->ending index of `inorder`<br />
INDEX = index of `preorder [ start_pre ]` in vector `inorder`.<br />

 * For **LEFT RECUSIVE CALL** `start_in remains same`, `end_in = INDEX - 1`, `start_pre = start_pre + 1`.
 * For **RIGHT RECURSIVE CALL** `end_in remains same`, `start_in = INDEX + 1`, `start_pre = (start_pre + 1) + (index - start_in)`.
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(int start_pre, int start_in, int end_in, vector<int>& preorder, vector<int>& inorder) 
    {
        
        if(start_in > end_in || start_pre > preorder.size()-1) return NULL;
        
        TreeNode* root = new TreeNode(preorder[start_pre]);
        
        int index = 0;
        for(int i = start_in; i <= end_in; i++)
            if(root->val == inorder[i]) index = i;
            
        root->left = solve(start_pre+1, start_in, index-1, preorder, inorder);
        root->right = solve(start_pre+index-start_in+1, index+1, end_in, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return solve(0, 0, inorder.size()-1, preorder, inorder);
    }
};
```
	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)**<br />
Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return _the reversed list_.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg"><br />
Input: head = [1,2,3,4,5], left = 2, right = 4<br />
Output: [1,4,3,2,5]<br />
	
>Example 2:<br />
Input: head = [5], left = 1, right = 1<br />
Output: [5]<br />
	
* Constraints: The number of nodes in the list is `n`.<br />
`1 <= n <= 500`<br />
`-500 <= Node.val <= 500`<br />
`1 <= left <= right <= n`<br />
	
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
            dummy->next = head;
            for (int i = 0; i < left - 1; i++){
                pre = pre->next;
            }
            cur = pre->next;
            for (int i = 0; i < right - left; i++){
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
            }
            return dummy->next;
    }
};
```

	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[86. Partition List](https://leetcode.com/problems/partition-list/)**<br />
Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.<br />
You should **preserve** the original relative order of the nodes in each of the two partitions.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/01/04/partition.jpg"><br />
Input: head = [1,4,3,2,5,2], x = 3<br />
Output: [1,2,2,4,3,5]<br />
	
>Example 2:<br />
Input: head = [2,1], x = 2<br />
Output: [1,2]<br />
 
* Constraints: The number of nodes in the list is in the range `[0, 200]`.<br />
`-100 <= Node.val <= 100`<br />
`-200 <= x <= 200`<br />
	
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        ListNode* small_head = small;
        ListNode* large_head = large;
        
        while (head){
            if (head->val < x){
                small->next = head;
                small = small -> next;
                head = head -> next;
                small->next = NULL;
            }
            else{
                large->next = head;
                large = large -> next;
                head = head -> next;
                large -> next = NULL;
            }
        }
        small -> next = large_head -> next;

        return small_head -> next;
    }
};
```
	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[114. Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)**<br />
Given the `root` of a binary tree, flatten the tree into a "linked list":<br />

 * The "linked list" should use the same `TreeNode` class where the `right` child pointer points to the next node in the list and the `left` child pointer is always `null`.<br />
 * The "linked list" should be in the same order as a **pre-order traversal** of the binary tree.<br />
 
>Example 1:<br />
<img src ="https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg"><br />
Input: root = [1,2,5,3,4,null,6]<br />
Output: [1,null,2,null,3,null,4,null,5,null,6]<br />

>Example 2:<br />
Input: root = []<br />
Output: []<br />
	
>Example 3:<br />
Input: root = [0]<br />
Output: [0]<br />
 
* Constraints: The number of nodes in the tree is in the range `[0, 2000]`.<br />
`-100 <= Node.val <= 100`<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* rightmost(TreeNode* root){
        if (root->right==NULL) return root;
        return rightmost(root->right);
    }
    
    void flatten(TreeNode* root) {
        if (root==NULL) return;
        TreeNode* nextright;
        TreeNode* rightMOST;
        
        while (root){
            
            if (root->left){
                rightMOST = rightmost(root->left);
                nextright = root->right;
                root->right = root->left;
                root->left=NULL;
                rightMOST->right=nextright;
            }
            root=root->right;
        }
    }
};
```

	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[240. Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/)**<br />
Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`.<br />
This matrix has the following properties:<br />

 * Integers in each row are sorted in ascending from left to right.<br />
 * Integers in each column are sorted in ascending from top to bottom.<br />
 
>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/11/24/searchgrid2.jpg"><br />
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5<br />
Output: true<br />
	
>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2020/11/24/searchgrid.jpg"><br />
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20<br />
Output: false<br />

* Constraints: `m == matrix.length`<br />
`n == matrix[i].length`<br />
`1 <= n, m <= 300`<br />
`-10^9 <= matrix[i][j] <= 10^9`<br />
All the integers in each row are **sorted** in ascending order.<br />
All the integers in each column are **sorted** in ascending order.<br />
`-10^9 <= target <= 10^9`<br />
	
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), i = m - 1, j = 0;
        while (i>=0 && j<n){
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) j++;
            else i--;
        }
        return false;
    }
};

//using binary search 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int lo, hi, mid;      
        for (int i=0; i<m; i++){
            if (mat[i][0]<=target && mat[i][n-1]>=target){
                lo = 0;
                hi = n - 1;
				if (lo==hi && mat[i][lo]==target) return true;
                while (lo < hi){
                    mid = (lo + hi) / 2;
                    if (mat[i][mid] == target) return true;
                    else if (mat[i][mid] < target) lo = mid + 1;
                    else hi = mid;
                }
            }
        }
        return false;
    }
};
```

	
	
	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)**<br />
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.<br />
According to the `definition of LCA on Wikipedia`: “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”<br />

>Example 1:<br />
<img src ="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png"><br />
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1<br />
Output: 3<br />
Explanation: The LCA of nodes 5 and 1 is 3.<br />

>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2018/12/14/binarytree.png"><br />
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4<br />
Output: 5<br />
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.<br />
	
>Example 3:<br />
Input: root = [1,2], p = 1, q = 2<br />
Output: 1<br />
 
* Constraints: The number of nodes in the tree is in the range `[2, 10^5]`.<br />
`-10^9 <= Node.val <= 10^9`<br />
All `Node.val` are **unique**.<br />
`p != q`<br />
`p` and `q` will exist in the tree.<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if (root == p || root == q)return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right)return root;
        return left? left: right;
    }
};
```

	
	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)**<br />
Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.<br />
If `target` is not found in the array, return `[-1, -1]`.<br />
You must write an algorithm with `O(log n)` runtime complexity.<br />

>Example 1:<br />
Input: nums = [5,7,7,8,8,10], target = 8<br />
Output: [3,4]<br />

>Example 2:<br />
Input: nums = [5,7,7,8,8,10], target = 6<br />
Output: [-1,-1]<br />

>Example 3:<br />
Input: nums = [], target = 0<br />
Output: [-1,-1]<br />
 
* Constraints: `0 <= nums.length <= 10^5`<br />
`-10^9 <= nums[i] <= 10^9`<br />
`nums` is a non-decreasing array.<br />
`-10^9 <= target <= 10^9`<br />

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(),nums.end(),target);
        auto up = upper_bound(nums.begin(),nums.end(),target);
        
        if(!binary_search(nums.begin(),nums.end(),target))    return {-1,-1};
        
        int first = low - nums.begin();
        int last = up - nums.begin()-1;
        
        return {first ,last};
    }
};

// not using upper bound and lower bound function
class Solution {
public:
    int getIndex(vector<int>& nums, int target, bool getFirst){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s<=e) {
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                ans = mid;          
                if(getFirst)  e = mid - 1;     
                else	s = mid + 1;                
            }
            else if(nums[mid] > target) e = mid - 1;
            else   s= mid + 1;
        }
        return ans;   
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>  v(2 , -1);

        int first = getIndex(nums, target, true);
        if(first == -1)  return v;
        int last = getIndex(nums, target, false);
        v[0] = first;
        v[1] = last;
        return v;
    }
};
```
	
	
<br /> <br /> <br />**[62. Unique Paths](https://leetcode.com/problems/unique-paths/)**<br />
There is a robot on an `m x n` grid. The robot is initially located at the `top-left` corner (i.e., `grid[0][0]`). The robot tries to move to the `bottom-right` corner (i.e., `grid[m - 1][n - 1]`). The robot can only move either `down` or `right` at any point in time.<br />
Given the two integers `m` and `n`, return the number of possible unique paths that the robot can take to reach the `bottom-right corner`.<br />
The test cases are generated so that the answer will be less than or equal to `2 * 10^9`.<br />
 
>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png"><br />
Input: m = 3, n = 7<br />
Output: 28<br />

>Example 2:<br />
Input: m = 3, n = 2<br />
Output: 3<br />
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:<br />
1. Right -> Down -> Down<br />
2. Down -> Down -> Right<br />
3. Down -> Right -> Down<br />
 
* Constraints: `1 <= m, n <= 100`<br />
	
```cpp
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp, int& m, int& n) {
        if(i == m-1 || j == n-1) return 1;
        if(dp[i][j] != 0)return dp[i][j];
        
        dp[i][j] = solve(i+1, j, dp, m, n) + solve(i, j+1, dp, m, n);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , 0));
        return solve(0, 0, dp, m, n);
    }
};	
```
	
<br /> <br /> <br />**[378. Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)**<br />
Given an `n x n` `matrix` where each of the rows and columns is sorted in ascending order, return _the `kth` smallest element in the matrix_.<br />
Note that it is the `kth` smallest element **in the sorted order**, not the `kth` **distinct** element.<br />
You must find a solution with a memory complexity better than `O(n^2)`.<br />

>Example 1:<br />
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8<br />
Output: 13<br />
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13<br />

>Example 2:<br />
Input: matrix = [[-5]], k = 1<br />
Output: -5<br />
 
* Constraints: `n == matrix.length == matrix[i].length`<br />
`1 <= n <= 300`<br />
`-10^9 <= matrix[i][j] <= 10^9`<br />
All the rows and columns of `matrix` are **guaranteed** to be sorted in **non-decreasing order**.<br />
`1 <= k <= n^2`<br />
	
```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        int low = matrix[0][0];
        int high = matrix[n-1][n-1]; 
        
        int mid, temp, count;
        
        while(low < high){
            mid = low + (high-low)/2;
            temp = n - 1;
            count = 0;
            
            for(int i = 0; i < n; i++){
                
                while(temp >= 0 && matrix[i][temp] > mid){
                    temp--;
                }
                count+= (temp+1);
            }
            
            if(count < k){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};
```
	
	
	
<br /> <br /> <br />**[108. Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)**<br />
Given an integer array `nums` where the elements are sorted in **ascending order**, convert _it to a **height-balanced** binary search tree_.<br />
A **height-balanced** binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg"><br />
Input: nums = [-10,-3,0,5,9]<br />
Output: [0,-3,9,-10,null,5]<br />
Explanation: [0,-10,5,null,-3,null,9] is also accepted:<br />
<img src = "https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg"><br />

>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2021/02/18/btree.jpg"><br />
Input: nums = [1,3]<br />
Output: [3,1]<br />
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.<br />
 
* Constraints: `1 <= nums.length <= 10^4`<br />
`-10^4 <= nums[i] <= 10^4`<br />
`nums` is sorted in a **strictly increasing** order.<br />

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
     TreeNode* convertintoBST(vector<int>& nums, int left, int right) 
    {
        if(left > right) return NULL;
        int mid = left+(right-left)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = convertintoBST(nums,left,mid-1);
        node->right = convertintoBST(nums,mid+1,right);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size() == 0) return NULL;
        return convertintoBST(nums,0,nums.size()-1);
    }
};
```


	



<br /> <br /> <br />**[234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)**<br />
Given the `head` of a singly linked list, return `true` _if it is a palindrome or `false` otherwise_.<br />

Example 1:
<pre>
<img src = "https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg">
Input: head = [1,2,2,1]
Output: true
</pre>
Example 2:
<pre>
<img src = "https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg">
Input: head = [1,2]
Output: false
</pre>
	
* Constraints: The number of nodes in the list is in the range `[1, 10^5]`.<br />
`0 <= Node.val <= 9`<br />
	
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* temp;
    
    bool check(ListNode* head) {
        if (NULL == head) return true;
        bool res = check(head->next) & (temp->val == head->val);
        temp = temp->next;
        return res;
    }
    
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
};
```
	
	
	
<br /> <br /> <br />**[1329. Sort the Matrix Diagonally](https://leetcode.com/problems/sort-the-matrix-diagonally/)**<br />
A **matrix diagonal** is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the **matrix diagonal** starting from `mat[2][0]`, where `mat` is a `6 x 3` matrix, includes cells `mat[2][0]`, `mat[3][1]`, and `mat[4][2]`.<br />
Given an `m x n` matrix `mat` of integers, sort each **matrix diagonal** in ascending order and return the resulting matrix.<br />
	
Example 1:
<pre>
<img src = "https://assets.leetcode.com/uploads/2020/01/21/1482_example_1_2.png">
Input: mat = [[3,3,1,1],
              [2,2,1,2],
	      [1,1,1,2]]
Output: [[1,1,1,1],
         [1,2,2,2],
	 [1,2,3,3]]
</pre>
Example 2:
<pre>
Input: mat = [[11,25,66,1,69,7],
             [23,55,17,45,15,52],
	     [75,31,36,44,58, 8],
	     [22,27,33,25,68, 4],
	     [84,28,14,11, 5,50]]
Output: [[ 5,17, 4, 1,52,7],
        [11,11,25,45, 8,69],
	[14,23,25,44,58,15],
	[22,27,31,36,50,66],
	[84,28,75,33,55,68]]
</pre>

* Constraints: `m == mat.length`<br />
`n == mat[i].length`<br />
`1 <= m, n <= 100`<br />
`1 <= mat[i][j] <= 100`<br />
	
```cpp
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> k;
        int m = mat.size() , n = mat[0].size();
        for (int r=0; r<m; r++)        // r-> row
        {
            k.clear();
            for (int j=0,i=r; j<n && i<m ; j++,i++) k.push_back(mat[i][j]);    // add to vector
            sort(k.begin(),k.end());
            for (int j=0,i=r; j<n && i<m ; j++,i++) mat[i][j]=k[j];            // replace
        }
        for (int c=1; c<n; c++)       // c->column
        {
            k.clear();
            for (int i=0, j=c; j<n && i<m; i++, j++) k.push_back(mat[i][j]);   // add to vector
            sort(k.begin(),k.end());
            for (int i=0, j=c; j<n && i<m; i++, j++) mat[i][j] = k[i];         //replace
        }
        return mat;
    }
};

//TIME : O ( N * LOG N ) -> sort
//O ( N ) -> number of diagonals
//TOTAL -> O ( N * N * LOG N )
//SPACE : O ( N ) -> Only on extra vector used
```
	
	
	
<br /> <br /> <br />**[200. Number of Islands](https://leetcode.com/problems/number-of-islands/)**<br />
Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return _the number of islands_.<br />
An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.<br />
	
Example 1:
<pre>
Input: grid = [["1","1","1","1","0"],
               ["1","1","0","1","0"],
               ["1","1","0","0","0"],
               ["0","0","0","0","0"]]
Output: 1
</pre>
Example 2:
<pre>
Input: grid = [["1","1","0","0","0"],
               ["1","1","0","0","0"],
               ["0","0","1","0","0"],
               ["0","0","0","1","1"]]
Output: 3
</pre>

* Constraints: `m == grid.length`<br />
`n == grid[i].length`<br />
`1 <= m, n <= 300`<br />
`grid[i][j]` is `'0'` or `'1'`.<br />
	
```cpp
class Solution {
public:
    
    void turn_to_dust(vector<vector<char>>& grid, int i, int j, int m, int n){
        if (i<0 || j<0 || i==m || j==n || grid[i][j]=='0') return;
        grid[i][j]='0';
        turn_to_dust(grid,i+1,j,m,n);
        turn_to_dust(grid,i,j+1,m,n);
        turn_to_dust(grid,i-1,j,m,n);
        turn_to_dust(grid,i,j-1,m,n);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]=='1'){
                    res++;
                    turn_to_dust(grid,i,j,m,n);
                }
            }
        }
        return res;
    }
};
```
	
	
	
	
	
<br /> <br /> <br />**[48. Rotate Image](https://leetcode.com/problems/rotate-image/)**<br />
You are given an `n x n` 2D `matrix` representing an image, rotate the image by **90** degrees (clockwise).<br />
You have to rotate the image **in-place**, which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.<br />

Example 1:
<pre>
<img src = "https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg">
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
</pre>
Example 2:
<pre>
<img src = "https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg">
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
</pre>
	
* Constraints: `n == matrix.length == matrix[i].length`<br />
`1 <= n <= 20`<br />
`-1000 <= matrix[i][j] <= 1000`<br />
	
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
```
	
	
	
	
	
<br /> <br /> <br />**[637. Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/)**<br />
Given the `root` of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within `10^-5` of the actual answer will be accepted.<br />
	
Example 1:
<pre>
<img src = "https://assets.leetcode.com/uploads/2021/03/09/avg1-tree.jpg">
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
</pre>
Example 2:
<pre>
<img src = "https://assets.leetcode.com/uploads/2021/03/09/avg2-tree.jpg">
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
</pre>

* Constraints: The number of nodes in the tree is in the range `[1, 10^4]`.<br />
`-2^31 <= Node.val <= 2^31 - 1`<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        // while there are nodes remaining to be visited
        while(!q.empty()){
            double temp = q.size();
            double sum = 0;
            // iterating each level of binary tree
            for(int i = 0; i < temp; i++){
                auto tt = q.front();
                q.pop();
                sum += (tt->val);
				// check for not NULL and pushing into queue.
                if(tt->left){
                    q.push(tt->left);
                }
                if(tt->right){
                    q.push(tt->right);
                }
            }
            ans.push_back(sum/ temp);
        }
        return ans;
    }
};
//Time Complexity : O(N), where N is the number of nodes in the given Tree.
//Space Complexity : O(M), where M is the maximum number of nodes at any level in the binary tree.
```
	
	
	
<br /> <br /> <br />**[429. N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)**<br />
Given an `n-ary tree`, return the level order traversal of its nodes' values.<br />
`N ary-Tree` input serialization is represented in their `level order traversal`, each group of children is separated by the `null value` (See examples).<br />
	
Example 1:
<pre>
<img src = "https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png">
Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]
</pre>
Example 2:
<pre>
<img src = "https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png">
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
</pre>

* Constraints: The height of the n-ary tree is less than or equal to `1000`<br />
The total number of nodes is between `[0, 10^4]`<br />
	
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> temp;
            int s = q.size();
            
            for(int i = 0; i < s; i++){
                temp.push_back(q.front()->val);
                
                Node* temp = q.front();
                q.pop();
                
                for(Node* child : temp->children)
                q.push(child);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//Time complexity is O(n) to traverse our tree.
//space complexity is O(n) as well to return answer.
```
	
	
	
	
	
	
	
	
	
	
	
	
<br /> <br /> <br />**[814. Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/)**<br />
Given the `root` of a binary tree, return the same tree where every subtree (of the given tree) not containing a `1` has been removed.<br />
A subtree of a node `node` is `node` plus every node that is a descendant of `node`.<br />
	
Example 1:
<pre>
<img src = "https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png">
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
</pre>
Example 2:
<pre>
<img src = "https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png">
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
</pre>
Example 3:
<pre>
<img src = "https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png">
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
</pre>
	
* Constraints: The number of nodes in the tree is in the range `[1, 200]`.<br />
`Node.val` is either `0` or `1`.<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root!=NULL){
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            if(!root->left && !root->right && root->val==0)
                return NULL;
        }
        return root;
    }
};
//Time Complexity: O(N), where N is the number of nodes in the Binary Tree.
//Space Complexity: O(H), where H is the height of the Binary Tree (Recursion stack space)
```
	
	
	
<br /> <br /> <br />**[606. Construct String from Binary Tree](https://leetcode.com/problems/construct-string-from-binary-tree/)**<br />
Given the `root` of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.<br />
Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.<br />
	
Example 1:
<pre>
<img src = "https://assets.leetcode.com/uploads/2021/05/03/cons1-tree.jpg">
Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)"
</pre>
Example 2:
<pre>
<img src = "https://assets.leetcode.com/uploads/2021/05/03/cons2-tree.jpg">
Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the 
one-to-one mapping relationship between the input and the output.
</pre>

* Constraints: The number of nodes in the tree is in the range `[1, 10^4]`.<br />
`-1000 <= Node.val <= 1000`<br />
	
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* root) {
		string ans = to_string(root->val);
		if (root->left) //left side check
			ans += "(" + tree2str(root->left) + ")";
		if (root->right) { //right side check
			if (!root->left) ans += "()"; //left side not present, but right side present
			ans += "(" + tree2str(root->right) + ")"; 
		}
		return ans;
	}
};
//Time Complexity: O(N), where N is the number of nodes in the Binary Tree.
//Space Complexity: O(H), where H is the height of the Binary Tree (Recursion stack space)
```

	
	
<br /> <br /> <br />**[273. Integer to English Words](https://leetcode.com/problems/integer-to-english-words/)**<br />
Convert a non-negative integer `num` to its English words representation.<br />
	
Example 1:
<pre>
Input: num = 123
Output: "One Hundred Twenty Three"
</pre>
Example 2:
<pre>
Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
</pre>
Example 3:
<pre>
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
</pre>

* Constraints: `0 <= num <= 2^31 - 1`<br />
	
```cpp
class Solution {
public:
    
    // 0 to 19
    string ones[20] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
    "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    
    // tens only
    string tens[10] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    
    /* Thousand - 1000
       Million  - 1000 000
       Billion  - 1000 000 000 
    */
    
    string helper(int num) 
    {
        if(num >=1000000000) 
        {
            return helper(num/1000000000) + " Billion" + helper(num%1000000000);
        } 
        else if(num >=1000000) 
        {
            return helper(num/1000000) + " Million" + helper(num%1000000);
        } 
        else if(num>=1000) 
        {
            return helper(num/1000) + " Thousand" + helper(num%1000);
        } 
        else if(num >=100) 
        {
            return helper(num/100) + " Hundred" + helper(num%100);
        } 
        else if(num >= 20) 
        {
            return " " + tens[num/10] + helper(num%10);
        } 
        else // 0 to 19...
            return (ones[num]!="") ?  " " + ones[num] : "";
        return "";
    }
    
    string numberToWords(int num) 
    {
        if(num == 0) return "Zero";
        
        string ans = helper(num);
        return ans.substr(1); // pass start index
    }  
};
```

	
	
	
	
	
	
	
	
<br /> <br /> <br />**[]()**<br />
