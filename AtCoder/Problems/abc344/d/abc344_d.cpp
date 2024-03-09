#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define repit(itr, x) for (auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr, x) for (auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  string t;
  cin >> t;
  int n;
  cin >> n;
  const int INF = 1001001001;
  vector<int> base(t.size() + 1, INF);
  auto dp = base;
  dp.front() = 0;
  rep(_i, n) {
    auto nxdp = dp;
    int sz;
    cin >> sz;
    rep(_j, sz) {
      string s;
      cin >> s;
      auto fc = [&](int l) {
        int idx = 0, r = l + s.size();
        if (r > t.size()) return false;
        rep2(i, l, r) {
          if (s.at(idx++) != t.at(i)) return false;
        }
        return true;
      };
      rep(i, t.size()) {
        if (!fc(i)) continue;
        int ni = i + s.size();
        nxdp.at(ni) = min(nxdp.at(ni), dp.at(i) + 1);
      }
    }
    swap(dp, nxdp);
  }
  int ans = dp.back();
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}