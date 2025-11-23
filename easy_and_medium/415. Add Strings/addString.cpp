    class Solution {
    public:
        string addStrings(string num1, string num2) { 
            int i = num1.size() - 1;
            int j = num2.size() - 1;
            int carry = 0;
            string temp = "";
            while(i >= 0 || j >= 0 || carry){ 
                int sum = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0) + carry;   
                temp += to_string(sum % 10);
                carry = sum / 10;
                if(i >= 0) i--;
                if(j >= 0) j--;
            } 
            reverse(temp.begin(),temp.end());
            return temp;

        }
    };