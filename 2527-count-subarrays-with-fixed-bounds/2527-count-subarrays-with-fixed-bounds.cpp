class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long res = 0;
        int leftBound = -1;
        int lastMin = -1;
        int lastMax = -1;

        for(int i = 0; i < n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                leftBound = i;
            }
            if(nums[i] == minK){
                lastMin = i;
            }
            if(nums[i] == maxK){
                lastMax = i;
            }
            int validStart = min(lastMin, lastMax);
            if(validStart > leftBound){
                res += validStart - leftBound;
            }
        }
        return res;
    }
};