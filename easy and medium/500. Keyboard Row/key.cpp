class Solution {
public:
    int findrow(char a){
        if(a < 97)
            a += 32; // convert upper case to lower case for easy to find

        if(a == 'q' || a=='w'|| a=='e'|| a=='r'|| a=='t'||a=='y'||a=='u'||a=='i'||a=='o'||a=='p')
            return 1;
        else if(a =='a'|| a == 's'|| a== 'd'||a=='f'||a=='g'||a=='h'||a=='j'||a=='k'||a=='l')
            return 2;

        return 3;
    }
    vector<string> findWords(vector<string>& words) {
        string temp = "";   
        string row1 = "qwertyuiopQWERTYUIOP"; // KeyBoard row1
        string row2 = "asdfghjklASDFGHJKL"; //KeyBoard row2
        string row3 = "zxcvbnmZXCVBNM"; //KeyBoard row3
        vector<string> ans; 

        for(int index = 0; index < words.size(); index++){
            int count = 0;
            temp = words[index];
            int a = findrow(temp[0]);
            if(a == 1){
                for(int ind = 0; ind < temp.size();ind++){
                    for(int ind1 = 0; ind1 < row1.size();ind1++){
                        if(temp[ind] == row1[ind1]){
                            count++;
                            break;
                        }
                    }
                }
                if(count == temp.size()) // checking the string valid or not !!
                    ans.push_back(temp);    //if valid then push into ans
            }
            else if(a == 2){ // row 2 checking
                for(int ind = 0; ind < temp.size();ind++){
                    for(int ind1 = 0; ind1 < row2.size();ind1++){
                        if(temp[ind] == row2[ind1]){
                            count++;
                            break;
                        }
                    }
                }
                if(count == temp.size())    // checking the string valid or not !!
                    ans.push_back(temp);    //if valid then push into ans
            }
            else{  // row3 checking
                for(int ind = 0; ind < temp.size();ind++){
                    for(int ind1 = 0; ind1 < row3.size();ind1++){
                        if(temp[ind] == row3[ind1]){
                            count++;
                            break;
                        }
                    }
                }
                if(count == temp.size())    // checking the string valid or not !!
                    ans.push_back(temp); //if valid then push into ans
            }
        }
        return ans; 
    }
};