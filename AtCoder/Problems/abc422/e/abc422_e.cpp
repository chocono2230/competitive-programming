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
  auto fc = [&](int p, int q) -> tuple<ll, ll, ll> {
    auto [x1, y1] = xy.at(p);
    auto [x2, y2] = xy.at(q);
    ll xd = y1 - y2;
    ll yd = x2 - x1;
    ll zd = (x2 - x1) * y1 + (y2 - y1) * x1;
    ll g = gcd(xd, yd);
    g = gcd(g, zd);
    if (g != 0) {
      xd /= g;
      yd /= g;
      zd /= g;
    }
    if (xd < 0) {
      xd *= -1;
      yd *= -1;
      zd *= -1;
    }
    ll t = x1 * xd + y1 * yd + zd;
    return {xd, yd, zd - t};
  };
  set<int> se;
  set<tuple<ll, ll, ll>> ban;
  while (time_from_clock() < 1.5) {
    int p = xor128() % n;
    if (se.find(p) != se.end()) continue;
    se.insert(p);
    map<tuple<ll, ll, ll>, int> mp;
    rep(i, n) {
      if (i == p) continue;
      auto r = fc(p, i);
      mp[r]++;
      if (ban.find(r) != ban.end()) {
        if (mp[r] > 100) break;
      }
    }
    int mx = 0;
    tuple<ll, ll, ll> ab;
    for (auto [x, y] : mp) {
      if (y >= n / 2) {
        cout << "Yes" << endl;
        auto [a, b, c] = x;
        cout << a << " " << b << " " << c << endl;
        // rep(i, n) {
        //   auto [px, py] = xy.at(i);
        //   cerr << i << " " << px * a << " " << py * b << " " << c << " : ";
        //   cerr << px * a + py * b + c << endl;
        // }
        return 0;
      }
      if (y > mx) {
        mx = y;
        ab = x;
      }
    }
    ban.insert(ab);
  }
  cout << "No" << endl;
  return 0;
}