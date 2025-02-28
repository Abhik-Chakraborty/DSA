class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int, int> num_map;
        for (int num : nums) {
            num_map[num] = 1;  
        }
        vector<int> distinct_nums;
        for (auto& entry : num_map) {
            distinct_nums.push_back(entry.first);
        }
        sort(distinct_nums.rbegin(), distinct_nums.rend());

        if (distinct_nums.size() < 3) {
            return distinct_nums[0];  
        }

        return distinct_nums[2];
    }
};