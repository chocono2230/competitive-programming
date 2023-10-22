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
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d.at(i);
  ll l1, c1, k1;
  cin >> l1 >> c1 >> k1;
  ll l2, c2, k2;
  cin >> l2 >> c2 >> k2;
  const int INF = 1001001001;
  vector dp(n + 1, vector<int>(k1 + 1, INF));
  dp.front().front() = 0;
  rep(i, n) {
    int now = d.at(i);
    int ni = i + 1;
    rep(k, k1 + 1) {
      rep(add, k2 + 1) {
        if (dp.at(i).at(k) + add > k2) continue;
        int l = add * l2;
        int nk = k;
        if (l < now) {
          nk += (now - l + l1 - 1) / l1;
        }
        if (nk > k1) continue;
        dp.at(ni).at(nk) = min(dp.at(ni).at(nk), dp.at(i).at(k) + add);
      }
    }
  }
  const ll lINF = 1e18;
  ll ans = lINF;
  rep(i, k1 + 1) {
    if (dp.back().at(i) == INF) continue;
    int b = dp.back().at(i);
    ans = min(ans, c1 * i + c2 * b);
  }
  if (ans == lINF) ans = -1;
  cout << ans << endl;
  return 0;
}