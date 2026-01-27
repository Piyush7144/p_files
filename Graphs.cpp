//to do 
//Undertand all questions of targans algorithm skip kosaraju

Graphs

Graph and its representation:

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        for (auto x : adj[v])
           cout << x<<" ";
        printf("\n");
    }
}
 
// Driver code
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}


1. dfs

void dfs(int s, vector<int> &g[], bool *vis)
{
	vis[s] = true;
	cou<<s<<" ";

	for(int i = 0; i< (int)g[s].size(); ++i)
	{
		if(vis[g[s][i]] == false)
			dfs(g[s][i], g, vis); 
	}

}

int main()

{
	int T;
	cin>>T;

	while(T--)
	{
		int N, E;
		cin>>N>>E;

		vetor<int> g[N];
		bool vis[N];

		memset(vis, false, sizeof(vis));

		for(int i = 0; i< E; i++)
		{
			int u, v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);

		}
		dfs(0, g, vis);
		cout<<endl;
	}
}



2. bfs (we can use bfs to find sortest distane bt source to destination in graph(unweighted) but no dfs
	    dfs is exponential here, but in tree both works)

// bfs solution are much faster for some other questions

void bfs(int s, vector<int> adj[], bool vis[], int N)
{
	queue<int> q;
	q.push(s);
	vis[s] = true;

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout<<curr<<" ";

		for(int i = 0; i< adj[curr].size(); ++i)
		{
			if(vis[adj[curr][i]] == false)
				{
					q.push(adj[curr][i]);
					vis[adj[curr][i]] = true;
				}
		}
	}
}



int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N, E;
		cin>>N>>E;

		vector<int> adj[N];
		bool vis[N] = {false};

		for(int i = 0; i< E; i++)
		{
			int u, v;
			cin>>u>>v;

			adj[u].push_back(v);
		}

		bfs(0,adj, vis, N);
		cout<<endl;
	}
}




3. Cycle detection in undirected graph(using dfs)

Keep on traversing the graph. If you found an edge pointing to 
an already visited node(except the parent node), a cycley if found

#include "bits/stdc++.h"

using namespace std;


bool iscycle( int src, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
	visited[src] = true;
	for(auto i: adj[src])
	{
		if(i != parent) {
			if( visited[i])
				return true;
			if( !visited[i] and iscycle(i, adj, visited, src)){
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int n, m;
	cin>>n>>m;
	vector<vector<int>> adj(n);

	for(int i = 0; i< n; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool cycle = false;
	vector<bool> visited(n, false);

	for(int i = 0; i< n; i++)
	{
		if(!visited[i] and iscycle(i, adj, visited, -1)) {
			cycle = true;
		}
	}

	if(cycle)
		cout<<"Cycle is presetn"<<endl;
	else
		cout<<"cycle is not presetn"<<endl;
}

Time Complexity: O(V+E). 
The program does a simple DFS Traversal of the graph which is 
represented using adjacency list. So the time complexity is O(V+E).
Space Complexity: O(V). 
To store the visited array O(V) space is required.7


3.2 cycle detection in undirected  graph(using bfs)

//use parent array because we forget about parents

bool isCyclicConntected(vector<int> adj[], int s,
                        int V, vector<bool>& visited)
{
    vector<int> parent(V, -1);
 

    queue<int> q;
 
    visited[s] = true;
    q.push(s);
 
    while (!q.empty()) {
 
        // Dequeue a vertex from queue and print it
        int u = q.front();
        q.pop();
 
        // Get all adjacent vertices of the dequeued
        // vertex u. If a adjacent has not been visited,
        // then mark it visited and enqueue it. We also
        // mark parent so that parent is not considered
        // for cycle.
        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                parent[v] = u;
            }
            else if (parent[u] != v)
                return true;
        }
    }
    return false;
}
 
bool isCyclicDisconntected(vector<int> adj[], int V)
{
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);
 
    for (int i = 0; i < V; i++)
        if (!visited[i] && isCyclicConntected(adj, i,
                                         V, visited))
            return true;
    return false;
}



4. cycle detection in directed graph(using dfs)
//solution using bfs us based on indegree and khan's algorithm bit diffficult

1.Mark the current node as visited and also mark the index 
in recursion stack  

2. Find all the vertices which are not visited and are adjacent 
to the current node. 

3. If the adjacnet vertices are already marked in the recursion
stack then a cycle if found. 



bool iscycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack) {

    visited[src] = true;
	stack[src] = true;

	for(auto i : adj[src]){
		if(!visited[i] and iscycle(i, adj, visited, stack)){
			return true;
		}
		if(stack[i])
			return true;
	}
	stack[src] = false;
	return false;
}
int main()
{
	int n, m;
	cin>>n>>m;
	vector<vector<int>> adj(n);

	for(int i = 0; i< n; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	bool cycle = false;
	vector<bool> visited(n, false);
	vector<bool> stack(n, false);

	for(int i = 0; i< n; i++)
	{
		if(!visited[i] and iscycle(i, adj, visited, stack)) {
			cycle = true;
		}
	}

	if(cycle)
		cout<<"Cycle is presetn"<<endl;
	else
		cout<<"cycle is not presetn"<<endl;
}




5. No of islands in a graph //no of connected components

// Loop through whole matrix. If we reach any 1 then mark the whole island
// With different digit(2).


class Solution {
    void mark_current_island(vector<vector<char>> &matrix,int x,int y,int r,int c)
    {
        if(x<0 || x>=r || y<0 || y>=c || matrix[x][y]!='1')  //Boundary case for matrix
            return;
        
        //Mark current cell as visited
        matrix[x][y] = '2';
        
        //Make recursive call in all 4 adjacent directions
        mark_current_island(matrix,x+1,y,r,c);  //DOWN
        mark_current_island(matrix,x,y+1,r,c);  //RIGHT
        mark_current_island(matrix,x-1,y,r,c);  //TOP
        mark_current_island(matrix,x,y-1,r,c);  //LEFT
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        //For FAST I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int rows = grid.size();
        if(rows==0)     //Empty grid boundary case
            return 0;
        int cols = grid[0].size();
        
        //Iterate for all cells of the array
        int no_of_islands = 0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]=='1')
                {
                    mark_current_island(grid,i,j,rows,cols);
                    no_of_islands += 1;
                }
            }
        }
        return no_of_islands;
    }
};


5.2 Connected components:

Idea
1.visit the nodes in a depth-first fashion
2. If the node is not visited, visit that node and 
its neighbours recursively. 
3. Each time a invisited node is found, a new component will
be found. 


Q. Find the no of connected components in a graph and its size 

Solution1 :

int Graph::NumberOfconnectedComponents()
{
 
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
 
    // To store the number of connected components
    int count = 0;
    for (int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            DFSUtil(v, visited);
            count += 1;
        }
    }
 
    return count;
}
 
void Graph::DFSUtil(int v, bool visited[])
{
 
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
 
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

//solution 2
vector<bool> vis;
int n,m; 
vector<vector<int>> adj;

vector<int> components;

int get_comp(int idx)
{
    if(vis[idx])
        return 0;
    vis[idx] = true;
    int ans = 1;
    for(auto i : adj[idx])
    {
        if(!vis[i] ){
            ans += get_comp(i);
            vis[i] = true;
        }
    }
    return ans;
}

int main()
{
    cin>>n>>m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);

    for(int i = 0; i< m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i< n; i++){
        if(!vis[i])
        {
            components.push_back(get_comp(i));
        }
    }

    for(auto i: components){
        cout<<i<<endl;
    }
}


6. Bipartite graph // graph coloring 

i. Its vertices can be divided into two disjoint and independent
sets U and V such that every edge connects a vertex in U to one in V

ii. The graph does not contain any odd-length cycles. 

iii. The graph is 2 colorable 


Pseudocode:

i. Traverse the Graph
ii. If the current node is of red color, paint its neighbours
as blue. 
iii. If you are able to color the graph successfully, then the graph is Bipartite. 

vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool bipart;

void color(int u, int current){
    //If we can't color the node what we want to then return false, like it's blue but we wanted red
    if(col[u] != -1 and col[u] != current){
        bipart = false;
        return ;
    }
    col[u] = current;
    if(vis[u])
        return ;
    vis[u] = true;
    //Color all its adjcent nodes to different color
    //xor will handle the color switching between 0 and 1
    for(auto i: adj[u]){
        color(i, current xor 1);

    }
}
int main(){
    bipart = true;
    int n,m;
    cin>>n>>m;

    adj = vector<vector<int>>(n);
    vis = vector<bool>(n,false);
    col = vector<int>(n, -1);

    for(int i = 0; i< m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    for(int  i = 0; i< n; i++)
    {
        if(!vis[i]){
            color(i,0);
        }
    }
    if(bipart)
        cout<<"Graph is Bipartite"<<endl;
    else
        cout<<"Graph is not Bipartite"<<endl;
}


6.5 Shotest path in undirected graph with unit weight:

void BFS(vector<int> adj[], int N, int src) 
{ 
    int dist[N];
    for(int i = 0;i<N;i++) dist[i] = INT_MAX; 
    queue<int>  q;
    
    dist[src] = 0;
    q.push(src); 

    while(q.empty()==false) 
    { 
        int node = q.front(); 
        q.pop();
         
        for(auto it:adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it]=dist[node]+1;
                q.push(it);
            }
        } 
    } 
    for(int i = 0;i<N;i++) cout << dist[i] << " "; 
    
}


7. Deadlock detection: cycle in directed graph method 2

class Solution {
    bool isCyclic(vector<vector<int>>& adj,vector<int>& visited,int curr)
    {
        if(visited[curr]==2)
            return true;
        
        visited[curr] = 2;
        for(int i=0;i<adj[curr].size();++i)
            if(visited[adj[curr][i]]!=1)
                if(isCyclic(adj,visited,adj[curr][i]))
                    return true;
        
        visited[curr] = 1;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<int>> adj(numCourses);
        //Make adjacency matrix (Directed graph)
        for(int i=0;i<prerequisites.size();++i)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;++i)
            if(visited[i]==0)
                if(isCyclic(adj,visited,i))
                    return false;
        
        return true;
    }
};



8. Minimum steps to reach target by a Knight

This problem can be seen as shortest path in unweighted graph. 
Therefore we use BFS to solve this problem. We try all 8 possible 
positions where a Knight can reach from its position. If reachable 
position is not already visited and is inside the board, we push 
this state into queue with distance 1 more than its parent state. 
Finally we return distance of target position, when it gets pop out 
from queue.


#include <bits/stdc++.h>
using namespace std;
 
// structure for storing a cell's data
struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
};
 
// Utility method returns true if (x, y) lies
// inside Board
bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}
 
// Method returns minimum step
// to reach target position
int minStepToReachTarget(
    int knightPos[], int targetPos[],
    int N)
{
    // x and y direction, where a knight can move
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
 
    // queue for storing states of knight in board
    queue<cell> q;
 
    // push starting position of knight with 0 distance
    q.push(cell(knightPos[0], knightPos[1], 0));
 
    cell t;
    int x, y;
    bool visit[N + 1][N + 1];
 
    // make all cell unvisited
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;
 
    // visit starting state
    visit[knightPos[0]][knightPos[1]] = true;
 
    // loop until we have one element in queue
    while (!q.empty()) {
        t = q.front();
        q.pop();
 
        // if current cell is equal to target cell,
        // return its distance
        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;
 
        // loop for all reachable states
        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];
 
            // If reachable state is not yet visited and
            // inside board, push that state into queue
            if (isInside(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
}
 
// Driver code to test above methods
int main()
{
    int N = 30;
    int knightPos[] = { 1, 1 };
    int targetPos[] = { 30, 30 };
    cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}


9. Flood fill(Imp)

Given a 2D screen, location of a pixel in the screen and a color, 
replace color of the given pixel and all adjacent same colored 
pixels with the given color.

 Using Recursion

 The idea is simple, we first replace the color of the current pixel, 
 then recur for 4 surrounding points. The following is a detailed algorithm. 



// A recursive function to replace 
// previous color 'prevC' at  '(x, y)' 
// and all surrounding pixels of (x, y)
// with new color 'newC' and
floodFil(screen[M][N], x, y, prevC, newC)
1 If x or y is outside the screen, then return.
2 If color of screen[x][y] is not same as prevC, then return
3 Recur for north, south, east and west.
    floodFillUtil(screen, x+1, y, prevC, newC);
    floodFillUtil(screen, x-1, y, prevC, newC);
    floodFillUtil(screen, x, y+1, prevC, newC);
    floodFillUtil(screen, x, y-1, prevC, newC);


void floodFillUtil(int screen[][N], int x, int y, int prevC, int newC)
{
    // Base cases
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != prevC)
        return;
    if (screen[x][y] == newC)
        return;
 
    // Replace the color at (x, y)
    screen[x][y] = newC;
 
    // Recur for north, east, south and west
    floodFillUtil(screen, x+1, y, prevC, newC);
    floodFillUtil(screen, x-1, y, prevC, newC);
    floodFillUtil(screen, x, y+1, prevC, newC);
    floodFillUtil(screen, x, y-1, prevC, newC);
}
 
// It mainly finds the previous color on (x, y) and
// calls floodFillUtil()
void floodFill(int screen[][N], int x, int y, int newC)
{
    int prevC = screen[x][y];
      if(prevC==newC) return;
    floodFillUtil(screen, x, y, prevC, newC);
}


Using bfs:

Algorithm for BFS based approach :

Create a queue of pairs.
Insert an initial index given in the queue.
Mark initial index as visited in vis[][] matrix.

Until the queue is not empty repeat step 3.1 to 3.6
Take the front element from the queue Pop from the queue
Store current value/color at coordinate taken out from queue (precolor)
Update the value/color of the current index which is taken out from the queue

Check for all 4 direction i.e (x+1,y),(x-1,y),(x,y+1),(x,y-1) is valid or not 
and if valid then check that value at that coordinate should be equal to 
precolor and value of that coordinate in vis[][] is 0.

If all the above condition is true push the corresponding coordinate 
in queue and mark as 1 in vis[][]

int validCoord(int x, int y, int n, int m)
{
 
    if (x < 0 || y < 0) {
        return 0;
    }
    if (x >= n || y >= m) {
        return 0;
    }
    return 1;
}
 
// Function to run bfs
void bfs(int n, int m, int data[][8],
                     int x, int y, int color)
{
   
  // Visiting array
  int vis[101][101];
   
  // Initialing all as zero
  memset(vis, 0, sizeof(vis));
   
  // Creating queue for bfs
  queue<pair<int, int> > obj;
   
  // Pushing pair of {x, y}
  obj.push({ x, y });
   
  // Marking {x, y} as visited
  vis[x][y] = 1;
   
  // Until queue is emppty
  while (obj.empty() != 1)
  {
 
    // Extracting front pair
    pair<int, int> coord = obj.front();
    int x = coord.first;
    int y = coord.second;
    int preColor = data[x][y];
 
    data[x][y] = color;
     
    // Poping front pair of queue
    obj.pop();
 
    // For Upside Pixel or Cell
    if (validCoord(x + 1, y, n, m)
        && vis[x + 1][y] == 0
        && data[x + 1][y] == preColor)
    {
      obj.push({ x + 1, y });
      vis[x + 1][y] = 1;
    }
     
    // For Downside Pixel or Cell
    if (validCoord(x - 1, y, n, m)
        && vis[x - 1][y] == 0
        && data[x - 1][y] == preColor)
    {
      obj.push({ x - 1, y });
      vis[x - 1][y] = 1;
    }
     
    // For Right side Pixel or Cell
    if (validCoord(x, y + 1, n, m)
        && vis[x][y + 1] == 0
        && data[x][y + 1] == preColor)
    {
      obj.push({ x, y + 1 });
      vis[x][y + 1] = 1;
    }
     
    // For Left side Pixel or Cell
    if (validCoord(x, y - 1, n, m)
        && vis[x][y - 1] == 0
        && data[x][y - 1] == preColor)
    {
      obj.push({ x, y - 1 });
      vis[x][y - 1] = 1;
    }
  }
   
  // Printing The Changed Matrix Of Pixels
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}


10. Word ladder Problem:(same as bfs with prime banglore)

Approach: 

Start from the given start word.
Push the word in the queue
Run a loop until the queue is empty
Traverse all words that adjacent (differ by one character) to it and push the word in a queue (for BFS)
Keep doing so until we find the target word or we have traversed all words.

int shortestChainLen(
string start, string target,
set<string>& D)
{
   
    if(start == target)
      return 0;
 
    // If the target string is not
    // present in the dictionary
    if (D.find(target) == D.end())
        return 0;
 
    // To store the current chain length
    // and the length of the words
    int level = 0, wordlength = start.size();
 
    // Push the starting word into the queue
    queue<string> Q;
    Q.push(start);
 
    // While the queue is non-empty
    while (!Q.empty()) {
 
        // Increment the chain length
        ++level;
 
        // Current size of the queue
        int sizeofQ = Q.size();

        for (int i = 0; i < sizeofQ; ++i) {
 
            // Remove the first word from the queue
            string word = Q.front();
            Q.pop();
 
            // For every character of the word
            for (int pos = 0; pos < wordlength; ++pos) {
 
                // Retain the original character
                // at the current position
                char orig_char = word[pos];
 
                // Replace the current character with
                // every possible lowercase alphabet
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[pos] = c;
 
                    // If the new word is equal
                    // to the target word
                    if (word == target)
                        return level + 1;
 
                    // Remove the word from the set
                    // if it is found in it
                    if (D.find(word) == D.end())
                        continue;
                    D.erase(word);
 
                    // And push the newly generated word
                    // which will be a part of the chain
                    Q.push(word);
                }
 
                // Restore the original character
                // at the current position
                word[pos] = orig_char;
            }
        }
    }
 
    return 0;
}


11. Clone a undirected graph:  

//Design a new graph from the old graph , such that address of each node
//is different from original and the graph look same as original

GraphNode *cloneGraph(GraphNode *src)
{
    //A Map to keep track of all the
    //nodes which have already been created
    map<GraphNode*, GraphNode*> m;
    queue<GraphNode*> q;
  
    // Enqueue src node
    q.push(src);
    GraphNode *node;
  
    // Make a clone Node
    node = new GraphNode();
    node->val = src->val;
  
    // Put the clone node into the Map
    m[src] = node;
    while (!q.empty())
    {
        //Get the front node from the queue
        //and then visit all its neighbours
        GraphNode *u = q.front();
        q.pop();
        vector<GraphNode *> v = u->neighbours;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            // Check if this node has already been created
            if (m[v[i]] == NULL)
            {
                // If not then create a new Node and
                // put into the HashMap
                node = new GraphNode();
                node->val = v[i]->val;
                m[v[i]] = node;
                q.push(v[i]);
            }
  
            // add these neighbours to the cloned graph node
            m[u]->neighbours.push_back(m[v[i]]);
        }
    }
  
    // Return the address of cloned src Node
    return m[src];
}


12. Minimize count of connections required to be rearranged to make all the computers connected


Given an integer N, denoting the number of computers connected by 
cables forming a network and a 2D array connections[][], with each row (i, j) 
representing a connection between ith and jth computer, the task is to connect 
ll the computers either directly or indirectly by removing any of the given connections 
and connecting two disconnected computers. 
If it’s not possible to connect all the computers, print -1. 
Otherwise, print the minimum number of such operations required.

Approach: The idea is to use a concept similar to that of Minimum Spanning 
Tree, as in a Graph with N nodes, only N – 1 edges are required to make all the nodes connected.

Redundant edges = Total edges – [(Number of Nodes – 1) – (Number of components – 1)]

If Redundant edges > (Number of components – 1) : It is clear that there are enough wires 
that can be used to connect disconnected computers. Otherwise, print -1.


13. Shortest path from source to destination(unweighted or weight = 1)


void BFS(vector<int> adj[], int N, int src) //striver
{ 
    int dist[N];
    for(int i = 0;i<N;i++) dist[i] = INT_MAX; 
    queue<int>  q;
    
    dist[src] = 0;
    q.push(src); 

    while(q.empty()==false) 
    { 
        int node = q.front(); 
        q.pop();
         
        for(auto it:adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it]=dist[node]+1;
                q.push(it);
            }
        } 
    } 
    for(int i = 0;i<N;i++) cout << dist[i] << " "; 
    
} 


14. Snake and Ladder Problem

Given a snake and ladder board, find the minimum number of dice throws
required to reach the destination or last cell from source or 1st cell. 
Basically, the player has total control over outcome of dice throw and 
wants to find out minimum number of throws required to reach last cell.
If the player reaches a cell which is base of a ladder, the player has to 
climb up that ladder and if reaches a cell is mouth of the snake, has to 
go down to the tail of snake without a dice throw.


Shotest path in directed graph. 

struct queueEntry
{
    int v;     // Vertex number
    int dist;  // Distance of this vertex from source
};
 
// This function returns minimum number of dice throws required to
// Reach last cell from 0'th cell in a snake and ladder game.
// move[] is an array of size N where N is no. of cells on board
// If there is no snake or ladder from cell i, then move[i] is -1
// Otherwise move[i] contains cell to which snake or ladder at i
// takes to.
int getMinDiceThrows(int move[], int N)
{
    // The graph has N vertices. Mark all the vertices as
    // not visited
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    queue<queueEntry> q;
 
    // Mark the node 0 as visited and enqueue it.
    visited[0] = true;
    queueEntry s = {0, 0};  // distance of 0't vertex is also 0
    q.push(s);  // Enqueue 0'th vertex
 
    // Do a BFS starting from vertex at index 0
    queueEntry qe;  // A queue entry (qe)
    while (!q.empty())
    {
        qe = q.front();
        int v = qe.v; // vertex no. of queue entry
 
        // If front vertex is the destination vertex,
        // we are done
        if (v == N-1)
            break;
 
        // Otherwise dequeue the front vertex and enqueue
        // its adjacent vertices (or cell numbers reachable
        // through a dice throw)
        q.pop();
        for (int j=v+1; j<=(v+6) && j<N; ++j)
        {
            // If this cell is already visited, then ignore
            if (!visited[j])
            {
                // Otherwise calculate its distance and mark it
                // as visited
                queueEntry a;
                a.dist = (qe.dist + 1);
                visited[j] = true;
 
                // Check if there a snake or ladder at 'j'
                // then tail of snake or top of ladder
                // become the adjacent of 'i'
                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }
 
    // We reach here when 'qe' has last vertex
    // return the distance of vertex in 'qe'
    return qe.dist;
}



15. Minimum time required to rot all oranges

Given a matrix of dimension m*n where each cell in the matrix can have values 
0, 1 or 2 which has the following meaning:  

0: Empty cell
1: Cells have fresh oranges
2: Cells have rotten oranges
Determine what is the minimum time required so that all the oranges 
become rotten. A rotten orange at index [i,j] can rot other fresh 
orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left 
and right). If it is impossible to rot every orange then simply return -1.



Algorithm: 
Algorithm: 
Create an empty queue Q. 
Find all rotten oranges and enqueue them to Q. Also, enqueue a delimiter 
to indicate the beginning of the next time frame.
Run a loop While Q is not empty
Do following while delimiter in Q is not reached
Dequeue an orange from the queue, rot all adjacent oranges. While rotting 
the adjacent, make sure that the time frame is incremented only once. And 
the time frame is not incremented if there are no adjacent oranges.
Dequeue the old delimiter and enqueue a new delimiter. The oranges rotten
in the previous time frame lie between the two delimiters.


bool isvalid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < R && j < C);
}
 
// structure for storing coordinates of the cell
struct ele {
    int x, y;
};
 
// Function to check whether the cell is delimiter
// which is (-1, -1)
bool isdelim(ele temp)
{
    return (temp.x == -1 && temp.y == -1);
}
 
// Function to check whether there is still a fresh
// orange remaining
bool checkall(int arr[][C])
{
    for (int i=0; i<R; i++)
       for (int j=0; j<C; j++)
          if (arr[i][j] == 1)
             return true;
    return false;
}
 
// This function finds if it is possible to rot all oranges or not.
// If possible, then it returns minimum time required to rot all,
// otherwise returns -1
int rotOranges(int arr[][C])
{
    // Create a queue of cells
    queue<ele> Q;
    ele temp;
    int ans = 0;
 
    // Store all the cells having rotten orange in first time frame
    for (int i=0; i<R; i++)
    {
       for (int j=0; j<C; j++)
       {
            if (arr[i][j] == 2)
            {
                temp.x = i;
                temp.y = j;
                Q.push(temp);
            }
        }
    }
 
    // Separate these rotten oranges from the oranges which will rotten
    // due the oranges in first time frame using delimiter which is (-1, -1)
    temp.x = -1;
    temp.y = -1;
    Q.push(temp);
 
    // Process the grid while there are rotten oranges in the Queue
    while (!Q.empty())
    {
        // This flag is used to determine whether even a single fresh
        // orange gets rotten due to rotten oranges in current time
        // frame so we can increase the count of the required time.
        bool flag = false;
 
        // Process all the rotten oranges in current time frame.
        while (!isdelim(Q.front()))
        {
            temp = Q.front();
 
            // Check right adjacent cell that if it can be rotten
            if (isvalid(temp.x+1, temp.y) && arr[temp.x+1][temp.y] == 1)
            {
                // if this is the first orange to get rotten, increase
                // count and set the flag.
                if (!flag) ans++, flag = true;
 
                // Make the orange rotten
                arr[temp.x+1][temp.y] = 2;
 
                // push the adjacent orange to Queue
                temp.x++;
                Q.push(temp);
 
                temp.x--; // Move back to current cell
            }
 
            // Check left adjacent cell that if it can be rotten
            if (isvalid(temp.x-1, temp.y) && arr[temp.x-1][temp.y] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x-1][temp.y] = 2;
                temp.x--;
                Q.push(temp); // push this cell to Queue
                temp.x++;
            }
 
            // Check top adjacent cell that if it can be rotten
            if (isvalid(temp.x, temp.y+1) && arr[temp.x][temp.y+1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y+1] = 2;
                temp.y++;
                Q.push(temp); // Push this cell to Queue
                temp.y--;
            }
 
            // Check bottom adjacent cell if it can be rotten
            if (isvalid(temp.x, temp.y-1) && arr[temp.x][temp.y-1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y-1] = 2;
                temp.y--;
                Q.push(temp); // push this cell to Queue
            }
 
            Q.pop();
        }
 
        // Pop the delimiter
        Q.pop();
 
        // If oranges were rotten in current frame than separate the
        // rotten oranges using delimiter for the next frame for processing.
        if (!Q.empty()) {
            temp.x = -1;
            temp.y = -1;
            Q.push(temp);
        }
 
        // If Queue was empty than no rotten oranges left to process so exit
    }
 
    // Return -1 if all arranges could not rot, otherwise return ans.
    return (checkall(arr))? -1: ans;
}



16.0 Disjoint set naive implementation: O(n)

//Basically join all the disjoint sets into one.

void make(int v){
    parent[v] = v;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    return find_set(parent[v]);
}

//Makes a chain
void union_sets(int a , int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b)
        parent[b] = a;
}


16. Disjoint set Union (or union find)

Cycle detection using dsu in undirected graph. 

For all edge(u,v) in edges:
    x = find_set(u)
    y = find_set(v)
    if( x== y)
        //same set , cycle if found
        return true
    union(u,v)
return false

// disjoint set union using size, O(alpha(n)) = O(1)
const in N = 1e5+6;
vector<int> parent(N);
vector<int> size(N);

//dsu with path compression
void make_set(int v){
    parent[v] =v ;
    size[v] = 1;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    //path compression
    return parent[v] = find_set(parent[v]);
}

//size comparision
void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if( a!= b){
        if(size[a] < size[b])
            swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}
//dsu finished

int main() {
    for(int i = 0; i< N; i++){
        make_set(i);
    }

    int n, m; 
    cin>>n>>m;
    vector<vector<int>> edges;

    for(int i = 0; i< m; i++)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    bool cycle = false;
    for(auto i: edges){
        int u = i[0];
        int v = i[1];
        int x = find_set(u);
        int y = find_set(v);
        if(x == y){
            //Same set, cycle if found
            cycle = true;
        }
        else{
            union_sets(u,v);
        }
    }
    if(cycle)
        cout<<"Cycle if present"<<endl;
    else
        cout<<"Does not contain a cycle"<<endl;
}

16. Krunkals algorith (Minimum spanning tree)

// Spanning tree:
// Given an undireded and connected graph G(V, E), a spanning
// tree of the graph G is a tree that spans G(that is, it includes every
// vertex of G) and is subgrah of G(every edge in the tree belongs to G).

// The cost of the spanning tree the sum of the weighted of all the
// edges in the tree. 
// There can be many spanning tree. 

// No of vertices = V 
// No of edges in MST = (V-1)

// MST can be found for connected graph only. 
// Krunskals algo is a greedy algo.


Pseudocode:

1. Sort the edges in increasing order of their weights. 
2. Iterate in the soreted edges. 
    If inclusion of ith edge lead to a cycle, then skip
    this edge.  
    else
        include the edge in the mst. 

Complexity analysis: 

Time: complexity: O(Elog(V)) //sorting
Space Complexity: O(E+V)

//Implementation

const in N = 1e5+6;
vector<int> parent(N);
vector<int> size(N);

//dsu start
void make_set(int v){
    parent[v] =v ;
    size[v] = 1;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    //path compression
    return parent[v] = find_set(parent[v]);  //time complexity changes from o(n) to o(Log(n)) complexity
}

//size comparision  final time complexity O(alpha(n)) 
void union_sets(int a, int b){ 
    a = find_set(a);
    b = find_set(b);
    if( a!= b){
        if(size[a] < size[b])
            swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}
//dsu finished

int main() {
    for(int i = 0; i< N; i++){
        make_set(i);
    }

    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges;

    for(int i = 0; i< m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(), edges.end());
    int cost = 0;
    for(auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
         int x = find_set(u);
         int y= find_set(v);
         if( x == y)
            countinue;
        else
        {
            cout<<u<<" "<<v<<endl;
            cost += w;
            union_sets(u,v);
        }
    }
    cout<<cost;


17. Primes Algorithm for MST. Greedy //from take_u_forward

Idea:
Select an arbitrary vertex s to start the tree from 
While (there are still nontree vertices)
    select the edges of minimum wight between a  
    tree and nontree vertex. 
    Add the selected edge and vertex to the tree. 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,m;
    cin >> N >> m;
    vector<pair<int,int> > adj[N]; 

    int a,b,wt;
    for(int i = 0; i<m ; i++){
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }   
    
    int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
    return 0;
}

18. Dijkstras algorithm:

Given a weighted graph. Find the single source shortest path 
from a vertex u to all the vertices in the graph. If the node is  
unreachable, then print -1;

Note. The weights of the edges must be positive. 


Idea:

1. Assign a distance value to all vertices in the intput graph. 
Initialize all distance values as INFINITE. Assign distance value  
as 0 for the source vertex. 

2. While priority_queue/set is not empty
    A. Pick a vertex u from set s that has minimum distance value. 
    B. Update distance value of all adjacne vertices of u. 



#define INF 99999

// function to create an edge
void addEdge(vector<pair<int, int>> graph[], int u, int v, int w){
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

void dijkstras(vector<pair<int, int>> graph[], int src, int V){
    // use priority queue as min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // distance vector
    vector<int>dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    // normal BFS traversal
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        // traverse for the neighbors of u
        for(auto x : graph[u]){
            // x = {v, wt}
            int v = x.first;
            int wt = x.second;
            if(dist[v]>dist[u] + wt){
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout<<"Vertex   Distance from src\n";
    for(int i=0; i<V; i++)
        cout<<i<<"\t"<<dist[i]<<endl;
}

int main(){
    int V = 9;
    vector<pair<int, int>> graph[V];
    addEdge(graph ,0, 1, 4); 
    addEdge(graph ,0, 7, 8); 
    addEdge(graph ,1, 2, 8); 
    addEdge(graph ,1, 7, 11); 
    addEdge(graph ,2, 3, 7); 
    addEdge(graph ,2, 8, 2); 
    addEdge(graph ,2, 5, 4); 
    addEdge(graph ,3, 4, 9); 
    addEdge(graph ,3, 5, 14); 
    addEdge(graph ,4, 5, 10); 
    addEdge(graph ,5, 6, 2); 
    addEdge(graph ,6, 7, 1); 
    addEdge(graph ,6, 8, 6); 
    addEdge(graph ,7, 8, 7); 

    dijkstras(graph, 0, 9);
}
16. Strongly connected components in a graph(Kosaraju algorith)

//IF we can reah from every vertext to every other vertex
//in a component then it's called Strongly connnected component.

// All the nodes in a component are always strongly connected
//in an undirected graph but not in directed graph.

 

19. Cheapest Flights Within K Stops

The key difference with the classic Dijkstra algo is, we dont maintain 
the global optimal distance to each node, i.e. ignore below optimization:
alt ← dist[u] + length(u, v)
if alt < dist[v]:
Because there could be routes which their length is shorter but pass more
 stops, and those routes dont necessarily constitute the best route in the end. 
 To deal with this, rather than maintain the optimal routes with 0 to K stops for 
 each node, the solution simply put all possible routes into the priority queue, 
 so that all of them has a chance to be processed. IMO, this is the most brilliant part.


public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        Map<Integer, Map<Integer, Integer>> prices = new HashMap<>();
        for (int[] f : flights) {
            if (!prices.containsKey(f[0])) prices.put(f[0], new HashMap<>());
            prices.get(f[0]).put(f[1], f[2]);
        }
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> (Integer.compare(a[0], b[0])));
        pq.add(new int[] {0, src, k + 1});
        while (!pq.isEmpty()) {
            int[] top = pq.remove();
            int price = top[0];
            int city = top[1];
            int stops = top[2];
            if (city == dst) return price;
            if (stops > 0) {
                Map<Integer, Integer> adj = prices.getOrDefault(city, new HashMap<>());
                for (int a : adj.keySet()) {
                    pq.add(new int[] {price + adj.get(a), a, stops - 1});
                }
            }
        }
        return -1;
    }


20. Bellman ford algorithm:

//Idea

i. Initially d[v] = 0 and for all other elements d[] = inf  

ii. In each pass, relax all the edges. 
    ie. for edges (a,b) having weight w,
        d[b] = min(d[b], d[a] +w)

iii. Assuming no negative edge cycle, since there are n vertices  
shortest path can only contain 'n-1' edges. Therefore, we will  
get our answer in at most 'n-1' pass.  

iv. If we run for one more time and edges decreases then there is negative cycle  
//it works with negative edges and negative cycles.
//Basically used to detect negative cycle


#code   

const int INF = 1e9;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges;
    for(int i = 0; i< m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }

    int src;
    cin>>src;

    vector<int> dist(n, INF);
    dist[src] = 0;

    bool negative_cyle = false;

    for(int i = 0; i< n-1; i++){
        //negative_cyle = fase;
        for(auto e: edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            // if(dist[v] > w + dist[u])
            //     change = true;
            dist[v] =min( dist[v], w + dist[u]);;
        }
    }
    // commented codes are for detecting negative cycle
    for(auto i: dist)
        cout<<i<<" ";
    cout<<endl;
}



21. Floyd warshall algorithm  || All pairs shortest path  


//use random node k to check distance between i, j

d[i][j] = min(d[i][j] , d[j][k] + d[k][j]);

//it can also detect negative edge weight cycle
//if we have -ve distance from a vertex to itself then it has negative edge
//weight cycle and shortest path can't be found.

//including adjacent node won't affect distance value


const int INF = 1e9;

int main(){
    //distance matrix of graph
    vector<vector<int>> graph = {
        {0,5, INF, 10},
        {INF, 0,3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    int n = graph.size();

    vector<vector<int>> dist = graph;
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j< n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< n; j++)
        {
            if(dist[i][j] == INF)
                cout<<"INF ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}


22. Strongly connected components|| Kosaraju algorithm

//strongly connected components
if we can reach from every vertex to every other vertex in a component
the it is call scc   

//All nodes in a component are always strongly connected in a 
//undirected graph. 


#bruteforce
i. Find all pairs shortest path using floyd warshall algorithm
ii. check if between any 2 pairs, the distance is INF except self loops
    if true 
        then component is not SCC  
    else
        scc  

O(N^3)

//on reversing all edges of the graph, the type of graph won't change.
(scc will remain as ) 

//pseudo 
1.perform dfs traversal of graph. push node to stack before returning  
2. find the transpose graph by reversing the edges. 
3. Pop nodes one by one from stack and again do dfs on modified graph.(keep popping nodes)
   Each successfully dfs gives 1-scc.  

//code
#include<bits/stdc++.h>
using namespace std;
#define V 8
#define pb push_back

unordered_map<int,vector<int>> adj,rev;

void DFS1(int i,vector<bool>& visited,stack<int>& mystack)
{
    visited[i]=true;
    for(int j: adj[i])
        if(visited[j]==false)
            DFS1(j,visited,mystack);

    mystack.push(i);
}

void reverse()
{
    for(int i=0;i<V;++i)
    {
        for(int j: adj[i])
            rev[j].pb(i);
    }
}

void DFS2(int i,vector<bool>& visited)
{
    cout<<i<<" ";
    visited[i] = true;
    for(int j: rev[i])
        if(!visited[j])
            DFS2(j,visited);
}

void findSCCs()
{
    stack<int> mystack;

    vector<bool> visited(V,false);
    for(int i=0;i<V;++i)
        if(!visited[i])
            DFS1(i,visited,mystack);

    reverse();

    for(int i=0;i<V;++i)
        visited[i] = false;

    cout<<"Strongly Connected Components are:\n";
    while(!mystack.empty())
    {
        int curr = mystack.top();
        mystack.pop();
        if(visited[curr]==false)
        {
            DFS2(curr,visited);
            cout<<"\n";
        }
    }
}

int main()
{
    adj[0].pb(1);
    adj[1].pb(2);
    adj[2].pb(0);
    adj[2].pb(3);
    adj[3].pb(4);
    adj[4].pb(5);
    adj[4].pb(7);
    adj[5].pb(6);
    adj[6].pb(4);
    adj[6].pb(7);

    findSCCs();
    return 0;
}


23. Tarjans strongly connected components algorithm:

Tree edge: (U, V) U- present , V - child
Forward edge: (U, V) U - ancestor, V - dessendent
Backe edge: (U, V) U descendent , v - ancestor 
cross edge: don't have ancestor, descendent relationship'n

i. low -> Node with lowest disc time accessible. 
//low value will keep changing 
ii. disc  -> discovery time of node  
//but discovery time will remain same once discoverd

low[u] == disc[u] , then it is a head node  

stack is required to keep track of nodes present in scc.  
, if edge is pointing to a visited node already in scc the it is a  
back edge else cross edge.  

//why cross-edge is not processed 
-we don't want to again cover the already covered scc'  

#include<bits/stdc++.h>
using namespace std;
#define V 7
#define pb push_back

unordered_map<int,vector<int>> adj;

void DFS(int u,vector<int>& disc,vector<int>& low,stack<int>& mystack,vector<bool>& presentInStack)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time+=1;
    mystack.push(u);
    presentInStack[u] = true;

    for(int v: adj[u])
    {
        if(disc[v]==-1) //If v is not visited
        {
            DFS(v,disc,low,mystack,presentInStack);
            low[u] = min(low[u],low[v]);
        }
        //Differentiate back-edge and cross-edge
        else if(presentInStack[v])  //Back-edge case
            low[u] = min(low[u],disc[v]);
    }

    if(low[u]==disc[u]) //If u is head node of SCC
    {
        cout<<"SCC is: ";
        while(mystack.top()!=u)
        {
            cout<<mystack.top()<<" ";
            presentInStack[mystack.top()] = false;
            mystack.pop();
        }
        cout<<mystack.top()<<"\n";
        presentInStack[mystack.top()] = false;
        mystack.pop();
    }
}

void findSCCs_Tarjan()
{
    vector<int> disc(V,-1),low(V,-1);
    vector<bool> presentInStack(V,false);   //Avoids cross-edge
    stack<int> mystack;

    for(int i=0;i<V;++i)
        if(disc[i]==-1)
            DFS(i,disc,low,mystack,presentInStack);
}

int main()
{
    adj[0].pb(1);
    adj[1].pb(2);
    adj[1].pb(3);
    adj[3].pb(4);
    adj[4].pb(0);
    adj[4].pb(5);
    adj[4].pb(6);
    adj[5].pb(6);
    adj[6].pb(5);

    findSCCs_Tarjan();
    return 0;
}

//TIME COMPLEXITY: O(V+E)



24. Find bridges in a graph using tarjans algorithm:

//A bridge is an edge removing which increases the no of components.
//note brides in a network can represent critical wires or connections
//We can eliminate such vulnerabilities by adding edges or redesigning
//which increases reliability. (as there will not be a single point of failure)


time complexity: O(E. (V+E)

//naive
for each edge: (repeat)
i. Remove the edge from graph. 
ii. Perform dfs and see if there is only 1 component. if(component == 1)
then removed edge is not  a bridge else removed edge is a bridge.  
iii. Put back teh edge into the graph.  

//condition for a bridge
- if there is no back edge from a subgraph to it's ancestor or parent 
(across the edge being checked) then the edge will be a bridge.  '

imp: we don't consider child to parent edge' 
because: we will assume edge to be removed(we are not modifiing the list)

low[child] > disc[parent] for bridges

#define V 5
#define pb push_back

unordered_map<int,vector<int>> adj;

void DFS(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<pair<int,int>>& bridge)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time+=1;

    for(int v: adj[u])
    {
        if(disc[v]==-1) //If v is not visited
        {
            parent[v] = u;
            DFS(v,disc,low,parent,bridge);
            low[u] = min(low[u],low[v]);

            if(low[v] > disc[u])
                bridge.pb({u,v});
        }
        else if(v!=parent[u])   //Ignore child to parent edge
            low[u] = min(low[u],disc[v]);
    }
}

void findBridges_Tarjan()
{
    vector<int> disc(V,-1),low(V,-1),parent(V,-1);
    vector<pair<int,int>> bridge;

    for(int i=0;i<V;++i)
        if(disc[i]==-1)
            DFS(i,disc,low,parent,bridge);

    cout<<"Bridges are: \n";
    for(auto it: bridge)
        cout<<it.first<<"-->"<<it.second<<"\n";
}

int main()
{
    adj[0].pb(2);
    adj[2].pb(0);
    adj[0].pb(3);
    adj[3].pb(0);
    adj[1].pb(0);
    adj[0].pb(1);
    adj[2].pb(1);
    adj[1].pb(2);
    adj[3].pb(4);
    adj[4].pb(3);

    findBridges_Tarjan();
    return 0;
}

//TIME COMPLEXITY: O(V+E)


25. Articulation point: 

If a node is a articulation point then removing this edge will increase the no of components in graph 

//simple approach
//Time = O(V.(V+E))

1. For each node:
    a. Take out the node and all passing edges. 
    b. Find if we have only 1 component(use DFS)
    c. If components =1 then node is not Articulation point 
        else node is articulation point   

//Observations
Condition for an Articulation point 
a. If node u is root of DFS tree and has atleast 2 children(subgraph)

//how to detect articulation point for case a
i. Keep childen counter for each node:
ii. On calling dfs on each edge, mark the entire subgraph
iii. Call dfs on other edges only if node is not visited 
iv. Increment children counts on each unique DFS call 
v. If children > 1 then node is articulation point .  

b. Node U is not root of DFS tree and it has a child V such that no vertex in subtree rooted with V has a 
backedge to one of the ancesters of U. 

//how to detect ap for case b
i. We need to find the order of vertice from earliest 
to lastest to detect back-edges
- we use timestamp to mark nodes with increasing value  

ii. We need to maintain the earliest possible node accesible 
for a given node which will indicate if we have any back edge  
 - for this we will assign low value to each node  

iii. edge from child to parent is not back edge  
because parent is gonna get removed for ap check. 


#include<bits/stdc++.h>
using namespace std;
#define V 5
#define pb push_back

unordered_map<int,vector<int>> adj;

void DFS(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<bool>& articulation_Point)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time+=1;
    int children = 0;

    for(int v: adj[u])
    {
        if(disc[v]==-1) //If v is not visited
        {
            children += 1;
            parent[v] = u;
            DFS(v,disc,low,parent,articulation_Point);
            low[u] = min(low[u],low[v]);

            if(parent[u]==-1 and children>1)    //Case-1: U is root
                articulation_Point[u] = true;

            if(parent[u]!=-1 and low[v]>=disc[u])   //Case-2: Atleast 1 component will get separated
                articulation_Point[u] = true;
        }
        else if(v!=parent[u])   //Ignore child to parent edge
            low[u] = min(low[u],disc[v]);
    }   
}

void findAPs_Tarjan()
{
    vector<int> disc(V,-1),low(V,-1),parent(V,-1);
    vector<bool> articulation_Point(V,false);   //Avoids cross-edge

    for(int i=0;i<V;++i)
        if(disc[i]==-1)
            DFS(i,disc,low,parent,articulation_Point);

    cout<<"Articulation Points are: ";
    for(int i=0;i<V;++i)
        if(articulation_Point[i]==true)
            cout<<i<<" ";
}

int main()
{
    adj[0].pb(2);
    adj[2].pb(0);
    adj[0].pb(3);
    adj[3].pb(0);
    adj[1].pb(0);
    adj[0].pb(1);
    adj[2].pb(1);
    //adj[2].pb(4);
    //adj[4].pb(2);
    adj[1].pb(2);
    adj[3].pb(4);
    adj[4].pb(3);

    findAPs_Tarjan();
    return 0;
}

//TIME COMPLEXITY: O(V+E)

26. Topological sorting:


//Linear ordering of vertices such  that
//if there is an edge u-> v appears
//u appears before v in that ordering

//Only possible directed acyclic graph

 #include <bits/stdc++.h>
using namespace std;

class Solution{
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1; 
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                findTopoSort(it, vis, st, adj); 
            }
        }
        st.push(node); 
    }
    public:
    vector<int> topoSort(int N, vector<int> adj[]) {
        stack<int> st; 
        vector<int> vis(N, 0); 
        for(int i = 0;i<N;i++) {
            if(vis[i] == 0) {
                findTopoSort(i, vis, st, adj); 
            }
        }
        vector<int> topo;
        while(!st.empty()) {
            topo.push_back(st.top()); 
            st.pop(); 
        }
        return topo; 
        
    }
};