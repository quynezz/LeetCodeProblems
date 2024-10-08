#include<bits/stdc++.h> 

using namespace std; 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            
            int ind=0;
            for(auto it:st){
                nums[ind++]=it;

            }

        } 
        return st.size();
    }
};