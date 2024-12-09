class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> v1;
        for (auto& it : nums2) {
            nums1.push_back({it[0], it[1]});
        }
        sort(nums1.begin(), nums1.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        int i = 0;
        while (i < nums1.size()) {
            if (i + 1 < nums1.size() && nums1[i][0] == nums1[i + 1][0]) {
                nums1[i][1] += nums1[i + 1][1];
                nums1.erase(nums1.begin() + i + 1);
            } else {
                v1.push_back({nums1[i][0], nums1[i][1]});
                i++; 
            }
        }

        return v1;
    }
};
