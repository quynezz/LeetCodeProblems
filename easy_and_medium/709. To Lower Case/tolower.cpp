class Solution {
public:
    string toLowerCase(string s) {
    string res ="";
   for(auto it : s){  
      res += tolower(it);
   }
   return res;
    }
};