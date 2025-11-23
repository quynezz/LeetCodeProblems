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
private: 
void dfs(vector<int> &v, TreeNode* root){
    if(!root){
        return;
    }
    dfs(v,root->left);
    v.push_back(root->val);
    dfs(v,root->right);
}
public:
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> v;
        dfs(v,root);
        sort(v.begin(),v.end(),[&](int a, int b){
            return a > b;
        });
        unordered_set<int> s(v.begin(),v.end());
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        bool find = false;
        for(auto it : s){
            firstMin = min(it,firstMin);
        }
        for(auto it : s){
            if(it > firstMin && find == false){
                secondMin = it;
                find = true;
            }
        }
        return s.size() == 1 ? -1 : secondMin;
    }
};