class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {  
    vector<int> left(nums.size(),0),right(nums.size(),0),ans;

    for(int i = 1,j = nums.size() - 2; i < nums.size() && j >= 0; i++,j--){
        left[i] = nums[i - 1] + left[i - 1];
        right[j] = nums[j + 1] + right[j + 1];
    }
    for(int i = 0; i < nums.size(); i++){
        ans.push_back(abs(left[i] - right[i]));
    }
        return ans;
    }
};