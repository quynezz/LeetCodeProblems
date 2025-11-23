class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> res;
        for (int num : nums) {
            freq[num]++;
        }
        vector<pair<int, int>> temp(freq.begin(), freq.end());
        sort(temp.begin(), temp.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second > b.second;
        });
        for (int i = 0; i < k && i < temp.size(); i++) {
            res.push_back(temp[i].first);
        }

        return res;
    }
};
