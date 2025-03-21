class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mpp;
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;

            if(mpp[nums[i]] <= 2){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};