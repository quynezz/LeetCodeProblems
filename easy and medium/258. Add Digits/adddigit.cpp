class Solution {
public:
    int addDigits(int num) { 
        int sum = num;
        while(sum >= 10){
            num = sum; 
            sum = 0;
            while(num){  
                sum += num % 10; 
                num /= 10;
            }
        }
        return sum;
    }
};