class Solution {
public:
    int getDepth(TreeNode* root) {
        if (!root)return 0;
        return max(getDepth(root->right),getDepth(root->left))+1;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return NULL;
    
        int rd = getDepth(root->right);
        int ld = getDepth(root->left);
        
        if (rd == ld) return root; 
        if(rd > ld)  return lcaDeepestLeaves(root->right);
        else return lcaDeepestLeaves(root->left);
    }
};