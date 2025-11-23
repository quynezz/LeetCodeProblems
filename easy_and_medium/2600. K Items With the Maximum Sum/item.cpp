class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {  
        int sum = 0;
        while(k != 0){  
            if(numOnes > 0){
                sum += 1;
                k--;
                numOnes--;
            }else if(numZeros > 0){ 
                sum += 0;
                k--;
                numZeros--;
            }else{
                sum += -1;
                k--;
                numNegOnes--;
            }
        }
        return sum;
    }
};