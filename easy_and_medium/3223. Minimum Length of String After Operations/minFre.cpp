class Solution {
public:
    int minimumLength(string s) {
        vector<char> m(26,0);
        int n = s.size(); 
        for(int i = 0; i < s.size(); i++){
            m[s[i] - 'a']++;
            if(m[s[i] - 'a'] == 3){
                n -= 2;
                m[s[i] - 'a'] = 1;
            }
        }
        return n;
    }
};