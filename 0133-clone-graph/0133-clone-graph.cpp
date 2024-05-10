/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    vector<Node*> created;
    
    void dfs(Node* node, Node* clone){
        if(node == NULL) return;
        
        for(auto neighbour : node->neighbors){
            if(created[neighbour->val] == NULL){
                Node* cl = new Node(neighbour->val);
                created[cl->val] = cl;
                clone->neighbors.push_back(cl);
                dfs(neighbour, cl);
            }
            else{
                clone->neighbors.push_back(created[neighbour->val]);
            }
            // Remove push_back from both parts and use only use : clone->neighbors.push_back(created[neighbour->val]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        
        if( node == NULL) return NULL;
        
        // DFS : 
        // created.resize(110,NULL);
        // Node* clone = new Node(node->val);
        // created[clone->val] = clone;   // to make note that the node is already created or not.
        // dfs(node,clone);
        // return clone;
        
        // Andi-Bandi-Candi Jo na Submit hua Uski...
        
        Node* clone = new Node(node->val);
        
        queue<Node*> q;
        q.push(node);
        
        unordered_map<Node*, Node*> created;
        created[node] = clone;
        
        while(q.size()){
            Node* curr = q.front(); q.pop();
            
            for(auto nh : curr->neighbors){
                if(created.count(nh) == 0){
                    Node* temp = new Node(nh->val);
                    q.push(nh);
                    created[nh] = temp;
                }
                // Very Important Line :
                created[curr]->neighbors.push_back(created[nh]);
            }
        }
        
        return clone;
    }
};