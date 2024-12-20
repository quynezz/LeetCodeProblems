class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int div = 0;
        int temp = x;
        while(temp != 0){
            div += (temp % 10);
            temp /= 10;
        }
        return x % div == 0 ? div : -1;
    }
};