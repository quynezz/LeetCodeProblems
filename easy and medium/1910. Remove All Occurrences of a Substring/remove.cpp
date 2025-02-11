class Solution {
    public:
        string removeOccurrences(string s, string part) {
            while(s.size() > 0 && s.size() > s.find(part)){
                s.erase(s.find(part),part.size());
            }
            return s;
        }
    };