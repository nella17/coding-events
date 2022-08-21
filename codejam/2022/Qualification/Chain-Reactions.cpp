#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define fast ;
#else
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define cerr if (1) ; else cerr
#endif
#define _ <<' '<<

#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll,ll>;

void solve() {
    int n;
    cin >> n;
    vector<ll> fun(n);
    vector<int> par(n), root{};
    vector<vector<int>> edge(n);
    for(auto &x: fun) cin >> x;
    for(int i = 0; i < n; i++) {
        cin >> par[i]; par[i]--;
        if (par[i] == -1)
            root.emplace_back(i);
        else
            edge[ par[i] ].emplace_back(i);
    }

    function<pll(int)> dfs;
    dfs = [&](int x) {
        if (edge[x].empty())
            return pll{ fun[x], 0 };
        vector<ll> v;
        v.reserve(edge[x].size());
        ll sum = 0;
        for(int y: edge[x]) {
            auto [f,s] = dfs(y);
            v.emplace_back(f);
            sum += s;
        }
        sort(ALL(v));
        for(auto z: v) sum += z;
        sum -= v[0];
        // cerr _ x _ ':'; for(auto z: v) cerr _ z; cerr _ endl;
        return pll{ max(v[0],fun[x]), sum };
    };

    ll sum = 0;
    for(auto x: root) {
        auto [f,s] = dfs(x);
        // cerr _ x _ f _ s _ endl;
        sum += f + s;
    }
    cout << sum << endl;
}

signed main() {
    fast;

    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}
