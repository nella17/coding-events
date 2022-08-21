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
    int e, w;
    cin >> e >> w;

    int ans = 0;

    vector<unordered_map<int,int>> v{};
    vector<int> cur(w), cnt{};
    while (e--) {
        int c = 0;
        for(auto &x: cur) {
            cin >> x;
            c += x;
        }

        int l = 0;
        while (c and l < v.size()) {
            auto& mp = v[l];
            bool full = true;
            for(auto [i,x]: mp)
                if (x > cur[i])
                    full = false;
            if (!full)
                break;
            for(auto [i,x]: mp) {
                cur[i] -= x;
                c -= x;
            }
            l++;
        }

        if (c) {
            if (l < v.size()) {
                auto& mp = v[l];
                for(auto &[i,x]: mp) {
                    int u = min(x,cur[i]);
                    cur[i] -= x = u;
                    c -= u;
                    int d = u - cur[i];
                    ans += d;
                    cnt[l] -= d;
                }
                if (cnt[l] == 0) l--;
                while (l+1 < v.size()) {
                    ans += cnt.back();
                    cnt.pop_back();
                    v.pop_back();
                }
            }

            v.emplace_back();
            cnt.emplace_back(c);
            ans += c;
            for(int i = 0; i < w; i++)
                if (cur[i]) v.back().emplace(i,cur[i]);
        }

        cerr _ "---" _ endl;
        cerr _ c _ l _ ans _ endl;
        for(auto& mp: v) {
            for(auto [i,x]: mp) cerr _ i <<','<< x;
            cerr _ endl;
        }
    }

    for(auto x: cnt) ans += x;

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
