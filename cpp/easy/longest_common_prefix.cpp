#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";

        // Iterate through the characters of the first string
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];

            // Compare the character with the corresponding character in other strings
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].length() || strs[j][i] != c) {
                    // If mismatch found, return the common prefix up to this point
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};
