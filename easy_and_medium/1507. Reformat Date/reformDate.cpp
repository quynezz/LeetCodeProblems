class Solution {
public:
    string reformatDate(string date) {
        string temp = "";
        int count = 0;
        unordered_map<string,string> monthIndex = { 
    {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
    {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"} 
};
        stringstream ss(date);
        string word; 
        while(ss >> word){
            // for day
            if(count == 0){
                string day = "";
                for(int i = 0; i < word.size(); i++){
                    if((int)word[i] >= 48 && (int)word[i] <= 57){
                        day += word[i]; 
                    }
                }
                if(day.size() == 1){
                    char cr = day.back();
                    day.pop_back();
                    day += '0';
                    day += cr;
                }
                reverse(day.begin(),day.end());
                temp += day;
                temp.push_back('-');
                count++;
            }else if(count == 1){
                string cr = monthIndex[word];
                reverse(cr.begin(),cr.end());
                temp += cr;
                temp.push_back('-');
                count++;
            }else if(count == 2){
                string ret = word;
                reverse(ret.begin(),ret.end());
                temp += ret;
            }
        }
        reverse(temp.begin(),temp.end());
        return temp;
    
    }
};