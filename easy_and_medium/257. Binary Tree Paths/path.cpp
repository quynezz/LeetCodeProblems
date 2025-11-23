class Solution { 
private:  
    void path(TreeNode* root, vector<int> &v, vector<vector<int>> &ans) {   
        if (root->left == NULL && root->right == NULL) {    
            v.push_back(root->val); 
            ans.push_back(v);
            return;
        }   
        v.push_back(root->val);
        if(root->left != NULL){ 
            path(root->left,v,ans);
            v.pop_back();
        }
        if(root->right != NULL){ 
            path(root->right,v,ans);
            v.pop_back();
        }

    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> s;
        vector<int> v;             
        vector<vector<int>> ans; 
        vector<string> res; 
        path(root,v,ans);
        for(auto it : ans){ 
        string temp = "";
            for(int i = 0; i < it.size(); i++){   
                temp += to_string(it[i]);
                temp += "->";
            }
            temp.pop_back();
            temp.pop_back();
            res.push_back(temp);
        }
        return res;
    }
};
