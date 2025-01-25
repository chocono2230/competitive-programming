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
  int n, x;
  cin >> n >> x;
  vector ac(3, vector<pair<int, int>>());
  rep(i, n) {
    int v, a, c;
    cin >> v >> a >> c;
    v--;
    ac.at(v).push_back({a, c});
  }
  vector vvac(3, vector<pair<int, int>>());
  const ll INF = 1e18;
  vector<ll> base(x + 1, -INF);
  rep(idx, 3) {
    auto dp = base;
    dp.front() = 0;
    for (auto [a, c] : ac.at(idx)) {
      auto nxdp = base;
      rep(i, x + 1) {
        nxdp.at(i) = max(nxdp.at(i), dp.at(i));
        if (i + c > x) continue;
        nxdp.at(i + c) = max(nxdp.at(i + c), dp.at(i) + a);
      }
      swap(dp, nxdp);
    }
    rep(i, x + 1) {
      if (dp.at(i) < 0) continue;
      vvac.at(idx).push_back({dp.at(i), i});
    }
  }
  auto dp = base;
  rep(idx, 3) {
    auto nxdp = base;
    for (auto [a, c] : vvac.at(idx)) {
      rep(i, x + 1) {
        if (i + c > x) break;
        if (idx != 0 && dp.at(i) == -INF) continue;
        ll nx = a;
        if (idx != 0 && dp.at(i) < nx) nx = dp.at(i);
        nxdp.at(i + c) = max(nxdp.at(i + c), nx);
      }
    }
    swap(dp, nxdp);
  }
  ll ans = 0;
  rep(i, dp.size()) ans = max(ans, dp.at(i));
  cout << ans << endl;

  return 0;
}