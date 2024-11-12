class Solution {
private: 
    vector<int> findDepth(TreeNode* root, int ans, vector<int>& v) {  
        int depth = 0; 
        queue<TreeNode*> q;
        q.push(root);
        // method, check all the node at 1 level and then pop them all, push all nodes another level in.
        while (!q.empty()) {
            int levelSize = q.size();
            depth++; 
            while (levelSize > 0) {  
                TreeNode* current = q.front();
                q.pop();
                levelSize--;
                if (current->left != NULL) { 
                    if (current->left->val == ans) { 
                        v.push_back(depth);      
                        v.push_back(current->val);
                        break;
                    }
                    q.push(current->left);
                }
                if (current->right != NULL) { 
                    if (current->right->val == ans) { 
                        v.push_back(depth);     
                        v.push_back(current->val); 
                        break;

                    }
                    q.push(current->right);
                }
            }
        }
        return v; 
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {  
        vector<int> v1, v2;
        // v1 for x, v2 for y 
        findDepth(root, x, v1);
        findDepth(root, y, v2);  
        if (v1.empty() || v2.empty()) return false;
        if (v1[0] == v2[0] && v1[1] != v2[1]) { 
            return true;
        }
        return false;
    }
};
