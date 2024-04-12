class Node
{
    public:
     bool flag;
     Node* child[26];
     int index;
     int len;
     Node()
     {  flag=false;
        index=INT_MAX;
        len=INT_MAX;
        for(auto &i:child)
          i=NULL;
     }
};
class Trie{
    private:
     Node* root;
     public:
      Trie()
      {
        root=new Node();
      }
      void insert(string & s,int ind)
      {
        Node* node=root;
        for(auto i:s)
        {
            if(node->child[i-'a']==NULL)
              node->child[i-'a']=new Node();
            if(s.size()<node->child[i-'a']->len)
            {
                node->child[i-'a']->len=s.size();
                node->child[i-'a']->index=ind;
            }
            node=node->child[i-'a'];
        }
        node->flag=true;

      }
      int search(string& word)
      {
        Node* node=root;
        for(auto i:word)
        {
            if(node->child[i-'a']==NULL)return node->index;
            node=node->child[i-'a'];
        }
        return node->index;
      }
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
       Trie* trie=new Trie();
       int mn=INT_MAX;
       int ind=-1;
       for(int i=0;i<wordsContainer.size();i++)
       {
        reverse(wordsContainer[i].begin(),wordsContainer[i].end());
        if(wordsContainer[i].length()<mn)
        {
            mn=wordsContainer[i].length();
            ind=i;
        }
        trie->insert(wordsContainer[i],i);
       } 
       vector<int> ans(wordsQuery.size(),-1);
       for(int i=0;i<wordsQuery.size();i++)
       {
        reverse(wordsQuery[i].begin(),wordsQuery[i].end());
        int t=trie->search(wordsQuery[i]);
       
        if(t==INT_MAX)
          ans[i]=ind;
        else
          ans[i]=t;
       }
       return ans;
    }
};
