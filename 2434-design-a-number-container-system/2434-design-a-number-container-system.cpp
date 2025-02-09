class NumberContainers {
public:

    unordered_map<int,int> m;
    unordered_map<int, set<int>> m1;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(m.count(index)) {
            int n = m[index];
            m1[n].erase(index);
        }
        m[index] = number;
        m1[number].insert(index);
    }
    
    int find(int number) {
        if(!m1[number].size()) return -1;
        return *m1[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */