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
  vector<int> p(n);
  rep(i, n) cin >> p.at(i);
  reverse(ALL(p));
  vector dp(n + 1, vector<double>(n + 1, 0));
  vector<double> p9(n + 1, 1);
  rep2(i, 1, n) { p9.at(i) = p9.at(i - 1) * 0.9; }
  rep(i, n) {
    int ni = i + 1;
    rep(j, n + 1) {
      dp.at(ni).at(j) = max(dp.at(ni).at(j), dp.at(i).at(j));
      if (j <= i) {
        double add = dp.at(i).at(j) + p.at(i) * p9.at(j);
        dp.at(ni).at(j + 1) = max(dp.at(ni).at(j + 1), add);
      }
    }
  }
  double ans = -1e18, b = 1, ss = 0;
  // rep(i, n + 1) {
  //   rep(j, n + 1) cerr << dp.at(i).at(j) << " ";
  //   cerr << endl;
  // }
  rep2(i, 1, n + 1) {
    ss += b;
    b *= 0.9;
    double add = dp.back().at(i) / ss;
    add -= 1200 / sqrt(i);
    // cerr << i << " " << add << endl;
    ans = max(ans, add);
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}