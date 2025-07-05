class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mpp;

        for(auto it : arr){
            mpp[it]++;
        }
        int result = -1;

        for(auto num : mpp){
            if(num.first == num.second){
                result = max(result, num.first);
            }
        }
        return result;
    }
};