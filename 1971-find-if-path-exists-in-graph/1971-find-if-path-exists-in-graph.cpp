class Solution {
public:
    
    unordered_set<int> visited;
    
    bool dfs(int source, int destination, vector<vector<int>> &graph){
        if(source == destination) return true;
        
        visited.insert(source);
        
        for(auto neighbor : graph[source]){
            if(visited.count(neighbor) == 0){
                bool res = dfs(neighbor, destination, graph);
                if(res == true) return true;
            }
        }
        
        return false;
    }
    
    bool bfs(int source, int destination, vector<vector<int>> &graph){
        
        if(source == destination ) return true;
        
        queue<int> q;
        q.push(source);
        
        while(q.size()){
            int n = q.size();
            
            for(int i=1; i<=n; i++){
                int src = q.front(); q.pop();
                for(auto neighbor : graph[src]){
                    if(neighbor == destination) return true;
                    if(visited.count(neighbor) == 0){
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }
         return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> graph;
        graph.resize(n);
        
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        // for(int i=0; i<graph.size(); i++){
        //     for(int j=0; j<graph[i].size(); j++){
        //         cout<<graph[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        // return dfs(source,destination, graph); // 1188ms
        return bfs(source,destination, graph); // 387ms
    }
};