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
  vector p(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> p.at(i).at(j);
  map<int, int> mp;
  int sz = 0;
  rep(i, n) rep(j, n) mp[p.at(i).at(j)] = -1;
  vector<int> mp2p;
  for (auto &p : mp) {
    mp2p.push_back(p.first);
    p.second = sz++;
  }
  vector q(n, vector<int>(n));
  rep(i, n) rep(j, n) q.at(i).at(j) = mp[p.at(i).at(j)];
  vector r(n, vector<int>(n - 1));
  rep(i, n) rep(j, n - 1) cin >> r.at(i).at(j);
  vector d(n - 1, vector<int>(n));
  rep(i, n - 1) rep(j, n) cin >> d.at(i).at(j);
  const ll INF = 1e18;
  vector dp(n, vector(n, vector<pair<ll, ll>>(sz, {INF, -INF})));
  dp.at(0).at(0).at(q.at(0).at(0)) = {0, 0};
  rep(i, n) rep(j, n) rep(k, sz) {
    if (dp.at(i).at(j).at(k).first == INF) continue;
    int ni = i, nj = j;
    auto fc = [&](int cost) {
      ll z = -dp.at(i).at(j).at(k).second - cost;
      int mx = mp2p.at(k);
      int add = 1;
      if (z < 0) {
        int co = (abs(z) + mx - 1) / mx;
        add += co;
        z += co * mx;
      }
      int nxk = max(k, q.at(ni).at(nj));
      auto p = dp.at(i).at(j).at(k);
      p.first += add;
      p.second = -z;
      dp.at(ni).at(nj).at(nxk) = min(dp.at(ni).at(nj).at(nxk), p);
    };
    if (i != n - 1) {
      ni = i + 1;
      nj = j;
      fc(d.at(i).at(j));
    }
    if (j != n - 1) {
      ni = i;
      nj = j + 1;
      fc(r.at(i).at(j));
    }
  }

  ll ans = INF;
  rep(i, sz) ans = min(ans, dp.back().back().at(i).first);
  cout << ans << endl;
  return 0;
}