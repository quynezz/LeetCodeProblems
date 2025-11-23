class Solution {
private: 
bool helper(const string &s, int left, int right){ 
    while(left < right){ 
        if(s[left] != s[right]){  
            return false;
        }
        left++; 
        right--;
    }
    return true;
}
public:
    bool validPalindrome(string s) { 
        if(s.length() == (0 || 1 || 2)){ 
            return true;
        }
        int i = 0; 
        int j = s.length() - 1;
        while(i <= j){
            if(s[i] == s[j]){ 
                i++;
                j--;
            }   
            else if(s[i] != s[j]){ 
                return helper(s,i + 1, j) || helper(s,i,j - 1);
            }       
    }return true;
    }
};