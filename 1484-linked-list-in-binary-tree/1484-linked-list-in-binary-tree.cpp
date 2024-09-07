class Solution {
public:

    bool isMatch(ListNode* head, TreeNode* root){
        if(!head) return true;
        if(!root) return false;

        if(head->val == root->val) {
            bool left = isMatch(head->next, root->left);
            bool right = isMatch(head->next, root->right);
            if(left or right) return true;
            else return false;
        }

        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {

        if(!head) return true;
        if(!root) return false;
       
        bool x = isMatch(head, root);
        bool left = isSubPath(head, root->left);
        bool right = isSubPath(head, root->right);
        if(x or left or right) return true;
        return false;
    }
};