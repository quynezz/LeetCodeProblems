class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {  
        vector<vector<char>> rotatedBox(box[0].size(),vector<char>(box.size())); 
        for(int i = 0; i < box.size(); i++){
            for(int j = 0; j < box[i].size(); j++){  
                int jt = j; 
                if(box[i][j] == '#'){ 
                    while(jt < box[i].size()){
                        if(box[i][jt] == '*'){
                            break;
                        } 
                        if(box[i][jt] == '.'){
                            swap(box[i][j],box[i][jt]);
                        }
                        jt++;
                    }
                }
                rotatedBox[j][box.size() - 1 - i] = box[i][j];
        } 
    }
        return rotatedBox;
    }
};