class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash_array(256, -1);
        int l = 0;
        int r = 0;
        int length = 0;
        int maxLen = 0;
        if(s.size() == 0){
            return 0;
        }

        while(r < s.size()){
            if(hash_array[s[r]] != -1 && l <= hash_array[s[r]]) // that element s[r] is already seen before 
            {
                l = hash_array[s[r]] + 1;
            }
            length = r - l + 1;
            maxLen = max(maxLen, length);
            hash_array[s[r]] = r; //update the index
            r++;
        }
        return maxLen;
    }
};