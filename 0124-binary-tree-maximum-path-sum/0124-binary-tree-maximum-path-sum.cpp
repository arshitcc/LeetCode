class Solution {
public:
    int pathSum(TreeNode* root, int &maxSum){
        if(!root) return 0;
        int lst = max(0,pathSum(root->left, maxSum));
        int rst = max(0,pathSum(root->right, maxSum));
        int sum = root->val + lst + rst;
        maxSum = max(maxSum, sum);
        return root->val + max(lst,rst);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        pathSum(root,maxSum);
        return maxSum;
    }
};