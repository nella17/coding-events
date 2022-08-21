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
    int n;
    cin >> n;
    vector<int> v(n);
    map<int,int> mp{};
    for(auto &x: v) {
        cin >> x;
        mp[x]++;
    }
    for(auto x: v) {
        auto it = prev(mp.lower_bound(x*2+1));
        int y = it->ft, c = it->sd;
        if (x == y and c == 1) {
            y = it == mp.begin() ? -1 : prev(it)->ft;
        }
        cout << y << ' ';
    }
    cout << endl;
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
