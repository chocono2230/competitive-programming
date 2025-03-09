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
  cin >> n >> m;
  vector gr(n, vector<ll>(n, -1));
  rep(i, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    gr.at(u).at(v) = gr.at(v).at(u) = w;
  }
  ll ans = 8e18;
  vector<bool> table(n, false);
  auto dfs = [&](const auto &self, int pos, ll now) -> void {
    table.at(pos) = true;
    if (pos == n - 1) {
      ans = min(ans, now);
      return;
    }
    rep(i, n) {
      if (gr.at(pos).at(i) == -1) continue;
      if (table.at(i)) continue;
      self(self, i, now ^ gr.at(pos).at(i));
      table.at(i) = false;
    }
  };
  dfs(dfs, 0, 0);
  cout << ans << endl;
  return 0;
}