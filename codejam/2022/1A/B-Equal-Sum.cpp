#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define fast ;
#else
#define fast ios::sync_with_stdio(0);cin.tie(0);
// #define endl '\n'
#define cerr if (1) ; else cerr
#endif
#define _ <<' '<<

#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int K = 30;
constexpr int MAX = 1e9;

void solve() {
    int n;
    cin >> n;

    set<int,greater<int>> v;

    for(int i = 0; i < n; i++) {
        int x;
        if (i < K)
            x = 1<<i;
        else
            x = MAX - (i-K);
        v.emplace(x);
        cout << x << " \n"[i+1==n];
    }
    cout << flush;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.emplace(x);
    }

    ll sum = 0;
    for(auto x: v) sum += x;
    // for(auto x: v) cerr _ x; cerr _ endl;
    // cerr _ sum _ endl;

    set<int> ans;

    ll t = sum/2, u = 0;
    for(auto x: v) {
        if (t < (1<<K)) break;
        t -= x;
        u += x;
        ans.emplace(x);
    }

    for(int i = 0; i < K; i++) {
        int x = 1 << i;
        if (t & x) {
            ans.emplace(x);
            u += x;
        }
    }

    t = 0;
    for(auto x: ans) t += x;
    assert(u == t && u*2 == sum);

    int sz = ans.size();
    if (sz <= n)
        for(auto x: ans) cout << x << ' ';
    else
        for(auto x: v) if (ans.find(x) == ans.end())
            cout << x << ' ';
    cout << endl;
}

signed main() {
    fast;

    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
