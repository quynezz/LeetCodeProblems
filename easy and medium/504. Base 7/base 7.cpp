class Solution {
public:
    string convertToBase7(int num) { 
        if(num == 0){ 
            return "0";
        }
        string temp = ""; 
        int sign = 0; 
        num > 0 ? sign = 1 : sign = -1; 
        int m = abs(num); 
        while(m > 0){ 
            temp += to_string(m % 7); 
            m /= 7;
        }
        reverse(temp.begin(),temp.end()); 
        if(sign == -1){ 
            return "-" + temp;
        } 
        return temp;
    
    }
};