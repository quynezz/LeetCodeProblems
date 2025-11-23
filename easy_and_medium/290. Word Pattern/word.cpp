class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> v; 
        while (ss >> word) {  
            v.push_back(word);
        } 
        if (v.size() != pattern.size()) { 
            return false;
        }
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        for (int i = 0; i < pattern.size(); i++) { 
            char c = pattern[i];
            string x = v[i];
            if (m1.count(c) && m1[c] != x) return false;
            if (m2.count(x) && m2[x] != c) return false;

            m1[c] = x;
            m2[x] = c;
        }
        return true;
    }
};
