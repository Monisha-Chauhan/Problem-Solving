vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(q.empty()==false)
    {
        int n=q.size();
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            
            BinaryTreeNode<int>* curr=q.front();
           q.pop();
           v.push_back(curr->data);
           if(curr->left!=NULL)
            q.push(curr->left);
             if(curr->right!=NULL)
            q.push(curr->right);

        }
        ans.push_back(v[0]);
    }
    return ans;
}
