class Solution {
private:
    string expandCenter(string s, int l, int r) { 
        while(l >= 0 && r < s.length() && (s[l] == s[r])){  
            l--; 
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }

public:
    string longestPalindrome(string s) {
        string longest = "";
        if(s.empty()){ 
            return s;
        }  
        for(int i = 0; i < s.length(); i++){  
            string odd = expandCenter(s,i,i);
            if(odd.length() > longest.length()){ 
                longest = odd;
            }
            string even = expandCenter(s,i,i + 1);
            if(even.length() > longest.length()){ 
                longest = even;
            }
        }
        return longest;
    }
};
// q