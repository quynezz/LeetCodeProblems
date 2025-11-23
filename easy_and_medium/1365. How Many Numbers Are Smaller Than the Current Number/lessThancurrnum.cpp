class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> m;
        vector<int> v;
        for(int i = 0; i < temp.size(); i++){ 
            int count = 0;
            if(i == 0){
                m[temp[i]] = 0;
            }else{
            int n = i;
            while(n >= 0){  
                if(temp[i] > temp[n]){
                    count++;
                }
                n--;
            }
            m[temp[i]] = count;
            }
        }
        for(auto it : nums){
            v.push_back(m[it]);
        }
        return v;
    }
};