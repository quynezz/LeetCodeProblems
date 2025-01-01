class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int,int>> s;
        s.insert({x,y});
        for(int i = 0; i < path.size(); i++){
            if(path[i] == 'N') y += 1;
            else if(path[i] == 'S') y -= 1;
            else if(path[i] == 'E') x += 1;
            else if(path[i] == 'W') x -= 1;
            if(s.find({x,y}) != s.end()) return true;
            else s.insert({x,y});
        }
        return false;
    }
};