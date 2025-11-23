class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string,int> m; 
    for(int i = 0; i < matrix.size(); i++){
        string s = "";
        string temp = ""; 
        for(int j = 0; j < matrix[i].size(); j++){ 
            s += to_string(matrix[i][j]); 
            if(matrix[i][j] == 1){
                temp += '0';
            }else if(matrix[i][j] == 0){
            temp += '1';
            }
        }
        m[s]++; 
        m[temp]++;

    }
    int maxEle = 0;
    for(auto [pat,fre] : m){ 
        maxEle = max(maxEle,fre);
    }
    return maxEle;
    }
};