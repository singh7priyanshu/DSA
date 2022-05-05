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
