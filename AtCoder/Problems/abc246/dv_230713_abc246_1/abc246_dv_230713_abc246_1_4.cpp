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
  cin >> n;
  ll p = 1000005;
  ll ans = LLONG_MAX;
  for (ll a = p; a >= 0; a--) {
    ll ok = p, ng = -1;
    while (ok - ng > 1) {
      ll mid = (ok + ng) / 2;
      bool f = false;
      [&] {
        // if (mid != 0) {
        //   if (mid > LLONG_MAX / mid) {
        //     f = true;
        //     return;
        //   }
        //   if (mid * mid > LLONG_MAX / mid) {
        //     f = true;
        //     return;
        //   }
        //   if (a * a > LONG_LONG_MAX / mid) {
        //     f = true;
        //     return;
        //   }
        //   if (a * mid > LONG_LONG_MAX / mid) {
        //     f = true;
        //     return;
        //   }
        // }
        if (a * a * a + mid * a * a + mid * mid * a + mid * mid * mid >= n)
          f = true;
      }();
      if (f)
        ok = mid;
      else
        ng = mid;
    }
    ll add = a * a * a + a * a * ok + a * ok * ok + ok * ok * ok;
    ans = min(ans, add);
  }
  cout << ans << endl;
  return 0;
}