class Solution { 
public:
int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == INT_MIN && divisor == 1) return INT_MIN;
    int sign = (dividend < 0) == (divisor < 0) ? 1 : -1;
    long long absDividend = abs(static_cast<long long>(dividend));
    long long absDivisor = abs(static_cast<long long>(divisor));

    int quotient = 0;  
    while (absDividend >= absDivisor) {
        long long temp = absDivisor, multiple = 1;
        while (absDividend >= (temp << 1)) {
            temp <<= 1;          
            multiple <<= 1;      
        }
        absDividend -= temp;      
        quotient += multiple;      
    }

    return sign * quotient;     
}
};
