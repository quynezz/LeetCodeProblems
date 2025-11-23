class Solution {
int findmax(int num){
    int ans = INT_MIN;
    while(num != 0){
        int temp = num % 10;
        ans = max(temp,ans);
        num /= 10;
    }
    return ans;
}
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                int n = findmax(nums[i]);
                int m = findmax(nums[j]);
                if(n == m && (nums[i] + nums[j] > sum)){
                    sum = nums[i] + nums[j];
                }
            }
        }
        return sum == 0 ? -1 : sum;
    }
};