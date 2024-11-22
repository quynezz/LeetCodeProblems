class Solution {
public:
    double myPow(double x, int n) {
        // Handle base case where exponent is 0
        if (n == 0) return 1;
        long long N = n;  // Use long long to handle INT_MIN safely
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1; 
        while(N > 0){
            if(N % 2 == 1){
                result *= x;
            }
            x *= x;
            N /= 2;
        }
        
        return result;
    }
};
