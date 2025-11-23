class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {     
        vector<vector<int>> topo(n);
        vector<int> champ;  
        for(int i = 0; i < edges.size(); i++){
            topo[edges[i][1]].push_back(edges[i][0]);
        }
        int i = 0;
        while(i < n){
            if(topo[i].size() == 0){ 
                champ.push_back(i);
            }
            i++;
        }  
        return i = (champ.size() > 1) ? -1 : champ[0];
    }
};