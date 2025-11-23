class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) { 
        unordered_set<int> s;
        int count = 0; 
        int sum = 0; 
        for(auto it : banned){ 
            s.insert(it);
        }
        for(int i = 1; i <= n; i++){ 
            (s.find(i) == s.end()) && ((sum + i) <= maxSum) ? sum += i, count++ : sum += 0;
        }
        return count;
    }
};


