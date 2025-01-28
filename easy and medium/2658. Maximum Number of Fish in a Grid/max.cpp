class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxPoint = INT_MIN;
        int temp = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[r].size(); c++){
                if(grid[r][c] > 0){
                    dfs(temp,r,c,grid);
                    maxPoint = max(temp,maxPoint);
                    temp = 0;
                }
            }
        }
        return maxPoint == INT_MIN ? 0 : maxPoint;
    }
private: 
    void dfs(int& res, int r, int c,vector<vector<int>>& grid){
        // base case: 
        if(r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0 || grid[r][c] == 0){
            return;
        }
        res += grid[r][c];
        grid[r][c] = 0;
        dfs(res,r + 1, c, grid);
        dfs(res,r - 1, c, grid);
        dfs(res,r,c+1,grid);
        dfs(res,r,c-1,grid);

    }
};