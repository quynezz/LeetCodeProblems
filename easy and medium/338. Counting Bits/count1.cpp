class Solution {
public:
    vector<int> countBits(int n) { 
        vector<int> v(n + 1 ,0);
        for(int i = 1; i <= n; i++){  
            // take the 1's from divided number and 1's from i mod 2;
             v[i] = v[i / 2] + (i % 2);
        }
        return v;
    }
};