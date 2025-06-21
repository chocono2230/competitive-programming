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
using mint = modint998244353;
// using mint = double;

int main() {
  int n;
  cin >> n;
  map<int, vector<int>> mp;
  rep(i, n) {
    rep(j, 6) {
      int in;
      cin >> in;
      mp[in].push_back(i);
    }
  }
  mint ans = 0, ml = 1;
  vector<int> co(n, 0);
  int chk = 0;
  vector<mint> pv(7, 0), rv(7, 0);
  rep2(i, 1, 7) { pv.at(i) = (mint)i / (mint)6; }
  rep2(i, 1, 7) rv.at(i) = (mint)1 / pv.at(i);
  for (auto &[p, q] : mp) {
    auto tp = ml;
    for (auto now : q) {
      if (co.at(now) == 0) {
        chk++;
        co.at(now)++;
        continue;
      }
      ml *= rv.at(co.at(now));
      co.at(now)++;
      ml *= pv.at(co.at(now));
    }
    if (chk < n) continue;
    if (chk == n) {
      chk++;
      ml = 1;
      rep(i, n) { ml *= pv.at(co.at(i)); }
      // cerr << ml << " " << p << endl;
      ans += ml * (mint)p;
      continue;
    }
    ans += (ml - tp) * (mint)p;
  }
  cout << ans.val() << endl;
  return 0;
}