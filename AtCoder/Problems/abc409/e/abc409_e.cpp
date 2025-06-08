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
  vector<int> x(n);
  rep(i, n) cin >> x.at(i);
  vector gr(n, vector<pair<int, int>>());
  rep(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    gr.at(u).push_back({v, w});
    gr.at(v).push_back({u, w});
  }

  vector<pair<ll, ll>> dp(n, {-1, -1});
  vector<bool> chk(n, false);
  auto rc = [&](const auto &self, int now, int pr) -> pair<ll, ll> {
    if (chk.at(now)) return dp.at(now);
    chk.at(now) = true;
    ll pos = x.at(now);
    ll cost = 0;
    for (auto [nx, dd] : gr.at(now)) {
      if (nx == pr) continue;
      auto [p, c] = self(self, nx, now);
      cost += c;
      cost += (ll)abs(p) * dd;
      pos += p;
    }
    dp.at(now) = {pos, cost};
    return dp.at(now);
  };
  auto p = rc(rc, 0, -1);
  cout << p.second << endl;
  return 0;
}