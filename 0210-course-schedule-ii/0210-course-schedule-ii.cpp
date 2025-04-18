class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, vector<int>& result){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis, result) == true){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        result.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);  
        }

        vector<int> vis(numCourses, 0);  
        vector<int> pathVis(numCourses, 0);  
        vector<int> result;  

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis, result)) {
                    return {};  
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;

    }
};