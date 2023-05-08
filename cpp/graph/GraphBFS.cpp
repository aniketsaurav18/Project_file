#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V; // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    vector<list<int>> adj;

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    void BFS(int s);
    // prints DFS traversal form a given source s
    void DFS(int s);
    void DFSuntil(int i, vector<int> &vt);
};
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{

    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    vector<int> visitedbfs;
    visitedbfs.resize(V, false);
    queue<int> q;

    visitedbfs[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (auto it : adj[u])
        {
            if (!visitedbfs[it])
            {
                visitedbfs[it] = true;
                // cout << it << " ";
                q.push(it);
            }
        }
    }
}

void Graph::DFS(int s)
{
    vector<int> visited;
    visited.resize(V, false);
    visited[s] = true;
    cout << s << " ";

    for (auto it : adj[s])
    {
        if (visited[it] == false)
        {

            DFSuntil(it, visited);
        }
    }
}
void Graph ::DFSuntil(int it, vector<int> &vt)
{

    vt[it] = true;
    cout << it << " ";
    for (auto i : adj[it])
    {
        if (!vt[i])
        {

            DFSuntil(i, vt);
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);
    return 0;
}