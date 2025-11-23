class Solution {
private: 
void backtrack(vector<vector<int>> &l, vector<int> &q, int k, int n){ 
    // base case: 
    if(q.size() == k){
        int sum  = 0;
        for(auto it : q){
            sum += it;
        }
        if(sum == n){
            l.push_back(q);
            return;
        }
        return;
    }
    for(int i = ( q.empty() ) ? 1 : q.back() + 1; i <= 9; i++){
        q.push_back(i); 
        backtrack(l,q,k,n);
        q.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        vector<int> temp; 
        backtrack(v,temp,k,n);
        return v;
    }
};