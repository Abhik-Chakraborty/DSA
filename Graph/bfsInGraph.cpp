#include<bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, vector<int>>& adjList, vector<pair<int, int>> edges){
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
void bfs(unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //store front node in ans
        ans.push_back(frontNode);

        //Traverse all neighbour of frontNode
        for(auto it : adjList[frontNode]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
            }
        }
    }
}

vector <int> BFS(int vertex, vector<pair<int, int>> edges){
    unordered_map<int, vector<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    //traverse all components of a graph
    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;

}
int main() {
    int vertex = 5; // Total number of vertices (0 to 4)
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3},
        {3, 4}
    };

    vector<int> result = BFS(vertex, edges);

    // Output the BFS traversal order
    cout << "BFS Traversal: ";
    for(int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}