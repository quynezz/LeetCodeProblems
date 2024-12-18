class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.empty()) return m * n; 

        int a_min = m, b_min = n;
        for (auto& op : ops) {
            a_min = min(a_min, op[0]);
            b_min = min(b_min, op[1]);
        }
        return a_min * b_min;
    }
};
