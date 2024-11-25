class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) { 
        string target = "123450";
        string start = "";
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                start += to_string(board[i][j]);
            }
        }
        unordered_map<int, vector<int>> m {
            {0, {1, 3}},
            {1, {0, 2, 4}},
            {2, {1, 5}},
            {3, {0, 4}},
            {4, {1, 3, 5}},
            {5, {2, 4}}
        };
        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        visited.insert(start);
        int steps = 0; 
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string current = q.front();
                q.pop();
                if(current == target){
                    return steps;
                }
                int zero = current.find('0');
                for(int next : m[zero]){
                    string nextBoard = current;
                    swap(nextBoard[zero], nextBoard[next]);
                    if(visited.find(nextBoard) == visited.end()){
                        q.push(nextBoard);
                        visited.insert(nextBoard);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
