 TreeNode* invertTree(TreeNode* root) {
       if(root==NULL) return NULL;
       invertTree(root->left);
       invertTree(root->right);
       TreeNode* le=root->left;
       root->left=root->right;
       root->right=le;
      
       return root;
    }
