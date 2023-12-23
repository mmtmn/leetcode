class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending with 0 (except 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // The number is a palindrome if it's equal to its reversed half
        // or equal to the reversed half without the last digit (for odd-length numbers)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
