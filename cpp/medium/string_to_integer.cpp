#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, sign = 1;
        long result = 0;  // Use long to handle overflow

        // Skip leading whitespaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Check the sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert number and avoid overflow
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Check for overflow and clamp the result within INT_MIN and INT_MAX
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * result;
    }
};
