## Problem 18:
**[Naive algorithm for Pattern Searching](https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/)**<br />
Given a text `txt[0..n-1]` and a pattern `pat[0..m-1]`, write a function `search(char pat[], char txt[])` that prints all occurrences of `pat[]` in `txt[]`. You may assume that `n > m`.<br />

>Examples:<br />
<pre>
Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
</pre>
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Pattern-Searching-2-1.png"><br /><br />
Pattern searching is an important problem in computer science. When we do search for a string in notepad/word file or browser or database, pattern searching algorithms are used to show the search results. <br />
**Naive Pattern Searching:**<br />
Slide the pattern over text one by one and check for a match. If a match is found, then slide by 1 again to check for subsequent matches.<br />
```cpp
// C++ program for Naive Pattern
// Searching algorithm
#include <bits/stdc++.h>
using namespace std;

void search(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	/* A loop to slide pat[] one by one */
	for (int i = 0; i <= N - M; i++) {
		int j;

		/* For current index i, check for pattern match */
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;

		if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
			cout << "Pattern found at index "
				<< i << endl;
	}
}

// Driver Code
int main()
{
	char txt[] = "AABAACAADAABAAABAA";
	char pat[] = "AABA";
	search(pat, txt);
	return 0;
}
```
Output<br />
<pre>
Pattern found at index 0 
Pattern found at index 9 
Pattern found at index 13 
</pre>
**What is the best case?**<br />
The best case occurs when the first character of the pattern is not present in the text at all.<br />
```c
txt[] = "AABCCAADDEE";
pat[] = "FAA";
```
The number of comparisons in the best case is O(n).<br /><br />
**What is the worst case?**<br />
The worst case of Naive Pattern Searching occurs in the following scenarios.<br />
 1) When all characters of the text and pattern are the same.<br />
```c
txt[] = "AAAAAAAAAAAAAAAAAA";
pat[] = "AAAAA";
```
 2) Worst case also occurs when only the last character is different.<br />
 ```c
 txt[] = "AAAAAAAAAAAAAAAAAB";
 pat[] = "AAAAB";
```
The number of comparisons in the worst case is `O(m*(n-m+1))`. Although strings which have repeated characters are not likely to appear in English text, they may well occur in other applications (for example, in binary texts). The KMP matching algorithm improves the worst case to `O(n)`.<br />
