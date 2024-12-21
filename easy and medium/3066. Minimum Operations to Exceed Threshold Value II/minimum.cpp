class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<>> pq(nums.begin(),nums.end());
        long long count = 0;
        while(pq.top() < k){
            long long n = pq.top();
            pq.pop();
            long long m = pq.top();
            pq.pop();
            long long temp = min(n,m) * 2 + max(n,m);
            count++;
            pq.push(temp);
        }
        return count;
    }
};