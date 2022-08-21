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

constexpr ll INF = 1e16;
using fp = function<ll(ll,ll)>;
map<char,fp> opF{
    { '+', [](ll a, ll b) { return a+b; } },
    { '-', [](ll a, ll b) { return a-b; } },
    { '*', [](ll a, ll b) { return a*b; } },
    { '/', [](ll a, ll b) { return a/b - (a*b < 0 and a%b != 0); } },
};
const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, 1, -1, 0 };

void solve() {
    int n, p, m, Ax, Ay;
    cin >> n >> p >> m >> Ax >> Ay;
    Ax--; Ay--;
    array<char,4> op;
    array<int,4> ok;
    for(int i = 0; i < 4; i++)
        cin >> op[i] >> ok[i];
    vector<int> vx(p), vy(p), vc(p);
    for(int i = 0; i < p; i++) {
        cin >> vx[i] >> vy[i] >> vc[i];
        vx[i]--; vy[i]--;
    }

    auto idx = [&](int x, int y, int mask = 0) {
        return mask * n * n + x * n + y;
    };
    vector<int> mp(n*n,-1);
    for(int i = 0; i < p; i++)
        mp[ idx(vx[i],vy[i]) ] = i;

    int p2 = 1 << p;
    int sz = n*n*p2;
    vector<bool> vis(sz,false);
    vector<ll> dp(sz,-INF);
    // cerr _ n _ p2 _ n*n*p2 _ endl;
    auto upd = [&](int x, int y, int mask, ll val) {
        int i = idx(x,y,mask);
        // cerr _ x _ y _ mask  _ i _ val _ endl;
        if (!vis[i] or dp[i] < val) dp[i] = val;
        vis[i] = true;
    };
    upd(Ax,Ay,0,0);

    auto ck = [&](auto x, auto y) { return !x ? string("X") : to_string(y); };
    for(int i = 0; i < m; i++) {
        auto odp = dp; auto ovis = vis;
        for(int x = 0; x < n; x++) for(int y = 0; y < n; y++) {
            for(int mask = 0; mask < p2; mask++) {
                int j = idx(x,y,mask);
                if (ovis[j]) {
                    for(int d = 0; d < 4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (0 <= nx and nx < n and 0 <= ny and ny < n) {
                            int k = mp[idx(nx,ny)];
                            ll c = opF[op[d]](odp[j],ok[d]);
                            upd(nx, ny, mask, c);
                            if (k >= 0 and ((mask>>k)&1) == 0)
                                upd(nx, ny, mask|(1<<k), c+vc[k]);
                        }
                    }
                }
            }
        }

        /*
        cerr _ endl;
        for(int x = 0; x < n; x++) for(int y = 0; y < n; y++) {
            for(int mask = 0; mask < p2; mask++) {
                int u = idx(x,y,mask);
                cerr << ck(vis[u],dp[u]) << ',';
            }
            cerr << " \n"[y+1==n];
        }
        //*/
    }

    ll ans = -INF;
    for(int x = 0; x < n; x++) for(int y = 0; y < n; y++) {
        int i = idx(x,y,p2-1);
        ll r = dp[i];
        if (vis[i] and ans < r) {
            // cerr _ x _ y _ vis[i] _ r _ endl;
            ans = r;
        }
    }
    if (ans == -INF) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
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
