class Solution {
public:
    vector<int> getGaps(int eventTime, const vector<int>& startTime, const vector<int>& endTime) {
        vector<int> gaps;
        gaps.push_back(startTime[0]); 
        for (int i = 1; i < startTime.size(); ++i) {
            gaps.push_back(startTime[i] - endTime[i - 1]); 
        }
        gaps.push_back(eventTime - endTime.back()); 
        return gaps;
    }
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps = getGaps(eventTime, startTime, endTime);
        int windowSum = accumulate(gaps.begin(), gaps.begin() + k + 1, 0);
        int ans = windowSum;

        for (int i = k + 1; i < gaps.size(); ++i) {
            windowSum += gaps[i] - gaps[i - k - 1];
            ans = max(ans, windowSum);
        }

        return ans;
    }
};