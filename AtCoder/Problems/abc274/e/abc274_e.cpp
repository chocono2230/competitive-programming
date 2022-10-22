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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> xy(n), pq(m), v;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    xy.at(i) = {x, y};
    v.push_back({x, y});
  }
  rep(i, m) {
    int p, q;
    cin >> p >> q;
    pq.at(i) = {p, q};
    v.push_back({p, q});
  }

  const double INF = 1e18;
  int nm = n + m;
  vector dp(1 << (nm), vector<double>(nm, INF));
  rep(i, nm) {
    double d = hypot(v.at(i).first, v.at(i).second);
    dp.at(1 << i).at(i) = d;
  }
  int msk = (1 << n) - 1;
  double ans = INF;
  rep(bit, 1 << nm) {
    rep(last, nm) {
      if (dp.at(bit).at(last) == INF) continue;
      if ((bit & msk) == msk) {
        double add = dp.at(bit).at(last);
        int bb = (bit >> n);
        int p = __builtin_popcount(bb);
        double bst = 1 << p;
        add += hypot(v.at(last).first, v.at(last).second) / bst;
        ans = min(ans, add);
      }
      rep(nx, nm) {
        if ((bit & (1 << nx)) != 0) continue;
        int nxbit = (bit | (1 << nx));
        double add = dp.at(bit).at(last);
        int bb = (bit >> n);
        int p = __builtin_popcount(bb);
        double bst = 1 << p;
        add += hypot(abs(v.at(last).first - v.at(nx).first),
                     abs(v.at(last).second - v.at(nx).second)) /
               bst;
        dp.at(nxbit).at(nx) = min(dp.at(nxbit).at(nx), add);
      }
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}