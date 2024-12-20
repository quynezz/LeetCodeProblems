class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        priority_queue<int> pq;
        for(auto it : capacity){
            pq.push(it);
        }
        int temp = 0;
        int count = 0;
        for(auto it : apple){
            temp += it;
        }
        while(!pq.empty()){
            int n = pq.top();
            pq.pop();
            count++;
            temp -= n;
            if(temp <= 0){
                break;
            }
        }
        return count;
    }
};