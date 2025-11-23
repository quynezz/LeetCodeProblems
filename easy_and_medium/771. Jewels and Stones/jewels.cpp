class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        unordered_map<char,int> m;
        for(auto it : jewels){
            m[it]++;
        }
        for(auto it : stones){
            if(m.find(it) != m.end()){
                count++;
            }
        }
        return count;
    }
};