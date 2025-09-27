#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

unsigned long xor128() {
  static unsigned long x = 123456789, y = 362436069, z = 202509073,
                       w = 64813216;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

const clock_t start_time = clock();
double time_from_clock() {
  return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

int main() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> xy(n);
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    xy.at(i) = {x, y};
  }

  rep(_i, 100) {
    int p = xor128() % n, q = xor128() % n;
    if (p == q) continue;
    auto [x1, y1] = xy.at(p);
    auto [x2, y2] = xy.at(q);
    ll a = y1 - y2;
    ll b = x2 - x1;
    ll c = x1 * y2 - x2 * y1;
    int co = 0;
    rep(i, n) {
      auto [x, y] = xy.at(i);
      if (a * x + b * y + c == 0) co++;
    }
    if (co * 2 > n) {
      cout << "Yes" << endl;
      cout << a << " " << b << " " << c << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}