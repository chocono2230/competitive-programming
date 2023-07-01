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
  int n, m;
  cin >> n >> m;
  vector<ll> p(n);
  rep(i, n) cin >> p.at(i);
  ll ans = reduce(ALL(p));
  multiset<ll> se;
  rep(i, n) se.insert(p.at(i));
  vector<int> l(m);
  rep(i, m) cin >> l.at(i);
  vector<int> d(m);
  rep(i, m) cin >> d.at(i);
  vector<pair<int, int>> v(m);
  rep(i, m) v.at(i) = {d.at(i), l.at(i)};
  sort(ALL(v), greater<pair<int, int>>());
  for (auto [dd, zz] : v) {
    auto itr = se.lower_bound(zz);
    if (itr == se.end()) continue;
    ans -= dd;
    se.erase(itr);
  }
  cout << ans << endl;
  return 0;
}