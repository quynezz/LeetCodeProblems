class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            int maxN = -1;
            auto combine = [&](int n) -> long long{
                long long ans = 0;
                while(n != 0){
                    ans += n % 10;
                    n /= 10;
                }
                return ans;
            };
            unordered_map<int,priority_queue<int>> m;
            set<int,greater<int>> s;
            int ans = 0;
            bool find = false;
            for(int i = 0; i < nums.size(); i++){
                int temp = combine(nums[i]); 
                m[temp].push(nums[i]);
                if(m[temp].size() >= 2){
                    cout << "OK" << endl;
                    s.insert(temp);
                    find = true;
                } 
            }
            if(find == false) return -1;
            int max1 = 0;
            for(auto it : s){
                int num1 = m[it].top();
                m[it].pop();
                int num2 = m[it].top();
                m[it].pop();
                max1 = max(max1,(num1+num2));
            }
            return max1;
        }
    };