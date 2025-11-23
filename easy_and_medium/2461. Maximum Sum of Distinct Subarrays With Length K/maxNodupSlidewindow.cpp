class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) { 
        unordered_map<int,int> m; 
        long long temp = 0;
        long long sum = 0;
        for(int i = 0; i < k; i++){
            m[nums[i]]++; 
            temp += nums[i];
        }
        bool dup = (m.size() != k) ? true : false;
        if(!dup) sum = temp;
        for(int i = k; i < nums.size(); i++){
            temp += nums[i] - nums[i - k];
            m[nums[i]]++;
            m[nums[i - k]]--;
            if(m[nums[i - k]] == 0){
                m.erase(nums[i - k]);
            }
            dup = m.size() != k ? true : false;
            if(!dup){
                sum = max(sum,temp);
            }
        }
        return sum;
    }
};
