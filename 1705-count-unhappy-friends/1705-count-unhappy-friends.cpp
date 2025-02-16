class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<unordered_map<int, int>> rank(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                rank[i][preferences[i][j]] = j;
            }
        }

        vector<int> pairWith(n, -1);
        for (auto& p : pairs) {
            int a = p[0], b = p[1];
            pairWith[a] = b;
            pairWith[b] = a;
        }

        int unhappyCount = 0;
        for (int x = 0; x < n; ++x) {
            int y = pairWith[x];  
    
            for (int u : preferences[x]) {
                if (u == y) break;  
                
                int v = pairWith[u];  
                if (rank[u][x] < rank[u][v] && rank[x][u] < rank[x][y]) {
                    unhappyCount++;
                    break;
                }
            }
        }

        return unhappyCount;
    }
};