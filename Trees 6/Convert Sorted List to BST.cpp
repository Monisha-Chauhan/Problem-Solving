TreeNode* BinaryST(vector<int>& v)
{
    if(v.size()==0)return NULL;
    if(v.size()==1)return new TreeNode(v[0]);
    int mid=v.size()/2;
    TreeNode* root=new TreeNode(v[mid]);
    vector<int> lTree(v.begin(),v.begin()+mid);
    vector<int> rTree(v.begin()+mid+1,v.end());
    root->left=BinaryST(lTree);
    root->right=BinaryST(rTree);
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
       if(head==NULL)return NULL;
       vector<int> v;
       ListNode* temp=head;
       while(temp)
       {
        v.push_back(temp->val);
        temp=temp->next;
       }
       if(v.size()==1)return new TreeNode(v[0]);
       return BinaryST(v);

    }
