class Solution {
public:

    int maximumSwap(int num) {

        // BruteForce : Zindabad
       string x = to_string(num);

        int maxNum = num;
        for(int i=0; i<x.size(); i++){
            for(int j=i+1; j<x.size(); j++){
                swap(x[i],x[j]);
                num = stoi(x);
                maxNum = max(maxNum,num);
                swap(x[i],x[j]);
            }
        }
        return maxNum;
    }
};