class Solution {
public:
    int maximumSwap(int num) {
        int mNum = num; 
        string ans = to_string(num);
        for(int i = 0; i < ans.size() - 1; i++){
            for(int j = i + 1; j < ans.size(); j++){
            string temp = ans;
            swap(temp[i],temp[j]); 
            mNum = max(mNum,stoi(temp)); 
            }
        }
        return mNum;
    }
};