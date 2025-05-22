class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZeros;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nonZeros.push_back(nums[i]);
            }
        }
        for(int i = 0; i < nonZeros.size(); i++){
            nums[i] = nonZeros[i];
        }
        for(int i = nonZeros.size(); i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};