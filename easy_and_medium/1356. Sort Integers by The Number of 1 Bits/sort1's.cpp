class Solution {
private: 
int count(int num){
    int ans = 0;
    while(num != 0){
        ans += num % 2; 
        num /= 2;
    }
    return ans;
}
public:
    vector<int> sortByBits(vector<int>& arr) {  
        vector<int> v;
        vector<vector<int>> v1(32);
        for(int i = 0; i < arr.size(); i++){
            v1[count(arr[i])].push_back(arr[i]);
        }
        for(auto it : v1){
            sort(it.begin(),it.end());
            for(auto ti : it){
                v.push_back(ti);
            }
        }
        return v;
    }
};
