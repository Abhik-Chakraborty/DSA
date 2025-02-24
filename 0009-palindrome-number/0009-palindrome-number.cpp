class Solution {
public:
    bool isPalindrome(int x) {
        int ogNumber = x;
        int reverseNumber = 0;
        while(x > 0){
            int lastDigit = x % 10;
            x = x / 10;
            // Check for overflow before updating reverseNumber
            if (reverseNumber > INT_MAX / 10 || (reverseNumber == INT_MAX / 10 && lastDigit > INT_MAX % 10)) {
                return 0; // Return 0 if overflow happens
            }
            reverseNumber = (reverseNumber * 10) + lastDigit;
        }
        return reverseNumber == ogNumber;
    }
};