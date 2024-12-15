class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) { 
        double sum = 0;
        auto profit = [&](int pass, int total) { 
            return ((pass + 1) * 1.0 / (total + 1) * 1.0) - (pass * 1.0 / total);
        };
        priority_queue<pair<double, pair<int, int>>> pq;
        for (int i = 0; i < classes.size(); i++) { 
            sum += (classes[i][0] * 1.0 / classes[i][1]);
            pq.push({profit(classes[i][0], classes[i][1]), {classes[i][0], classes[i][1]}});
        }
        while (extraStudents--) {
            auto [pro, cls] = pq.top();
            auto [pass, total] = cls;
            pq.pop();
            sum += pro;
            pq.push({profit(pass + 1, total + 1), {pass + 1, total + 1}});
        }
        return sum / classes.size();
    }
};
