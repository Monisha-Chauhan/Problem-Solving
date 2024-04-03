#include<bits/stdc++.h>
bool isLeaf(TreeNode<int>* root)
{
    if(root==NULL)return false;
    if(root->left==NULL && root->right==NULL)return true;
    return false;
}
void addLeftBoundary(TreeNode<int>* root,vector<int>& res)
{
    TreeNode<int>* curr=root->left;
    while(curr)
    {
        if(!isLeaf(curr))res.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else curr=curr->right;
    }
}
void addRightBoundary(TreeNode<int>* root,vector<int>& res)
{
    TreeNode<int>* curr=root->right;
   stack<int> s;
  
    while(curr)
    {
        if(!isLeaf(curr))s.push(curr->data);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
    }
    while(s.empty()==false)
    {
        int a=s.top();
        s.pop();
        res.push_back(a);
    }

}
void addLeafNodes(TreeNode<int>* root,vector<int>& res)
{   if(root==NULL)return;
    if(isLeaf(root))
     { res.push_back(root->data);
     return ;}
     addLeafNodes(root->left,res);
     addLeafNodes(root->right,res);

}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> res;
    if(root==NULL)return res;
    if(!isLeaf(root))res.push_back(root->data);
    addLeftBoundary(root,res);
    addLeafNodes(root,res);
    addRightBoundary(root,res);
    return res;
}
