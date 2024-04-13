class Solution {
public:

    int largestRectangle(vector<int> heights){ 
        
        int n = heights.size();

        vector<int> nsIdx(n);
        nsIdx[n-1] = 0;
        stack<int> nst;
        nst.push(n-1);

        vector<int> psIdx(n);
        psIdx[0] = 0;
        stack<int> pst;
        pst.push(0);

        for(int i=n-2;i>=0;i--){
            while(nst.size()!=0 and heights[i]<=heights[nst.top()]) nst.pop();
            if(nst.size()!=0) nsIdx[i] = nst.top()-i-1;
            else nsIdx[i] = n-i-1;
            nst.push(i);
        
            while(pst.size()!=0 and heights[n-i-1]<=heights[pst.top()]) pst.pop();
            if(pst.size()!=0) psIdx[n-i-1] =n-i-pst.top()-2;
            else psIdx[n-i-1] = n-i-1;
            pst.push(n-i-1);
        }
        
        int hmax = -1;
        for(int i=0;i<n;i++) {
            heights[i] = heights[i]*(nsIdx[i]+psIdx[i]+1);
            hmax = max(hmax,heights[i]);
        }
        return hmax; 
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(m,0);
        
        int maxArea = INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') row[j]++;
                else row[j] = 0;
            }
            maxArea = max(maxArea,largestRectangle(row));
        }
        return maxArea;
        
    }
};