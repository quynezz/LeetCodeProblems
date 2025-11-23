class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) { 
        // sliding window
        int ans = INT_MAX;
        for(int i = l; i <= r; i++){ 
        int sum = 0; 
            for(int k = 0; k < i; k++){ 
                sum += nums[k];
            } 
            if(sum > 0){ 
                ans = min(sum,ans);
            }
            for(int y = i; y < nums.size(); y++){
                sum += nums[y] - nums[y - i]; 
                if(sum > 0){
                    ans = min(sum,ans);
                }
            } 
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};