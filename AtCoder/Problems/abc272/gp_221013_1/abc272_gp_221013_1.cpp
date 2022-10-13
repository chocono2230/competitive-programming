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

unsigned long xor128() {
  static unsigned long x = 123456789, y = 362436069, z = 202210132,
                       w = 64813216;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  set<int> p;
  rep(_i, 100) {
    int ai = xor128() % n, aj = xor128() % (n - 1);
    if (ai <= aj) aj++;
    int d = abs(a.at(ai) - a.at(aj));
    for (int i = 2; i * i <= d; i++) {
      if (d % i != 0) continue;
      p.insert(i);
      while (d % i == 0) d /= i;
    }
    if (d != 1) p.insert(d);
  }
  for (auto ans : p) {
    if (ans == 2) ans = 4;
    map<int, int> mp;
    for (auto now : a) mp[now % ans]++;
    for (auto q : mp) {
      if (q.second * 2 > n) {
        cout << ans << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}