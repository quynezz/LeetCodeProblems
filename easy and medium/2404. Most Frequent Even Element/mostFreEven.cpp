class Solution {
public:
    int mostFrequentEven(vector<int>& nums) { 
        unordered_map<int, int> m;
        int most = 0;
        int res = -1;
        
        for (auto it : nums) {
            if (it % 2 == 0) {  
                m[it]++;
                if (m[it] > most || (m[it] == most && it < res)) {
                    most = m[it];
                    res = it;
                }
            }
        }
        
        return res;
    }
};
