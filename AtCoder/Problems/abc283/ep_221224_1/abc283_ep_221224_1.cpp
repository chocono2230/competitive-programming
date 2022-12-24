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
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a.at(i).at(j);
  const int INF = 1001001001;
  vector dp(h, vector(2, vector<int>(2, INF)));
  dp.front().front().front() = 0;
  dp.front().front().back() = 1;
  rep2(i, 1, h) {
    rep(p, 2) rep(q, 2) rep(r, 2) {
      vector<int> x(w, -1);
      if (i != 1) {
        x = a.at(i - 2);
        if (p == 1) rep(j, w) x.at(j) = 1 - x.at(j);
      }
      auto y = a.at(i - 1);
      if (q == 1) rep(j, w) y.at(j) = 1 - y.at(j);
      auto z = a.at(i);
      if (r == 1) rep(j, w) z.at(j) = 1 - z.at(j);
      bool f = false;
      rep(j, w) {
        bool chk = false;
        if (j != 0 && y.at(j - 1) == y.at(j)) chk = true;
        if (j != w - 1 && y.at(j + 1) == y.at(j)) chk = true;
        if (x.at(j) == y.at(j) || y.at(j) == z.at(j)) chk = true;
        if (!chk) f = true;
      }
      if (i == h - 1) {
        rep(j, w) {
          bool chk = false;
          if (j != 0 && z.at(j - 1) == z.at(j)) chk = true;
          if (j != w - 1 && z.at(j + 1) == z.at(j)) chk = true;
          if (y.at(j) == z.at(j)) chk = true;
          if (!chk) f = true;
        }
      }
      if (!f) {
        int add = r;
        dp.at(i).at(q).at(r) =
            min(dp.at(i).at(q).at(r), dp.at(i - 1).at(p).at(q) + add);
      }
    }
  }
  int ans = INF;
  rep(p, 2) rep(q, 2) ans = min(ans, dp.back().at(p).at(q));
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}