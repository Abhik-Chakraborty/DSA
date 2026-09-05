class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int left = 0;
        int cost = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            int diff = s.charAt(right) - t.charAt(right);

            if (diff < 0) {
                diff = -diff;
            }

            cost = cost + diff;

            while (cost > maxCost) {

                int leftDiff = s.charAt(left) - t.charAt(left);

                if (leftDiff < 0) {
                    leftDiff = -leftDiff;
                }

                cost = cost - leftDiff;
                left++;
            }

            int length = right - left + 1;

            if (length > maxLength) {
                maxLength = length;
            }
        }

        return maxLength;
    }
}