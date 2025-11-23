class Solution {
public:
    int longestConsecutive(vector<int>& nums) { 
        if(nums.size() <= 1){
            return nums.size();
        }
        sort(nums.begin(),nums.end());
        int best = 0, count = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] + 1 == nums[i + 1]){
                count++;
            }else if(nums[i] != nums[i + 1]){
                best = max(best,count);
                count = 1;
            }
        }
        best = max(best,count);
        return best;
    }
};