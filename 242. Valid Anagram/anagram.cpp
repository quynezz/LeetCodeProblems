class Solution {
public:
    bool isAnagram(string s, string t) {
    unordered_map<char,int> m1;
   unordered_map<char,int> m2; 
   for(auto it1 : s){ 
      m1[it1]++;
   }
   for(auto it2 : t){ 
      m2[it2]++;
   }
   for(auto it3 : s){ 
      if(m1[it3] != m2[it3]){
         return false;
      }
   }
   for(auto it3 : t){ 
      if(m1[it3] != m2[it3]){
         return false;
      }
   }
return true;
    }
};