class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
       vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<bool>> wall(m, vector<bool>(n, false));
        vector<vector<bool>> guard(m, vector<bool>(n, false));
        for (auto w : walls) {
            wall[w[0]][w[1]] = true;
        }
        for (auto g : guards) {
            guard[g[0]][g[1]] = true;
            visited[g[0]][g[1]] = true; 
        }
        for (auto g : guards) {
            int x = g[0], y = g[1];
            // Down
            for (int i = x + 1; i < m; i++) {
                if (wall[i][y] || guard[i][y]) break;
                visited[i][y] = true;
            }

            // Up
            for (int i = x - 1; i >= 0; i--) {
                if (wall[i][y] || guard[i][y]) break;
                visited[i][y] = true;
            }

            // Right
            for (int j = y + 1; j < n; j++) {
                if (wall[x][j] || guard[x][j]) break;
                visited[x][j] = true;
            }

            // Left
            for (int j = y - 1; j >= 0; j--) {
                if (wall[x][j] || guard[x][j]) break;
                visited[x][j] = true;
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && !wall[i][j] && !guard[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};
