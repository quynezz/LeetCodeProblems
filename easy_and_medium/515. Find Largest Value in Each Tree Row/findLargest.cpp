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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        if(!root){
            return v;
        }
        while(!q.empty()){
            int lv = q.size();
            int temp = INT_MIN;
            for(int i = 0; i < lv; i++){
                TreeNode* current = q.front();
                q.pop();
                temp = max(temp,current->val);
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            v.push_back(temp);
        }
        return v;
    }
};