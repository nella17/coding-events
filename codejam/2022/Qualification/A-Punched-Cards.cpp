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
    int r, c;
    cin >> r >> c;
    for(int i = 0; i <= r*2; i++) {
        for(int j = 0; j <= c*2; j++) {
            char o = '.';
            if (i+j > 1) {
                int x = (i%2) << 1 | (j%2);
                switch (x) {
                case 0:
                    o = '+';
                    break;
                case 1:
                    o = '-';
                    break;
                case 2:
                    o = '|';
                    break;
                case 3:
                    o = '.';
                    break;
                }
            }
            cout << o;
        }
        cout << endl;
    }
}

signed main() {
    fast;

    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":\n";
        solve();
    }

    return 0;
}
