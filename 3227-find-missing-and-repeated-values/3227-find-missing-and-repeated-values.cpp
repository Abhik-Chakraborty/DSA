class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> count;
        vector<int> result(2);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                count[grid[i][j]]++;
            }
        }
        
        for (int i = 1; i <= n * n; ++i) {
            if (count[i] == 2) {
                result[0] = i;  
            }
            else if (count[i] == 0) {
                result[1] = i; 
            }
        }
        
        return result;
    }
};