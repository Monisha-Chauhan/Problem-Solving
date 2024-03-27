 bool hasPathSum(TreeNode* root, int targetSum) {
       if(root==NULL)return false; 
   
    if(!root->left && !root->right)
       return targetSum==root->val;
      
       bool left=hasPathSum(root->left,targetSum - root->val);
       bool right=hasPathSum(root->right,targetSum - root->val);
       return left||right;
    }
