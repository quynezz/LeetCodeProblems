class Solution {
private: 
    bool back(vector<vector<char>>& board, int index, string& word, int row, int col) {
        if (index == word.length()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';
        bool found = back(board, index + 1, word, row + 1, col) ||
                     back(board, index + 1, word, row - 1, col) ||
                     back(board, index + 1, word, row, col + 1) ||
                     back(board, index + 1, word, row, col - 1);

        board[row][col] = temp; // Restore original value

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (back(board, 0, word, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
