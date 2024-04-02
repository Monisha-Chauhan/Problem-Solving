 void inorder(Node* root,vector<int>& v)
    {
        if(root==NULL)return;
        inorder(root->left,v);
        v.push_back(root->data);
       
        inorder(root->right,v);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     vector<int> v1,v2;
     inorder(root1,v1);
     inorder(root2,v2);
     vector<int> ans;
     set<int> s;
     for(auto i:v1)
       s.insert(i);
     
      
     for(int i:v2)
     {
        if(s.find(i)!=s.end())
         ans.push_back(i);
     }
     return ans;
    }
