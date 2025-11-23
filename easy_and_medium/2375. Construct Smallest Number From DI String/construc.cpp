


class Solution {
    public:
        string smallestNumber(string pattern) {
            int n = pattern.size() + 1;
            vector<int> v(n + 1);
            stack<int> st;
            string ans = "";
            for(int i = 0; i < n; i++){
                st.push(i + 1);
                 if(pattern[i] == 'I'){
                    while(!st.empty()){
                        ans += (to_string(st.top()));
                        st.pop();
                    }
                }
            }
            while(!st.empty()){
                ans += to_string(st.top());
                st.pop();
            }
            return ans;
        }
    };