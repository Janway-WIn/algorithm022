class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0) return 0;
        vector<int> res(n, 1);
        int i = 0, j = 0,  k = 0;
        for (int it = 1; it < n; it++) {
            int tmp = min(res[i] * 2, min(res[j] * 3, res[k] * 5));
            if (tmp == res[i] * 2) i++;
            if (tmp == res[j] * 3) j++;
            if (tmp == res[k] * 5) k++;
            res[it] = tmp;
        }
        return res[n - 1];
    }
};
