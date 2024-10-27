#include<bits/stdc++.h> 

using namespace std; 

class Solution {
public:
    int reverse(int x) {
        int m = 0;
        // Tạo biến sign check x là âm hay dương
        int sign = (x < 0) ? -1 : 1; 
        // Chuyển giá trị hiện tại về giá trị tuyệt đối để đảo 
        x = abs(x); 

        while (x != 0) {
            int lastdigit = x % 10;
            // Tràn số
            if (m > (INT_MAX - lastdigit) / 10) {
                return 0;
            }
            m = m * 10 + lastdigit;
            x /= 10;
        }
        // Nhân với giá trị check ban đầu 
        m *= sign; 

        return m;
    }
};
