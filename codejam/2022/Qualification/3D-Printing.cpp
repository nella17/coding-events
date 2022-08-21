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
    const int TOT = 1e6;
    array<array<int,4>,3> v;
    for(auto &a: v) for(auto &x: a) cin >> x;
    array<int,4> mn;
    int sum = 0;
    for(int i = 0; i < 4; i++) {
        mn[i] = TOT;
        for(auto &a: v)
            if (a[i] < mn[i])
                mn[i] = a[i];
        sum += mn[i];
    }
    if (sum < TOT) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        sum = 0;
        for(int i = 0; i < 4; i++) {
            int x = min(TOT-sum, mn[i]);
            sum += x;
            cout << x << " \n"[i+1==4];
        }
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
