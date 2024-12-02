class Solution {
public:
    int lastRemaining(int n) {
        int start = 1, step = 1;
        int remaining = n;
        bool leftToRight = true;

        while (remaining > 1) {
            if (leftToRight || remaining % 2 == 1) {
                start += step;
            }
            step *= 2;
            remaining /= 2;
            leftToRight = !leftToRight;
        }

        return start;
    }
};
