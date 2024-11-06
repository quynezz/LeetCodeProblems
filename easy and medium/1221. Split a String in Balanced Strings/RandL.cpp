class Solution {
public:
    int balancedStringSplit(string s) { 
        int ans = 0;
        int count = 0; 
      for(auto it : s){ 
        if(it == 'R'){ 
            count++;
        }else if(it == 'L'){ 
            count--;
        }
        if(count == 0){ 
            ans++;
        }
      }
      return ans;
    }
};
