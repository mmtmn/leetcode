#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (std::abs(target - currentSum) < std::abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                if (currentSum > target) {
                    right--;
                } else if (currentSum < target) {
                    left++;
                } else {
                    return target; // The sum is exactly equal to the target
                }
            }
        }

        return closestSum;
    }
};
