class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> fre(1000,0);
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            fre[nums[i]]++;
            if(fre[nums[i]] > 1) ans.push_back(nums[i]);
        }
        return ans;
    }
};