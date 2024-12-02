class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        int i = 0;

        while (i < nums.size()) {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i += 2; 
            } else {
                v.push_back(nums[i]); 
                i++; 
            }
        }
        return v;
    }
};
