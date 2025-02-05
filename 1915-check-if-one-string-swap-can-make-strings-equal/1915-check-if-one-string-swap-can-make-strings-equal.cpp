class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       if (s1 == s2) {
            return true;
        }
        vector<int> diffIndices;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diffIndices.push_back(i);
            }
        }
        if (diffIndices.size() == 2){
            int i = diffIndices[0], j = diffIndices[1];
            swap(s1[i], s1[j]);
            return s1 == s2;
        }
        return false;
    }
};