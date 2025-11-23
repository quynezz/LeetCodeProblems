class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {  
        sort(items.begin(), items.end());
        vector<int> maxBeauty(items.size(), 0);
        maxBeauty[0] = items[0][1];  
        for (int i = 1; i < items.size(); i++) {
            maxBeauty[i] = max(maxBeauty[i - 1], items[i][1]);
        }
        
        vector<int> result;
        for (int query : queries) {
            int left = 0, right = items.size() - 1, index = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (items[mid][0] <= query) {
                    index = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (index != -1) {
                result.push_back(maxBeauty[index]);
            } else {
                result.push_back(0);  
            }
        }
        
        return result;
    }
};
