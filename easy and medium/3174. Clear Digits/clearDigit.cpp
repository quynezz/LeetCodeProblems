class Solution {
    public:
        string clearDigits(string s) {
            stack<char> st; 
            for(auto it : s){
                if(isdigit(it)){
                    if(!st.empty()){
                        st.pop();
                    }
                }else{
                    st.push(it);
                }
            }
            s.clear();
            while(!st.empty()){
                s += st.top();
                st.pop();
            }
            reverse(s.begin(),s.end());
            return s;
        }
    };