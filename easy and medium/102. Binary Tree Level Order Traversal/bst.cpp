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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<pair<TreeNode*,int>> q;
        if(root == NULL){
            return v;
        }
        q.push({root,0});
        while(!q.empty()){
            auto [node,lv] = q.front();
            q.pop();
            if(v.size() <= lv) {
                v.push_back({});
            }
            v[lv].push_back(node->val);
            if(node->left) q.push({node->left,lv + 1});
            if(node->right) q.push({node->right,lv + 1});
        }
        return v;
    }
};