struct NodeInfo {
    bool isBST;
    int minVal;
    int maxVal;
      int sum;
    NodeInfo() {
        isBST = true;
        minVal = INT_MAX;
        maxVal = INT_MIN;
        sum = 0;

    }
};

NodeInfo solve(TreeNode* root,int& ans) {
    if (root==NULL) return NodeInfo();
    NodeInfo left = solve(root->left,ans);
    NodeInfo right = solve(root->right,ans);
    NodeInfo result;
    if (left.isBST && right.isBST && left.maxVal < root->val && root->val < right.minVal) {
         result.isBST = true;
        result.sum = left.sum+right.sum+root->val;
        result.minVal = min(root->val, left.minVal);
        result.maxVal = max(root->val, right.maxVal);
        
     } 
    else {
        result.isBST = false;
        result.minVal = INT_MIN;
        result.maxVal = INT_MAX;
        result.sum = max(left.sum, right.sum);
        
    }
    if(result.isBST)
      ans=max(ans,result.sum);
    return result;
}

class Solution {
public:
    int maxSumBST(TreeNode* root) {
      int sum=0;
      NodeInfo node=solve(root,sum);
      return sum; 
    }
};
