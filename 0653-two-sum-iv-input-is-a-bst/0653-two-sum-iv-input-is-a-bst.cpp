class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
       vector<int> ans;
        stack<TreeNode*> st;
        while(root or st.size()){
            while(root){
                st.push(root);
                root = root->left;
            }
            TreeNode* temp = st.top(); st.pop();
            ans.push_back(temp->val);
            if(temp->right) root = temp->right;
        }

        for(int i=0; i<ans.size(); i++){
            for(int j=i+1; j<ans.size(); j++){
                if(ans[i]+ans[j] == k) return true;
            }
        }
        return false; 
    }
};