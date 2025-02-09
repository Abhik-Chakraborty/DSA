class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, window_or = 0, max_len = 0;

        for (int right = 0; right < n; ++right) {
            while ((window_or & nums[right]) != 0) {
                window_or ^= nums[left];
                left++;
            }
            window_or |= nums[right];
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};