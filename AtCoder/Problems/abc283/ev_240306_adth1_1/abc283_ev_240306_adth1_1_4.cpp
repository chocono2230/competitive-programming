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
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a.at(i).at(j);

  auto ff = [](int l, int r) { return l ^ r; };
  auto fc = [&](int ti, int prmode, int tmode, int nxmode) {
    rep(wi, w) {
      int pwi = wi - 1;
      int now = a.at(ti).at(wi);
      if (pwi != -1 && a.at(ti).at(pwi) == now) continue;
      pwi = wi + 1;
      if (pwi != w && a.at(ti).at(pwi) == now) continue;
      if (ti != 0 && ff(a.at(ti - 1).at(wi), prmode) == ff(now, tmode))
        continue;
      if (ti != h - 1 && ff(a.at(ti + 1).at(wi), nxmode) == ff(now, tmode))
        continue;
      return false;
    }
    return true;
  };

  const int INF = 1001001001;
  vector dp(h + 1, vector(2, vector<int>(2, INF)));
  dp.front().front().front() = 0;
  dp.front().front().back() = 1;
  rep(i, h) rep(j, 2) rep(k, 2) {
    int ni = i + 1, nj = k;
    if (dp.at(i).at(j).at(k) == INF) continue;
    rep(nk, 2) {
      if (!fc(i, j, k, nk)) continue;
      dp.at(ni).at(nj).at(nk) =
          min(dp.at(ni).at(nj).at(nk), dp.at(i).at(j).at(k) + nk);
    }
  }
  int ans = INF;
  rep(j, 2) rep(k, 2) ans = min(ans, dp.back().at(j).at(k));
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}