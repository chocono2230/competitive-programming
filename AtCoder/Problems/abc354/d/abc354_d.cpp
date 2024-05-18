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
  ll a, b;
  cin >> a >> b;
  ll c, d;
  cin >> c >> d;
  ll dx = (c - a);
  ll dy = (d - b);
  if (a < 0) {
    a += (abs(a) + 3) / 4 * 4;
  }
  if (b < 0) {
    b += (abs(b) + 1) / 2 * 2;
  }
  a %= 4;
  b %= 2;
  ll ddy = dy / 2;
  ll mdy = dy % 2;
  ll ddx = dx / 4;
  ll mdx = dx % 4;
  // cerr << a << " " << b << " " << ddy << " " << mdy << " " << ddx << " " <<
  // mdx
  //      << endl;

  ll ans = ddy * ddx * 8;
  ll pa = a;
  rep(i, mdx) {
    if (pa <= 1) {
      ans += 3 * ddy;
    } else {
      ans += ddy;
    }
    pa++;
    pa %= 4;
  }
  ans += mdy * ddx * 4;
  pa = a;
  if (b == 1) pa = (pa + 4 - 1) % 4;
  rep(i, mdx) {
    if (pa == 0)
      ans += 2 * mdy;
    else if (pa == 2)
      ans += 0 * mdy;
    else
      ans += 1 * mdy;
    pa++;
    pa %= 4;
  }
  cout << ans << endl;
  return 0;
}