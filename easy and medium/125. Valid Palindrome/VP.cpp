#include<bits/stdc++.h> 
 
using namespace std;

class Solution {  
    public:  
    bool isPalindrome(string s){  
        int n = s.length();
        string result;
        if(n == 0){  
            return true;
        }  
        for(int i = 0; i <n; i++) {  
            if(isalnum(s[i])){ 
                result += tolower(s[i]);

            }
        }
        string temp = result; 
        reverse(temp.begin(), temp.end());
      return result == temp; 
    }
};