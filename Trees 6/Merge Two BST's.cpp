 void inorder(Node* root,vector<int>& v)
    {
        if(root==NULL)return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> v1,v2;
       inorder(root1,v1);
       inorder(root2,v2);
       v1.insert(v1.end(),v2.begin(),v2.end());
       sort(v1.begin(),v1.end());
       return v1;
    }
