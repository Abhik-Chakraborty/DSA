class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int highestCount = 0;
        for(int i  = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count++;
                highestCount = max(highestCount, count);
            }
            else {
                count = 0;
            }
        }
        return highestCount;
    }
};