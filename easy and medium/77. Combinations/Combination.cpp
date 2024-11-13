class Solution {
private:  
void back(vector<vector<int>>&ans, int k, int n, vector<int> &temp,int start){ 
    if(temp.size() == k){
        ans.push_back(temp);
        return;
    }
    for(int i = start; i <= n; i++){ 
        temp.push_back(i);
        back(ans,k,n,temp,i + 1);
        temp.pop_back();
    }
}
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int> temp;
        back(ans,k,n,temp,1);
        return ans;
    }
};