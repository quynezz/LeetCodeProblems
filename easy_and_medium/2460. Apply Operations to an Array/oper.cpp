class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            vector<int> res; 
            for(int i = 0; i < nums.size() - 1; i++){
                if(nums[i] == nums[i + 1]){
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
            }
            for(auto it : nums) if(it != 0) res.push_back(it);
            for(auto it : nums) if(it == 0) res.push_back(it);
            return res;
        }
    };