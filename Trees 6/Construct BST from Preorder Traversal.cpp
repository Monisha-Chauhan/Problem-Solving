 int preIndex=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int n=preorder.size();
     TreeNode* root= ctree(preorder,inorder,0,n-1);  

      return root;
    }
    TreeNode* ctree(vector<int>& preorder,vector<int>& inorder,int is,int ie)
    {
        if(is>ie)
          return NULL;
        TreeNode* root=new TreeNode(preorder[preIndex++]);
        int inIndex;
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==root->val)
            {
                inIndex=i;
                break;
            }
        }
        root->left=ctree(preorder,inorder,is,inIndex-1);
        root->right=ctree(preorder,inorder,inIndex+1,ie);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        inorder=preorder;
        sort(inorder.begin(),inorder.end());
        return buildTree(preorder,inorder);
    }
