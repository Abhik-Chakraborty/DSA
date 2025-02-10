class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;
    
        for (char ch : s) {
            if (isdigit(ch)) {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                stk.push(ch);
            }
        }

        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }

        return result;
    }
};