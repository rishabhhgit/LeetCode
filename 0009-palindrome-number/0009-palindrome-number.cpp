
class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes (e.g., -121 != 121-)
        // Also, if the last digit is 0, the first must be 0 (only possible for 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is odd, we can get rid of the middle digit by revertedNumber/10
        // For example, in 121, at the end of the loop x = 1, revertedNumber = 12
        return x == revertedNumber || x == revertedNumber / 10;
    }
};