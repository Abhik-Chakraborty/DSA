class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        for (const auto& f : folder) {
            if (res.empty() || f.find(res.back() + "/") != 0) {
                res.push_back(f);
            }
        }
        return res;
    }
};