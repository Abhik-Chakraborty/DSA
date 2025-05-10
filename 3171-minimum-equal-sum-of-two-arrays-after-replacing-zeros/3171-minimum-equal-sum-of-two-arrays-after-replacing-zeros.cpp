class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;

        for (int x : nums1) {
            if (x == 0) zero1++;
            else sum1 += x;
        }

        for (int x : nums2) {
            if (x == 0) zero2++;
            else sum2 += x;
        }

        long long minPossible1 = sum1 + zero1 * 1LL;
        long long minPossible2 = sum2 + zero2 * 1LL;

        long long target = max(minPossible1, minPossible2);

        long long needed1 = target - sum1;
        long long needed2 = target - sum2;

        if ((zero1 == 0 && needed1 != 0) || (zero2 == 0 && needed2 != 0)) {
            return -1;
        }

        if (needed1 >= zero1 && needed2 >= zero2) {
            return target;
        }

        return -1;
    }
};
