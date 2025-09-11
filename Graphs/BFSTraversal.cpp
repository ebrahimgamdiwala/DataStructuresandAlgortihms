#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph{
    int V;
    list<int> *l; //dynamic int array : int *arr;

    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void BFS(){
        queue<int> q;
        q.push(0);

        vector<bool> visited(V, false);
        visited[0] = true;

        while (q.size()>0)
        {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for(int v : l[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }

        }
        cout << endl;
    }

};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.BFS();

    return 0;
}