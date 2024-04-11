class Node{
    public:
     Node* child[26];
     bool isWord=false;
     Node()
     {
        for(auto &i:child)
          i=NULL;
     }
    
};
class Trie {
    Node* root;
public:
    Trie() {
        root=new Node;
    }
    
    void insert(string word) {
      int n=word.size();
      Node* node=root;
      for(int i=0;i<n;i++)
      {
        if(node->child[word[i]-'a']==NULL)
           node->child[word[i]-'a']=new Node();
      
      node=node->child[word[i]-'a'];
      }
      node->isWord=true;
    }
    
    bool search(string word) {
     int n=word.size();
     Node* node=root;
     for(int i=0;i<n;i++)
     {
        if(node->child[word[i]-'a']==NULL)
          return false;
     
     node=node->child[word[i]-'a']; 
    }
    return node->isWord;
    }
    
    bool startsWith(string prefix) {
       int n = prefix.size();
		Node* node = root;
		for (int i = 0; i < n; i++) {
			if (node->child[prefix[i] - 'a'] == NULL) {
				return false;
			}
			node = node->child[prefix[i] - 'a'];
		}
		return true; 
    }
};
