class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        double minCost = DBL_MAX;
        
        int n = quality.size();
        vector<pair<double,int>> pay;
        
        for(int i=0; i<n; i++){
            double min_ratio = (double)wage[i]/quality[i];
            pay.push_back({min_ratio, quality[i]});
        }
        
        sort(pay.begin(), pay.end());
        
        double qualitySum = 0;
        double minRatio = 0;
        priority_queue<int> pq;
        
        // The HARD-Part :
        for(int i=0; i<k; i++){
            minRatio = max(minRatio, pay[i].first);
            qualitySum += pay[i].second;
            pq.push(pay[i].second);
        }
        
        minCost = min(minCost, minRatio*qualitySum);
        
        for(int i=k; i<n; i++){
            
            // pay[i].first = new Fixed worker according to which pay will now be given
            qualitySum -= pq.top(); pq.pop();
            qualitySum += pay[i].second;
            pq.push(pay[i].second);
            
            minCost = min(minCost, pay[i].first*qualitySum);
        }
        
        return minCost;   
    }
};