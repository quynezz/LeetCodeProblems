class Solution {
public:
    bool isPalindrome(int x) { 
        if ( x < 0 ){  
            return false;
        }  
        long long  m = 0; 
        int temp = x; 
            while (x != 0){  
            m = m * 10 + x % 10;
            x /= 10;
        }
        return m == temp;
    }
     
     
};

// Brute Force