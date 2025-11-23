class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> v[101];
        vector<int> vC(101,0);
        vector<int> vC2(101,0);
        int count = 0;
        for(int i = 0; i < s1.size(); i++){
            v[s1[i] - '0'].push_back(i);
            vC[s1[i] - '0']++;
        }
        for(int i = 0; i < s2.size(); i++){
            bool find = false;
            int countT = 0;
            vC2[s2[i] - '0']++;
            for(auto it : v[s2[i] - '0']){
                countT++;
                if(it == i) find = true;
            }
            cout << vC[s2[i] - '0'] << " ";
            if(countT ==  0) {
                return false;
            }
            if(find == false){
                count++;
            }
        }
        for(int i = 0; i < s2.size(); i++){
            if(vC2[s2[i] - '0'] != vC[s2[i] - '0']) return false;
        }
        return count == 2 || count == 0 ? true : false;
    }
};