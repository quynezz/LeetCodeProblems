class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int count = 0;
        bool visited[251][251]; 
        memset(visited,false,sizeof(visited));
        for(int i = 0; i < R; i++){
            bool check = false;
            for(int j = 0; j < C; j++){
                if(grid[i][j] == 1){
                // down
                    int tempi = i - 1;
                    while(tempi >= 0 && tempi < R){
                        if(grid[tempi][j] == 1 && !visited[tempi][j]){
                        visited[tempi][j] = true;
                        count++;
                        check = true;
                        }
                        tempi--;
                    }
                    // up
                    tempi = i + 1;
                    while(tempi < R ){
                        if(grid[tempi][j] == 1 && !visited[tempi][j]){
                            visited[tempi][j] = true;
                            count++;
                            check = true;
                        }
                        tempi++;
                    }
                    // left
                    int tempj = j - 1;
                    while(tempj >= 0 && tempj < C){
                        if(grid[i][tempj] == 1 && !visited[i][tempj]){
                            visited[i][tempj] = true;
                            count++;
                            check = true;
                        }
                        tempj--;
                    }
                    // right
                    tempj = j + 1;
                    while(tempj < C){
                        if(grid[i][tempj] == 1 && !visited[i][tempj]){
                            visited[i][tempj] = true;
                            count++;
                            check = true;    
                        }
                        tempj++;
                    }
                    if(check == true && !visited[i][j]){
                        visited[i][j] = true;
                        count++;
                    }
            }
            }
        }
        return count;
    }
};