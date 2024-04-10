class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        sort(deck.begin(),deck.end()); // n(logn)
        
        //  2 3 5 7 11 12 13 17
        //      2 3  4  5  6  7 1
        //  2 x  3 x  5 x 7 x
        //  2 11 3 13 5 12 7 17
        
        int n = deck.size();
        vector<int> ans(n);

        queue<int> q;
        for(int i=0;i<n;i++) q.push(i);

        int i = 0;
        while(q.size()){  // n
            ans[q.front()] = deck[i]; q.pop();
            
            q.push(q.front());
            q.pop();
            i++;
        }

        return ans;
    }
};