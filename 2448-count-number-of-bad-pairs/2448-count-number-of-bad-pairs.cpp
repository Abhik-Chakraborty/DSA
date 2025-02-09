class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freqMap;
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            int key = i - nums[i];
            goodPairs += freqMap[key];
            freqMap[key]++;
        }

        long long totalPairs = (long long)n * (n - 1) / 2;
        return totalPairs - goodPairs;
    }
};