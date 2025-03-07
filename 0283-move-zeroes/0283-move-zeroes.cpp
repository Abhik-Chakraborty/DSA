class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        //trying to get zero and point it to j pointer.
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        if(j == -1) return;
        // I got j's pos
        for(int i = j + 1; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }

    }
};