class Solution {
public:
    string removeDigit(string number, char digit) {
        string res = "";
        int count = 0;
        vector<bool> visited(number.size(),0);
        for(auto it : number){
            if(it == digit){
                count++;
            }
        }
        while(count != 0){
        string temp1 = "";
        bool done = false;
        for(int i = 0; i < number.size(); i++){
            if(number[i] == digit && visited[i] == false && done == false){ 
                visited[i] = true;
                done = true;
                continue;
            }
            temp1 += number[i];
        }
        if(temp1 > res){
            res = temp1;
        }
        count--;
        }
        return res;
    }
};





// class Solution {
// public:
//     string removeDigit(string number, char digit) {
//         string res = "";
//         for(int i = 0; i < number.size(); i++){
//             if(number[i] == digit){
//                string temp = number.substr(0,i) + number.substr(i + 1,number.size() - 1);
//                res = max(temp,res);
//             }
//         }
//         return res;
//     }
// };