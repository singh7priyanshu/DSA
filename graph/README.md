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
**[1319. Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)**<br />
There are `n` computers numbered from `0` to `n - 1` connected by ethernet cables `connections` forming a network where `connections[i] = [ai, bi]` represents a connection between computers `ai` and `bi`. Any computer can reach any other computer directly or indirectly through the network.<br />
You are given an initial computer network `connections`. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.<br />
Return _the minimum number of times you need to do this in order to make all the computers connected_. If it is not possible, return `-1`.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2020/01/02/sample_1_1677.png"><br />
Input: n = 4, connections = [[0,1],[0,2],[1,2]]<br />
Output: 1<br />
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.<br />

>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2020/01/02/sample_2_1677.png"><br />
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]<br />
Output: 2<br />

>Example 3:<br />
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]<br />
Output: -1<br />
Explanation: There are not enough cables.<br />

* Constraints: `1 <= n <= 10^5`<br />
`1 <= connections.length <= min(n * (n - 1) / 2, 10^5)`<br />
`connections[i].length == 2`<br />
`0 <= ai, bi < n`<br />
`ai != bi`<br />
There are no repeated connections.<br />
No two computers are connected by more than one cable.<br />

```cpp
class Solution {
    private:
    bool dfssolve(int node,vector<int>&visited,vector<int>adj[]){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfssolve(it,visited,adj)) return true;
            }
        }
        return false;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()) return -1;
        // adjacency list 
        vector<int>adj[n];
        int connected=0;
        vector<int>visited(n+1,0);
//         making the adjacency list
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
//         counting components by bfs 
        for(int i=0;i<n;i++){
            if(!visited[i]){
                 connected++;
                dfssolve(i,visited,adj);
            }
        }
        // if there are n nodes so we simply need m-1 minimum wires to connect to the network
        return connected-1;
    }
};
```






<br /><br /><br />
## Problem 11:
**[127. Word Ladder](https://leetcode.com/problems/word-ladder/)**<br />
A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:<br />
	
 * Every adjacent pair of words differs by a single letter.<br /> 
 * Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.<br />
 * `sk == endWord`<br />
 
Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return _the **number of words** in the **shortest transformation sequence** from `beginWord` to `endWord`, or `0` if no such sequence exists_.<br />

>Example 1:<br />
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]<br />
Output: 5<br />
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.<br />

>Example 2:<br />
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]<br />
Output: 0<br />
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.<br />
 
* Constraints: `1 <= beginWord.length <= 10`<br />
`endWord.length == beginWord.length`<br />
`1 <= wordList.length <= 5000`<br />
`wordList[i].length == beginWord.length`<br />
`beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.<br />
`beginWord != endWord`<br />
All the words in `wordList` are **unique**.<br />

```cpp
static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet; // declare an unordered set
        
        bool isPresent = false; // to find whether end word is present in word list or not
        
        // Inserting all words from wordList to wordSet
        for(string word: wordList)
        {
            if(endWord.compare(word) == 0) // if end word is present in wordList
            {
                isPresent = true;
            }
            
            wordSet.insert(word); // Inserting each word in wordSet
        }
        
        if(isPresent == false) // if end word is not present in worrd List
            return 0;
        
        queue<string> q; // declare an queue, for BFS traversal
        q.push(beginWord); // push begi word into our queue
        
        int depth = 0; // for telling depth of the queue we are exploring
        
        // Implementing BFS
        while(q.empty() == false)
        {
            depth = depth + 1; // if one level is over increment depth
            
            int levelSize = q.size(); // number of words present at a level
            
            // travelling in each level
            while(levelSize--)
            {
                string curr = q.front();
                q.pop();
                
                // checking for all possible depth word
                for(int i = 0; i < curr.length(); i++) // for each index
                {
                    string temp = curr; 
                    
                    //checking out each possibility of alphabet
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;
                        
                        if(curr.compare(temp) == 0) // skipping the same word
                            continue;
                        
                        if(temp.compare(endWord) == 0) // if matches with end word
                            return depth + 1;
                        
                        // if present in word set
                        if(wordSet.find(temp) != wordSet.end())
                        {
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
        }
        
        return 0; // and at last, we still not able to find our end word.
    }
};
```






**[126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/)**<br />
A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:<br />

 * Every adjacent pair of words differs by a single letter.<br />
 * Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.<br />
 * `sk == endWord`<br />
 
Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return _all the **shortest transformation sequences** from `beginWord` to `endWord`, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words_ [`beginWord, s1, s2, ..., sk`].<br />

>Example 1:<br /> 
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]<br />
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]<br />
Explanation: There are 2 shortest transformation sequences:<br />
"hit" -> "hot" -> "dot" -> "dog" -> "cog"<br />
"hit" -> "hot" -> "lot" -> "log" -> "cog"<br />

>Example 2:<br />
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]<br />
Output: []<br />
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.<br />
 
* Constraints: `1 <= beginWord.length <= 5`<br />
`endWord.length == beginWord.length`<br />
`1 <= wordList.length <= 500`<br />
`wordList[i].length == beginWord.length`<br />
`beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.<br />
`beginWord != endWord`<br />
All the words in `wordList` are **unique**.<br />

```cpp
class Solution
{
public:
    vector<vector<string>> res;
    vector<string> te;
    unordered_map<string, int> mp;
    string b;
    void dfs(string s)
    {
        te.push_back(s);
        if (s == b)
        {
            vector<string> x = te;
            reverse(x.begin(), x.end());
            res.push_back(x);
            te.pop_back();
            return;
        }
        int cur = mp[s];
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            for (char cc = 'a'; cc <= 'z'; cc++)
            {
                s[i] = cc;
                if (mp.count(s) && mp[s] == cur - 1)
                    dfs(s);
            }
            s[i] = c;
        }
        te.pop_back();
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        b = beginWord;
        queue<string> q;
        int k = beginWord.size();
        q.push({beginWord});
        mp[beginWord] = 0;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                string t = q.front();
                q.pop();
                int x = mp[t] + 1;
                for (int i = 0; i < k; i++)
                {
                    string temp = t;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        temp[i] = ch;
                        if (!mp.count(temp) && dict.count(temp))
                            mp[temp] = x, q.push(temp);
                    }
                }
            }
        }
        if (mp.count(endWord))
            dfs(endWord);
        return res;
    }
};
```








<br /><br /><br />
## Problem 12:
**[Dijkstra’s shortest path algorithm | Greedy Algo](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/)**<br />
Given a `graph` and a `source vertex` in the graph, find the _shortest paths from the source to all vertices in the given graph_.<br />
`Dijkstra’s algorithm` is very similar to `Prim’s algorithm` for `minimum spanning tree`. Like `Prim’s MST`, we generate a `SPT (shortest path tree)` with a given **source** as a **root**. We maintain two sets, one set contains `vertices` included in the **shortest-path tree**, other set includes `vertices not yet included` in the **shortest-path tree**. At every step of the algorithm, we find a vertex that is in the other set (set of not yet included) and has a `minimum distance` from the source.<br />
Below are the detailed steps used in `Dijkstra’s algorithm` to find the shortest path from a single source vertex to all other vertices in the given graph.<br />

**Algorithm**<br />

 1) Create a set `sptSet` **(shortest path tree set)** that keeps track of vertices included in the shortest-path tree, i.e., whose **minimum distance** from the source is calculated and finalized. Initially, this set is empty.<br /> 
 2) Assign a distance value to all vertices in the input graph. Initialize all distance values as `INFINITE`. Assign distance value as `0` for the source vertex so that it is picked first. <br />
 3) While sptSet doesn’t include all vertices<br /> 
  ….a) Pick a vertex `u` which is not there in `sptSet` and has a minimum distance value.<br /> 
  ….b) Include `u` to `sptSet`. <br />
  ….c) Update distance value of all adjacent vertices of `u`. To update the distance values, iterate through all adjacent vertices.<br /> 
  For every adjacent vertex `v`, if the sum of distance value of `u` (from source) and weight of edge `u-v`, is less than the distance value of `v`, then update the distance value of `v`. <br />

Let us understand with the following example:<br />
<img src = "https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg"><br />
The set sptSet is initially empty and distances assigned to vertices are **{0, INF, INF, INF, INF, INF, INF, INF}** where **INF** indicates `infinite`. Now pick the vertex with a `minimum distance` value. The vertex `0` is picked, include it in `sptSet`. So `sptSet` becomes `{0}`. After including `0` to `sptSet`, update distance values of its adjacent vertices. Adjacent vertices of `0` are `1` and `7`. The distance values of `1` and `7` are updated as `4` and `8`. The following subgraph shows vertices and their distance values, only the vertices with finite distance values are shown. The vertices included in `SPT` are shown in **green colour**.<br />
<img src = "https://www.geeksforgeeks.org/wp-content/uploads/MST1.jpg"><br />
Pick the vertex with `minimum distance value` and not already included in **SPT (not in sptSET)**. The vertex `1` is picked and added to `sptSet`. So `sptSet` now becomes **{0, 1}**. Update the distance values of adjacent vertices of `1`. The distance value of vertex `2` becomes `12`.<br />
<img src = "https://www.geeksforgeeks.org/wp-content/uploads/DIJ2.jpg"><br />
Pick the vertex with **minimum distance** value and not already included in `SPT` (**not in sptSET**). Vertex `7` is picked. So **sptSet** now becomes `{0, 1, 7}`. Update the distance values of adjacent vertices of `7`. The distance value of vertex `6` and `8` becomes finite (`15` and `9` respectively).<br />
<img src = "https://www.geeksforgeeks.org/wp-content/uploads/DIJ3.jpg"><br />
Pick the vertex with **minimum distance** value and not already included in `SPT (not in sptSET)`. Vertex `6` is picked. So `sptSet` now becomes `{0, 1, 7, 6}`. Update the distance values of adjacent vertices of `6`. The distance value of vertex `5` and `8` are updated.<br />
<img src = "https://www.geeksforgeeks.org/wp-content/uploads/DIJ4.jpg"><br />
We repeat the above steps until sptSet `includes` all vertices of the given graph. Finally, we get the following `Shortest Path Tree (SPT)`.<br />
<img src = "https://www.geeksforgeeks.org/wp-content/uploads/DIJ5.jpg"><br />

**How to implement the above algorithm?**<br />
We use a boolean array `sptSet[]` to represent the set of vertices included in `SPT`. If a value `sptSet[v]` is `true`, then vertex `v` is included in `SPT`, otherwise `not`. Array `dist[]` is used to store the **shortest distance values** of all vertices.<br />
```cpp
// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <iostream>
using namespace std;
#include <limits.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
	cout <<"Vertex \t Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t"<<dist[i]<< endl;
}

// Function that implements Dijkstras single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // The output array. dist[i] will hold the shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist);
}

// driver program to test above function
int main()
{

	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
			    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
			    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
			    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
			    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
			    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
			    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
			    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
			    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstra(graph, 0);

	return 0;
}
```
Output: <br />
<pre>
Vertex   Distance from Source
0                0
1                4
2                12
3                19
4                21
5                11
6                9
7                8
8                14
</pre>
<pre>
Time Complexity: O(V^2)
Space Complexity: O(V)
</pre>

<br />**Notes:**<br /> 
1) The code calculates the **shortest distance** but doesn’t calculate the **path information**. We can create a `parent array`, update the `parent array` when distance is updated (like `prim’s implementation`) and use it to show the `shortest path` from source to different vertices.<br />
2) The code is for `undirected graphs`, the same **Dijkstra function** can be used for `directed graphs also`.<br />
3) The code finds the **shortest distances** from the **source to all vertices**. If we are interested only in the shortest distance from the source to a single target, we can `break` the for loop when the **picked minimum distance vertex is equal to the target** (Step 3.a of the algorithm).<br />
4) Time Complexity of the implementation is `O(V^2)`. If the input graph is represented using adjacency list, it can be reduced to `O(E log V)` with the help of a `binary heap`.<br />
5) `Dijkstra’s algorithm` doesn’t work for graphs with `negative weight cycles`. It may give `correct results for a graph with negative edges` but you must allow a vertex can be **visited multiple times** and that version will lose its `fast time complexity`. For graphs with `negative weight edges and cycles`, `Bellman–Ford algorithm` can be used.<br />








<br /><br /><br />
## Problem 13:
**[Implement Topological Sort](https://practice.geeksforgeeks.org/problems/topological-sort/1)**<br />
Given a `Directed Acyclic Graph (DAG)` with `V` vertices and `E` edges, Find any `Topological Sorting` of that Graph.<br />

>Example 1:<br />
Input:<br />
<img src = "https://user-images.githubusercontent.com/71781982/184528293-993fa131-daf6-4d77-b89d-8c217890f7d2.png"><br />
Output:<br />
1<br />
Explanation:<br />
The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, then output<br />
would be 1 for all test cases.<br />
One possible Topological order for the graph is 3, 2, 1, 0.<br />

>Example 2:<br />
Input:<br />
<img src = "https://user-images.githubusercontent.com/71781982/184528296-bb641a6b-d4cb-4322-813c-a26e8e7fbe7d.png"><br />
Output:<br />
1<br />
Explanation:<br />
The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, then output<br />
would be 1 for all test cases.<br />
One possible Topological order for the graph is 5, 4, 2, 1, 3, 0.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `topoSort()`  which takes the integer `V` denoting the number of vertices and `adjacency list` as input parameters and returns _an array consisting of a the vertices in Topological order_. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then console output will be `1` else `0`.<br />

<pre>
Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).
</pre>

* Constraints: `2 ≤ V ≤ 10^4`<br />
`1 ≤ E ≤ (N*(N-1))/2`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void topo(vector<int> adj[], int u, bool visited[], stack<int> &s) 
    {
        //marking the current vertex as visited.
        visited[u] = true; 
    
        //traversing over the adjacent vertices.
        for (auto v : adj[u])
        {
            //if any vertex is not visited, we call the function recursively.
            if (!visited[v])
                topo(adj, v, visited,s); 
        }
        //pushing the current vertex into the stack.
        s.push(u); 
    }
    
    //Function to return list containing vertices in Topological order. 
    vector <int> topoSort(int N, vector<int> adj[]) 
    {
        //using boolean array to mark visited nodes and currently 
        //marking all the nodes as false.
        bool visited[N + 1];                
        memset(visited, 0, sizeof visited); 
        
        stack<int> s;
        
        //traversing over all the vertices.
        for (int i = 0; i < N; i++) 
        {
            //if the current vertex is not visited, we call the topo function.
            if (!visited[i])              
                topo(adj, i, visited, s); 
        }
    
        vector <int> res;
        int i = -1;
        while (!s.empty())
        {
            //pushing elements of stack in list and popping them from stack.
            res.push_back (s.top()); 
            s.pop();
        }
        //returning the list.
        return res;
    }
};

int check(int V, vector<int> &res, vector<int>adj[]){
    if(V!=res.size())return 0;
    vector<int>map(V, -1);
    for(int i = 0;i<V;i++){
        map[res[i]] = i;
    }
    for(int i = 0;i<V;i++){
        for(int v : adj[i]){
            if(map[i] > map[v])return 0;
        }
    }
    return 1;
}

int main(){
    int t; cin>>t;
    while(t--){
        int N, E; cin>>E>>N;
        int u, v;
        vector<int>adj[N];
        for(int i = 0;i<E;i++){
            cin>>u>>v;
            adj[u].push_back(v);    
        }
        Solution ob;
        vector<int>res = ob.topoSort(N, adj);
        cout<<check(N, res, adj)<<endl;
    }
}
```










<br /><br /><br />
## Problem 14:
**[Minimum time taken by each job to be completed given by a Directed Acyclic Graph](https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/)**<br />
Given a `Directed Acyclic Graph` having `V` vertices and `E` edges, where each edge `{U, V}` represents the Jobs `U` and `V` such that Job `V` can only be started only after completion of Job `U`. The task is to determine the **minimum time** taken by each job to be completed where each Job takes unit time to get completed.<br />
Examples:<br />
<pre>
Input: N = 10, E = 13, Below is the given graph:
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20200804212533/Semester1.png"><br />
Output: 1 1 2 2 2 3 4 5 2 6  
Explanation:
Start the jobs 1 and 2 at the beginning and complete them at 1 unit of time. 
Since, jobs 3, 4, 5, and 9 have the only dependency on one job (i.e 1st job for 
jobs 3, 4, and 5 and 2nd job for job 9). So, we can start these jobs at 1st unit of 
time and complete these at 2nd unit of time after the completion of the dependent Job.
Similarly, 
Job 6 can only be done after 3rd and 4th jobs are done. So, start it at 2nd unit of time and complete it at 3rd unit of time.
Job 7 can only be done after job 6 is done. So, you can start it at 3rd unit of time and complete it at 4th unit of time.
Job 8 can only be done after 4th, 5th, and 7th jobs are done. So, start it at 4th unit of time and complete it at 5th unit of time.
Job 10 can only be done after the 8th job is done. So, start it at 5th unit of time and complete it at 6th unit of time.

Input: N = 7, E = 7, Below is the given graph:
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20200808013603/Semester2.png"><br />
Output: 1 2 3 3 3 4 4  
Explanation:
Start the Job 1 at the beginning and complete it at 1st unit of time.
The job 2 can only be done after 1st Job is done. So, start it at 1st unit of time and complete it at 2nd unit of time.
Since, Job 3, 4, and 5 have the only dependency on 2nd Job. So, start these jobs at 2nd unit of time and complete these at 3rd unit of time.
The Job 6 can only be done after the 3rd and 4th Job is done. So, start it at 3rd unit of time and complete it at 4th unit of time.
The Job 7 can only be done after the 5th Job is done. So, start it at 3rd hour and complete it at 4th unit of time.
</pre>
**Approach:**<br />
The job can be started only if all the jobs that are prerequisites of the job that are done. Therefore, the idea is to use Topological Sort for the given network. Below are the steps:<br />

 1. Finish the jobs that are not dependent on any other job.<br />
 2. Create an array `inDegree[]` to store the count of the dependent node for each node in the given network.<br />
 3. Initialize a queue and push all the vertex whose `inDegree[]` is `0`.<br />
 4. Initialize the timer to `1` and store the **current queue size**(say size) and do the following:<br />
   * Pop the node from the queue until the size is **0** and update the finishing time of this node to the **timer**.<br />
   * While popping the node(say node **U**) from the queue decrement the **inDegree** of every node connected to it.<br />
   * If **inDegree** of any node is **0** in the above step then insert that node in the queue.<br />
   * Increment the timer after all the above steps.<br />
 5. Print the finishing time of all the nodes after we traverse every node in the above step.<br />
 
Below is the implementation of the above approach:<br />
```cpp
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
#define maxN 100000

// Adjacency List to store the graph
vector<int> graph[maxN];

// Array to store the in-degree of node
int indegree[maxN];

// Array to store the time in which
// the job i can be done
int job[maxN];

// Function to add directed edge
// between two vertices
void addEdge(int u, int v)
{
	// Insert edge from u to v
	graph[u].push_back(v);

	// Increasing the indegree
	// of vertex v
	indegree[v]++;
}

// Function to find the minimum time
// needed by each node to get the task
void printOrder(int n, int m)
{
	// Find the topo sort order
	// using the indegree approach

	// Queue to store the
	// nodes while processing
	queue<int> q;

	// Pushing all the vertex in the
	// queue whose in-degree is 0

	// Update the time of the jobs
	// who don't require any job to
	// be completed before this job
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			job[i] = 1;
		}
	}

	// Iterate until queue is empty
	while (!q.empty()) {

		// Get front element of queue
		int cur = q.front();

		// Pop the front element
		q.pop();

		for (int adj : graph[cur]) {

			// Decrease in-degree of
			// the current node
			indegree[adj]--;

			// Push its adjacent elements
			if (indegree[adj] == 0) {
				job[adj] = job[cur] + 1;
				q.push(adj);
			}
		}
	}

	// Print the time to complete
	// the job
	for (int i = 1; i <= n; i++)
		cout << job[i] << " ";
	cout << "\n";
}

// Driver Code
int main()
{
	// Given Nodes N and edges M
	int n, m;
	n = 10;
	m = 13;

	// Given Directed Edges of graph
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(1, 5);
	addEdge(2, 3);
	addEdge(2, 8);
	addEdge(2, 9);
	addEdge(3, 6);
	addEdge(4, 6);
	addEdge(4, 8);
	addEdge(5, 8);
	addEdge(6, 7);
	addEdge(7, 8);
	addEdge(8, 10);

	// Function Call
	printOrder(n, m);
	return 0;
}
```
Output:<br />
<pre>
1 1 2 2 2 3 4 5 2 6
</pre>
<pre>
Time Complexity: O(V+E), where V is the number of nodes and E is the number of edges. 
Auxiliary Space: O(V)
</pre>





<br /><br /><br />
## Problem 15:
**[Find whether it is possible to finish all tasks or not from given dependencies](https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/)**<br />
There are a total of `n` tasks you have to pick, labelled from `0` to `n-1`. Some tasks may have prerequisites, for example to pick task `0` you have to first pick task `1`, which is expressed as a pair: `[0, 1]`<br />
Given the total number of tasks and a list of prerequisite pairs, is it possible for you to finish all tasks?<br />
Examples:<br />
<pre>
Input: 2, [[1, 0]] 
Output: true 
Explanation: There are a total of 2 tasks to pick. To pick task 1 you should have finished task 0. So it is possible.
Input: 2, [[1, 0], [0, 1]] 
Output: false 
Explanation: There are a total of 2 tasks to pick. To pick task 1 you should have finished task 0, and to pick task 0 you should also have finished task 1. So it is impossible.
Input: 3, [[1, 0], [2, 1], [3, 2]] 
Output: true 
Explanation: There are a total of 3 tasks to pick. To pick tasks 1 you should have finished task 0, and to pick task 2 you should have finished task 1 and to pick task 3 you should have finished task 2. So it is possible.
</pre>
**Solution:**<br />
We can consider this problem as a graph (related to **topological sorting**) problem. All tasks are nodes of the graph and if task `u` is a prerequisite of task `v`, we will add a directed edge from node `u` to node `v`. Now, this problem is equivalent to detecting a cycle in the graph represented by prerequisites. If there is a cycle in the graph, then it is not possible to finish all tasks (because in that case there is no any topological order of tasks). Both `BFS` and `DFS` can be used to solve it.<br />
Since pair is inconvenient for the implementation of graph algorithms, we first transform it to a graph. If task `u` is a prerequisite of task `v`, we will add a directed edge from node `u` to node `v`.<br />
**Prerequisite :** Detect Cycle in a Directed Graph<br />

<br />`Using DFS`<br />
For DFS, it will first visit a node, then one neighbor of it, then one neighbor of this neighbor… and so on. If it meets a node which was visited in the current process of `DFS` visit, a cycle is detected and we will return `false`. Otherwise it will start from another unvisited node and repeat this process till all the nodes have been visited. Note that you should make two records: one is to record all the visited nodes and the other is to record the visited nodes in the current **DFS** visit.<br />
The code is as follows. We use a `vector visited` to record all the visited nodes and another vector onpath to record the **visited nodes of the current DFS visit**. Once the current visit is finished, we reset the `onpath` value of the starting node to `false`.<br />
```cpp
// CPP program to check whether we can finish all
// tasks or not from given dependencies.
#include <bits/stdc++.h>
using namespace std;

// Returns adjacency list representation from a list
// of pairs.
vector<unordered_set<int> > make_graph(int numTasks, vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph(numTasks);
	for (auto pre : prerequisites)
		graph[pre.second].insert(pre.first);
	return graph;
}

// A DFS based function to check if there is a cycle
// in the directed graph.
bool dfs_cycle(vector<unordered_set<int> >& graph, int node, vector<bool>& onpath, vector<bool>& visited)
{
	if (visited[node])
		return false;
	onpath[node] = visited[node] = true;
	for (int neigh : graph[node])
		if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
			return true;
	return onpath[node] = false;
}

// Main function to check whether possible to finish all tasks or not
bool canFinish(int numTasks, vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph = make_graph(numTasks, prerequisites);
	vector<bool> onpath(numTasks, false), visited(numTasks, false);
	for (int i = 0; i < numTasks; i++)
		if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
			return false;
	return true;
}

int main()
{
	int numTasks = 4;

	vector<pair<int, int> > prerequisites;

	// for prerequisites: [[1, 0], [2, 1], [3, 2]]

	prerequisites.push_back(make_pair(1, 0));
	prerequisites.push_back(make_pair(2, 1));
	prerequisites.push_back(make_pair(3, 2));
	if (canFinish(numTasks, prerequisites)) {
		cout << "Possible to finish all tasks";
	}
	else {
		cout << "Impossible to finish all tasks";
	}

	return 0;
}
```
Output<br />
<pre>
Possible to finish all tasks
</pre>
<br />`Using BFS`<br />
BFS can be used to solve it using the idea of topological sort. If topological sorting is possible, it means there is no cycle and it is possible to finish all the tasks.<br />
**BFS** uses the indegrees of each node. We will first try to find a node with `0` indegree. If we fail to do so, there must be a `cycle in the graph` and we return `false`. Otherwise we have found `one`. We set its indegree to be `-1` to prevent from visiting it again and reduce the indegrees of all its neighbors by `1`. This process will be repeated for `n` (number of nodes) times. If we have not returned `false`, we will return `true`.<br />
```cpp
// A BFS based solution to check if we can finish
// all tasks or not. This solution is mainly based
// on Kahn's algorithm.
#include <bits/stdc++.h>
using namespace std;

// Returns adjacency list representation from a list
// of pairs.
vector<unordered_set<int> >
make_graph(int numTasks, vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph(numTasks);
	for (auto pre : prerequisites)
		graph[pre.second].insert(pre.first);
	return graph;
}

// Finds in-degree of every vertex
vector<int>
compute_indegree(vector<unordered_set<int> >& graph)
{
	vector<int> degrees(graph.size(), 0);
	for (auto neighbors : graph)
		for (int neigh : neighbors)
			degrees[neigh]++;
	return degrees;
}

// Main function to check whether possible to finish all
// tasks or not
bool canFinish(int numTasks, vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph
		= make_graph(numTasks, prerequisites);
	vector<int> degrees = compute_indegree(graph);
	for (int i = 0; i < numTasks; i++) {
		int j = 0;
		for (; j < numTasks; j++)
			if (!degrees[j])
				break;
		if (j == numTasks)
			return false;
		degrees[j] = -1;
		for (int neigh : graph[j])
			degrees[neigh]--;
	}
	return true;
}

int main()
{
	int numTasks = 4;
	vector<pair<int, int> > prerequisites;
	prerequisites.push_back(make_pair(1, 0));
	prerequisites.push_back(make_pair(2, 1));
	prerequisites.push_back(make_pair(3, 2));
	if (canFinish(numTasks, prerequisites)) {
		cout << "Possible to finish all tasks";
	}
	else {
		cout << "Impossible to finish all tasks";
	}

	return 0;
}
```
Output<br />
<pre>
Possible to finish all tasks
</pre>






<br /><br /><br />
## Problem 16:
**[Find the number of islands](https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1)**<br />
Given a grid of size `n*m` (`n` is the number of rows and `m` is the number of columns in the grid) consisting of `'0's` (Water) and `'1's`(Land). Find the number of islands.<br />
**Note:** An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all `8` directions.<br />

>Example 1:<br />
<img src = "https://user-images.githubusercontent.com/71781982/184530331-fb9f9dcd-bac7-4cad-b612-b435feea756d.png"><br />

>Example 2:<br />
<img src = "https://user-images.githubusercontent.com/71781982/184530329-9d71f8b4-bc49-40ae-b5e0-477fbd9a1d71.png"><br />

**Your Task:**<br />
You don't need to read or print anything. Your task is to complete the function `numIslands()` which takes the grid as an input parameter and returns _the total number of islands_.<br />

<pre>
Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)
</pre>

* Constraints: `1 ≤ n, m ≤ 500`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // these lists are used to get row and column numbers of 8
    // neighbours of a given cell.
    vector<int> dx = {-1, 0, 1, 0, 1, -1, -1, 1};
    vector<int> dy = {0, -1, 0, 1, 1, 1, -1, -1};

    bool isValid(int x, int y, int n, int m) {
        return (x >= 0 and x < n and y >= 0 and y < m);
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // boolean array to mark visited cells.
        // initially all cells are unvisited.
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // using queue for BFS.
        queue<pair<int, int>> q;
        int ans = 0;

        // traversing over all cells of given matrix.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if cell is unvisited and grid value is 1, we increment the
                // count and mark it as visited.
                if (!vis[i][j] and grid[i][j] == '1') {
                    ans++;
                    vis[i][j] = true;

                    // pushing it into the queue.
                    q.push({i, j});
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 8; k++) {
                            // if row and column number is in range, grid value
                            // is 1 and cell is not yet visited,
                            if (isValid(x + dx[k], y + dy[k], n, m) and
                                !vis[x + dx[k]][y + dy[k]] and
                                grid[x + dx[k]][y + dy[k]] == '1') {
                                // we push the cell in queue and mark it
                                // visited.
                                q.push({x + dx[k], y + dy[k]});
                                vis[x + dx[k]][y + dy[k]] = true;
                            }
                        }
                    }
                }
            }
        }
        // returning the result.
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<vector<char>>grid(n, vector<char>(m, '#'));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++)cin>>grid[i][j];
        }
        Solution ob;
        int ans = ob.numIslands(grid);
        cout<<ans<<endl;
    }
}
```





<br /><br /><br />
## Problem 17:
**[Given a sorted Dictionary of an Alien Language, find order of characters](https://practice.geeksforgeeks.org/problems/alien-dictionary/1)**<br />
Given a sorted dictionary of an alien language having `N` words and `k` starting alphabets of standard dictionary. Find the order of characters in the alien language.<br />
**Note:** Many orders may be possible for a particular test case, thus you may return _any valid order and output will be `1` if the order of string returned by the function is correct else `0` denoting incorrect string returned_.<br />
 
>Example 1:<br />
Input: <br />
N = 5, K = 4<br />
dict = {"baa","abcd","abca","cab","cad"}<br />
Output:<br />
1<br />
Explanation:<br />
Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before<br /> 
"abcd", therefore 'b' is before 'a' in output. Similarly we can find other orders.<br />

>Example 2:<br />
Input: <br />
N = 3, K = 3<br />
dict = {"caa","aaa","aab"}<br />
Output:<br />
1<br />
Explanation:<br />
Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before<br />
"aaa", therefore 'c' is before 'a' in output. Similarly we can find other orders.<br />
 
**Your Task:**<br />
You don't need to read or print anything. Your task is to complete the function `findOrder()` which takes  the string array `dict[]`, its size `N` and the integer `K` as input parameter and returns _a string denoting the order of characters in the alien language_.<br />

<pre>
Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
Expected Space Compelxity: O(K)
</pre>

* Constraints: `1 ≤ N, M ≤ 300`<br />
`1 ≤ K ≤ 26`<br />
`1 ≤ Length of words ≤ 50`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class graph {
  public:
    int V;
    list<int> *adj;

    graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addedge(int v, int u) { adj[v].push_back(u); }
};
class Solution{
    public:
    void dictorder(string str1, string str2, graph *g, int *exist) {
        int n1 = str1.size();
        int n2 = str2.size();
    
        for (int i = 0; i < n1; i++) exist[(int)str1[i]] = 1;
        for (int i = 0; i < n2; i++) exist[(int)str2[i]] = 1;
    
        int i = 0;
        while (i < n1 && i < n2) {
            if (str1[i] != str2[i]) {
                g->addedge((int)str1[i], (int)str2[i]);
                return;
            }
            i++;
        }
    }
    
    void topsort(list<int> *adj, bool *visited, stack<char> &st, int v,
                 int *exist) {
        if (exist[v]) {
            visited[v] = true;
            for (auto u : adj[v])
                if (!visited[u]) topsort(adj, visited, st, u, exist);
            st.push((char)v);
        }
    }
    
    string findOrder(string dict[], int N, int K) {
        graph *g = new graph(256);
        int exist[256] = {0};
        for (int i = 1; i < N; i++) {
            dictorder(dict[i - 1], dict[i], g, exist);
        }
    
        bool visited[256] = {0};
        stack<char> st;
        for (int i = 0; i < 256; i++) {
            if (!visited[i]) topsort(g->adj, visited, st, i, exist);
        }
    
        string final = "";
        while (!st.empty()) {
            final += st.top();
            st.pop();
        }
    
        return final;
    }
};

string order;
bool f(string a, string b){
    int p1 = 0, p2 = 0;
    for(int i = 0;i<min(a.size(), b.size()) and p1 == p2; i++){
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }
    if(p1 == p2 and a.size() != b.size())return a.size() < b.size();
    return p1<p2;
}

int main(){
    int t; cin>>t;
    while(t--){
        int N, K; cin>>N>>K;
        string dict[N];
        for(int i = 0;i<N;i++)cin>>dict[i];
        Solution ob;
        string ans = ob.findOrder(dict, N, K);
        order = "";
        for(int i = 0;i<ans.size();i++)order += ans[i];

        string temp[N];
        std::copy(dict, dict+N, temp);

        bool f = true;
        for(int i = 0;i<N;i++){
            if(dict[i] != temp[i])f = false;
        }

        if(f)cout<<1;
        else cout<<0;
        cout<<endl;
    }
}
```







<br /><br /><br />
## Problem 18:
**[Kruskal’s Minimum Spanning Tree Algorithm | Greedy Algo](https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/)**<br />
**What is a Spanning Tree?**<br />
A Spanning tree is a subset to a connected graph `G`, where all the edges are connected, i.e, we can traverse to any edge from a particular edge with or without intermediates. Also, a spanning tree must not have any cycle in it. Thus we can say that if there are `n` vertices in a connected graph then the `no. of edges` that a spanning tree may have is `n-1`.<br />

**What is Minimum Spanning Tree?**<br /> 
Given a connected and **undirected graph**, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. A single graph can have many different spanning trees. A `minimum spanning tree (MST)` or minimum weight spanning tree for a weighted, connected, undirected graph is a spanning tree with a weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.<br />

**How many edges does a minimum spanning tree has?**<br /> 
A **minimum spanning tree** has `(V – 1)` edges where V is the number of vertices in the given graph.<br />

Below are the steps for finding `MST` using **Kruskal’s algorithm**<br />
<pre>
1. Sort all the edges in non-decreasing order of their weight. 
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it. 
3. Repeat step#2 until there are (V-1) edges in the spanning tree.
</pre>
The algorithm is a `Greedy Algorithm`. The Greedy Choice is to pick the smallest weight edge that does not cause a cycle in the `MST` constructed so far. Let us understand it with an example: Consider the below input graph.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210727035309/UntitledDiagram92.png"><br />
The graph contains `9` vertices and `14` edges. So, the minimum spanning tree formed will be having `(9 – 1) = 8` edges.<br />
<pre>
After sorting:

Weight   Src    Dest
1         7      6
2         8      2
2         6      5
4         0      1
4         2      5
6         8      6
7         2      3
7         7      8
8         0      7
8         1      2
9         3      4
10        5      4
11        1      7
14        3      5
</pre>
Now pick all edges one by one from the sorted list of edges<br />

1. Pick edge `7-6`: No cycle is formed, include it.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210727035707/UntitledDiagram100.png"><br />
2. Pick edge `8-2`: No cycle is formed, include it.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210727035650/UntitledDiagram99.png"><br />
3. Pick edge `6-5`: No cycle is formed, include it. <br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210727035627/UntitledDiagram98.png"><br />
4. Pick edge `0-1`: No cycle is formed, include it. <br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210727035604/UntitledDiagram97.png"><br />
5. Pick edge `2-5`: No cycle is formed, include it.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210727035542/UntitledDiagram96.png"><br />
6. Pick edge `8-6`: Since including this edge results in the cycle, discard it.<br />
7. Pick edge `2-3`: No cycle is formed, include it. <br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210727035519/UntitledDiagram95.png"><br />
8. Pick edge `7-8`: Since including this edge results in the cycle, discard it.<br />
9. Pick edge `0-7`: No cycle is formed, include it. <br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210727035450/UntitledDiagram94.png"><br />
10. Pick edge `1-2`: Since including this edge results in the cycle, discard it.<br />
11. Pick edge `3-4`: No cycle is formed, include it. <br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20210727035418/UntitledDiagram93.png"><br />
Since the number of edges included equals `(V – 1)`, the algorithm stops here.<br />

<br />Below is the implementation of the above idea:<br />
```cpp
#include <bits/stdc++.h>
using namespace std;
// DSU data structure
// path compression + rank by union

class DSU {
	int* parent;
	int* rank;

public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find function
	int find(int i)
	{
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}
	// union function
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

class Graph {
	vector<vector<int> > edgelist;
	int V;

public:
	Graph(int V) { this->V = V; }

	void addEdge(int x, int y, int w)
	{
		edgelist.push_back({ w, x, y });
	}

	void kruskals_mst()
	{
		// 1. Sort all edges
		sort(edgelist.begin(), edgelist.end());

		// Initialize the DSU
		DSU s(V);
		int ans = 0;
		cout << "Following are the edges in the ""constructed MST"<< endl;
		for (auto edge : edgelist) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			// take that edge in MST if it does form a cycle
			if (s.find(x) != s.find(y)) {
				s.unite(x, y);
				ans += w;
				cout << x << " -- " << y << " == " << w << endl;
			}
		}
		cout << "Minimum Cost Spanning Tree: " << ans;
	}
};
int main()
{
	/* Let us create following weighted graph
				10
			   0--------1
			   | \	    |
			  6|  5\    |15
			   |	 \  |
			   2--------3
				4	 */
	Graph g(4);
	g.addEdge(0, 1, 10);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);
	g.addEdge(2, 0, 6);
	g.addEdge(0, 3, 5);

	// int n, m;
	// cin >> n >> m;

	// Graph g(n);
	// for (int i = 0; i < m; i++)
	// {
	//	 int x, y, w;
	//	 cin >> x >> y >> w;
	//	 g.addEdge(x, y, w);
	// }

	g.kruskals_mst();
	return 0;
}
```
Output<br />
<pre>
Following are the edges in the constructed MST
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
Minimum Cost Spanning Tree: 19
</pre>
<pre>
Time Complexity: O(ElogE) or O(ElogV). 
Sorting of edges takes O(ELogE) time. 
After sorting, we iterate through all edges and apply the find-union algorithm. 
The find and union operations can take at most O(LogV) time. 
So overall complexity is O(ELogE + ELogV) time. The value of E can be at most O(V2), so O(LogV) is O(LogE) the same. 
Therefore, the overall time complexity is O(ElogE) or O(ElogV)
</pre>






<br /><br /><br />
## Problem 19:
**[Prim’s Minimum Spanning Tree (MST) | Greedy Algo](https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/)**<br />
Like `Kruskal’s algorithm`, `Prim’s algorithm` is also a **Greedy algorithm**. It starts with an empty spanning tree. The idea is to maintain two sets of vertices. The first set contains the **vertices already included in the MST**, the other set contains the **vertices not yet included**. At every step, it considers all the edges that connect the two sets and picks the `minimum weight edge` from these edges. After picking the edge, it moves the other endpoint of the edge to the set containing MST. <br />
A group of edges that connects two sets of vertices in a graph is called cut in graph theory. So, at every step of **Prim’s algorithm**, we find a cut (of two sets, one contains the vertices already included in `MST` and the other contains the rest of the vertices), pick the `minimum weight edge` from the cut, and include this vertex to `MST` Set (the set that contains already included vertices).<br />
<br />**How does Prim’s Algorithm Work?**<br />
The idea behind **Prim’s algorithm** is simple, a spanning tree means all vertices must be connected. So the two `disjoint subsets` (discussed above) of vertices must be connected to make a Spanning Tree. And they must be connected with the **minimum** weight edge to make it a `Minimum Spanning Tree`.<br />
<br />Algorithm <br />

1) Create a set **mstSet** that keeps track of vertices already included in `MST`.<br />
2) Assign a key value to all vertices in the input graph. Initialize all key values as `INFINITE`. Assign the key value as `0` for the first vertex so that it is picked first.<br /> 
3) While **mstSet** doesn’t include all vertices<br /> 
	….a) Pick a vertex `u` which is not there in **mstSet** and has a **minimum** key value.<br /> 
	….b) Include `u` to `mstSet`. <br />
	….c) Update key value of all adjacent vertices of `u`. To update the key values, iterate through all adjacent vertices. For every adjacent vertex `v`, if the weight of edge `u-v` is less than the previous key value of `v`, update the key value as the weight of `u-v`.<br />
	
The idea of using key values is to pick the **minimum weight edge** from cut. The key values are used only for vertices that are not yet included in **MST**, the key value for these vertices indicates the **minimum weight edges** connecting them to the set of vertices included in `MST`. <br />

Let us understand with the following example:<br />
<img src = "https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg"><br />
The set `mstSet` is initially empty and keys assigned to vertices are `{0, INF, INF, INF, INF, INF, INF, INF}` where **INF** indicates **infinite**. Now pick the **vertex** with the **minimum** key value. The vertex `0` is picked, include it in `mstSet`. So `mstSet` becomes `{0}`. After including to `mstSet`, update key values of adjacent vertices. Adjacent vertices of `0` are `1` and `7`. The key values of `1` and `7` are updated as `4` and `8`. Following subgraph shows vertices and their key values, only the vertices with finite key values are shown. The vertices included in `MST` are shown in **green color**.<br />
<img src = "https://www.geeksforgeeks.org/wp-content/uploads/MST1.jpg"><br />
Pick the vertex with **minimum** key value and not already included in **MST (not in mstSET)**. The vertex `1` is picked and added to **mstSet**. So **mstSet** now becomes `{0, 1}`. Update the key values of adjacent vertices of `1`. The key value of vertex `2` becomes `8`.<br />
<img src = "https://www.geeksforgeeks.org/wp-content/uploads/MST2.jpg"><br />
Pick the vertex with **minimum** key value and not already included in **MST (not in mstSET)**. We can either pick vertex `7` or vertex `2`, let vertex `7` is picked. So **mstSet** now becomes `{0, 1, 7}`. Update the key values of adjacent vertices of `7`. The key value of vertex `6` and `8` becomes finite (`1` and `7` respectively).<br />
<img src = "https://www.geeksforgeeks.org/wp-content/uploads/MST3.jpg"><br />
Pick the vertex with **minimum** key value and not already included in `MST (not in mstSET)`. Vertex `6` is picked. So mstSet now becomes `{0, 1, 7, 6}`. Update the key values of adjacent vertices of `6`. The key value of vertex `5` and `8` are updated.<br />
<img src = "https://www.geeksforgeeks.org/wp-content/uploads/MST4.jpg"><br />
We repeat the above steps until `mstSet` includes all vertices of given graph. Finally, we get the following graph.<br />
<img src = "https://www.geeksforgeeks.org/wp-content/uploads/MST5.jpg"><br />
<br />**How to implement the above algorithm?**<br />
We use a boolean array `mstSet[]` to represent the set of vertices included in `MST`. If a value `mstSet[v]` is `true`, then vertex `v` is included in `MST`, otherwise not. Array `key[]` is used to store key values of all vertices. Another array `parent[]` to store indexes of parent nodes in **MST**. The parent array is the output array which is used to show the constructed **MST**. <br />
```cpp
// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 5

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
	// Array to store constructed MST
	int parent[V];
	
	// Key values used to pick minimum weight edge in cut
	int key[V];
	
	// To represent set of vertices included in MST
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.
	// Make key 0 so that this vertex is picked as first vertex.
	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum key vertex from the
		// set of vertices not yet included in MST
		int u = minKey(key, mstSet);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of
		// the adjacent vertices of the picked vertex.
		// Consider only those vertices which are not
		// yet included in MST
		for (int v = 0; v < V; v++)

			// graph[u][v] is non zero only for adjacent vertices of m
			// mstSet[v] is false for vertices not yet included in MST
			// Update the key only if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the constructed MST
	printMST(parent, graph);
}

// Driver code
int main()
{
	/* Let us create the following graph
		2   3
	    (0)--(1)--(2)
	    |    / \    |
	   6| 8/    \5  |7
	    | /      \  |
	    (3)--------(4)
		  9	 */
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
			    { 2, 0, 3, 8, 5 },
			    { 0, 3, 0, 0, 7 },
			    { 6, 8, 0, 0, 9 },
			    { 0, 5, 7, 9, 0 } };

	// Print the solution
	primMST(graph);

	return 0;
}
```
Output: <br />
<pre>
Edge   Weight
0 - 1    2
1 - 2    3
0 - 3    6
1 - 4    5
</pre>
<pre>
The Time Complexity of the above program is O(V^2). 
If the input graph is represented using adjacency list, then the time complexity of Prim’s algorithm 
can be reduced to O(E log V) with the help of a binary heap.  
In this implementation, we are always considering the spanning tree to start from the root of the graph, 
and this is the basic difference between Kruskal’s Minimum Spanning Tree and Prim’s Minimum Spanning tree.
</pre>






<br /><br /><br />
## Problem 20:
**[Total number of Spanning Trees in a Graph](https://www.geeksforgeeks.org/total-number-spanning-trees-graph/)**<br />
If a graph is a complete graph with `n` vertices, then total number of spanning trees is `n^(n-2)` where `n` is the number of nodes in the graph. In complete graph, the task is equal to counting different labeled trees with `n` nodes for which have `Cayley’s formula`.<br />
<br />**What if graph is not complete?**<br />
Follow the given procedure:<br />

 * STEP 1: Create Adjacency Matrix for the given graph. <br />
 * STEP 2: Replace all the diagonal elements with the degree of nodes. For eg. element at `(1,1)` position of adjacency matrix will be replaced by the degree of node `1`, element at `(2,2)` position of adjacency matrix will be replaced by the degree of node `2`, and so on.<br /> 
 * STEP 3: Replace all non-diagonal `1`’s with `-1`. <br />
 * STEP 4: Calculate co-factor for any element. <br />
 * STEP 5: The cofactor that you get is the total number of spanning tree for that graph. <br />

Consider the following graph:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Kirchoff-formula.jpg"><br />
Adjacency Matrix for the above graph will be as follows:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/matrix_.png"><br />
After applying STEP 2 and STEP 3, adjacency matrix will look like<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/matrix_2-1.png"><br />
The co-factor for `(1, 1)` is `8`. Hence total no. of spanning tree that can be formed is `8`.<br />
**NOTE:** Co-factor for all the elements will be same. Hence we can compute co-factor for any element of the matrix. This method is also known as `Kirchhoff’s Theorem`. It can be applied to complete graphs also.<br />






<br /><br /><br />
## Problem 21:
**[Implement Bellman Ford Algorithm / Negative weight cycle](https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1)**<br />
Given a weighted directed graph with `n` nodes and `m` edges. Nodes are labeled from `0` to `n-1`, the task is to check if it contains a negative weight cycle or not.
**Note:** `edges[i]` is defined as `u`, `v` and `weight`.<br />
 
>Example 1:<br />
Input: n = 3, edges = {{0,1,-1},{1,2,-2},{2,0,-3}}<br />
Output: 1<br />
Explanation: The graph contains negative weight cycle as 0->1->2->0 with weight -1,-2,-3.<br />

>Example 2:<br />
Input: n = 3, edges = {{0,1,-1},{1,2,-2},{2,0,3}}<br />
Output: 0<br />
Explanation: The graph does not contain any negative weight cycle. <br />

**Your Task:**<br />
You don't need to read or print anyhting. Your task is to complete the function `isNegativeWeightCycle()` which takes `n` and edges as input paramater and returns `1` if graph contains negative weight cycle otherwise returns `0`.<br />
 
<pre>
Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(n)
</pre>

Constraints: `1 <= n <= 100`<br />
`1 <= m <= n*(n-1)`, where `m` is the total number of Edges in the directed graph.<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
struct edge{
    int a, b, cost;
};
public:
    int isNegativeWeightCycle(int n, vector<vector<int>>edges){
        vector<edge>Edges;
        for(auto i: edges){
            edge p;
            p.a = i[0];
            p.b = i[1];
            p.cost = i[2];
            Edges.push_back(p);
        }
        int INF = INT_MAX;
        vector<int> d(n);
        vector<int> p(n, -1);
        int x;
        for (int i = 0; i < n; ++i) {
            x = -1;
            for (edge e : Edges) {
                if (d[e.a] + e.cost < d[e.b]) {
                    d[e.b] = d[e.a] + e.cost;
                    p[e.b] = e.a;
                    x = e.b;
                }
            }
        }       
        if(x == -1)return 0;
        return 1;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<vector<int>>edges;
        for(int i = 0;i<m;i++){
            int x, y, z; cin>>x>>y>>z;
            edges.push_back({x, y, z});
        }
        Solution ob;
        int ans = ob.isNegativeWeightCycle(n, edges);
        cout<<ans<<endl;
    }
}
```






<br /><br /><br />
## Problem 22:
**[Implement Floyd warshallAlgorithm](https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1)**<br />
The problem is to find the **shortest** distances between every pair of vertices in a given edge-weighted directed Graph. The Graph is represented as an `adjacency matrix`, and the matrix denotes the `weight of the edges` (if it exists) else `-1`.<br />
Do it in-place.<br />
 
>Example 1:<br />
Input: matrix = {{0,25},{-1,0}}<br />
Output: {{0,25},{-1,0}}<br />
Explanation: The shortest distance between every pair is already given(if it exists).<br />

>Example 2:<br />
Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}<br />
Output: {{0,1,7},{1,0,6},{-1,-1,0}}<br />
Explanation: We can reach 3 from 1 as 1->2->3 and the cost will be 1+6=7 which is less than 43.<br />

**Your Task:**<br />
You don't need to read, return or print anything. Your task is to complete the function `shortest_distance()` which takes the matrix as input parameter and modify the distances for every pair in-place.<br />
 
<pre>
Expected Time Complexity: O(n^3)
Expected Space Complexity: O(1)
</pre>

* Constraints: `1 <= n <= 100`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void shortest_distance(vector<vector<int>>&matrix){
        int INF = INT_MAX;
        int n = matrix.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == -1)
                    matrix[i][j] = INF;
            }
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][k] < INF && matrix[k][j] < INF and matrix[i][k] + matrix[k][j] < INF)
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]); 
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] >= INF)
                    matrix[i][j] = -1;
            }
        }
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>>matrix(n, vector<int>(n, -1));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++)cin>>matrix[i][j];
        }
        Solution ob;
        ob.shortest_distance(matrix);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
```







<br /><br /><br />
## Problem 23:
**[Travelling Salesman Problem | (Naive and Dynamic Programming)](https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/)**<br />
**Travelling Salesman Problem (TSP):**<br />
Given a set of cities and the distance between every pair of cities, the problem is to find the `shortest possible route` that visits every city exactly once and returns to the `starting point`. **Note** the `difference between Hamiltonian Cycle and TSP`. The `Hamiltonian cycle` problem is to find `if there exists a tour` that visits every city exactly once. Here we know that Hamiltonian Tour exists (because the graph is complete) and in fact, many such tours exist, the problem is to find a `minimum weight Hamiltonian Cycle`.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Euler12.png"><br />
For example, consider the graph shown in the figure on the right side. A `TSP tour` in the graph is `1-2-4-3-1`. The cost of the tour is `10+25+30+15` which is `80`. The problem is a famous `NP-hard problem`. There is no polynomial-time know solution for this problem. The following are different solutions for the traveling salesman problem. <br />
<br />Naive Solution:<br />

1) Consider city `1` as the starting and ending point.<br />
2) Generate all `(n-1)!` Permutations of cities.<br /> 
3) Calculate the cost of every permutation and keep track of the `minimum cost permutation`.<br /> 
4) Return the permutation with minimum cost.<br /> 

<pre>
Time Complexity: Θ(n!) 
</pre>
<br />**Dynamic Programming:**<br />
Let the given set of vertices be `{1, 2, 3, 4,….n}`. Let us consider `1` as starting and ending point of output. For every other vertex `I` (other than 1), we find the **minimum cost path** with `1` as the starting point, `I` as the **ending point**, and all vertices appearing exactly once. Let the cost of this `path cost (i)`, and the cost of the corresponding Cycle would `cost (i) + dist(i, 1)` where `dist(i, 1)` is the distance from `I` to `1`. Finally, we return the minimum of all `[cost(i) + dist(i, 1)]` values. This looks simple so far.<br /> 
**Now the question is how to get `cost(i)`?**<br />
To calculate the `cost(i)` using Dynamic Programming, we need to have some recursive relation in terms of sub-problems.<br /> 
Let us define a term `C(S, i)` be the cost of the minimum cost path visiting each vertex in set S exactly once, starting at `1` and ending at `i`. We start with all subsets of size `2` and calculate `C(S, i)` for all subsets where `S` is the subset, then we calculate `C(S, i)` for all subsets `S` of size `3` and so on. Note that `1` must be present in every subset.<br />
<pre>
If size of S is 2, then S must be {1, i},
 C(S, i) = dist(1, i) 
Else if size of S is greater than 2.
 C(S, i) = min { C(S-{i}, j) + dis(j, i)} where j belongs to S, j != i and j != 1.
</pre>
Below is the **dynamic programming** solution for the problem using `top down recursive+memoized approach`:-<br />
For maintaining the subsets we can use the bitmasks to represent the remaining nodes in our subset. Since bits are faster to operate and there are only few nodes in graph, bitmasks is better to use.<br />
For example: –  <br />
`10100` represents node `2` and node `4` are left in set to be processed<br />
`010010` represents node `1` and `4` are left in subset.<br />
**NOTE:-** ignore the `0th` bit since our graph is **1-based**<br />
```cpp
#include <iostream>
using namespace std;

// there are four nodes in example graph (graph is 1-based)
const int n = 4;
// give appropriate maximum to avoid overflow
const int MAX = 1000000;

// dist[i][j] represents shortest distance to go from i to j
// this matrix can be calculated for any given graph using
// all-pair shortest path algorithms
int dist[n + 1][n + 1] = {{ 0, 0, 0, 0, 0 }, 
                          { 0, 0, 10, 15, 20 },
	                  { 0, 10, 0, 25, 25 }, 
			  { 0, 15, 25, 0, 30 },
	                  { 0, 20, 25, 30, 0 },
};

// memoization for top down recursion
int memo[n + 1][1 << (n + 1)];

int fun(int i, int mask)
{
	// base case
	// if only ith bit and 1st bit is set in our mask,
	// it implies we have visited all other nodes already
	if (mask == ((1 << i) | 3))
		return dist[1][i];
	// memoization
	if (memo[i][mask] != 0)
		return memo[i][mask];

	int res = MAX; // result of this sub-problem

	// we have to travel all nodes j in mask and end the
	// path at ith node so for every node j in mask,
	// recursively calculate cost of travelling all nodes in
	// mask except i and then travel back from node j to
	// node i taking the shortest path take the minimum of
	// all possible j nodes

	for (int j = 1; j <= n; j++)
		if ((mask & (1 << j)) && j != i && j != 1)
			res = std::min(res, fun(j, mask & (~(1 << i))) 	+ dist[j][i]);
	return memo[i][mask] = res;
}
// Driver program to test above logic
int main()
{
	int ans = MAX;
	for (int i = 1; i <= n; i++)
		// try to go from node 1 visiting all nodes in
		// between to i then return from i taking the
		// shortest route to 1
		ans = std::min(ans, fun(i, (1 << (n + 1)) - 1) 	+ dist[i][1]);

	printf("The cost of most efficient tour = %d", ans);

	return 0;
}
```
Output<br />
<pre>
The cost of most efficient tour = 80
</pre>
<pre>
For a set of size n, we consider n-2 subsets each of size n-1 such that all subsets don’t have nth in them. 
Using the above recurrence relation, we can write a dynamic programming-based solution. 
There are at most O(n*2n) subproblems, and each one takes linear time to solve. 
The total running time is therefore O(n2*2n). The time complexity is much less than O(n!) but still exponential. 
The space required is also exponential. So this approach is also infeasible even for a slightly higher number of vertices
</pre>







<br /><br /><br />
## Problem 24:
**[Graph Coloring](https://www.geeksforgeeks.org/graph-coloring-applications/)**<br />
Graph coloring problem is to **assign** colors to certain elements of a graph subject to certain `constraints`. <br />
`Vertex coloring` is the most common graph coloring problem. The problem is, given `m` colors, find a way of coloring the `vertices of a graph` such that **no two adjacent vertices are colored using same color**. The other graph coloring problems like `Edge Coloring` (No vertex is incident to two edges of same color) and `Face Coloring` (`Geographical Map Coloring`) can be transformed into vertex coloring. <br />
`**Chromatic Number:**` The smallest number of colors needed to color a graph `G` is called its `chromatic number`. For example, the following can be colored minimum `2` colors. <br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/GraphColoring.png"><br />
The problem to find chromatic number of a given graph is `NP Complete`.<br />
<br /><br />**Applications of Graph Coloring:**<br />
The graph coloring problem has huge number of applications.<br />

1) `Making Schedule or Time Table`: Suppose we want to make am exam schedule for a university. We have list different subjects and students enrolled in every subject. Many subjects would have common students (of same batch, some backlog students, etc). **How do we schedule the exam so that no two exams with a common student are scheduled at same time?** **How many minimum time slots are needed to schedule all exams?** This problem can be represented as a graph where every vertex is a subject and an edge between two vertices mean there is a common student. So this is a graph coloring problem where minimum number of time slots is equal to the chromatic number of the graph.<br />
2) `Mobile Radio Frequency Assignment`: When frequencies are assigned to towers, frequencies assigned to all towers at the same location must be different. How to assign frequencies with this constraint? **What is the `minimum number` of frequencies needed?** This problem is also an instance of graph coloring problem where every tower represents a vertex and an edge between two towers represents that they are in range of each other. <br />
3) `Sudoku:` Sudoku is also a variation of Graph coloring problem where every cell represents a vertex. There is an edge between two vertices if they are in same row or same column or same block.<br />
4) `Register Allocation:` In compiler optimization, register allocation is the process of assigning a large number of target program variables onto a small number of CPU registers. This problem is also a graph coloring problem.<br />
5) `Bipartite Graphs:` We can check if a graph is Bipartite or not by coloring the graph using two colors. If a given graph is 2-colorable, then it is Bipartite, otherwise not.<br />
6) `Map Coloring`: Geographical maps of countries or states where no two adjacent cities cannot be assigned same color. Four colors are sufficient to color any map according to four colour theorem.<br />
	
	





<br /><br /><br />
## Problem 25:
**[909. Snakes and Ladders](https://leetcode.com/problems/snakes-and-ladders/)**<br />
You are given an `n x n` integer matrix board where the cells are labeled from `1` to `n^2` in a Boustrophedon style starting from the bottom left of the board (i.e. `board[n - 1][0]`) and alternating direction each row.<br />

You start on square `1` of the board. In each move, starting from square `curr`, do the following:<br />

 * Choose a destination square next with a label in the range `[curr + 1, min(curr + 6, n2)]`.<br />
This choice simulates the result of a standard 6-sided die roll: i.e., there are always **at most** 6 destinations, regardless of the size of the board.<br />
 * If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.<br />
 * The game ends when you reach the square `n^2`.<br />
 
A board square on row `r` and column `c` has a snake or ladder if `board[r][c] != -1`. The destination of that snake or ladder is `board[r][c]`. Squares `1` and `n^2` do not have a snake or ladder.<br />
**Note** that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.<br />

 * For example, suppose the board is `[[-1,4],[-1,3]]`, and on the first move, your destination square is `2`. You follow the ladder to square `3`, but do not follow the subsequent ladder to `4`.<br />
 
Return _the least number of moves required to reach the square n^2_. If it is not possible to reach the square, return `-1`.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2018/09/23/snakes.png"><br />
Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]<br />
Output: 4<br />
Explanation: <br />
In the beginning, you start at square 1 (at row 5, column 0). You decide to move to square 2 and must take the ladder to square 15.<br />
You then decide to move to square 17 and must take the snake to square 13. You then decide to move to square 14 and must take the ladder to square 35.<br />
You then decide to move to square 36, ending the game. This is the lowest possible number of moves to reach the last square, so return 4.<br />

>Example 2:<br />
Input: board = [[-1,-1],[-1,3]]<br />
Output: 1<br />

* Constraints: `n == board.length == board[i].length`<br />
`2 <= n <= 20`<br />
`grid[i][j]` is either `-1` or in the range `[1, n^2]`.<br />
The squares labeled `1` and `n^2` do not have any ladders or snakes.<br />

```cpp
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int, int> mp;
        int n = board.size();
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] != -1) {
                    int val;
                    if((n-i)%2 != 0) val = (n-i-1)*n + j + 1;
                    else val = (n-i-1)*n + n - j;
                    mp[val] = board[i][j];
                }
            }
        }
        queue<pair<int, int>> q;
        vector<int> visited(n*n+1, false);
        q.push({1, 0});
        while(!q.empty()) {
            int node = q.front().first;
            int moves = q.front().second;
            q.pop();
            if(node == n*n) return moves;
            if(visited[node]) continue;
            visited[node] = true;
            for(int k = 1; k <= 6; k++) {
                if(node+k > n*n) continue;
                int x = node + k;
                if(mp.find(x) != mp.end()) x = mp[x];
                q.push({x, moves+1});
            }
        }
        return -1;
    }
};
```






<br /><br /><br />
## Problem 26:
**[Bridges in a graph](https://www.geeksforgeeks.org/bridge-in-a-graph/)**<br />
An edge in an `undirected connected graph` is a bridge if removing it disconnects the graph. For a disconnected undirected graph, definition is similar, a bridge is an edge removing which `increases` number of disconnected components.<br /> 
Like `Articulation Points`, bridges represent vulnerabilities in a connected network and are useful for designing reliable networks. For example, in a wired computer network, an articulation point indicates the **critical computers** and a bridge indicates the `critical wires or connections`.<br />
Following are some example graphs with bridges highlighted with red color.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Bridge1.png"><br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Bridge2-300x176.png"><br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Bridge2-300x176.png"><br />
<br />`Naive Approach:` A simple approach is to **one by one remove all edges** and see if removal of an edge causes disconnected graph. Following are steps of simple approach for connected graph.<br />
For every edge `(u, v)`, do following :<br />

 * Remove `(u, v)` from graph<br /> 
 * See if the graph remains connected (We can either use `BFS` or `DFS`)<br /> 
 * Add `(u, v)` back to the graph.<br />

<pre>
Time Complexity: O(E*(V+E)) for a graph represented using adjacency list.
</pre>
**Efficient Approach:**The idea is similar to `O(V+E)` algorithm for Articulation Points. We do `DFS traversal` of the given graph. In `DFS tree` an edge `(u, v)` **(u is parent of v in DFS tree)** is bridge if there does not exist any other alternative to reach `u` or an ancestor of `u` from subtree rooted with `v`.<br />
The value `low[v]` indicates earliest visited vertex reachable from subtree rooted with `v`. The condition for an edge `(u, v)` to be a bridge is, `“low[v] > disc[u]”`.<br />
Following are the implementations of above approach.<br />
```cpp
// A C++ program to find bridges in a given undirected graph
#include<iostream>
#include <list>
#define NIL -1
using namespace std;

// A class that represents an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
	void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]);
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	void bridge(); // prints all bridges
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); // Note: the graph is undirected
}

// A recursive function that finds and prints bridges using
// DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[])
{
	// A static variable is used for simplicity, we can
	// avoid use of static variable by passing a pointer.
	static int time = 0;

	// Mark the current node as visited
	visited[u] = true;

	// Initialize discovery time and low value
	disc[u] = low[u] = ++time;

	// Go through all vertices adjacent to this
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i; // v is current adjacent of u

		// If v is not visited yet, then recur for it
		if (!visited[v])
		{
			parent[v] = u;
			bridgeUtil(v, visited, disc, low, parent);

			// Check if the subtree rooted with v has a
			// connection to one of the ancestors of u
			low[u] = min(low[u], low[v]);

			// If the lowest vertex reachable from subtree
			// under v is below u in DFS tree, then u-v
			// is a bridge
			if (low[v] > disc[u])
			cout << u <<" " << v << endl;
		}

		// Update low value of u for parent function calls.
		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

// DFS based function to find all bridges. It uses recursive
// function bridgeUtil()
void Graph::bridge()
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];

	// Initialize parent and visited arrays
	for (int i = 0; i < V; i++)
	{
		parent[i] = NIL;
		visited[i] = false;
	}

	// Call the recursive helper function to find Bridges
	// in DFS tree rooted with vertex 'i'
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			bridgeUtil(i, visited, disc, low, parent);
}

// Driver program to test above function
int main()
{
	// Create graphs given in above diagrams
	cout << "\nBridges in first graph \n";
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.bridge();

	cout << "\nBridges in second graph \n";
	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.bridge();

	cout << "\nBridges in third graph \n";
	Graph g3(7);
	g3.addEdge(0, 1);
	g3.addEdge(1, 2);
	g3.addEdge(2, 0);
	g3.addEdge(1, 3);
	g3.addEdge(1, 4);
	g3.addEdge(1, 6);
	g3.addEdge(3, 5);
	g3.addEdge(4, 5);
	g3.bridge();

	return 0;
}
```
Output<br />
<pre>
Bridges in first graph 
3 4
0 3

Bridges in second graph 
2 3
1 2
0 1

Bridges in third graph 
1 6
</pre>
<pre>
Time Complexity: The above function is simple DFS with additional arrays. 
So time complexity is same as DFS which is O(V+E) for adjacency list representation of graph.
Auxiliary Space: O(B^M) where B is the maximum branching factor of the search tree and M is the maximum depth of the state space.
</pre>





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
