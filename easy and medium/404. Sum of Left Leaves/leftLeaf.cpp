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
    int sumOfLeftLeaves(TreeNode* root) { 
        if((root->right == NULL && root->left == NULL ) || root == NULL  ) { 
            return 0;
        }      
        int temp = 0;
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()){ 
            TreeNode* current = q.front(); 
            q.pop(); 
            if(current->left != NULL){ 
                if(!current->left->left && !current->left->right) { 
                temp += current->left->val;
                } else { 
                q.push(current->left);
            }
            }
            if(current->right != NULL){ 
                q.push(current->right);
            }
        }
    return temp;
    }
};