class Solution {
public:
    int findMaxElement(const vector<int>& nums) {
        int maxVal = nums[0];
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
        }
        return maxVal;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = findMaxElement(nums); 
        long long result = 0;
        int count = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == maxVal) {
                count++;
            }

            while (count >= k) {
                if (nums[left] == maxVal) {
                    count--;
                }
                left++;
            }

            result += left;
        }

        return result;
    }
};