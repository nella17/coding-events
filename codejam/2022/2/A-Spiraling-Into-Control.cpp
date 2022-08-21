#ifndef DEBUG
#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#endif
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

constexpr int MAX = 1e4+5;

void solve(int n, int k) {
    bool can = k%2 == 0 and k >= n-1;
    vector<pii> pt{};
    if (can) {
        vector<int> v{};
        v.reserve(n*2);
        v.emplace_back(0);
        const int n2 = n*n;
        for(int i = 0, u = n, z = 1; i < n2; ) {
            i += u;
            v.emplace_back(i);
            if (z) u--;
            z ^= 1;
        }

        assert(v.size() == n*2);
        // for(auto x: v) cerr _ x; cerr _ endl;

        int c = 0;
        for(int i = 0; i < n*2 and c+n2-(v[i]+1) > k; ) {
            int a = v[i]+1;
            int ni = min(i+4,n*2-1);
            int b = v[ni];
            int diff = b - a - 1;
            // cerr _ a _ b _ diff _ c _ n2-a _ endl;
            if (b > a+1 and c+n2-a-diff >= k) {
                c += 2;
                pt.emplace_back(a, b);
                i = ni;
            } else {
                c += v[i+1] - v[i];
                i++;
            }
        }
    }

    if (!can) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << pt.size() << endl;
        for(auto [x,y]: pt) cout << x _ y << endl;
    }
}

signed main() {
    fast;

    /*
    for(int i = 3; i <= 9999; i += 2)
        solve(i, 9999+1);
    */

    int T;
    // T = 100;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int n, k;
        // n = 39; k = n*n-3;
        cin >> n >> k;
        solve(n, k);
    }

    return 0;
}
