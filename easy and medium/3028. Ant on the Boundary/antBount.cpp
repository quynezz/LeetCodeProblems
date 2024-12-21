class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int temp = 0;
        int count = 0;
        for(auto it : nums){
            temp += it;
            if(temp == 0){
                count++;
            }
        }
        return count;
    }
};