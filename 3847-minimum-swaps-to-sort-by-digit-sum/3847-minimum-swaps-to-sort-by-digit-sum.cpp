class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int, int>, int>> numData; 
        for (int i = 0; i < n; ++i) {
            numData.push_back({{digitSum(nums[i]), nums[i]}, i});
        }

        sort(numData.begin(), numData.end());
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || numData[i].second == i) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = numData[j].second;
                cycleSize++;
            }

            if (cycleSize > 1)
                swaps += cycleSize - 1;
        }

        return swaps;
    }
};