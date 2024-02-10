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

ll extgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  ll g = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return g;
}

int main() {
  ll x, y;
  cin >> x >> y;
  ll a = 0, b = 0;
  ll g = extgcd(x, y, b, a);
  g = abs(g);
  if (g >= 3) {
    cout << -1 << endl;
    return 0;
  }
  b *= -1;
  if (g == 1) {
    a *= 2;
    b *= 2;
  }
  cout << a << " " << b << endl;
  return 0;
}