class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0)); //visited array 
        queue<pair<pair<int,int>, int>> q; // {{row, col}, time}

        //Initailly we need to find the already rotten orgenges, and push them into the queue.
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }else{
                    vis[i][j] = 0;
                }
            }
        }
        int maxTime = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            // {{row, col}, time}
            int row = q.front().first.first; 
            int col = q.front().first.second; 
            int time = q.front().second;
            maxTime = max(maxTime, time);
            q.pop();
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i]; // neighbour row
                int ncol = col + dcol[i]; //neighbour col
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n
                    && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)                  
                { 
                    q.push({{nrow, ncol}, time + 1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return maxTime;
    }
};