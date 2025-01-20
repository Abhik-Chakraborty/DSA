class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, pair<int, int>> posMap;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                posMap[mat[i][j]] = {i, j};
            }
        }
        
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        for (int i = 0; i < arr.size(); ++i) {
            int num = arr[i];
            if (posMap.find(num) != posMap.end()) {
                auto [row, col] = posMap[num];
                rowCount[row]++;
                colCount[col]++;
                if (rowCount[row] == n || colCount[col] == m) {
                    return i;  
                }
            }
        }
        
        return -1;
    }
};