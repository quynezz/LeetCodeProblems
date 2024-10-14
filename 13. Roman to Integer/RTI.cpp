#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) { 
    int n = s.length();
  unordered_map<char, int> mp{ 
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };   
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            if(mp[s[i]] < mp[s[i + 1]] ){ 
                ans += (mp[s[i]] * -1);
            } else { 
                ans += mp[s[i]];
            }
        }
        return ans;
    }
};