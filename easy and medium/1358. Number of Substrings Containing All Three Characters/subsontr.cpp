class Solution {
    public:
        int numberOfSubstrings(string s) {
            unordered_map<char,int> m; 
            int l = 0;
            int count = 0; 
            for(int r = 0; r < s.size(); r++){
                  m[s[r]]++;
                if(m.size() == 3){
                    count += s.size() - (r + 1) + 1;
                    while(m.size() == 3){
                        m[s[l]]--;
                        if(m[s[l]] == 0){
                            m.erase(s[l]);
                        }
                        l++;
                        if(m.size() == 3) count += s.size() - (r + 1) + 1;
                    }
                }
            }
            return count;
        }
    };