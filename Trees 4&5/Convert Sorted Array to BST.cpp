TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return NULL;
        if(nums.size()==1) return new TreeNode(nums[0]);
        int mid=nums.size()/2;
        TreeNode *root=new TreeNode(nums[mid]);
        vector<int> lefts(nums.begin(),nums.begin()+mid);
        vector<int> rights(nums.begin()+mid+1,nums.end());
        root->left=sortedArrayToBST(lefts);
        root->right=sortedArrayToBST(rights);
        return root;
    }
