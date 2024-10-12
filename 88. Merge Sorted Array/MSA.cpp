class Solution {
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
    vector<int> v;  
    for(auto it : nums1){ 
        v.push_back(it);
    }
    nums1.resize(m + n);  
    
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (v[i] <= nums2[j]) {
            nums1[k++] = v[i++];
        } else {
            nums1[k++] = nums2[j++];
        }
    }
    while (i < m) {
        nums1[k++] = v[i++];
    }
    while (j < n) {
        nums1[k++] = nums2[j++];
    }
}
};