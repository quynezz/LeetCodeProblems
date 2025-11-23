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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> v;
            for(int i = 0; i < n; i++){
                TreeNode* current = q.front();
                q.pop();
                v.push_back(current);
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            if(level % 2 != 0){
                int l = 0, r = v.size() - 1; 
                while(l < r){
                    swap(v[l]->val,v[r]->val);
                    l++;
                    r--;
                }
            }
            level++;
        }
        return root;
    }
};