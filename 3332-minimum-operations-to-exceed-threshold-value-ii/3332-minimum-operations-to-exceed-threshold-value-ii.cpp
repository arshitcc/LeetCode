class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        
        long long count=0;
        for(auto i : nums) pq.push(i);
        while(pq.top()<k){
            long long a=pq.top(); pq.pop();
            long long b=pq.top(); pq.pop();
            long long sum=min(a,b)*2+max(a,b);
            pq.push(sum);
            count++;
        }
        return count;
        
    }
};