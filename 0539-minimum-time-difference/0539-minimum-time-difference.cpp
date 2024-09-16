class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // 24 hrs = 1440 ; // The Unique state for time.
        
        int n = timePoints.size();
        vector<int> time(n); 
        int mint;
        
        for(int i=0; i<n; i++){
            mint  = stoi(timePoints[i].substr(0,2)) *60;
            mint += stoi(timePoints[i].substr(3,5));
            time[i] = mint;
        }
        
        sort(time.begin(),time.end());
        
        int adjMin=INT_MAX;
        
        for(int i=1; i<n; i++){
            adjMin= min(adjMin,  time[i]-time[i-1] ); // diff. of adjacent 2
        }
        
        int firstLast = ( 1440 - time[n-1] ) + time[0];
        return min(adjMin,firstLast);
    }
};