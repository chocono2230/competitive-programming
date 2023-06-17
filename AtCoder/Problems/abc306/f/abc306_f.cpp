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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  vector a(n, vector<int>(m));
  rep(i, n) rep(j, m) {
    cin >> a.at(i).at(j);
    mp[a.at(i).at(j)] = -1;
  }
  rep(i, n) { sort(ALL(a.at(i))); }
  int sz = 0;
  for (auto &p : mp) p.second = sz++;
  fenwick_tree<ll> fw(sz);
  rep(i, m) { fw.add(mp[a.back().at(i)], 1); }
  ll ans = 0;
  int co = 1;
  rrep(i, n - 1) {
    rep(j, m) {
      int now = mp[a.at(i).at(j)];
      ans += fw.sum(0, now) + co * (j + 1);
      // cerr << now << " " << a.at(i).at(j) << " " << fw.sum(0, now) << " "
      //      << co * (j + 1) << endl;
    }
    rep(j, m) fw.add(mp[a.at(i).at(j)], 1);
    co++;
  }
  cout << ans << endl;
  return 0;
}