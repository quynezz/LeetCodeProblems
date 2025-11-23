class Solution {
public:
    string multiply(string num1, string num2) {       
        if(num1 == "0" || num2 == "0"){
            return "0";
        } 
        int n = num1.length();
        int m = num2.length(); 
        string res = "";
        vector<int> v(n + m, 0); // 
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int temp = (num1[i] - '0') * (num2[j] - '0'); 
                int sum = temp + v[i + j + 1]; 
                v[i + j + 1] = sum % 10;  
                v[i + j] += sum / 10; // carry 
            }
        } 
        bool zero = true;
        for(auto it : v){
            if(zero && it == 0){
                continue;
            }
            zero = false;
            res += to_string(it);
        }
        return res;
    }
};