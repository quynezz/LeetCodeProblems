class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        long long sum = 0; 
        for(auto it : gifts){
            sum += it;
        }
        while(k != 0){ 
            int temp = pq.top();
            sum -=  temp - floor(sqrt(temp));
            pq.pop();
            pq.push(floor(sqrt(temp)));
            k--;
        }
        return sum;
    }
};