class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int totalCoveredDays = 0;
        int currentStart = meetings[0][0];
        int currentEnd = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];

            if (start <= currentEnd) {
                currentEnd = max(currentEnd, end);
            } else {
                totalCoveredDays += currentEnd - currentStart + 1;
                currentStart = start;
                currentEnd = end;
            }
        }
        totalCoveredDays += currentEnd - currentStart + 1;

        return days - totalCoveredDays;
    }
};