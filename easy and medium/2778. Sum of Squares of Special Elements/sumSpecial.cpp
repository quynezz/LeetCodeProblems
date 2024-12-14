class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            int j = i + 1;
            if(n % j == 0){
                sum += (nums[i] * nums[i]);
            }
        }
        return sum;
    }
};