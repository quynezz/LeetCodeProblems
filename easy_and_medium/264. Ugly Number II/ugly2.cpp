class Solution {
public:
   int nthUglyNumber(int n) { 
        priority_queue<long long ,vector<long long >, greater<long long >> q;
        unordered_set<long long > s; 
        vector<long long > v;
        long long  count = 0;
        q.push(1);
        s.insert(1);
        while(count < n){ 
            long long temp = q.top();
            q.pop();
            v.push_back(temp);
            count++;
            for(auto it : {2, 3, 5}){ 
                long long  num = temp * it;
                if(s.find(num) == s.end()){ 
                    q.push(num);
                    s.insert(num);
                }
            }
        }
        return v.back();
    }

    // another solution
};
