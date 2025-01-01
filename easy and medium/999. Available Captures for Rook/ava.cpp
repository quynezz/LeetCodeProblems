class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0; 
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'R') { // Found the rook
                    
                    // To the right
                    int jj = j + 1; // Start checking one step to the right
                    while (jj < 8) { // Ensure within bounds
                        if (board[i][jj] == '.') {
                            jj++;
                        } else if (board[i][jj] == 'B') { // Blocked by bishop
                            break;
                        } else if (board[i][jj] == 'p') { // Pawn found
                            count++;
                            break;
                        }
                    }

                    // To the left
                    jj = j - 1; // Start checking one step to the left
                    while (jj >= 0) {
                        if (board[i][jj] == '.') {
                            jj--;
                        } else if (board[i][jj] == 'B') {
                            break;
                        } else if (board[i][jj] == 'p') {
                            count++;
                            break;
                        }
                    }

                    // Go up
                    int ii = i - 1; // Start checking one step up
                    while (ii >= 0) {
                        if (board[ii][j] == '.') {
                            ii--;
                        } else if (board[ii][j] == 'B') {
                            break;
                        } else if (board[ii][j] == 'p') {
                            count++;
                            break;
                        }
                    }

                    // Go down
                    ii = i + 1; // Start checking one step down
                    while (ii < 8) {
                        if (board[ii][j] == '.') {
                            ii++;
                        } else if (board[ii][j] == 'B') {
                            break;
                        } else if (board[ii][j] == 'p') {
                            count++;
                            break;
                        }
                    }
                    
                    return count; // Return immediately after processing all directions
                }
            }
        }
        
        return count; // If rook is not found (edge case)
    }
};
