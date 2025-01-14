class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count = 0;
        unordered_map<int,int> fre; 
        vector<int> ans(A.size(),0); 
        for(int i = 0; i < A.size(); i++){
            fre[A[i]]++;
            if(fre[A[i]] == 2) count++;
            fre[B[i]]++;
            if(fre[B[i]] == 2) count++;
            ans[i] = count;
        }
        return ans;
    }
};