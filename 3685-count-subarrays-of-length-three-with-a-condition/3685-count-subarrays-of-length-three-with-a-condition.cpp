class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        if(nums.size() < 3){
            return 0;
        }
        int count = 0;

        for(int i = 1; i < nums.size()-1; i++){
            int first = nums[i - 1];
            int second = nums[i];
            int thrid = nums[i + 1];

            if(first + thrid == second/2.0){
                count++;
            }
        }
        return count;
    }
};