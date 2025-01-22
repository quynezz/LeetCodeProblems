class Solution {
public:
    int dx[4] = {-1, 1, 0, 0}; 
    int dy[4] = {0, 0, 1, -1}; 
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    res[i][j] = 0; 
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto[currX,currY] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && res[newX][newY] == -1){
                    res[newX][newY] = res[currX][currY] + 1;
                    q.push({newX,newY});
                }
            }
        }
        return res;
    }
};
