class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }

        unordered_map<char, int> mpp;
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
        }

        for(int j = 0; j < t.size(); j++){
            if(mpp[t[j]] == 0){
                return false;
            }
            mpp[t[j]]--;
        }
        return true;
    }
};