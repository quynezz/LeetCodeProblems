class Solution {
public:
    bool isBalanced(string num) {
        int sumE = 0;
        int sumO = 0;
        for(int i = 0; i < num.size(); i++){
            if(i % 2 == 0){
                sumE += num[i] - '0';
            }else if(i % 2 != 0){
                sumO += num[i] - '0';
            }
        }
        return sumE == sumO;
    }
};