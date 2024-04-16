struct Node
{
    public:
     int count;
     int sum;
     Node* children[2];
     Node()
     {
        children[0]=NULL;
        children[1]=NULL;
         count=0;
         sum=0;
     }
};
class Solution {
public:

void insert(Node* root,int num,int ind)
{
    Node* node=root;
    for(int i=31;i>=0;i--)
    {
        int bit=1&(num>>i);
        if(root->children[bit]==NULL)
          root->children[bit]=new Node();
    root=root->children[bit];
    }
    root->sum+=ind;
    root->count++;
}
int indexPair(Node* root,int num,int ind)
{
    for(int i=31;i>=0;i--)
    {int bit=1&(num>>i);
        if(root->children[bit]==NULL)
          return 0;
      root=root->children[bit];
    }
    return (((root->count)*ind)-(root->sum));
}
    int countTriplets(vector<int>& arr) {
      long long ans=0;
      int xorval=0;
      Node* root=new Node();
      for(int i=0;i<arr.size();i++)
      {
        insert(root,xorval,i);
        xorval^=arr[i];
        ans+=indexPair(root,xorval,i);
      }  
      return ans;
    }
};
