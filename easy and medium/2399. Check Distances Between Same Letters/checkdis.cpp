class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<int,int> m;
        vector<pair<char,int>> v;
        for(int i = 0; i < s.size(); i++){
            int n = s[i] - 'a';
            if(m.find(n) != m.end()){
                int temp = i - m[n] - 1;
                v.push_back({s[i],temp});
            }else{
            m[n] = i;
            }
        }
        sort(v.begin(),v.end(), [&](pair<int,int>a, pair<int,int>b){
            return (a.first - 'a') < (b.first - 'a');
        });
        for(auto& [charac,dis] : v){
            for(int i = 0; i < distance.size(); i++){
                if(i == (charac-'a')){
                    if(dis != distance[i]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};