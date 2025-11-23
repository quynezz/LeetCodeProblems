#include<bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    bool isValid(string s) {  
        stack<char> st; 
        unordered_map<char,char> mp = { 
            {')','('},
            {'}','{'},
            {']','['}
        };
        for(char it : s){  
            if(mp.find(it) != mp.end()){
                if(!st.empty() && st.top() == mp[it]){  
                    st.pop();
                } else { 
                    return false;
                }
            } else { 
                st.push(it);
            }
        }
        return st.empty();
    }
};