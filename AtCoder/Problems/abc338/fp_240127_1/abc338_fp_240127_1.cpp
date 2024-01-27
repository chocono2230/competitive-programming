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
  const ll INF = 1e18;
  vector gr(n, vector<ll>(n, INF));
  rep(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    gr.at(u).at(v) = w;
  }
  rep(i, n) gr.at(i).at(i) = 0;
  rep(k, n) rep(i, n) rep(j, n) {
    if (gr.at(i).at(k) == INF || gr.at(k).at(j) == INF) continue;
    gr.at(i).at(j) = min(gr.at(i).at(j), gr.at(i).at(k) + gr.at(k).at(j));
  }

  vector dp(1 << n, vector<ll>(n, INF));
  rep(i, n) { dp.at((1 << i)).at(i) = 0; }
  rep2(bit, 1, 1 << n) {
    rep(now, n) {
      if (dp.at(bit).at(now) == INF) continue;
      rep(nx, n) {
        int nxbit = (bit | (1 << nx));
        if (nxbit == bit) continue;
        if (gr.at(now).at(nx) == INF) continue;
        ll nw = dp.at(bit).at(now) + gr.at(now).at(nx);
        dp.at(nxbit).at(nx) = min(dp.at(nxbit).at(nx), nw);
      }
    }
  }
  ll ans = INF;
  rep(i, n) ans = min(ans, dp.back().at(i));
  if (ans == INF)
    cout << "No" << endl;
  else
    cout << ans << endl;
  return 0;
}