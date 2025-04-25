class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        //{diff, {row, col}}
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq; //minheap
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int delrow[] ={-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m - 1)return diff;

            for(int i = 0; i < 4; i++){
                int newRow = row + delrow[i];
                int newCol = col + delcol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){
                    int newEffort = max(abs(heights[row][col] - heights[newRow][newCol]), diff);

                    if(newEffort < dist[newRow][newCol]){
                        dist[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }

        }
        return 0;
    }

    // Time Complexity : using Djiktras -> O(E log V); E : Total number of edges, V : Total number of nodes; 
    //Space Complexity : O(n x m)
};