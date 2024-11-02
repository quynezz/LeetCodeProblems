class Solution {
public:
    bool isSubsequence(string s, string t) {  
        int i = 0; 
        int count = 0;
        int u = 0; 
        for(auto it : s){ 
            count++;
        }
        while(u < t.length() && i < s.length()){
            if(s[i] == t[u]){ 
                i++;
                count--;
            }  
            u++;
        }
        return count == 0;
    }
};