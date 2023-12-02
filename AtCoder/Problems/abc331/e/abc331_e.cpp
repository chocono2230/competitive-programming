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
  int n, m, l;
  cin >> n >> m >> l;
  vector<pair<int, int>> ai(n), bi(m);
  rep(i, n) {
    int in;
    cin >> in;
    ai.at(i) = {in, i};
  }
  rep(i, m) {
    int in;
    cin >> in;
    bi.at(i) = {in, i};
  }
  sort(ALL(ai), greater<pair<int, int>>());
  sort(ALL(bi), greater<pair<int, int>>());
  set<pair<int, int>> cd;
  rep(i, l) {
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    if (c > d) swap(c, d);
    cd.insert({c, d});
  }
  int ans = 0;
  for (auto [a, aidx] : ai) {
    for (auto [b, bidx] : bi) {
      int p = aidx, q = bidx;
      if (p > q) swap(p, q);
      if (cd.find({p, q}) != cd.end()) continue;
      ans = max(ans, a + b);
      break;
    }
  }
  cout << ans << endl;

  return 0;
}