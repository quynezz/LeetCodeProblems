class Solution {
private:   
    string emailUnique(string s){  
        string res = "";
        int i = 0; // local name;
        int q = 0; // @
        int k = s.length() - 1;
        int j = 0; // domain name
        while(q < s.length()){ 
            if(s[q] == '@'){
                break;
            }
            q++;
        }
            j = q + 1; 
        while(i < q){ 
            if(s[i] == '+'){ 
                break;
            }else if(s[i] == '.'){
                i++;
            }
            else {
                res += s[i];
                i++;
            }
        }
        res += '@';
        while(j < s.length()){  
            res += s[j];
            j++;
        }
        return res;
    }
public:
    int numUniqueEmails(vector<string>& emails) { 
        unordered_set<string> s;
        for(auto it : emails){ 
            it = emailUnique(it);  
            s.insert(it);
        } 
        return s.size();
    }
};
