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

ll fc(ll now, ll k, ll mx) {
  for (ll i = 0; i < k; i++) {
    if (now * 2 > mx) return -1;
    now *= 2;
  }
  return now;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll mx, x, k;
    cin >> mx >> x >> k;
    ll ans = 0;
    ll btml = fc(x, k, mx);
    ll btmr = fc(x + 1, k, mx);
    if (btml != -1) {
      if (btmr == -1) btmr = mx + 1;
      ans += btmr - btml;
    }
    ll now = x;
    while (now != 1 && k != 0) {
      ll nx = now / 2;
      [&] {
        if (k == 1) {
          ans++;
          return;
        }
        ll l = -1, r = -1;
        if (now % 2 == 1) {
          l = fc(nx, k - 1, mx);
          r = fc(now, k - 2, mx);
        } else {
          l = fc(now + 1, k - 2, mx);
          r = fc(nx + 1, k - 1, mx);
        }
        if (l != -1) {
          if (r == -1) r = mx + 1;
          ans += r - l;
        }
      }();
      k--;
      now = nx;
    }
    cout << ans << endl;
  }
  return 0;
}