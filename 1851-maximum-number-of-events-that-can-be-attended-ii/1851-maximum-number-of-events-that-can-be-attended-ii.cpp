class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    
        vector<int> endTimes(n);
        for (int i = 0; i < n; ++i){
            endTimes[i] = events[i][1];
        }
        for (int i = 1; i <= n; ++i) {
            int s = events[i - 1][0], e = events[i - 1][1], v = events[i - 1][2];
            int l = upper_bound(endTimes.begin(), endTimes.end(), s - 1) - endTimes.begin();

            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[l][j - 1] + v);
            }
        }
        return dp[n][k];
    }
};