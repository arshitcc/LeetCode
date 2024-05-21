class Solution {
public:
        
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Dependency Problem  : 
        
        // Implementing Topological Sort :  Kahn's Algorithm with BFS : 
        
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);
        unordered_set<int> visited;
        
        
        for(auto i : prerequisites) {
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        
        queue<int> q;
        int numVisited = 0;
        
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) {
                q.push(i);
                visited.insert(i);
                numVisited++;
            }
        }
        
        while(q.size()){
            int src = q.front(); q.pop();
            for(auto x : graph[src]){
                if(visited.count(x) == 0){
                    indegree[x]--;
                    if(indegree[x] == 0){
                        q.push(x);
                        visited.insert(x);
                        numVisited++;
                    }
                }
            }
        }
        
        if(numVisited < numCourses) return false;
        return true;

    }
};