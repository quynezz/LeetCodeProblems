class Solution {
public:
    string removeStars(string s) {
        stack<char> st; 
        for(auto it : s){
            if(it == '*'){
                st.pop();
            }else{
                st.push(it);
            }
        }
        string ans = "";
        while(!st.empty()){
            char temp = st.top();
            ans += temp;
            st.pop(); 
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};