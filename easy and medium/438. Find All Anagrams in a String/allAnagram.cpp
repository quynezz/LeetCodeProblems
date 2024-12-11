class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        vector<int> v;
        if(p.size() > s.size()){
            return v;
        }
        for(int i = 0; i < p.size(); i++){
            v1[s[i] - 'a']++;
            v2[p[i] - 'a']++;
        }
        if(v1 == v2){
            v.push_back(0);
        }
        for(int i = p.size(); i < s.size(); i++){
            v1[s[i - p.size()] - 'a']--;
            v1[s[i] - 'a']++;
            if(v1 == v2){
                v.push_back(i - p.size() + 1);
            }
        }
        return v;
    }
};