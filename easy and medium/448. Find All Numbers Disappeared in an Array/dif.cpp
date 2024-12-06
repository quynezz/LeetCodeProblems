class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) { 
        vector<int> v;
        bool visited[100001];
        memset(visited,false,sizeof(visited));
        for(int i = 0; i < nums.size(); i++){
            visited[nums[i]] = true;
        }
        for(int i = 1; i <= nums.size(); i++){
            if(!visited[i]){
                v.push_back(i);
            }
        }
        return v;
    }
};