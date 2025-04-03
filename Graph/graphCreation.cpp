#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    map<int, vector<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected graph
        //  direction = 0 -> directed graph

        // create an edge from u to v
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for (auto it : adj)
        {
            cout << it.first << " -> ";
            for (auto j : it.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout<<"Enter the number of node : ";
    cin >> n;

    int m; 
    cout<<"Enter the number of edges : ";
    cin>>m;

    graph g;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        //cretaed an undirected graph
        g.addEdge(u,v,0);
    }
    //printing graph
    g.printAdjList();
}