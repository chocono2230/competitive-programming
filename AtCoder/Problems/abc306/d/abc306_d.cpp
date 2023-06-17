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
  const ll INF = 1e18;
  vector<ll> base(2, -INF);
  auto dp = base;
  dp.at(0) = 0;
  rep(i, n) {
    auto nxdp = base;
    auto [x, y] = xy.at(i);
    if (x == 0) {
      nxdp.at(0) = max({nxdp.at(0), dp.at(0), dp.at(0) + y, dp.at(1) + y});
      nxdp.at(1) = max({nxdp.at(1), dp.at(1)});
    } else {
      nxdp.at(0) = max({nxdp.at(0), dp.at(0)});
      nxdp.at(1) = max({nxdp.at(1), dp.at(1), dp.at(0) + y});
    }
    swap(dp, nxdp);
  }
  ll ans = max(dp.front(), dp.back());
  cout << ans << endl;
  return 0;
}