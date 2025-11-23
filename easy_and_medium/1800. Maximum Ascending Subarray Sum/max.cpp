class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int res = -1; 
        int temp = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] < nums[i + 1]){
                temp += nums[i];
            }else{
                temp += nums[i];
                res = max(temp,res);
                temp = 0;
            }
        }
        nums[nums.size() - 1] > nums[nums.size() - 2] ? temp += nums[nums.size() - 1] : temp += 0;
        res = max(res,temp);
        return res;
    }
};