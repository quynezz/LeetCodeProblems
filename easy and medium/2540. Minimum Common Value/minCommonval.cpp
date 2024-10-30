class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;  
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){ 
            if(nums1[i] < nums2[j]){ 
                i++;
            } else if(nums1[i] > nums2[j]){ 
                j++;
            }else { 
                ans = nums1[i];
                return ans;
            }
        }

        return -1;
    }
};