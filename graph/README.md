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
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Bridge3.png"><br />
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
**[Strongly Connected Components (Kosaraju's Algo)](https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1)**<br />
Given a `Directed Graph` with `V` vertices (`Numbered from 0 to V-1`) and `E` edges, Find the number of strongly connected components in the graph.<br />

>Example 1:<br />
Input:<br />
<img src = "https://user-images.githubusercontent.com/71781982/184537150-9cae5dbf-c2ec-4f80-954b-70af56c7e9ae.png"><br />
Output:<br />
3<br />
Explanation:<br />
<img src = "https://user-images.githubusercontent.com/71781982/184537151-57b37a41-adfb-4011-8aee-e81d00149d54.png"><br />
We can clearly see that there are 3 Strongly Connected Components in the Graph<br />

>Example 2:<br />
Input:<br />
<img src = "https://user-images.githubusercontent.com/71781982/184537157-6af86acd-59a4-43f7-9af9-2150c72e5d2f.png"><br />
Output:<br />
1<br />
Explanation:<br />
All of the nodes are connected to each other. So, there's only one SCC.<br />

**Your Task:**<br />
You don't need to read input or print anything. Your task is to complete the function `kosaraju()` which takes the number of vertices `V` and `adjacency list` of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.<br />

<pre>
Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).
</pre>

* Constraints: `1 ≤ V ≤ 5000`<br />
`0 ≤ E ≤ (V*(V-1))`<br />
`0 ≤ u, v ≤ N-1`<br />
Sum of `E` over all testcases will not exceed `25*10^6`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function that creates transpose of the adjacency list.
    void transpose(int V, vector<int> adj[], vector<int> transpose_adj[]) 
    {
        for (int u = 0; u < V; u++)
            for (auto v : adj[u])
                transpose_adj[v].push_back(u);
    }
    
    stack<int> s;
    void dfs(vector<int> adj[], bool *visited, int u) 
    {
        //marking the current node as visited.
        visited[u] = true;
        
        //iterating over adjacent vertices and calling function 
        //recursively if any adjacent vertex is not visited.
        for (auto v : adj[u])
        {
            if (visited[v] == 0)
                dfs(adj, visited, v);
        }
    }
    
    void fillorder(vector<int> adj[], bool *visited, int u)
    {
        //marking the current node as visited.
        visited[u] = true;
        
        //iterating over adjacent vertices and calling function 
        //recursively if any adjacent vertex is not visited.
        for (auto v : adj[u])
            if (visited[v] == 0)
                fillorder(adj, visited, v);
        
        //pushing vertex into the stack.
        s.push(u);
    }
    
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //using boolean list to mark visited nodes and currently 
        //marking all the nodes as false.
        bool visited[V];
        memset(visited, 0, sizeof(visited));
        
        //filling vertices in stack according to their finishing times.
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                fillorder(adj, visited, i);
        
        //creating transpose of adjacency list.
        vector<int> transpose_adj[V];
        transpose(V, adj, transpose_adj);
    
        //marking all the nodes as not visited again.
        for (int i = 0; i < V; i++)
            visited[i] = false;
    
        int ans = 0;
        
        //now processing all vertices in order defined by stack.
        while (!s.empty()) 
        {
            //popping a vertex from stack.
            int temp = s.top();
            s.pop();
            
            //if vertex is not visited, we call dfs function 
            //and increment the counter.
            if (!visited[temp]) {
                dfs(transpose_adj, visited, temp);
                ans++;
            }
        }
        //returning the count.
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int V, E; cin>>V>>E;
        vector<int>adj[V];
        for(int i = 0;i<E;i++){
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
        }
        Solution ob;
        cout<<ob.kosaraju(V, adj)<<endl;
    }
}
```









<br /><br /><br />
## Problem 28:
**[Check whether a given graph is Bipartite or not](https://www.geeksforgeeks.org/bipartite-graph/)**<br />
A `Bipartite Graph` is a graph whose vertices can be divided into two independent sets, `U` and `V` such that every edge `(u, v)` either connects a `vertex` from `U` to `V` or a `vertex` from `V` to `U`. In other words, for every `edge (u, v)`, either `u` belongs to `U` and `v` to `V`, or `u` belongs to `V` and `v` to `U`. We can also say that there is **no edge that connects vertices of same set**.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/bipartitegraph-1.jpg"><br />
A `bipartite graph` is possible if the graph coloring is possible using `two` colors such that vertices in a set are colored with the **same color**. Note that it is possible to color a `cycle graph` with even cycle using two colors. For example, see the following graph.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/bipartitegraphfive.sixJPG.jpg"><br />
It is not possible to color a cycle graph with odd cycle using two colors.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/bipartitegraphfive.jpg"><br />
<br />**Algorithm to check if a graph is Bipartite:**<br />
One approach is to check whether the graph is `2-colorable` or not using `backtracking algorithm` `m coloring problem`.<br />
Following is a simple algorithm to find out whether a given graph is `Bipartite` or not using Breadth First Search (BFS).<br /> 

1. Assign `RED` color to the source vertex (putting into set `U`).<br /> 
2. Color all the neighbors with `BLUE` color (putting into set `V`). <br />
3. Color all neighbor’s neighbor with `RED` color (putting into set `U`). <br />
4. This way, assign color to all vertices such that it satisfies all the constraints of `m` way coloring problem where `m = 2`.<br /> 
5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with `2 vertices` (or graph is not Bipartite)<br />

```cpp
// C++ program to find out whether a
// given graph is Bipartite or not
#include <iostream>
#include <queue>
#define V 4

using namespace std;

// This function returns true if graph
// G[V][V] is Bipartite, else false
bool isBipartite(int G[][V], int src)
{
	// Create a color array to store colors
	// assigned to all vertices. Vertex
	// number is used as index in this array.
	// The value '-1' of colorArr[i]
	// is used to indicate that no color
	// is assigned to vertex 'i'. The value 1
	// is used to indicate first color
	// is assigned and value 0 indicates
	// second color is assigned.
	int colorArr[V];
	for (int i = 0; i < V; ++i)
		colorArr[i] = -1;

	// Assign first color to source
	colorArr[src] = 1;

	// Create a queue (FIFO) of vertex
	// numbers and enqueue source vertex
	// for BFS traversal
	queue <int> q;
	q.push(src);

	// Run while there are vertices
	// in queue (Similar to BFS)
	while (!q.empty())
	{
		// Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
		int u = q.front();
		q.pop();

		// Return false if there is a self-loop
		if (G[u][u] == 1)
		return false;

		// Find all non-colored adjacent vertices
		for (int v = 0; v < V; ++v)
		{
			// An edge from u to v exists and
			// destination v is not colored
			if (G[u][v] && colorArr[v] == -1)
			{
				// Assign alternate color to this adjacent v of u
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}

			// An edge from u to v exists and destination
			// v is colored with same color as u
			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}

	// If we reach here, then all adjacent
	// vertices can be colored with alternate color
	return true;
}

// Driver program to test above function
int main()
{
	int G[][V] = {{0, 1, 0, 1},
		      {1, 0, 1, 0},
		      {0, 1, 0, 1},
		      {1, 0, 1, 0}
	};

	isBipartite(G, 0) ? cout << "Yes" : cout << "No";
	return 0;
}
```
Output: <br />
<pre>
Yes
</pre>
<pre>
Time Complexity : O(V*V) as ajacency matrix is used for graph but can be made O(V+E) by using adjacency list
Space Complexity : O(V) due to queue and color vector.
</pre>
**The above algorithm works only if the graph is connected**. In above code, we always start with source `0` and assume that vertices are visited from it. One important observation is a `graph with no edges is also Bipartite`. Note that the Bipartite condition says all edges should be from one set to another.<br />
We can extend the above code to handle cases when a graph is not connected. The idea is repeatedly called above method for all not yet visited vertices.<br /> 
```cpp
// C++ program to find out whether
// a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>

using namespace std;

const int V = 4;

// This function returns true if
// graph G[V][V] is Bipartite, else false
bool isBipartiteUtil(int G[][V], int src, int colorArr[])
{
	colorArr[src] = 1;

	// Create a queue (FIFO) of vertex numbers a
	// nd enqueue source vertex for BFS traversal
	queue<int> q;
	q.push(src);

	// Run while there are vertices in queue (Similar to
	// BFS)
	while (!q.empty()) {
		// Dequeue a vertex from queue ( Refer
		// http://goo.gl/35oz8 )
		int u = q.front();
		q.pop();

		// Return false if there is a self-loop
		if (G[u][u] == 1)
			return false;

		// Find all non-colored adjacent vertices
		for (int v = 0; v < V; ++v) {
			// An edge from u to v exists and
			// destination v is not colored
			if (G[u][v] && colorArr[v] == -1) {
				// Assign alternate color to this
				// adjacent v of u
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}

			// An edge from u to v exists and destination
			// v is colored with same color as u
			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}

	// If we reach here, then all adjacent vertices can
	// be colored with alternate color
	return true;
}

// Returns true if G[][] is Bipartite, else false
bool isBipartite(int G[][V])
{
	// Create a color array to store colors assigned to all
	// vertices. Vertex/ number is used as index in this
	// array. The value '-1' of colorArr[i] is used to
	// indicate that no color is assigned to vertex 'i'.
	// The value 1 is used to indicate first color is
	// assigned and value 0 indicates second color is
	// assigned.
	int colorArr[V];
	for (int i = 0; i < V; ++i)
		colorArr[i] = -1;

	// This code is to handle disconnected graph
	for (int i = 0; i < V; i++)
		if (colorArr[i] == -1)
			if (isBipartiteUtil(G, i, colorArr) == false)
				return false;

	return true;
}

// Driver code
int main()
{
	int G[][V] = { { 0, 1, 0, 1 },
		       { 1, 0, 1, 0 },
		       { 0, 1, 0, 1 },
		       { 1, 0, 1, 0 } };

	isBipartite(G) ? cout << "Yes" : cout << "No";
	return 0;
}
```
Output: <br />
<pre>
Yes
</pre>
<pre>
Time Complexity of the above approach is same as that Breadth First Search. 
In above implementation is O(V^2) where V is number of vertices. 
If graph is represented using adjacency list, then the complexity becomes O(V+E).
</pre>
**If Graph is represented using Adjacency List .**Time Complexity will be `O(V+E)`.<br />
**Works for connected as well as disconnected graph**.<br />
```cpp
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<int> adj[])
{
	// vector to store colour of vertex
	// assigning all to -1 i.e. uncoloured
	// colours are either 0 or 1
	// for understanding take 0 as red and 1 as blue
	vector<int> col(V, -1);

	// queue for BFS storing {vertex , colour}
	queue<pair<int, int> > q;

	//loop incase graph is not connected
	for (int i = 0; i < V; i++) {
	
	//if not coloured
		if (col[i] == -1) {
		
		//colouring with 0 i.e. red
			q.push({ i, 0 });
			col[i] = 0;
		
			while (!q.empty()) {
				pair<int, int> p = q.front();
				q.pop();
			
				//current vertex
				int v = p.first;
				//colour of current vertex
				int c = p.second;
				
				//traversing vertexes connected to current vertex
				for (int j : adj[v]) {
				
					//if already coloured with parent vertex color
					//then bipartite graph is not possible
					if (col[j] == c)
						return 0;
				
					//if uncoloured
					if (col[j] == -1) {
					//colouring with opposite color to that of parent
						col[j] = (c) ? 0 : 1;
						q.push({ j, col[j] });
					}
				}
			}
		}
	}
	//if all vertexes are coloured such that
	//no two connected vertex have same colours
	return 1;
}


// { Driver Code Starts.
int main()
{

	int V, E;
	V = 4 , E = 8;
	//adjacency list for storing graph
	vector<int> adj[V];
	adj[0] = {1,3};
	adj[1] = {0,2};
	adj[2] = {1,3};
	adj[3] = {0,2};
	

	bool ans = isBipartite(V, adj);
	//returns 1 if bipartite graph is possible
	if (ans)
		cout << "Yes\n";
	//returns 0 if bipartite graph is not possible
	else
		cout << "No\n";

	return 0;
}
```
Output<br />
<pre>
Yes
</pre>
<pre>
Time Complexity: O(V+E)
Auxiliary Space: O(V)
</pre>
**Can DFS algorithm be used to check the bipartite-ness of a graph?**<br />
```cpp
// C++ program to find out whether a given graph is Bipartite or not.
// Using recursion.
#include <iostream>

using namespace std;
#define V 4


bool colorGraph(int G[][V],int color[],int pos, int c){
	
	if(color[pos] != -1 && color[pos] !=c)
		return false;
		
	// color this pos as c and all its neighbours and 1-c
	color[pos] = c;
	bool ans = true;
	for(int i=0;i<V;i++){
		if(G[pos][i]){
			if(color[i] == -1)
				ans &= colorGraph(G,color,i,1-c);
				
			if(color[i] !=-1 && color[i] != 1-c)
				return false;
		}
		if (!ans)
			return false;
	}
	
	return true;
}

bool isBipartite(int G[][V]){
	int color[V];
	for(int i=0;i<V;i++)
		color[i] = -1;
		
	//start is vertex 0;
	int pos = 0;
	// two colors 1 and 0
	return colorGraph(G,color,pos,1);
	
}

int main()
{
	int G[][V] = {{0, 1, 0, 1},
		      {1, 0, 1, 0},
		      {0, 1, 0, 1},
		      {1, 0, 1, 0}
	};

	isBipartite(G) ? cout<< "Yes" : cout << "No";
	return 0;
}
```
Output<br />
<pre>
Yes
</pre>
<pre>
Time Complexity: O(V+E)
Auxiliary Space: O(V)
</pre>







<br /><br /><br />
## Problem 29:
**[Detect a negative cycle in a Graph | (Bellman Ford)](https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/)**<br />
We are given a `directed graph`. We need to compute whether the graph has a **negative cycle or not**. A negative cycle is one in which the overall sum of the cycle becomes **negative**.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/negative_cycle.png"><br />
Negative weights are found in various applications of graphs. For example, instead of paying cost for a path, we may get some advantage if we follow the path.<br />
Examples:<br />
<pre>
Input : 4 4
        0 1 1
        1 2 -1
        2 3 -1
        3 0 -1

Output : Yes
The graph contains a negative cycle.
</pre>
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/negative_cycle121.png"><br />
The idea is to use `Bellman-Ford Algorithm`.<br /> 
<pre>
Below is an algorithm to find if there is a negative weight cycle reachable from 
the given source.

1. Initialize distances from the source to all vertices as infinite and distance to 
   the source itself as 0. Create an array dist[] of size |V| with all values as 
   infinite except dist[src] where src is the source vertex.
2. This step calculates the shortest distances. Do the following |V|-1 times 
   where |V| is the number of vertices in the given graph. 
   1. Do the following for each edge u-v.
   2. If dist[v] > dist[u] + weight of edge uv, then update dist[v]. 
   3. dist[v] = dist[u] + weight of edge uv.
   
3. This step reports if there is a negative weight cycle in the graph. Do the 
   following for each edge u-v  
   1. If dist[v] > dist[u] + weight of edge uv, then the “Graph has a negative 
      weight cycle” 
</pre>
The idea of step `3` is, step `2` guarantees the **shortest distances** if the graph **doesn’t contain a negative weight cycle**. If we iterate through all edges one more time and get a shorter path for any vertex, then there is a **negative weight** cycle.<br />
Implementation:<br />
```cpp
// A C++ program to check if a graph contains negative
// weight cycle using Bellman-Ford algorithm. This program
// works only if all vertices are reachable from a source
// vertex 0.
#include <bits/stdc++.h>
using namespace std;

// a structure to represent a weighted edge in graph
struct Edge {
	int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph {
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[graph->E];
	return graph;
}

// The main function that finds shortest distances
// from src to all other vertices using Bellman-
// Ford algorithm. The function also detects
// negative weight cycle
bool isNegCycleBellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	// Step 1: Initialize distances from src
	// to all other vertices as INFINITE
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// Step 2: Relax all edges |V| - 1 times.
	// A simple shortest path from src to any
	// other vertex can have at-most |V| - 1
	// edges
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	// Step 3: check for negative-weight cycles.
	// The above step guarantees shortest distances
	// if graph doesnt contain negative weight cycle.
	// If we get a shorter path, then there
	// is a cycle.
	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			return true;
	}

	return false;
}

// Driver program to test above functions
int main()
{
	/* Let us create the graph given in above example */
	int V = 5; // Number of vertices in graph
	int E = 8; // Number of edges in graph
	struct Graph* graph = createGraph(V, E);

	// add edge 0-1 (or A-B in above figure)
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;

	// add edge 0-2 (or A-C in above figure)
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;

	// add edge 1-2 (or B-C in above figure)
	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;

	// add edge 1-3 (or B-D in above figure)
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;

	// add edge 1-4 (or A-E in above figure)
	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;

	// add edge 3-2 (or D-C in above figure)
	graph->edge[5].src = 3;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 5;

	// add edge 3-1 (or D-B in above figure)
	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 1;

	// add edge 4-3 (or E-D in above figure)
	graph->edge[7].src = 4;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = -3;

	if (isNegCycleBellmanFord(graph, 0))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
```
Output<br />
<pre>
No
</pre>
<br />**How does it work?**<br />
As discussed, the `Bellman-Ford algorithm`, for a given source, first calculates the **shortest distances** which have at most one edge in the path. Then, it calculates the shortest paths with `at-most 2 edges`, and so on. After the `i-th iteration` of the outer loop, the shortest paths with at most `i` edges are calculated. There can be a maximum `|V| – 1` edge on any simple path, that is why the outer loop runs `|v| – 1` time. If there is a negative weight cycle, then one more iteration would give a short route.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/negativecycle.png"><br />
<br />**How to handle a disconnected graph (If the cycle is not reachable from the source)?**<br />
The above algorithm and program might not work if the given graph is disconnected. It works when all vertices are reachable from source vertex `0`.<br />
To handle disconnected graphs, we can repeat the process for vertices for which distance is **infinite**.<br />
Implementation:<br />
```cpp
// A C++ program for Bellman-Ford's single source
// shortest path algorithm.
#include <bits/stdc++.h>
using namespace std;

// a structure to represent a weighted edge in graph
struct Edge {
	int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph {
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[graph->E];
	return graph;
}

// The main function that finds shortest distances
// from src to all other vertices using Bellman-
// Ford algorithm. The function also detects
// negative weight cycle
bool isNegCycleBellmanFord(struct Graph* graph, int src, int dist[])
{
	int V = graph->V;
	int E = graph->E;

	// Step 1: Initialize distances from src
	// to all other vertices as INFINITE
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// Step 2: Relax all edges |V| - 1 times.
	// A simple shortest path from src to any
	// other vertex can have at-most |V| - 1
	// edges
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	// Step 3: check for negative-weight cycles.
	// The above step guarantees shortest distances
	// if graph doesnt contain negative weight cycle.
	// If we get a shorter path, then there
	// is a cycle.
	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			return true;
	}

	return false;
}

// Returns true if given graph has negative weight
// cycle.
bool isNegCycleDisconnected(struct Graph* graph)
{

	int V = graph->V;
	// To keep track of visited vertices to avoid
	// recomputations.
	bool visited[V];
	memset(visited, 0, sizeof(visited));

	// This array is filled by Bellman-Ford
	int dist[V];

	// Call Bellman-Ford for all those vertices
	// that are not visited
	for (int i = 0; i < V; i++) {
		if (visited[i] == false) {
			// If cycle found
			if (isNegCycleBellmanFord(graph, i, dist))
				return true;

			// Mark all vertices that are visited
			// in above call.
			for (int i = 0; i < V; i++)
				if (dist[i] != INT_MAX)
					visited[i] = true;
		}
	}

	return false;
}

// Driver program to test above functions
int main()
{
	/* Let us create the graph given in above example */
	int V = 5; // Number of vertices in graph
	int E = 8; // Number of edges in graph
	struct Graph* graph = createGraph(V, E);

	// add edge 0-1 (or A-B in above figure)
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;

	// add edge 0-2 (or A-C in above figure)
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;

	// add edge 1-2 (or B-C in above figure)
	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;

	// add edge 1-3 (or B-D in above figure)
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;

	// add edge 1-4 (or A-E in above figure)
	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;

	// add edge 3-2 (or D-C in above figure)
	graph->edge[5].src = 3;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 5;

	// add edge 3-1 (or D-B in above figure)
	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 1;

	// add edge 4-3 (or E-D in above figure)
	graph->edge[7].src = 4;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = -3;

	if (isNegCycleDisconnected(graph))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
```
Output<br />
<pre>
No
</pre>








<br /><br /><br />
## Problem 30:
**[Longest Path in a Directed Acyclic Graph](https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/)**<br />
Given a `Weighted Directed Acyclic Graph (DAG)` and a source vertex `s` in it, find the longest distances from `s` to all other vertices in the given graph.<br />
The longest path problem for a general graph is not as easy as the shortest path problem because the longest path problem doesn’t have optimal substructure property. In fact, the `Longest Path problem is NP-Hard` for a general graph. However, the longest path problem has a **linear time solution for directed acyclic graphs**. The idea is similar to linear time solution for shortest path in a `directed acyclic graph`., we use `Topological Sorting`.<br /> 
We initialize distances to all vertices as `minus infinite` and distance to source as `0`, then we find a topological sorting of the graph. Topological Sorting of a graph represents a linear ordering of the graph. Once we have `topological order` (or linear representation), we one by one process all vertices in topological order. For every vertex being processed, we update distances of its adjacent using distance of current vertex.<br />
Following figure shows step by step process of finding longest paths.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/LongestPath-2.png"><br />
<pre>
Following is complete algorithm for finding longest distances. 
 1. Initialize dist[] = {NINF, NINF, ….} and dist[s] = 0 where s is the source vertex. Here NINF means negative infinite. 
 2. Create a topological order of all vertices. 
 3. Do following for every vertex u in topological order. 
    * ..Do following for every adjacent vertex v of u  
    * ……if (dist[v] < dist[u] + weight(u, v)) 
    * ………dist[v] = dist[u] + weight(u, v) 
</pre>
Following is C++ implementation of the above algorithm.<br />
```cpp
// A C++ program to find single source longest distances
// in a DAG
#include <iostream>
#include <limits.h>
#include <list>
#include <stack>
#define NINF INT_MIN
using namespace std;

// Graph is represented using adjacency list. Every
// node of adjacency list contains vertex number of
// the vertex to which edge connects. It also
// contains weight of the edge
class AdjListNode {
	int v;
	int weight;

public:
	AdjListNode(int _v, int _w)
	{
		v = _v;
		weight = _w;
	}
	int getV() { return v; }
	int getWeight() { return weight; }
};

// Class to represent a graph using adjacency list
// representation
class Graph {
	int V; // No. of vertices'

	// Pointer to an array containing adjacency lists
	list<AdjListNode>* adj;

	// A function used by longestPath
	void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);

public:
	Graph(int V); // Constructor
	~Graph(); // Destructor

	// function to add an edge to graph
	void addEdge(int u, int v, int weight);

	// Finds longest distances from given source vertex
	void longestPath(int s);
};

Graph::Graph(int V) // Constructor
{
	this->V = V;
	adj = new list<AdjListNode>[V];
}

Graph::~Graph() // Destructor
{
	delete [] adj;
}


void Graph::addEdge(int u, int v, int weight)
{
	AdjListNode node(v, weight);
	adj[u].push_back(node); // Add v to u's list
}

// A recursive function used by longestPath. See below
// link for details
// https:// www.geeksforgeeks.org/topological-sorting/
void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack)
{
	// Mark the current node as visited
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<AdjListNode>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {
		AdjListNode node = *i;
		if (!visited[node.getV()])
			topologicalSortUtil(node.getV(), visited, Stack);
	}

	// Push current vertex to stack which stores topological
	// sort
	Stack.push(v);
}

// The function to find longest distances from a given vertex.
// It uses recursive topologicalSortUtil() to get topological
// sorting.
void Graph::longestPath(int s)
{
	stack<int> Stack;
	int dist[V];

	// Mark all the vertices as not visited
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to store Topological
	// Sort starting from all vertices one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	// Initialize distances to all vertices as infinite and
	// distance to source as 0
	for (int i = 0; i < V; i++)
		dist[i] = NINF;
	dist[s] = 0;
	// Process vertices in topological order
	while (Stack.empty() == false) {
		// Get the next vertex from topological order
		int u = Stack.top();
		Stack.pop();

		// Update distances of all adjacent vertices
		list<AdjListNode>::iterator i;
		if (dist[u] != NINF) {
			for (i = adj[u].begin(); i != adj[u].end(); ++i){
			
				if (dist[i->getV()] < dist[u] + i->getWeight())
					dist[i->getV()] = dist[u] + i->getWeight();
			}
		}
	}

	// Print the calculated longest distances
	for (int i = 0; i < V; i++)
		(dist[i] == NINF) ? cout << "INF " : cout << dist[i] << " ";
	
	delete [] visited;
}

// Driver program to test above functions
int main()
{
	// Create a graph given in the above diagram.
	// Here vertex numbers are 0, 1, 2, 3, 4, 5 with
	// following mappings:
	// 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
	Graph g(6);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 3, 6);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 5, 1);
	g.addEdge(3, 4, -1);
	g.addEdge(4, 5, -2);

	int s = 1;
	cout << "Following are longest distances from " "source vertex " << s << " \n";
	g.longestPath(s);

	return 0;
}
```
Output<br />
<pre>
Following are longest distances from source vertex 1 
INF 0 2 9 8 10 
</pre>
<pre>
Time Complexity: Time complexity of topological sorting is O(V+E). 
After finding topological order, the algorithm process all vertices and for every vertex, it runs a loop for all adjacent vertices. 
Total adjacent vertices in a graph is O(E). So the inner loop runs O(V+E) times. 
Therefore, overall time complexity of this algorithm is O(V+E).
</pre>





<br /><br /><br />
## Problem 31:
**[Journey to the Moon](https://www.hackerrank.com/challenges/journey-to-the-moon/problem)**<br />
<img src = "https://user-images.githubusercontent.com/71781982/184545381-0e7702f1-d1be-4789-8eab-26c7ccfb3c71.png"><br />
<img src = "https://user-images.githubusercontent.com/71781982/184545463-3be37a09-8dcb-4c8c-877b-2f4e74dec621.png"><br />
<img src = "https://user-images.githubusercontent.com/71781982/184545465-e1f6d3f4-02c1-4c15-90a2-939e7ad80af6.png"><br />
```cpp
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[100001] = {0};

struct node {
  vector<long long> neighbour;
};

long long bfs(long long, node *);

int main() {
  long long n,m;
  scanf("%lld %lld", &n, &m);
  node nodelist[n];
  long long a,b;
  while(m--) {
    scanf("%lld %lld", &a, &b);
    nodelist[a].neighbour.push_back(b);
    nodelist[b].neighbour.push_back(a);
  }

  long long connected = 0; //no of connected components
  long long total = 0;
  long long temp = 0;
  std::vector<int> count;
  for (long long i = 0; i < n; ++i) {
    if(!visited[i]) {
      temp = bfs(i, nodelist);
      count.push_back( temp );
      total += temp;
      connected++;
    }
  }
  long long answer = (total * (total - 1)) / 2;
  for (int i = 0; i < connected; ++i) {
    answer -= (count[i] * (count[i] - 1)) / 2;
  }
  printf("%lld", answer);

}

long long bfs(long long nod, node *nodelist) {
  int count = 0;
  queue<long long> Q;
  Q.push(nod);
  long long n;
  while(!Q.empty()) {
    n = Q.front();
    Q.pop();
    if(visited[n]) {
      continue;
    }
    visited[n] = true;
    count++;
    for (vector<long long>::iterator itr = nodelist[n].neighbour.begin(); itr != nodelist[n].neighbour.end(); ++itr) {
      if(!visited[*itr]) {
        Q.push(*itr);
      }
    }
  }
  return count;
}
```














<br /><br /><br />
## Problem 32:
**[787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)**<br />
There are `n` cities connected by some number of flights. You are given an array `flights` where `flights[i] = [fromi, toi, pricei]` indicates that there is a flight from city `fromi` to city `toi` with cost `pricei`.<br />
You are also given three integers `src`, `dst`, and `k`, return _**the cheapest price** from `src` to `dst` with at most `k` stops_. If there is no such route, return `-1`.<br />

>Example 1:<br />
<img src = "https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-3drawio.png"><br />
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1<br />
Output: 700<br />
Explanation:<br />
The graph is shown above.<br />
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.<br />
**Note** that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.<br />

>Example 2:<br />
<img src = "https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-1drawio.png"><br />
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1<br />
Output: 200<br />
Explanation:<br />
The graph is shown above.<br />
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.<br />

>Example 3:<br />
<img src = "https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-2drawio.png"><br />
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0<br />
Output: 500<br />
Explanation:<br />
The graph is shown above.<br />
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.<br />
 
* Constraints: `1 <= n <= 100`<br />
`0 <= flights.length <= (n * (n - 1) / 2)`<br />
`flights[i].length == 3`<br />
`0 <= fromi, toi < n`<br />
`fromi != toi`<br />
`1 <= pricei <= 10^4`<br />
There will not be any multiple flights between two cities.<br />
`0 <= src, dst, k < n`<br />
`src != dst`<br />

```cpp
class Solution{
    public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //using bellmon ford
        vector<int> dis(n,1e7);
        dis[src] = 0;
        for(int stops = 0;stops<=k;stops++)
        {
            vector<int> ndis = dis;
            for(int i = 0;i<flights.size();i++)
            {
                ndis[flights[i][1]] = min(dis[flights[i][0]] + flights[i][2],ndis[flights[i][1]]);
            }
            dis = ndis;
        }
        
        return dis[dst]>=1e7?-1:dis[dst];
        }
};
```







<br /><br /><br />
## Problem 33:
**[Oliver and the Game](https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/)**<br />
Oliver and Bob are best friends. They have spent their entire childhood in the beautiful city of Byteland. The people of Byteland live happily along with the King.
The city has a unique architecture with total `N` houses. The King's Mansion is a very big and beautiful bungalow having `address = 1`. Rest of the houses in Byteland have some unique address, (say `A`), are connected by roads and there is always a unique path between any two houses in the city. Note that the King's Mansion is also included in these houses.<br />
Oliver and Bob have decided to play Hide and Seek taking the entire city as their arena. In the given scenario of the game, it's Oliver's turn to hide and Bob is supposed to find him.<br />
Oliver can hide in any of the houses in the city including the King's Mansion. As Bob is a very lazy person, for finding Oliver, he either goes towards the King's Mansion (he stops when he reaches there), or he moves away from the Mansion in any possible path till the last house on that path.<br />
Oliver runs and hides in some house (say `X`) and Bob is starting the game from his house (say `Y`). If Bob reaches house `X`, then he surely finds Oliver.<br />
Given `Q` queries, you need to tell Bob if it is possible for him to find Oliver or not.<br />
<pre>
The queries can be of the following two types:
0 X Y : Bob moves towards the King's Mansion.
1 X Y : Bob moves away from the King's Mansion
</pre>
**INPUT :**<br />
The first line of the input contains a single integer `N`, total number of houses in the city. Next `N-1` lines contain two space separated integers `A` and `B` denoting a road between the houses at address `A` and `B`.<br />
Next line contains a single integer `Q` denoting the number of queries.<br />
Following `Q` lines contain three space separated integers representing each query as explained above.<br />

**OUTPUT :**<br />
Print `"YES"` or `"NO"` for each query depending on the answer to that query.<br />

* CONSTRAINTS : `1 ≤ N ≤ 10^5`<br />
`1 ≤ A,B ≤ N`<br />
`1 ≤ Q ≤ 5*10^5`<br />
`1 ≤ X,Y ≤ N`<br />

**NOTE :**<br />
Large Input size. Use printf scanf or other fast I/O methods.<br />
<img src = "https://user-images.githubusercontent.com/71781982/184546122-2df8e4c7-0781-4f8e-9743-dcff3ac75428.png"><br />

```cpp
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

vector <int> v[100001];
int tim;
int ta[100001], td[100001];

void dfs(int x)
{
	tim++;
	ta[x] = tim;
	for (int i = 0; i < v[x].size(); ++i) {
		if (!ta[v[x][i]]) {
			dfs(v[x][i]);
			tim++;
		}
	}
	tim++;
	td[x] = tim;
}

int main()
{
	int n, m, i, j, k, a, b, c, x, y;
	cin >> n;
	for (i = 1; i < n; ++i) {
		scanf("%d %d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	cin >> m;
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) swap(c, b);
		if (ta[b] <= ta[c] && td[c] <= td[b]) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
```







<br /><br /><br />
## Problem 34:
**[Water Jug problem using BFS](https://www.geeksforgeeks.org/water-jug-problem-using-bfs/)**<br />
You are given an `m` liter jug and a `n` liter jug. Both the jugs are initially empty. The jugs don’t have markings to allow measuring smaller quantities. You have to use the jugs to measure `d` liters of water where `d` is less than `n`.<br /> 
`(X, Y)` corresponds to a state where `X` refers to the amount of water in `Jug1` and `Y` refers to the amount of water in `Jug2`<br /> 
Determine the path from the initial state `(xi, yi)` to the final state `(xf, yf)`, where `(xi, yi)` is `(0, 0)` which indicates both Jugs are initially empty and `(xf, yf)` indicates a state which could be `(0, d)` or `(d, 0)`.<br />
The operations you can perform are:

 1. Empty a Jug, `(X, Y)->(0, Y)` Empty Jug `1`<br />
 2. Fill a Jug, `(0, 0)->(X, 0)` Fill Jug `1`<br />
 3. Pour water from one jug to the other until one of the jugs is either empty or full, `(X, Y) -> (X-d, Y+d)`<br />
 
Examples:<br />
<pre>
Input : 4 3 2
Output : {( 0,0),(0,3),(4,0),(4,3),(3,0),(1,3),(3,3),(4,2),(0,2)}
</pre>
Here, we keep exploring all the different valid cases of the states of water in the jug simultaneously until and unless we reach the required target water.<br />
As provided in the problem statement, at any given state we can do either of the following operations:<br />

 1. Fill a jug<br />
 2. Empty a jug<br />
 3. Transfer water from one jug to another until either of them gets completely filled or empty.<br />
 
Examples:<br />
<pre>
   Input: X = 4, Y = 3, Z = 2
      Output: {(0, 0), (0, 3), (3, 0), (3, 3), (4, 2), (0, 2)}
Explanation: 
    Step 1:- First we will fill the 4 litre jug completely with water. 
    Step 2:- Then optimal approach would be to empty water from 4-litre jug into 3-litre  (leaving 1L water in 4L jug and 3L completely full). Hence we got 1L water.
    Step 3:- Now, Empty water from 3L.
    Step 4:- Pour the water from 4L jug into 3L jug Now 4L container is completely empty and 1L water in present in 3L litre jug.
    Step 5:- Fill the 4L jug with water completely again.
    Step 6:- On transfering  water from 4L jug to 3L jug, we will get 2L water in 4L jug which was our required quantity. 
</pre>
<pre>
   Input:  X = 3, Y = 5, Z = 4

       Output: 6

Explanation:
    Step 1:- First we will fill the 5-litres jug to its maximum capacity.
    Step 2:- Then optimal approach would be to transfer 3-litres from 5-litres jug to 3-litres jugs. 
    Step 3:- Now, Empty the 3-litres jug.
    Step 4:- Transfer 2L from 5L jug to 3-L jug.
    Step 5:- Now, Fill 5-litres jug to its maximum capacity.
    Step 6:- On Pouring water from 5L jug to 3L jug until it’s full we will get 4L water in 5-litre jug which was our required quantity. 
</pre>
<br />**Running of the algorithm:**<br />
We start at an initial state in the queue where both the jugs are empty. We then continue to explore all the possible intermediate states derived from the current jug state using the operations provided.<br />
We also, maintain a visited matrix of states so that we avoid revisiting the same state of jugs again and again.<br />
<img src = "https://user-images.githubusercontent.com/71781982/184546464-2ed1d7d1-e3f2-42fc-97c0-0aed438e04a3.png"><br />
<img src = "https://user-images.githubusercontent.com/71781982/184546467-a2ea6703-9d73-49ba-95d0-0dc8203c2993.png"><br />
From the table above, we can observe that the state where both the jugs are filled is redundant as we won’t be able to continue ahead / do anything with this state in any possible way.<br />
So, we proceed, keeping in mind all the valid state cases (as shown in the table above) and we do a `BFS` on them.<br />
In the `BFS`, we firstly skip the states which was **already visited or if the amount of water in either of the jugs exceeded the jug quantity**. <br />
If we continue further, then we firstly mark the current state as visited and check if in this state, if we have obtained the target quantity of water in either of the jugs, we can empty the other jug and return the `current state’s entire path`.<br />
But, if we have not yet found the target quantity, we then derive the intermediate states from the current state of jugs i.e. we derive the valid cases, mentioned in the table above (go through the code once if you have some confusion).<br />
We keep repeating all the above steps **until** we have `found our target` or `there are no more states left to proceed with`.<br />
Implementation:<br />
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
void printpath(map<pii, pii> mp, pii u)
{
	if (u.first == 0 && u.second == 0) {
		cout << 0 << " " << 0 << endl;
		return;
	}
	printpath(mp, mp[u]);
	cout << u.first << " " << u.second << endl;
}
void BFS(int a, int b, int target)
{
	map<pii, int> m;
	bool isSolvable = false;
	map<pii, pii> mp;

	queue<pii> q;

	q.push(make_pair(0, 0));
	while (!q.empty()) {

		auto u = q.front();
		// cout<<u.first<<" "<<u.second<<endl;
		q.pop();
		if (m[u] == 1)
			continue;

		if ((u.first > a || u.second > b || u.first < 0 || u.second < 0))
			continue;
		// cout<<u.first<<" "<<u.second<<endl;

		m[{ u.first, u.second }] = 1;

		if (u.first == target || u.second == target) {
			isSolvable = true;

			printpath(mp, u);
			if (u.first == target) {
				if (u.second != 0)
					cout << u.first << " " << 0 << endl;
			}
			else {
				if (u.first != 0)
					cout << 0 << " " << u.second << endl;
			}
			return;
		}
		// completely fill the jug 2
		if (m[{ u.first, b }] != 1) {
			q.push({ u.first, b });
			mp[{ u.first, b }] = u;
		}

		// completely fill the jug 1
		if (m[{ a, u.second }] != 1) {
			q.push({ a, u.second });
			mp[{ a, u.second }] = u;
		}

		// transfer jug 1 -> jug 2
		int d = b - u.second;
		if (u.first >= d) {
			int c = u.first - d;
			if (m[{ c, b }] != 1) {
				q.push({ c, b });
				mp[{ c, b }] = u;
			}
		}
		else {
			int c = u.first + u.second;
			if (m[{ 0, c }] != 1) {
				q.push({ 0, c });
				mp[{ 0, c }] = u;
			}
		}
		// transfer jug 2 -> jug 1
		d = a - u.first;
		if (u.second >= d) {
			int c = u.second - d;
			if (m[{ a, c }] != 1) {
				q.push({ a, c });
				mp[{ a, c }] = u;
			}
		}
		else {
			int c = u.first + u.second;
			if (m[{ c, 0 }] != 1) {
				q.push({ c, 0 });
				mp[{ c, 0 }] = u;
			}
		}

		// empty the jug 2
		if (m[{ u.first, 0 }] != 1) {
			q.push({ u.first, 0 });
			mp[{ u.first, 0 }] = u;
		}

		// empty the jug 1
		if (m[{ 0, u.second }] != 1) {
			q.push({ 0, u.second });
			mp[{ 0, u.second }] = u;
		}
	}
	if (!isSolvable)
		cout << "No solution";
}

int main()
{
	int Jug1 = 4, Jug2 = 3, target = 2;
	cout << "Path from initial state " "to solution state ::\n";
	BFS(Jug1, Jug2, target);
	return 0;
}
```
Output<br />
<pre>
Path of states of jugs followed is :
0 , 0
0 , 3
3 , 0
3 , 3
4 , 2
0 , 2
</pre>
<pre>
Time Complexity: O(n*m).
Space Complexity: O(n*m). Where n and m are the quantity of jug1 and jug2, respectively. 
</pre>







<br /><br /><br />
## Problem 35:
**[Find if there is a path of more than k length from a source](https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/)**<br />
Given a `graph`, a source vertex in the graph and a number `k`, find if there is a simple path (without any cycle) **starting from given source and ending at any other vertex** such that the distance from source to that vertex is atleast `‘k’ length`.<br />
Example:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20220710161400/UndirecteGraph-300x144.png"><br />
<pre>
	Weighted Undirected Graph
</pre>
<pre>
Input  : Source s = 0, k = 58
Output : True
There exists a simple path 0 -> 7 -> 1
-> 2 -> 8 -> 6 -> 5 -> 3 -> 4
Which has a total distance of 60 km which
is more than 58.

Input  : Source s = 0, k = 62
Output : False

In the above graph, the longest simple
path has distance 61 (0 -> 7 -> 1-> 2
 -> 3 -> 4 -> 5-> 6 -> 8, so output 
should be false for any input greater 
than 61.
</pre>
One important thing to note is, simply doing `BFS` or `DFS` and picking the **longest edge at every step would not work**. The reason is, a **shorter edge can produce longer path due to higher weight** edges connected through it.<br />
The idea is to use `Backtracking`. We start from given source, **explore all paths from current vertex**. We keep track of current distance from source. If distance becomes more than `k`, we return `true`. If a path doesn’t produces more than `k` distance, we **backtrack**.<br />
**How do we make sure that the path is simple and we don’t loop in a cycle?**<br />
The idea is to keep track of current path vertices in an array. Whenever we add a vertex to path, we **check if it already exists or not in current path**. If it exists, we ignore the edge.<br />
Below is implementation of above idea.<br />
```cpp
// Program to find if there is a simple path with
// weight more than k
#include<bits/stdc++.h>
using namespace std;

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a dipathted graph using
// adjacency list representation
class Graph
{
	int V; // No. of vertices

	// In a weighted graph, we need to store vertex
	// and weight pair for every edge
	list< pair<int, int> > *adj;
	bool pathMoreThanKUtil(int src, int k, vector<bool> &path);

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);
	bool pathMoreThanK(int src, int k);
};

// Returns true if graph has path more than k length
bool Graph::pathMoreThanK(int src, int k)
{
	// Create a path array with nothing included
	// in path
	vector<bool> path(V, false);

	// Add source vertex to path
	path[src] = 1;

	return pathMoreThanKUtil(src, k, path);
}

// Prints shortest paths from src to all other vertices
bool Graph::pathMoreThanKUtil(int src, int k, vector<bool> &path)
{
	// If k is 0 or negative, return true;
	if (k <= 0)
		return true;

	// Get all adjacent vertices of source vertex src and
	// recursively explore all paths from src.
	list<iPair>::iterator i;
	for (i = adj[src].begin(); i != adj[src].end(); ++i)
	{
		// Get adjacent vertex and weight of edge
		int v = (*i).first;
		int w = (*i).second;

		// If vertex v is already there in path, then
		// there is a cycle (we ignore this edge)
		if (path[v] == true)
			continue;

		// If weight of is more than k, return true
		if (w >= k)
			return true;

		// Else add this vertex to path
		path[v] = true;

		// If this adjacent can provide a path longer
		// than k, return true.
		if (pathMoreThanKUtil(v, k-w, path))
			return true;

		// Backtrack
		path[v] = false;
	}

	// If no adjacent could produce longer path, return
	// false
	return false;
}

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair> [V];
}

// Utility function to an edge (u, v) of weight w
void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Driver program to test methods of graph class
int main()
{
	// create the graph given in above figure
	int V = 9;
	Graph g(V);

	// making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	int src = 0;
	int k = 62;
	g.pathMoreThanK(src, k)? cout << "Yes\n" : cout << "No\n";

	k = 60;
	g.pathMoreThanK(src, k)? cout << "Yes\n" : cout << "No\n";

	return 0;
}
```
Output:<br />
<pre>
No
Yes
</pre>
<br /><br />**The above solution can be modified to find weight of longest path from a given source**.<br />
<pre>
Time Complexity: O(n!) 
</pre>
From the source node, we one-by-one visit all the paths and check if the total weight is `greater than k` for each path. So, the worst case will be when the number of possible paths is `maximum`. This is the case when every node is connected to every other node.<br /> 
Beginning from the source node we have `n-1` adjacent nodes. The time needed for a path to connect any two nodes is `2`. One for joining the source and the next adjacent vertex. One for breaking the connection between the source and the old adjacent vertex.<br /> 
After selecting a node out of `n-1` adjacent nodes, we are left with `n-2` adjacent nodes (as the source node is already included in the path) and so on at every step of selecting a node our problem reduces by `1` node.<br />
<pre>
We can write this in the form of a recurrence relation as: F(n) = n*(2+F(n-1))  
This expands to: 2n + 2n*(n-1) + 2n*(n-1)*(n-2) + ……. + 2n(n-1)(n-2)(n-3)…..1  
As n times 2n(n-1)(n-2)(n-3)….1 is greater than the given expression so we can safely say time complexity is: n*2*n!  
Here in the question the first node is defined so time complexity becomes  F(n-1) = 2(n-1)*(n-1)! = 2*n*(n-1)! – 2*1*(n-1)! = 2*n!-2*(n-1)! = O(n!)
</pre>



<br /><br /><br />
## Problem 36:
**[M-Coloring Problem](https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1)**<br />
Given an `undirected graph` and an integer `M`. The task is to determine if the graph can be colored with **at most** `M` colors such that **no two adjacent vertices** of the graph are colored with the **same** color. Here coloring of a graph means the assignment of colors to all vertices. Print `1` if it is possible to colour vertices and `0` otherwise.<br />

>Example 1:<br />
Input:<br />
N = 4<br />
M = 3<br />
E = 5<br />
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}<br />
Output: 1<br />
Explanation: It is possible to colour the given graph using 3 colours.<br />

>Example 2:<br />
Input:<br />
N = 3<br />
M = 2<br />
E = 3<br />
Edges[] = {(0,1),(1,2),(0,2)}<br />
Output: 0<br />

**Your Task:**<br />
Your task is to complete the function `graphColoring()` which takes the `2d-array graph[]`, the number of colours and the number of nodes as inputs and returns _`true` if answer exists otherwise `false`_. `1` is printed if the returned value is true, `0` otherwise. The printing is done by the driver's code.<br />
**Note:** In Example there are Edges not the graph. Graph will be like, if there is an edge between vertex `X` and vertex `Y` `graph[]` will contain `1` at `graph[X-1][Y-1]`, else `0`. In `2d-array graph[ ]`, nodes are `0-based indexed`, i.e. from `0` to `N-1`.Function will be contain `2-D graph` not the edges.<br />

<pre>
Expected Time Complexity: O(MN).
Expected Auxiliary Space: O(N).
</pre>

* Constraints: `1 ≤ N ≤ 20`<br />
`1 ≤ E ≤ (N*(N-1))/2`<br />
`1 ≤ M ≤ N`<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isSafe(int v, bool graph[101][101], int color[101], int c, int V) {
        // checking if the connected nodes to v have same colour as c.
        for (int i = 0; i < V; i++)
            if (graph[v][i] && c == color[i]) return false;
    
        // returning true if no connected node has same colour.
        return true;
    }
    
    bool graphColoringUtil(bool graph[101][101], int m, int color[101], int v,
                           int V) {
        // if all vertices have been assigned colour then we return true.
        if (v == V) return true;
    
        for (int c = 1; c <= m; c++) {
            // checking if this colour can be given to a particular node.
            if (isSafe(v, graph, color, c, V)) {
                // assigning colour to the node.
                color[v] = c;
    
                // calling function recursively and checking if other nodes
                // can be assigned other colours.
                if (graphColoringUtil(graph, m, color, v + 1, V) == true)
                    // returning true if the current allocation was successful.
                    return true;
    
                // if not true, we backtrack and remove the colour for that node.
                color[v] = 0;
            }
        }
        // if no colour can be assigned, we return false.
        return false;
    }
    
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        int *color = new int[n];
        for (int i = 0; i < n; i++) color[i] = 0;
    
        // checking if colours can be assigned.
        if (graphColoringUtil(graph, m, color, 0, n) == false) {
            return false;
        }
    
        return true;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int n, m, e, i; cin>>n>>m>>e;
        bool graph[101][101];
        for(i = 0;i<n;i++)memset(graph[i], 0, sizeof(graph[i]));
        for(i = 0;i<e;i++){
            int a, b; cin>>a>>b;
            graph[a-1][b-1] = 1;
            graph[b-1][a-1] = 1;
        }    
        Solution ob;
        cout<<ob.graphColoring(graph, m, n)<<endl;
    }
}
```







<br /><br /><br />
## Problem 37:
**[Minimum edges to reverse to make path from a source to a destination](https://www.geeksforgeeks.org/minimum-edges-reverse-make-path-source-destination/)**<br />
Given a `directed graph` and a `source node` and `destination node`, we need to find how many edges we need to reverse in order to make **at least** `1` path from the source node to the destination node.<br />
Examples:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/reverseEdge.png"><br />
<pre>
In above graph there were two paths from node 0 to node 6,
0 -> 1 -> 2 -> 3 -> 6
0 -> 1 -> 5 -> 4 -> 6
But for first path only two edges need to be reversed, so answer will be 2 only.
</pre>
This problem can be solved assuming a different version of the given graph. In this version we make a **reverse edge** corresponding to every edge and we assign that a weight `1` and assign a weight `0` to original edge. After this modification above graph looks something like below,<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/modifiedGraph.png"><br />
Now we can see that we have modified the graph in such a way that, if we move towards `original edge`, **no cost is incurred**, but if we move toward `reverse edge` **1 cost is added**. So if we apply `Dijkstra’s shortest path` on this modified graph from given source, then that will give us `minimum cost` to reach from **source** to **destination** i.e. minimum edge reversal from source to destination.<br />
Below is the code based on above concept. <br />
```cpp
// C++ Program to find minimum edge reversal to get
// atleast one path from source to destination
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// This class represents a directed graph using
// adjacency list representation
class Graph
{
	int V;
	list<pair<int, int>> *graph;

public:
	// Constructor:
	Graph(int V)
	{
		this->V = V;
		graph = new list<pair<int, int>>[V];
	}

	// Adding edges into the graph:
	void addEdge(int u, int v, int w)
	{
		graph[u].push_back(make_pair(v, w));
	}

	// Returns shortest path from source to all other vertices.
	vector<int> shortestPath(int source)
	{
		// Create a set to store vertices that are being preprocessed
		set<pair<int, int>> setds;

		// Create a vector for distances and initialize all
		// distances as infinite (INF)
		vector<int> distance(V, INF);

		// Insert source itself in Set and initialize its distance as 0.
		setds.insert(make_pair(0, source));
		distance = 0;

		/* Looping till all shortest distance are finalized
		then setds will become empty */
		while (!setds.empty())
		{
			// The first vertex in Set is the minimum distance
			// vertex, extract it from set.
			pair<int, int> tmp = *(setds.begin());
			setds.erase(setds.begin());

			// vertex label is stored in second of pair (it
			// has to be done this way to keep the vertices
			// sorted distance (distance must be first item
			// in pair)
			int u = tmp.second;

			list<pair<int, int>>::iterator i;
			for (i = graph[u].begin(); i != graph[u].end(); ++i)
			{
				// Get vertex label and weight of current adjacent
				// of u.
				int v = (*i).first;
				int weight = (*i).second;

				// If there is shorter path to v through u.
				if (distance[v] > distance[u] + weight)
				{
					/* If distance of v is not INF then it must be in
						our set, so removing it and inserting again
						with updated less distance.
						Note : We extract only those vertices from Set
						for which distance is finalized. So for them,
						we would never reach here. */
					if (distance[v] != INF)
						setds.erase(setds.find(make_pair(distance[v], v)));

					// Updating distance of v
					distance[v] = distance[u] + weight;
					setds.insert(make_pair(distance[v], v));
				}
			}
		}
		return distance;
	}

	Graph modelGraphWithEdgeWeight(int edge[][2], int E, int V)
	{
		Graph g(V);
		for (int i = 0; i < E; i++)
		{
			// original edge : weight 0
			g.addEdge(edge[i][0], edge[i][1], 0);

			// reverse edge : weight 1
			g.addEdge(edge[i][1], edge[i][0], 1);
		}
		return g;
	}

	int getMinEdgeReversal(int edge[][2], int E, int V, int source, int destination)
	{
		// get modified graph with edge weight.
		Graph g = modelGraphWithEdgeWeight(edge, E, V);

		// distance vector stores shortest path.
		vector<int> dist = g.shortestPath(source);

		// If distance of destination is still INF then we cannot reach destination. Hence, not possible.
		if (dist[destination] == INF)
			return -1;
		else
			return dist[destination];
	}
};

int main()
{
	int V = 7;
	Graph g(V);

	int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, {4, 5}, {6, 4}, {6, 3}};
	int E = sizeof(edge) / sizeof(edge[0]);

	int minEdgeToReverse = g.getMinEdgeReversal(edge, E, V, 0, 6);

	if (minEdgeToReverse != -1)
		cout << minEdgeToReverse << endl;
	else
		cout << "Not Possible." << endl;

	return 0;
}
```
Output:<br />
<pre>
2
</pre>
<pre>
One more efficient approach to this problem would be by using 0-1 BFS concept. 
</pre>
Below is the implementation of that algorithm:<br />
```java
//Java code to find minimum edge reversal to get
//atleast one path from source to destination using 0-1 BFS
//Code By: Sparsh_CBS
import java.util.*;

class Node{
	private int val;
	private int weight;
	private Integer parent;
	Node(int val, int weight){
		this.val = val;
		this.weight = weight;
		parent = null;
	}
	//We have used the concept of parent to avoid
	//a child revisiting its parent and pushing it in
	//the deque during the 0-1 BFS
	Node(int val, int distance, Integer parent){
		this.val = val;
		this.weight = distance;
		this.parent = parent;
	}

	public int getVal(){
		return val;
	}

	public int getWeight(){
		return weight;
	}

	public Integer getParent(){
		return parent;
	}
}

public class Gfg{
	public static void main(String[] args) {
		List<List<Integer>> adj = new ArrayList<>();
		for(int i = 0; i < 7; i++)
			adj.add(new ArrayList<>());

		adj.get(0).add(1);
		
		adj.get(2).add(1);
		
		adj.get(5).add(1);
		
		adj.get(2).add(3);
		
		adj.get(6).add(3);
		
		adj.get(6).add(4);
		
		adj.get(4).add(5);

		int ans = getMinRevEdges(adj, 0, 6);
	
		if(ans == Integer.MAX_VALUE)
			System.out.println(-1);
		else
			System.out.println(ans);
	}

	private static int getMinRevEdges(List<List<Integer>> adj, int src, int dest){
		int n = adj.size();

		//Create the given graph into bidirectional graph
		List<List<Node>> newAdj = getBiDirectionalGraph(adj);

		//Now, Apply 0-1 BFS using Deque to get the shortest path

		//In the implementation, we will only add the
		//encountered node into the deque if and only if
		//the distance at which it was earlier explored was
		//strictly larger than the currently encountered distance
		Deque<Node> dq = new LinkedList<>();

		//Here Node is made up of : Node(int node_val, int node_distance, int node_parent)
		dq.offer(new Node(src,0,0));
		int[] dist = new int[n];
		//Set the distance of all nodes to infinity(Integer.MAX_VALUE)
		Arrays.fill(dist, Integer.MAX_VALUE);
		//set distance of source node as 0
		dist[src] = 0;

		while(!dq.isEmpty()){
			Node curr = dq.pollFirst();
			int currVal = curr.getVal();
			int currWeight = curr.getWeight();
			int currParent = curr.getParent();
			//If we encounter the destination node, we return
			if(currVal == dest)
				return currWeight;
			//Iterate over the neighbours of the current Node
			for(Node neighbourNode: newAdj.get(currVal)){
				int neighbour = neighbourNode.getVal();
				if(neighbour == currParent)
					continue;

				int wt = neighbourNode.getWeight();
				if(wt == 0 && dist[neighbour] > currWeight){
					dist[neighbour] = currWeight;
					dq.offerFirst(new Node(neighbour,currWeight, currVal));
				}
				else if(dist[neighbour] > currWeight+wt){
					dist[neighbour] = currWeight+wt;
					dq.offerLast(new Node(neighbour, currWeight+wt, currVal));
				}
			}
		}
		return Integer.MAX_VALUE;
	}

	private static List<List<Node>> getBiDirectionalGraph(List<List<Integer>> adj){
		int n = adj.size();
		List<List<Node>> newAdj = new ArrayList<>();
		
		for(int i = 0; i < n; i++)
			newAdj.add(new ArrayList<>());
		
		boolean[] visited = new boolean[n];
		Queue<Integer> queue = new LinkedList<>();

		for(int i = 0; i < n; i++){
			if(!visited[i]){
				visited[i] = true;
				queue.offer(i);
				
				while(!queue.isEmpty()){
					int curr = queue.poll();
					for(int neighbour: adj.get(curr)){
						//original edges are to be assigned a weight of 0
						newAdj.get(curr).add(new Node(neighbour, 0));
						//make a fake edge and assign a weight of 1
						newAdj.get(neighbour).add(new Node(curr, 1));
					
						if(visited[neighbour]){
						//if the neighbour was visited, then dont
						// add it again in the queue
						continue;
						}
						visited[neighbour] = true;
						queue.offer(neighbour);
					}
				}
			}
		}
		return newAdj;
	}
}
```
Output:<br />
<pre>
2
</pre>
<pre>
Time Complexity: O(V+E)
Space Complexity: O(V+2*E)
</pre>






<br /><br /><br />
## Problem 38:
**[Paths to travel each nodes using each edge (Seven Bridges of Königsberg)](https://www.geeksforgeeks.org/paths-travel-nodes-using-edgeseven-bridges-konigsberg/)**<br />
There are `n` nodes and `m` bridges in between these nodes. Print the possible path through each node using each edges (if possible), traveling through each edges only once.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/bridge-1.jpg"><br />
Examples :<br />
<pre>
Input : [[0, 1, 0, 0, 1],
         [1, 0, 1, 1, 0],
         [0, 1, 0, 1, 0],
         [0, 1, 1, 0, 0],
         [1, 0, 0, 0, 0]]

Output : 5 -> 1 -> 2 -> 4 -> 3 -> 2

Input : [[0, 1, 0, 1, 1],
         [1, 0, 1, 0, 1],
         [0, 1, 0, 1, 1],
         [1, 1, 1, 0, 0],
         [1, 0, 1, 0, 0]]

Output : "No Solution"
</pre>
It is one of the famous problems in Graph Theory and known as problem of `“Seven Bridges of Königsberg”`. This problem was solved by famous mathematician **Leonhard Euler in 1735**. This problem is also considered as the beginning of **Graph Theory**.<br />
The problem back then was that: There was `7 bridges connecting 4 lands around the city of Königsberg in Prussia`.<br />
**Was there any way to start from any of the land and go through each of the bridges once and only once?**<br />
**Euler** first introduced graph theory to solve this problem. He considered each of the lands as a node of a graph and each bridge in between as an edge in between. Now he calculated if there is any `Eulerian Path` in that graph. If there is an Eulerian path then there is a solution otherwise not.<br /> 
Problem here, is a generalized version of the problem in 1735.<br />
Below is the implementation :<br />
```cpp
// A C++ program print Eulerian Trail in a
// given Eulerian or Semi-Eulerian Graph
#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
using namespace std;

// A class that represents an undirected graph
class Graph
{
// No. of vertices
	int V;

	// A dynamic array of adjacency lists
	list<int> *adj;
public:

	// Constructor and destructor
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}
	~Graph()
	{
		delete [] adj;
	}

	// functions to add and remove edge
	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void rmvEdge(int u, int v);

	// Methods to print Eulerian tour
	void printEulerTour();
	void printEulerUtil(int s);

	// This function returns count of vertices
	// reachable from v. It does DFS
	int DFSCount(int v, bool visited[]);

	// Utility function to check if edge u-v
	// is a valid next edge in Eulerian trail or circuit
	bool isValidNextEdge(int u, int v);
};

/* The main function that print Eulerian Trail.
It first finds an odd degree vertex (if there is any)
and then calls printEulerUtil() to print the path */
void Graph::printEulerTour()
{
	// Find a vertex with odd degree
	int u = 0;

	for (int i = 0; i < V; i++)
		if (adj[i].size() & 1)
		{
			u = i;
			break;
		}

	// Print tour starting from oddv
	printEulerUtil(u);
	cout << endl;
}

// Print Euler tour starting from vertex u
void Graph::printEulerUtil(int u)
{

	// Recur for all the vertices adjacent to
	// this vertex
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i;

		// If edge u-v is not removed and it's a
		// valid next edge
		if (v != -1 && isValidNextEdge(u, v))
		{
			cout << u << "-" << v << " ";
			rmvEdge(u, v);
			printEulerUtil(v);
		}
	}
}

// The function to check if edge u-v can be considered
// as next edge in Euler Tout
bool Graph::isValidNextEdge(int u, int v)
{

	// The edge u-v is valid in one of the following
	// two cases:

	// 1) If v is the only adjacent vertex of u
	int count = 0; // To store count of adjacent vertices
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
		if (*i != -1)
			count++;
	if (count == 1)
		return true;


	// 2) If there are multiple adjacents, then u-v
	// is not a bridge
	// Do following steps to check if u-v is a bridge

	// 2.a) count of vertices reachable from u
	bool visited[V];
	memset(visited, false, V);
	int count1 = DFSCount(u, visited);

	// 2.b) Remove edge (u, v) and after removing
	// the edge, count vertices reachable from u
	rmvEdge(u, v);
	memset(visited, false, V);
	int count2 = DFSCount(u, visited);

	// 2.c) Add the edge back to the graph
	addEdge(u, v);

	// 2.d) If count1 is greater, then edge (u, v)
	// is a bridge
	return (count1 > count2)? false: true;
}

// This function removes edge u-v from graph.
// It removes the edge by replacing adjacent
// vertex value with -1.
void Graph::rmvEdge(int u, int v)
{
	// Find v in adjacency list of u and replace
	// it with -1
	list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
	*iv = -1;


	// Find u in adjacency list of v and replace
	// it with -1
	list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
	*iu = -1;
}

// A DFS based function to count reachable
// vertices from v
int Graph::DFSCount(int v, bool visited[])
{
	// Mark the current node as visited
	visited[v] = true;
	int count = 1;

	// Recur for all vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (*i != -1 && !visited[*i])
			count += DFSCount(*i, visited);

	return count;
}

// Driver program to test above function
int main()
{
	// Let us first create and test
	// graphs shown in above figure
	Graph g1(4);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 2);
	g1.addEdge(2, 3);
	g1.printEulerTour();

	Graph g3(4);
	g3.addEdge(0, 1);
	g3.addEdge(1, 0);
	g3.addEdge(0, 2);
	g3.addEdge(2, 0);
	g3.addEdge(2, 3);
	g3.addEdge(3, 1);

	// comment out this line and you will see that
	// it gives TLE because there is no possible
	// output g3.addEdge(0, 3);
	g3.printEulerTour();

	return 0;
}
```
Output:<br />
<pre>
2-0  0-1  1-2  2-3  
1-0  0-2  2-3  3-1  1-0  0-2
</pre>










<br /><br /><br />
## Problem 39:
**[Vertex Cover Problem | (Introduction and Approximate Algorithm)](https://www.geeksforgeeks.org/vertex-cover-problem-set-1-introduction-approximate-algorithm-2/)**<br />
A vertex cover of an `undirected graph` is a subset of its vertices such that for every edge `(u, v)` of the graph, either `‘u’` or `‘v’` is in the vertex cover. Although the name is Vertex Cover, the set covers all edges of the given graph. Given an undirected graph, the vertex cover problem is to find **minimum size** vertex cover.<br /> 
The following are some examples.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/vertexcover.png"><br />
`Vertex Cover Problem` is a known `NP Complete problem`, i.e., there is **no polynomial-time solution** for this `unless P = NP`. There are approximate **polynomial-time algorithms** to solve the problem though.<br />
<br />**Naive Approach:**<br />
Consider all the subset of vertices one by one and find out whether it covers all edges of the graph. For eg. in a graph consisting only 3 vertices the set consisting of the combination of vertices are:`{0,1,2,{0,1},{0,2},{1,2},{0,1,2}}` . Using each element of this set check whether these vertices cover all  all the edges of the graph. Hence update the optimal answer. And hence print the **subset having minimum number of vertices** which also covers all the edges of the graph.<br />
**Approximate Algorithm for Vertex Cover:**<br />
<pre>
1) Initialize the result as {}
2) Consider a set of all edges in given graph.  Let the set be E.
3) Do following while E is not empty
...a) Pick an arbitrary edge (u, v) from set E and add 'u' and 'v' to result
...b) Remove all edges from E which are either incident on u or v.
4) Return result 
</pre>
Below diagram to show the execution of the above approximate algorithm:<br />
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/minimumvertexcover.png"><br />
<br />**How well the above algorithm perform?**<br />
It can be proved that the above approximate algorithm never finds a **vertex cover whose size is more than twice the size of the minimum possible vertex cover**.<br />
**Implementation:**<br />
The following are C++ and Java implementations of the above approximate algorithm.<br />
```cpp
// Program to print Vertex Cover of a given undirected graph
#include<iostream>
#include <list>
using namespace std;

// This class represents a undirected graph using adjacency list
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	void printVertexCover(); // prints vertex cover
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
	adj[w].push_back(v); // Since the graph is undirected
}

// The function to print vertex cover
void Graph::printVertexCover()
{
	// Initialize all vertices as not visited.
	bool visited[V];
	for (int i=0; i<V; i++)
		visited[i] = false;

	list<int>::iterator i;

	// Consider all edges one by one
	for (int u=0; u<V; u++)
	{
		// An edge is only picked when both visited[u] and visited[v]
		// are false
		if (visited[u] == false)
		{
			// Go through all adjacents of u and pick the first not
			// yet visited vertex (We are basically picking an edge
			// (u, v) from remaining edges.
			for (i= adj[u].begin(); i != adj[u].end(); ++i)
			{
				int v = *i;
				if (visited[v] == false)
				{
					// Add the vertices (u, v) to the result set.
					// We make the vertex u and v visited so that
					// all edges from/to them would be ignored
					visited[v] = true;
					visited[u] = true;
					break;
				}
			}
		}
	}

	// Print the vertex cover
	for (int i=0; i<V; i++)
		if (visited[i])
		cout << i << " ";
}

// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 6);

	g.printVertexCover();

	return 0;
}
```
Output:<br />
<pre>
0 1 3 4 5 6
</pre>
<pre>
The Complexity of the above algorithm is O(V + E).
</pre>
**Exact Algorithms:**<br /> 
Although the problem is `NP complete`, it can be solved in polynomial time for the following types of graphs.<br />

1) Bipartite Graph<br />
2) Tree Graph<br />

The problem to check whether there is a vertex cover of size smaller than or equal to a given number `k` can also be solved in polynomial time if `k` is bounded by `O(LogV)`<br />







<br /><br /><br />
## Problem 40:
**[Chinese Postman or Route Inspection](https://www.geeksforgeeks.org/chinese-postman-route-inspection-set-1-introduction/)**<br />
`Chinese Postman Problem` is a variation of `Eulerian circuit problem` for `undirected graphs`. An Euler Circuit is a closed walk that covers every edge once starting and ending position is same. Chinese Postman problem is defined for **connected** and **undirected graph**. The problem is to **find shortest path or circuity that visits every edge of the graph at least once**.<br />
If input graph contains `Euler Circuit`, then a solution of the problem is `Euler Circuit`<br />
An undirected and connected graph has Eulerian cycle if “all vertices have even degree“.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Chinese-Postman.png"><br />
It doesn’t matter whether graph is `weighted` or `unweighted`, the Chinese Postman Route is always same as `Eulerian Circuit` if it exists. In weighted graph the **minimum possible weight of Postman tour** is `sum of all edge weights which we get through Eulerian Circuit`. We can’t get a shorter route as we must visit all edges **at-least** once.<br /> 
<pre>
  If input graph does NOT contain Euler Circuit 
</pre>
In this case, the task reduces to following.<br /> 
1) In `unweighted graph`, **minimum** number of `edges` to duplicate so that the given graph converts to a graph with `Eulerian Cycle`.<br /> 
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Chinese-Postman2.png"><br />
2) In weighted graph, `minimum total weight` of edges to duplicate so that given graph converts to a graph with `Eulerian Cycle`.<br />
<img src = "https://media.geeksforgeeks.org/wp-content/cdn-uploads/Chinese-Postman-3-1.png"><br />
<pre>
Algorithm to find shortest closed path or optimal 
Chinese postman route in a weighted graph that may
not be Eulerian.

step 1 : If graph is Eulerian, return sum of all 
         edge weights.Else do following steps.
step 2 : We find all the vertices with odd degree 
step 3 : List all possible pairings of odd vertices  
         For n odd vertices total number of pairings 
         possible are, (n-1) * (n-3) * (n -5)... * 1
step 4 : For each set of pairings, find the shortest 
         path connecting them.
step 5 : Find the pairing with minimum shortest path 
         connecting pairs.
step 6 : Modify the graph by adding all the edges that  
         have been found in step 5.
step 7 : Weight of Chinese Postman Tour is sum of all 
         edges in the modified graph.
step 8 : Print Euler Circuit of the modified graph. 
         This Euler Circuit is Chinese Postman Tour.
</pre>
Illustration :<br />
<pre>
                   3
        (a)-----------------(b)
     1 /  |                  |  \1
      /   |                  |   \
     (c)  | 5               6|   (d)
      \   |                  |   /
     2 \  |         4        |  /1
        (e)------------------(f)
As we see above graph does not contain Eulerian circuit
because is has odd degree vertices [a, b, e, f]
they all are odd degree vertices . 

First we make all possible pairs of odd degree vertices
[ae, bf], [ab, ef], [af, eb] 
so pairs with min sum of weight are [ae, bf] :
ae = (ac + ce = 3 ),  bf = ( bd + df = 2 ) 
Total : 5

We add edges ac, ce, bd and df to the original graph and
create a modified graph.
</pre>
<img src = "https://media.geeksforgeeks.org/wp-content/uploads/img038-1024x606.jpg"><br />
<pre>
Optimal chinese postman route is of length : 5 + 23 = 
28 [ 23 = sum  of all edges of modified graph ]

Chinese Postman Route :  
a - b - d - f - d - b - f - e - c - a - c - e - a 
This route is Euler Circuit of the modified graph. 
</pre>






<br /><br /><br />
## Problem 41:
**[]()**<br />

<br /><br /><br />
## Problem 42:
**[]()**<br />

<br /><br /><br />
## Problem 43:
**[]()**<br />
