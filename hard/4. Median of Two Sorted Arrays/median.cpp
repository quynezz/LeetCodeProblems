class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
        // nums1.resize(nums1.size() + nums2.size());;
        for(auto it : nums2){ 
            nums1.push_back(it);
        } 
        if(nums1.size() == 1){
             return nums1[0];
        }
        float temp = 0;
        sort(nums1.begin(),nums1.end());
        int mid = (0 + nums1.size() - 1 ) / 2; 
        if(nums1.size() % 2 != 0){ 
            temp = nums1[mid];
        } else {
         temp = ((float(nums1[mid]) + float(nums1[mid + 1])) / 2 ) ;
        }
        return temp;
    }
};