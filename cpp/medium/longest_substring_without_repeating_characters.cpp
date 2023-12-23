// Beats 92.01%of users with C++
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int start = 0;  // start index of the current window

        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];

            // If the character is in the current window, move the start
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
                start = charIndexMap[currentChar] + 1;
            }

            charIndexMap[currentChar] = end;
            maxLength = std::max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
