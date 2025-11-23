class Solution {
public:
    bool isPalindrome(string s) { 
        if(s == " "){ 
            return true;
        }  
        string temp = "";
        string ans = ""; 
        stringstream ss(s); 
        string word;  
        for(int i = 0; i < s.length(); i++){ 
            if(isalnum(s[i])){ 
                temp += tolower(s[i]);
            }
        }
        for(auto it : temp){ 
            ans += it;
        } 
        reverse(ans.begin(),ans.end()); 
        if(ans == temp){ 
            return true;
        }
        return false;
    }
};