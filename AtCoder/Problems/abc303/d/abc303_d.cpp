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
  int x, y, z;
  cin >> x >> y >> z;
  string s;
  cin >> s;
  int n = s.size();
  const ll INF = 1e18;
  vector dp(n + 1, vector<ll>(2, INF));
  dp.front().front() = 0;
  dp.front().back() = z;
  rep(i, n) {
    int ni = i + 1;
    int p = 0;
    if (s.at(i) == 'A') p = 1;
    rep(j, 2) {
      if (j == p) {
        dp.at(ni).at(j) = min(dp.at(ni).at(j), dp.at(i).at(j) + x);
        dp.at(ni).at(1 - j) = min(dp.at(ni).at(1 - j), dp.at(i).at(j) + x + z);
        dp.at(ni).at(1 - j) = min(dp.at(ni).at(1 - j), dp.at(i).at(j) + z + y);
      } else {
        dp.at(ni).at(j) = min(dp.at(ni).at(j), dp.at(i).at(j) + y);
        dp.at(ni).at(1 - j) = min(dp.at(ni).at(1 - j), dp.at(i).at(j) + y + z);
        dp.at(ni).at(1 - j) = min(dp.at(ni).at(1 - j), dp.at(i).at(j) + z + x);
      }
    }
  }
  ll ans = min(dp.back().front(), dp.back().back());
  cout << ans << endl;
  return 0;
}