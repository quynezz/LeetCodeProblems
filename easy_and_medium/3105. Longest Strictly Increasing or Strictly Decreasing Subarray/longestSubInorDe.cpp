class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxL = -1, countU = 1, countD = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                countD++;
                countU = 1;
            }else if(nums[i] < nums[i + 1]){
                countU++;
                countD = 1;
            }else if(nums[i] == nums[i + 1]){
                countU = 1, countD = 1;
            }
        }
        maxL = max(maxL,countU);
        maxL = max(maxL,countD);
        return maxL;
    }
};