class Solution {
public:
    int specialArray(vector<int>& nums) {
        int last = -1;
        for(int i = 1; i <= nums.size(); i++){
            int count = 0;
            for(auto it : nums){
                if(it >= i){
                    count++;
                }
            }
            if(count == i){
                last = count;
            }
        }
        return last;
    }
};