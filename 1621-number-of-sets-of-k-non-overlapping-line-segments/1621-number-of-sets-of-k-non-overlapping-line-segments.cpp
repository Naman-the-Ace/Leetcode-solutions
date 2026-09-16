class Solution {
public:
    const int mod = 1e9 + 7;
    long long t[1001][1001];

    int solve(int n, int k, int i) {
        if (k == 0) return 1;
        if (i >= n) return 0;

        if (t[k][i] != -1)
            return t[k][i];

        long long skip = solve(n, k, i + 1);

        long long take = 0;

        for (int j = i + 1; j < n; j++) {
            take += solve(n, k - 1, j);
            take %= mod;
        }

        return t[k][i] = (skip + take) % mod;
    }

    int numberOfSets(int n, int k) {
        memset(t, -1, sizeof(t));
        return solve(n, k, 0);
    }
};