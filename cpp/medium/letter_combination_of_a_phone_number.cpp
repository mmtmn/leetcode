#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};

        std::unordered_map<char, std::string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        std::vector<std::string> result;
        std::string currentCombination;
        backtrack(result, phoneMap, digits, 0, currentCombination);
        return result;
    }

private:
    void backtrack(std::vector<std::string> &result, const std::unordered_map<char, std::string> &phoneMap, 
                   const std::string &digits, int index, std::string &currentCombination) {
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }

        char digit = digits[index];
        const std::string &letters = phoneMap.at(digit);
        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(result, phoneMap, digits, index + 1, currentCombination);
            currentCombination.pop_back(); // backtrack
        }
    }
};
