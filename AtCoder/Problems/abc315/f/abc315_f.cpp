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
  int n;
  cin >> n;
  vector<pair<int, int>> xy(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    xy.at(i) = {x, y};
  }
  const double INF = 1e18;
  int sz = min(n + 1, 30);
  vector dp(n, vector<double>(sz, INF));
  dp.at(0).at(0) = 0;
  rep(i, n - 1) {
    auto [x1, y1] = xy.at(i);
    rep(j, dp.at(i).size()) {
      rep2(ni, i + 1, n) {
        int nj = j + (ni - i - 1);
        if (nj >= sz) break;
        auto [x2, y2] = xy.at(ni);
        double d = hypot(x1 - x2, y1 - y2);
        dp.at(ni).at(nj) = min(dp.at(ni).at(nj), dp.at(i).at(j) + d);
      }
    }
  }
  double ans = INF;
  rep(i, sz) {
    int add = 0;
    if (i != 0) add = (1 << (i - 1));
    ans = min(ans, dp.back().at(i) + add);
  }
  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}