class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> us(s.begin(),s.end());
        return us.size();
    }
};