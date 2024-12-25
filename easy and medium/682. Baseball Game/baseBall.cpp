class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<string> v;
        for(auto it : operations){
            if(it != "x" && it != "+" && it != "D" && it != "C"){
                v.push_back(it);
            }else if(it == "+"){
                string temp = to_string(stoi(v[v.size() - 1]) + stoi(v[v.size() - 2]));
                v.push_back(temp);
            }else if(it == "D"){
                string temp = to_string(stoi(v[v.size() - 1]) * 2);
                v.push_back(temp);
            }else if(it == "C"){
                v.pop_back();
            }
        }
        int sum = 0;
        for(auto it : v){
            sum += stoi(it);
        }
        return sum;
    }
};