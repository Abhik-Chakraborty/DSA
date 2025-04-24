class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> distinctElement(nums.begin(), nums.end());
        int totalDistinct = distinctElement.size();
        int count = 0;
        int n = nums.size();

        for(int i = 0; i < nums.size(); i++){
            set<int> seen;
            for(int j = i; j < nums.size(); j++){
                seen.insert(nums[j]);
                if(seen.size() == totalDistinct){
                    count++;
                }
            }
        }
        return count;
    }
};