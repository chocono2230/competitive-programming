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
  int h, w, k;
  cin >> h >> w >> k;
  int si, sj;
  cin >> si >> sj;
  si--;
  sj--;
  vector a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a.at(i).at(j);
  int n = h * w;
  const ll INF = 1e18;
  vector base(h, vector<ll>(w, -INF));
  auto dp = base;
  dp.at(si).at(sj) = 0;
  ll ans = -INF;
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  rep(p, n + 5) {
    int z = k - p - 1;
    if (z < 0) break;
    auto nxdp = base;
    rep(i, h) rep(j, w) {
      if (dp.at(i).at(j) == -INF) continue;
      nxdp.at(i).at(j) = max(nxdp.at(i).at(j), dp.at(i).at(j) + a.at(i).at(j));
      rep(k, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
        nxdp.at(ni).at(nj) =
            max(nxdp.at(ni).at(nj), dp.at(i).at(j) + a.at(ni).at(nj));
      }
    }
    swap(dp, nxdp);
    rep(i, h) rep(j, w) {
      ll add = dp.at(i).at(j);
      add += (ll)a.at(i).at(j) * (ll)z;
      ans = max(ans, add);
    }
  }
  cout << ans << endl;
  return 0;
}