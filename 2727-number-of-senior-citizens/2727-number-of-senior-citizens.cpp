class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto i : details){
            int age = (i[11]-48)*10 + i[12]-48;
            if(age > 60) count++;
        }
        return count;
    }
};