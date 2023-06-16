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

struct frac {
  ll top = 0, btm = 1;
  frac(ll top, ll btm) : top(top), btm(btm) {}
  frac() {}
  friend bool operator<(const frac &l, const frac &r) {
    return l.top * r.btm < r.top * l.btm;
  }
  friend bool operator==(const frac &l, const frac &r) {
    return l.top * r.btm == r.top * l.btm;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> xy(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    xy.at(i) = {x, y};
  }
  if (k == 1) {
    cout << "Infinity" << endl;
    return 0;
  }
  k = k * (k - 1) / 2;
  map<tuple<frac, frac>, int> mp;
  map<int, int> xmp;
  auto fc = [&](pair<ll, ll> p, pair<ll, ll> q) -> void {
    if (p.first == q.first) {
      xmp[p.first]++;
      return;
    }
    if (p.first > q.first) swap(p, q);
    frac add(q.second - p.second, q.first - p.first);
    ll g = gcd(add.top, add.btm);
    add.top /= g;
    add.btm /= g;
    frac zz(add.btm * p.second - p.first * add.top, add.btm);
    g = gcd(zz.top, zz.btm);
    zz.top /= g;
    zz.btm /= g;
    mp[{add, zz}]++;
  };
  rep(i, n) rep2(j, i + 1, n) fc(xy.at(i), xy.at(j));
  int ans = 0;
  for (auto &p : mp) {
    // cerr << p.second << endl;
    if (p.second >= k) ans++;
  }
  for (auto &p : xmp) {
    // cerr << p.first << " " << p.second << endl;
    if (p.second >= k) ans++;
  }
  cout << ans << endl;
  return 0;
}