class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int count = 0;
        if(nums[0] == 1 && nums[nums.size() - 1] == nums.size()){
            return count;
        }
        // swap 1;
        while(true){
            if(nums[0] == 1) break;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 1){
                    swap(nums[i],nums[i - 1]);
                    count++;
                }
            }
        }
        while(true){
            if(nums[nums.size() - 1] == nums.size()) break;
            for(int i = 0; i < nums.size() - 1; i++){
                if(nums[i] == nums.size()){
                    swap(nums[i],nums[i + 1]);
                    count++;
                }
            }
        }
        return count;
    }
};