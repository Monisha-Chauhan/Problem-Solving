 void inorder(TreeNode* root, vector<TreeNode*> &v) {
        if (root==NULL) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        v.push_back(new TreeNode(-1e9));
        inorder(root, v);
        v.push_back(new TreeNode(1e9));
        TreeNode* a = NULL, *b = NULL;
       
        for (int i=1; i<v.size()-1; i++) {
            if (v[i]->val > v[i+1]->val) {
                if (a==NULL) {
                    a = v[i];
                    b = v[i+1];
                }
                else
                 b = v[i+1];
            }
        }
        swap(a->val, b->val); 
    }
