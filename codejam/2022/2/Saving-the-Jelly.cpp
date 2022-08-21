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

ll d(pii a, pii b) {
    ll dx = a.ft - b.ft;
    ll dy = a.sd - b.sd;
    return dx*dx + dy*dy;
}

void solve() {
    int n;
    cin >> n;
    vector<pii> childs(n), candy(n);
    pii blue;
    for(auto &[x,y]: childs) cin >> x >> y;
    cin >> blue.ft >> blue.sd;
    for(auto &[x,y]: candy) cin >> x >> y;

    auto cmp = [&](const auto& v, const pii& r, int i, int j) {
        ll di = d(v[i],r);
        ll dj = d(v[j],r);
        if (di != dj) return di < dj;
        di = d(v[i],blue);
        dj = d(v[j],blue);
        if (di != dj) return di > dj;
        return i < j;
    };

    bool can = true;
    vector<pii> ans{};
    ans.reserve(n);

    vector<int> chid(n), caid(n);
    for(int i = 0; i < n; i++)
        chid[i] = caid[i] = i;
    sort(ALL(chid), [&](int i, int j) { return cmp(childs,blue,i,j); });
    // sort(ALL(caid), [&](int i, int j) { return cmp(candy,blue,i,j); });
    // for(auto i: chid) cerr _ childs[i].ft _ childs[i].sd _ endl;
    vector<bool> used(n,false);
    for(auto x: chid) {
        ll db = d(childs[x],blue);
        sort(ALL(caid), [&](int i, int j) { return cmp(candy,childs[x],i,j); });
        for(auto y: caid) if (!used[y]) {
            ll dc = d(childs[x],candy[y]);
            if (db < dc) {
                can = false;
            } else {
                used[y] = true;
                ans.emplace_back(x,y);
            }
            break;
        }
        if (!can) break;
    }

    if (!can) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << "POSSIBLE" << endl;
        for(auto [a,b]: ans)
            cout << a+1 _ b+2 << endl;
    }
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
