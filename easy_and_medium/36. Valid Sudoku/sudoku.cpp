class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> r[9];
        unordered_set<char> c[9];
        unordered_set<char> b[9]; 
        for(int i = 0; i < 9; i++){  
            for(int j = 0; j < 9; j++){  
                if(board[i][j] == '.'){
                    continue;
                }  
                int index = (i / 3 ) * 3 + (j / 3);
                int value = board[i][j];
                if(r[i].count(value) || c[j].count(value) || b[index].count(value)){  
                    return false;
                } 
                r[i].insert(value); 
                c[j].insert(value);
                b[index].insert(value);
            }
        }
            return true;

    }
};