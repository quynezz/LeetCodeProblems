class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        unordered_set<int> s;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - 1 == nums[i - 1]){
                sum += nums[i];
            }else{
                break;
            }
        }
        for(auto it : nums){
            s.insert(it);
        }
        while(s.find(sum) != s.end()){
            sum += 1;
        }
        return sum;
    }
};