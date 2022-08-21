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

void solve() {
    int E, w;
    cin >> E >> w;

    vector<unordered_map<int,int>> dp(E+1);
    dp[0][0] = 0;

    vector<int> cur(w), v{};
    for(int e = 0; e < E; e++) {
        v.clear();
        for(int i = 0; i < w; i++) {
            cin >> cur[i];
            for(int j = 0; j < cur[i]; j++)
                v.emplace_back(i+1);
        }

        cerr _ v.size() _ endl;
        do {
            int cm = 0, cl = v.size();
            for(auto x: v)
                cm = cm * 4 + x;
            // for(auto x: v) cerr _ x; cerr _ endl;
            int r = 1e9;
            for(auto [pm,pc]: dp[e]) {
                int pl = 0;
                int same = 0;
                for(int i = pm, s = 1; i; i /= 4) {
                    if (s) {
                        if (pl < cl and i%4 == v[cl-1-pl])
                            same++;
                        else
                            s = 0;
                    }
                    pl++;
                }
                int z = pc + cl + pl - same*2;
                if (z < r) r = z;
            }
            dp[e+1][cm] = r;
        } while (next_permutation(ALL(v)));
        cerr _ e _ dp[e+1].size() _ endl;
    }

    int ans = 1e9;
    for(auto [m,c]: dp[E])
        if (c < ans) ans = c;
    cerr _ ans _ v.size() _ endl;
    ans += v.size();
    cout << ans << endl;
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
