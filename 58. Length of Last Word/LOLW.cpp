#include <bits/stdc++.h>
typedef long long ll; 
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        //  i point at the last element of the string, the first while is loop and stop till it see a ' ', second loop start from the last word till it see the ' '; 
        int i = s.length(); 
        int length = 0;
        while(i > 0 && s[i - 1] == ' '){  
            i--;
        }
        while(i > 0 && s[i - 1] != ' '){  
            i--; 
            length++;
        }
        return length;
    }
}; 
