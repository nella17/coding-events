#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define fast ;
#else
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
// #define cerr if (1) ; else cerr
#endif
#define _ <<' '<<

#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int R = 105;
int table[R][R] = {};
void solve(int t) {
    int r; cin >> r;
    for(int i = 0; i <= r; i++) {
        for(int x = 0; x <= i; x++) {
            int y = round(sqrt(i*i - x*x));
            table[x][y] = table[y][x] = t;
        }
    }
    /*
    for(int x = 0; x <= r; x++)
        for(int y = 0; y <= r; y++)
            cerr << fixed << setw(2) << table[x][y] << " \n"[y==r];
    cerr << endl;
    //*/
    int c = 0;
    for(int x = 0; x <= r; x++)
        for(int y = 0; y <= r; y++)
            if (round(sqrt(x*x+y*y)) <= r and table[x][y] != t)
                c++;
    cout << 4*c << endl;
}

signed main() {
    fast;

    /*
    ld mn = 1, mx = 0;
    for(int r = 0; r < R; r++) {
        for(int x = 0; x <= r; x++) {
            int y = round(sqrt(r*r - x*x));
            table[x][y] = table[y][x] = 1;
        }
        for(int x = 0; x <= r; x++)
            for(int y = 0; y <= r; y++)
                cout << fixed << setw(2) << table[x][y] << " \n"[y==r];
        cout << endl;
        int c = 0;
        for(int x = 0; x <= r; x++)
            for(int y = 0; y <= r; y++)
                if (round(sqrt(x*x+y*y)) <= r and table[x][y] == 0)
                    c++;
        // cerr _ r _ c _ ':';
        if (r == R-1)
        for(int x = 0; x <= r; x++)
            for(int y = 0; y <= r; y++)
                if (round(sqrt(x*x+y*y)) <= r and table[x][y] == 0) {
                    ld z = sqrt(x*x+y*y);
                    z -= int(z);
                    if (z > mx) mx = z;
                    if (z < mn) mn = z;
                }
        // cerr _ endl;
    }
    cerr _ mn _ mx _ endl;
    */

    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve(t);
    }

    return 0;
}
