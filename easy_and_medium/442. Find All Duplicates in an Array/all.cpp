class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        vector<bool> visited(nums.size(), false);
        for(int i = 0; i < nums.size(); i++){ 
            if(!visited[nums[i]]){
                visited[nums[i]] = true;
            }else if(visited[nums[i]]){
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};