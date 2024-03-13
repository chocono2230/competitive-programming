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
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> dxdy;
  rep(i, 3) {
    int dx, dy;
    cin >> dx >> dy;
    dxdy.push_back({dx, dy});
  }
  set<pair<int, int>> e;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    e.insert({x, y});
  }
  auto tr2p = [&](ll i, ll j, ll k) {
    pair<ll, ll> res;
    res.first += dxdy.at(0).first * i;
    res.first += dxdy.at(1).first * j;
    res.first += dxdy.at(2).first * k;
    res.second += dxdy.at(0).second * i;
    res.second += dxdy.at(1).second * j;
    res.second += dxdy.at(2).second * k;
    return res;
  };
  vector base(305, vector<mint>(305, 0));
  auto dp = base;
  dp.at(0).at(0) = 1;
  rep2(i, 1, n + 1) {
    auto nxdp = base;
    rep(j, 305) rep(k, 305) {
      if (dp.at(j).at(k) == 0) continue;
      int mv = (j + k);
      auto p = tr2p(i - mv, j, k);
      if (e.find(p) == e.end()) nxdp.at(j).at(k) += dp.at(j).at(k);
      if (j != 304) {
        int mv = (j + k + 1);
        auto p = tr2p(i - mv, j + 1, k);
        if (e.find(p) == e.end()) nxdp.at(j + 1).at(k) += dp.at(j).at(k);
      }
      if (k != 304) {
        int mv = (j + k + 1);
        auto p = tr2p(i - mv, j, k + 1);
        if (e.find(p) == e.end()) nxdp.at(j).at(k + 1) += dp.at(j).at(k);
      }
    }
    swap(dp, nxdp);
  }
  mint ans = 0;
  rep(i, 305) rep(j, 305) ans += dp.at(i).at(j);
  cout << ans.val() << endl;
  return 0;
}