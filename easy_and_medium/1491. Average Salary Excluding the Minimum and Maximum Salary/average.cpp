class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        int ans = 0;
        int count = 0;
        for(int i = 1; i < salary.size() - 1; i++){
            ans += salary[i];
            count++;
        }
        return (double)ans / count;
    }
};