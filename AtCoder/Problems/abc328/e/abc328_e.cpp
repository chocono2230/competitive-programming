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
  int n, m;
  ll k;
  cin >> n >> m >> k;
  vector gr(n, vector<pair<int, ll>>());
  rep(i, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--;
    v--;
    gr.at(u).push_back({v, w});
    gr.at(v).push_back({u, w});
  }
  ll ans = k;
  vector<bool> chk(n, false);
  vector<pair<int, ll>> edges;
  auto dfs = [&](const auto &self, int now, int co, ll sum) -> void {
    chk.at(now) = true;
    co++;
    if (co == n) {
      // cerr << sum << endl;
      ans = min(ans, sum % k);
      chk.at(now) = false;
      co--;
      return;
    }
    for (auto p : gr.at(now)) {
      edges.push_back(p);
    }
    for (auto [nx, cost] : edges) {
      if (chk.at(nx)) continue;
      self(self, nx, co, sum + cost);
    }
    rep(i, gr.at(now).size()) edges.pop_back();
    chk.at(now) = false;
    co--;
  };
  dfs(dfs, 0, 0, 0);
  cout << ans << endl;
  return 0;
}