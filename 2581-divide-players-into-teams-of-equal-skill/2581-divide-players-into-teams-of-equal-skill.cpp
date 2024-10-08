class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int i=0; 
        int j=skill.size()-1;

        int x = -1;
        while(i<j){
            if(x == -1) x = skill[i++]+skill[j--];
            else if(x == skill[i]+skill[j]){
                i++;
                j--;
            }
            else return -1;
        }

        i=0;
        j=skill.size()-1;
        long long sum = 0;
        while(i<j) sum += (skill[i++]*skill[j--]);
        return sum;
    }
};