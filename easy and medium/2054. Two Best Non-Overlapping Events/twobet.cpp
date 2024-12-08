#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; 
        });

        int n = events.size();
        vector<int> maxValue(n, 0);
        maxValue[0] = events[0][2]; 
        for (int i = 1; i < n; i++) {
            maxValue[i] = max(maxValue[i - 1], events[i][2]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            int lo = 0, hi = i - 1, best = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (events[mid][1] < events[i][0]) {
                    best = mid; 
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if (best != -1) {
                result = max(result, events[i][2] + maxValue[best]);
            } else {
                result = max(result, events[i][2]); 
            }
        }

        return result;
    }
};