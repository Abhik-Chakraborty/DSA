class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            result.push_back(it);
        }
        nums = result;
        return result.size();

    }
};