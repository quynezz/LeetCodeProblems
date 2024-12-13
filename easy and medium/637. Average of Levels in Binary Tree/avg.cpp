/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) { 
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q; 
        q.push({root,0});
        while(!q.empty()){
            auto [node,lv] = q.front();
            q.pop();
            if(ans.size() <= lv){
                ans.push_back({});
            }
            ans[lv].push_back(node->val);
            if(node->left){
                q.push({node->left,lv + 1});
            }
            if(node->right){
                q.push({node->right,lv + 1});
            }
        }
        vector<double> temp;
        for(auto it : ans){
            double n = 0;
            double count = 0;
            for(auto ti : it){
                n += ti;
                count++;
            }
            n /= (count * 1.0);
            temp.push_back(n);
        }
        return temp;
    }
};