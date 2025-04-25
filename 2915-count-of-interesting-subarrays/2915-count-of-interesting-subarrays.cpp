class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> mpp;
        mpp[0] = 1;
        int count = 0;
        long long res = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % modulo == k){
                count++;
            }

            int modValue = (count - k) % modulo;
            if(modValue < 0){
                modValue += modulo;
            }
            if(mpp.count(modValue)){
                res +=mpp[modValue];
            }
            int currentMod = count % modulo;
            mpp[currentMod]++;
        }
        return res;
    }
};