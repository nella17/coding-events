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

constexpr int MAXN = 1e5;

int z[MAXN*2+1];
int Manacher(string tmp) {
  string s = "&";
  int l = 0, r = 0, x, ans;
  for (char c : tmp) s += c, s += '%';
  ans = 0, x = 0;
  const int sz = s.size();
  for (int i = 1; i < sz; i++) {
    z[i] = r > i ? min(z[2 * l - i], r - i) : 1;
    while (s[i + z[i]] == s[i - z[i]]) ++z[i];
    if (z[i] + i > r) r = z[i] + i, l = i;
  }
  for (int i = 1; i < sz; i++)
    if (s[i] == '%') x = max(x, z[i]);
  ans = x / 2 * 2, x = 0;
  for (int i = 1; i < sz; i++)
    if (s[i] != '%') x = max(x, z[i]);
  return max(ans, (x - 1) / 2 * 2 + 1);
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    Manacher(s);
    string ans = "";
    int r = 0;
    // for(int i = 0; i <= n*2+1; i++) cerr _ z[i]; cerr _ endl;
    for(int i = 0; i < n; i++) {
        if (i == z[i]) {
            int j = n-i, k = n+i;
            int o = k % 2;
            int x = (z[k]-o) / 2 * 2 + o;
            // cerr _ i _ j _ k _ z[k] _ x _ endl;
            if (j == x)
                r = i;
        }
    }
    // cerr _ r _ z[r] _ endl;
    ans = s.substr(r);
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
