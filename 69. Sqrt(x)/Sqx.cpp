
class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) {
            return 0;
        }
        long long l = 1;
        long long r = x;
        long long m;
        while (l <= r) {
            m = (l + r) / 2;
            if (m * m == x) {
                return m;
            } else if (m * m < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
};