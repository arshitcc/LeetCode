class ProductOfNumbers {
public:
    vector<long long> ans;
    int lastZero = -1;

    ProductOfNumbers() {
        ans.push_back(1); 
    }

    void add(int num) {
        if (num == 0) {
            ans.push_back(1);
            lastZero = ans.size()-1; 
        } else ans.push_back(ans.back()*num);
    }

    int getProduct(int k) {
        int n = ans.size();
        if (k > n-1) return 0; 
        if (lastZero >= n-k) return 0;
        return ans[n-1]/ans[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */