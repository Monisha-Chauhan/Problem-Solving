void path(TreeNode* root,vector<string>& ans,string s)
{
    if(root==NULL)return ;
    s=s+to_string(root->val);
    
    if(root->left==NULL && root->right==NULL)
    {
        
        ans.push_back(s);
        return;
    }
     s=s+"->";
     path(root->left,ans,s);
     path(root->right,ans,s);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s="";
        if(root==NULL)return ans;
        path(root,ans,s);
        return ans;
    }
