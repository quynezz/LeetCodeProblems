class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int temp = 1;
        int i = 0;
        int count = 1;
        while(i < nums.size() - 1){
            if(nums[i] < nums[i + 1]){
                count++;
            }else{
                temp = max(temp,count);
                count = 1;
            }
            i++;
        }
        temp = max(temp,count);
        return temp;
    }
};