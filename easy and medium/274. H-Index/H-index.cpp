class Solution {
public:
    int hIndex(vector<int>& citations) { 
        sort(citations.begin(),citations.end(),greater<int>());
        int i = 1;
        for(auto it : citations){
            if(it >= i){
                i++;
            }else{
                break;
            }
        }
        return i - 1;
    }
};