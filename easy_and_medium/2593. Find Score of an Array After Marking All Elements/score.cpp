class Solution {
public:
    long long findScore(vector<int>& nums) {
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        long long sum = 0;
        vector<bool> visited(nums.size(),false);
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i],i});
        }
        while(!pq.empty()){
            auto [num,index] = pq.top();
            pq.pop();
            if(visited[index]){
                continue;
            } 
            sum += num;
            if(index - 1 >= 0){
                visited[index - 1] = true;
            }
            if(index + 1 <= nums.size() - 1){
                visited[index + 1] = true;
            }
        }
        return sum;
    }
};