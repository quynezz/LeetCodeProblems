class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
         int lsum = 0, total = 0;
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if(lsum == total - lsum - nums[i]){
                return i;
            }
            lsum += nums[i];
        } 
        return -1;
    }
};