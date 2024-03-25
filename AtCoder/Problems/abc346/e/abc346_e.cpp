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
  int h, w, m;
  cin >> h >> w >> m;
  vector<tuple<int, int, int>> tax(m);
  rep(i, m) {
    int t, a, x;
    cin >> t >> a >> x;
    a--;
    tax.at(i) = {t, a, x};
  }
  vector<bool> hu(h, false), wu(w, false);
  int hs = h, ws = w;
  map<int, ll> mp;
  rrep(i, m) {
    auto [t, a, x] = tax.at(i);
    if (t == 1) {
      if (hu.at(a)) continue;
      if (ws == 0) continue;
      hu.at(a) = true;
      hs--;
      mp[x] += ws;
    } else {
      if (wu.at(a)) continue;
      if (hs == 0) continue;
      wu.at(a) = true;
      ws--;
      mp[x] += hs;
    }
  }
  ll z0 = (ll)h * w;
  for (auto p : mp) {
    if (p.first == 0) continue;
    z0 -= p.second;
  }
  if (z0 != 0) mp[0] = z0;
  cout << mp.size() << endl;
  for (auto [a, b] : mp) cout << a << " " << b << endl;
  return 0;
}