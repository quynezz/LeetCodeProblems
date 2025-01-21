class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m = grid[0].size(); 
        // accumulate(stat,end,initial number to plus);
        long long top = accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long bot = 0;
        long long res = LLONG_MAX;
        for(int i = 0; i < m; i++){
            top -= grid[0][i];
            res = min(res,max(top,bot));
            bot += grid[1][i];
        }
        return res;
    }
};