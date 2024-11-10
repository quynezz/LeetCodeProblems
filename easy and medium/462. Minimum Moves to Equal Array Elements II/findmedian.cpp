class Solution {
public:
    int minMoves2(vector<int>& nums) { 
        int count = 0;
        sort(nums.begin(),nums.end()); 
        // find median
        int k = nums[0 + nums.size() / 2]; 
        for(int i = 0; i < nums.size(); i++){
            count += abs(nums[i] - k);
        }
        return count;
    }
};