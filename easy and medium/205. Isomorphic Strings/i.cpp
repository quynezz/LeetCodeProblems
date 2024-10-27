class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1;
        unordered_map<char,char> m2;
        int n = 0;
        if(s.length() != t.length()){ 
            return false;
        }     
        for(int i = 0; i < s.length(); i++){  
            char n = s[i];
            char m = t[i];
            if(m1.count(n) && m1[n] != t[i] || m2.count(m) && m2[m] != s[i]){ 
                return false;
            }
            m1[n] = t[i];
            m2[m] = s[i];
        }
        
        return true;
    }
};