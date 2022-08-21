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

mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());

template<typename T> T randint(T n) { return uniform_int_distribution<T>(T(0),T(n-1))(rng); }

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> cnt(n,0);
    auto ask = [&](int x = -1) {
        if (x == -1)
            cout << 'W' << endl;
        else
            cout << 'T' _ x+1 << endl;
    };
    int known = 0;
    auto read = [&]() {
        int x, c;
        cin >> x >> c;
        if (!cnt[x-1]) {
            known++;
            cnt[x-1] = c;
        }
    };

    read();
    if (n <= k+1) {
        for(int i = 0; i < n; i++) {
            if (cnt[i])
                continue;
            ask(i);
            read();
        }
    } else {
        int q = 0;
        for(int i = 0; q < k and i < n*4; i++) {
            int x = randint(n);
            if (cnt[x])
                continue;
            q++;
            ask(q%2 ? x : -1);
            read();
        }
    }

    ll sum = 0;
    for(auto t: cnt)
        sum += t;
    sum = sum * n / known / 2;
    cout << 'E' _ sum << endl;
}

signed main() {
    fast;

    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
