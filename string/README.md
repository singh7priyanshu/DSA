# Love Babbar Sheet 450 - Strings
## Problem 1:
**[344. Reverse String](https://leetcode.com/problems/reverse-string/)**<br />
Write a function that reverses a string. The input string is given as an array of characters `s`.<br /> 
You must do this by modifying the input array `in-place` with `O(1)` extra memory.<br />

>Example 1:<br />
Input: s = ["h","e","l","l","o"]<br />
Output: ["o","l","l","e","h"]<br />       
 
>Example 2:<br />
Input: s = ["H","a","n","n","a","h"]<br />
Output: ["h","a","n","n","a","H"]<br />  
 
* Constraints: `1 <= s.length <= 10^5`<br />
s[i] is a `printable ascii character`.<br />  
 
```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=(s.size())-1;
        for(int k=0;k<s.size()/2;k++){
            swap(s[i],s[j]);
            i++;j--;
        }
    }
};
```






<br /><br /><br />
## Problem 2:
**[Check whether a String is Palindrome or not](https://practice.geeksforgeeks.org/problems/palindrome-string0817/1)**<br />
Given a string `S`, check if it is palindrome or not.<br />

>Example 1:<br />
Input: S = "abba"<br />
Output: 1<br />
Explanation: S is a palindrome<br />

>Example 2:<br />
Input: S = "abc" <br />
Output: 0<br />
Explanation: S is not a palindrome<br />
 
**Your Task**:<br />
You don't need to read input or print anything. Complete the function `isPalindrome()` which accepts string `S` and returns an integer value `1` or `0`.<br />

<pre>
Expected Time Complexity: O(Length of S)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 <= Length of S<= 10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:     
    int isPalindrome(string S){
    for(int i=0;i<S.size()/2;i++){
            if(S[i]!= S[S.size()-i-1])return 0;
        }
        return 1;
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
        cout<<ob.isPalindrome(s)<<endl;
    }
    return 0;
}
```


<br /><br /><br />
## Problem 3:
**[Find Duplicate characters in a string](https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/)**<br />
Write an efficient program to print all the duplicates and their counts in the input string. <br />
`Method 1`: **Using hashing**<br />
Algorithm: Let input string be “geeksforgeeks” <br />
<pre>
Construct character count array from the input string.
count[‘e’] = 4 
count[‘g’] = 2
count[‘k’] = 2
……
Print all the indexes from the constructed array which have values greater than 1.
</pre>
Implementation:<br />
```cpp
// C++ program to count all duplicates
// from string using hashing
#include <iostream>
using namespace std;
# define NO_OF_CHARS 256

class gfg
{
	public :
	
	/* Fills count array with
	frequency of characters */
	void fillCharCounts(char *str, int *count)
	{
		int i;
		for (i = 0; *(str + i); i++)
		count[*(str + i)]++;
	}

	/* Print duplicates present
	in the passed string */
	void printDups(char *str)
	{
		
		// Create an array of size 256 and fill
		// count of every character in it
		int *count = (int *)calloc(NO_OF_CHARS, sizeof(int));
		fillCharCounts(str, count);

		// Print characters having count more than 0
		int i;
		for (i = 0; i < NO_OF_CHARS; i++)
		if(count[i] > 1)
			printf("%c, count = %d \n", i, count[i]);

		free(count);
	}
};

/* Driver code*/
int main()
{
	gfg g ;
	char str[] = "test string";
	g.printDups(str);
	//getchar();
	return 0;
}
```

**Output**<br />
<pre>
s, count = 2 
t, count = 3
</pre>
<pre>
Time Complexity: O(n), where n = length of the string passed
Space Complexity: O(NO_OF_CHARS)
</pre>
**Note**: Hashing involves the use of an array of fixed size each time no matter whatever the string is. <br />
For example, str = “aaaaaaaaaa”. <br />
An array of size `256` is used for str, only `1` block out of total size `(256)` will be utilized to store the number of occurrences of `‘a’` in str (i.e count[‘a’] = 10). <br />
Rest 256 – 1 = `255` blocks remain unused.<br /> 
Thus, Space Complexity is potentially high for such cases. So, to avoid any discrepancies and to improve Space Complexity, maps are generally preferred over long-sized arrays.<br />

`Method 2`: **Using Maps**<br />
`Approach`: The approach is the same as discussed in Method 1, but, using a map to store the count.<br />
**Implementation**:<br />
```cpp
// C++ program to count all duplicates
// from string using maps
#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
	map<char, int> count;
	for (int i = 0; i < str.length(); i++) {
		count[str[i]]++;
	}

	for (auto it : count) {
		if (it.second > 1)
			cout << it.first << ", count = " << it.second
				<< "\n";
	}
}
/* Driver code*/
int main()
{
	string str = "test string";
	printDups(str);
	return 0;
}
```
Output<br />
<pre>
s, count = 2
t, count = 3
</pre>
<pre>
Time Complexity: O(N*log(N)), where N = length of the string passed and 
 it generally takes O(log(N)) time for an element insertion in a map. 
Space Complexity: O(K), where K = size of the map (0<=K<=input_string_length).
</pre>
**Implementation**:<br />
```cpp
// C++ program to count all duplicates
// from string using maps
#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
	unordered_map<char, int> count;
	for (int i = 0; i < str.length(); i++) {
		count[str[i]]++; //increase the count of characters by 1
	}

	for (auto it : count) { //iterating through the unordered map
		if (it.second > 1) //if the count of characters is greater then 1 then duplicate found
			cout << it.first << ", count = " << it.second
				<< "\n";
	}
}
/* Driver code*/
int main()
{
	string str = "test string";
	printDups(str);
	return 0;
}
```
Output<br />
<pre>
s, count = 2
t, count = 3
</pre>
<pre>
Time Complexity: O(N), where N = length of the string passed and 
 it takes O(1) time to insert and access any element in an unordered map
Auxiliary Space: O(K), where K = size of the map (0<=K<=input_string_length).
</pre>





















<br /><br /><br />
## Problem 4:
**[Why strings are immutable in Java?](https://www.javatpoint.com/why-string-is-immutable-or-final-in-java#:~:text=The%20String%20is%20immutable%20in,it%20makes%20the%20String%20immutable.)**<br />
The String is immutable in Java because of the `security`, `synchronization` and `concurrency`, `caching`, and `class loading`.<br />
The reason of making string final is to destroy the `immutability` and to not allow others to extend it. <br />
The String objects are cached in the `String pool`, and it makes the String **immutable**.<br />













<br /><br /><br />
## Problem 5:
**[Write a Code to check whether one string is a rotation of another](https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/)**<br />
Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1? <br />
(eg given `s1` = `ABCD` and `s2` = `CDAB`, return `true`, given `s1` = `ABCD`, and `s2` = `ACBD` , return `false`)<br />
`Algorithm`: **areRotations(str1, str2)**<br />
<pre>
1. Create a temp string and store concatenation of str1 to
   str1 in temp.
                      temp = str1.str1
2. If str2 is a substring of temp then str1 and str2 are 
   rotations of each other.

Example:                 
                 str1 = "ABACD"
                 str2 = "CDABA"

 temp = str1.str1 = "ABACDABACD"
 Since str2 is a substring of temp, str1 and str2 are 
 rotations of each other.
 </pre>
**Implementation**:<br />
```cpp
// C++ program to check if two given strings
// are rotations of each other
# include <bits/stdc++.h>
using namespace std;

/* Function checks if passed strings (str1
and str2) are rotations of each other */
bool areRotations(string str1, string str2)
{
/* Check if sizes of two strings are same */
if (str1.length() != str2.length())
		return false;

string temp = str1 + str1;
return (temp.find(str2) != string::npos);
}

/* Driver program to test areRotations */
int main()
{
string str1 = "AACD", str2 = "ACDA";
if (areRotations(str1, str2))
	printf("Strings are rotations of each other");
else
	printf("Strings are not rotations of each other");
return 0;
}
```
```c
// C program to check if two given strings are rotations of
// each other
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/* Function checks if passed strings (str1 and str2)
are rotations of each other */
int areRotations(char *str1, char *str2)
{
int size1 = strlen(str1);
int size2 = strlen(str2);
char *temp;
void *ptr;

/* Check if sizes of two strings are same */
if (size1 != size2)
	return 0;

/* Create a temp string with value str1.str1 */
temp = (char *)malloc(sizeof(char)*(size1*2 + 1));
temp[0] = '';
strcat(temp, str1);
strcat(temp, str1);

/* Now check if str2 is a substring of temp */
ptr = strstr(temp, str2);

free(temp); // Free dynamically allocated memory

/* strstr returns NULL if the second string is NOT a
	substring of first string */
if (ptr != NULL)
	return 1;
else
	return 0;
}

/* Driver program to test areRotations */
int main()
{
	char *str1 = "AACD";
	char *str2 = "ACDA";

	if (areRotations(str1, str2))
	printf("Strings are rotations of each other");
	else
	printf("Strings are not rotations of each other");

	getchar();
	return 0;
}
```
Output<br />
<pre>
Strings are rotations of each other
</pre>
<pre>
Time Complexity will be O(n*n), where n is the length of the string.
Auxiliary Space: O(n)
</pre>
`Method 2`**(Using STL)**:<br />
**Algorithm **:<br />
<pre>
1. If the size of both the strings is not equal, then it can never be possible.
2. Push the original string into a queue q1.
3. Push the string to be checked inside another queue q2.
4. Keep popping q2‘s and pushing it back into it till the number of such operations are less than the size of the string.
5. If q2 becomes equal to q1 at any point during these operations, it is possible. Else not.
</pre>
**Implementation:**<br />
```cpp
#include <bits/stdc++.h>
using namespace std;
bool check_rotation(string s, string goal)
{
	if (s.size() != goal.size())
		return false;
	queue<char> q1;
	for (int i = 0; i < s.size(); i++) {
		q1.push(s[i]);
	}
	queue<char> q2;
	for (int i = 0; i < goal.size(); i++) {
		q2.push(goal[i]);
	}
	int k = goal.size();
	while (k--) {
		char ch = q2.front();
		q2.pop();
		q2.push(ch);
		if (q2 == q1)
			return true;
	}
	return false;
}
int main()
{
	string s1 = "ABCD";
	string s2 = "CDAB";
	if (check_rotation(s1, s2))
		cout << s2 << " is a rotated form of " << s1
			<< endl;
	else
		cout << s2 << " is not a rotated form of " << s1
			<< endl;
	string s3 = "ACBD";
	if (check_rotation(s1, s3))
		cout << s3 << " is a rotated form of " << s1
			<< endl;
	else
		cout << s3 << " is not a rotated form of " << s1
			<< endl;
	return 0;
}
```
Output<br />
<pre>
CDAB is a rotated form of ABCD
ACBD is not a rotated form of ABCD
</pre>
<pre>
Time Complexity will be O(n1 + n2) , where n is the length of the strings.
Auxiliary Space: O(n)
</pre>
**Time Complexity:** Time complexity of this problem depends on the implementation of strstr function. <br />
If the implementation of strstr is done using `KMP matcher` then complexity of the above program is `O(n1 + n2)` where `n1` and `n2` are lengths of strings. `KMP matcher` takes `O(n)` time to find a substring in a string of length `n` where length of substring is assumed to be smaller than the string.<br />
`Method 3:`<br />
**Algorithm:**<br />
<pre>
1. Find all the positions of first character of original string in the string to be checked.
2. For every position found, consider it to be the starting index of the string to be checked.
3. Beginning from the new starting index, compare both strings and check whether they are equal or not.
4. (Suppose original string to be s1,string to be checked be s2,n is length of strings 
    and j is the position of first character of s1 in s2, then for i < (length of original 
    string) ,check if s1[i]==s2[(j+1)%n). Return false if any character mismatch is 
    found, else return true.
5. Repeat 3rd step for all positions found.
</pre>
**Implementation:**<br />
```cpp
#include <iostream>
#include <vector>
using namespace std;

bool checkString(string &s1, string &s2, int indexFound, int Size)
{
	for(int i=0;i<Size;i++){
	//check whether the character is equal or not
		if(s1[i]!=s2[(indexFound+i)%Size])return false;
	// %Size keeps (indexFound+i) in bounds, since it
	// ensures its value is always less than Size
	}

	return true;
}

int main() {
	
string s1="abcd";
string s2="cdab";

if(s1.length()!=s2.length()){
	cout<<"s2 is not a rotation on s1"<<endl;
}
else{
	// store occurrences of the first character of s1
	vector<int> indexes;
	
	int Size = s1.length();
	char firstChar = s1[0];
	
	for(int i=0;i<Size;i++){
		if(s2[i]==firstChar)indexes.push_back(i);
	}
	

	bool isRotation=false;

	// check if the strings are rotation of each other for
	// every occurence of firstChar in s2
	for(int idx: indexes){
		isRotation = checkString( s1, s2, idx, Size);
		if(isRotation)break;
	}

	if(isRotation)cout<<"s2 is rotation of s1"<<endl;
	else cout<<"s2 is not a rotation of s1"<<endl;
	}
	return 0;
}
```
Output
<pre>
s2 is rotation of s1
</pre>
<pre>		
Time Complexity will be O(n*n) in the worst case, where n is the length of the string.
Auxiliary Space: O(1)
</pre>







<br /><br /><br />
## Problem 6:
**[Java Program to Check if a string is a valid shuffle of two distinct strings](https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings)**<br />
check if a string is the valid shuffle of two other strings in Java.<br />
```java
import java.util.Arrays;

class Test {


  // length of result string should be equal to sum of two strings
  static boolean checkLength(String first, String second, String result) {
    if (first.length() + second.length() != result.length()) {
      return false;
    }
    else {
      return true;
    }
  }

  // this method converts the string to char array 
  // sorts the char array
  // convert the char array to string and return it
  static String sortString(String str) {
  
    char[] charArray = str.toCharArray();
    Arrays.sort(charArray);

    // convert char array back to string
    str = String.valueOf(charArray);

    return str;
  }

  // this method compares each character of the result with 
  // individual characters of the first and second string
  static boolean shuffleCheck(String first, String second, String result) {
    
    // sort each string to make comparison easier
    first = sortString(first);
    second = sortString(second);
    result = sortString(result);

    // variables to track each character of 3 strings
    int i = 0, j = 0, k = 0;

    // iterate through all characters of result
    while (k != result.length()) {

      // check if first character of result matches
      // with first character of first string
      if (i < first.length() && first.charAt(i) == result.charAt(k))
        i++;

      // check if first character of result matches
      // with the first character of second string
      else if (j < second.length() && second.charAt(j) == result.charAt(k))
        j++;

      // if the character doesn't match
      else {
        return false;
      }

      // access next character of result
      k++;
    }

    // after accessing all characters of result
    // if either first or second has some characters left
    if(i < first.length() || j < second.length()) {
      return false;
    }

    return true;
  }

  public static void main(String[] args) {

    String first = "XY";
    String second = "12";
    String[] results = {"1XY2", "Y1X2", "Y21XX"};

    // call the method to check if result string is
    // shuffle of the string first and second
    for (String result : results) {
      if (checkLength(first, second, result) == true && shuffleCheck(first, second, result) == true) {
        System.out.println(result + " is a valid shuffle of " + first + " and " + second);
      }
      else {
        System.out.println(result + " is not a valid shuffle of " + first + " and " + second);
      }
    }
  }
}
```
Output<br />
<pre>
1XY2 is a valid shuffle of XY and 12
Y1X2 is a valid shuffle of XY and 12     
Y21XX is not a valid shuffle of XY and 12
</pre>
In the above example, we have a string array named `results`. It contains three strings: `1XY2`, `Y1X2`, and `Y21XX`. We are checking if these three strings are valid shuffle of strings `first(XY)` and `second(12)`.<br /><br />
Here, we have used 3 methods:<br /><br />
**1. checkLength()** - The number of characters in a shuffled string should be equal to the sum of the character in two strings.<br />
So, this method checks if the length of the shuffled string is same as the sum of the length of the `first` and `second` strings.<br />
If the length is not equal, there is no need to call the `shuffleCheck()` method. Hence, we have used the if statement as<br />
<pre>
// inside main method
if (checkLength(first, second, result) == true && shuffleCheck(first, second, result) == true)
</pre>
**2. sortString()** - This method converts the string to `char` Array and then uses the `Arrays.sort()` method to sort the array. Finally, returns the sorted string.<br />
Since we are comparing the shuffled string with the other two strings, sorting all three strings will make the comparison more efficient.<br />
**3. shuffleCheck()** - This method compares the individual characters of the shuffled string with the characters of `first` and `second` strings<br />



















<br /><br /><br />
## Problem 7:
**[38. Count and Say](https://leetcode.com/problems/count-and-say/)**<br />
The **count-and-say** sequence is a sequence of digit strings defined by the recursive formula:<br />

 * `countAndSay(1) = "1"`<br />
 * `countAndSay(n)` is the way you would "say" the digit string from `countAndSay(n-1)`, which is then converted into a different digit string.<br />
 
To determine how you "say" a digit string, split it into the **minimal** number of substrings such that each substring contains exactly **one** unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.<br /><br />
For example, the saying and conversion for digit string `"3322251"`:<br />
<img src = "https://assets.leetcode.com/uploads/2020/10/23/countandsay.jpg"><br />
Given a positive integer `n`, return _the `nth` term of the **count-and-say** sequence_.<br /><br />

>Example 1:<br />
Input: n = 1<br />
Output: "1"<br />
Explanation: This is the base case.<br />

>Example 2:<br />
Input: n = 4<br />
Output: "1211"<br />
Explanation:<br />
countAndSay(1) = "1"<br />
countAndSay(2) = say "1" = one 1 = "11"<br />
countAndSay(3) = say "11" = two 1's = "21"<br />
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"<br />
 
* Constraints: `1 <= n <= 30`<br />

```cpp
class Solution {
public:
    string countAndSay(int n) {
        vector<string>v(31);
        v[0]="0";
        v[1]="1";
        for(int i=2;i<=30;i++){
            int x=i;
            string temp = v[i-1],result = "";
            int j=0;
            while(j<temp.length()){
                int count = 1;
                while(j+1<temp.length() && temp[j] == temp[j+1]){
                    count++;
                    j++;
                }
                result+=to_string(count)+temp[j];
                j++;
            }
            v[i] = result;
        }
        return v[n];
    }
};
```















<br /><br /><br />
## Problem 8:
**[Longest Palindrome in a String](https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1)**<br />
Given a string `S`, find the longest palindromic substring in `S`. **Substring of string S:** `S[ i . . . . j ]` where `0 ≤ i ≤ j < len(S)`. **Palindrome string:** A string which reads the same backwards. More formally, `S` is palindrome if `reverse(S) = S`. Incase of conflict, return the substring which occurs first ( with the least starting index).<br />

>Example 1:<br />
Input:<br />
S = "aaaabbaa"<br />
Output: aabbaa<br />
Explanation: The longest Palindromic substring is "aabbaa".<br />

>Example 2:<br />
Input: <br />
S = "abc"<br />
Output: a<br />
Explanation: "a", "b" and "c" are the longest palindromes with same length.<br />
The result is the one with the least starting index.<br />

**Your Task**:<br />
You dont need to read input or print anything. Your task is to complete the function **longestPalin()** which takes the string `S` as input and returns the longest palindromic substring of `S`.<br />
<pre>
Expected Time Complexity: O(|S|^2).
Expected Auxiliary Space: O(1).
</pre>	
* Constraints: `1 ≤ |S| ≤ 10^3`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestPalin (string S) {
        int i = 0, l, h = 0;
        for(int i = 0;i<S.size();i++){
            int length1 = helper(S, i, i);
            int length2 = helper(S, i, i+1);
            int length = max(length1, length2);
            if(h-l < length-1){
                l = i-(length-1)/2;
                h = i+(length)/2;
            }
        }
        return S.substr(l, h-l+1);
    }
    
    int helper(string s, int l, int h){
        while(l>=0 && h<s.size() && s[l]==s[h]){
            l--;
            h++;
        }
        return h-l-1;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        string S; cin>>S;
        Solution ob;
        cout<<ob.longestPalin(S)<<endl;
    }
}
```

















<br /><br /><br />
## Problem 9:
**[Find Longest Recurring Subsequence in String / Longest Repeating Subsequence](https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1)**<br />
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
## Problem 10:
**[Print all subsequences of a string](https://www.geeksforgeeks.org/print-subsequences-string/)**<br />
Given a string, we have to find out all subsequences of it. A String is a subsequence of a given String, that is generated by deleting some character of a given string without changing its order.<br />
**Examples: **<br />
<pre>
Input : abc
Output : a, b, c, ab, bc, ac, abc

Input : aaa
Output : a, aa, aaa
</pre>
`Method 1 (Pick and Don’t Pick Concept) :`<br />
**Implementation:**<br />
```cpp
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Find all subsequences
void printSubsequence(string input, string output)
{
	// Base Case
	// if the input is empty print the output string
	if (input.empty()) {
		cout << output << endl;
		return;
	}

	// output is passed with including
	// the Ist character of
	// Input string
	printSubsequence(input.substr(1), output + input[0]);

	// output is passed without
	// including the Ist character
	// of Input string
	printSubsequence(input.substr(1), output);
}

// Driver code
int main()
{
	// output is set to null before passing in as a
	// parameter
	string output = "";
	string input = "abcd";

	printSubsequence(input, output);

	return 0;
}
```
Output<br />
<pre>
abcd
abc
abd
ab
acd
ac
ad
a
bcd
bc
bd
b
cd
c
d
</pre>
`Method 2 `<br />
**Explanation :**<br />
<pre>
Step 1: Iterate over the entire String
Step 2: Iterate from the end of string 
        in order to generate different substring
        add the substring to the list
Step 3: Drop kth character from the substring obtained 
        from above to generate different subsequence.
Step 4: if the subsequence is not in the list then recur.
</pre>
Below is the implementation of the approach. <br />
```cpp
// CPP program to print all subsequence of a
// given string.
#include <bits/stdc++.h>
using namespace std;

// set to store all the subsequences
unordered_set<string> st;

// Function computes all the subsequence of an string
void subsequence(string str)
{

	// Iterate over the entire string
	for (int i = 0; i < str.length(); i++) {

		// Iterate from the end of the string
		// to generate substrings
		for (int j = str.length(); j > i; j--) {
			string sub_str = str.substr(i, j);
			st.insert(sub_str);

			// Drop kth character in the substring
			// and if its not in the set then recur
			for (int k = 1; k < sub_str.length(); k++) {
				string sb = sub_str;

				// Drop character from the string
				sb.erase(sb.begin() + k);
				subsequence(sb);
			}
		}
	}
}

// Driver Code
int main()
{
	string s = "aabc";
	subsequence(s);
	for (auto i : st)
		cout << i << " ";
	cout << endl;

	return 0;
}
```
Output<br />
<pre>
aab aa aac bc b abc aabc ab ac a c 
</pre>
`Method 3:`<br />
One by one fix characters and recursively generates all subsets starting from them. After every recursive call, we remove last character so that the next permutation can be generated. <br />
**Implementation:**<br />
```cpp
// CPP program to generate power set in
// lexicographic order.
#include <bits/stdc++.h>
using namespace std;

// str : Stores input string
// n : Length of str.
// curr : Stores current permutation
// index : Index in current permutation, curr
void printSubSeqRec(string str, int n, int index = -1,
					string curr = "")
{
	// base case
	if (index == n)
		return;

	if (!curr.empty()) {
		cout << curr << "\n";
	}

	for (int i = index + 1; i < n; i++) {

		curr += str[i];
		printSubSeqRec(str, n, i, curr);

		// backtracking
		curr = curr.erase(curr.size() - 1);
	}
	return;
}

// Generates power set in lexicographic
// order.
void printSubSeq(string str)
{
	printSubSeqRec(str, str.size());
}

// Driver code
int main()
{
	string str = "cab";
	printSubSeq(str);
	return 0;
}
```
Output<br />
<pre>
c
ca
cab
cb
a
ab
b
</pre>
<pre>
Time Complexity: O(n * 2n), where n is the size of the given string
Auxiliary Space: O(1), as no extra space is used
</pre>













<br /><br /><br />
## Problem 11:
**[Permutations of a given string](https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1)**<br />
Given a string `S`. The task is to print all permutations of a given string in lexicographically sorted order.<br />

>Example 1:<br />
Input: ABC<br />
Output:<br />
ABC ACB BAC BCA CAB CBA<br />
Explanation:<br />
Given string ABC has permutations in 6 <br />
forms as ABC, ACB, BAC, BCA, CAB and CBA .<br />

>Example 2:<br />
Input: ABSG<br />
Output:<br />
ABGS ABSG AGBS AGSB ASBG ASGB BAGS <br />
BASG BGAS BGSA BSAG BSGA GABS GASB <br />
GBAS GBSA GSAB GSBA SABG SAGB SBAG<br /> 
SBGA SGAB SGBA<br />
Explanation:<br />
Given string ABSG has 24 permutations.<br />

**Your Task:**<br />  
You don't need to read input or print anything. Your task is to complete the function `find_permutaion()` which takes the string S as input parameter and returns a vector of string in lexicographical order.<br />

<pre>
Expected Time Complexity: O(n! * n)
Expected Space Complexity: O(n)
</pre>

* Constraints: `1 <= length of string <= 5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        vector<string>find_permutation(string S){
            vector<string>res;
            sort(S.begin(), S.end());
            do{
                res.push_back(S);
            }while(next_permutation(S.begin(), S.end()));
            return res;
        }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string str;
        cin >> str;
        Solution obj;
        vector<string>ans = obj.find_permutation(str);
        for(auto i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
} 
```
Here is a solution that is used as a basis in backtracking.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/NewPermutation.gif"><br />
```cpp
// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;


// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(string a, int l, int r)
{
	// Base case
	if (l == r)
		cout<<a<<endl;
	else
	{
		// Permutations made
		for (int i = l; i <= r; i++)
		{

			// Swapping done
			swap(a[l], a[i]);

			// Recursion called
			permute(a, l+1, r);

			//backtrack
			swap(a[l], a[i]);
		}
	}
}

// Driver Code
int main()
{
	string str = "ABC";
	int n = str.size();
	permute(str, 0, n-1);
	return 0;
}
```
```cpp
#include <bits/stdc++.h>
#include <string>
using namespace std;

void permute(string s , string answer)
{
	if(s.length() == 0)
	{
		cout<<answer<<" ";
		return;
	}
	for(int i=0 ; i<s.length() ; i++)
	{
		char ch = s[i];
		string left_substr = s.substr(0,i);
		string right_substr = s.substr(i+1);
		string rest = left_substr + right_substr;
		permute(rest , answer+ch);
	}

}

int main()
{
	string s;
	string answer="";

	cout<<"Enter the string : ";
	cin>>s;

	cout<<"\nAll possible strings are : ";
	permute(s , answer);
	return 0;
}
```








<br /><br /><br />
## Problem 12:
**[Split the Binary string into two substring with equal 0’s and 1’s](https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/)**<br />
Given a binary string `str` of length `N`, the task is to find the maximum count of consecutive substrings `str` can be divided into such that all the substrings are balanced i.e. they have equal number of `0s` and `1s`. If it is not possible to split str satisfying the conditions then print `-1`.<br />

>Example:<br />
<pre>
Input: str = “0100110101” 
Output: 4 
The required substrings are “01”, “0011”, “01” and “01”.
Input: str = “0111100010” 
Output: 3 

Input: str = “0000000000” 

Output: -1
</pre>
**Approach:**<br />
Initialize `count = 0` and traverse the string character by character and keep track of the number of `0s` and `1s` so far, whenever the count of `0s` and `1s` become equal increment the count. As in the given question, if it is not possible to split string then on that time count of 0s must not be equal to count of 1s then return -1 else print the value of count after the traversal of the complete string.<br />
Below is the implementation of the above approach:<br />
```cpp
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the count
// of maximum substrings str
// can be divided into
int maxSubStr(string str, int n)
{

	// To store the count of 0s and 1s
	int count0 = 0, count1 = 0;

	// To store the count of maximum
	// substrings str can be divided into
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '0') {
			count0++;
		}
		else {
			count1++;
		}
		if (count0 == count1) {
			cnt++;
		}
	}

	// It is not possible to
	// split the string
	if (count0!=count1) {
		return -1;
	}

	return cnt;
}

// Driver code
int main()
{
	string str = "0100110101";
	int n = str.length();

	cout << maxSubStr(str, n);

	return 0;
}
```
Output:<br />
<pre>
4
</pre>
<pre>
Time complexity: O(N) where N is the length of string 
Space Complexity: O(1)
</pre>











<br /><br /><br />
## Problem 13:
**[Word Wrap Problem [VERY IMP]](https://practice.geeksforgeeks.org/problems/word-wrap1646/1)**<br />
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





<br /><br /><br />
## Problem 14:
**[EDIT Distance [Very Imp]](https://practice.geeksforgeeks.org/problems/edit-distance3702/1)**<br />
Given two strings `s` and `t`. Return the minimum number of operations required to convert s to t.<br />
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
You don't need to read or print anything. Your task is to complete the function `editDistance()` which takes strings `s` and `t` as input parameters and returns the minimum number of operation to convert the string s to string t.<br /> 

<pre>
Expected Time Complexity: O(|s|*|t|)
Expected Space Complexity: O(|s|*|t|)
</pre>

* Constraints: `1 ≤ Length of both strings ≤ 100`<br />
`Both the strings are in lowercase.`<br />

```cpp
#include <bits/stdc++.h>
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

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
```

























<br /><br /><br />
## Problem 15:
**[Find next greater number with same set of digits. [Very Very IMP]](https://practice.geeksforgeeks.org/problems/next-permutation5226/1)**<br />
Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers `arr[ ]` of size `N`.<br />

>Example 1:<br />
Input: N = 6<br />
arr = {1, 2, 3, 6, 5, 4}<br />
Output: {1, 2, 4, 3, 5, 6}<br />
Explaination: The next permutation of the given array is {1, 2, 4, 3, 5, 6}.<br />

>Example 2:<br />
Input: N = 3<br />
arr = {3, 2, 1}<br />
Output: {1, 2, 3}<br />
Explaination: As arr[] is the last permutation. So, the next permutation is the lowest one.<br />

**Your Task:**<br />
You do not need to read input or print anything. Your task is to complete the function `nextPermutation()` which takes `N` and `arr[ ]` as input parameters and returns a list of numbers containing the next permutation.<br />

<pre>
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
</pre>

* Constraints: `1 ≤ N ≤ 10000`<br />

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int ind = 0;
        vector<int>v = arr;
        for(int i = N-2;i>=0;i--){
            if(v[i]<v[i+1]){
                ind = i;
                break;
            }
        }
        for(int i = N-1;i>ind;i--){
            if(v[i]>v[ind]){
                swap(v[i], v[ind]);
                ind++;
                break;
            }
        }
        for(int i = 0;i<(N-ind)/2;i++)swap(v[i+ind], v[N-i-1]);
        return v;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
} 
```










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
