class Solution {
public:
    bool checkString(string s) {
        char a = 'a';
        char b = 'a';
        int j = 0;
        if(s.find(b) == string::npos){ 
            return  true;
        }
        if(s.find(a) == string::npos){ 
            return true;
        }  
        for(int i = 0; i < s.length(); i++){ 
            if(s[i] == 'b'){ 
                j++;
            }
            if(s[i] == 'a' && j > 0){
                return false;
            }
        }
        return true;
    }
};