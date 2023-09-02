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
  vector tb(n, vector<int>(n, 0));
  rep(i, n - 1) {
    rep2(j, i + 1, n) {
      int in;
      cin >> in;
      tb.at(i).at(j) = in;
    }
  }
  vector<ll> dp(1 << n, 0);
  rep(bit, 1 << n) {
    ll now = dp.at(bit);
    rep(j, n) {
      if ((bit & (1 << j)) != 0) continue;
      rep2(k, j + 1, n) {
        if ((bit & (1 << k)) != 0) continue;
        int add = tb.at(j).at(k);
        int nxbit = (bit | (1 << j) | (1 << k));
        dp.at(nxbit) = max(dp.at(nxbit), now + add);
      }
    }
  }
  ll ans = *max_element(ALL(dp));
  cout << ans << endl;
  return 0;
}