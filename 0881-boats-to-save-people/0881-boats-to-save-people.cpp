class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int boat=  0;

        sort(people.begin(),people.end());

        int i = 0;
        int j = people.size()-1;
        while(i<=j){
            if(people[i] + people[j] <= limit){
                boat++;
                i++;
                j--;
            }
            else if(people[j]<=limit){
                boat++;
                j--;
            }
        }
        
        return boat;

    }
};