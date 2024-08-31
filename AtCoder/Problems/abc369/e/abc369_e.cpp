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

const ll INF = 1e18;
int main() {
  int n, m;
  cin >> n >> m;
  vector gr(n, vector<pair<int, ll>>());
  vector<tuple<int, int, int>> edge(m);
  vector mngr(n, vector<ll>(n, INF));
  rep(i, n) mngr.at(i).at(i) = 0;
  rep(i, m) {
    int u, v, t;
    cin >> u >> v >> t;
    u--;
    v--;
    mngr.at(u).at(v) = mngr.at(v).at(u) = min(mngr.at(v).at(u), (ll)t);
    edge.at(i) = {u, v, t};
  }
  rep(k, n) rep(i, n) rep(j, n) {
    mngr.at(i).at(j) =
        min(mngr.at(i).at(j), mngr.at(i).at(k) + mngr.at(k).at(j));
  }

  int q;
  cin >> q;
  while (q--) {
    int ki;
    cin >> ki;
    vector<int> b(ki);
    rep(i, ki) {
      cin >> b.at(i);
      b.at(i)--;
    }
    sort(ALL(b));
    ll ans = INF;
    do {
      vector dp(ki + 1, vector<ll>(2, INF));
      vector mm(ki + 1, vector<ll>(2, 0));
      dp.at(0).at(0) = 0;
      dp.at(0).at(1) = 0;
      rep(i, ki) {
        int now = b.at(i);
        auto [u, v, t] = edge.at(now);
        vector<int> zz = {u, v};
        rep(j, 2) {
          rep(idx, 2) {
            int p1 = mm.at(i).at(j);
            ll ad1 = mngr.at(p1).at(zz.at(idx));
            if (dp.at(i).at(j) + ad1 + t < dp.at(i + 1).at(idx)) {
              dp.at(i + 1).at(idx) = dp.at(i).at(j) + ad1 + t;
              mm.at(i + 1).at(idx) = zz.at(1 - idx);
            }
          }
        }
      }
      auto [f1, f2, f3] = edge.at(b.back());
      ll c1 = mngr.at(f1).at(n - 1);
      ll c2 = mngr.at(f2).at(n - 1);
      ans = min({ans, dp.back().at(0) + c2, dp.back().at(1) + c1});
    } while (next_permutation(ALL(b)));
    cout << ans << endl;
  }
  return 0;
}