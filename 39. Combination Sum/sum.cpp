class Solution {
private: 
    void generate(vector<int>& nums, vector<vector<int>>& result, int i, int total, vector<int>& current, int target) {  
        if (total == target) {  
            result.push_back(current);
            return;
        } 
        if (i >= nums.size() || total > target) { 
            return;
        }
        current.push_back(nums[i]);
        generate(nums, result, i, total + nums[i], current, target); // Can reuse nums[i]
        current.pop_back(); // Backtrack
        generate(nums, result, i + 1, total, current, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result; 
        vector<int> current; 
        sort(candidates.begin(), candidates.end());
        generate(candidates, result, 0, 0, current, target);
        return result;
    }
};
