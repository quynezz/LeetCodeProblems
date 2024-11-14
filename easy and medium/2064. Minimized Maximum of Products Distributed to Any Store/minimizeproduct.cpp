class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {   
        int maxQ = 0;
        for(auto it : quantities){
            maxQ = max(it,maxQ);
        }
        int l = 1; 
        int r = maxQ;
        while(l <= r){
            int store = 0; 
            int mid = ( l + r ) / 2;
            for(auto it : quantities){  
                store += ceil((double)it / mid);
            }
            if(store < n){
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return l;
    }
};