 Node* f_node(Node* root, int key){
        if(root==NULL)return NULL;
        if(root->data==key)return root;
        Node* left=f_node(root->left,key);
        if(left!=NULL)
          return left;
       
        Node* right=f_node(root->right,key);
        if(right!=NULL)
          return right;
   
        return NULL;
    }
 Node* lowestCommonAncestor(Node* root, Node* p,Node* q) {
        if(root==NULL)
         return NULL;
         if(root->data==p->data || root->data==q->data)
            return root;
        Node* lca1=lowestCommonAncestor(root->left,p,q);
        Node* lca2=lowestCommonAncestor(root->right,p,q);
         if(lca1!=NULL && lca2!=NULL)
           return root;
         else if(lca1!=NULL)
            return lca1;
        else
            return lca2;
        
    }
     int min_steps(Node* root,int key){
        if(root==NULL)return 1e9;
        if(root->data==key)return 0;
        int left=min_steps(root->left,key);
        if(left!=1e9)return 1+left;
        int right=min_steps(root->right,key);
        if(right!=1e9)return 1+right;
        return 1e9;
        
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
         Node* Na=f_node(root,a);
        Node* Nb=f_node(root,b);
      Node* lca=lowestCommonAncestor(root,Na,Nb);
        int s1=min_steps(lca,a);
        int s2=min_steps(lca,b);
        return s1+s2;
    }
