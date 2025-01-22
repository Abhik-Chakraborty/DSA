class Solution {
public:
    void generateParenthesesHelper(int open, int close, int n, string current, vector<string>& result) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (open < n) {
            generateParenthesesHelper(open + 1, close, n, current + "(", result);
        }
        
        if (close < open) {
            generateParenthesesHelper(open, close + 1, n, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesesHelper(0, 0, n, "", result);
        return result;
    }
};