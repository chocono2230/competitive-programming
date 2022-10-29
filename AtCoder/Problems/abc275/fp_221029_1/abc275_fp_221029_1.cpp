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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  const int INF = 1001001001;
  vector dp(n + 1, vector(m + 1, vector(2, INF)));
  dp.front().front().back() = 0;
  rep(i, n) rep(j, m + 1) rep(k, 2) {
    if (dp.at(i).at(j).at(k) == INF) continue;
    int ni = i + 1;
    rep(nk, 2) {
      int nj = j;
      if (nk == 1) nj += a.at(i);
      int add = dp.at(i).at(j).at(k);
      if (nk == 0) {
        if (k == 1) add++;
      }
      if (nj > m) continue;
      dp.at(ni).at(nj).at(nk) = min(dp.at(ni).at(nj).at(nk), add);
    }
  }
  rep2(i, 1, m + 1) {
    int ans = dp.back().at(i).front();
    ans = min(ans, dp.back().at(i).back());
    if (ans == INF) ans = -1;
    cout << ans << endl;
  }
  return 0;
}