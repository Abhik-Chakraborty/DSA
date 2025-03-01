class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n-1){
            if(nums[i] == nums[i + 1]){
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
                i += 2;
            }
            else{
                i++;
            }
        }
        int j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                if(i != j){
                    nums[i] = 0;
                }
                j++;
            }
        }
        return nums;
    }
};