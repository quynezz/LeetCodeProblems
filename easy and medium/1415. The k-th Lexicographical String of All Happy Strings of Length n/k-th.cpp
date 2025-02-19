class Solution {
    void backtrack(int n, vector<string>& ans,string temp){
        if(temp.size() == n){
            cout << temp << " ";
            ans.push_back(temp);
            return;
        }
        for(char i = 'a'; i <= 'c'; i++){
            if(temp.size() > 0  && temp.back() == i){
                continue;
            }
            backtrack(n,ans,temp + i);
        }
    }
    public:
        string getHappyString(int n, int k) {
            vector<string> ans;        
            string temp = "";
            backtrack(n,ans,temp);
            if(ans.size() < k) return "";
            return ans[k - 1];
        }
    };