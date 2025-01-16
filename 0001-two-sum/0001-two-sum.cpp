class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];

            if(mpp.find(complement) != mpp.end()){
                result.push_back(mpp[complement]);
                result.push_back(i);
                return result;
            }
            mpp[nums[i]] = i;
        }
        return {-1, -1};
    }
};