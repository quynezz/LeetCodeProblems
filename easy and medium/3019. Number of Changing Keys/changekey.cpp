class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0; 
        for(int i = 0; i < s.size() - 1; i++){
            toupper(s[i]) != s[i + 1] && tolower(s[i]) != s[i + 1] ? count += 1 : count += 0;
        }
        return count;
    }
};