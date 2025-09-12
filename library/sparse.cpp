class Sparse {
public:
    vector<vector<ll>> t;
    vector<ll> v;
    ll n;
 
    Sparse(const vector<ll>& a) {
        v = a;
        n = a.size();
        int log = 32 - __builtin_clz(n);
        t.assign(n, vector<ll>(log));
        build();
    }
//l and r should be input as 0 based
    ll query(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return min(t[l][k], t[r - (1 << k) + 1][k]);
    }
 
private:
    void build() {
        for (int i = 0; i < n; ++i)
            t[i][0] = v[i];
        for (int k = 1; (1 << k) <= n; ++k) {
            for (int i = 0; i + (1 << k) <= n; ++i) {
                t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
};

