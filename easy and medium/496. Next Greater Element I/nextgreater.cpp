class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {  
//         // find the next great element "to the right" (iterate until find the greater value than current)); 
//         vector<int> ans;
//         unordered_map<int,int> m;
//         for(int i = 0; i < nums2.size(); i++){  
//             m[nums2[i]] = i;
//         }  
//         for(int i = 0; i < nums1.size(); i++){ 
//             if(m.count(nums1[i])){ 
//                 int index = m[nums1[i]];
//                 bool visited = false;
//                 for(int j = index + 1; j < nums2.size(); j++){ 
//                     if(nums2[j] > nums1[i]){  
//                         visited = true;
//                         ans.push_back(nums2[j]);
//                         break;
//                     }
//                 }
//                     if(!visited){ 
//                         ans.push_back(-1);
//                     }
//             }else{
//                 ans.push_back(-1);
//             }
//         }
//         return ans;
//     }
    // monotonic stack;
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {   
        stack<int> s; 
        vector<int> v; // ans 
        unordered_map<int,int> m;
        for(int i = nums2.size() - 1; i >= 0; i--){  
            int n = nums2[i];  
            while(!s.empty() && s.top() <= n){ 
                s.pop();
            }  
            m[n] = s.empty() ? -1 : s.top();  
            s.push(n);
        }
        for(auto it : nums1){ 
            v.push_back(m[it]);
        }
        return v;
    }
};