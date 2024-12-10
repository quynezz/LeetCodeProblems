class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> m; 
        for (int i = 0; i < s.size(); i++) {
            string temp = ""; 
            temp += s[i];
            m[temp]++;
            for (int j = i + 1; j < s.size(); j++) { 
                if (s[j] == s[i]) {
                    temp += s[j];
                    m[temp]++;   
                } else {
                    break; 
                }
            }
        }
        
        int res = 0;
        for (auto& [words, freq] : m) {
            if (freq >= 3) { 
                int n = words.size();
                res = max(res, n);
            }
        }
        
        return res == 0 ? -1 : res;
    }
};
