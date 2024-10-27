class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int sum = 0;
            for(int i = 0; i < n; i++){     
                    sum += mat[i][i] + mat[i][n - 1 - i]; 
                    if(i == (n - 1 - i )){ 
                        sum -= mat[i][i];
            }
        }
        return sum;
    }
};