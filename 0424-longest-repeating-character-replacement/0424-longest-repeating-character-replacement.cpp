class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxFreq = 0;
        int maxLen = 0;
        unordered_map<char, int> mpp;
        while(right < s.size()){
            mpp[s[right]]++;
            maxFreq = max(maxFreq, mpp[s[right]]);
            int length = right - left + 1;
            if(length - maxFreq > k){
                mpp[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};