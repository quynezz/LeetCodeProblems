#include<bits/stdc++.h>

using namespace std;

 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
private:
    bool valid(TreeNode* root,long int min, long max) {
        if(root == NULL) return true;
        if(root->val > min && root->val < max && valid(root->left,min,root->val)&& valid(root->right,root->val,max)){
         return true; 
        } else {
            return false;
        }
    }
    public: 
    bool  isValidBST(TreeNode *root){ 
        return valid(root,LONG_MIN,LONG_MAX);
    }
};