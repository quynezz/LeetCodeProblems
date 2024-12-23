class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;
        // start with Alice
        bool Alice = true;
        int temp = 10;
        while(true){
            if(n < temp) break;
            n -= temp; 
            if(Alice == false){
                Alice = true;
            }else if(Alice == true){
                Alice = false;
            }
            temp--;
        }
        // if Alice have to take => lose otherwise win
        return Alice == true ? false : true; 
    }
};