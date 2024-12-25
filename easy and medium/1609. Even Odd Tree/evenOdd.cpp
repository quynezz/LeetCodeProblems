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
    bool isEvenOddTree(TreeNode* root) {
        if(!root){
            return false;
        }else if(!root->left && !root->right){
            if(root->val % 2 == 0){
                return false;
            }else{
                return true;
            }
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int lv = q.size(); 
            int temp = -1;
            if(level == 0){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->val % 2 == 0){
                    return false;
                }
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                // even
            }else if(level % 2 == 0){
                for(int i = 0; i < lv; i++){
                    TreeNode* cur = q.front();
                    q.pop();
                    if(temp == -1){
                        temp = cur->val;
                    }else if(temp != -1){
                        if(cur->val <= temp || cur->val % 2 == 0){
                            return false;
                        }else{
                            temp = cur->val;
                        }
                    }
                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }
                if(temp % 2 == 0){
                    return false;
                }
            } else if(level % 2 != 0){
                for(int i = 0; i < lv; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(temp == -1){
                    temp = cur->val;
                }else if(temp != -1){
                    if(cur->val >= temp || cur->val % 2 != 0){
                        return false;
                    }else{
                        temp = cur->val;
                    }
                }
                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
            }
            if(temp % 2 != 0){
                    return false;
                }
        }
        level++;
        }
        return true;
    }
};