class Solution {
public:
    bool isSubstringPresent(string s) {
        for(int i = 0; i < s.size() - 1; i++){
           string temp = "";
           temp.push_back(s[i + 1]);
           temp.push_back(s[i]);
            if(s.find(temp) != string::npos){
                return true;
            }
        }
        return false;
    }
};