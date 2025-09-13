#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph
{
    int V;
    list<int> *l; // dynamic int array : int *arr;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    // DFS Traversal
    void DFSHelper(int u, vector<bool> &visited)
    { // O(V+E)
        cout << u << " ";
        visited[u] = true;

        for (int v : l[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                DFSHelper(v, visited);
            }
        }
    }

    void DFS()
    {
        int src = 0;
        vector<bool> vis(V, false);

        DFSHelper(src, vis);
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.DFS();

    return 0;
}