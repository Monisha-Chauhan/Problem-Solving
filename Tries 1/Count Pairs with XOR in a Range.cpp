class Node{
 public:
     Node* child[2];
     int count;
     Node()
     {
        child[0]=NULL;
        child[1]=NULL;
        count=0;
     }
};
class Trie{
    Node* root;
 public:
  Trie()
  {
    root=new Node;

  }
  void insert(int n)
  {
    Node* node=root;
    for(int i=31;i>=0;i--)
    {
        int bit=(n>>i)&1;
        if(node->child[bit]==NULL)
          node->child[bit]=new Node();
        node=node->child[bit];
        node->count++;
    }
  }
  int countXOR(int n,int high)
  {
    Node* node=root;
    int c=0;
    for(int i=31;i>=0 && node!=NULL;i--)
    {
        int bNum=(n>>i)&1;
        int bHigh=(high>>i)&1;
        if(bHigh==1)
        {
            if(node->child[bNum]!=NULL)
              c+=node->child[bNum]->count;
            node=node->child[1-bNum];
        }
        else
        node=node->child[bNum];
    }
    return c;
  }

};
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
       Trie trie;
       int c=0;
       for(int i:nums)
       {
        c+=trie.countXOR(i,high+1)-trie.countXOR(i,low);
        trie.insert(i);
       } 
       return c;

    }
};
