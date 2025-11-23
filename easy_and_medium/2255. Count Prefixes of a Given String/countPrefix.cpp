class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
      int count = 0;
      for(auto it : words){
        int i = 0;
        bool ok = true;
        if(s.find(it) != string::npos){
            while(i < it.length()){
                if(it[i] != s[i]){
                    ok = false;
                    break;
                }
                i++;
            }
        }else{ 
            ok = false;
        }
        if(ok == true){
            count++;
        }
      }  
      return count;
    }
};