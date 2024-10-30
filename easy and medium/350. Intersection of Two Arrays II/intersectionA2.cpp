class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {  
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        vector<int> v; 
        for(auto it : nums1){  
            m1[it]++;
        }  
        for(auto it : nums2){  
            m2[it]++;
        }
        for(auto it : nums1){ 
            if(m1.count(it) && m2.count(it)){  
                int i = min(m1[it],m2[it]);
                while(i != 0){ 
                v.push_back(it);
                i--;
                }
                m1[it] = 0;
                m2[it] = 0;
            }
        }
     
        return v;
        }
    
};