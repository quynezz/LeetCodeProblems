class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxN = *max_element(nums.begin(),nums.end());
        int mark = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != maxN){
                if(nums[i] * 2 > maxN){
                    return -1;
                }
            }else if(nums[i] == maxN){
                mark = i;
            }
        }
        return mark;
    }
};