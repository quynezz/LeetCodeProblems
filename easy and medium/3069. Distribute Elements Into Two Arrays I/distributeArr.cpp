class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1; 
        vector<int> a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for(int i = 2; i < nums.size(); i++){
                a1.back() > a2.back() ? a1.push_back(nums[i]) : a2.push_back(nums[i]);
            }
        for(auto it : a2){
            a1.push_back(it);
        }
        return a1;
    }
};