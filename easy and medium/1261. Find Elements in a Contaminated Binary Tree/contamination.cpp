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
class FindElements {
    unordered_map<int,int> m;
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        bfs(root);
    }
    
    bool find(int target) {
        return m.count(target);
    }
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root); 
        while(!q.empty()){
            TreeNode* cur = q.front();
            int x = cur->val;
            m[x]++;
            q.pop();
            if(cur->left) {
                cur->left->val = 2 * x + 1;
                q.push(cur->left);
                m[cur->left->val]++;
            }
            if(cur->right)  {
                cur->right->val = 2 * x + 2;
                q.push(cur->right);
                m[cur->right->val]++;
            } 
        }
    }
    
};
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */