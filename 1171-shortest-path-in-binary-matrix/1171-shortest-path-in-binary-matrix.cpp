class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1}, {1, -1}, {1, 0}, {1, 1}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({1, 0, 0}); 
        dist[0][0] = 1;

        while (!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == n - 1)
                return d;

            for (auto& dir : directions) {
                int newX = x + dir[0], newY = y + dir[1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0) {
                    if (d + 1 < dist[newX][newY]) {
                        dist[newX][newY] = d + 1;
                        pq.push({d + 1, newX, newY});
                    }
                }
            }
        }

        return -1;
    }
};