class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(),nums.end()); 
        int temp = 0;
        while(k != 0){
            int n = q.top();
            temp += q.top();
            q.pop();
            q.push(n + 1);
            k--;
        }
        return temp;
    }
};