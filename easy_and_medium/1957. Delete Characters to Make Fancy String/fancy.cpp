class Solution {
public:
    string makeFancyString(string s) {
        string res = ""; 
        int count = 1;  
        res += s[0]; 
        
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count <= 2) {
                res += s[i];
            }
        }
        
        return res;
    }
};
