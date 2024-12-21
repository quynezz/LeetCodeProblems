class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int l = 0, r = 1;
        long long count = nums.size();
        for(r; r < nums.size(); r++){
            if(nums[r] == nums[r - 1]){
                l = r;
            }else{
                count += r - l;
            }
        }
        return count;
    }
};