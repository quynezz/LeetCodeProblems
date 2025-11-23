class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) { 
        int carry = 0;
        int i = num.size() - 1;
        vector<int> ans;
        // also check if the first element is >= 10 by check carry > 0;
        while(i >= 0 || k > 0 || carry > 0){  
            int n = i >=0 ? num[i] : 0;
            int j = k % 10;
            int temp = n + j + carry; 
            ans.push_back(temp % 10);
            carry = temp / 10;
            
            i--; 
            k /= 10;
        }
        // 4,3,2,1;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};