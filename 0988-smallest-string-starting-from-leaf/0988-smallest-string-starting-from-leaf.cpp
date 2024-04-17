class Solution {
public:

    string ddfs(TreeNode* root, string x){
        if(!root) return "";
        if(!root->left and !root->right){
            x.push_back((char)(root->val+97));
            return x;
        }
        
        string s1 = ddfs(root->left,x);
        string s2 = ddfs(root->right,x);

        if(!s1.size()){
            s2.push_back((char)(root->val+97));
            return s2;
        }
        if(!s2.size()){
            s1.push_back((char)(root->val+97));
            return s1;
        }

        s1.push_back((char)(root->val+97));
        s2.push_back((char)(root->val+97));

        int i = 0;
        int j = 0;

        while(i<s1.size() and j<s2.size()){
            if(s1[i] < s2[j]) return s1;
            else if(s1[i] > s2[j]) return s2;
            else {
                i++;
                j++;
            }
        }
        if(s1.size() < s2.size()) return s1;
        else return s2;
    }
    
    string ans = "";
    
    void dfs(TreeNode* root, string x){
        if(!root) return ;
        
        if(!root->left and !root->right){
            if(ans == ""){ // first answer
                ans = (char)(root->val+97) + x;
            }
            else{
                
                x = (char)(root->val  + 97)+ x;
                int i = 0;
                int j = 0;
                while(i< ans.size() and j<x.size()){
                    if(ans[i] < x[j]) break;
                    else if(ans[i] == x[j]){
                        i++;
                        j++;
                    }
                    else{
                        ans =  x;
                        break;
                    }
                }
                if(i<ans.size() and j == x.size() ) ans = x;
                
                // ans = min(ans,(char)(root->val+97)+x); // \U0001f622
            }
        }
        dfs(root->left,(char)(root->val+97)+x);
        dfs(root->right,(char)(root->val+97)+x);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        
        // return ddfs(root,""); // => TC : 69/70
        
        dfs(root,"");  
        return ans;
        
    }
};