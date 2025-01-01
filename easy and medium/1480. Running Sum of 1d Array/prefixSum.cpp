class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefixS(nums.size(),0);
        prefixS[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) prefixS[i] = prefixS[i - 1] + nums[i];
        return prefixS;
    }
};