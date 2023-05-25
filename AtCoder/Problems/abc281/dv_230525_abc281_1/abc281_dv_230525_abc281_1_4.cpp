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
  int n, k, d;
  cin >> n >> k >> d;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  const ll INF = 1e18;
  vector dp(n + 1, vector(k + 1, vector<ll>(d, -INF)));
  dp.front().front().front() = 0;
  rep(i, n) {
    int ni = i + 1;
    rep(j, k + 1) rep(m, d) {
      if (dp.at(i).at(j).at(m) == -INF) continue;
      dp.at(ni).at(j).at(m) = max(dp.at(ni).at(j).at(m), dp.at(i).at(j).at(m));
      if (j != k) {
        ll nx = dp.at(i).at(j).at(m) + a.at(i);
        int nj = j + 1, nm = (m + (a.at(i) % d)) % d;
        dp.at(ni).at(nj).at(nm) = max(dp.at(ni).at(nj).at(nm), nx);
      }
    }
  }
  ll ans = dp.back().back().at(0);
  if (ans == -INF) ans = -1;
  cout << ans << endl;
  return 0;
}