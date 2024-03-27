int res=0;
 int diameterOfBinaryTree(TreeNode* root) {
        maxHeight(root);
        return res;
    }
    int maxHeight(TreeNode* root) {
        if(root==NULL)
         return 0;
        int lh=maxHeight(root->left);
        int rh=maxHeight(root->right);
       res=max(res,lh+rh);

        return max(lh,rh)+1;
    }
