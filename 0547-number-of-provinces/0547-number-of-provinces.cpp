class Solution {
public:
    
    int get(int x, vector<int> &parent){
        return parent[x]= (parent[x]==x)? x : get(parent[x],parent);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> parent(n);
        
        for(int i=0; i<n; i++) parent[i]=i;
        
        vector<int> sz(n,1);
        
        int i=0;
        int j=1;
        
        while(i<n and j<n){
            if(isConnected[i][j] == 1 and get(i,parent)!=get(j,parent)){
                
                int a = get(i,parent);
                int b = get(j,parent);
                if(sz[b] <=sz[a]){
                    parent[b] = a;
                    sz[a] += sz[b];
                }
                else{
                    parent[a] = b;
                    sz[b] += sz[a];
                }
            }
            
            if(j == n-1){
                i++;
                j=i+1;
            }
            else j++;
        }
        
        int groups = 0;
        for(int i=0; i<n; i++){
            if(parent[i] == i) groups++;
        }
        
        return groups;
        
    }
};