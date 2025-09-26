
/*
Graph used in this example:

    0
    |
    1
   / \
  2---3
   \
    4

Edges:
0-1, 1-2, 1-3, 2-3, 2-4
There is a cycle: 1-2-3-1
*/

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph
{
    int V;        // Number of vertices
    list<int> *l; // Array of adjacency lists

public:
    // Constructor: initializes the graph with V vertices
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    // Adds an undirected edge between u and v
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // Helper function to check for a cycle in an undirected graph using BFS
    // src: starting node, vis: visited array
    bool isCycleUndirBFS(int src, vector<bool> &vis)
    {                            // O(V+E)
        queue<pair<int, int>> q; // {current node, parent node}

        q.push({src, -1}); // Start BFS from src, parent is -1
        vis[src] = true;   // Mark src as visited

        while (!q.empty())
        {
            int u = q.front().first;        // Current node
            int parentU = q.front().second; // Parent of current node
            q.pop();

            // Traverse all neighbours of u
            for (int v : l[u])
            {
                if (!vis[v])
                {
                    // If neighbour v is not visited, mark and enqueue it
                    vis[v] = true;
                    q.push({v, u});
                }
                else if (v != parentU)
                {
                    // If neighbour is visited and not parent, cycle found
                    return true;
                }
            }
        }

        // No cycle found in this component
        return false;
    }

    // Checks for cycle in all components of the graph
    bool isCycle()
    {
        vector<bool> visited(V, false); // Visited array for all nodes
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                // If node i is not visited, check for cycle from i
                if (isCycleUndirBFS(i, visited))
                {
                    return true;
                }
            }
        }
        // No cycle in any component
        return false;
    }
};

int main()
{
    Graph g(5);
    // Add edges as per the diagram above
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    // Check for cycle
    cout << "Cycle detected: " << (g.isCycle() ? "Yes" : "No") << endl;

    return 0;
}