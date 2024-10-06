#include<bits/stdc++.h> 
using namespace std; 
#include <unordered_map>
class Solution {
public:
    bool isValid(string s) {   
        stack<int> st; 
        unordered_map<int,int> mp = {
            {')','('},
            {'}','{'},
            {']','['},
        }; 
        for(auto it : s){   
            // check closing
            if(mp.find(it) != mp.end()){
                // check top value  = key value of it  
                if(!mp.empty() && st.top() == mp[it]){  
                    st.pop();
                } else { 
                    return false;
                }
            } else {
                // push openning
                st.push(it);
            }
        }
        return st.empty();
    }
};
