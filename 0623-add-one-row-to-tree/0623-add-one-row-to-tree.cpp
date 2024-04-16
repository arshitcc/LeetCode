class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
    
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;
        
        while(q.size()){
            
            if(lvl == depth-1){
                queue<TreeNode*> next;
                int x = q.size();
                for(int i=1; i<=x; i++){
                    TreeNode* temp = q.front(); q.pop(); q.push(temp);
                    if(temp->left) next.push(temp->left);
                    if(temp->right) next.push(temp->right);
                }
                
                while(q.size()){
                    TreeNode* curr = q.front(); q.pop();
                    TreeNode* nodeLeft = new TreeNode(val);
                    TreeNode* nodeRight = new TreeNode(val);
                    TreeNode* dep;
                    
                    if(curr->left == next.front()){
                        dep = next.front(); next.pop();
                        curr->left = nodeLeft;
                        nodeLeft->left = dep;
                    }
                    else if(curr->left != next.front()){
                        curr->left = nodeLeft;
                    }
                    
                    if(curr->right == next.front()){
                        dep = next.front(); next.pop();
                        curr->right = nodeRight;
                        nodeRight->right = dep;
                    }
                    else if(curr->right != next.front()){
                        curr->right = nodeRight;
                    }

                }
                return root;
            }
            
            int n = q.size();
            
            for(int i=1; i<=n; i++){
                TreeNode* temp = q.front(); q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            lvl++;
            
        }
        return root;
    }
};