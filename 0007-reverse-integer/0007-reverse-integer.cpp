class Solution {
public:
    int reverse(int x) {
        int reverseNumber = 0;
        bool isNegative = x < 0;
        if(x == INT_MIN){
            return 0;
        }
        x = abs(x);
        while( x > 0){
            int lastDigit = x % 10; 
            x = x / 10;
            // Check for overflow before updating reverseNumber
            if (reverseNumber > INT_MAX / 10 || (reverseNumber == INT_MAX / 10 && lastDigit > INT_MAX % 10)) {
                return 0; // Return 0 if overflow happens
            }
            reverseNumber = (reverseNumber * 10) + lastDigit;
        }
        return isNegative ? -reverseNumber : reverseNumber;
    }
};