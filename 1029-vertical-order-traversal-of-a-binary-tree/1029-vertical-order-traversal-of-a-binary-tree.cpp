/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int levels(TreeNode* root){
        if(!root) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // Optimal Solution : 
        if(!root) return {{}};
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>> m;

        while(q.size()){
            auto [temp, p] = q.front(); q.pop();
            auto [y,x] = p;
            m[y][x].insert(temp->val);
            if(temp->left) q.push({temp->left,{y-1, x+1}});
            if(temp->right) q.push({temp->right,{y+1, x+1}});
        }

        vector<vector<int>> ans;
        for(auto [a,nodes] : m){
            vector<int> temp;
            for(auto [x,y] : nodes){
                temp.insert(temp.end(),y.begin(),y.end());
            }
            ans.push_back(temp);
        }
        return ans;

        // My Approach : problem : Not able to sort overlap_nodes as required :
        // if(!root) return {{}};
        // queue<pair<TreeNode*, pair<int,int>>> q;
        // q.push({root,{0,0}});
        // int n = levels(root);
        // vector<vector<int>> v(2*n -1);

        // while(q.size()){
        //     auto [temp, p] = q.front(); q.pop();
        //     auto [x,y] = p;
        //     v[y+n-1].push_back(temp->val);
        //     if(temp->left) q.push({temp->left,{x+1, y-1}});
        //     if(temp->right) q.push({temp->right,{x+1, y+1}});
        // }
        
        // vector<vector<int>> ans;
        // for(auto i : v) if(i.size() > 0) ans.push_back(i);
    
        // return ans;
    }
};