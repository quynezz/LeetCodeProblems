class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]){
                count++;
            }else{
                if(count % 2 != 0){
                    return false;
                }
                count = 1;
            }
        }
        return true;
    }
};