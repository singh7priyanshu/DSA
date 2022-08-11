# Love Babbar Sheet 450 - Trie
## Problem 1:
**[Construct a trie from scratch](https://www.geeksforgeeks.org/trie-insert-and-search/)**<br />
Trie is an efficient information retrieval data structure. Using Trie, search complexities can be brought to `optimal limit (key length)`. If we store keys in a `binary search tree`, a well balanced BST will need time proportional to `M * log N`, where `M` is the maximum string length and `N` is the number of keys in the tree. Using Trie, we can search the key in `O(M) time`. However, the penalty is on Trie storage requirements.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Trie.png"><br />
Every node of Trie consists of `multiple` branches. Each branch represents a possible character of keys. We need to mark the `last node of every key` as the **end of the word node**. A Trie node field `isEndOfWord` is used to distinguish the node as the end of the word node. A simple structure to represent nodes of the English alphabet can be as follows,<br />
```cpp
// Trie node 
struct TrieNode 
{ 
     struct TrieNode *children[ALPHABET_SIZE];
     // isEndOfWord is true if the node 
     // represents end of a word 
     bool isEndOfWord; 
}; 
```
`Inserting` a key into Trie is a simple approach. Every character of the input key is inserted as an `individual Trie node`. Note that the children is an array of pointers (or references) to next level trie nodes. The key character acts as an index to the array children. If the input key is **new** or **an extension of the existing key**, we need to construct non-existing nodes of the key, and mark the end of the word for the last node. If the input key is a **prefix** of the existing key in Trie, we simply mark the last node of the key as the end of a word. The **key length determines Trie depth**.<br />
`Searching` for a key is similar to an `insert` operation, however, we only compare the **characters and move down.** The search can terminate due to the end of a string or lack of key in the trie. In the former case, if the isEndofWord field of the last node is true, then the key exists in the trie. In the second case, the search terminates **without examining** all the characters of the key, since the key is not present in the trie.<br />
The following picture explains the construction of trie using keys given in the example below,<br />
<pre>
                       root
                    /   \    \
                    t   a     b
                    |   |     |
                    h   n     y
                    |   |  \  |
                    e   s  y  e
                 /  |   |
                 i  r   w
                 |  |   |
                 r  e   e
                        |
                        r
</pre>
In the picture, every character is of type `trie_node_t`. For example, the root is of type `trie_node_t`, and it’s children `a`, `b` and `t` are filled, all other nodes of root will be `NULL`. Similarly, `“a”` at the next level is having only one child `(“n”)`, all other children are `NULL`.<br />
`Insert` and `search` costs `O(key_length)`, however, the memory requirements of Trie is `O(ALPHABET_SIZE * key_length * N)` where `N` is the number of keys in Trie.<br />
There are efficient representations of trie nodes (e.g. **compressed trie**, **ternary search tree**, etc.) to minimize the memory requirements of the trie.<br />
```cpp
// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];

	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}
	return (pCrawl->isEndOfWord);
}

// Driver
int main()
{
	// Input keys (use only 'a' through 'z'
	// and lower case)
	string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct TrieNode *root = getNode();

	// Construct trie
	for (int i = 0; i < n; i++)
		insert(root, keys[i]);

	// Search for different keys
	search(root, "the")? cout << "Yes\n" : cout << "No\n";
	search(root, "these")? cout << "Yes\n" : cout << "No\n";
	search(root, "their")? cout << "Yes\n" : cout << "No\n";
	search(root, "thaw")? cout << "Yes\n" : cout << "No\n";
	return 0;
}
```
Output :<br />
<pre>
the --- Present in trie
these --- Not present in trie
their --- Present in trie
thaw --- Not present in trie
</pre>




<br /><br /><br />
## Problem 2:
**[Find shortest unique prefix for every word in a given list](https://www.geeksforgeeks.org/find-all-shortest-unique-prefixes-to-represent-each-word-in-a-given-list/)**<br />
Given an `array` of words, find _all shortest unique prefixes to represent each word in the given array_. Assume that no word is prefix of another.<br /> 
**Examples:**<br />
<pre>
Input: arr[] = {"zebra", "dog", "duck", "dove"}
Output: dog, dov, du, z
Explanation: dog => dog
             dove => dov 
             duck => du
             zebra => z

Input: arr[] =  {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
Output: geeksf, geeksg, geeksq}
</pre>
A **Simple Solution** is to consider every `prefix` of every word (starting from the **shortest to largest**), and if a **prefix is not prefix of any other string**, then print it.<br /> <br />
An **Efficient Solution** is to use `Trie`. The idea is to maintain a count in every node. Below are steps.<br />
1) Construct a Trie of all words. Also maintain frequency of every node (Here frequency is **number of times node is visited during insertion**). Time complexity of this step is `O(N)` where `N` is total number of characters in all words.<br /> 
2) Now, for every word, we find the character nearest to the root with frequency as `1`. The prefix of the word is path from root to this character. To do this, we can traverse Trie starting from root. For every node being traversed, we check its frequency. If frequency is one, we _print all characters from root to this node and don’t traverse down this node_.<br />
Time complexity if this step also is `O(N)` where `N` is total number of characters in all words.<br />
<pre>
               root
                / \
         (d, 3)/   \(z, 1)
              /     \
          Node1     Node2
           / \          \
     (o,2)/   \(u,1)     \(e,1)
         /     \          \
   Node1.1    Node1.2     Node2.1
      /  \         \            \
(g,1)/    \ (t,1)   \(c,1)       \(b,1)
    /      \         \            \ 
   Leaf   Leaf       Node1.2.1     Node2.1.1
   (dog)  (dot)        \               \
                         \(k, 1)          \(r, 1)
                          \                \   
                          Leaf           Node2.1.1.1
                          (duck)              \
                                                \(a,1)
                                                 \
                                                 Leaf
                                                 (zebra)
</pre>
Below is the implementation of above idea.<br />
```cpp
// C++ program to print all prefixes that
// uniquely represent words.
#include<bits/stdc++.h>
using namespace std;

#define MAX 256

// Maximum length of an input word
#define MAX_WORD_LEN 500

// Trie Node.
struct trieNode
{
	struct trieNode *child[MAX];
	int freq; // To store frequency
};

// Function to create a new trie node.
struct trieNode *newTrieNode(void)
{
	struct trieNode *newNode = new trieNode;
	newNode->freq = 1;
	for (int i = 0; i<MAX; i++)
		newNode->child[i] = NULL;
	return newNode;
}

// Method to insert a new string into Trie
void insert(struct trieNode *root, string str)
{
	// Length of the URL
	int len = str.length();
	struct trieNode *pCrawl = root;

	// Traversing over the length of given str.
	for (int level = 0; level<len; level++)
	{
		// Get index of child node from current character
		// in str.
		int index = str[level];

		// Create a new child if not exist already
		if (!pCrawl->child[index])
			pCrawl->child[index] = newTrieNode();
		else
		(pCrawl->child[index]->freq)++;

		// Move to the child
		pCrawl = pCrawl->child[index];
	}
}

// This function prints unique prefix for every word stored
// in Trie. Prefixes one by one are stored in prefix[].
// 'ind' is current index of prefix[]
void findPrefixesUtil(struct trieNode *root, char prefix[], int ind)
{
	// Corner case
	if (root == NULL)
	return;

	// Base case
	if (root->freq == 1)
	{
	prefix[ind] = '\0';
	cout << prefix << " ";
	return;
	}

	for (int i=0; i<MAX; i++)
	{
	if (root->child[i] != NULL)
	{
		prefix[ind] = i;
		findPrefixesUtil(root->child[i], prefix, ind+1);
	}
	}
}

// Function to print all prefixes that uniquely
// represent all words in arr[0..n-1]
void findPrefixes(string arr[], int n)
{
	// Construct a Trie of all words
	struct trieNode *root = newTrieNode();
	root->freq = 0;
	for (int i = 0; i<n; i++)
		insert(root, arr[i]);

	// Create an array to store all prefixes
	char prefix[MAX_WORD_LEN];

	// Print all prefixes using Trie Traversal
	findPrefixesUtil(root, prefix, 0);
}

// Driver function.
int main()
{
	string arr[] = {"zebra", "dog", "duck", "dove"};
	int n = sizeof(arr)/sizeof(arr[0]);
	findPrefixes(arr, n);

	return 0;
}
```
Output: <br />
<pre>
dog dov du z
</pre>
<pre>
Time Complexity: O(n)
Space Complexity: O(n)
</pre>



<br /><br /><br />
## Problem 3:
**[Word Break Problem | (Trie solution)](https://www.geeksforgeeks.org/word-break-problem-trie-solution/)**<br />
Given an input `string` and a `dictionary of words`, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details. <br />
This is a famous Google interview question, also being asked by many other companies now a days.<br />
<pre>
Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes 
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or 
"i like sam sung".
</pre>
**Implementation:**<br />
```cpp
// A DP and Trie based program to test whether
// a given string can be segmented into
// space separated words in dictionary
#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];

	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode* getNode(void)
{
	struct TrieNode* pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode* root, string key)
{
	struct TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode* root, string key)
{
	struct TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// returns true if string can be segmented into
// space separated words, otherwise returns false
bool wordBreak(string str, TrieNode* root)
{
	int size = str.size();

	// Base case
	if (size == 0)
		return true;

	// Try all prefixes of lengths from 1 to size
	for (int i = 1; i <= size; i++) {
		// The parameter for search is str.substr(0, i)
		// str.substr(0, i) which is prefix (of input
		// string) of length 'i'. We first check whether
		// current prefix is in dictionary. Then we
		// recursively check for remaining string
		// str.substr(i, size-i) which is suffix of
		// length size-i
		if (search(root, str.substr(0, i))
			&& wordBreak(str.substr(i, size - i), root))
			return true;
	}

	// If we have tried all prefixes and none
	// of them worked
	return false;
}

// Driver program to test above functions
int main()
{
	string dictionary[] = { "mobile", "samsung", "sam", "sung", "man",
			        "mango", "icecream", "and", "go", "i",
			        "like", "ice", "cream" };
	int n = sizeof(dictionary) / sizeof(dictionary[0]);
	struct TrieNode* root = getNode();

	// Construct trie
	for (int i = 0; i < n; i++)
		insert(root, dictionary[i]);

	wordBreak("ilikesamsung", root) ? cout << "Yes\n" : cout << "No\n";
	wordBreak("iiiiiiii", root) ? cout << "Yes\n" : cout << "No\n";
	wordBreak("", root) ? cout << "Yes\n" : cout << "No\n";
	wordBreak("ilikelikeimangoiii", root) ? cout << "Yes\n" : cout << "No\n";
	wordBreak("samsungandmango", root) ? cout << "Yes\n" : cout << "No\n";
	wordBreak("samsungandmangok", root) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}
```
Output<br />
<pre>
Yes
Yes
Yes
Yes
Yes
No
</pre>



<br /><br /><br />
## Problem 4:
**[Given a sequence of words, print all anagrams together](https://practice.geeksforgeeks.org/problems/print-anagrams-together/1)**<br />
Given an `array of strings`, return _all groups of strings that are anagrams_. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.<br />
**Note:** The final output will be in **lexicographic order**.<br />

>Example 1:<br />
Input:<br />
N = 5<br />
words[] = {act,god,cat,dog,tac}<br />
Output:<br />
act cat tac <br />
god dog<br />
Explanation:<br />
There are 2 groups of anagrams "god", "dog" make group 1.<br />
"act", "cat", "tac" make group 2.<br />

>Example 2:<br />
Input:<br />
N = 3<br />
words[] = {no,on,is}<br />
Output: <br />
no on<br />
is<br />
Explanation:<br />
There are 2 groups of anagrams "no", "on" make group 1.<br />
"is" makes group 2. <br />

**Your Task:**<br />
The task is to complete the function `Anagrams()` that takes a `list of strings` as input and returns _a list of groups such that each group consists of all the strings that are anagrams_.<br />

<pre>
Expected Time Complexity: O(N*|S|*log|S|), where |S| is the length of the strings.
Expected Auxiliary Space: O(N*|S|), where |S| is the length of the strings.
</pre>

* Constraints: `1<=N<=100`<br />
`1<=|S|<=10`<br />

```cpp
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>> result;
        //hashmap to contains groups of anagrams
        unordered_map<string, vector<string>>umap;
        for(int i = 0;i<string_list.size();i++){
            string s = string_list[i];
            // sort each string
            sort(s.begin(), s.end());
            //add original string to corresponding sorted string in hash map
            umap[s].push_back(string_list[i]);
        }
        for(auto itr = umap.begin();itr != umap.end(); itr++)result.push_back(itr->second);
        return result;
    }
};  

int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<string>string_list;
    for(int i = 0;i<n;i++)cin>>string_list[i];
    Solution ob;
    vector<vector<string>>result = ob.Anagrams(string_list);
    sort(result.begin(), result.end());
    for(int i = 0;i<result.size();i++){
      for(int j = 0;j<result[i].size();j++){
        cout<<result[i][j]<<" ";
      }
      cout<<endl;
    }
  }
}
```





<br /><br /><br />
## Problem 5:
**[]()**<br />

<br /><br /><br />
## Problem 6:
**[]()**<br />
