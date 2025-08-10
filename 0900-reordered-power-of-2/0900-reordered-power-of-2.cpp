class Solution {
public:
    string signature(long long x) {
        string s = to_string(x);
        sort(s.begin(), s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        static unordered_set<string> sigs;     
        if (sigs.empty()) {
            for (long long p = 1; p <= 1000000000LL; p <<= 1) {
                sigs.insert(signature(p));
            }
        }
        return sigs.count(signature(n)) > 0;
    }
};