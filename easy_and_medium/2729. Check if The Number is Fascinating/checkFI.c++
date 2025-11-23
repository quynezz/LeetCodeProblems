class Solution {
public:
    bool isFascinating(int n) {
        unordered_map<int,int> m;
        string temp1 = to_string(n) + to_string(n * 2) + to_string(n * 3);
        for(auto it : temp1) m[it - '0']++;
        for(int i = 1; i <= 9; i++) {
            if(!m.count(i) || m[i] != 1)return false;
        }
        return true;
    }
};