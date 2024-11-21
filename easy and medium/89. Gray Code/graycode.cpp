class Solution {
public:
    vector<int> grayCode(int n) {
        // take current num XOR with the (current num >> 1); 
        vector<int> v;
        n = pow(2,n) - 1; 
        for(int i = 0; i <= n; i++){ 
            v.push_back(i ^ (i >> 1));
        }
        return v;
    }
};