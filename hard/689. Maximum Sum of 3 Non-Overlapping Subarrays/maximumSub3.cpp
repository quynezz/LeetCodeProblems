class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int bestStartIndex1 = 0, curSum1 = 0, curSum2 = 0, curSum3 = 0, maxSum1 = 0, maxSum2 = 0, maxSum3 = 0;
        vector<int> bestStartIndex2 = {0, k}, bestStartIndex3 = {0, k, 2 * k};

        for (int i = 0; i < k; i++) curSum1 += nums[i], curSum2 += nums[i + k], curSum3 += nums[i + 2 * k];
        maxSum1 = curSum1; maxSum2 = maxSum1 + curSum2; maxSum3 = curSum1 + curSum2 + curSum3;

        for (int i = 1; i <= nums.size() - 3 * k; i++) {
            curSum1 += nums[i + k - 1] - nums[i - 1];
            curSum2 += nums[i + 2 * k - 1] - nums[i + k - 1];
            curSum3 += nums[i + 3 * k - 1] - nums[i + 2 * k - 1];

            if (curSum1 > maxSum1) {
                maxSum1 = curSum1;
                bestStartIndex1 = i;
            }
            if (curSum2 + maxSum1 > maxSum2) {
                maxSum2 = curSum2 + maxSum1;
                bestStartIndex2 = {bestStartIndex1, i + k};
            }
            if (curSum3 + maxSum2 > maxSum3) {
                maxSum3 = curSum3 + maxSum2;
                bestStartIndex3 = {bestStartIndex2[0], bestStartIndex2[1], i + 2 * k};
            }
        }
        return bestStartIndex3;
    }
};