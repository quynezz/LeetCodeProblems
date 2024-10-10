#include <bits/stdc++.h>
typedef long long ll; 
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {  
        string result = ""; 
        int i = a.length()- 1;
        int j = b.length()- 1;
        int carry = 0; 
        while (i >= 0 || j >= 0 || carry){ 
            int sum = carry;
            if(i >= 0){  
             sum += a[i] - '0';
             i--;
            }
            if(j >= 0){  
             sum += b[j] - '0';
             j--;
            }   
            result += to_string(sum % 2);
            carry = sum / 2;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};



