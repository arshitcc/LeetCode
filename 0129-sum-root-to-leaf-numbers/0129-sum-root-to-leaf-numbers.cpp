class Solution {
public:
    
    int sum;
    
    void summ(TreeNode* root, int num){
            if(!root) return;
            if(!root->left and !root->right){
                num += root->val;
                sum += num;
                return;
            }
            num += root->val;
            num *=10;
            summ(root->left,num);
            summ(root->right,num);
    }
    
    int sumNumbers(TreeNode* root) {
        sum = 0;
        summ(root,0);
        return sum;
    }
};