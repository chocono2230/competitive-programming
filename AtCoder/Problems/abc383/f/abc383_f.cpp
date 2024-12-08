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
  int n, x, k;
  cin >> n >> x >> k;
  vector<tuple<int, int, int>> cpu(n);
  rep(i, n) {
    int p, u, c;
    cin >> p >> u >> c;
    cpu.at(i) = {c, p, u};
  }
  const ll INF = 1e18;
  vector base(x + 1, vector<ll>(2, -INF));
  auto dp = base;
  dp.front().front() = 0;
  sort(ALL(cpu));
  int bf = get<0>(cpu.at(0));
  for (auto [c, p, u] : cpu) {
    auto nxdp = base;
    if (c != bf) {
      rep(i, x + 1) {
        dp.at(i).at(0) = max(dp.at(i).at(0), dp.at(i).at(1));
        dp.at(i).at(1) = -INF;
      }
    }
    rep(i, x + 1) {
      rep(j, 2) {
        nxdp.at(i).at(j) = max(nxdp.at(i).at(j), dp.at(i).at(j));
        int ni = i + p;
        if (ni > x) continue;
        int nj = 1;
        ll add = u;
        if (j == 0) {
          add += k;
        }
        nxdp.at(ni).at(nj) = max(nxdp.at(ni).at(nj), dp.at(i).at(j) + add);
      }
    }
    bf = c;
    swap(dp, nxdp);
  }
  ll ans = 0;
  rep(i, x + 1) rep(j, 2) ans = max(ans, dp.at(i).at(j));
  cout << ans << endl;
  return 0;
}