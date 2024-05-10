class Solution {
public:
    
    // DFS : 
    unordered_set<int> visited;
    
    void collectKeys(int curr, vector<vector<int>> &rooms){
        
        visited.insert(curr);
        for(auto neighbour : rooms[curr]){
            if(visited.count(neighbour) == 0){
                visited.insert(neighbour);
                collectKeys(neighbour,rooms);
            }
        }
        
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        // // DFS : 
        // visited.insert(0);
        // collectKeys(0, rooms);
        
        
        // BFS : 
        
        unordered_set<int> visited;
        visited.insert(0);
        
        queue<int> q;
        q.push(0);
        
        while(q.size()){
            int curr = q.front(); q.pop();
            
            visited.insert(curr);
            
            for(int neighbour : rooms[curr]){
                if(visited.count(neighbour) == 0){ // if not visited then visit.
                    visited.insert(neighbour);
                    q.push(neighbour);
                }
            }
            
        }
        
        return visited.size()==rooms.size();
    }
};