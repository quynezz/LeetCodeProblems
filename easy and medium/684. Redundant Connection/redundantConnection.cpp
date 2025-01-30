    class Solution {
    int parent[1001];
    private: 
        void make_set(vector<vector<int>>& edges){
            set<int> s;
            for(int i = 0; i < edges.size(); i++){
                    parent[edges[i][0]] = edges[i][0];
                    parent[edges[i][1]] = edges[i][1];  
            }
        }
        int find(int v){
            if(v == parent[v]){
                return v;
            }
            return find(parent[v]);
        }
        int unionFind(int a, int b){
            a = find(a);
            b = find(b);
            // check = 0 mean haven't union yet
            int check = 0;
            if(a != b){
                parent[b] = a;
            }else{
                check = 1;
            }
            return check;
        }
    public:
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {    
            make_set(edges);
            vector<int> res;
            int temp = 0;    
            for(int i = 0; i < edges.size(); i++){
                temp = unionFind(edges[i][0],edges[i][1]);
                if(temp == 1){
                    res.push_back(edges[i][0]);
                    res.push_back(edges[i][1]);
                }
            }
            if(res.size() > 2){
                return {res[res.size() - 1],res[res.size() - 2]};
            }
            return res;
        }
    };