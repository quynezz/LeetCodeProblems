class Solution {
public:
    string convert(string s, int numRows) {
        // down up 
        if (numRows == 1) return s;
        string temp = "";
        vector<string> v(numRows);
        int row = 0;
        bool down = true;
        for(int i = 0; i < s.length(); i++){  
            if(!down && row == 0){
                down = true;
            }
            if(down && row == numRows - 1){  
                down = false;
            }
            v[row].push_back(s[i]);
            if(down){
                row++;
            }
            if(!down){
                row--;
            }
        }
        for(auto it : v){ 
            temp += it;
        }
        return temp;l
    }
};
