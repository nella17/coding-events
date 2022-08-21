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
    string s;
    cin >> s;
    int x = 0;
    char c = 255;
    string ans = "";
    for(char i: s) {
        if (c == i) {
            x++;
        } else {
            if (c < i)
                ans += string(x,c);
            c = i; x = 1;
        }
        ans += i;
    }
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
