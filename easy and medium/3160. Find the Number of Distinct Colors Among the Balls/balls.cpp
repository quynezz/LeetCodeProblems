class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> m,color;
        int count = 0;
        int n = queries.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int first = queries[i][0];
            int second = queries[i][1];
            // check if the same have seen 
            if(m.count(first) && m[first] == second){
                ans[i] = count;
                continue;
            }
            if(m.count(first)){
                int temp_color = m[first];
                color[temp_color]--;
                if(color[temp_color] == 0){
                    count--;
                    color.erase(temp_color);
                }
            }
            if(!color.count(second)){
                count++;
            }
            m[first] = second;
            color[second]++;
            ans[i] = count;
        }
        return ans;
    }
};