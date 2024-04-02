struct NodeInfo {
    bool isBST;
    int minVal;
    int maxVal;
    int size;
    NodeInfo() {
        isBST = true;
        minVal = INT_MAX;
        maxVal = INT_MIN;
        size = 0;
    }
};

NodeInfo solve(Node* root) {
    if (root==NULL) return NodeInfo();
    NodeInfo left = solve(root->left);
    NodeInfo right = solve(root->right);
    NodeInfo result;
    if (left.isBST && right.isBST && left.maxVal < root->data && root->data < right.minVal) {
         result.isBST = true;
        result.size = 1 + left.size + right.size;
        result.minVal = min(root->data, left.minVal);
        result.maxVal = max(root->data, right.maxVal);
        
     } 
    else {
        result.isBST = false;
        result.minVal = INT_MIN;
        result.maxVal = INT_MAX;
        result.size = max(left.size, right.size);
        
    }
    return result;
}

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
       return solve(root).size;

    	
    }
};
