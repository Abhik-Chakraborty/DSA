class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; 

        vector<string> rows(numRows, "");

        int i = 0;
        int n = s.length();
        
        while (i < n) {
            for (int row = 0; row < numRows && i < n; row++) {
                rows[row] += s[i++];
            }
            for (int row = numRows - 2; row >= 1 && i < n; row--) {
                rows[row] += s[i++];
            }
        }

        string result = "";
        for (int row = 0; row < numRows; row++) {
            result += rows[row];
        }

        return result;
    }
};