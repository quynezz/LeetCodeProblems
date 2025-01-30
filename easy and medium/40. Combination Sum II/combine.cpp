class Solution {
private:
    void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int index, int current, int target) {
        // Base case: if the current sum equals the target, add the combination to the result
        if (current == target) {
            res.push_back(temp);
            return;
        }
        // 1,1,2,5,6,7,10
        
        // Base case: if the current sum exceeds the target or we've reached the end of the array, return
        if (current > target || index >= candidates.size()) {
            return;
        }

        temp.push_back(candidates[index]);
        backtrack(res, temp, candidates, index + 1, current + candidates[index], target);
        temp.pop_back();
    
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }
        backtrack(res, temp, candidates, index + 1, current, target);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        
        // Sort the candidates to handle duplicates
        sort(candidates.begin(), candidates.end());
        
        // Start the backtracking process
        backtrack(res, temp, candidates, 0, 0, target);
        
        return res;
    }
};