class Solution {
public:
    int maximumCount(vector<int>& nums) {
       int posCount = 0;
       int negCount = 0;
       for(int i = 0; i < nums.size(); i++){
        if(nums[i] < 0) negCount++;
        if(nums[i] > 0) posCount++;
       }
       if(negCount > posCount){
        return negCount;
       }
       else{
        return posCount;
       }

    }
};