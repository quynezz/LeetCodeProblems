class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {   
        unordered_set<int> m1;
        unordered_set<int> m2;
        bool visited[10001];
        vector<int> v;
        for(auto it : nums1){ 
            m1.insert(it);
        }
        for(auto it : nums2){ 
            m2.insert(it);
        }
        for(auto it : nums1){ 
            if(m1.count(it) && m2.count(it) && !visited[it]){   
                v.push_back(it);
                visited[it] = true;
            }
        }
        return v;   
    }
};