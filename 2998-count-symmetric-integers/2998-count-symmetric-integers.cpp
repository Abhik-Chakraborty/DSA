class Solution {
public:
    bool isSymmetric(int num) {
        string s = to_string(num);
        int len = s.length();

        if (len % 2 != 0) return false; 

        int mid = len / 2;
        int leftSum = 0, rightSum = 0;

        for (int i = 0; i < mid; ++i)
            leftSum += s[i] - '0';

        for (int i = mid; i < len; ++i)
            rightSum += s[i] - '0';

        return leftSum == rightSum;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; ++i) {
            if (isSymmetric(i))
                ++count;
        }
        return count;
    }
};