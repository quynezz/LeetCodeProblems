class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            string temp = "";
            for(int i = 0; i < nums.size(); i++){
                nums[i][i] == '0' ? temp += '1' : temp += '0';
            }
            return temp;        
        }
    };
    
    
    
    
    
    
    // class Solution {
    // void backtrack(vector<string>& ans, int n, string& temp){
    //     // base case: 
    //         if(temp.size() == n){
    //             ans.push_back(temp);
    //             return;
    //         }
    //         for(char word = '0'; word <= '1'; word++){
    //             temp += word;
    //             backtrack(ans,n,temp);
    //             temp.pop_back();
    //         }
    // }
    // public:
    //     string findDifferentBinaryString(vector<string>& nums) {
    //         vector<string> ans; 
    //         string temp = "";
    //         int n = nums.size();
    //         backtrack(ans,n,temp);
    //         set<string> st;
    //         for(auto it : nums) st.insert(it);
    //         for(auto it : ans){
    //             if(st.find(it) == st.end()){
    //                 return it;
    //             }
    //         }
    //         return "";
    //     }
    // };