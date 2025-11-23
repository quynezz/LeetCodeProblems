#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int maxFrequency(std::vector<int>& nums, int k) {
        int totalK = 0;

        // Count occurrences of k in nums
        for (int num : nums) {
            if (num == k) {
                totalK++;
            }
        }

        // Generate unique values of k - num
        std::unordered_set<int> xVals;
        for (int num : nums) {
            xVals.insert(k - num);
        }

        int maxCount = totalK; // At least the original count if we have to perform the operation

        // Iterate through each x in xVals
        for (int x : xVals) {
            int currentCandidate;
            if (x == 0) {
                currentCandidate = totalK;
            } else {
                std::vector<int> transformed(nums.size());
                for (size_t i = 0; i < nums.size(); ++i) {
                    if (nums[i] == k - x) {
                        transformed[i] = 1;
                    } else if (nums[i] == k) {
                        transformed[i] = -1;
                    } else {
                        transformed[i] = 0;
                    }
                }

                int currentMax = kadane(transformed);
                currentCandidate = currentMax + totalK;
            }
            maxCount = std::max(maxCount, currentCandidate);
        }

        return maxCount;
    }

private:
    int kadane(const std::vector<int>& arr) {
        if (arr.empty()) return 0;

        int maxSoFar = arr[0];
        int currentMax = arr[0];

        for (size_t i = 1; i < arr.size(); ++i) {
            currentMax = std::max(arr[i], currentMax + arr[i]);
            maxSoFar = std::max(maxSoFar, currentMax);
        }

        return maxSoFar;
    }
};
