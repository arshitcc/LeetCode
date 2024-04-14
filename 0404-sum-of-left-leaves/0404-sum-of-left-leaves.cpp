class Solution {
public:
    
    int sum ;
    
    void summ(TreeNode* root, bool fromLeft){
        if(!root) return;
        if(!root->left and !root->right and fromLeft==true) sum += root->val;
        summ(root->left,true);
        summ(root->right,false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        summ(root,false);
        return sum;
    }
};