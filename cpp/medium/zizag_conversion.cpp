#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        std::vector<std::string> rows(std::min(numRows, int(s.length())));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }

        std::string converted;
        for (const std::string &row : rows) {
            converted += row;
        }
        return converted;
    }
};
