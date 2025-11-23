class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() <= 2){
            return -1;
        }
        sort(nums.begin(),nums.end());
        if(nums.size() % 2 == 0){
            return nums[nums.size() / 2 - 1];
        }
        return nums[nums.size() / 2];
    }
};