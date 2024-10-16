class Solution {
public:
    vector<vector<int>> generate(int numRows) { 
        vector<vector<int>> p(numRows);
        if(numRows>= 1){  
            p[0] = {1};
        }
        if(numRows >= 2){  
            p[1] = {1,1};
        }
        for(int i = 2; i < numRows; i++){  
            p[i].resize(i+1);
            p[i][0] = 1; // first edge
            p[i][i] = 1; // last edge 
            for(int j = 1; j < p[i].size() - 1; j++){
                p[i][j] = p[i - 1][j - 1] + p[i - 1][j];  
             }
        } 
    }
};