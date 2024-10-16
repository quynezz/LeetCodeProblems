class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> p(rowIndex + 1);
        if(rowIndex>= 0){  
            p[0] = {1};
        }
        for(int i = 1; i <= rowIndex; i++){  
            p[i].resize(i+1);
            p[i][0] = 1; // first edge
            p[i][i] = 1; // last edge 
            for(int j = 1; j < i; j++){
                p[i][j] = p[i - 1][j - 1] + p[i - 1][j];  
             } 
    }
    return p[rowIndex];
}
};