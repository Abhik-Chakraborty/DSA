class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;
        for(int i = 0; i< n; i++){
            if(visited[i] == 0){
                dfs(i, isConnected, visited, n);
                count++;
            }
        }
        return count;
    }
    void dfs(int index, vector<vector<int>>& isConnected, vector<int>& visited, int n){
        visited[index] = 1;
        for(int i = 0; i < n; i++){
            if(isConnected[index][i] == 1 && visited[i] == 0){
                dfs(i, isConnected, visited, n);
            }
        }
    }
};