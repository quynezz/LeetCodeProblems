class Solution {
public:
//      bool checkValid(vector<vector<int>>& matrix) { 
//         int n = matrix.size(); 
//         for(int i = 0 ; i < n; i++){  
//         set<int> row;
//         set<int> col; 
//         for(int j = 0; j < n; j++){   
//             row.insert(matrix[i][j]);
//             col.insert(matrix[j][i]);
//         }
//         for(int k = 1; k <= n; k++){ 
//             if(row.find(k) == row.end() || col.find(k) == col.end() ){ 
//                 return false;
//             }
//         }
//     }
//    return true;
//     }



    bool checkValid(vector<vector<int>>& matrix) {
   for(int i = 0; i < matrix.size(); i++){
    unordered_map<int,int> row,col;
      for(int j = 0; j < matrix[i].size();j++){  
        // map row and count
         row[matrix[i][j]]++;
        // map col and count
         col[matrix[j][i]]++;
      }
    // check frequency of row and col of n elements
   for(int k = 1; k <= matrix.size(); k++){ 
    if(row[k] != 1 || col[k] != 1){  
        return false; 
   }
}
   } 
   return true;
    }
};