class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = 0;
        ans += nums[0];
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int index = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < min1){
                min1 = nums[i];
                index = i;
            }
        }
        for(int i = 1; i < nums.size(); i++){
            if(i != index){
                min2 = min(nums[i],min2);
            }
        }
        ans += min1 + min2;
        return ans;
    }
};