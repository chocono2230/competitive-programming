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
  ll xa, ya;
  cin >> xa >> ya;
  ll xb, yb;
  cin >> xb >> yb;
  xb -= xa;
  yb -= ya;
  ll xc, yc;
  cin >> xc >> yc;
  xc -= xa;
  yc -= ya;
  if (xb < 0) {
    xb *= -1;
    xc *= -1;
  }
  if (yb < 0) {
    yb *= -1;
    yc *= -1;
  }
  ll ans = abs(xb - xc) + abs(yb - yc);
  const ll INF = 1e18;
  ll add = INF;
  int co = 0;
  if (xb < xc) {
    co++;
    ll p = yb;
    if (xb == 0)
      p++;
    else
      p += xb - 1;
    add = min(add, p);
  }
  if (xc < xb) {
    co++;
    ll p = 0;
    if (xb == 0) {
      p = yb + 1;
    } else if (yb == 0) {
      p = xb + 1 + 2;
    } else {
      p = xb + yb + 1;
    }
    add = min(add, p);
  }
  if (yb < yc) {
    co++;
    ll p = 0;
    if (yb == 0) {
      p = xb + 1;
    } else {
      p = xb + yb - 1;
    }
    add = min(add, p);
  }
  if (yc < yb) {
    co++;
    ll p = 0;
    if (yb == 0) {
      p = xb + 1;
    } else if (xb == 0) {
      p = yb + 1 + 2;
    } else {
      p = xb + yb + 1;
    }
    add = min(add, p);
  }
  ans += add;
  if (co > 1) ans += 2;
  cout << ans << endl;
  return 0;
}