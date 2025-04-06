class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int index = -1;  
        int maxCount = -1;  
        int n = mat.size();  
        int m = mat[0].size();  

        for (int i = 0; i < n; i++) {
            int countRows = 0;
            for(int j = 0; j < m; j++){
                countRows += mat[i][j];            
            }
            if (countRows > maxCount) {
                maxCount = countRows;
                index = i;
            }
        }
        return {index, maxCount};
    }
};