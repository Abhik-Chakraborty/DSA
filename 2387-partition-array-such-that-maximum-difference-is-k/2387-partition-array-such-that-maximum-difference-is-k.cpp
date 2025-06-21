class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // [1,2,3,5,6]
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = 0;
        int count = 0;
        while(j < nums.size()){
            if(nums[j] - nums[i] > k){
                i = j;
                count++;
            }
            j++;
        }
        return count+1;
    }
};