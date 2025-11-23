class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) { 
        sort(nums.begin(),nums.end());
        int n = nums.size() / 3;
        vector<int> v;
        int count = 1;
        for(int i = 0; i < nums.size(); i++){ 
            if(i == nums.size() - 1 || nums[i] != nums[i + 1]){ 
                if(count > n){
                    v.push_back(nums[i]);
                }
                count = 1;
            }else{
                count++;
            }
        }
        return v;
    }
};