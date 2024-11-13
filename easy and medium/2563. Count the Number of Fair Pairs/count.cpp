class Solution {
private: 
int binarySearch(int l, int r, int tar,vector<int> &nums){  
    while(l <= r){
        int mid = (l + r)/ 2;
        if(nums[mid] >= tar){
            r = mid - 1;
        }else{ 
            l = mid + 1;
        }
    }
    return r;
}
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end()); 
        long long  res = 0;
        for(int i = 0; i < nums.size(); i++){ 
            int low = lower - nums[i];
            int up = upper - nums[i];
            res += (
            binarySearch(i + 1,nums.size() - 1,up + 1,nums) - 
            binarySearch(i + 1,nums.size() - 1,low,nums)
            );
        }
        return res;
    }
};