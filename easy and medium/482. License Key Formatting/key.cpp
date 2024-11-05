class Solution {
public:
    string licenseKeyFormatting(string s, int k) { 
        string temp = "";
        string res = "";
        int i = 0;
        for(auto it : s){ 
            if(isalnum(it)){  
                temp += toupper(it);
            }
        }
        int first = temp.length() % k; 
        if(first != 0){  
            res += temp.substr(i,first); 
            i += first;
            if(i < temp.length()){ 
                res += '-';
            }
        }
        while(i < temp.length()){ 
            res += temp.substr(i,k); 
            i += k;
            if(i <  temp.length()){ 
                res += '-';
            }
        }
        return res;
    }
};