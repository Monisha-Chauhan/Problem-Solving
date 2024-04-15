#include <bits/stdc++.h>
using namespace std;
struct TrieNode {
    TrieNode* children[26];
     bool flag;
     
};
 struct TrieNode* getNode()
{
    struct TrieNode* node = new TrieNode;
    node->flag = false;
 
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
 
    return node;
}
 void insert(struct TrieNode* root, string key)
{
    struct TrieNode* node= root;
 
    for (int i= 0; i< key.length(); i++) {
        int index = (key[i]-'a');
        if (!node->children[index])
            node->children[index] = getNode();
 
        node= node->children[index];
    }
   node->flag= true;
}
 bool isLastNode(struct TrieNode* root)
{
    for (int i = 0; i < 26; i++)
        if (root->children[i])
            return 0;
    return 1;
}
 void suggestionsRec(struct TrieNode* root,string currPrefix)
{
   
    if (root->flag)
        cout << currPrefix << endl;
 
    for (int i = 0; i < 26; i++)
        if (root->children[i]) {
           
            char child = 'a' + i;
            suggestionsRec(root->children[i], currPrefix + child);
        }
}
int printAutoSuggestions(TrieNode* root, string query)
{
    struct TrieNode* node = root;
    for (char c : query) {
        int ind = c-'a';
        if (!node->children[ind])
            return 0;
       node= node->children[ind];
    }
   
    if (isLastNode(node)) {
        cout << query << endl;
        return -1;
    }
    suggestionsRec(node, query);
    return 1;
}
 
