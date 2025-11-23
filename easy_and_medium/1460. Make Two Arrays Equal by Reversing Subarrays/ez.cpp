class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2; 
        for(auto it : target){
            m1[it]++;
        }
        for(auto it : arr){
            m2[it]++;
        }
        for(auto it : arr){
            if(m1[it] != m2[it] || m1.find(it) == m1.end()){
                return false;
            }
        }
        
        return true;
    }
};