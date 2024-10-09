#include <bits/stdc++.h>
typedef long long ll; 

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1] += 1;   
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] > 9) {
                digits[i] = 0; // Reset current digit to 0
                if (i == 0) { // If we are at the first digit
                    digits.insert(digits.begin(), 1); 
                    break;
                } else if(i > 0){
                    // if we are not at the first digit
                digits[i - 1]++; 
                }
            }
        }
        return digits;
    }  
};
