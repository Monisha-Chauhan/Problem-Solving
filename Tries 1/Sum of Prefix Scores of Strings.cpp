class Solution {
public:
 struct Node
 {
    Node* child[26];
    int count;
    Node()
    {
        count=0;
        for(int i=0;i<26;i++)
          child[i]=NULL;
    }
 };
 Node* root;
 void insert(string& word)
 {
    Node* node=root;
    for(int i=0;i<word.size();i++)
    {
        if(node->child[word[i]-'a'])
          node=node->child[word[i]-'a'];
        else
        {
            node->child[word[i]-'a']=new Node;
            node=node->child[word[i]-'a'];
        }
        node->count++;
    }
 }
 int scores(string& word)
 {
    Node* node=root;
    int s=0;
    for(int i=0;i<word.size();i++)
    {
        if(node->child[word[i]-'a'])
         node=node->child[word[i]-'a'];
        s+=node->count;
    }
    return s;
 }
    vector<int> sumPrefixScores(vector<string>& words) {
      root=new Node();
      for(auto i:words)
        insert(i);
    vector<int> score;
    for(auto i:words)
    {
        int c=scores(i);
          score.push_back(c);
    }  
    return score;
    }
};
