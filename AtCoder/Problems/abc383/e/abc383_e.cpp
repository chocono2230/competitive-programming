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

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<tuple<int, int, int>> wuv(m);
  rep(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    wuv.at(i) = {w, u, v};
  }
  vector<int> ac(n, 0), bc(n, 0);
  rep(i, k) {
    int in;
    cin >> in;
    in--;
    ac.at(in)++;
  }
  rep(i, k) {
    int in;
    cin >> in;
    in--;
    bc.at(in)++;
  }

  dsu uf(n);
  sort(ALL(wuv));
  ll ans = 0;
  for (auto [w, u, v] : wuv) {
    auto r = uf.same(u, v);
    if (r) continue;
    int ul = uf.leader(u);
    int vl = uf.leader(v);
    auto rc = [&]() {
      int mn = min(ac.at(ul), bc.at(vl));
      ans += (ll)mn * w;
      ac.at(ul) -= mn;
      bc.at(vl) -= mn;
      swap(ul, vl);
    };
    rc();
    rc();
    int nl = uf.merge(u, v);
    ac.at(nl) = ac.at(ul) + ac.at(vl);
    bc.at(nl) = bc.at(ul) + bc.at(vl);
  }
  cout << ans << endl;
  return 0;
}