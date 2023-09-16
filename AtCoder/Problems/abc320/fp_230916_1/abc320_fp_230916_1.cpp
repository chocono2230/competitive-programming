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
  int n, h;
  cin >> n >> h;
  vector<int> x(n);
  rep(i, n) cin >> x.at(i);
  vector<pair<int, int>> pf(n - 1);
  rep(i, n - 1) {
    int p, f;
    cin >> p >> f;
    pf.at(i) = {p, f};
  }
  const ll INF = 1e18;
  vector base(h + 1, vector<ll>(h + 1, INF));
  auto dp = base;
  rep(i, h + 1) dp.at(h).at(i) = 0;
  rep(idx, n) {
    int d = x.at(idx);
    if (idx != 0) d -= x.at(idx - 1);
    auto nxdp = base;
    int p = -1, f = -1;
    if (idx != n - 1) {
      tie(p, f) = pf.at(idx);
    }
    rrep(i, h + 1) {
      const int ni = i - d;
      if (ni < 0) break;
      rep(j, h + 1) {
        const int nj = j + d;
        if (nj > h) break;
        nxdp.at(ni).at(nj) = min(nxdp.at(ni).at(nj), dp.at(i).at(j));
        if (p == -1) continue;
        int nni = min(h, ni + f);
        nxdp.at(nni).at(nj) = min(nxdp.at(nni).at(nj), dp.at(i).at(j) + p);
        int nnj = nj - f;
        if (nnj >= 0)
          nxdp.at(ni).at(nnj) = min(nxdp.at(ni).at(nnj), dp.at(i).at(j) + p);
        if (nj == h) {
          rep2(r, nnj, nj) {
            nxdp.at(ni).at(r) = min(nxdp.at(ni).at(r), dp.at(i).at(j) + p);
          }
        }
      }
    }
    swap(dp, nxdp);
  }
  ll ans = INF;
  rep(i, h + 1) { ans = min(ans, dp.at(i).at(i)); }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}