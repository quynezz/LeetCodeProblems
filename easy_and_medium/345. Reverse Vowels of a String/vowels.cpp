class Solution {
public:
    string reverseVowels(string s) {   
        int i = 0; 
        int j = s.length() - 1;
        string vow = "aeiouAEIOU";  
        while(i <= j){  
            if(vow.find(s[i]) != string::npos && vow.find(s[j]) != string::npos) { 
                swap(s[i], s[j]);
                i++; 
                j--;
            } else if(vow.find(s[i]) == string::npos) { 
                i++; 
            } else if(vow.find(s[j]) == string::npos) { 
                j--;
            }
        } 
        return s;
    }
};
