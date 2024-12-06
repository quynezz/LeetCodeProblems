class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long  i = 1; i < INT_MAX; i++){
            if(i * i == num){
                return true;
            }else if(i * i > num ){
                return false;
            }
        }
        return false;
    }
};