class Solution {
public:

    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> q;
        int n = students.size();
        for(int i=0;i<n;i++) q.push(students[i]);

        int i = 0; 
        int count = 0;
            
        while(q.size()!=0 and count!=q.size()){

            if(q.front()==sandwiches[i]){
                count = 0; 
                i++; 
                q.pop();
            }
            else{
                q.push(q.front());
                q.pop(); 
                count++;
            }
        }
        return q.size();
    }
};