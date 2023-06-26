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
  int t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    ll ans = -8e18;
    ll b = 0, a = 0;
    rep(i, n) {
      ll x, y;
      cin >> x >> y;
      if (i == 0) {
        ans = x;
      }
      ll nxb = (x * y) + b;
      if (b > 0 && nxb < 0 && x != 0) {
        ll t = b / abs(x);
        ll ta = t * (t + 1) / 2 * x + b * t;
        ans = max(ans, a + ta);
        t = (b + abs(x) - 1) / abs(x);
        ta = t * (t + 1) / 2 * x + b * t;
        ans = max(ans, a + ta);
      }
      ll add = y * (y + 1) / 2 * x + b * y;
      a += add;
      ans = max(ans, a);
      b = nxb;
    }
    cout << ans << endl;
  }
  return 0;
}