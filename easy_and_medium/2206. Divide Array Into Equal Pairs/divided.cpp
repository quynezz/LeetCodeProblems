class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            int n = nums.size() / 2;
            int count = 0;
            unordered_map<int,int> m;
            for(auto it : nums) m[it]++;
            for(auto& [ num , fre] : m){
                if(fre >= 2) {
                    count += fre / 2;
                }
            }
            cout << count << " " << n << endl;
            return count == n;
        }
    };