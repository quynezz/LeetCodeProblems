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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st; 
        int index = 0;
        while(index < traversal.size()){
            int depth = 0;
            while(index < traversal.size() && traversal[index] == '-'){
                depth++;
                index++;
            }
            while(st.size() > depth){
                st.pop();
            }       
            int value = 0;
            while(index < traversal.size() && isdigit(traversal[index])){
                value = value * 10 + (traversal[index] - '0');
                index++;
            }
            TreeNode* root = new TreeNode(value);
         if(!st.empty()){
            if(st.top()->left == NULL){
                st.top()->left = root;
            }else{
                st.top()->right = root;
            }
        }
            st.push(root);
        }
        while(st.size() > 1) st.pop();
        return st.top();
    }
};