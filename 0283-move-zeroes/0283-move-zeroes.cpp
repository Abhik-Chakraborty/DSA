class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]); //[1, 3, 12]
            }
        }
        int tempSize = temp.size();
        for(int i = 0; i < tempSize; i++){
            nums[i] = temp[i];
        }
        for(int i = tempSize; i < nums.size(); i++){
            nums[i] = 0;
        }

    }
};