int rangeSumBST(TreeNode* root, int low, int high) {
        if(root ==NULL)return 0;
        int curr=0;
        if(root->val>=low && root->val<=high)
         curr=root->val;
         int left=rangeSumBST(root->left,low,high);
         int right=rangeSumBST(root->right,low,high);
         return curr+left+right;
    }
