class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> m;
        priority_queue<pair<char,int>> pq;
        for(auto it : s){
            m[it]++;
        }
        for(auto& [c,f] : m){
            pq.push({c,f});
        }
        string temp = "";
        while(!pq.empty()){
            auto [c,f] = pq.top();
            pq.pop();
            int n = min(f,repeatLimit);
            f -= n;
            temp.append(n,c);
            if(f > 0){
                if(pq.empty()) break;
                auto [nextC,nextF] = pq.top();
                pq.pop();
                temp += nextC; 
                nextF--;
                if(nextF > 0){
                    pq.push({nextC,nextF});
                }
                pq.push({c,f});
            }
        }
        return temp;
    }
};