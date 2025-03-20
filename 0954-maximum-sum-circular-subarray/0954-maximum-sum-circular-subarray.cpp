class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currMax = 0;
        int totalSum = 0;
        int minSum = INT_MAX;
        int currMin = 0;
        for(int i = 0; i < nums.size(); i++){
            //for maxSubarray
            currMax += nums[i];
            maxSum = max(currMax, maxSum);
            if(currMax < 0) currMax = 0;
            //for minSubarray
            currMin += nums[i];
            minSum = min(currMin, minSum);
            if(currMin > 0) currMin = 0;

            totalSum += nums[i];

        }
        if(totalSum == minSum){
            return maxSum;
        }
        return max(maxSum, totalSum - minSum);
    }
};