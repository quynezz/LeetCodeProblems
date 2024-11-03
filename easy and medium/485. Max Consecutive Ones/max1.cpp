class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){ 
            if(nums[i] == 1){ 
                temp++;
                if(temp > max){ 
                    max = temp;
                }
            } else if(nums[i] == 0 ){ 
                temp = 0;
            }
        }
        return max;
    }
};