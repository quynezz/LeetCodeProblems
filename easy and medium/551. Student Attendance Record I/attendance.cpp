class Solution {
public:
    bool checkRecord(string s) {
        unordered_map<char,int> m;
        int count = 0;
        int i = 0; 
        for(auto it : s){ 
            m[it]++;
        }
        while(i < s.length()){ 
            if(s[i] == 'A'){ 
                if(m[s[i]] >= 2){ 
                    return false;
                }
            } 
            if(s[i] == 'L'){ 
                count++; 
                if(count == 3){ 
                    return false;
                }
            }else { 
                count = 0;
            }    
            i++;  
    }
    return true;
    }

};