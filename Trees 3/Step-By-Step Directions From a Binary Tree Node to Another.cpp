TreeNode* find_node(TreeNode* root, int key){
        if(root==NULL)return NULL;
        if(root->val==key)return root;
        TreeNode* left=find_node(root->left,key);
        if(left!=NULL)
          return left;
       
        TreeNode* right=find_node(root->right,key);
        if(right!=NULL)
          return right;
   
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
         return NULL;
         if(root->val==p->val || root->val==q->val)
            return root;
        TreeNode* lca1=lowestCommonAncestor(root->left,p,q);
        TreeNode* lca2=lowestCommonAncestor(root->right,p,q);
         if(lca1!=NULL && lca2!=NULL)
           return root;
         else if(lca1!=NULL)
            return lca1;
        else
            return lca2;
        
    }
    bool getPath(TreeNode* root, int key,string& path){
        if(root==NULL)return false;
        if(root->val==key)return true;
        path+="L";
        bool left=getPath(root->left,key,path);
        if(left!=NULL)return true;
        path.pop_back();
        path+="R";
        bool right=getPath(root->right,key,path);
        if(right!=NULL)return true;
        path.pop_back();
        return false;
    }
 string getDirections(TreeNode* root, int startValue, int destValue) {
          TreeNode* p=find_node(root,startValue);
        TreeNode* q=find_node(root,destValue);
        TreeNode* lca=lowestCommonAncestor(root,p,q);
        string p_path="";
        string q_path="";
        getPath(lca,p->val,p_path);
        getPath(lca,q->val,q_path);
        string ans="";
        for(int i=0;i<p_path.size();i++){
            ans+="U";
        }
        ans+=q_path;
        return ans;
    }
};
