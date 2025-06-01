class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current, int index) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) return;

        for (int i = index; i < candidates.size(); ++i) {
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, current, i);
            current.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, result, current, 0);
        return result;
    }
};