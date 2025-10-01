// Required for input/output, vector, and list (for the adjacency list).
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

/**
 * @brief Represents a directed graph using an adjacency list.
 */
class Graph
{
    int V; // Number of vertices
    // Pointer to an array of lists. Each list stores the neighbors of a vertex.
    list<int> *l;

public:
    /**
     * @brief Constructs a new Graph object.
     *
     * @param V The number of vertices in the graph.
     */
    Graph(int V)
    {
        this->V = V;
        // Dynamically allocate an array of V lists.
        l = new list<int>[V];
    }

    /**
     * @brief Adds a directed edge from vertex u to vertex v.
     *
     * @param u The source vertex.
     * @param v The destination vertex.
     */
    void addEdge(int u, int v)
    {
        // Add v to the adjacency list of u.
        l[u].push_back(v);
    }

    /**
     * @brief A recursive DFS helper function to detect cycles.
     * @details This function explores the graph from a starting node. It uses two boolean arrays:
     * `vis` to keep track of all visited nodes ever, and `recPath` (recursion path) to track
     * nodes that are currently in the recursion stack for the current DFS traversal. A cycle is
     * detected if we encounter a neighbor that is already in the current `recPath`.
     *
     * @param curr The current vertex being visited.
     * @param vis The global visited array.
     * @param recPath The array tracking the current recursion path.
     * @return true If a cycle is detected in the traversal from `curr`.
     * @return false If no cycle is detected.
     */
    bool isCycleDirDFS(int curr, vector<bool> &vis, vector<bool> &recPath)
    {
        // Mark the current node as visited and as part of the current recursion path.
        vis[curr] = true;
        recPath[curr] = true;

        // Iterate over all neighbors of the current vertex.
        for (int neighbour : l[curr])
        {
            // If the neighbor has not been visited yet, recurse on it.
            if (!vis[neighbour])
            {
                if (isCycleDirDFS(neighbour, vis, recPath))
                {
                    // If the recursive call finds a cycle, propagate the result up.
                    return true;
                }
            }
            // If the neighbor is already visited AND it's on the current recursion path...
            else if (recPath[neighbour])
            {
                // ... we have found a back edge, which means there is a cycle.
                return true;
            }
        }

        // Backtrack: Remove the current node from the recursion path as we return.
        recPath[curr] = false;
        return false;
    }

    /**
     * @brief Checks if the graph contains a cycle.
     * @return true If the graph has at least one cycle.
     * @return false If the graph is a Directed Acyclic Graph (DAG).
     *
     * ## Overall Approach
     * The algorithm uses Depth-First Search (DFS) to detect cycles. A standard `visited` array
     * is not enough for a directed graph. We also need to know if we've revisited a node *within the same path*
     * of the current traversal. For this, a second boolean array, `recPath` (recursion path), is used.
     *
     * The `isCycle` function iterates through all vertices to handle disconnected components of the graph.
     * For each unvisited vertex, it initiates a DFS traversal (`isCycleDirDFS`).
     *
     * ## Time Complexity: O(V + E)
     * Where V is the number of vertices and E is the number of edges. This is the standard time
     * complexity for a DFS traversal of a graph represented by an adjacency list. Each vertex
     * and each edge is visited exactly once.
     *
     * ## Space Complexity: O(V)
     * The space is dominated by the `vis` and `recPath` vectors, as well as the recursion stack depth,
     * all of which are proportional to the number of vertices in the worst case.
     */
    bool isCycle()
    {
        // `vis` keeps track of all nodes visited in any DFS traversal.
        vector<bool> vis(V, false);
        // `recPath` keeps track of nodes in the current traversal path only.
        vector<bool> recPath(V, false);

        // This loop ensures that we check all components of a possibly disconnected graph.
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                // If an unvisited node is found, start a new DFS traversal from it.
                if (isCycleDirDFS(i, vis, recPath))
                {
                    return true; // If any traversal finds a cycle, we're done.
                }
            }
        }
        // If we finish checking all nodes and find no cycles, the graph is acyclic.
        return false;
    }
};

int main()
{
    // --- Test Case ---
    // Create a graph with 4 vertices.
    // The edges are: 1->0, 0->2, 2->3, 3->0
    // This creates a cycle: 0 -> 2 -> 3 -> 0
    Graph g(4);

    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    // Call the function to detect if a cycle exists.
    cout << "Is there a cycle in the directed graph? " << (g.isCycle() ? "Yes" : "No") << endl; // Expected: Yes

    return 0;
}
