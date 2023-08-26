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
  int ta = 0, ao = 0;
  vector<pair<int, int>> dd;
  rep(i, n) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x > y) {
      ta += z;
    } else {
      ao += z;
      dd.push_back({(y - x + 1) / 2, 2 * z});
    }
  }
  if (ta > ao) {
    cout << 0 << endl;
    return 0;
  }
  const ll INF = 1e18;
  vector<ll> base(ao - ta + 1, INF);
  auto dp = base;
  dp.front() = 0;
  for (auto [a, b] : dd) {
    auto nxdp = base;
    rep(i, dp.size()) {
      nxdp.at(i) = min(nxdp.at(i), dp.at(i));
      int ni = min(i + b, (int)base.size() - 1);
      nxdp.at(ni) = min(nxdp.at(ni), dp.at(i) + a);
    }
    swap(dp, nxdp);
  }
  cout << dp.back() << endl;
  return 0;
}