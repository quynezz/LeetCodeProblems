class Solution {
public:
    bool judgeCircle(string moves) {  
        int u = 0;
        int d = 0;
        int l = 0;
        int r = 0;
        for(auto it : moves){ 
            if(it == 'U') u++;
            else if(it == 'D') d++;
            else if(it == 'L') l++;
            else if(it == 'R') r++;
        }
        return u == d && l == r;
    }
};