class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {   
        vector<int> lucky; 
        for(int i = 0; i < matrix.size(); i++){
            int num = matrix[i][0]; 
            int index = 0;
            bool ok = true;
            for(int j = 0; j < matrix[i].size();j++){ 
                if(num > matrix[i][j]){
                    num = matrix[i][j];
                    index = j;
                }
            }    
            for(int k = 0; k < matrix.size(); k++){
                if(num < matrix[k][index]){  
                    ok = false; 
                }
            }
            if(ok == true){
                lucky.push_back(num);
            }
        }
        return lucky;
    }
};