class Solution {
public:
    vector<int> shortestToChar(string s, char c) {    
        vector<int> v;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == c){
                v.push_back(0);
            }else{ 
                bool find1 = false;
                bool find2 = false;
                int n1 = i;
                int n2 = i;
                while(n1 >= 0){
                    if(s[n1] == c){
                        find1 = true;
                        break;
                    }
                    n1--;
                }
                while(n2 < s.size()){
                    if(s[n2] == c){
                        find2 = true;
                        break;
                    }
                    n2++;
                }
                if(find1 == true && find2 == true){
                    int temp1 = abs(i - n1);
                    int temp2 = abs(i - n2);
                    int temp = min(temp1,temp2);
                    v.push_back(temp);
                }else if(find1 == true && find2 == false){
                    int tempz = abs(i - n1);
                    v.push_back(tempz);
                }else if(find1 == false && find2 == true){
                    int tempz = abs(i - n2);
                    v.push_back(tempz);
                }
            }
        }
        return v;
    }
};