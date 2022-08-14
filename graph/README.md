# Love Babbar Sheet 450 - Graph
## Problem 1:
**[Create a Graph, print it](https://onedrive.live.com/?authkey=%21AJrTq%5FU8BPKIWDk&id=842AECBB531CCEA4%211179&cid=842AECBB531CCEA4&parId=root&parQt=sharedby&parCid=5B675CE2DCD5977F&o=OneUp)**<br />
```cpp
#include"stdafx.h"
#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<set>
using namespace std;
template<typename T>
class graph {
public:
    map<T, list<pair<T,int> > > adjlist;

    void addEdge(T u, T v, int dist,bool bidirec = 1)
    {
         
        adjlist[u].push_back(make_pair(v, dist));
        
        if (bidirec)
            adjlist[v].push_back(make_pair(u, dist));
    }

    void print_adj()
    {
        for (auto n : adjlist)
        {
            cout << n.first<<" : ";
                for (auto a : n.second )
            {
                cout <<"( "<<a.first<<" , "<<a.second<<" ) " ;
            }
                cout << endl;
        }
    }

    void bfs(T u)
    {
        map< T, bool> visited;
        queue<T> q;
        q.push(u);
        while (!q.empty())
        {
            T front_element = q.front();
            q.pop();
            if (!visited[front_element]) {
                cout << front_element << " -> ";
                visited[front_element] = true;
            }
            for (auto a : (adjlist[front_element]))
            {
                if(!visited[a.first])
                q.push(a.first);
                
            }
        }
    }

    void dfs_helper(T src,map<T,bool> &visited)
    {
        visited[src] = true;
        cout << src << " -> ";

        for (auto a : adjlist[src])
        {
            if (!visited[a.first])
            {
                dfs_helper(a.first, visited);
            }
        }
    }   
 
    void dfs_utility(T src) //calling function of dfs helper
    {
        map < T, bool> visited;
        dfs_helper(src, visited);
    }

    void bfs_sssp(T src)
    {

        map<T, int> distance;
        map<T, T> parent;
        for (auto i : adjlist)
        {
            distance[i.first] = INT_MAX;
        }
        queue<T> q;
        q.push(src);
        distance[src] = 0;
        parent[src]=src;
        while (!q.empty())
        {
            T front_element = q.front();
            q.pop();

            for (auto neighbours : (adjlist[front_element]))
            {
                if (distance[neighbours.first] == INT_MAX)
                {
                    q.push(neighbours.first);
                    distance[neighbours.first] = distance[front_element] + 1;
                    parent[neighbours.first] = front_element;
                }
            }
        }

        for (auto i : adjlist)
        {
            cout << "distance to " << i.first << " from  " << src << " is " << distance[i.first] << endl;
        }

        //suppose u want to know the hortest path beeen 2 nodes.
        //let destion be == g
        T temp = 'g';
        while (parent[temp] != temp)
        {

            cout << temp << "<--";
            temp = parent[temp];
        }cout << src << endl;

    }


    void dijkstra(T src)
    {
        map<T, int> dist;
        for (auto i : adjlist)
        {
            dist[i.first] = INT_MAX;
        }
        set<pair<int, T> > s;
        s.insert(make_pair(0, src));
        dist[src] = 0;
        while (!s.empty())
        {
            auto p = *(s.begin());
            int nodedist = p.first;// sorce node ka distance
            T temp = p.second;
            s.erase(s.begin());

            for (auto neigh : adjlist[temp])
            {
                if (nodedist + neigh.second < dist[neigh.first])//neigh.second distance h adjlist me
                {

                    //purane wale ko delete karo and naye wale ko dalo
                    auto f = s.find(make_pair(dist[neigh.first], neigh.first));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }

                    dist[neigh.first] = nodedist + neigh.second;
                    s.insert(make_pair(dist[neigh.first], neigh.first));
                }
            }
        }
        for (auto d : dist) 
            cout << d.first << " and " << d.second << endl;
        
    }
};

int main()
{
    graph<char> g;
    g.addEdge('0', '1',4, 0);
    g.addEdge('0', '7',8, 0);
    g.addEdge('1', '7',11, 0);
    g.addEdge('1', '2',8, 0);
    g.addEdge('7', '8',7, 0);
    g.addEdge('2', '8',2, 0);
    g.addEdge('8', '6',6, 0);
    g.addEdge('2', '5',4, 0);
    g.addEdge('6', '5',2, 0);
    g.addEdge('2', '3',7, 0);
    g.addEdge('3', '3',14, 0);
    g.addEdge('3', '4',9, 0);
    g.addEdge('5', '4',10, 0);
    g.addEdge('7', '6',1, 0);
    g.print_adj();
    
    return 0;
}
```






<br /><br /><br />
## Problem 2:
**[Implement BFS algorithm](https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1)**<br />
Given a directed graph. The task is to do **Breadth First Traversal** of this graph starting from `0`.<br />
**Note:** One can move from node `u` to node `v` only if there's an edge from `u` to `v` and find the **BFS traversal** of the graph starting from the `0th` vertex, from **left to right** according to the graph. Also, you should only take nodes **directly** or **indirectly** connected from Node `0` in consideration.<br />

>Example 1:<br />
Input:<br />
<img src = "https://user-images.githubusercontent.com/71781982/184507578-4b7b960a-6bd5-48dd-a461-4895e0ceb29b.png"><br />
Input:<br />
<pre>
1
5
4
0 1 
0 2 
0 3 
2 4 
</pre>
Output: 0 1 2 3 4<br />
Explanation: <br />
0 is connected to 1 , 2 , 3. 2 is connected to 4.<br />
so starting from 0, it will go to 1 then 2 then 3.After this 2 to 4, thus bfs will be 0 1 2 3 4.<br />

>Example 2:<br />
Input:<br />
<img src = "https://user-images.githubusercontent.com/71781982/184507581-8bec4151-a6fb-47d7-9303-ba6757d0fab4.png"><br />
Output: 0 1 2<br />
Explanation:<br />
0 is connected to 1 , 2. so starting from 0, it will go to 1 then 2, thus bfs will be 0 1 2 3 4.<br /> 

**Your task:**<br />
You don’t need to read input or print anything. Your task is to complete the function `bfsOfGraph()` which takes the integer `V` denoting the number of vertices and `adjacency list` as input parameters and returns  _a list containing the BFS traversal of the graph starting from the 0th vertex from left to right_.<br />

<pre>
Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
</pre>

* Constraints: `1 ≤ V, E ≤ 10^4`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // boolean list to mark all the vertices as not visited.
        vector<bool> vis(V, false);
        int s = 0;

        // initially we mark first vertex as visited(true).
        vis[s] = true;

        vector<int> res;

        // creating a queue for BFS and pushing first vertex in queue.
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            // adding front element in output list and popping it from queue.
            int t = q.front();
            res.push_back(t);
            q.pop();

            // traversing over all the connected components of front element.
            for (int v : adj[t]) {
                // if they aren't visited, we mark them visited and add to
                // queue.
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        // returning the output list.
        return res;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int V, E;
        cin>>V>>E;
        vector<int>adj[V];
        for(int i = 0;i<E;i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        Solution ob;
        vector<int>ans = ob.bfsOfGraph(V, adj);
        for(int i = 0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
}
```








<br /><br /><br />
## Problem 3:
**[Depth First Search or DFS for a Graph](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)**<br />
`Depth First Traversal` (or Search) for a graph is similar to `Depth First Traversal` of a tree. The only catch here is, unlike trees, graphs may contain cycles (a node may be visited twice). To avoid processing a node more than once, use a boolean visited array.<br /> 
Example:<br />
<pre>
Input: n = 4, e = 6 
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3 
Output: DFS from vertex 1 : 1 2 0 3 
Explanation: 
DFS Diagram: 
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20200507074112/ezgif.com-gif-maker61.gif"><br />
Input: n = 4, e = 6 
2 -> 0, 0 -> 2, 1 -> 2, 0 -> 1, 3 -> 3, 1 -> 3 
Output: DFS from vertex 2 : 2 0 1 3 
Explanation: 
DFS Diagram: 
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20200507075041/ezgif.com-gif-maker7.gif"><br />
</pre>
<br />**Approach:**<br />
`Depth-first search` is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the `root node` (selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible along each branch before backtracking. So the basic idea is to start from the root or any arbitrary node and mark the node and move to the adjacent unmarked node and continue this loop until there is no unmarked adjacent node. Then `backtrack` and check for other unmarked nodes and traverse them. Finally, print the nodes in the path.<br />
<br />**Algorithm:**<br />
Create a `recursive function` that takes the index of the node and a visited array.<br />

 1. Mark the `current node` as visited and print the node.<br />
 2. Traverse all the `adjacent` and unmarked nodes and call the **recursive function** with the index of the adjacent node.<br />

**Implementation:**<br /> 
Below are implementations of simple `Depth First Traversal`. The C++ implementation uses an adjacency list representation of graphs. STL’s list container is used to store lists of adjacent nodes.<br />
```cpp
// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	// function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

// Driver code
int main()
{
	// Create a graph given in the above diagram
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal" " (starting from vertex 2) \n";
	g.DFS(2);

	return 0;
}
```
Output:<br /> 
<pre>
Following is Depth First Traversal (starting from vertex 2)
2 0 1 3
</pre>
<pre>
Complexity Analysis: 
Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V), since an extra visited array of size V is required.
</pre>
<br /> **Handling A Disconnected Graph:**<br />

 * **Solution:**<br /> 

This will happen by handling a corner case.<br /> 
The above code traverses only the vertices reachable from a given source vertex.<br /> 
All the vertices may not be reachable from a given vertex, as in a Disconnected graph.<br /> 
**To do a complete DFS traversal** of such graphs, run **DFS** from all unvisited nodes after a DFS.<br /> 
_The recursive function remains the same._<br />
 * **Algorithm:** <br />
    1. Create a recursive function that takes the index of the node and a visited array.<br />
    2. Mark the current node as visited and print the node.<br />
    3. Traverse all the adjacent and unmarked nodes and call the recursive function with the index of the adjacent node.<br />
    4. Run a loop from 0 to the number of vertices and check if the node is unvisited in the previous DFS, call the recursive function with the current node.<br />

**Implementation:**<br />
```cpp
// C++ program to print DFS
// traversal for a given
// graph
#include <bits/stdc++.h>
using namespace std;

class Graph {

	// A function used by DFS
	void DFSUtil(int v);

public:
	map<int, bool> visited;
	map<int, list<int> > adj;
	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints DFS traversal of the complete graph
	void DFS();
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v)
{
	// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i);
}

// The function to do DFS traversal. It uses recursive
// DFSUtil()
void Graph::DFS()
{
	// Call the recursive helper function to print DFS
	// traversal starting from all vertices one by one
	for (auto i : adj)
		if (visited[i.first] == false)
			DFSUtil(i.first);
}

// Driver Code
int main()
{
	// Create a graph given in the above diagram
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 9);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(9, 3);

	cout << "Following is Depth First Traversal \n";
	g.DFS();

	return 0;
}
```
Output: <br />
<pre>
Following is Depth First Traversal
0 1 2 3 9
</pre>
<pre>
Complexity Analysis: 
Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V), since an extra visited array of size V is required.
</pre>










<br /><br /><br />
## Problem 4:
**[Detect Cycle in Directed Graph using BFS/DFS Algo](https://www.geeksforgeeks.org/detect-cycle-in-a-graph/)**<br />
Given a `directed graph`, check whether the graph contains a `cycle` or not. Your function should return _`true` if the given graph contains `at least one cycle`, else return `false`_.<br />
Example,<br />
<pre>
Input: n = 4, e = 6
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
Output: Yes
Explanation:
Diagram:
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20200429134027/Untitled-Diagram1411.png"><br />
</pre>
<pre>
The diagram clearly shows a cycle 0 -> 2 -> 0

Input:n = 4, e = 4
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 3
Output:No
Explanation:
Diagram:
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20200429134054/Untitled-Diagram151.png"><br />
</pre>
<pre>
The diagram clearly shows no cycle
</pre>
**Solution using Depth First Search or DFS**<br />
 * **Approach:** `Depth First Traversal` can be used to detect a `cycle` in a Graph. `DFS` for a connected graph produces a `tree`. There is a **cycle in a graph only if there is a back edge present in the graph**. A back edge is an edge that is from a `node to itself (self-loop)` or `one of its ancestors in the tree produced by DFS`. In the following graph, there are `3` back edges, marked with a `cross` sign. We can observe that these 3 back edges indicate 3 cycles present in the graph.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/cycle.png"><br />
 * For a disconnected graph, Get the `DFS` forest as output. To detect cycle, check for a cycle in `individual` trees by checking back edges.<br />
To detect a back edge, keep track of `vertices` currently in the **recursion stack** of function for `DFS` traversal. If a **vertex is reached that is already in the recursion stack**, then there is a `cycle` in the tree. The edge that connects the current vertex to the vertex in the recursion stack is a back edge. Use `recStack[] array` to keep track of vertices in the recursion stack.<br />
**Dry run of the above approach:**<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190704130006/DetectCycleInaDirectedGraph.png"><br />
**In the above image there is a mistake node 1 is making a directed edge to 2 not with 0 please make a note.**<br />
 * **Algorithm:**<br />
   1. Create the graph using the given number of edges and vertices.<br />
   2. Create a recursive function that initializes the current index or vertex, visited, and recursion stack.<br />
   3. Mark the current node as visited and also mark the index in recursion stack.<br />
   4. Find all the vertices which **are not visited** and are adjacent to the current node. Recursively call the function for those vertices, If the recursive function returns true, return true.<br />
   5. If the adjacent vertices are already marked in the recursion stack then return `true`.<br />
   6. Create a wrapper class, that calls the recursive function for all the vertices and if any function `returns true return true`. Else if for all vertices the function `returns false return false`.<br />

**Implementation:**<br />
```cpp
// A C++ Program to detect cycle in a graph
#include<bits/stdc++.h>

using namespace std;

class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
	bool isCyclicUtil(int v, bool visited[], bool *rs); // used by isCyclic()
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	bool isCyclic(); // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// This function is a variation of DFSUtil() in
// https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
	if(visited[v] == false)
	{
		// Mark the current node as visited and part of recursion stack
		visited[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
				return true;
			else if (recStack[*i])
				return true;
		}

	}
	recStack[v] = false; // remove the vertex from recursion stack
	return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in
// https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
	// Mark all the vertices as not visited and not part of recursion
	// stack
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}

	// Call the recursive helper function to detect cycle in different
	// DFS trees
	for(int i = 0; i < V; i++)
		if ( !visited[i] && isCyclicUtil(i, visited, recStack))
			return true;

	return false;
}

int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	if(g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";
	return 0;
}
```
Output: <br />
<pre>
Graph contains cycle
</pre>
<pre>
Complexity Analysis: 
Time Complexity: O(V+E). 
Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).
Space Complexity: O(V). 
To store the visited and recursion stack O(V) space is needed.
</pre>







<br /><br /><br />
## Problem 5:
**[Detect Cycle in UnDirected Graph using BFS/DFS Algo](https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)**<br />
Given an `undirected graph` with `V` vertices and `E` edges, check whether it contains any cycle or not.<br /> 

>Example 1:<br />
Input:  <br />
V = 5, E = 5<br />
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}<br /> 
Output: 1<br />
Explanation:<br />
<img src = "https://user-images.githubusercontent.com/71781982/184510914-670bde56-8258-48e6-b816-17c201ba8af6.png"><br />
1->2->3->4->1 is a cycle.<br />

>Example 2:<br />
Input: <br />
V = 4, E = 2<br />
adj = {{}, {2}, {1, 3}, {2}}<br />
Output: 0<br />
Explanation: <br />
<img src = "https://user-images.githubusercontent.com/71781982/184510916-4bfdffdb-a0a0-4240-9598-96f72ad19d1e.png"><br />
No cycle in the graph.<br />
 
**Your Task:**<br />
You don't need to read or print anything. Your task is to complete the function `isCycle()` which takes `V` denoting the number of vertices and `adjacency list` as input parameters and returns _a boolean value denoting if the undirected graph contains any cycle or not, return `1` if a cycle is present else return `0`_.<br />
**NOTE:** The adjacency list denotes the **edges of the graph where edges[i]** stores all other vertices to which ith vertex is connected.<br />
 
<pre>
Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
</pre>

* Constraints: `1 ≤ V, E ≤ 10^5`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCycleUtil(int u, int par, vector<int> adj[], vector<bool>& vis) {
        // marking the current vertex as visited.
        vis[u] = true;

        // iterating on all the adjacent vertices.
        for (auto v : adj[u]) {
            if (v == par) continue;

            // if current vertex is visited, we return true else we
            // call the function recursively to detect the cycle.
            if (vis[v]) return true;
            if (isCycleUtil(v, u, adj, vis)) return true;
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // using a boolean list to mark all the vertices as not visited.
        vector<bool> vis(V, false);

        // iterating over all the vertices.
        for (int i = 0; i < V; i++) {
            // if vertex is not visited, we call the function to detect cycle.
            if (!vis[i]) {
                bool f = isCycleUtil(i, -1, adj, vis);
                // if cycle is found, we return true.
                if (f) return true;
            }
        }
        return false;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int V, E;
        cin>>V>>E;
        vector<int>adj[V];
        for(int i = 0;i<E;i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution ob;
        bool ans = ob.isCycle(V, adj);
        if(ans)cout<<"1\n";
        else cout<<"0\n";
    }
}
```











<br /><br /><br />
## Problem 6:
**[Rat in a maze Problem](https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)**<br />
Consider a rat placed at `(0, 0)` in a square matrix of order `N * N`. It has to reach the destination at `(N - 1, N - 1)`. Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are `'U'(up)`, `'D'(down)`, `'L' (left)`, `'R' (right)`.<br />
Value `0` at a cell in the matrix represents that it is blocked and rat cannot move to it while value `1` at a cell in the matrix represents that rat can be travel through it.<br />
**Note:** In a path, no cell can be visited more than one time. If the source cell is `0`, the rat cannot move to any other cell.<br />

>Example 1:<br />
<pre>
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
</pre>

>Example 2:
<pre>
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is blocked.
</pre>

**Your Task:**<br />
You don't need to read input or print anything. Complete the function `printPath()` which takes `N` and `2D array m[ ][ ]` as input parameters and returns the list of paths in lexicographically increasing order.<br /> 
`Note:` In case of no path, return an `empty list`. The driver will output `"-1"` automatically.<br />

<pre>
Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.
</pre>

* Constraints: `2 ≤ N ≤ 5`<br />
`0 ≤ m[i][j] ≤ 1`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> visited(5, vector<int> (5,0));
vector<string> result;

class Solution{
    public:
    void path(vector<vector<int>> &m, int x, int y, string dir, int n) {
        if (x == n - 1 and y == n - 1) {
            result.push_back(dir);
            return;
        }
    
        if (m[x][y] == 0 or visited[x][y] == 1) return;
    
        // DFS
        visited[x][y] = 1;
        if (x > 0) path(m, x - 1, y, dir + 'U', n);
        if (y > 0) path(m, x, y - 1, dir + 'L', n);
        if (x < n - 1) path(m, x + 1, y, dir + 'D', n);
        if (y < n - 1) path(m, x, y + 1, dir + 'R', n);
        visited[x][y] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                visited[i][j] = false;
            }
        }
        result.clear();
    
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0) return result;
    
        path(m, 0, 0, "", n);
    
        sort(result.begin(), result.end());
        return result;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>m(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>m[i][j];
            }
        }
        Solution obj;
        vector<string>result = obj.findPath(m,n);
        if(result.size()==0){
            cout<<-1;
        }
        else{
            for(int i =0;i<result.size();i++) cout<< result[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```








<br /><br /><br />
## Problem 7:
**[Minimum Step by Knight](https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1)**<br />
Given a square chessboard, the `initial` position of Knight and `position` of a `target`. Find out the `minimum` steps a Knight will take to reach the target position.<br />
**Note:** The initial and the target position coordinates of Knight have been given according to `1-base indexing`.<br />

>Example 1:<br />
Input:<br />
N=6<br />
knightPos[ ] = {4, 5}<br />
targetPos[ ] = {1, 1}<br />
Output:<br />
3<br />
Explanation:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/KnightChess.jpg"><br />
Knight takes 3 step to reach from `(4, 5) to (1, 1)`: (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).<br />
 
**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `minStepToReachTarget()` which takes the initial position of Knight `(KnightPos)`, the target position of Knight `(TargetPos)`, and the size of the `chessboard (N)` as input parameters and returns _the minimum number of steps required by the knight to reach from its current position to the given target position or return `-1` if its not possible_.<br />

<pre>
Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).
</pre>

* Constraints: `1 <= N <= 1000`<br />
`1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    private:
    struct cell{
        int x;
        int y;
        int steps;
    };
    public:
    
    //Function to check if cell indexes are within bounds.
    bool isValid(int x, int y, int N){
        return (x >=0 and x < N and y >=0 and y < N);
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
    {
        KnightPos[0]--;
        KnightPos[1]--;
        TargetPos[0]--;
        TargetPos[1]--;
        
        //using boolean list to mark visited cells and currently 
        //marking all the cells as false.
        vector<vector<bool>>vis(N, vector<bool>(N, false));
        
        vector<vector<int>>dxy = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
        
        //queue for storing visited cells by knight in board and steps taken.
        queue<cell>q;
        
        //pushing starting position of knight with 0 distance.
        q.push({KnightPos[0], KnightPos[1], 0});
        
        //marking starting cell as visited.
        vis[KnightPos[0]][KnightPos[1]] = true;
        
        while(!q.empty())
        {
            //storing cell indexes and steps of front element and popping them.
            int x = q.front().x;
            int y = q.front().y;
            int steps = q.front().steps;
            q.pop();
            
            //if we reach the required cell, we return true.
            if(x == TargetPos[0] and y == TargetPos[1])
                return steps;
                
            //using loop to reach all the cells that can be reached by knight.
            for(int i = 0; i < dxy.size(); i++)
            {
                int n_x = x + dxy[i][0];
                int n_y = y + dxy[i][1];
                
                //if cell indexes are valid and cell is not visited, we push the 
                //indexes in queue with steps and mark cell as visited.
                if(isValid(n_x, n_y, N) and !vis[n_x][n_y])
                {
                    q.push({n_x, n_y, steps+1});
                    vis[n_x][n_y] = true;
                }
            }
        }
        return -1;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        vector<int>KnightPos(2);
        vector<int>TargetPos(2);
        int N; cin>>N;
        cin>>KnightPos[0]>>KnightPos[1];
        cin>>TargetPos[0]>>TargetPos[1];
        Solution ob;
        int ans = ob.minStepToReachTarget(KnightPos, TargetPos, N);
        cout<<ans<<endl;
    }
}
```








<br /><br /><br />
## Problem 8:
**[733. Flood Fill](https://leetcode.com/problems/flood-fill/)**<br />
An image is represented by an `m x n` integer grid `image` where `image[i][j]` represents the pixel value of the image.<br />
You are also given three integers `sr`, `sc`, and `newColor`. You should perform a **flood fill** on the image starting from the pixel `image[sr][sc]`.<br />
To perform a **flood fill**, consider the starting pixel, plus any pixels connected **4-directionally** to the starting pixel of the same color as the starting pixel, plus any pixels connected `4-directionally` to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with `newColor`.<br />
Return _the modified image after performing the flood fill_.<br />

>Example 1:<br />
><img src = "https://assets.leetcode.com/uploads/2021/06/01/flood1-grid.jpg"><br />
>Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2<br />
>Output: [[2,2,2],[2,2,0],[2,0,1]]<br />
>Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting >pixel (i.e., the blue pixels) are colored with the new color.<br />
>Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.<br />
	
>Example 2:<br />
>Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2<br />
>Output: [[2,2,2],[2,2,2]]<br />
 
* Constraints: `m == image.length`<br />
`n == image[i].length`<br />
`1 <= m, n <= 50`<br />
`0 <= image[i][j], newColor < 2^16`<br />
`0 <= sr < m`<br />
`0 <= sc < n`<br />
	
```cpp
class Solution {
public:
    void dfs(int i,int j,int initialColor,int newColor,vector<vector<int>> &image){
        if(i<0 || j<0 || i>=(image.size()) || j>=(image[0].size()) || image[i][j] != initialColor) return;
        image[i][j] = newColor;
        dfs(i-1,j,initialColor,newColor,image);
        dfs(i+1,j,initialColor,newColor,image);
        dfs(i,j-1,initialColor,newColor,image);
        dfs(i,j+1,initialColor,newColor,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor) dfs(sr,sc,image[sr][sc],newColor,image);
        return image;
    }
};
```









<br /><br /><br />
## Problem 9:
**[133. Clone Graph](https://leetcode.com/problems/clone-graph/)**<br />
Given a reference of a node in a **connected** undirected graph.<br />
Return a **deep copy** (clone) of the graph.<br />
Each node in the graph contains a value (`int`) and a list (`List[Node]`) of its neighbors.<br />
<pre>
class Node {
    public int val;
    public List<Node> neighbors;
}
</pre>
<br />**Test case format:**<br />
For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with `val == 1`, the second node with `val == 2`, and so on. The graph is represented in the test case using an adjacency list.<br />
**An adjacency list** is a collection of unordered **lists** used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.<br />
The given node will always be the first node with `val = 1`. You must return the **copy of the given node** as a reference to the cloned graph.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2019/11/04/133_clone_graph_question.png"><br />
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]<br />
Output: [[2,4],[1,3],[2,4],[1,3]]<br />
Explanation: There are 4 nodes in the graph.<br />
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).<br />
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).<br />
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).<br />
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).<br />

>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2020/01/07/graph.png"><br />
Input: adjList = [[]]<br />
Output: [[]]<br />
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.<br />

>Example 3:<br />
Input: adjList = []<br />
Output: []<br />
Explanation: This an empty graph, it does not have any nodes.<br />
 
* Constraints: The number of nodes in the graph is in the range `[0, 100]`.<br />
`1 <= Node.val <= 100`<br />
`Node.val` is unique for each node.<br />
There are no repeated edges and **no self-loops** in the graph.<br />
The Graph is connected and all nodes can be visited starting from the given node.<br />

```cpp
class Solution {
public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) // if node is null, then simply return null
        {
          
            return NULL;
        }
        
        // for a node, we will check whether we already creates a copy of thiis or not. If it is present in map that means we already creates a copy of this.
        //But if not present in map, that means we have not a copy of this.
        // Also, if we create a copy, then being a good neighbor, we find whether our neighbor have a copy or not, so we will travel all around our adjcant.
        
        if(mp.find(node) == mp.end()) // if not present in map
        {
            mp[node] = new Node(node -> val, {}); // make a copy
            
            for(auto adj: node -> neighbors) // travel in adjcant
            {
                mp[node] -> neighbors.push_back(cloneGraph(adj)); //add copy
            }
        }
        
        return mp[node]; // and at last, return mp[node] as till now we clone our whole graph
        
    }
};
```





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
