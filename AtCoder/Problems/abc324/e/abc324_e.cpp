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
  int n;
  cin >> n;
  string t;
  cin >> t;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  auto fc = [&]() -> ll {
    fenwick_tree<ll> fw(t.size() + 1);
    ll res = 0;
    for (auto &ss : s) {
      reverse(ALL(ss));
      int idx = t.size() - 1;
      for (auto c : ss) {
        if (idx == -1) break;
        if (c == t.at(idx)) idx--;
      }
      idx++;
      res += fw.sum(idx, t.size() + 1);

      reverse(ALL(ss));
      idx = 0;
      for (auto c : ss) {
        if (idx == t.size()) break;
        if (c == t.at(idx)) idx++;
      }
      fw.add(idx, 1);
    }
    return res;
  };
  ll ans = fc();
  reverse(ALL(s));
  ans += fc();
  for (auto ss : s) {
    string p = ss + ss;
    int idx = 0;
    for (auto c : p) {
      if (idx == t.size()) break;
      if (c == t.at(idx)) idx++;
    }
    if (idx == t.size()) ans++;
  }
  cout << ans << endl;
  return 0;
}