class Solution {
public:
    unordered_set<int> s;
    unordered_set<string> ans;

    void solve(string &tiles, string x){
        ans.insert(x);
        for(int i=0; i<tiles.size(); i++){
            if(!s.count(i)){
                s.insert(i);
                x.push_back(tiles[i]);
                solve(tiles,x);
                x.pop_back();
                s.erase(i);
            }
        }
    }
    int numTilePossibilities(string tiles) {
        string x = "";
        solve(tiles,x);
        return ans.size()-1;
    }
};