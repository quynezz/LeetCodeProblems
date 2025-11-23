class Solution {  
private: 
void permutation(vector<int>& nums,vector<int> &temp,vector<vector<int>> &v, unordered_map<int,int> &m){    
    if(temp.size() == nums.size()){ 
        v.push_back(temp);
        return;
    } 
    for(int i = 0; i < nums.size(); i++){ 
        if(m[i] <= 0){ 
        temp.push_back(nums[i]);
        m[i]++;   
        permutation(nums,temp,v,m);
        m[i]--; 
        temp.pop_back();
        }
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {  
        vector<vector<int>> v;
        vector<int> temp;
        unordered_map<int,int> m;
        permutation(nums,temp,v,m);
        return v;
    }
};