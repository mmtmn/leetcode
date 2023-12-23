#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length(), n = p.length();
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        // Base cases
        dp[0][0] = true;  // Both strings are empty
        for (int i = 1; i <= n; i++) {
            // If pattern has '*', it depends on the character two steps back
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 2];
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // If characters match, or pattern has '.', inherit the previous state
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // If pattern has '*', it could mean zero occurrences or more
                    // Check for zero occurrences first
                    dp[i][j] = dp[i][j - 2];

                    // Check for one or more occurrences
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
