class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> rowFre; 
        unordered_map<int,int> colFre; 
        vector<int> rowNum(mat.size(),0);
        vector<int> colNum(mat[0].size(),0);
        for(int i = 0; i < mat.size(); i++){ 
            for(int j = 0; j < mat[i].size(); j++){
                rowFre[mat[i][j]] = i; 
                colFre[mat[i][j]] = j;
            }
        }
        for(int i = 0; i < arr.size(); i++){
            int index = arr[i];
            int temp1 = rowFre[index];
            int temp2 = colFre[index];
            rowNum[temp1]++;
            colNum[temp2]++;
      if (rowNum[temp1] == mat[0].size() || colNum[temp2] == mat.size()) {
        return i; 
}

        }
        return 0;
    }
};