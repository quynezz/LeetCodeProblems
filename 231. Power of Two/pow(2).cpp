class Solution {
public:
    bool isPowerOfTwo(int n) { 
        long long temp = 1;
        if(temp == n){ 
            return true;
        }
        for(int i = 0; i < 31; i++){  
            temp *= 2;
            if(temp == n){
                return true;
            }else if(temp > n){ 
                return false;
                break;
            }
        }
        return false;
    }
};