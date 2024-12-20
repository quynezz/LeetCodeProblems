class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longest = 0;
        int countU = 1;
        int countD = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] < nums[i + 1]){
                countU += 1;
            }else{ 
                longest = max(countU, longest);
                countU = 1;
            }
        }
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1] && nums[i] != nums[i + 1]){
                countD += 1;
            }else{ 
                longest = max(countD, longest);
                countD = 1;
            }
        }
        longest = max(countU,longest);
        longest = max(countD,longest);

        return longest;
    }
};