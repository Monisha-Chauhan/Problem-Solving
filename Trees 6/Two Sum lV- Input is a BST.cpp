bool tar(TreeNode* root,int k,unordered_set<int>& s)
{
    if(root==NULL)return false;
    if(s.find(k-root->val)!=s.end())return true;
    s.insert(root->val);
    return tar(root->left,k,s) || tar(root->right,k,s);
}
    bool findTarget(TreeNode* root, int k) {
      unordered_set<int> s;
      return tar(root,k,s);  
    }
