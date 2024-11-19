class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
    unordered_map<int,int> m; 
    vector<int> v;
    int maxN = 0;
    for(auto it : digits){
        m[it]++;
    }
    for(int i = 100; i < 999; i += 2){
        int x = i;
        int n1 = x % 10;
        x /= 10;
        int n2 = x % 10;
        x /= 10;
        int n3 = x % 10;
        if(m[n1] != 0){
            m[n1]--; 
            if(m[n2] != 0){
                m[n2]--;
                if(m[n3] != 0){
                    v.push_back(i);
                }
                m[n2]++;
            }
                m[n1]++;
        }
    }
    return v;
    }
};