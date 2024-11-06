class Solution {
public:
    int myAtoi(string s) {
        string digit = "";
        int sign = 1;
        int i = 0; 
        while (i < s.length() && s[i] == ' ') { 
            i++;
        }
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) { 
            sign = (s[i] == '-') ? -1 : 1;
            i++; 
        }

        while (i < s.length() && isdigit(s[i])) { 
            digit += s[i]; 
            i++;
        }
        if (digit.empty()) { 
            return 0;
        }
        try {
            int temp = stoi(digit) * sign;
            return temp;
        } catch (out_of_range& e) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
    }
};



