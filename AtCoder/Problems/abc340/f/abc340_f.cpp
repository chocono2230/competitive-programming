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
  ll x, y;
  cin >> x >> y;
  ll a = 0, b = 0;
  bool sw = false;
  bool sw2 = false;
  if (x < 0) {
    sw = true;
    x *= -1;
  }
  if (y < 0) {
    sw2 = true;
    y *= -1;
  }
  ll g = gcd(x, y);
  if (g >= 3) {
    cout << -1 << endl;
    return 0;
  }
  if (g == 2) {
    if (x < y) {
      b = y / 2;
      a = x - 1;
    } else {
      a = x / 2;
      b = y - 1;
    }
  } else {
    a = 1;
    b = 1;
  }

  if (sw) {
    a *= -1;
  }
  if (sw2) {
    b *= -1;
  }
  cout << a << " " << b << endl;
  return 0;
}