class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char, int> count;

        for(char c : s){
            count[c]++;
        }

        int required = n / 4;
        if (count['Q'] == required &&
            count['W'] == required &&
            count['E'] == required &&
            count['R'] == required) {
                return 0;
            }

        int left = 0;
        int res = n;

        for(int right = 0; right < n; right++){
            count[s[right]]--;

            while(left <= right && count['Q'] <= required
            && count['W'] <= required
            && count['E'] <= required
            && count['R'] <= required){
                res = min(res, right - left + 1);
                count[s[left]]++;
                left++;
            }
        }
        return res;
    }
};