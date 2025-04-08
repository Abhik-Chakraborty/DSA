class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        int count = 0;
        while(true){
            bool hasDuplicate = false;
            for(auto it : mpp){
                if(it.second > 1){
                    hasDuplicate = true;
                    break;
                }
            }
            if(!hasDuplicate){
                return count;
            }
            count++;
            int n = nums.size();

            nums.erase(nums.begin(), nums.begin() + min(3, n));
            
            mpp.clear();
            for(int i = 0; i < nums.size(); i++){
                mpp[nums[i]]++;
            }
        }
    }
};