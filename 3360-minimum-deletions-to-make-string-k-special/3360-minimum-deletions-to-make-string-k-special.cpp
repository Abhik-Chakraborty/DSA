class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqMap;
        for (char c : word) {
            freqMap[c]++;
        }

        vector<int> freqs;
        for (auto& entry : freqMap) {
            freqs.push_back(entry.second);
        }

        sort(freqs.begin(), freqs.end());
        int minDeletions = INT_MAX;
        int maxFreq = freqs.back();

        for (int minFreq = 1; minFreq <= maxFreq; ++minFreq) {
            int maxFreqAllowed = minFreq + k;
            int deletions = 0;

            for (int freq : freqs) {
                if (freq < minFreq) {
                    deletions += freq;  
                } else if (freq > maxFreqAllowed) {
                    deletions += freq - maxFreqAllowed;  
                }
            }

            minDeletions = min(minDeletions, deletions);
        }

        return minDeletions;
    }
};