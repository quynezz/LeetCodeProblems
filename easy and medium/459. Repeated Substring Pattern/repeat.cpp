class Solution {
public:
    bool repeatedSubstringPattern(string s) {   
        string temp = s + s; 
        string sub = temp.substr(1,temp.length() - 2); 
        if(sub.find(s) != string::npos) {  
            return true;
        } 
        return false;
       
       
       
       
       
       
        // int n = s.length();
        // for(int i = 1; i <= n / 2; i++){  
        //     if(n % i == 0){ 
        //     string sub = s.substr(0,i);
        //     string temp = ""; 
        //     for(int j = 0; j < n / i; j++){ 
        //         temp += sub; 
        //         if(temp == s){
        //              return true; 
        //         }
        //     } 
        //     }
        // }
        // return false;
    }
};