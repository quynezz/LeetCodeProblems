class Solution {
public:
    string removeOuterParentheses(string s) { 
        stack<int> st;
        string ans = ""; 
        for(auto it : s){  
            if(it == '(' && st.empty()){  
            st.push(it); 
        } else if(it == '(' && !st.empty()){ 
            st.push(it);
            ans += it;
        }
        if(it == ')'){ 
            st.pop();
            if(!st.empty()){ 
                ans += it;
            }
        }
        }
        return ans;
    }
};