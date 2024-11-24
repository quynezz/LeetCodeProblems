class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0; 
        long long small = LLONG_MAX;
        int count = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] < 0){ 
                count++;
                small = min(small,abs((long long)matrix[i][j]));
                sum += abs((long long)matrix[i][j]);
                }else{ 
                    small = min(small,(long long)matrix[i][j]);
                    sum += (long long)matrix[i][j];
                }
            }
        }
        if(count % 2 != 0) { 
            sum += (2 * (small * -1));        
        }
        return static_cast<long long>(sum);
    }
};