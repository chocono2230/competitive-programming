#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    ll x, y;
    cin >> x >> y;
    x = abs(x);
    y = abs(y);
    if (a > b) {
      swap(x, y);
      swap(a, b);
    }
    ll p = b - a * 3;
    ll d1 = min(x, y);
    ll ans = d1 * a * 2;
    x -= d1;
    y -= d1;
    if (x != 0) {
      ans += a;
      x--;
      ans += (x / 2) * a;
      if (p > 0)
        ans += ((x + 1) / 2) * (3 * a);
      else
        ans += ((x + 1) / 2) * b;
    } else if (y != 0) {
      ans += (y / 2) * a;
      if (p > 0)
        ans += ((y + 1) / 2) * (3 * a);
      else
        ans += ((y + 1) / 2) * b;
    }
    cout << ans << endl;
  }
  return 0;
}