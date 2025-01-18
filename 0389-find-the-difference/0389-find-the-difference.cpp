class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int, int> mpp;
        string temp;

        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            if(mpp.find(t[i]) == mpp.end() || mpp[t[i]] == 0){
                return t[i];
            }
            else{
                mpp[t[i]]--;
            }
        }
        return temp[0];
    }
};