class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        if(nums.size() <= 1) return false;
        int temp = 0;
        bool found = false;
        bool stop = false;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1 && found == false){
                temp = i;
                found = true;
            }else if(nums[i] == 1 && found == true){
                i - temp - 1 < k ? stop = true : temp = i; 
            }
            if(stop == true) return false;
        }
        return true;
    }
};