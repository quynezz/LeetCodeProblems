class Solution {
public:
    int maxDepth(string s) {
        int temp = 0;
        int maxD = 0; 
        for(auto it : s){
            if(it == '('){                
                temp++;
            }else if(it == ')'){
                maxD = max(temp,maxD);
                temp--;
            }
        }
        return maxD;
    }
};