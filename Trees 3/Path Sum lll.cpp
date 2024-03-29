int ans=0;
void helper(TreeNode* root,long long int targetSum)
{
    if(root ==NULL)return;
    if(targetSum==root->val)ans++;
    helper(root->left,targetSum-root->val);
    helper(root->right,targetSum-root->val);
} 
    int pathSum(TreeNode* root, int targetSum) {
    if(root)

      { helper(root,targetSum);
       pathSum(root->left,targetSum );
       pathSum(root->right,targetSum );}
      return ans; 
    }
