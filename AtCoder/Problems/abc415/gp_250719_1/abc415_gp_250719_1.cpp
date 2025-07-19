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
  ll n;
  int m;
  cin >> n >> m;
  vector<int> maxb(301, -1);
  int mxa = -1, mxc = 1;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    int c = a - b;
    if (mxa * c < mxc * a) {
      mxa = a;
      mxc = c;
    } else if (mxa * c == mxc * a && mxa > a) {
      mxa = a;
      mxc = c;
    }
    if (maxb.at(a) < b) maxb.at(a) = b;
  }
  int sz = 300 * 301;
  ll dd = max(-1LL, (n - sz) / mxc);
  ll pn = n - dd * mxc;
  if (dd == -1) pn = n;
  vector<ll> dp(pn + 1, 0);
  dp.back() = dd * mxa;
  if (dd == -1) dp.back() = 0;
  rrep(i, pn + 1) {
    rep(a, maxb.size()) {
      int ni = i - a;
      if (ni < 0) break;
      if (maxb.at(a) < 0) continue;
      ni += maxb.at(a);
      dp.at(ni) = max(dp.at(ni), dp.at(i) + a);
    }
  }
  // rep(i, pn + 1) cerr << dp.at(i) << " ";
  // cerr << endl;
  ll ans = 0;
  rep(i, pn + 1) { ans = max(ans, dp.at(i) + i); }
  cout << ans << endl;
  return 0;
}