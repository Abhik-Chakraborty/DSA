class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return false;
        }
        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;

        for(int i = 0; i < word1.size(); i++){
            mpp1[word1[i]]++;
            mpp2[word2[i]]++;
        }
        // for(int i = 0; i < word2.size(); i++){
        //     mpp2[word2[i]]++;
        // }
        
        if(mpp1.size() != mpp2.size()){
            return false;
        }

        for(auto it : mpp1){
            if(mpp2.find(it.first) == mpp2.end()){
                return false;
            }
        }
        vector<int> freq1;
        vector<int> freq2;
        for (auto it : mpp1) {
            freq1.push_back(it.second);
        }
        for (auto it : mpp2) {
            freq2.push_back(it.second);
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};