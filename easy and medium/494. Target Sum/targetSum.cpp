class Solution {
private:
    void bt(int& count, vector<int>& nums, int target, int sum, int index) {
        // Base case: If we reach the end of the array
        if (index == nums.size()) {
            if (sum == target) {
                count++; // Found a valid way
            }
            return;
        }

        bt(count, nums, target, sum + nums[index], index + 1); 
        bt(count, nums, target, sum - nums[index], index + 1); 
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        int sum = 0;
        bt(count, nums, target, sum, 0);

        return count;
    }
};
