class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int longest = 0;
        vector<bool> visited(nums.size(),false);
        for(int i = 0; i < nums.size(); i++){
            int count = 0;
            int temp = i;
            while(visited[temp] == false){
                    visited[temp] = true;   
                    temp = nums[temp];
                    count++;
                }
            longest = max(count,longest);
        }
        return longest;
    }
};