/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        if(!root) return root;

        queue<Node*> q;
        q.push(root);

        int n = 1;
        int count = 1;
        while(q.size()){

            if(n==1) count = 1;

            for(int i=1; i<=count; i++){
                Node* temp = q.front(); q.pop();
                n--;

                if(i==count) temp->next = NULL;
                else if(q.size()) temp->next = q.front();

                if(temp->left) {
                    q.push(temp->left);
                    n++;
                }
                if(temp->right) {
                    q.push(temp->right);
                    n++;
                }
            }

            count = n;
        }


        return root;
    }
};