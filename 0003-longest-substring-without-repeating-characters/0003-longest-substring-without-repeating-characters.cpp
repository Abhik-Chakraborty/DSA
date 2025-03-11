class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int maxLen = INT_MIN;
        if(s.size() == 0){
            return 0;
        }

        for(int i = 0; i < s.size(); i++){
            int hash_array[256] = {0};

            for(int j = i; j < s.size(); j++){
                if(hash_array[s[j]] == 1) break;
                length = j - i + 1;
                maxLen = max(maxLen, length);
                hash_array[s[j]] = 1;
            }
        }
        return maxLen;
    }
};