class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i = 1; i <= nums.size(); i++){
            sum += i; 
        }

        int sum2 = 0;
        for(int i = 0; i < nums.size(); i++){
            sum2 += nums[i];
        }

        return sum - sum2;
    }
};