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
void dfs(TreeNode* root, vector<int> &v){ 
    if(!root){ 
        return;
    } 
    v.push_back(root->val);
    dfs(root->left,v);
    dfs(root->right,v);
}
public:
    vector<int> findMode(TreeNode* root) { 
        vector<int> temp;
        vector<int> v;
        unordered_map<int,int> m ;  
        dfs(root,temp);  
        for(auto it : temp){ 
            m[it]++;
        }
        int ans =0;
        for(auto[val,fre] : m){ 
            if(fre > ans){ 
                ans = fre;
            }
        }
        for(auto it : temp){ 
            if(m[it] == ans){  
                v.push_back(it);
                m[it]--;
            }
        }
        return v;
    }
};