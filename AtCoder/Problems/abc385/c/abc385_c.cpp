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
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h.at(i);
  int ans = 1;
  const int sz = 3005;
  rep2(mod, 1, n + 1) {
    vector<pair<int, int>> table(mod, {0, 0});
    rep(i, n) {
      int m = i % mod;
      auto p = table.at(m);
      if (p.first == h.at(i)) {
        p.second++;
      } else {
        p = {h.at(i), 1};
      }
      ans = max(ans, p.second);
      table.at(m) = p;
    }
  }
  cout << ans << endl;
  return 0;
}