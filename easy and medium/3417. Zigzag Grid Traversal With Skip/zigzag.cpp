class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<int> v;
        // flip the direction (false = right, true = left)
        bool flip = false; 
        // already take ? false = need take, true = no need take
        bool taken = false;
        for(int i = 0; i < R; i++){
            if(!flip){
                for(int j = 0; j < C; j++){
                    if(!taken){
                        v.push_back(grid[i][j]);
                    }
                        taken = !taken;
                }
            }else if(flip){
                for(int j = C - 1; j >= 0; j--){
                    if(!taken){
                        v.push_back(grid[i][j]);
                    }
                        taken = !taken;
                }
            }
            flip = !flip;
        }
        return v;
    }
};