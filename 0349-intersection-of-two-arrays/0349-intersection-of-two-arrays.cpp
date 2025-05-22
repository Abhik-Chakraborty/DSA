class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        unordered_map<int, int> mpp;

        for(int num : nums1){
            mpp[num]++;
        }

        for(int num : nums2){
            if(mpp.find(num) != mpp.end()){
                st.insert(num);
            }
        }
        vector<int> res(st.begin(), st.end());
        return res;
    }
};