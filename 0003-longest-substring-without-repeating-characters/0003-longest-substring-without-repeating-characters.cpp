class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            int len = 0;
            unordered_map<int, int> mpp;
            for(int j = i; j < s.size(); j++){
                if(mpp.find(s[j]) != mpp.end()){
                    break;
                }
                mpp[s[j]] = i;
                len++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};