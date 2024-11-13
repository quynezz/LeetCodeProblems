class Solution {
private:
    void backtrack(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result, vector<bool>& visited) {
        // If the current permutation is complete, add it to the result
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, temp, result, visited);
            visited[i] = false;
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, temp, result, visited);
        return result;
    }
};
