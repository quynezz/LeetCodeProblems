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
    // Recursive
    // private: 
// bool Symetric(TreeNode* left, TreeNode* right){ 
//     if(!left && !right ) { 
//         return true;
//     }
//     if(!left || !right || left->val != right->val){ 
//         return false;
//     }
//     return Symetric(left->right,right->left) && Symetric(left->left,right->right);
// }
// public:
//     bool isSymmetric(TreeNode* root) { 
//         if(root == NULL){
//              return true;
//         }
//         return Symetric(root->left,root->right);
    
    // }
public:
// BFS
    bool isSymmetric(TreeNode* root) { 
        if(root == NULL){ 
            return true;
        }
        queue<TreeNode*> q; 
            q.push(root->left);
            q.push(root->right); 
        while(!q.empty()){  
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            if(!left && !right){  
                continue;
            }
            if(!left || !right || left->val != right->val){ 
                return false;
            }
         
                q.push(left->left);
                q.push(right->right);
                q.push(left->right);
                q.push(right->left);
            }
        
        return true;
    
    }
};